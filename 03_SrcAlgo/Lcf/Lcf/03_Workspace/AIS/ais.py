import ConfigParser
import subprocess, shlex
import itertools
import argparse
import logging
import pickle
import stat
import time
import sys
import os
import re
from threading import Timer, _Timer
from distutils.dir_util import copy_tree
#from distutils.version import LooseVersion
from pkg_resources import parse_version

class CLI_ExitCodes(object):

    SUCCESS_OR_NO_DIFF = 0      # Successful completion or No differences between the files being compared  (using si diff).
    COMMAND_ERROR = 1           # Command usage error.
    USER_CANCELED_CMD = 2       # Command was canceled by user (NOT CTRL-c).
    INVALID_ELEM_SEL_CMD = 3    # Invalid element in the selection for the command.
    SANDBOX_AMBIGOUS = 4        # Sandbox specified was ambiguous (using an si command). Command not executed.
    ERROR_SEL_CMD = 5           # Unable to create or utilize the selection for the command.
    NO_NEXT_ELEM = 6            # Unable to continue with the selection for the command because the program cannot find the next element.
    NETWORK_ERROR = 10          # Connection failed: a network error caused the command to terminate.
    IS_DIFF = 16                # diff compared the files and found them to be different (using si diff).
    FAIL_DIFF = 17              # Failure due to any of the following (using si diff): invalid command line argument, cannot open one of the input files, out of memory, read error on one of the input files, more than LINE_MAX characters between newlines
    BINARY_EMBEDDED_NUL = 19    # At least one of the files is a binary file containing embedded NUL (\0) bytes (using si diff).
    GENERAL_CMD_FAIL = 128      # General command failure.
    USER_CANCELED_CTRL_C = 130  # Command was canceled by the user using CTRL-c.
    UNKNOWN_ERROR = 255         # Unknown exception or error code.
    pass

class ErrorCodes(object):

    #TODO: Define suberror codes (CONFIGURE_RELEASE_ID, CONFIGURE_LATEST etc.).
    MODULE_IMPORT = 1
    VIEW_PROJECT = 2
    CONFIGURE_SUBPROJECT = 3
    CHECK_IN_FILE_NOT_FOUND = 4
    OLD_REV_FILE_NOT_FOUND = 5
    LOCK_FILE = 6
    INCORRECT_CFG_MODE = 7
    NO_RELEASE_ID = 8
    RESYNC = 9
    INCORRECT_BUILD_MODE = 10
    CHECKPOINT = 11
    READ_CONFIG = 12
    COMMAND = 13
    CONNECT = 14
    UNKONWN = 15

try:
    from ims import IMS, TimeoutError, CommandError, APIException, ProjectType, ShareType, ChangePackageState, State, init_logging
except Exception:
    print sys.exc_info()
    sys.exit(ErrorCodes.MODULE_IMPORT)

def get_exception_message(e):
    if not isinstance(e, Exception):
        #exc_info = sys.exc_info()
        #raise exc_info[0], exc_info[1], exc_info[2]
        return 'The "e" parameter must be a subtype of Exception!'

    message = e.message
    if isinstance(e, APIException):
        ex_resp = e.response
        if ex_resp.work_items is not None:
            for wi in ex_resp.work_items:
                if wi.api_exception is not None:
                    message += '\n\t%s' % wi.api_exception.message
                    message += '\n\t%s' % [str(field) for field in wi.api_exception.fields]
    return message

def configure_buildunit_releaseID(subpj_lst, ex_global, build_unit_name):
    try:
        if not subpj_lst:
            logger.error('No subproject found for "%s" build unit in configuration file (build_mode: "%s", configure_mode: "%s")!', build_unit_name, build_mode, configure_mode)
            sys.exit(6)
        
        resp = ims.viewproject(*subpj_lst, batch=None, recurse=None, project=base_project, devpath=devpath, filter='!file:*')
        #ex_global = set()

        with open(file_old_config_rev, 'a+') as f:
            #TODO: Get the list of 'shared build subprojects' (all the other subprojects types should be ignored) - exit in all the other cases!
            for item in resp.work_items:
                if item.parent_id.upper() in ex_global:
                    logger.info('Subproject\'s (grand)parent found in exception list, it will not be configured: "%s"...', item.id)
                    # exclude it using configpath from variant branch, so it's children can be easily excluded (without running 'projectinfo' command on them)
                    ex_global.add(item.id.upper())
                    continue
    
                subpj_type = item.getField('type').value
                rev_field = item.getField('memberrev')
                if not rev_field: rev = None
                else: rev = rev_field.item.id
    
                #There should be no normal or variant shared subprojects because we branch from a checkpoint, but just in case somebody manually reconfigure...
                if subpj_type == ShareType.ARCHIVED:
                    #f.write('%s\t%s\t%s\n' % (item.getField('name').value, subpj_type, rev))
                    pass
                elif subpj_type == ShareType.SUBPROJECT:
                    #f.write('%s\t%s\t%s\n' % (item.id, subpj_type, rev))
                    pass
                elif subpj_type == ShareType.BUILD_SUBPROJECT:
                    #f.write('%s\t%s\t%s\n' % (item.id, subpj_type, rev))
                    pass
                elif subpj_type == ShareType.VARIANT_SUBPROJECT:
                    #f.write('%s\t%s\t%s\n' % (item.id, subpj_type, rev))
                    pass
                elif subpj_type == ShareType.SHARED_SUBPROJECT:
                    #f.write('%s\t%s\t%s\n' % (item.id, subpj_type, rev))
                    pass
                elif subpj_type == ShareType.SHARED_VARIANT_SUBPROJECT:
                    #f.write('%s\t%s\t%s\n' % (item.id, subpj_type, rev))
                    pass
                elif subpj_type == ShareType.SHARED_BUILD_SUBPROJECT:
                    #check if item is in exclude list using repository location (a flatpath)
                    r = ims.projectinfo(batch=None, project=item.id)
                    shared_location = r.work_items[0].getField('sharedFrom').value
                    if shared_location.upper() in ex_global:
                        logger.info('Subproject found in exception list, it will not be configured: "%s"', item.id)
                        #add it again with configpath from variant branch, so it's children can be easily excluded (without running 'projectinfo' command on them)
                        ex_global.add(item.id.upper())
                        continue
    
                    #TODO: Move it up! Add item.id to exception list so it's children won't be taken into consideration to be configured
                    ex_global.add(item.id.upper())
    
                    try:
                        # Configure to revision from 'components_release' (based on releaseID) by iterate over all components
                        # Detect the subproject revision inside a "component" revision
                        for comp in components_release:
                            if shared_location.startswith(comp[0].replace('/project.pj', '')):
                                build_comp = comp[2] + shared_location[len(comp[0].replace('/project.pj', '')):]
                                #TODO: If subproject was dropped from the component we can only ignore it...
                                #TODO: Check if comp[1] revision exists to avoid thrown exception, perhaps we need to run a viewprojecthistory or handle it in ims library.
                                r = ims.projectinfo(batch=None, project=build_comp)
                                subpj_rev = r.work_items[0].getField('revision').item.id
                                # Only configure if the revision is different!
                                if rev != subpj_rev:
                                    f.write('%s\t%s\t%s\n' % (item.id, subpj_type, rev))
                                    logger.debug('Configure subproject "%s" from revision "%s" to revision "%s", based on ReleaseID="%s"', item.id, rev, subpj_rev, releaseID)
                                    #do not specify 'devpath' as '#d=TEST_PARALLEL_BRANCH' is specified in 'item.parent_id'
                                    r = ims.configuresubproject(item.display_id, batch=None, cpid=cpid, type='build', subprojectRevision=subpj_rev, project=item.parent_id)
                                    pass
                                else:
                                    logger.info('Subproject "%s" is already configured to ReleaseID revision ("%s")...', item.id, subpj_rev) #rev
                                break
                    except APIException as e:
                        # Ignore dropped subprojects (combination of old branches and new releases)!
                        if e.exception_class == 'ItemNotFoundException':
                            logger.warning('Subproject "%s" was dropped in the meantime from the component...', item.id)
                            continue
                        message = get_exception_message(e)
                        logger.exception('Exception occurred: %s', message)
                        sys.exit(1)
                else: #unknown subproject type
                    logger.warning('Subproject of unkonwn type ("%s") found, it will not be configured: "%s"', subpj_type, item.id)
                    f.write('%s\t%s\t%s\n' % (item.id, subpj_type, rev))
    except SystemExit as e:
        #print "Exit with error number: " + str(e.code)
        logger.exception('Exception occurred:')
        sys.exit(e.code)

def get_uses_releases(releases, releaseID):
    try:
        resp = ims.issues(batch=None, fields='Structure Element,Summary', queryDefinition='((field["Type"] = "Release") and (relationship["ID"] backwards forwards using ["Uses"] = %s))' % releaseID)
        # resp.work_items will be None if the user doesn't has rights on the server (there is no <WorkItems> in the xml)

        if not resp.work_items:
            logger.error('Release ID "%s" empty or not found on server "%s@%s:%s"!', releaseID, resp.connection_username, resp.connection_hostname, resp.connection_port)
            sys.exit(1)

        for wi in resp.work_items:
            if wi.id not in releases:
                releases.add(wi.id)
                #if '[%s]' % project in wi.getField('Summary').value:
                #if (family.split('/')[0]).rstrip('x') in wi.getField('Structure Element').item.id:
                #TODO: For exceptional projects like MFC430H17, MFC500
                if (project.upper() in ['MFC430H17', 'MFC500'] and project in wi.getField('Summary').value) or ((family.split('/')[-1]).rstrip('x') in wi.getField('Structure Element').item.id):
                    logger.info('This is a release that can contains other releases: %s', wi.id)
                    get_uses_releases(releases, wi.id)
            else:
                logger.info('Release found again, it will be ignored: %s!', wi.id)
    #TODO: To be moved in IMS class
    except CommandError as e:
        logger.exception('Exception occurred:')
    except APIException as e:
        logger.exception('Exception occurred:')
        print 'Exception catched Message: ' + e.message
        #print 'Exception catched args:\n\t' + '\n'.join([str(arg) for arg in e.fields.args])
        #print 'Exception catched Response: ' + str(e.response)
        print 'Exception catched Class: ' + e.exception_class
        print 'Exception catched Fields: ' + str([str(field) for field in e.fields])
        r = e.response
        #print 'Exception catched e.response Class: ' + str(r.__class__)
        if r.work_items is not None:
            for wi in r.work_items:
                if wi.api_exception is not None:
                    print '\t\t%s' % wi.api_exception.message
                    print '\t\t\t%s' % [str(field) for field in wi.api_exception.fields]
            #print '\n'.join(['\t\t'+wi.api_exception.message for wi in r.work_items if wi.api_exception is not None])
    except TypeError as e:
        cmd = ims.cmdRunner
        print '\nNot enough rights for "%s" on "%s:%s" server!' % (cmd.user, cmd.hostname, cmd.port)
        #resp.work_items will be None if the user doesn't has rights on the server (there is no <WorkItems> in the xml)
        exc_info = sys.exc_info()
        raise exc_info[0], exc_info[1], exc_info[2]

    return releases

def configure_releaseID(iuc, dpu, sil):
    global components_release

    '''Query Definition
    Query Definition: (relationship["ID"] backwards forwards using ["Uses"] = 801292)
    Sorted By: ID (Descending)
    Fields: ID,Type,Summary,State,Assigned User,Project
    '''

    #TODO: Should exception list(s) be used by nighlybuilds as well?
    ex_global_iuc = set()
    ex_global_dpu = set()
    ex_global_sil = set()
    if build_mode in ['DPU', 'BOTH'] and iuc and ex_files_releaseID_iuc:
        ex_global_iuc.update(item.upper() for item in ex_files_releaseID_iuc)
    if build_mode in ['DPU', 'BOTH'] and dpu and ex_files_releaseID_dpu:
        ex_global_dpu.update(item.upper() for item in ex_files_releaseID_dpu)
    if build_mode in ['DPU', 'BOTH'] and sil and ex_files_releaseID_sil:
        ex_global_sil.update(item.upper() for item in ex_files_releaseID_sil)

    try:
        releases = set([])
        get_uses_releases(releases, releaseID)
        logger.debug('Releases (%s):\n\t%s', len(releases), ', '.join(releases))
        resp = ims.viewissue(*releases, batch=None)
        
        components = []
        for wi in resp.work_items:
            if wi.getField('State').item.id in [State.PLANNED, State.REALIZED, State.INTEGRATED, State.TESTED, State.RELEASED, State.CLOSED]:
                released_cp_item = wi.getField('Released Checkpoint').item
                if released_cp_item == None:
                    logger.warning('Release "%s" with ID "%s" does not have a "Released Checkpoint" field (used to configure subproject)...', wi.getField('Summary').value, wi.id)
                    # Components without a "Released Checkpoint" field can be safely ignore (the label can be used to find the revision)
                    continue
                #location -> #location=/ADAS/SW/Components/SR_SignRecognition/project.pj#b=1.254.0.0.1522069503990.0.1.2
                location = released_cp_item.getField('project').value
                location_str = '#location='
                if location.startswith(location_str):
                    #location -> /ADAS/SW/Components/SR_SignRecognition/project.pj#b=1.254.0.0.1522069503990.0.1.2
                    location = location[len(location_str):]
                    share_build_str = '#b='
                    index = location.rfind(share_build_str)
                    if index != -1:
                        projRev = location[index+len(share_build_str):]
                        #location -> /ADAS/SW/Components/SR_SignRecognition/project.pj
                        location = location[:index]
                        #print 'Project: "%s" (rev. "%s")' % (location, projRev)
                    else:
                        logger.warning('Release "%s" with ID "%s" does not have a "#b=" in "Released Checkpoint" item (used to configure subproject)...', wi.getField('Summary').value, wi.id)
                        continue

                    # Find component duplicates (newer, older revision)...
                    t = (location, projRev, wi.id) #component
                    element = [comp for comp in components if comp[0] == location] #component
                    
                    if element and parse_version(element[0][1]) < parse_version(projRev):
                        # Remove the existing one...
                        logger.debug('Older component build found in the list, it will be replaced by:\n\t%s', ' '.join(t))
                        components.remove(element[0])
                        components.append(t)
                    elif element and parse_version(element[0][1]) >= parse_version(projRev):
                        logger.debug('Newer (or same) component build found in the list, it will be kept:\n\t%s', ' '.join(element[0]))
                    else:
                        logger.debug('New component build to be added to the list:\n\t%s', ' '.join(t))
                        components.append(t)
                else:
                    logger.debug('Unexpected format of "Released Checkpoint" project for ID "%s": "%s"!', wi.id, location)
            else:
                #TODO: Save and print a summary!
                logger.warning('Release "%s" with ID "%s" is in state "%s", so will not be configured...', wi.getField('Summary').value, wi.id, wi.getField('State').item.id)
        logger.debug('Components:\n\t%s', '\n\t'.join(' '.join(comp) for comp in components))
        pass

        # Configure subprojects based on 'components_release' list.
        try:
            components_release = []
            for item in components:
                #TODO: Find a better way to detect the subproject revision inside a "component" revision

                project_path = '#%s#b=%s#' % (item[0].replace('/project.pj', '').replace('/ADAS/SW/', '/ADAS/SW#', 1), item[1])
                components_release.append((item[0], item[1], project_path))

            #TODO: Only reconfigure subprojects based on build units passed as parameters
            # Make it generic by adding options in configuration file: builunit_iuc = M11_APPL, builunit_dpu = DPU, MTS

            if build_mode in ['IuC', 'BOTH']:
                if iuc:
                    logger.debug('IuC will be reconfigured (%s)...', build_unit_iuc)

                    #TODO: Add subprojects from shared_buildunit to the exclude list, if anything needs to be checkpointed
                    #TODO: Add the same code as from 'sil' to be easier to refactor in a function.
                    for item in shared_buildunit_iuc:
                        project_path = get_proj_subproj(item)[0]
                        #Add buildunit to the exclude list! This can be optimize by excluding the buildunit from subpj_lst, but is only working for true buildunits (not for MTS cfg and dll subprojects).
                        resp = ims.projectinfo(batch=None, project=project_path)
                        shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
                        project_name_flatpath = resp.work_items[0].getField('projectName').value
                        ex_global_iuc.add(project_path.upper())
                        ex_global_iuc.add(shared_from_flatpath.upper())
                        ex_global_iuc.add(project_name_flatpath.upper())
                        subproject_devpath = configure_project_build(project_path)[0] #no need for subpj_devpath=devpath_buildunits_iuc[item] as the variant is automatically determined
                    if cfg_prev_cp_iuc:
                        for item in cfg_prev_cp_iuc:
                            project_path = get_proj_subproj(item)[0]
                            #Add buildunit to the exclude list! This can be optimize by excluding the buildunit from subpj_lst, but is only working for true buildunits (not for MTS cfg and dll subprojects).
                            resp = ims.projectinfo(batch=None, project=project_path)
                            shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
                            project_name_flatpath = resp.work_items[0].getField('projectName').value
                            ex_global_iuc.add(project_path.upper())
                            ex_global_iuc.add(shared_from_flatpath.upper())
                            ex_global_iuc.add(project_name_flatpath.upper())
                    if 'SIL' in build_units and cfg_prev_cp_sil:
                        for item in cfg_prev_cp_sil:
                            project_path = get_proj_subproj(item)[0]
                            #Add buildunit to the exclude list! This can be optimize by excluding the buildunit from subpj_lst, but is only working for true buildunits (not for MTS cfg and dll subprojects).
                            resp = ims.projectinfo(batch=None, project=project_path)
                            shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
                            project_name_flatpath = resp.work_items[0].getField('projectName').value
                            ex_global_iuc.add(project_path.upper())
                            ex_global_iuc.add(shared_from_flatpath.upper())
                            ex_global_iuc.add(project_name_flatpath.upper())

                    subpj_lst = []
                    subpj_lst.append(build_unit_iuc)
                    if cfg_outside_buildunit_iuc:
                        get_subfolders_outside_buildunits(subpj_lst, ex_global_iuc)

                    for item in shared_buildunit_iuc:
                        try:
                            subpj_lst.remove(item)
                        except ValueError as e:
                            pass

                    if subpj_lst:
                        configure_buildunit_releaseID(subpj_lst, ex_global_iuc, 'IuC')
                    else:
                        logger.info('The "%s" buildunit was configured to shared build so no subproject will be reconfigured!', build_unit_iuc)
                else:
                    logger.warning('IuC will NOT be reconfigured (build_mode: "%s", configure_mode: "%s")!', build_mode, configure_mode)

            if build_mode in ['DPU', 'BOTH']:
                if dpu:
                    logger.debug('DPU will be reconfigured (%s)...', build_unit_dpu)

                    #TODO: Add subprojects from shared_buildunit to the exclude list, if anything needs to be checkpointed
                    #TODO: Add the same code as from 'sil' to be easier to refactor in a function.
                    for item in shared_buildunit_dpu:
                        project_path = get_proj_subproj(item)[0]
                        #Add buildunit to the exclude list! This can be optimize by excluding the buildunit from subpj_lst, but is only working for true buildunits (not for MTS cfg and dll subprojects).
                        resp = ims.projectinfo(batch=None, project=project_path)
                        shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
                        project_name_flatpath = resp.work_items[0].getField('projectName').value
                        ex_global_dpu.add(project_path.upper())
                        ex_global_dpu.add(shared_from_flatpath.upper())
                        ex_global_dpu.add(project_name_flatpath.upper())
                        subproject_devpath = configure_project_build(project_path)[0] #no need for subpj_devpath=devpath_buildunits_iuc[item] as the variant is automatically determined
                    if cfg_prev_cp_dpu:
                        for item in cfg_prev_cp_dpu:
                            project_path = get_proj_subproj(item)[0]
                            #Add buildunit to the exclude list! This can be optimize by excluding the buildunit from subpj_lst, but is only working for true buildunits (not for MTS cfg and dll subprojects).
                            resp = ims.projectinfo(batch=None, project=project_path)
                            shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
                            project_name_flatpath = resp.work_items[0].getField('projectName').value
                            ex_global_dpu.add(project_path.upper())
                            ex_global_dpu.add(shared_from_flatpath.upper())
                            ex_global_dpu.add(project_name_flatpath.upper())

                    subpj_lst = []
                    subpj_lst.append(build_unit_dpu)
                    if cfg_outside_buildunit_dpu:
                        get_subfolders_outside_buildunits(subpj_lst, ex_global_dpu)

                    for item in shared_buildunit_dpu:
                        try:
                            subpj_lst.remove(item)
                        except ValueError as e:
                            pass

                    if subpj_lst:
                        configure_buildunit_releaseID(subpj_lst, ex_global_dpu, 'DPU')
                    else:
                        logger.info('The "%s" buildunit was configured to shared build so no subproject will be reconfigured!', build_unit_dpu)
                else:
                    logger.warning('DPU will NOT be reconfigured (build_mode: "%s", configure_mode: "%s")!', build_mode, configure_mode)

                if sil:
                    logger.debug('SIL will be reconfigured (%s)...', build_unit_sil)

                    #TODO: Add subprojects from shared_buildunit to the exclude list, if anything needs to be checkpointed
                    for item in shared_buildunit_sil:
                        project_path = get_proj_subproj(item)[0]
                        #Add buildunit to the exclude list! This can be optimize by excluding the buildunit from subpj_lst, but is only working for true buildunits (not for MTS cfg and dll subprojects).
                        resp = ims.projectinfo(batch=None, project=project_path)
                        shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
                        project_name_flatpath = resp.work_items[0].getField('projectName').value
                        ex_global_sil.add(project_path.upper())
                        ex_global_sil.add(shared_from_flatpath.upper())
                        ex_global_sil.add(project_name_flatpath.upper())
                        subproject_devpath = configure_project_build(project_path)[0] #no need for subpj_devpath=devpath_buildunits_iuc[item] as the variant is automatically determined
                    if cfg_prev_cp_sil:
                        for item in cfg_prev_cp_sil:
                            project_path = get_proj_subproj(item)[0]
                            #Add buildunit to the exclude list! This can be optimize by excluding the buildunit from subpj_lst, but is only working for true buildunits (not for MTS cfg and dll subprojects).
                            resp = ims.projectinfo(batch=None, project=project_path)
                            shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
                            project_name_flatpath = resp.work_items[0].getField('projectName').value
                            ex_global_sil.add(project_path.upper())
                            ex_global_sil.add(shared_from_flatpath.upper())
                            ex_global_sil.add(project_name_flatpath.upper())

                    subpj_lst = []
                    subpj_lst.append(build_unit_sil)
                    if cfg_outside_buildunit_sil:
                        get_subfolders_outside_buildunits(subpj_lst, ex_global_sil)

                    for item in shared_buildunit_sil:
                        try:
                            subpj_lst.remove(item)
                        except ValueError as e:
                            pass

                    if subpj_lst:
                        configure_buildunit_releaseID(subpj_lst, ex_global_sil, 'SIL')
                    else:
                        logger.info('The "%s" buildunit was configured to shared build so no subproject will be reconfigured!', build_unit_sil)
                else:
                    logger.warning('SIL will NOT be reconfigured (build_mode: "%s", configure_mode: "%s")!', build_mode, configure_mode)

        except APIException as e:
            logger.exception('Exception occurred: %s', e.message) # session closing
            # Nothing to restore!
            sys.exit(1)

        logger.info('Configure subprojects successfully (configure_mode: "%s")', configure_mode)
        if os.path.isfile(file_old_config_rev):
            #TODO: Rename file_old_config_rev
            t = time.localtime()
            timestamp = '_%d%02d%02d_%02d%02d%02d' % (t.tm_year, t.tm_mon, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec)
            root, ext = os.path.splitext(file_old_config_rev)
            new_file = root + timestamp + ext
            os.rename(file_old_config_rev, new_file)

    #TODO: To be moved in IMS class
    except CommandError as e:
        logger.exception('Exception occurred:')
    except APIException as e:
        logger.exception('Exception occurred:')
        print 'Exception catched Message: ' + e.message
        #print 'Exception catched args:\n\t' + '\n'.join([str(arg) for arg in e.fields.args])
        #print 'Exception catched Response: ' + str(e.response)
        print 'Exception catched Class: ' + e.exception_class
        print 'Exception catched Fields: ' + str([str(field) for field in e.fields])
        r = e.response
        #print 'Exception catched e.response Class: ' + str(r.__class__)
        if r.work_items is not None:
            for wi in r.work_items:
                if wi.api_exception is not None:
                    print '\t\t%s' % wi.api_exception.message
                    print '\t\t\t%s' % [str(field) for field in wi.api_exception.fields]
            #print '\n'.join(['\t\t'+wi.api_exception.message for wi in r.work_items if wi.api_exception is not None])
    except TypeError as e:
        cmd = ims.cmdRunner
        print '\nNot enough rights for "%s" on "%s:%s" server!' % (cmd.user, cmd.hostname, cmd.port)
        #resp.work_items will be None if the user doesn't has rights on the server (there is no <WorkItems> in the xml)
        exc_info = sys.exc_info()
        raise exc_info[0], exc_info[1], exc_info[2]

def kill_process(proc, command_string, timeout_occured):
    #TODO: Check here for deadlock!
    #proc.kill() # doesn't kill the children...
    proc = subprocess.Popen("TASKKILL /F /PID {pid} /T".format(pid=proc.pid), shell=True, stdout = subprocess.PIPE, stderr=subprocess.STDOUT)
    stdout, stderr = proc.communicate()
    logger.debug('KILL command output:\n%s', str(stdout).replace('\r\n', '\n')) # looger add an '\r' when it sees an '\n' (it doesn't matter there is one present)
    timeout_occured[0] = True
    logger.error('Timeout has occured on command: "%s". Operation cancelled.', command_string)

def run_cmd(command_string, timeout=None, show_time=True):
    #TODO: Check correct handling of the parameters in command_string!
    command_string = get_absolute_path(command_string)
    if show_time: logger.debug('Run command: "%s"', command_string)

    try:
        proc = None
        timer = None
        timeout_occured = None
        cmd, cwd = get_cmd_cwd(command_string)

        if show_time: start = time.time()

        #TODO: Drop the shell=True and print command output realtime.
        proc = subprocess.Popen(command_string, cwd=cwd, stdout = subprocess.PIPE, stderr=subprocess.STDOUT) #stderr = subprocess.PIPE
        timeout_occured = [False]
        if timeout: timer = Timer(timeout, kill_process, [proc, command_string, timeout_occured])
        if timeout: timer.start()

        logger.debug('Command output:')
        while proc.poll() is None:
            line = proc.stdout.readline()
            line = line.replace('\r\n', '')
            #line = line.replace('\r', '')
            #line = line.replace('\n', '')
            #do not print empty lines
            if line:
                logger.debug(line)
    except WindowsError as e:
        logger.exception('Exception occurred: %s', e.strerror)
    except Exception as e:
        logger.exception('Exception occurred:')
    finally:
        #TODO: Check here for deadlock!
        #if isinstance(timer, _Timer):
        if timer and timeout: timer.cancel()
        if show_time: end = time.time()
        if show_time: logger.debug('Time command "%s": %.2fs', command_string, end - start)

    if not timeout_occured or not proc:
        return False
    if timeout_occured[0]: #timeout_occured and 
        errMessage = 'Command: "%s" timeouts (%.2fs)!' % (command_string, timeout)
        logger.error(errMessage)
        #raise TimeoutError(errMessage)
        return False
    elif proc.returncode is None: #proc and 
        errMessage = 'Command: "%s" was interrupted by the user!' % (command_string)
        logger.error(errMessage)
        #raise CommandError(errMessage)
        return False
    elif proc.returncode != 0: #proc and 
        errMessage = 'Command: "%s" failed with the error code: %d!' % (command_string, proc.returncode)
        logger.error(errMessage)
        #raise CommandError(errMessage)
        return False

    return True

class MyConfigParser(ConfigParser.ConfigParser):
    #ConfigParser is an old-style class, so super can't be used: super(MyConfigParser, self).get(section, option)

    #set default value for missing option (allow empty value)
    def get(self, section, option, default=None):
        value = default
        try:
            value = ConfigParser.ConfigParser.get(self, section, option)
            #if not value: value = default # value is empty string
        except ConfigParser.NoSectionError:
            exc_info = sys.exc_info()
            raise exc_info[0], exc_info[1], exc_info[2]
        except ConfigParser.NoOptionError:
            pass

        return value

    def _get(self, section, conv, option, default=None):
        value = default
        try:
            value = ConfigParser.ConfigParser._get(self, section, conv, option)
            #if not value: value = default # value is empty string
        except ConfigParser.NoSectionError:
            exc_info = sys.exc_info()
            raise exc_info[0], exc_info[1], exc_info[2]
        except TypeError:
            pass
        except ConfigParser.NoOptionError:
            pass

        return value

    #set default value for missing option (throw exception for empty value)
    def getboolean(self, section, option, default=False):
        value = default
        try:
            value = ConfigParser.ConfigParser.getboolean(self, section, option)
        except ValueError:
            #value for boolean types can't be empty
            exc_info = sys.exc_info()
            raise exc_info[0], exc_info[1], exc_info[2]
        except ConfigParser.NoSectionError:
            exc_info = sys.exc_info()
            raise exc_info[0], exc_info[1], exc_info[2]
        except ConfigParser.NoOptionError:
            pass
        except AttributeError:
            #ConfigParser.getboolean() will call MyConfigParser.get() and None is returned (no exception thrown) instead of a value convertible to boolean
            pass

        return value

    #set default value for missing option (throw exception for empty value)
    def getint(self, section, option, default=0):
        #value = default
        try:
            value = ConfigParser.ConfigParser.getint(self, section, option)
        except ValueError:
            #value for int types can't be empty
            exc_info = sys.exc_info()
            raise exc_info[0], exc_info[1], exc_info[2]
            #pass
        except ConfigParser.NoSectionError:
            exc_info = sys.exc_info()
            raise exc_info[0], exc_info[1], exc_info[2]
        except ConfigParser.NoOptionError:
            pass
        except AttributeError:
            #ConfigParser.getint() will call MyConfigParser.get() and None is returned (no exception thrown) instead of a value convertible to boolean
            pass

        if value is None:
            value = default
        return value

    #use default=[] - to guarantee all lists read from configuration are initialized (not None)
    def getlist(self, section, option, default=None):
        opt_values = self.get(section, option) #, default='' #.strip()
        if not opt_values:
            values = default
        else:
            values = [value.strip() for value in opt_values.split(',') if value.strip()] # ci_file.strip() != ''
        '''print values
        print '%s (%s):' % (section, option)
        if not values:
            print 'No value found!'
        else:
            print '\n'.join(values)
        '''
        return values

    #default and default_bool are default values if option is missing (for getboolean if value is empty/missing exception is thrown!)
    def get_ex_sections(self, default=None, default_bool=False):
        #known_sections = ['IMS', 'MFC431', 'PROJECT', 'SANDBOX', 'CHECK_IN', 'EXCEPTION_CONFIGURE']
        ex_files = []
        for section in self.sections():
            if section.lower().find('/project.pj') != -1:
                revision = self.get(section, 'revision', default)
                configure = self.getboolean(section, 'configure', default_bool)
                ex_files.append((section, revision, configure))
        #This sections define subprojects to be configured to a specific revision (different from 'latest') in case of configure_mode = latest
        #and NOT present in a release in case of configure_mode = releaseID
        '''print ex_files
        print 'Subprojects configured independently to a specific revision (or only verify that\'s the case):'
        print '\n'.join(str(s) for s in ex_files)
        '''
        return ex_files


def create_logger(filename, overwrite=False):
    loggerName = filename[:filename.rfind(".")]
    #print 'logger = ' + loggerName
    '''
    logging.basicConfig(filename=filename, filemode=('w' if overwrite else 'a'), level=logging.DEBUG, format='%(asctime)s [%(levelname)s]: %(message)s', datefmt='%d/%m/%Y %H:%M:%S')
    '''
    # create logger with loggerName
    logger = logging.getLogger(loggerName)
    logger.setLevel(logging.DEBUG)
    # create file handler which logs even debug messages
    fh = logging.FileHandler(filename, mode=('w' if overwrite else 'a'))
    fh.setLevel(logging.DEBUG)
    # create console handler (with a higher log level: logging.ERROR)
    ch = logging.StreamHandler()
    ch.setLevel(logging.DEBUG)
    # create formatter and add it to the handlers
    formatter = logging.Formatter('%(asctime)s [%(levelname)s]: %(message)s', datefmt='%d/%m/%Y %H:%M:%S') #- %(name)s - 
    fh.setFormatter(formatter)
    ch.setFormatter(formatter)
    # add the handlers to the logger
    logger.addHandler(fh)
    logger.addHandler(ch)

    '''logger levels
    logger.debug('Debug')
    logger.info('Info')
    logger.warning('Warning')
    logger.error('Error')
    logger.critical('Critical')
    '''
    #return logger
    pass

def restore_configure_subprojects(filepath): #, removeFile=False
    # TODO: Update to support closing the change package via a parameter.
    logger.info('Start reconfiguring subprojects from file: "%s" (restore mode)', filepath)
    if not os.path.isfile(filepath):
        logger.error('File not found: %s.\n\t\tPlease check INI option "file_old_config_rev" in "CONFIGURATION" section!', filepath)
        sys.exit(1)
    with open(filepath, 'r') as f:
        for line in f.readlines():
            # No needed to handle build-shared-subproject inside another one as the file will not contain those subprojects (filtered out in 'configure_subprojects').
            name, subpj_type, rev = line.split()
            if subpj_type != ShareType.SHARED_BUILD_SUBPROJECT:
                continue
            try:
                project_path, proj, subproj = get_proj_subproj(name)
                #do not specify 'devpath' as '#d=TEST_PARALLEL_BRANCH' as is already present in 'proj'
                resp = ims.configuresubproject(subproj, batch=None, cpid=cpid, type='build', subprojectRevision=rev, project=proj)
            except APIException as e:
                message = get_exception_message(e)
                logger.exception('Exception occurred: %s', message)
                sys.exit(1)
    logger.info('Subprojects successfully restored from file "%s"', filepath)
    #TODO: Rename file_old_config_rev
    t = time.localtime()
    timestamp = '_%d%02d%02d_%02d%02d%02d' % (t.tm_year, t.tm_mon, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec)
    root, ext = os.path.splitext(filepath)
    new_file = root + timestamp + ext
    os.rename(filepath, new_file)
    '''
    #If restored succeded and removeFile=True, remove the file containing old revisions
    #if removeFile:
    #    logger.info('Removing file containing reconfiguring subprojects: "%s"', filepath)
    #    os.remove(filepath)
    #else:
    #    logger.info('File containing reconfiguring subprojects NOT removed: "%s". You will need to provide the "--force" flag next time...', filepath)
    '''

#proj_path must be an absolute path (flat or config)
def get_proj_trunk_rev(proj_path):
    trunk_rev = None # ':trunktip'
    project_path, proj, subproj = get_trunk_proj_subproj(proj_path)
    '''
    resp = ims.viewproject(batch=None, project=proj)
    for item in resp.work_items:
        if item.display_id == proj_path:
            rev_field = item.getField('memberrev')
            if rev_field: trunk_rev = rev_field.item.id
            else: trunk_rev = None
            break
    if not trunk_rev:
        trunk_rev = get_proj_head_rev(proj_path)
    '''
    try:
        resp = ims.projectinfo(batch=None, project=project_path)
        item = resp.work_items[0]
        project_type = item.getField('projectType').value
        if project_type != ProjectType.BUILD:
            logger.warning('Subproject "%s" is NOT configured as build on trunk so we use latest revision!"', project_path)
        trunk_rev = item.getField('revision').item.id
    except APIException as e:
        if e.exception_class == 'ItemNotFoundException':
            logger.warning('Subproject "%s" was dropped in the meantime from the trunk...', proj_path)
        else:
            message = get_exception_message(e)
            logger.exception('Exception occurred: %s', message)
        logger.warning('The latest revision will be used for subproject "%s" on devpath "%s"!"', proj_path, devpath)
        trunk_rev = ':head'

    return trunk_rev

#proj_path must be an absolute path (flat or config)
def get_proj_head_rev(proj_path):
    head_rev = ':head'
    r = ims.viewprojecthistory(batch=None, project=proj_path)
    revisions_field = r.work_items[0].getField('revisions').item_list
    for item in revisions_field:
        #revisions are sorted in decreasing order, so the first 'x.y' found is the head revision
        #there are exceptions like 'x.y.0.0.z.0', z = very large number, but it's safe to ignore them (checkpoints to restore content)?!
        rev = item.getField('revision').item.id
        rev_count = rev.count('.')
        revs = rev.split('.')
        if rev_count == 1 or (rev_count == 5 and revs[2] == '0' and revs[3] == '0' and revs[5] == '0'):
            head_rev = rev
            break
    return head_rev

def configure_buildunit_latest(subpj_lst, ex_global, build_unit_name, match_trunk=False):
    if match_trunk:
        logger.info('All subprojects will be updated to trunk revision (%s)!', build_unit_name)
    else:
        logger.info('All subprojects will be configured to latest available revision (%s)', build_unit_name)

    try:
        if not subpj_lst:
            logger.error('No subproject found for "%s" build unit in configuration file (build_mode: "%s", configure_mode: "%s")!', build_unit_name, build_mode, configure_mode)
            sys.exit(6)

        resp = ims.viewproject(*subpj_lst, batch=None, recurse=None, project=base_project, devpath=devpath, filter='!file:*')

        with open(file_old_config_rev, 'a+') as f:
            # Get the list of 'shared build subprojects' (all the other subprojects types should be ignored)
            for item in resp.work_items:
                #TODO: Exlude all children of an excluded subproject, it could be optimize to jump over all children.
                # it's 'cheaper' to first check if a child's parent is in exclude list (using configpath from variant branch) - no need for running 'projectinfo' command
                # do not filter by ShareType.SHARED_BUILD_SUBPROJECT
                # as there can be normal (shared) subprojects that contains such suprojects - just in theory?
                # or user choose to exclude a normal subproject that contains such suprojects - do we need support for this?
                if item.parent_id.upper() in ex_global:
                    logger.info('Subproject\'s (grand)parent found in exception list, it will not be configured: "%s"...', item.id)
                    # exclude it using configpath from variant branch, so it's children can be easily excluded (without running 'projectinfo' command on them)
                    ex_global.add(item.id.upper())
                    continue
    
                subpj_type = item.getField('type').value
                rev_field = item.getField('memberrev')
                if not rev_field: rev = None
                else: rev = rev_field.item.id
    
                #There should be no normal or variant shared subprojects because we branch from a checkpoint, but just in case somebody manually reconfigure...
                if subpj_type == ShareType.ARCHIVED:
                    #f.write('%s\t%s\t%s\n' % (item.getField('name').value, subpj_type, rev))
                    pass
                elif subpj_type == ShareType.SUBPROJECT:
                    #f.write('%s\t%s\t%s\n' % (item.id, subpj_type, rev))
                    pass
                elif subpj_type == ShareType.BUILD_SUBPROJECT:
                    #f.write('%s\t%s\t%s\n' % (item.id, subpj_type, rev))
                    # TODO: Sometimes integrators are creating a subproject in the repository, instead of sharing it from another location!
                    # /ADAS/SW/Projects/MFC431x/MFC431/M11_APPL/03_Design/03_Code_Generation/Project_Specific/MFC431BD10/Tresos/project.pj
                    # vs
                    # /ADAS/SW/Integration/PRJCFG_MFC431x/MFC431/M11_APPL/03_Design/03_Code_Generation/Project_Specific/MFC431SC19/Tresos/project.pj
                    # ex_global.add(item.id.upper())
                    # continue
                    pass
                elif subpj_type == ShareType.VARIANT_SUBPROJECT:
                    #f.write('%s\t%s\t%s\n' % (item.id, subpj_type, rev))
                    pass
                elif subpj_type == ShareType.SHARED_SUBPROJECT:
                    #f.write('%s\t%s\t%s\n' % (item.id, subpj_type, rev))
                    pass
                elif subpj_type == ShareType.SHARED_VARIANT_SUBPROJECT:
                    #f.write('%s\t%s\t%s\n' % (item.id, subpj_type, rev))
                    pass
                elif subpj_type == ShareType.SHARED_BUILD_SUBPROJECT:
                    #check if item is in exclude list using repository location (a flatpath)
                    r = ims.projectinfo(batch=None, project=item.id)
                    project_location = r.work_items[0].getField('projectName').value
                    shared_location = r.work_items[0].getField('sharedFrom').value
                    if shared_location.upper() in ex_global or project_location.upper() in ex_global:
                        logger.info('Subproject found in exception list, it will not be configured: "%s"', item.id)
                        #add it again with configpath from variant branch, so it's children can be easily excluded (without running 'projectinfo' command on them)
                        ex_global.add(item.id.upper())
                        continue
                    
                    #TODO: Move it up! Add item.id to exception list so it's children won't be taken into consideration to be configured
                    ex_global.add(item.id.upper())
    
                    #TODO: Configure to the latest revision of the subproject (or it should be the latest revision of the component - /ADAS/SW/Components/<component>?)
                    #      See 'configure_releaseID' function if needs to ensure that (be sure only use it for components as not all shared subprojects are components).
                    try:
                        if not match_trunk:
                            #TODO: Optimize by first check if the current revision is not the latest!
                            dp, head_rev = get_devpath_from_build(item.id)
                            if rev != head_rev:
                                f.write('%s\t%s\t%s\n' % (item.id, subpj_type, rev))
                                logger.info('Configure subproject "%s" from revision "%s" to revision "%s"', item.id, rev, head_rev)
                                #do not specify 'devpath' as '#d=TEST_PARALLEL_BRANCH' as is already present in 'item.parent_id'
                                r = ims.configuresubproject(item.display_id, batch=None, cpid=cpid, type='build', subprojectRevision=head_rev, project=item.parent_id)
                                pass
                            else:
                                logger.info('Subproject "%s" is already configured to latest revision ("%s")...', item.id, head_rev) #rev
                        else:
                            #TODO: Optimize by first check if the current revision is not the trunk revision!
                            trunk_rev = get_proj_trunk_rev(item.display_id) # trunk revision or latest revision
                            if trunk_rev and rev != trunk_rev:
                                f.write('%s\t%s\t%s\n' % (item.id, subpj_type, rev))
                                logger.info('Configure subproject "%s" from revision "%s" to revision "%s" (trunk)', item.id, rev, trunk_rev)
                                #do not specify 'devpath' as '#d=TEST_PARALLEL_BRANCH' as is already present in 'item.parent_id'
                                r = ims.configuresubproject(item.display_id, batch=None, cpid=cpid, type='build', subprojectRevision=trunk_rev, project=item.parent_id)
                                pass
                            else:
                                logger.info('Subproject "%s" is already configured to trunk revision ("%s")...', item.id, trunk_rev) #rev
                    except APIException as e:
                        message = get_exception_message(e)
                        logger.exception('Exception occurred: %s', message)
                        sys.exit(1)
                elif subpj_type == ShareType.PENDING_CONFIGURE_SUBPROJECT:
                    #f.write('%s\t%s\t%s\n' % (item.getField('name').value, subpj_type, rev))
                    logger.warning('Subproject in "pending-configure-subproject" state detected: "%s"!', item.id)
                else: #unknown subproject type
                    logger.warning('Subproject of unkonwn type ("%s") found, it will not be configured: "%s"', subpj_type, item.id)
                    f.write('%s\t%s\t%s\n' % (item.id, subpj_type, rev))
    except SystemExit as e:
        #print "Exit with error number: " + str(e.code)
        logger.exception('Exception occurred:')
        sys.exit(e.code)

def get_subfolders_outside_buildunits(subpj_lst, ex_global=[]):
    used_build_units = []
    if build_unit_iuc: # this will throw exception if the project does not have a IuC build unit!
        used_build_units.append(build_unit_iuc)
    if build_unit_dpu: # this will throw exception if the project does not have a DPU build unit!
        used_build_units.append(build_unit_dpu)
    if build_unit_sil: # this will throw exception if the project does not have a SIL build unit!
        used_build_units.append(build_unit_sil)
    resp = ims.viewproject(batch=None, norecurse=None, project=base_project, devpath=devpath, filter='!file:*')
    for wi in resp.work_items:
        subproj = get_proj_subproj(wi.display_id)[2]
        r = ims.projectinfo(batch=None, project=wi.id)
        shared_location = r.work_items[0].getField('sharedFrom').value #Exclude BLUP, BRES, UFBL (shared build) by searching them in exclude list.
        if subproj not in used_build_units and shared_location.upper() not in ex_global:
            subpj_lst.append(subproj)

#check a single change package for pending entries
def pending_entries_cp(cpid):
    resp = ims.viewcp(cpid)
    for item in resp.work_items[0].getField('MKSEntries').item_list:
        if item.getField('type').item.getField('isPending').value == True:
            return True
    return False

#check a single change package for closed state
def closed_cp(cpid):
    resp = ims.viewcp(cpid)
    if resp.work_items[0].getField('state').value == ChangePackageState.CLOSED:
        return True
    else:
        return False

#check a single change package for sumitted state
def submitted_cp(cpid):
    resp = ims.viewcp(cpid)
    if resp.work_items[0].getField('state').value == ChangePackageState.SUBMITTED:
        return True
    else:
        return False

def create_cp(ro, step_str):
    global cpid
    try:
        resp = ims.createcp(batch=None, issueId=ro, summary='[ais][%s][%s] ' % (project, devpath) + step_str, description='Automatically created change package')
        cpid = resp.result.primary_value.item.id
        return cpid
    except APIException as e:
        message = get_exception_message(e)
        logger.exception('Exception occurred: %s', message)
        sys.exit(10)

# close a change package, handle the cp-review as well; should we update member revision?
def close_cp(cpid):
    no_retries = 2
    retries = 2
    while True:
        exc_info = None
        #review_needed = pending_entries_cp(cpid)
        resp = ims.submitcp(cpid, batch=None, closeCP=None) #, nocloseCP=None, confirmcommit=None
        #review_needed = not closed_cp(cpid)
        review_needed = submitted_cp(cpid)
        if review_needed:
            #user = 'uidt997z'
            #password = os.environ[user]
            try:
                #resp = ims.acceptcp(cpid, batch=None, comments='Automatically accepted change package by ais', reviewer='group:__MainstreamReviewer', user=user, password=password) #, forceconfirm=None, yes=None | super, all
                resp = ims.acceptcp(cpid, batch=None, comments='Automatically accepted change package by ais', reviewer='group:__MainstreamReviewer') #, forceconfirm=None, yes=None | super, all
            except APIException as e:
                logger.exception('Exception occurred: %s', e.message)
                exc_info = sys.exc_info()
                resp = ims.opencp(cpid, batch=None)
                state = resp.work_items[0].result.message
                if state != 'opened':
                    logger.warning('Change package "%s" could not be re-opened (state is %s)...', cpid, state)
                logger.info('Wait for 10s and retry %s/%s...', no_retries-retries+1, no_retries)
                time.sleep(10)
            except Exception as e:
                logger.warning('[close_cp] Disable retry functionality because a different type of exception occurred (not APIException)')
                logger.exception('Exception occurred:')
                exc_info = sys.exc_info()
                retries = 0
            else:
                break
            finally:
                if exc_info:
                    if retries == 0:
                        raise exc_info[0], exc_info[1], exc_info[2]
                elif not exc_info and retries < no_retries:
                    logger.info('[close_cp] Retrying really works!')
                retries -= 1
        else:
            break
    #resp = ims.disconnect_source(batch=None, noconfirm=None, user=user) # all acounts will use the same server!

#return a string of comma-separated parameters keys that has value True: summary_cp(param1=True, param2=False, param3=True, param4=False) --> "param1, param3"
def summary_helper_cp(**kwargs):
    lst = []
    for key, value in kwargs.iteritems():
        if value:
            lst.append(key)
    if lst:
        return ', '.join(lst)
    else:
        return 'no buildunit, no option'

def update_members_to_trunk_rev(update_membs_to_trunk_rev, build_unit_name):
    if update_membs_to_trunk_rev:
        logger.info('All members from "update_members_to_trunk_rev" list will be updated to trunk revision (%s):\n\t%s', build_unit_name, '\n\t'.join(update_membs_to_trunk_rev))
        for item in update_membs_to_trunk_rev:
            #TODO: Update only if different!
            member_path, proj, member = get_proj_member(item)
            proj_trunk = os.path.split(member_path)[0] + '/project.pj'
            resp = ims.memberinfo(member, batch=None, project=proj_trunk)
            rev = resp.work_items[0].getField('memberrevision').value
            logger.info('Configure member "%s" to trunk revision "%s"', item, rev)
            resp = ims.updaterevision(member, batch=None, cpid=cpid, nocloseCP=None, revision=rev, project=proj)
    else:
        logger.info('No member was found in "update_members_to_trunk_rev" list (%s)!', build_unit_name)

def update_subprojects_to_trunk_rev(update_subpj_to_trunk_rev, build_unit_name):
    if update_subpj_to_trunk_rev:
        logger.info('All subprojects from "update_subpj_to_trunk_rev" list will be updated to trunk revision (%s):\n\t%s', build_unit_name, '\n\t'.join(update_subpj_to_trunk_rev))
        for item in update_subpj_to_trunk_rev:
            project_path, proj, subproj = get_trunk_proj_subproj(item)
            resp = ims.projectinfo(batch=None, project=project_path)
            project_type = resp.work_items[0].getField('projectType').value
            if project_type != ProjectType.BUILD:
                logger.warning('Subproject "%s" is NOT configured as build so it will be set as latest on "%s" devpath!"', project_path, devpath)
            project_rev = resp.work_items[0].getField('revision').item.id
            project_path, proj, subproj = get_proj_subproj(item)
            logger.info('Configure subproject "%s" to trunk revision "%s"', item, project_rev)
            resp = ims.configuresubproject(subproj, batch=None, cpid=cpid, type='build', subprojectRevision=project_rev, project=proj)
    else:
        logger.info('No subproject was found in "update_subpj_to_trunk_rev" list (%s)', build_unit_name)

def configure_subprojects(force=False, recover=False, iuc=False, dpu=False, sil=False): #Step 1
    global update_subpj_to_trunk_rev_iuc, update_subpj_to_trunk_rev_dpu, update_subpj_to_trunk_rev_sil

    logger.debug('Step 1 - Pre build actions: Configure subprojects')
    logger.debug('*'*50)

    #logger.debug('Create change package')
    new_cpid = create_cp(ro, 'Step: configure_subprojects (%s)' % summary_helper_cp(iuc=iuc, dpu=dpu, sil=sil, recover=recover, force=force))
    logger.debug('Create change package: %s', new_cpid)

    # Check if "--recover" or "--force" flag was provided...
    if os.path.isfile(file_old_config_rev) and recover:
        logger.info('Restoring the previous revision of the subprojects from "%s" file because "--recover" flag was provided.', file_old_config_rev)
        restore_configure_subprojects(file_old_config_rev) #, removeFile=False
        return
    elif not os.path.isfile(file_old_config_rev) and recover:
        logger.error('Cannot restore the previous revision of the subprojects because "%s" file is misssing.', file_old_config_rev)
        return
    elif os.path.isfile(file_old_config_rev) and not force:
        logger.error('A previous attempt to (re)configure subprojects was unsuccessfully, see "%s" file.', file_old_config_rev)
        logger.error('Provide "--force" flag to force new configuration or "--recover" flag to recover old configuration!')
        sys.exit(1)
    elif os.path.isfile(file_old_config_rev) and force:
        logger.info('Overwrite "%s" file containing previous configuration of subprojects because "--force" flag was provided!', file_old_config_rev)
        os.remove(file_old_config_rev)

    # For nightlybuilds this subcommand must be called with all build units "--iuc --dpu --sil"!
    if not iuc and not dpu and not sil:
        logger.error('No build unit provided (build_mode: "%s", configure_mode: "%s")!', build_mode, configure_mode)
        sys.exit(6)

    #TODO: Check if all required parameters were provided and are correct (command line, INIs), eg.: base_project, devpath, cpid etc.
    logger.debug('Configure mode: "%s"', configure_mode)
    cfg_mode = ['latest', 'releaseID']
    if configure_mode not in cfg_mode:
        #TODO: Raise exception!
        logger.error('"configure_mode" must be one of: %s ("%s")', cfg_mode, configure_mode)
        sys.exit(1)

    logger.debug('Build mode: "%s"', build_mode)
    accepted_build_mode = ['IuC', 'DPU', 'BOTH']
    if build_mode not in accepted_build_mode:
        #TODO: Raise exception!
        logger.error('Wrong build_mode provided in INI file: "%s" (must be one of %s)', build_mode, accepted_build_mode)
        sys.exit(2)

    if ex_sections_files:
        logger.debug('Subprojects to be configured independently to a specific revision (or only verify that\'s the case):\n\t%s', '\n\t'.join([str(subpj[0]) for subpj in ex_sections_files]))

    if configure_mode == 'latest':
        logger.debug('Configure to latest...')
        #TODO: Also consider as exceptions all 'shared-build-subproject'(s) with a revision formed from more then 2 sets of numbers (eg.: a.b.c.d) - for nightlybuild?
        # Add to exception list special sections from ini files
        ex_global = set([proj[0].upper() for proj in ex_sections_files])
        ex_global_iuc = set(ex_global)
        ex_global_dpu = set(ex_global)
        ex_global_sil = set(ex_global)

        #TODO: Should exception list(s) be used by nighlybuilds as well?
        if build_mode in ['IuC', 'BOTH'] and iuc and ex_files_iuc:
            ex_global_iuc.update(item.upper() for item in ex_files_iuc)
        if build_mode in ['DPU', 'BOTH'] and dpu and ex_files_dpu:
            ex_global_dpu.update(item.upper() for item in ex_files_dpu)
        if build_mode in ['DPU', 'BOTH'] and sil and ex_files_sil:
            ex_global_sil.update(item.upper() for item in ex_files_sil)

        try:
            #TODO: Only reconfigure subprojects based on build units passed as parameters
            # Make it generic by adding options in configuration file: builunit_iuc = M11_APPL, builunit_dpu = DPU, MTS

            if build_mode in ['IuC', 'BOTH']:
                if iuc:
                    logger.debug('IuC will be reconfigured...')

                    #TODO: Configure shared buildunits as well (Application Projects).
                    #devpaths_iuc = []
                    for item in shared_buildunit_iuc:
                        project_path = get_proj_subproj(item)[0]
                        #Add buildunit to the exclude list! This can be optimize by excluding the buildunit from subpj_lst, but is only working for true buildunits (not for MTS cfg and dll subprojects).
                        resp = ims.projectinfo(batch=None, project=project_path)
                        shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
                        project_name_flatpath = resp.work_items[0].getField('projectName').value
                        ex_global_iuc.add(project_path.upper())
                        ex_global_iuc.add(shared_from_flatpath.upper())
                        ex_global_iuc.add(project_name_flatpath.upper())
                        subproject_devpath = configure_project_build(project_path)[0] #no need for subpj_devpath=devpath_buildunits_iuc[item] as the variant is automatically determined
                        #devpaths_iuc.append(subproject_devpath)
                    if cfg_prev_cp_iuc:
                        for item in cfg_prev_cp_iuc:
                            project_path = get_proj_subproj(item)[0]
                            #Add buildunit to the exclude list! This can be optimize by excluding the buildunit from subpj_lst, but is only working for true buildunits (not for MTS cfg and dll subprojects).
                            resp = ims.projectinfo(batch=None, project=project_path)
                            shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
                            project_name_flatpath = resp.work_items[0].getField('projectName').value
                            ex_global_iuc.add(project_path.upper())
                            ex_global_iuc.add(shared_from_flatpath.upper())
                            ex_global_iuc.add(project_name_flatpath.upper())
                            #subproject_devpath = configure_project_build(project_path)[0] #no need for subpj_devpath=devpath_buildunits_iuc[item] as the variant is automatically determined
                            #devpaths_iuc.append(subproject_devpath)
                    #TODO: Proper handling the excluding in the ex_files list!!! This is due to the fact that cfg_prev_cp_sil contains subporjects outside of SIL!
                    if 'SIL' in build_units and cfg_prev_cp_sil:
                        for item in cfg_prev_cp_sil:
                            project_path = get_proj_subproj(item)[0]
                            #Add buildunit to the exclude list! This can be optimize by excluding the buildunit from subpj_lst, but is only working for true buildunits (not for MTS cfg and dll subprojects).
                            resp = ims.projectinfo(batch=None, project=project_path)
                            shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
                            project_name_flatpath = resp.work_items[0].getField('projectName').value
                            ex_global_iuc.add(project_path.upper())
                            ex_global_iuc.add(shared_from_flatpath.upper())
                            ex_global_iuc.add(project_name_flatpath.upper())
                            #subproject_devpath = configure_project_build(project_path)[0] #no need for subpj_devpath=devpath_buildunits_iuc[item] as the variant is automatically determined
                            #devpaths_iuc.append(subproject_devpath)
                    '''
                    file_devpaths_iuc = 'devpaths_iuc.txt'
                    with open(file_devpaths_iuc, 'w') as f:
                        pickle.dump(devpaths_iuc, f)
                    '''
                    subpj_lst = []
                    subpj_lst.append(build_unit_iuc)
                    if cfg_outside_buildunit_iuc:
                        get_subfolders_outside_buildunits(subpj_lst, ex_global_iuc)

                    for item in shared_buildunit_iuc:
                        try:
                            subpj_lst.remove(item)
                        except ValueError as e:
                            pass

                    if subpj_lst:
                        if update_all_subpj_to_trunk_rev_iuc:
                            ex_global_iuc = set()
                            update_subpj_to_trunk_rev_iuc = [] # empty the list so "update_subprojects_to_trunk_rev" won't have any effect
                        elif update_subpj_to_trunk_rev_iuc: # update from "update_subpj_to_trunk_rev" list only if "update_all_subpj_to_trunk_rev_iuc" is false
                            ex_global_iuc.update(item.upper() for item in update_subpj_to_trunk_rev_iuc)
                        configure_buildunit_latest(subpj_lst, ex_global_iuc, 'IuC', update_all_subpj_to_trunk_rev_iuc)
                        update_subprojects_to_trunk_rev(update_subpj_to_trunk_rev_iuc, 'IuC') # must be called after "configure_buildunit_latest" so there will be no subproject in pending state
                        update_members_to_trunk_rev(update_members_to_trunk_rev_iuc, 'IuC')
                    else:
                        logger.info('The "%s" buildunit was configured to shared build so no subproject will be reconfigured!', build_unit_iuc)
                else:
                    logger.warning('IuC will NOT be reconfigured (build_mode: "%s", configure_mode: "%s")!', build_mode, configure_mode)

            if build_mode in ['DPU', 'BOTH']:
                if dpu:
                    logger.debug('DPU will be reconfigured...')

                    #TODO: Configure shared buildunits as well (Application Projects).
                    #devpaths_dpu = []
                    for item in shared_buildunit_dpu:
                        project_path = get_proj_subproj(item)[0]
                        #Add buildunit to the exclude list! This can be optimize by excluding the buildunit from subpj_lst, but is only working for true buildunits (not for MTS cfg and dll subprojects).
                        resp = ims.projectinfo(batch=None, project=project_path)
                        shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
                        project_name_flatpath = resp.work_items[0].getField('projectName').value
                        ex_global_dpu.add(project_path.upper())
                        ex_global_dpu.add(shared_from_flatpath.upper())
                        ex_global_dpu.add(project_name_flatpath.upper())
                        subproject_devpath = configure_project_build(project_path)[0] #no need for subpj_devpath=devpath_buildunits_dpu[item] as the variant is automatically determined
                        #devpaths_dpu.append(subproject_devpath)
                    if cfg_prev_cp_dpu:
                        for item in cfg_prev_cp_dpu:
                            project_path = get_proj_subproj(item)[0]
                            #Add buildunit to the exclude list! This can be optimize by excluding the buildunit from subpj_lst, but is only working for true buildunits (not for MTS cfg and dll subprojects).
                            resp = ims.projectinfo(batch=None, project=project_path)
                            shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
                            project_name_flatpath = resp.work_items[0].getField('projectName').value
                            ex_global_dpu.add(project_path.upper())
                            ex_global_dpu.add(shared_from_flatpath.upper())
                            ex_global_dpu.add(project_name_flatpath.upper())
                            #subproject_devpath = configure_project_build(project_path)[0] #no need for subpj_devpath=devpath_buildunits_dpu[item] as the variant is automatically determined
                            #devpaths_dpu.append(subproject_devpath)
                    '''
                    file_devpaths_dpu = 'devpaths_dpu.txt'
                    with open(file_devpaths_dpu, 'w') as f:
                        pickle.dump(devpaths_dpu, f)
                    '''
                    subpj_lst = []
                    subpj_lst.append(build_unit_dpu)
                    if cfg_outside_buildunit_dpu:
                        get_subfolders_outside_buildunits(subpj_lst, ex_global_dpu)

                    for item in shared_buildunit_dpu:
                        try:
                            subpj_lst.remove(item)
                        except ValueError as e:
                            pass

                    if subpj_lst:
                        if update_all_subpj_to_trunk_rev_dpu:
                            ex_global_dpu = set()
                            update_subpj_to_trunk_rev_dpu = [] # empty the list so "update_subprojects_to_trunk_rev" won't have any effect
                        elif update_subpj_to_trunk_rev_dpu: # update from "update_subpj_to_trunk_rev" list only if "update_all_subpj_to_trunk_rev_dpu" is false
                            ex_global_dpu.update(item.upper() for item in update_subpj_to_trunk_rev_dpu)
                        configure_buildunit_latest(subpj_lst, ex_global_dpu, 'DPU', update_all_subpj_to_trunk_rev_dpu)
                        update_subprojects_to_trunk_rev(update_subpj_to_trunk_rev_dpu, 'DPU') # must be called after "configure_buildunit_latest" so there will be no subproject in pending state
                        update_members_to_trunk_rev(update_members_to_trunk_rev_dpu, 'DPU')
                    else:
                        logger.info('The "%s" buildunit was configured to shared build so no subproject will be reconfigured!', build_unit_dpu)
                else:
                    logger.warning('DPU will NOT be reconfigured (build_mode: "%s", configure_mode: "%s")!', build_mode, configure_mode)

                if sil:
                    logger.debug('SIL will be reconfigured...')

                    #TODO: Configure shared buildunits as well (Application Projects).
                    #devpaths_sil = []
                    for item in shared_buildunit_sil:
                        project_path = get_proj_subproj(item)[0]
                        #Add buildunit to the exclude list! This can be optimize by excluding the buildunit from subpj_lst, but is only working for true buildunits (not for MTS cfg and dll subprojects).
                        resp = ims.projectinfo(batch=None, project=project_path)
                        shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
                        project_name_flatpath = resp.work_items[0].getField('projectName').value
                        ex_global_sil.add(project_path.upper())
                        ex_global_sil.add(shared_from_flatpath.upper())
                        ex_global_sil.add(project_name_flatpath.upper())
                        subproject_devpath = configure_project_build(project_path)[0] #no need for subpj_devpath=devpath_buildunits_sil[item] as the variant is automatically determined
                        #devpaths_sil.append(subproject_devpath)
                    if cfg_prev_cp_sil:
                        for item in cfg_prev_cp_sil:
                            project_path = get_proj_subproj(item)[0]
                            #Add buildunit to the exclude list! This can be optimize by excluding the buildunit from subpj_lst, but is only working for true buildunits (not for MTS cfg and dll subprojects).
                            resp = ims.projectinfo(batch=None, project=project_path)
                            shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
                            project_name_flatpath = resp.work_items[0].getField('projectName').value
                            ex_global_sil.add(project_path.upper())
                            ex_global_sil.add(shared_from_flatpath.upper())
                            ex_global_sil.add(project_name_flatpath.upper())
                            #subproject_devpath = configure_project_build(project_path)[0] #no need for subpj_devpath=devpath_buildunits_sil[item] as the variant is automatically determined
                            #devpaths_sil.append(subproject_devpath)
                    '''
                    file_devpaths_sil = 'devpaths_sil.txt'
                    with open(file_devpaths_sil, 'w') as f:
                        pickle.dump(devpaths_sil, f)
                    '''
                    subpj_lst = []
                    subpj_lst.append(build_unit_sil)
                    if cfg_outside_buildunit_sil:
                        get_subfolders_outside_buildunits(subpj_lst, ex_global_sil)

                    for item in shared_buildunit_sil:
                        try:
                            subpj_lst.remove(item)
                        except ValueError as e:
                            pass

                    if subpj_lst:
                        if update_all_subpj_to_trunk_rev_sil:
                            ex_global_sil = set()
                            update_subpj_to_trunk_rev_sil = [] # empty the list so "update_subprojects_to_trunk_rev" won't have any effect
                        elif update_subpj_to_trunk_rev_sil: # update from "update_subpj_to_trunk_rev" list only if "update_all_subpj_to_trunk_rev_sil" is false
                            ex_global_sil.update(item.upper() for item in update_subpj_to_trunk_rev_sil)
                        configure_buildunit_latest(subpj_lst, ex_global_sil, 'SIL', update_all_subpj_to_trunk_rev_sil)
                        update_subprojects_to_trunk_rev(update_subpj_to_trunk_rev_sil, 'SIL') # must be called after "configure_buildunit_latest" so there will be no subproject in pending state
                        update_members_to_trunk_rev(update_members_to_trunk_rev_sil, 'SIL')
                    else:
                        logger.info('The "%s" buildunit was configured to shared build so no subproject will be reconfigured!', build_unit_sil)
                else:
                    logger.warning('SIL will NOT be reconfigured (build_mode: "%s", configure_mode: "%s")!', build_mode, configure_mode)
        except APIException as e:
            logger.exception('Exception occurred: %s', e.message) # session closing
            sys.exit(1)

        logger.info('Configure subprojects successfully (configure_mode: "%s")', configure_mode)
        if os.path.isfile(file_old_config_rev):
            #TODO: Rename file_old_config_rev
            t = time.localtime()
            timestamp = '_%d%02d%02d_%02d%02d%02d' % (t.tm_year, t.tm_mon, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec)
            root, ext = os.path.splitext(file_old_config_rev)
            new_file = root + timestamp + ext
            os.rename(file_old_config_rev, new_file)

    elif configure_mode == 'releaseID':
        #TODO: Get the list of revisions of components from a releaseID (for each project that is not in the exception list)
        if not releaseID:
            #TODO: Raise exception!
            sys.exit(1)
        logger.debug('Configure using releaseID: "%s"...', releaseID)

        configure_releaseID(iuc, dpu, sil)

    logger.debug('Close change package: %s', cpid)
    close_cp(cpid)
    logger.debug('TO BE DONE...')

def delete_nonmembers():
    sandbox_ims = os.path.join(sandbox, 'project.pj').replace('\\', '/')
    resp = ims.viewnonmembers(batch=None, sandbox=sandbox_ims, recurse=None, cwd=sandbox) #includeFormers, fields
    if resp.work_items:
        logger.info('Delete non-member(s) found:')
        for wi in resp.work_items:
            f = wi.display_id
            logger.info('\t"%s"', f)
            os.chmod(f, stat.S_IWRITE)
            os.remove(f)

def project_resync(del_non_members=False, resync_list=None): #Step 2
    logger.debug('Step 2 - Pre build actions: Resync (sub)project(s)')
    logger.debug('*'*50)
    logger.debug('Project: "%s"', base_project)
    logger.debug('Sandbox: "%s"', sandbox)

    try:
        if resync_list is None:
            # Resync entire sandbox if 'resync_subprojects = project.pj' was specified in configuration file! The list of relative paths is transform in 'read_config'
            if resync_subprojects and resync_subprojects[0][len(sandbox):] == '/project.pj':
                logger.info('Resync entire sandbox!')
                resp = ims.resync(batch=None, recurse=None, overwriteChanged=None, sandbox=resync_subprojects[0])
            elif resync_subprojects:
                logger.info('Resync sandbox:\n\t%s', '\n\t'.join(resync_subprojects))
                #TODO: Run one command per subprobject to reduce chances to timout or better DISABLE or INCREASE timeout
                resp = ims.resync(*resync_subprojects, batch=None, recurse=None, overwriteChanged=None, includeDropped=None, nomerge=None) # overwriteIfPending, populate , overwriteDeferred, removeOutOfScope
            else:
                logger.error('No list of subprojects to resync specified as parameter nor in configuration file!')
                sys.exit(1)
        elif len(resync_list):
            #resync_list.append(sandbox + '/project.pj')
            '''Subsandboxes to resync
            resync_list[:] = [get_absolute_path(item) for item in resync_list]
            '''
            '''Find subproject, subsandbox
            index = base_project.rindex('/')
            subproject = base_project[:index]+'/01_Supporting_Process' + base_project[index:]
            subsandbox = sandbox + '/M11_APPL/04_Engineering/00_Projects/MFC431/build.h'
            subsandbox = sandbox + '/M11_APPL/04_Engineering/00_Projects/project.pj'
            '''
            '''Cannot filter folders...
            #includeDropped, restoreTimestamp, overwriteUnchanged, filter=changed:newmem, filter=changed:missing
            #'!01_Supporting_Process', '!02_Requirements', '!03_Design', '!04_Engineering', '!05_Testing', '!06_Deliverables'
            #resp = ims.resync(*resync_list, batch=None, recurse=None, filter_1='file:!06_Deliverables', filter_2='file:!06_Deliverables/*', filter_3='file:!*/06_Deliverables', filter_4='file:!*/06_Deliverables/*')
            #resp = ims.resync(*resync_list, batch=None, recurse=None, filter='file:!06_Deliverables,file:!06_Deliverables/*,file:!*/06_Deliverables,file:!*/06_Deliverables/*')
            filters = ['!01_Supporting_Process', '!02_Requirements', '!03_Design', '!04_Engineering', '!05_Testing', '!06_Deliverables']
            filters_iuc = []
            filters_dpu = []
            filter = ','.join('file:'+f for f in filters) #caseinsensitivefile
            #resp = ims.resync(*resync_list, batch=None, recurse=None, filter=filter)
            '''
            logger.info('Resync sandbox:\n\t%s', '\n\t'.join(resync_list))
            #TODO: Run one command per subprobject to reduce chances to timout or better DISABLE or INCREASE timeout
            resp = ims.resync(*resync_list, batch=None, recurse=None, overwriteChanged=None, includeDropped=None, nomerge=None) # overwriteIfPending, populate , overwriteDeferred, removeOutOfScope
        else:
            logger.error('Empty list of subprojects to resync specified!')
            sys.exit(1)

        if del_non_members:
            delete_nonmembers()
    except (APIException, Exception) as e:
        message = get_exception_message(e)
        logger.exception('Exception occurred: %s', message)
        #logger.info('Restoring the previous revision of the subprojects from "%s" file because of unsuccessfully resync of the sandbox.', file_old_config_rev)
        #restore_configure_subprojects(file_old_config_rev) #, removeFile=False
        sys.exit(1)

    logger.debug('TO BE DONE...')

# Read the SW Version Number from the header file (was or will be updated by update_cfg_buildinfo, update_sw_ver_no)!
def read_revision_IuC(file_path, base=16):
    file_path = get_absolute_path(file_path)

    #str1 = '#define MK_EXE_VERSION 0x03020f'
    str1 = '#define MK_EXE_VERSION 0(?:x|X)([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})'

    content = ''
    with open(file_path, 'r') as f:
        content = f.read()

    if not content:
        logger.error('File "%s" is empty!', file_path)
        return ''

    m1 = re.search(str1, content)
    if not m1:
        logger.error('Unknown format for "%s"!', file_path)
        return ''

    g1 = int(content[m1.regs[1][0]:m1.regs[1][1]], base)
    g2 = int(content[m1.regs[2][0]:m1.regs[2][1]], base)
    g3 = int(content[m1.regs[3][0]:m1.regs[3][1]], base)

    return '%02d.%02d.%02d' % (g1, g2, g3)

def update_CW_IuC(cp_label_iuc):
    str6 = '_CW([0-9][0-9])_R?([0-9][0-9])\.([0-9][0-9])\.([0-9]+)'
    m6 = re.search(str6, cp_label_iuc)
    if m6:
        cw = cp_label_iuc[m6.regs[1][0]:m6.regs[1][1]]
        t = time.localtime()
        cw_new = '%02d' % (t.tm_yday//7+1)
        cp_label_iuc = cp_label_iuc.replace('CW'+cw, 'CW'+cw_new)
    return cp_label_iuc

def update_pj_cp_label(project_cp_label):
    str6 = '_CW([0-9][0-9])_R?([0-9][0-9]\.[0-9][0-9]\.[0-9]+)'
    m6 = re.search(str6, project_cp_label)
    if m6:
        cw = project_cp_label[m6.regs[1][0]:m6.regs[1][1]]
        t = time.localtime()
        cw_new = '%02d' % (t.tm_yday//7+1)
        project_cp_label = project_cp_label.replace('CW'+cw, 'CW'+cw_new)

        ver = project_cp_label[m6.regs[2][0]:m6.regs[2][1]]
        ver_new = read_revision_IuC(sw_ver_iuc)
        project_cp_label = project_cp_label.replace(ver, ver_new)

    return project_cp_label

# Read the SW Version Number from the header file (was or will be updated by update_cfg_buildinfo, update_sw_ver_no)!
def read_revision_DPU(file_path):
    file_path = get_absolute_path(file_path)

    #str1 = 'SW Version Number 006.117.40'
    str1 = 'SW Version Number ([0-9][0-9][0-9])\.([0-9][0-9][0-9])\.([0-9][0-9])'

    content = ''
    with open(file_path, 'r') as f:
        content = f.read()

    if not content:
        logger.error('File "%s" is empty!', file_path)
        return ''

    m1 = re.search(str1, content)
    if not m1:
        logger.error('Unknown format for "%s"!', file_path)
        return ''

    g1 = int(content[m1.regs[1][0]:m1.regs[1][1]])
    g2 = int(content[m1.regs[2][0]:m1.regs[2][1]])
    g3 = int(content[m1.regs[3][0]:m1.regs[3][1]])

    return '%03d.%03d.%02d' % (g1, g2, g3)

#exit in case of empty file
#return true or false depending on successfully type detection
def update_cfg_buildinfo(file_path):
    file_path = get_absolute_path(file_path)
    os.chmod(file_path, stat.S_IWRITE)

    #str1 = 'SW Version Number 006.117.40'
    #str2 = '#define MK_EXE_VERSION ((( 6 ) << 16u) + (( 117 ) << 8u) + ( 40 ))'
    str1 = 'SW Version Number ([0-9][0-9][0-9])\.[0-9][0-9][0-9]\.[0-9][0-9]'
    #TODO: Handle in the script the 'ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/00_Projects/MFC431HI28/cfg_buildinfo.h' error of single digit for last group?
    str2 = '#define MK_EXE_VERSION \(\(\(\ *[0-9] *\) *<< *16u\) *\+ *\(\( *[0-9]?[0-9][0-9] *\) *<< *8u\) *\+ *\( *[0-9]?[0-9] *\)\)'

    content = ''
    with open(file_path, 'r') as f:
        content = f.read()

    if not content:
        logger.error('File "%s" is empty!', file_path)
        sys.exit(1)

    m1 = re.search(str1, content)
    m2 = re.search(str2, content)
    if not m1 or not m2:
        return False

    t = time.localtime()
    #g1 = int(content[m1.regs[1][0]:m1.regs[1][1]]) # get the 'PPB' part of the revision from the file as the rule is not followed, eg.: 000, 006
    # it was requested that for nightlybuilds will have 000.YWW.DC and for releases 006.YWW.DC - ad it as option in configuration file?
    if configure_mode == 'latest':
        g1 = 0
    elif configure_mode == 'releaseID':
        g1 = 6

    g2 = (t.tm_year - 2017)*100 + (t.tm_yday//7+1)
    g3 = ((t.tm_wday + 1) % 7)*10 + 0 # assume is the first checkpoint of the day

    old_rev = read_revision_DPU(file_path)
    new_rev = '%03d.%03d.%02d' % (g1, g2, g3)

    # if software revision is the same (up to, except last digit), increment checkpoint per day
    if old_rev[:-1] == new_rev[:-1]:
        g3 = int(old_rev[-2:])+1 # assume no more then 10 checkpoints are done in one day

    '''
    #TODO: Find the real checkpoint number per day - only for the same branch?
    try:
        idx = base_project.rfind('/')
        dpu_project = base_project[:idx] + '/DPU' + base_project[idx:]
        #TODO: Include devpath in the dpu_project path!
        resp = ims.projectinfo(batch=None, project=dpu_project, devpath=devpath)
        rev = resp.work_items[0].getField('revision').item.id
        no_rev = int(rev[rev.rfind('.')+1:]) - 1
        if no_rev == 0:
            g3 = (t.tm_wday + 1)*10 + 0
        else:
            #TODO: Include devpath in the dpu_project path!
            resp = ims.viewprojecthistory(batch=None, project=dpu_project, devpath=devpath)
            item_list = resp.work_items[0].getField('revisions').item_list
            for item in item_list:
                if item.id == rev:
                    for label in item.getField('labels').item_list:
                        label
                        break
                    break
    except APIException as e:
        logger.exception('Exception occurred: %s', e.message)
        sys.exit(4)
    except Exception as e:
        logger.exception('Exception occurred:')
        sys.exit(4)
    '''

    # Update in reverse order as the text pieces can have different lengths and the indexes won't match
    l2 = '#define MK_EXE_VERSION ((( %d ) << 16u) + (( %d ) << 8u) + ( %d ))' % (g1, g2, g3)
    content = content[:m2.start()] + l2 + content[m2.end():]

    l1 = 'SW Version Number %03d.%03d.%02d' % (g1, g2, g3)
    content = content[:m1.start()] + l1 + content[m1.end():]

    with open(file_path, 'w') as f:
        f.write(content)

    return True

def update_build(file_path):
    file_path = get_absolute_path(file_path)
    os.chmod(file_path, stat.S_IWRITE)

    #str1 = '#define MK_BDATE 180620'
    #str2 = '#define MK_EXE_VERSION 0x080203'
    #str3 = '#define MK_BTIME 140000'
    #str4 = '#define MK_BUILD_TYPE RELEASE' #DO_NOT_USE, PRERELEASE, TESTVERSION, NIGHTLYBUILDS, RELEASE
    str1 = '#define MK_BDATE ([0-9]+)[0-9][0-9][0-9][0-9]'
    #str2 = '#define MK_EXE_VERSION 0(x|X)[0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F]'
    str2 = '#define MK_EXE_VERSION 0(x|X)[0-9a-fA-F]{6}'
    str3 = '#define MK_BTIME ([0-9]+)[0-9][0-9][0-9][0-9]'
    str4 = '#define MK_BUILD_TYPE [A-Z_]+'

    content = ''
    with open(file_path, 'r') as f:
        content = f.read()

    if not content:
        logger.error('File "%s" is empty!', file_path)
        sys.exit(1)

    m1 = re.search(str1, content)
    m2 = re.search(str2, content)
    m3 = re.search(str3, content)
    m4 = re.search(str4, content)
    if not m1 or not m2 or not m3 or not m4:
        return False

    t = time.localtime()

    # Find the real major, minor and patch level from label: project_cp_label = {project}_Overall_08.02-INT222
    #TODO: Use cp_label_iuc instead?
    str5 = '_Overall_([0-9][0-9])\.([0-9][0-9])-(INT|TST)([0-9]+)'
    str6 = '_CW[0-9][0-9]_R?([0-9][0-9])\.([0-9][0-9])\.([0-9]+)'
    m5 = re.search(str5, project_cp_label)
    m6 = re.search(str6, project_cp_label)
    if not m5 and not m6:
        logger.error('Unknown format for label "%s", use default major, minor, patch level and integration type: 0, 0, 1, TESTVERSION ("%s")!', project_cp_label, file_path)
        major, minor, patch = (0, 0, 1)
        build_type = 'TST'
    elif m5:
        major = int(project_cp_label[m5.regs[1][0]:m5.regs[1][1]])
        minor = int(project_cp_label[m5.regs[2][0]:m5.regs[2][1]])
        patch = int(project_cp_label[m5.regs[4][0]:m5.regs[4][1]])
        build_type = project_cp_label[m5.regs[3][0]:m5.regs[3][1]]
    elif m6:
        #TODO: Get the major, minor revision from the label and the patch level by incrementing the previous one
        major = int(project_cp_label[m6.regs[1][0]:m6.regs[1][1]])
        minor = int(project_cp_label[m6.regs[2][0]:m6.regs[2][1]])
        str7 = '#define MK_EXE_VERSION 0(?:x|X)([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})' #([0-9a-fA-F]{6})
        m7 = re.search(str7, content)
        major_old = int(content[m7.regs[1][0]:m7.regs[1][1]], 16)
        minor_old = int(content[m7.regs[2][0]:m7.regs[2][1]], 16)
        #Restart patch to 1 if major and minor from build.h are different from the ones in label!
        if major != major_old or minor != minor_old:
            patch = 1
        else:
            patch = int(content[m7.regs[3][0]:m7.regs[3][1]], 16) + 1
        build_type = 'RELEASE'

    # Update in reverse order as the text pieces can have different lengths and the indexes won't match
    if run_mode == 'nightlybuilds':
        l4 = '#define MK_BUILD_TYPE %s' % ('NIGHTLYBUILDS')
    elif run_mode == 'integrator':
        if build_type == 'TST':
            l4 = '#define MK_BUILD_TYPE %s' % ('TESTVERSION')
        elif build_type in ['INT', 'RELEASE']:
            l4 = '#define MK_BUILD_TYPE %s' % ('RELEASE')
        else:
            l4 = '#define MK_BUILD_TYPE %s' % ('UNKNOWN')
    content = content[:m4.start()] + l4 + content[m4.end():]

    # handle midnight (leading 0 means octal!)
    if t.tm_hour == 0:
        tm_hour = 1
    else:
        tm_hour = t.tm_hour
    l3 = '#define MK_BTIME %d%02d%02d' % (tm_hour, t.tm_min, t.tm_sec)
    content = content[:m3.start()] + l3 + content[m3.end():]
    
    if run_mode == 'nightlybuilds':
        g1 = 0
        g2 = t.tm_yday//7+1
        g3 = (t.tm_wday + 1) % 7
        l2 = '#define MK_EXE_VERSION 0x%02d%02d%02d' % (g1, g2, g3)
    else:
        l2 = '#define MK_EXE_VERSION 0x%02x%02x%02x' % (major, minor, patch)
    content = content[:m2.start()] + l2 + content[m2.end():]

    l1 = '#define MK_BDATE %d%02d%02d' % (t.tm_year % 100, t.tm_mon, t.tm_mday)
    content = content[:m1.start()] + l1 + content[m1.end():]

    with open(file_path, 'w') as f:
        f.write(content)

    return True

update_functions_list = [update_cfg_buildinfo, update_build] #update_co_latest_cp

def get_next_rev(project):
    project_path = get_proj_subproj(project)[0]
    resp = ims.projectinfo(batch=None, project=project_path)
    crt_rev = resp.work_items[0].getField('revision').item.id
    idx = crt_rev.rfind('.') + 1
    next_rev = crt_rev[:idx] + str(int(crt_rev[idx:])+1)
    return next_rev

#TODO: Make it generic, not only for DPU...
def update_co_latest_cp(file_path, build_unit, deliverables):
    file_path = get_absolute_path(file_path)
    os.chmod(file_path, stat.S_IWRITE)

    #TODO: Make sure update_cfg_buildinfo() is called before this line!
    global cp_label_dpu
    cp_label_dpu = cp_label_dpu.replace('{version}', read_revision_DPU(sw_ver_dpu))

    #set PRJREV=1.101.1.2
    #set DPU_DELIVERY_PRJREV=1.50.2.2
    #set SANDBOX=SW_MFC431_DPU_TRUNK_006.121.10
    str1 = 'set PRJREV=([0-9]+)(\.[0-9]+)+'
    str2 = 'set DPU_DELIVERY_PRJREV=([0-9]+)(\.[0-9]+)+'
    str3 = 'set SANDBOX=([\w\.]+)'

    content = ''
    with open(file_path, 'r') as f:
        content = f.read()

    if not content:
        logger.error('File "%s" is empty!', file_path)
        sys.exit(1)

    m1 = re.search(str1, content)
    m2 = re.search(str2, content)
    m3 = re.search(str3, content)
    if not m1 or not m2 or not m3:
        return False

    dpu_projrev = get_next_rev(build_unit)
    dpu_delivery_projrev = get_next_rev(deliverables)

    # Update in reverse order as the text pieces can have different lengths and the indexes won't match
    l3 = 'set SANDBOX=%s' % (cp_label_dpu)
    content = content[:m3.start()] + l3 + content[m3.end():]

    l2 = 'set DPU_DELIVERY_PRJREV=%s' % (dpu_delivery_projrev)
    content = content[:m2.start()] + l2 + content[m2.end():]

    l1 = 'set PRJREV=%s' % (dpu_projrev)
    content = content[:m1.start()] + l1 + content[m1.end():]

    with open(file_path, 'w') as f:
        f.write(content)

    return True

#return the headers for entire family using the sandbox, not the IMS
def get_headers_family(header_file):
    build_abs = get_absolute_path(header_file)
    idx1 = build_abs.rfind('/')
    idx2 = build_abs[:idx1].rfind('/')
    filename = build_abs[idx1+1:]
    OO_Projects = build_abs[:idx2]
    dir_list = os.listdir(OO_Projects)
    files_list = []
    for dir in dir_list:
        file_path = os.path.join(OO_Projects, dir, filename).replace('\\', '/')
        if os.path.isfile(file_path):
            files_list.append(file_path)

    return files_list

def sw_ver_yyyy_cw_id(file_path):
    file_path = get_absolute_path(file_path)
    os.chmod(file_path, stat.S_IWRITE)

    str1 = '#define MK_BDATE ([0-9]+)[0-9][0-9][0-9][0-9]'
    str2 = '#define MK_EXE_VERSION 0(x|X)[0-9a-fA-F]{6}'
    str3 = '#define MK_BTIME ([0-9]+)[0-9][0-9][0-9][0-9]'
    str4 = '#define MK_BUILD_TYPE [A-Z_]+'

    content = ''
    with open(file_path, 'r') as f:
        content = f.read()

    if not content:
        logger.error('File "%s" is empty!', file_path)
        sys.exit(1)

    old_rev = read_revision_IuC(file_path, 10)
    if not old_rev:
        logger("Revision could NOT be parsed by 'read_revision_IuC' function!")
        return False

    m1 = re.search(str1, content)
    m2 = re.search(str2, content)
    m3 = re.search(str3, content)
    m4 = re.search(str4, content)
    if not m1 or not m2 or not m3 or not m4:
        return False

    t = time.localtime()

    # Update in reverse order as the text pieces can have different lengths and the indexes won't match
    if run_mode == 'nightlybuilds':
        l4 = '#define MK_BUILD_TYPE %s' % ('NIGHTLYBUILDS')
    elif run_mode == 'integrator':
        if build_type == 'TST':
            l4 = '#define MK_BUILD_TYPE %s' % ('TESTVERSION')
        elif build_type in ['INT', 'RELEASE']:
            l4 = '#define MK_BUILD_TYPE %s' % ('RELEASE')
        else:
            l4 = '#define MK_BUILD_TYPE %s' % ('UNKNOWN')
    content = content[:m4.start()] + l4 + content[m4.end():]

    # handle midnight (leading 0 means octal!)
    if t.tm_hour == 0:
        tm_hour = 1
    else:
        tm_hour = t.tm_hour
    l3 = '#define MK_BTIME %d%02d%02d' % (tm_hour, t.tm_min, t.tm_sec)
    content = content[:m3.start()] + l3 + content[m3.end():]
    
    # if run_mode == 'nightlybuilds':
    # yy.cw.id
    old_yy = int(old_rev[0:2])  # it will be 0 if old format was used: 00.cw.day, will be again 0 in year 2100
    old_cw = int(old_rev[3:5])
    old_id = int(old_rev[6:8])

    new_cw = t.tm_yday//7+1
    yy = t.tm_year % 100
    cw = new_cw
    if old_yy != 0 and old_cw == new_cw:
        id = old_id + 1
    else:
        id = 0
    l2 = '#define MK_EXE_VERSION 0x%02d%02d%02d' % (yy, cw, id)
    content = content[:m2.start()] + l2 + content[m2.end():]

    l1 = '#define MK_BDATE %d%02d%02d' % (t.tm_year % 100, t.tm_mon, t.tm_mday)
    content = content[:m1.start()] + l1 + content[m1.end():]

    with open(file_path, 'w') as f:
        f.write(content)

    return True

def update_headers(files_list, sw_ver_type):
    updated_files_list = []
    not_updated_files_list = []
    for file_path in files_list:
        if sw_ver_type:
            sw_ver_type = "sw_ver_%s" % sw_ver_type
            try:
                if globals()[sw_ver_type](file_path):
                    logger.info('Successfully update software revision for "%s" (%s)', file_path, sw_ver_type)
                    updated_files_list.append(file_path)
                else:
                    logger.error('Unknown format for "%s" (%s)!', file_path, sw_ver_type)
                    not_updated_files_list.append(file_path)

            except:
                logger.error('No function named "%s" found to update software version!', sw_ver_type)
        else:
            for update_fct in update_functions_list:
                if update_fct(file_path):
                    logger.info('Successfully update software revision for "%s"', file_path)
                    updated_files_list.append(file_path)
                    break
            else:
                logger.error('Unknown format for "%s"!', file_path)
                not_updated_files_list.append(file_path)

    if len(files_list) != len(updated_files_list):
        if len(files_list) > 1:
            logger.error('Not all software revision files updated')
        else:
            logger.error('Software revision file NOT updated!')

    return updated_files_list, not_updated_files_list

def update_sw_rev(header_file, family, sw_ver_type=None):
    if not header_file:
        logger.info('No file provided to be updated (update_sw_rev)!')
        #sys.exit(3)
        return None, None
    file_path = get_absolute_path(header_file)
    if os.path.isfile(file_path):
        #TODO: Handle family parameter by using the local file system not the IMS server.
        if family:
            files_list = get_headers_family(file_path)
            logger.debug('Update software revision (family):\n\t%s', '\n\t'.join(files_list))
        else:
            logger.debug('Update software revision: "%s"', file_path)
            files_list = [file_path]
        return update_headers(files_list, sw_ver_type)
    else:
        logger.error('File does not exists "%s"!', file_path)
        #sys.exit(3)
        return None, None

def update_checkout_latest(co_latest_cp, build_unit, deliverables):
    if not co_latest_cp:
        logger.info('No file provided to be updated (update_checkout_latest)!')
        #sys.exit(3)
        return
    if not deliverables:
        logger.error('No subproject provided (option "deliverables" in INI file)!')
        #sys.exit(3)
        return
    file_path = get_absolute_path(co_latest_cp)
    if os.path.isfile(file_path):
        logger.debug('Update software revision: "%s"', file_path)
        if not update_co_latest_cp(file_path, build_unit, deliverables):
            logger.error('Unknown format for "%s"!', file_path)
            #sys.exit(1)
            return file_path
    else:
        logger.error('File does not exists "%s"!', file_path)
        #sys.exit(3)
        return

def update_sw_ver_no(family=False, iuc=False, dpu=False, sil=False): #Step 3
    logger.debug('Step 3 - Pre build actions: Update software version number')
    logger.debug('*'*50)

    #TODO: Update all Version Header Files from Project Family based on family parameter.
    #TODO: Automagically detect the type of file and exit only if none of them is found!

    logger.debug('Configure mode: "%s"', configure_mode)
    logger.debug('Build mode: "%s"', build_mode)

    cfg_mode = ['latest', 'releaseID']
    if configure_mode not in cfg_mode:
        #TODO: Raise exception!
        logger.error('"configure_mode" must be one of: %s ("%s")', cfg_mode, configure_mode)
        sys.exit(1)

    accepted_build_mode = ['IuC', 'DPU', 'BOTH']
    if build_mode not in accepted_build_mode:
        #TODO: Raise exception!
        logger.error('Wrong build_mode provided in INI file: "%s" (must be one of %s)', build_mode, accepted_build_mode)
        sys.exit(2)

    #TODO: Does the order really matters? Can be done simultaneosly?
    if build_mode in ['IuC', 'BOTH'] and iuc:
        logger.debug('Update software revision file(s) for IuC')
        update_sw_rev(sw_ver_iuc, family, sw_ver_type_iuc)

        # Update checkout_latest_mfc431_checkpoint.bat
        update_checkout_latest(co_latest_cp_iuc, build_unit_iuc, deliverables_iuc)

    if build_mode in ['DPU', 'BOTH'] and dpu:
        logger.debug('Update software revision file(s) for DPU')
        update_sw_rev(sw_ver_dpu, family)

        # No need to update gen_buildinfo.h
        #logger.debug('Update software revision files(s) for DPU')
        #update_sw_rev(sw_ver_2_dpu, family)

        # Update checkout_latest_mfc431_checkpoint.bat
        update_checkout_latest(co_latest_cp_dpu, build_unit_dpu, deliverables_dpu)

    if build_mode in ['DPU', 'BOTH'] and sil:
        #logger.warning('No update for software revision SIL!')

        logger.debug('Update software revision file(s) for SIL')
        update_sw_rev(sw_ver_sil, family)

        # Update checkout_latest_mfc431_checkpoint.bat
        update_checkout_latest(co_latest_cp_sil, build_unit_sil, deliverables_sil)

    logger.debug('TO BE DONE...')

def lock_files(): #Step 4
    logger.debug('Step 4 - Pre build actions: Lock files')
    logger.debug('*'*50)

    logger.debug('Build mode: "%s"', build_mode)
    accepted_build_mode = ['IuC', 'DPU', 'BOTH']
    if build_mode not in accepted_build_mode:
        #TODO: Raise exception!
        logger.error('Wrong build_mode provided in INI file: "%s" (must be one of %s)', build_mode, accepted_build_mode)
        sys.exit(2)
    if build_mode in ['IuC', 'BOTH']:
        logger.debug('Lock files IuC:\n\t%s', '\n\t'.join(ci_files_iuc))
        #logger.debug('Lock files IuC (release):\n\t%s', '\n\t'.join(ci_iuc_release_files))
        #logger.debug('Lock files IuC (debug):\n\t%s', '\n\t'.join(ci_iuc_debug_files))
        pass
    if build_mode in ['DPU', 'BOTH']:
        logger.debug('Lock files DPU:\n\t%s', '\n\t'.join(ci_files_dpu))
        logger.debug('Lock files SIL:\n\t%s', '\n\t'.join(ci_files_sil))
        pass

    logger.warning('Locking files is done immediately before checkin them...')

    logger.debug('TO BE DONE...')

def dir_chmod(path, mode):
    for root, dirs, files in os.walk(path):
        for fname in files:
            full_path = os.path.join(root, fname)
            os.chmod(full_path, mode)

#split command line into actual command and current working directory
def get_cmd_cwd(command_line):
    cwd = os.path.dirname(shlex.split(command_line)[0])
    cmd = command_line[len(cwd)+1:]
    return cmd, cwd

def run_build_script(build_script, cpy_out_script, buildunit):
    if not build_script:
        logger.info('No script provided for building "%s" (build_mode: "%s")!', buildunit, build_mode)
        #sys.exit(5)
        return
    if not run_cmd(build_script, timeout_cmd):
        logger.error('Building "%s" failed!', buildunit)
        sys.exit(3)
    if cpy_out_script:
        logger.info('Copy folder content from "%s" to "%s"', cpy_out_script[0], cpy_out_script[1])
        # Remove readonly flag from directory...
        #dir_chmod(cpy_out_script[0], stat.S_IWRITE)
        dir_chmod(cpy_out_script[1], stat.S_IWRITE)
        copy_tree(cpy_out_script[0], cpy_out_script[1])
    #elif build_script is None:
    #    logger.error('No script provided for building "%s" (build_mode: "%s")!', buildunit, build_mode)
    #else: # build_script is empty, so intentional missing
    #    logger.warning('No script provided for building "%s" (build_mode: "%s")!', buildunit, build_mode)
    pass

def build_project(iuc=False, dpu=False, sil=False): #Step 5
    # For nightlybuilds this subcommand must be called with all build units "--iuc --dpu --sil"!
    if not iuc and not dpu and not sil:
        logger.error('No build unit provided (build_mode: "%s", configure_mode: "%s")!', build_mode, configure_mode)
        sys.exit(6)

    logger.debug('Step 5 - Build project: Run building process per se')
    logger.debug('*'*50)
    try:
        accepted_build_mode = ['IuC', 'DPU', 'BOTH']
        if build_mode not in accepted_build_mode:
            #TODO: Raise exception!
            logger.error('Wrong build_mode provided in INI file: "%s" (must be one of %s)', build_mode, accepted_build_mode)
            sys.exit(2)

        logger.debug('Build mode: "%s"', build_mode)

        #TODO: Does the order really matters? Can be done simultaneously?
        if build_mode in ['IuC', 'BOTH']:
            if iuc:
                logger.info('Start building IuC...')
                if not build_script_1_iuc and not build_script_2_iuc and not build_script_3_iuc and not build_script_4_iuc:
                    logger.error('No script provided for building IuC (build_mode: "%s")!', build_mode)
                    sys.exit(2)

                run_build_script(build_script_1_iuc, cpy_out_script_1_iuc, 'IuC')
                run_build_script(build_script_2_iuc, cpy_out_script_2_iuc, 'IuC')
                run_build_script(build_script_3_iuc, cpy_out_script_3_iuc, 'IuC')
                run_build_script(build_script_4_iuc, cpy_out_script_4_iuc, 'IuC')
            else:
                logger.warning('NOT building IuC: build_mode provided in INI file: ("%s"), but the "--iuc" parameter not provided to "build_project" subcommand', build_mode)

        #TODO: Should we continue if IuC building failed?
        if build_mode in ['DPU', 'BOTH']:
            if dpu:
                logger.info('Start building DPU...')
                if not build_script_1_dpu and not build_script_2_dpu and not build_script_3_dpu and not build_script_4_dpu:
                    logger.error('No script provided for building DPU (build_mode: "%s")!', build_mode)
                    sys.exit(2)

                run_build_script(build_script_1_dpu, cpy_out_script_1_dpu, 'DPU')
                run_build_script(build_script_2_dpu, cpy_out_script_2_dpu, 'DPU')
                run_build_script(build_script_3_dpu, cpy_out_script_3_dpu, 'DPU')
                run_build_script(build_script_4_dpu, cpy_out_script_4_dpu, 'DPU')
            else:
                logger.warning('NOT building DPU: build_mode provided in INI file ("%s"), but the "--dpu" parameter not provided to "build_project" subcommand', build_mode)

            if sil:
                logger.info('Start building SIL...')
                if not build_script_1_sil and not build_script_2_sil and not build_script_3_sil and not build_script_4_sil:
                    logger.error('No script provided for building SIL (build_mode: "%s")!', build_mode)
                    sys.exit(2)

                run_build_script(build_script_1_sil, cpy_out_script_1_sil, 'SIL')
                run_build_script(build_script_2_sil, cpy_out_script_2_sil, 'SIL')
                run_build_script(build_script_3_sil, cpy_out_script_3_sil, 'SIL')
                run_build_script(build_script_4_sil, cpy_out_script_4_sil, 'SIL')
            else:
                logger.warning('NOT building SIL: build_mode provided in INI file: ("%s"), but the "--sil" parameter not provided to "build_project" subcommand', build_mode)
    except SystemExit as e:
        #print "Exit with error number: " + str(e.code)
        logger.exception('Exception occurred:')
        #return False
        # Do not restore, we should continue
        #logger.info('Restoring the previous revision of the subprojects from "%s" file because of unsuccessfully configuring/checkpointing of a subproject.', file_old_config_rev)
        #restore_configure_subprojects(file_old_config_rev) #, removeFile=False
        sys.exit(e.code)

    logger.debug('TO BE DONE...')
    #return True

def flash_ECU(): #Step 6
    logger.debug('Step 6 - Post build actions: Flash ECU')
    logger.debug('*'*50)

    logger.debug('Please manually flash the ECU...')

    logger.debug('TO BE DONE...')

def trigger_BAT_test(): #Step 7
    logger.debug('Step 6 - Post build actions: Run BAT test')
    logger.debug('*'*50)

    logger.debug('Please manually run the BAT test(s)...')

    logger.debug('TO BE DONE...')

def checkin_file(file_path, subsandbox, ci_branch, label, description):
    ###TODO: Remove lock when checkin failed and also update ci command to force a checkin when "Store By Reference" is required.
    #http://10.68.48.194:8080/view/Admin_CheckPoints/job/Magnus_MFC431_DevGate/187/consoleFull  <--  Fail to checkin file
    # Checkin file differently based on ci_branch
    if ci_branch:
        resp = ims.lock(file_path, sandbox=subsandbox, batch=None, cpid=cpid, lockType="exclusive") #, revision=":memberbranchtip"
        resp = ims.ci(file_path, sandbox=subsandbox, batch=None, label=label, update=None, cpid=cpid, nocloseCP=None, checkinUnchanged=None, description=description) #, nobranchVariant=None
    else:
        #resp = ims.co(file_path, sandbox=subsandbox, batch=None, nolock=None, revision=":head") #--nooverwriteChanged, noupdate=None
        resp = ims.lock(file_path, sandbox=subsandbox, batch=None, revision=":head", cpid=cpid, lockType="exclusive")
        #--[no|confirm]skipUpdateOnLockConflict, label='', revision=":head"+1, nobranch=None, ?nobranchUpdate=None?
        resp = ims.ci(file_path, sandbox=subsandbox, batch=None, label=label, noupdate=None, nobranchVariant=None, cpid=cpid, nocloseCP=None, checkinUnchanged=None, description=description)

#convert, for a file, IMS absolute and relative (flatpath) to sandbox absolute path
def convert_ims_to_local_absolute_path(relative_path):
    absolute_path = get_absolute_path(relative_path)
    idx = absolute_path.rindex('/') + 1
    subsandbox = absolute_path[:idx] + 'project.pj'
    filename = absolute_path[idx:]
    return absolute_path, subsandbox, filename

def checkin_files_list(files_list, ci_branch, label, description):
    checkin_files = []
    not_checkin_files = []
    #TODO: Is there any need to be optimized by sending just one/a few ci command (group files by location) and one for each file?
    #files = []
    for f in files_list:
        absolute_path, subsandbox, filename = convert_ims_to_local_absolute_path(f)
        #files.append(absolute_path) #*files
        #TODO: First check if local file exists before trying to checkin (ItemNotFoundException + si.MemberNotFound)!
        if not os.path.isfile(absolute_path):
            logger.error('File cannot be checked-in: it does not exists "%s"!', absolute_path)
            not_checkin_files.append(absolute_path)
            continue
        try:
            checkin_file(absolute_path, subsandbox, ci_branch, label, description)
        except (APIException, Exception) as e:
            #TOOD: Check if file is not already locked by somebody else: ItemModificationException + si.OtherUserLocked
            message = get_exception_message(e)
            logger.exception('Exception occurred: %s', message)
            # Do not restore here the previous revision of the subprojects
            '''
            logger.info('Restoring the previous revision of the subprojects from "%s" file because of unsuccessfully configuring/checkpointing of a subproject.', file_old_config_rev)
            restore_configure_subprojects(file_old_config_rev) #, removeFile=False
            '''
            #sys.exit(1)
        else:
            logger.info('Successfully checkin file "%s"', absolute_path)
            checkin_files.append(absolute_path)
        finally:
            if absolute_path not in checkin_files:
                logger.error('Fail to checkin file "%s"', absolute_path)
                not_checkin_files.append(absolute_path)

    return checkin_files, not_checkin_files

def checkin_sw_ver(file_path, family, ci_branch, label, description):
    file_path = get_absolute_path(file_path)
    if not os.path.isfile(file_path):
        logger.error('Software revision file NOT found: "%s"!', file_path)
        sys.exit(3)
    #TODO: Handle family parameter by using the local file system not the IMS server.
    if family:
        files_list = get_headers_family(file_path)
        logger.debug('Checkin software revision (family):\n\t%s', '\n\t'.join(files_list))
    else:
        files_list = [file_path]
        logger.debug('Checkin software revision: "%s"', file_path)

    checkin_files_list(files_list, ci_branch, label, description)

def check_in_files(family=False, iuc=False, dpu=False, sil=False): #Step 8
    logger.debug('Step 7 - Post build actions: Check-in files')
    logger.debug('*'*50)

    #logger.debug('Create change package')
    new_cpid = create_cp(ro, 'Step: check_in_files (%s)' % summary_helper_cp(iuc=iuc, dpu=dpu, sil=sil, family=family))
    logger.debug('Create change package: %s', new_cpid)

    try:
        global cp_label_iuc, cp_label_dpu, cp_label_sil

        accepted_build_mode = ['IuC', 'DPU', 'BOTH']
        if build_mode not in accepted_build_mode:
            #TODO: Raise exception!
            logger.error('Wrong build_mode provided in INI file: %s (must be one of %s)', build_mode, accepted_build_mode)
            sys.exit(2)

        logger.debug('Build mode: "%s"', build_mode)

        if build_mode in ['IuC', 'BOTH'] and iuc:
            base = 10 if sw_ver_type_iuc else 16
            logger.debug('Checkin files for IuC')
            cp_label_iuc = cp_label_iuc.replace('{version}', read_revision_IuC(sw_ver_iuc, base))

            if sw_ver_iuc:
                checkin_sw_ver(sw_ver_iuc, family, ci_branch_iuc, cp_label_iuc, cp_label_iuc) #ci_description
            else:
                logger.info('No software revision defined for IuC in INI file!')


            if ci_files_iuc:
                logger.debug('Checkin files IuC:\n\t%s', '\n\t'.join(ci_files_iuc))
                checkin_files_list(ci_files_iuc, ci_branch_iuc, cp_label_iuc, cp_label_iuc) #ci_description
            else:
                logger.warning('List of checkin files for IuC in INI file is empty or missing!')

        if build_mode in ['DPU', 'BOTH'] and dpu:
            logger.debug('Checkin files for DPU')
            #TODO: Make sure update_cfg_buildinfo() is called before this line!
            cp_label_dpu = cp_label_dpu.replace('{version}', read_revision_DPU(sw_ver_dpu))

            if sw_ver_dpu:
                checkin_sw_ver(sw_ver_dpu, family, ci_branch_dpu, cp_label_dpu, cp_label_dpu) #ci_description
            else:
                logger.info('No software revision defined for DPU in INI file!')

            if ci_files_dpu:
                logger.debug('Checkin files DPU:\n\t%s', '\n\t'.join(ci_files_dpu))
                checkin_files_list(ci_files_dpu, ci_branch_dpu, cp_label_dpu, cp_label_dpu) #ci_description
            else:
                logger.warning('List of checkin files for DPU in INI file is empty or missing!')

        if build_mode in ['DPU', 'BOTH'] and sil:
            logger.debug('Checkin files for SIL')
            #TODO: Make sure update_cfg_buildinfo() is called before this line!
            if cp_label_sil.find('{version}') != -1:
                if build_unit_dpu:
                    cp_label_sil = cp_label_sil.replace('{version}', read_revision_DPU(sw_ver_dpu))
                else:
                    logger.error('Using "{version}" tag inside a checkpoint label is only possible if the project have a DPU!')
                    sys.exit(2)

            if sw_ver_sil:
                checkin_sw_ver(sw_ver_sil, family, ci_branch_sil, cp_label_sil, cp_label_sil) #ci_description
            else:
                logger.info('No software revision defined for SIL in INI file!')

            if ci_files_sil:
                logger.debug('Checkin files SIL:\n\t%s', '\n\t'.join(ci_files_sil))
                checkin_files_list(ci_files_sil, ci_branch_sil, cp_label_sil, cp_label_sil) #ci_description
            else:
                logger.warning('List of checkin files for SIL in INI file is empty or missing!')
    except SystemExit as e:
        logger.exception('Exception occurred:')
        #logger.info('Restoring the previous revision of the subprojects from "%s" file because of unsuccessfully checkin files.', file_old_config_rev)
        #restore_configure_subprojects(file_old_config_rev) #, removeFile=False
        sys.exit(e.code)

    logger.debug('Close change package: %s', cpid)
    close_cp(cpid)
    logger.debug('TO BE DONE...')

def get_overall_cp_description():
    if not description_overall:
        description = cp_description
    else:
        bu_list = []
        bu_names = description_overall[::2]
        overall_bu = description_overall[1::2]
        for i, item in enumerate(overall_bu):
            bu = bu_names[i]
            bu_cp = get_checkpoint_rev(item)
            bu_label = ''
        
            project_path = get_proj_subproj(item)[0]
            r = ims.viewprojecthistory(batch=None, fields='labels,revision', project=project_path)
            revision_field = r.work_items[0].getField('revisions').item_list
            for rev in revision_field:
                if rev.id == bu_cp:
                    #TODO: Here item_list is a list of strings! Use the first label!
                    label_list = rev.getField('labels').item_list
                    if label_list:
                        #TODO: Check if label contains both the project and the buld unit name
                        if len(label_list) > 1:
                            for lbl in label_list:
                                bu_ims = item[:item.rindex('/')]
                                if project in lbl and (bu_ims in lbl or bu_ims.upper() in ['APPL', 'M11_APPL']):
                                    bu_label = lbl
                                    break
                        else:
                            bu_label = label_list[0]
                    break
            if not bu_label: #empty label?
                bu_label = 'NO_LABEL_FOUND'
            #TODO: Overall checkpoint should have description like this: {buildunit}<4 TABS>{bu_label}<6 TABS>(Checkpoint Number: {bu_checkpoint})
            bu_text = '%s\t\t\t\t%s\t\t\t\t\t\t(Checkpoint Number: %s)' % (bu, bu_label, bu_cp)
            bu_list.append(bu_text)
        description = '\n'.join(bu_list)
    return description

def checkpoint_subprojects(label=None, broken=False, unstable=False, overall=False, iuc=False, dpu=False, sil=False): #Step 9
    logger.debug('Step 8 - Post build actions: Checkpoint subprojects')
    logger.debug('*'*50)

    logger.debug('Build mode: "%s"', build_mode)

    accepted_build_mode = ['IuC', 'DPU', 'BOTH']
    if build_mode not in accepted_build_mode:
        #TODO: Raise exception!
        logger.error('Wrong build_mode provided in INI file: "%s" (must be one of %s)', build_mode, accepted_build_mode)
        sys.exit(2)

    #logger.debug('Create change package')
    new_cpid = create_cp(ro, 'Step: checkpoint_subprojects (%s)' % summary_helper_cp(iuc=iuc, dpu=dpu, sil=sil, overall=overall))
    logger.debug('Create change package: %s', new_cpid)

    try:
        global cp_label_iuc, cp_label_dpu, cp_label_sil
        # Handle checkpoint of the subprojects (M11_APPL, DPU, MTS)
        #TODO: For nightlybuilds it is necessary CP for BuildUnits?!
        #if run_mode == 'integrator':
        if iuc:
            base = 10 if sw_ver_type_iuc else 16
            cp_label_iuc = cp_label_iuc.replace('{version}', read_revision_IuC(sw_ver_iuc, base))
            cp_label_iuc = update_CW_IuC(cp_label_iuc)

            logger.debug('Checkpoint IuC for %s (%s)', base_project, build_unit_iuc)
            for item in cp_subpj_iuc:
                #TODO: Automatically detect shared location and set to latest build instead checkpointing (already done in configure_subprojects, only set the label)...
                checkpoint_project(item, cp_label_iuc, cp_label_iuc) #cp_description

            #TODO: Add label for shared buildunits (Application Project).
            for item in shared_buildunit_iuc:
                project_path = get_proj_subproj(item)[0] #, proj, subproj
                resp = ims.projectinfo(batch=None, project=project_path)
                shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
                project_rev = resp.work_items[0].getField('revision').item.id
                logger.info('Subproject (buildunit) "%s" is shared from "%s" - it will be only labeled (revision: %s)', project_path, shared_from_flatpath, project_rev)
                resp = ims.addprojectlabel(batch=None, label=cp_label_iuc, project=shared_from_flatpath, projectRevision=project_rev) #, moveLabel=None, recurse=None, includeUnchangedSubprojects=None?

            if cfg_prev_cp_iuc:
                for item in cfg_prev_cp_iuc:
                    configure_project_build(item) #no need for subpj_devpath=devpath_buildunits_iuc[item] as the variant is automatically determined
        if dpu:
            #TODO: Make sure update_cfg_buildinfo() is called before this line!
            cp_label_dpu = cp_label_dpu.replace('{version}', read_revision_DPU(sw_ver_dpu))

            logger.debug('Checkpoint DPU for %s (%s)', base_project, build_unit_dpu)
            for item in cp_subpj_dpu:
                #TODO: Automatically detect shared location and set to latest build instead checkpointing (already done in configure_subprojects, only set the label)...
                checkpoint_project(item, cp_label_dpu, cp_label_dpu) #cp_description

            #TODO: Add label for shared buildunits (Application Project).
            for item in shared_buildunit_dpu:
                project_path = get_proj_subproj(item)[0] #, proj, subproj
                resp = ims.projectinfo(batch=None, project=project_path)
                shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
                project_rev = resp.work_items[0].getField('revision').item.id
                logger.info('Subproject (buildunit) "%s" is shared from "%s" - it will be only labeled (revision: %s)', project_path, shared_from_flatpath, project_rev)
                resp = ims.addprojectlabel(batch=None, label=cp_label_dpu, project=shared_from_flatpath, projectRevision=project_rev) #, moveLabel=None, recurse=None, includeUnchangedSubprojects=None?

            if cfg_prev_cp_dpu:
                for item in cfg_prev_cp_dpu:
                    configure_project_build(item) #no need for subpj_devpath=devpath_buildunits_dpu[item] as the variant is automatically determined
        if sil:
            #TODO: Make sure update_cfg_buildinfo() is called before this line!
            if cp_label_sil.find('{version}') != -1:
                if build_unit_dpu:
                    cp_label_sil = cp_label_sil.replace('{version}', read_revision_DPU(sw_ver_dpu))
                else:
                    logger.error('Using "{version}" tag inside a checkpoint label is only possible if the project have a DPU!')
                    sys.exit(2)

            logger.debug('Checkpoint SIL for %s (%s)', base_project, build_unit_sil)
            for item in cp_subpj_sil:
                #TODO: Automatically detect shared location and set to latest build instead checkpointing (already done in configure_subprojects, only set the label)...
                checkpoint_project(item, cp_label_sil, cp_label_sil) #cp_description

            #TODO: Add label for shared buildunits (Application Project). This label will be used for cfg_prev_cp_sil.
            for item in shared_buildunit_sil:
                project_path = get_proj_subproj(item)[0] #, proj, subproj
                resp = ims.projectinfo(batch=None, project=project_path)
                shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
                project_rev = resp.work_items[0].getField('revision').item.id
                logger.info('Subproject (buildunit) "%s" is shared from "%s" - it will be only labeled (revision: %s)', project_path, shared_from_flatpath, project_rev)
                resp = ims.addprojectlabel(batch=None, label=cp_label_sil, project=shared_from_flatpath, projectRevision=project_rev) #, moveLabel=None, recurse=None, includeUnchangedSubprojects=None?

            #configure the cfg and dll folders from Deliverables to the previous checkpointed version from MTS Build Unit
            #TODO: Automatically detect shared location and set to latest build - handle by the 'configure_project_build' (like in case of a2l)
            if cfg_prev_cp_sil:
                for item in cfg_prev_cp_sil:
                    configure_project_build(item) #no need for subpj_devpath=devpath_buildunits_sil[item] as the variant is automatically determined
        if overall:
            global project_cp_label, project_cp_broken_label, project_cp_unstable_label
            base = 10 if sw_ver_type_iuc else 16
            project_cp_label = project_cp_label.replace('{version}', read_revision_IuC(sw_ver_iuc, base))
            project_cp_label = update_pj_cp_label(project_cp_label)
            project_cp_broken_label = project_cp_broken_label.replace('{version}', read_revision_IuC(sw_ver_iuc, base))
            project_cp_broken_label = update_pj_cp_label(project_cp_broken_label)
            project_cp_unstable_label = project_cp_unstable_label.replace('{version}', read_revision_IuC(sw_ver_iuc, base))
            project_cp_unstable_label = update_pj_cp_label(project_cp_unstable_label)

            #TODO: For nightlybuilds if build or BAT fails still doing this (beside overall checkpointing)?
            logger.debug('Checkpoint OVERALL for %s (%s)', base_project, devpath)

            #update the member revision of the A2L File within MTS/ini Folder to the previous checked in version
            if update_member_rev_overall:
                for item in update_member_rev_overall:
                    update_member_revision(item)

            if not build_script_1_overall and not build_script_2_overall and not build_script_3_overall:
                logger.warning('No script provided for generating an overall SDL/CDL (build_mode: "%s")!', build_mode)
            else:
                #generate an overall SDL/CDL and checkin those into Deliverables
                if build_script_1_overall:
                    if not run_cmd(build_script_1_overall, timeout_cmd):
                        logger.error('Overall build_script_1 failed (Generating SDL/CDL)!')
                        sys.exit(3)
                if build_script_2_overall:
                    if not run_cmd(build_script_2_overall, timeout_cmd):
                        logger.error('Overall build_script_2 failed')
                        sys.exit(3)
                if build_script_3_overall:
                    if not run_cmd(build_script_3_overall, timeout_cmd):
                        logger.error('Overall build_script_3 failed!')
                        sys.exit(3)

                # Checkin SDL/CDL.
                if ci_files_overall:
                    for f in ci_files_overall:
                        absolute_path = convert_ims_to_local_absolute_path(f)[0]
                        # Clear readonly flag for ci_files_overall files! Fixed the batch file by deleting the files.
                        if os.path.isfile(absolute_path):
                            os.chmod(absolute_path, stat.S_IWRITE)
                    logger.debug('Checkin generated SDL/CDL files:\n\t%s', '\n\t'.join(ci_files_overall))
                    checkin_files_list(ci_files_overall, ci_branch_iuc, project_cp_label, project_cp_label)  #ci_description
                else:
                    logger.warning('No SDL/CDL files to be checked-in (empty option in configuration files)!')

            # Configure build units and deliverables to previously created checkpoints and save devpaths
            if build_unit_iuc:
                devpaths_iuc = []
                for item in cp_subpj_iuc:
                    subproject_devpath = configure_project_build(item)[0]
                    devpaths_iuc.append(subproject_devpath)
            if build_unit_dpu:
                devpaths_dpu = []
                for item in cp_subpj_dpu:
                    subproject_devpath = configure_project_build(item)[0]
                    devpaths_dpu.append(subproject_devpath)
            if build_unit_sil:
                devpaths_sil = []
                for item in cp_subpj_sil:
                    subproject_devpath = configure_project_build(item)[0]
                    devpaths_sil.append(subproject_devpath)

            # Overall Checkpoint
            logger.debug('Checkpoint Overall for %s (%s)', base_project, project)
            if label is None:
                label = project_cp_label
            if broken:
                label = project_cp_broken_label
            elif unstable:
                label = project_cp_unstable_label

            description = get_overall_cp_description()
            
            logger.debug('Close change package: %s', cpid)
            close_cp(cpid)

            resp = ims.checkpoint(batch=None, project=base_project, devpath=devpath, label=label, description=description, checkpointUnchangedSubprojects=None, nolabelUnchangedSubprojects=None)

            #TODO: Create another change package!!!
            #logger.debug('Create change package')
            new_cpid = create_cp(ro, 'Step: checkpoint_subprojects (%s)' % summary_helper_cp(iuc=iuc, dpu=dpu, sil=sil, overall=overall))
            logger.debug('Create change package: %s', new_cpid)

            # Configure build units and deliverables back to variant
            #TODO: Be sure to set it to the original devpath which is not necessarily to one from configuration file(s) (save devpath at the begining of subcommand)
            if build_unit_iuc:
                for i, item in enumerate(cp_subpj_iuc):
                    configure_project_variant(item, devpaths_iuc[i]) #get_devpath_from_build(item)

                #TODO: Set shared buildunits back as shared variants.
                if devpath_buildunits_iuc:
                    '''
                file_devpaths_iuc = 'devpaths_iuc.txt'
                if os.path.isfile(file_devpaths_iuc):
                    with open(file_devpaths_iuc, 'r') as f:
                        devpaths = pickle.load(f)
                    '''
                    #TODO: Configure as variant subprojects from shared_buildunit only if configure_mode != 'releaseID' or if run_mode != integrator?!
                    #if configure_mode == 'latest':
                    for i, item in enumerate(shared_buildunit_iuc):
                        project_path = get_proj_subproj(item)[0]
                        configure_project_variant(project_path, devpath_buildunits_iuc[item]) #get_devpath_from_build(item)
                    '''
                    t = time.localtime()
                    timestamp = '_%d%02d%02d_%02d%02d%02d' % (t.tm_year, t.tm_mon, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec)
                    root, ext = os.path.splitext(file_devpaths_iuc)
                    new_file = root + timestamp + ext
                    os.rename(file_devpaths_iuc, new_file)
                else:
                    logger.error('File containing the devpath of the shared buildunit(s) does not exist ("%s")!', file_devpaths_iuc)
                    #sys.exit(9)
                    '''

            if build_unit_dpu:
                for i, item in enumerate(cp_subpj_dpu):
                    configure_project_variant(item, devpaths_dpu[i]) #get_devpath_from_build(item)

                #TODO: Set shared buildunits back as shared variants.
                if devpath_buildunits_dpu:
                    '''
                file_devpaths_dpu = 'devpaths_dpu.txt'
                if os.path.isfile(file_devpaths_dpu):
                    with open(file_devpaths_dpu, 'r') as f:
                        devpaths = pickle.load(f)
                    '''
                    #TODO: Configure as variant subprojects from shared_buildunit only if configure_mode != 'releaseID' or if run_mode != integrator?!
                    #if configure_mode == 'latest':
                    for i, item in enumerate(shared_buildunit_dpu):
                        project_path = get_proj_subproj(item)[0]
                        configure_project_variant(project_path, devpath_buildunits_dpu[item])  #get_devpath_from_build(item)
                    '''
                    t = time.localtime()
                    timestamp = '_%d%02d%02d_%02d%02d%02d' % (t.tm_year, t.tm_mon, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec)
                    root, ext = os.path.splitext(file_devpaths_dpu)
                    new_file = root + timestamp + ext
                    os.rename(file_devpaths_dpu, new_file)
                else:
                    logger.error('File containing the devpath of the shared buildunit(s) does not exist ("%s")!', file_devpaths_dpu)
                    #sys.exit(9)
                    '''

            if build_unit_sil:
                for i, item in enumerate(cp_subpj_sil):
                    configure_project_variant(item, devpaths_sil[i]) #get_devpath_from_build(item)

                #TODO: Set shared buildunits back as shared variants.

                if devpath_buildunits_sil:
                    '''
                file_devpaths_sil = 'devpaths_sil.txt'
                if os.path.isfile(file_devpaths_sil):
                    with open(file_devpaths_sil, 'r') as f:
                        devpaths = pickle.load(f)
                    '''
                    #TODO: Configure as variant subprojects from shared_buildunit only if configure_mode != 'releaseID' or if run_mode != integrator?!
                    #if configure_mode == 'latest':
                    for i, item in enumerate(shared_buildunit_sil):
                        project_path = get_proj_subproj(item)[0]
                        configure_project_variant(project_path, devpath_buildunits_sil[item])  #get_devpath_from_build(item)
                    '''
                    t = time.localtime()
                    timestamp = '_%d%02d%02d_%02d%02d%02d' % (t.tm_year, t.tm_mon, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec)
                    root, ext = os.path.splitext(file_devpaths_sil)
                    new_file = root + timestamp + ext
                    os.rename(file_devpaths_sil, new_file)
                else:
                    logger.error('File containing the devpath of the shared buildunit(s) does not exist ("%s")!', file_devpaths_sil)
                    #sys.exit(9)
                    '''

            if os.path.isfile(file_timestamp):
                os.remove(file_timestamp)
    except (APIException, Exception) as e:
        message = get_exception_message(e)
        logger.exception('Exception occurred: %s', e.message)
        #logger.info('Restoring the previous revision of the subprojects from "%s" file because of unsuccessfully configuring/checkpointing of a subproject.', file_old_config_rev)
        #restore_configure_subprojects(file_old_config_rev) #, removeFile=False
        sys.exit(1)

    logger.debug('Close change package: %s', cpid)
    close_cp(cpid)
    logger.debug('TO BE DONE...')

#return absolute local path using '/' as directory separator for a relative path (local, flatpath)
#TODO: Use shlex to correctly handle '\' characters in case of command lines (os.path.dirname(shlex.split(relative_path)[0]))
#TODO: Handle IMS absolute path (flatpath) for files only
def get_absolute_path(relative_path):
    if relative_path[1] == ':': #a path containing a ':' (colon) must be an absolute path
        absolute_path = relative_path.replace('\\', '/')
    elif relative_path.startswith('/'):
        s = '/' + project + '/'
        idx = relative_path.find(s)
        if idx == -1:
            raise ValueError('Absolute path (local) can not be determined using project="%s" and IMS flatpath: "%s"!' % (project, relative_path))
        relative_path = relative_path[idx+len(s):]
        absolute_path = os.path.join(sandbox, relative_path).replace('\\', '/')
        #if absolute_path.endswith('/project.pj'):
        #    absolute_path = absolute_path[:-len('/project.pj')]
    else:
        absolute_path = os.path.join(sandbox, relative_path).replace('\\', '/')
    return absolute_path

#returns the configpath of the base_project
def get_config_path():
    project_path = '#%s#d=%s#' % (base_project.replace('/project.pj', '').replace('/ADAS/SW/', '/ADAS/SW#', 1), devpath)
    return project_path

def get_trunk_proj_subproj(relative_path):
    if relative_path.startswith('#'): #configpath
        #TODO: Check for devpath (#d=)
        project_path = relative_path
        idx1 = project_path.rindex('/')
        idx2 = project_path.rindex('#')
        idx = max(idx1, idx2)
        proj = project_path[:idx]
        subproj = project_path[idx+1:] + '/project.pj'
        return project_path, proj, subproj
    elif relative_path.startswith('/'): #a path starting with '/' must be an absolute path
        project_path = relative_path
        relative_path = relative_path[len(base_project[:-len('project.pj')]):]
    else:
        project_path = base_project.replace('project.pj', relative_path)
    idx1 = project_path.rfind('/')
    idx2 = project_path[:idx1].rfind('/') + 1
    proj = project_path[:idx2] + project_path[idx1+1:]
    subproj = project_path[idx2:]
    return project_path, proj, subproj


#return a tuple (project_path, proj, subproj) based on 'relative_path' (flatpath, configpath):
#project_path: the configpath of the 'relative_path' (absolute path)
#proj:         configpath for entire project except last subproject (absolute path)
#subproj:      flatpath for last subproject (relative path)
def get_proj_subproj(relative_path):
    if relative_path.startswith('#'): #configpath
        #TODO: Check for devpath (#d=)
        project_path = relative_path
        idx1 = project_path.rindex('/')
        idx2 = project_path.rindex('#')
        idx = max(idx1, idx2)
        proj = project_path[:idx]
        subproj = project_path[idx+1:] + '/project.pj'
        return project_path, proj, subproj
    elif relative_path.startswith('/'): #a path starting with '/' must be an absolute path
        project_path = relative_path
        relative_path = relative_path[len(base_project[:-len('project.pj')]):]
    else:
        project_path = base_project.replace('project.pj', relative_path)
    idx1 = project_path.rfind('/')
    idx2 = project_path[:idx1].rfind('/') + 1
    #proj = project_path[:idx2] + 'project.pj'
    proj = project_path[:idx2] + project_path[idx1+1:]
    #TODO: Make it a config path
    proj = proj.replace(base_project[:-len('project.pj')], get_config_path())[:-len('/project.pj')]
    subproj = project_path[idx2:]
    #TODO: Make it a config path
    project_path = get_config_path() + relative_path.replace('/project.pj', '')
    return project_path, proj, subproj

#return a tuple (member_path, proj, member) based on 'relative_path' (flatpath):
#member_path: the flatpath of the 'relative_path' (absolute path)
#proj:        configpath for entire project except member (absolute path)
#member:      filename
def get_proj_member(relative_path):
    if relative_path.startswith('/'): #a path starting with '/' must be an absolute path
        member_path = relative_path
        relative_path = relative_path[len(base_project[:-len('project.pj')]):]
    else:
        member_path = base_project.replace('project.pj', relative_path)
    idx = member_path.rfind('/')
    proj = member_path[:idx]
    #TODO: Make it a config path
    proj = proj.replace(base_project[:-len('project.pj')], get_config_path())
    member = member_path[idx+1:]
    return member_path, proj, member

def update_member_revision(relative_path):
    #TODO: Update only if different!
    member_path, proj, member = get_proj_member(relative_path)
    resp = ims.archiveinfo(member, batch=None, project=proj)
    archive_name = resp.work_items[0].getField('archiveName').value
    archive_path, archive_proj, archive = get_proj_member(archive_name)
    resp = ims.memberinfo(archive, batch=None, project=archive_proj)
    rev = resp.work_items[0].getField('memberrevision').value
    resp = ims.updaterevision(member, batch=None, cpid=cpid, nocloseCP=None, revision=rev, project=proj)

##path: relative path - 06_Deliverables/DPU/project.pj
## Checkpoint the project in case the subproject is not shared, otherwise configure to latest available revision (already done in configure_subprojects) and add the label.
## This function is called when a subproject is in cp_subpj list, so for configure_mode = 'releaseID' (that's what integrators use) we need to checkpoint the shared buildunits instead of only setting the label!
#TODO: Split this function in multiple functions!
def checkpoint_project(relative_path, label, description, cp_always=False):
    project_rev = None
    project_path = get_proj_subproj(relative_path)[0] #, proj, subproj

    '''
    resp = ims.projectinfo(batch=None, project=project_path)
    project_name_flatpath = resp.work_items[0].getField('projectName').value
    shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
    # Check if subproject is actually shared
    if project_name_flatpath != shared_from_flatpath:
        #project_rev = resp.work_items[0].getField('revision').item.id
        #shared_from_configpath = get_proj_subproj(shared_from_flatpath)[0]
        #r = ims.projectinfo(batch=None, project=shared_from_configpath)
        project_rev = resp.work_items[0].getField('revision').item.id
        #logger.info('Subproject (buildunit) "%s" is shared from "%s" - it will be set to the latest available revision (revision: %s)', project_path, shared_from_flatpath, project_rev)
        #resp = ims.configuresubproject(subproj, batch=None, cpid=cpid, type='build', subprojectRevision=project_rev, project=proj)
        logger.info('Subproject (buildunit) "%s" is shared from "%s" - it will be only labeled (revision: %s)', project_path, shared_from_flatpath, project_rev)
        resp = ims.addprojectlabel(batch=None, label=label, project=shared_from_flatpath, projectRevision=project_rev) #, moveLabel=None, recurse=None, includeUnchangedSubprojects=None?
    else:
    '''
    #TODO: Check if the checkpoint is correctly done!!! It may need to make sure it's not shared build!
    resp = ims.checkpoint(batch=None, project=project_path, label=label, description=description, checkpointUnchangedSubprojects=None, nolabelUnchangedSubprojects=None)
    #TODO: The last one is the one we are looking for, because the command checkpoint recursively all the subprojects...
    for wi in resp.work_items:
        if wi.id.upper() == project_path.upper():
            #TODO: Check this again due to update in ims library (result = root)!!!
            project_rev = wi.result.primary_value.item.id
            break
    logger.info('Subproject "%s" successfully checkpointed (revision: %s)', project_path, project_rev)
    return project_rev

#return devpath and revision - to be deleted
def get_devpath_rev(relative_path):
    project_path = get_proj_subproj(relative_path)[0]
    resp = ims.projectinfo(batch=None, project=project_path)
    project_rev = resp.work_items[0].getField('revision').item.id
    developmentPath = resp.work_items[0].getField('developmentPath').item
    if developmentPath:
        subproject_devpath = developmentPath.id
    else:
        subproject_devpath = None
    return subproject_devpath, project_rev

def get_project_type(relative_path):
    project_path = get_proj_subproj(relative_path)[0]
    resp = ims.projectinfo(batch=None, project=project_path)
    project_type = resp.work_items[0].getField('projectType').value
    project_rev = resp.work_items[0].getField('revision').item.id
    return project_type, project_rev

def configure_project_normal(relative_path):
    project_path, proj, subproj = get_proj_subproj(relative_path)
    project_type, project_rev = get_project_type(project_path)
    if project_type != ProjectType.NORMAL:
        resp = ims.configuresubproject(subproj, batch=None, cpid=cpid, type='normal', project=proj)
    return project_type, project_rev

def get_devpath_from_build(relative_path):
    project_path, proj, subproj = get_proj_subproj(relative_path)
    resp = ims.projectinfo(batch=None, project=project_path)
    project_name_flatpath = resp.work_items[0].getField('projectName').value
    shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
    sharedRevision = resp.work_items[0].getField('revision').item.id
    sharedRevision = sharedRevision.split('.')
    # handle "as of" checkpoints
    if '0' in sharedRevision:
        sharedRevision = sharedRevision[:sharedRevision.index('0')]
    devPathRevision = '.'.join(sharedRevision[:-2])
    if devPathRevision == '':
        logger.info('This is trunk revision (%s) of "%s"!', sharedRevision, project_path)
        try:
            # Try to get the latest trunk revision, which could be different than :head if the component is configured as variant on the repository path
            # ex.: #/ADAS/SW#Components/Mcal/MCAL_MicroControllerAbstractionLayer/03_Design/03_Code_Generation/Project_Specific/MFC431TA19/Tresos/conf/MCAL_REN_EB
            r = ims.projectinfo(batch=None, project=shared_from_flatpath)
            latest_rev = r.work_items[0].getField('revision').item.id
        except APIException as e:
            if e.exception_class == 'ItemNotFoundException':
                logger.warning('Subproject "%s" was dropped in the meantime from the trunk...', shared_from_flatpath)
            else:
                message = get_exception_message(e)
                logger.exception('Exception occurred: %s', message)
            logger.warning('The latest revision will be used for subproject "%s" on devpath "%s"!"', shared_from_flatpath, devpath)
            latest_rev = ':head'
        return None, latest_rev
    cmpDevpathCandidates = []
    for item in resp.work_items[0].getField('developmentPaths').item_list:
        if item.getField('revision').item.id == devPathRevision:
            cmpDevpathCandidates.append(item.id)
    # TODO: Improve detection of the verification branch, by using the date of the first CP on the branch (viewprojecthistory)
    if project_path.upper() == '#/ADAS/SW#Projects/MFC431x/MFC431#d=MFC431_Verification_v1#M11_APPL/04_Engineering/00_Projects/MFC431SW19/VCS'.upper():
        dp = 'SW_VCS_DEVPATH_MFC431_FamilyBranch'
    else:
        dp = cmpDevpathCandidates[int(sharedRevision[-2]) - 1]
    logger.info('This is a branch revision (%s) of "%s"!', sharedRevision, project_path)
    try:
        r = ims.projectinfo(batch=None, project=project_name_flatpath, devpath=dp)
    except APIException:
        logger.warning('Subproject "%s" was dropped in the meantime from the trunk... Trying to use "sharedFrom" location "%s"', project_name_flatpath, shared_from_flatpath)
        try:
            r = ims.projectinfo(batch=None, project=shared_from_flatpath, devpath=dp)
        except APIException as e:
            logger.exception('Subproject "%s" was dropped in the meantime from the trunk... Trying to use "project_path" location %s', shared_from_flatpath, project_path)
            try:
                r = ims.projectinfo(batch=None, project=project_path)  # project_path should be config path containing devpath
            except APIException as e:
                logger.exception('Subproject "%s" can NOT be reconfigured', project_path)
                message = get_exception_message(e)
                logger.exception('Exception occurred: %s', message)
                sys.exit(1)
    latest_rev = r.work_items[0].getField('revision').item.id
    return dp, latest_rev

## Configure project to the latest checkpoint of the branch if 'project_rev=None', else as specified revision.
## In case project is shared build the devpath (branch) info is missing so you must provide that in as subpj_devpath - no need for this as it is automatically detected.
## Return the subproject_devpath of the relative_path parameter only if the subproject is not configured as build, else None
def configure_project_build(relative_path, project_rev=None): #, subpj_devpath=None, label=None
    project_path, proj, subproj = get_proj_subproj(relative_path)

    resp = ims.projectinfo(batch=None, project=project_path)

    developmentPath = resp.work_items[0].getField('developmentPath').item
    if developmentPath:
        subproject_devpath = developmentPath.id
    else:
        subproject_devpath = None

    if not project_rev:
        project_type = resp.work_items[0].getField('projectType').value
        ###TODO: Build shared projects can't be easily set to latest revision of variant (as the devpath info is missing) - try to use subpj_devpath!
        if project_type == ProjectType.BUILD:
            project_name_flatpath = resp.work_items[0].getField('projectName').value
            shared_from_flatpath = resp.work_items[0].getField('sharedFrom').value
            bp_path = base_project.replace('project.pj', '')
            """
            if subpj_devpath: #workaround for when a build unit is set as build shared because of interrupted checkpoint operation
                #Set it as variant first to get the latest revision on the branch...
                #TODO: Find the "y" in ".1.y" by counting all the devpaths starting with the same version, order is perserved! Or find a solution for pending operation without closing the CP.
                r = ims.configuresubproject(subproj, batch=None, cpid=cpid, type='variant', variant=subpj_devpath, project=proj)
                r = ims.projectinfo(batch=None, project=project_path)
                developmentPath = resp.work_items[0].getField('developmentPath').item
                if developmentPath:
                    subproject_devpath = developmentPath.id
                proj_crt_rev = r.work_items[0].getField('revision').item.id
            """
            if bp_path in project_name_flatpath and bp_path in shared_from_flatpath: #shared from same project -> is ok to call get_proj_subproj on it
                shared_from_configpath = get_proj_subproj(shared_from_flatpath)[0]
                r = ims.projectinfo(batch=None, project=shared_from_configpath)
                proj_crt_rev = r.work_items[0].getField('revision').item.id
            else:
                dp, proj_crt_rev = get_devpath_from_build(relative_path)
                '''
                #TODO: Determine the devpath from from the build shared, or better get the latest revision from the parent!!!
                parent_id = resp.work_items[0].parent_id
                #TODO: Check if there is no need to get all the subprojects recursively!!!
                r = ims.viewproject(batch=None, norecurse=None, project=parent_id)
                for wi in r.work_items:
                    if wi.id.upper() == project_path.upper():
                        proj_crt_rev = wi.getField('memberrev').item.id
                        break
                '''
                """
            elif label is not None: # the subproject was checkpointed previously with a label
                r = ims.viewprojecthistory(batch=None, project=project_path)
                revisions_field = r.work_items[0].getField('revisions').item_list
                for item in revisions_field:
                    labels_field = item.getField('labels').item_list
                    if label in labels_field:
                        proj_crt_rev = item.getField('revision').item.id
                        break
                else:
                    logger.error('Subproject "%s" has no revision labeled "%s"', project_path, label)
                    sys.exit(9)
                '''
            else:
                logger.error('A label must be provided to be able to find the revision to be set for subproject "%s"', project_path)
                sys.exit(9)
                '''
            else:
                logger.error('The subproject "%s" is set as build (shared) and no devpath was provided!', project_path)
                sys.exit(9)
                """
        else:
            proj_crt_rev = resp.work_items[0].getField('revision').item.id

        project_rev = proj_crt_rev

    #TODO: Check if project_rev != <crt rev of project_path>
    resp = ims.configuresubproject(subproj, batch=None, cpid=cpid, type='build', subprojectRevision=project_rev, project=proj)
    return subproject_devpath, project_rev

def configure_project_variant(relative_path, subpj_devpath=None):
    project_path, proj, subproj = get_proj_subproj(relative_path)
    if subpj_devpath is None:
        subpj_devpath = devpath
    #specify 'devpath' as '#d=TEST_PARALLEL_BRANCH' is NOT specified
    resp = ims.configuresubproject(subproj, batch=None, cpid=cpid, type='variant', variant=subpj_devpath, project=proj)

def get_checkpoint_rev(relative_path):
    project_path = get_proj_subproj(relative_path)[0]
    resp = ims.projectinfo(batch=None, project=project_path)
    project_rev = resp.work_items[0].getField('revision').item.id
    return project_rev

def num(conv, s):
    try:
        return conv(s)
    except: # (ValueError, TypeError) as e
        return None

def custom_subpj_cmp(item1, item2):
    x = item1.display_id.lower()
    y = item2.display_id.lower()
    #custom sort order: parent subproject first
    if x.endswith('/project.pj') and y.endswith('/project.pj'):
        xx = x[:-len('project.pj')]
        yy = y[:-len('project.pj')]
        if xx in yy:
            return -1
        elif yy in xx:
            return 1
    return cmp(x, y)

def custom_members_cmp(item1, item2):
    return cmp(item1.getField('name').value.lower(), item2.getField('name').value.lower())

#return a tuple of lists for subprojects and members
def get_members_subprojects(use_devpath=False): #checkpoint_revision
    if use_devpath:
        resp = ims.viewproject(batch=None, recurse=None, project=base_project, devpath=devpath) #, filter='!file:*'
    else:
        resp = ims.viewproject(batch=None, recurse=None, project=base_project) #, filter='!file:*'

    subpjs = []
    members = []
    
    for wi in resp.work_items:
        #if wi.model_type == Item.SI_SUBPROJECT:
        if wi.display_id.endswith('/project.pj'):
            #wi.display_id
            subpjs.append(wi)
        #elif wi.model_type == Item.SI_MEMBER:
        else:
            #wi.getField('name').value
            members.append(wi)

    #logger.info('Only distinct items (members and subprojects) found in "%s": ', xml_file, len(subpjs) + len(members) == len(resp.work_items))
    return subpjs, members

# No detection for changed shared location!
def get_diff(only_subpj=False): #False - members and subprojects. It is not possible to for "viewproject" command to return only members...
    #TODO: Fix UNICODE characters '\xe2\x80\x93', '\u2013' (e.g. long dash). This is only a cmd.exe problem, in the file the correct character is written.
    #print wi.getField('name').value.replace(u'\u2013', '?')
    #print wi.getField('name').value.encode('ISO-8859-1', 'xmlcharrefreplace') #UTF8, ISO-8859-1, ASCII, ignore, replace, xmlcharrefreplace

    subpj_trunk, members_trunk = get_members_subprojects()
    subpj_devpath, members_devpath = get_members_subprojects(use_devpath=True)

    subpj_ex = [] #list of subprojects that are/shoud be in the exception list
    members_ex = [] #list of members that must manualy be set to "correct" revision
    subpj_diff = [] #list of all subprojects that are set to a different revision (even no revision)
    members_diff = [] #list of all members that are set to a different revision

    subpj_trunk_items = [item.display_id for item in subpj_trunk]
    members_trunk_items = [item.getField('name').value for item in members_trunk]
    subpj_devpath_items = [item.display_id for item in subpj_devpath]
    members_devpath_items = [item.getField('name').value for item in members_devpath]

    logger.debug('Start subpj_dropped')
    start = time.time()
    #subpj_dropped = list(subpj_devpath - subpj_trunk)
    subpj_dropped = []
    for item in subpj_devpath:
        try:
            index = subpj_trunk_items.index(item.display_id)
            memberrev_field1 = item.getField('memberrev')
            memberrev_field2 = subpj_trunk[index].getField('memberrev')
            if memberrev_field1 and memberrev_field2:
                memberrev1 = memberrev_field1.item.id
                memberrev2 = memberrev_field2.item.id
                if memberrev1 != memberrev2:
                    # Add subproject to diff list because of different revision
                    subpj_diff.append((item, memberrev1, memberrev2))
                    #TODO: Add subproject to exception list because it is set as build shared on trunk (children subprojects will be removed later).
                    subpj_ex.append(item)
            elif memberrev_field1:
                memberrev1 = memberrev_field1.item.id
                memberrev2 = '?:head?'
                # Add subproject to diff list because it is configured as normal or variant on trunk
                subpj_diff.append((item, memberrev1, memberrev2))
            elif memberrev_field2:
                memberrev1 = '?variant?'
                memberrev2 = memberrev_field2.item.id
                # Add subproject to diff list because it was reconfigured as normal or variant (shared) on branch
                subpj_diff.append((item, memberrev1, memberrev2))
        except ValueError:
            subpj_dropped.append(item)
    subpj_dropped.sort(cmp=custom_subpj_cmp)
    stop = time.time()
    logger.debug('Time subpj_dropped: %.2fs', stop - start)

    logger.debug('Start subpj_added')
    start = time.time()
    #subpj_added = list(subpj_trunk - subpj_devpath)
    subpj_added = []
    for item in subpj_trunk:
        if item.display_id not in subpj_devpath_items:
            subpj_added.append(item)
    subpj_added.sort(cmp=custom_subpj_cmp)
    stop = time.time()
    logger.debug('Time subpj_added: %.2fs', stop - start)

    logger.debug('Start subpj_ex trimming')
    start = time.time()
    #TODO: Remove children subprojects of any kinds. The list is sorted in a custom order (parent subproject first).
    parent = '?'
    for item in subpj_ex[:]:
        subpj = item.display_id.upper()
        if subpj.startswith(parent):
            subpj_ex.remove(item)
        else:
            parent = subpj[:subpj.rfind('/')]
    stop = time.time()
    logger.debug('Time subpj_ex trimming: %.2fs', stop - start)

    logger.debug('Start members_dropped')
    start = time.time()
    #members_dropped = list(members_devpath - members_trunk)
    members_dropped = []
    for item in members_devpath:
        try:
            index = members_trunk_items.index(item.getField('name').value)
            memberrev1 = item.getField('memberrev').item.id
            memberrev2 = members_trunk[index].getField('memberrev').item.id
            if memberrev1 != memberrev2:
                # Add memeber to diff list because of different revision
                members_diff.append((item, memberrev1, memberrev2))
                #TODO: Add member to exception list because it has different revision (it will be removed later if it is part of a subproject that was reconfigured).
                members_ex.append(item)
        except ValueError:
            members_dropped.append(item)
    members_dropped.sort(cmp=custom_members_cmp)
    stop = time.time()
    logger.debug('Time members_dropped: %.2fs', stop - start)

    logger.debug('Start members_added')
    start = time.time()
    #members_added = list(members_trunk - members_devpath)
    members_added = []
    for item in members_trunk:
        if item.getField('name').value not in members_devpath_items:
            members_added.append(item)
    members_added.sort(cmp=custom_members_cmp)
    stop = time.time()
    logger.debug('Time members_added: %.2fs', stop - start)

    logger.debug('Start members_ex trimming')
    start = time.time()
    subpj_diff_items = [item[0].display_id for item in subpj_diff] # #subpj_ex
    #TODO: Remove members that are part of a subproject that was reconfigured because reconfiguring the subproject will take care of them!
    # (even if subproject is normal shared on trunk)
    for item in members_ex[:]:
        #parent = item.context.upper()
        parent = item.getField('parent').value.upper()
        for item_subpj in subpj_diff_items:
            subpj = item_subpj[:item_subpj.rfind('/')].upper()
            if parent.startswith(subpj):
                members_ex.remove(item)
                break
    stop = time.time()
    logger.debug('Time members_ex trimming: %.2fs', stop - start)

    with open(diff_subprojects, 'w+') as f:
        f.write('Subprojects dropped on trunk:\n')
        if not subpj_dropped:
            f.write('\tNo subproject dropped on trunk\n')
        for item in subpj_dropped:
            f.write('\t%s\n' % item.display_id.encode('utf-8'))

        f.write('Subprojects added on trunk:\n')
        if not subpj_added:
            f.write('\tNo subproject added on trunk\n')
        for item in subpj_added:
            f.write('\t%s\n' % item.display_id.encode('utf-8'))

        f.write('Subprojects with changed revision (only parents -> exception list):\n')
        if not subpj_ex:
            f.write('\tNo subproject with changed revision\n')
        for item in subpj_ex:
            f.write('\t%s\n' % item.display_id.encode('utf-8'))

        f.write('Subprojects with no/changed revision (build shared, head and devpath):\n')
        if not subpj_diff:
            f.write('\tNo subproject with changed revision\n')
        for item in subpj_diff:
            f.write('\t%s (devpath: %s, trunk: %s)\n' % (item[0].display_id.encode('utf-8'), item[1], item[2]))

    with open(diff_members, 'w+') as f:
        f.write('Members dropped on trunk:\n')
        if not members_dropped:
            f.write('\tNo member dropped on trunk\n')
        for item in members_dropped:
            f.write('\t%s\n' % item.getField('name').value.encode('utf-8'))

        f.write('Members added on trunk:\n')
        if not members_added:
            f.write('\tNo member added on trunk\n')
        for item in members_added:
            f.write('\t%s\n' % item.getField('name').value.encode('utf-8'))

        f.write('Members with changed revision (not part of reconfigured subproject):\n')
        if not members_ex:
            f.write('\tNo member with changed revision\n')
        for item in members_ex:
            f.write('\t%s\n' % item.getField('name').value.encode('utf-8'))

        f.write('Members with changed revision (all):\n')
        if not members_diff:
            f.write('\tNo member wiht changed revision\n')
        for item in members_diff:
            f.write('\t%s (devpath: %s, trunk: %s)\n' % (item[0].getField('name').value.encode('utf-8'), item[1], item[2]))

# Create the sandbox; if drop is True first drop the subproject; if resync is true the sandbox will be also resynced.
def create_sandbox(drop=False, resync=False):
    project_path = get_config_path()
    try:
        resp = ims.sandboxes(batch=None) # manage=None
        for wi in resp.work_items:
            # print wi.getField('sandboxName').value
            sb = wi.getField('sandboxName').value.replace('\\', '/').upper().strip('/PROJECT.PJ')
            hm = wi.getField('server').item.getField('hostname').value.upper()
            pt = wi.getField('server').item.getField('port').value
            if sb == sandbox.upper():
                if not (hm == hostname.upper() and pt == portSI):
                    logger.error('Sandbox "%s" found on another server (%s:%s)!', sandbox, hm, pt)
                    sys.exit(1)
                logger.info('Sandbox "%s" exists!', sandbox)
                if drop:
                    logger.info('Dropping the sandbox...')
                    resp = ims.dropsandbox(sandbox+'/project.pj', batch=None, forceConfirm='yes', delete='all') # noconfirm=None, delete='members'
                    logger.info('Sandbox "%s" will be recreated!', sandbox)
                    resp = ims.createsandbox(sandbox, batch=None, project=base_project, devpath=devpath, norecurse=None) # , populate=None, noopenView=None
                break
        else:
            if drop:
                logger.warning('Sandbox "%s" does not exist, so cannot be dropped!', sandbox)
            logger.info('Sandbox "%s" does not exist, it will be created!', sandbox)
            resp = ims.createsandbox(sandbox, batch=None, project=base_project, devpath=devpath, norecurse=None) # , populate=None, noopenView=None
        if resync:
            logger.info('Resync sandbox "%s"...', sandbox)
            project_resync()
        else:
            logger.warning('Sandbox resync NOT performed!')
    except (APIException, Exception) as e:
        message = get_exception_message(e)
        logger.exception('Exception occurred: %s', message)
        sys.exit(1)
    pass


'''create_config()
def create_config(config_name):
    config = ConfigParser.RawConfigParser()
    config.add_section('IMS')
    config.set('IMS', 'hostname', 'ims-adas-test1')
    config.set('IMS', 'port', '8101')
    config.set('IMS', 'user', '')
    config.set('IMS', 'password', '')
    config.set('IMS', 'project', '/ADAS/SW/Test/07_Projects/MFC431x/MFC431/project.pj')
    #config.set('IMS', 'project', '/ADAS/SW/Projects/MFC431x/MFC431/05_Testing/05_Test_Environment/CANOE/project.pj')
    config.set('IMS', 'cpid', '')

    # Writing our configuration file to 'config_subpj.ini'
    with open(config_name, 'wb') as configfile:
        config.write(configfile)
'''

def expand_label(label, default_label, timestamp):
    date = '%s_%s_%s' % (timestamp.tm_year, timestamp.tm_mon, timestamp.tm_mday)
    timeofday = '%02d%02d%02d' % (timestamp.tm_hour, timestamp.tm_min, timestamp.tm_sec)

    if not label:
        logger.warning('No checkpoint label found in configuration file, using the default one: "%s"!', default_label)
        label = default_label
    label = label.replace('{date}', date)
    label = label.replace('{time}', timeofday)
    label = label.replace('{project}', project)
    return label

def read_config(config_files, first_subcommand=False):
    logger.info('Start reading configuration(s):\n\t%s', '\n\t'.join(config_files))
    config = MyConfigParser() #ConfigParser.ConfigParser()

    try:
        found_cfg = config.read(config_files)
        if found_cfg:
            #logger.info('Found configuration(s):\n\t%s', '\n\t'.join(found_cfg))
            not_found_cfg = list(set(config_files) - set(found_cfg))
            if not_found_cfg:
                logger.warning('NOT found configuration(s):\n\t%s', '\n\t'.join(not_found_cfg))
        else:
            logger.error("No configuration file found!")
            return False

        global file_old_config_rev, file_timestamp, diff_subprojects, diff_members, no_log_files, no_retries, timeout_ims, timeout_cmd
        #global timeout_iuc_release, timeout_iuc_debug, timeout_dpu, timeout_sil
        #global timeout_connect, timeout_locate, timeout_checkin, timeout_checkout, timeout_configure, timeout_checkpoint, timeout_viewissue, timeout_issues
        global hostname, portSI, portIM, user, password
        global base_project, family, project, devpath, projectRevision, run_mode, configure_mode, build_mode, releaseID, cpid, ro
        global project_cp_label, project_cp_unstable_label, project_cp_broken_label, checkinUnchanged, ci_description, cp_description, resync_subprojects
        global update_members_to_trunk_rev_iuc, update_subpj_to_trunk_rev_iuc, update_all_subpj_to_trunk_rev_iuc
        global update_members_to_trunk_rev_dpu, update_subpj_to_trunk_rev_dpu, update_all_subpj_to_trunk_rev_dpu
        global update_members_to_trunk_rev_sil, update_subpj_to_trunk_rev_sil, update_all_subpj_to_trunk_rev_sil
        global update_member_rev_overall, build_script_1_overall, build_script_2_overall, build_script_3_overall, ci_files_overall, description_overall
        global sandbox
        global build_units
        global build_unit_iuc, cp_label_iuc, ci_branch_iuc, cfg_outside_buildunit_iuc, sw_ver_iuc, build_script_1_iuc, build_script_2_iuc, build_script_3_iuc, build_script_4_iuc
        global cp_subpj_iuc, shared_buildunit_iuc, devpath_buildunits_iuc, cfg_prev_cp_iuc, cpy_out_script_1_iuc, cpy_out_script_2_iuc, cpy_out_script_3_iuc, cpy_out_script_4_iuc, ci_files_iuc, ex_files_iuc, ex_files_releaseID_iuc, co_latest_cp_iuc, deliverables_iuc
        global build_unit_dpu, cp_label_dpu, ci_branch_dpu, cfg_outside_buildunit_dpu, sw_ver_dpu, build_script_1_dpu, build_script_2_dpu, build_script_3_dpu, build_script_4_dpu
        global cp_subpj_dpu, shared_buildunit_dpu, devpath_buildunits_dpu, cfg_prev_cp_dpu, cpy_out_script_1_dpu, cpy_out_script_2_dpu, cpy_out_script_3_dpu, cpy_out_script_4_dpu, ci_files_dpu, ex_files_dpu, ex_files_releaseID_dpu, co_latest_cp_dpu, deliverables_dpu #sw_ver_2_dpu
        global build_unit_sil, cp_label_sil, ci_branch_sil, cfg_outside_buildunit_sil, sw_ver_sil, build_script_1_sil, build_script_2_sil, build_script_3_sil, build_script_4_sil
        global sw_ver_type_iuc, sw_ver_type_dpu, sw_ver_type_sil
        global cp_subpj_sil, shared_buildunit_sil, devpath_buildunits_sil, cfg_prev_cp_sil, cpy_out_script_1_sil, cpy_out_script_2_sil, cpy_out_script_3_sil, cpy_out_script_4_sil, ci_files_sil, ex_files_sil, ex_files_releaseID_sil, co_latest_cp_sil, deliverables_sil
        global ex_sections_files

        #TODO: Provide defaults for all the options!
        file_old_config_rev = config.get('CONFIGURATION', 'file_old_config_rev')
        if not file_old_config_rev: file_old_config_rev = 'old_config_rev.txt'
        file_timestamp = config.get('CONFIGURATION', 'file_timestamp')
        if not file_timestamp: file_timestamp = 'file_timestamp.txt'
        diff_subprojects = config.get('CONFIGURATION', 'diff_subprojects')
        if not diff_subprojects: diff_subprojects = 'diff_subprojects.txt'
        diff_members = config.get('CONFIGURATION', 'diff_members')
        if not diff_members: diff_members = 'diff_members.txt'
        no_log_files = config.getint('CONFIGURATION', 'no_log_files')
        no_retries = config.getint('CONFIGURATION', 'no_retries')
        timeout_ims = config.getfloat('CONFIGURATION', 'timeout_ims')
        if not timeout_ims:
            logger.warning('No timeout for IMS commands specified in configuration file!')
        timeout_cmd = config.getfloat('CONFIGURATION', 'timeout_cmd')
        if not timeout_cmd:
            logger.warning('No timeout for CMD commands specified in configuration file!')
        #timeout_iuc_release = config.getfloat('CONFIGURATION', 'timeout_iuc_release')
        #timeout_iuc_debug = config.getfloat('CONFIGURATION', 'timeout_iuc_debug')
        #timeout_dpu = config.getfloat('CONFIGURATION', 'timeout_dpu')
        #timeout_sil = config.getfloat('CONFIGURATION', 'timeout_sil')
        '''Other unused timeout options
        #timeout_connect = config.get('CONFIGURATION', 'timeout_connect')
        #timeout_locate = config.get('CONFIGURATION', 'timeout_locate')
        #timeout_checkin = config.get('CONFIGURATION', 'timeout_checkin')
        #timeout_checkout = config.get('CONFIGURATION', 'timeout_checkout')
        #timeout_configure = config.get('CONFIGURATION', 'timeout_configure')
        #timeout_checkpoint = config.get('CONFIGURATION', 'timeout_checkpoint')
        #timeout_viewissue = config.get('CONFIGURATION', 'timeout_viewissue')
        #timeout_issues = config.get('CONFIGURATION', 'timeout_issues')
        '''

        hostname = config.get('IMS', 'hostname')
        portSI = config.get('IMS', 'portSI')
        portIM = config.get('IMS', 'portIM')
        user = config.get('IMS', 'user')
        password = config.get('IMS', 'password')
        
        sandbox = config.get('SANDBOX', 'sandbox')
        if not sandbox:
            logger.error('Mandatory option empty or not found in section [SANDBOX]: sandbox!')
            sys.exit(2)
        else:
            #TODO: Converting '\' in '/' is done in 'get_absolute_path' function...
            sandbox = sandbox.replace('\\', '/')

        family = config.get('PROJECT', 'family')
        project = config.get('PROJECT', 'project')
        if not project:
            logger.error('Mandatory option empty or not found in section [PROJECT]: project!')
            sys.exit(2)
        base_project = config.get('PROJECT', 'base_project')
        if not base_project:
            logger.error('Mandatory option empty or not found in section [PROJECT]: base_project!')
            sys.exit(2)
        devpath = config.get('PROJECT', 'devpath')
        if not devpath:
            logger.error('Mandatory option empty or not found in section [PROJECT]: devpath!')
            sys.exit(2)
        #projectRevision = config.get('PROJECT', 'projectRevision')
        accepted_run_mode = ['nightlybuilds', 'integrator']
        run_mode = config.get('PROJECT', 'run_mode')
        if run_mode not in accepted_run_mode:
            logger.error('Mandatory option empty, not found or incorrect in section [PROJECT]: run_mode (accepted values: %s, value read: "%s")!', accepted_run_mode, run_mode)
            sys.exit(2)
        accepted_configure_mode = ['releaseID', 'latest']
        configure_mode = config.get('PROJECT', 'configure_mode')
        if configure_mode not in accepted_configure_mode:
            logger.error('Mandatory option empty, not found or incorrect in section [PROJECT]: configure_mode (accepted values: %s, value read: "%s")!', accepted_configure_mode, configure_mode)
            sys.exit(2)
        if configure_mode == 'releaseID':
            #TODO: In case there is an empty 'releaseID=' in config, this will throw an exception, but it is ok as the script cannot continue. Is even better then setting it to 0.
            releaseID = config.getint('PROJECT', 'releaseID', 0)
        else:
            # if configure_mode == 'latest' ignore option releaseID
            releaseID = 0
        build_mode = config.get('PROJECT', 'build_mode')
        # cpid = config.get('PROJECT', 'cpid')
        ro = config.get('PROJECT', 'ro')
        if not ro:
            logger.error('Mandatory option empty or not found in section [PROJECT]: ro!')
            sys.exit(2)

        #TODO: Delete the timestamp file if we are on the first subcommand to ensure a clean start of the integration process!
        if first_subcommand and os.path.isfile(file_timestamp):
            os.remove(file_timestamp)
        elif not first_subcommand and not os.path.isfile(file_timestamp):
            logger.warning('This is not the first subcommand ("%s") and the timestamp file "%s" does not exist!', kwargs['subcommand'], file_timestamp)
            logger.warning('The file will be created but there can be problems with checkins and checkpoints labels/description in case {date} and {time} tags are used...')
        #TODO: Create timestamp file on the first subcommand (if not already present). It will be deleted after overall checkpoint.
        if os.path.isfile(file_timestamp):
            with open(file_timestamp, 'r') as f:
                timestamp = pickle.load(f)
        else:
            timestamp = time.localtime()
            with open(file_timestamp, 'w') as f:
                pickle.dump(timestamp, f)

        project_cp_label = config.get('PROJECT', 'project_cp_label')
        project_cp_label = expand_label(project_cp_label, 'SWI_{project}_{date}_{time}', timestamp)
        project_cp_unstable_label = config.get('PROJECT', 'project_cp_unstable_label')
        project_cp_unstable_label = expand_label(project_cp_unstable_label, 'Unstable_{project}_{date}_{time}', timestamp)
        project_cp_broken_label = config.get('PROJECT', 'project_cp_broken_label')
        project_cp_broken_label = expand_label(project_cp_broken_label, 'Broken_{project}_{date}_{time}', timestamp)

        resync_subprojects = config.getlist('PROJECT', 'resync_subprojects')
        resync_subprojects[:] = [get_absolute_path(item) for item in resync_subprojects]

        checkinUnchanged = config.get('PROJECT', 'checkinUnchanged')
        ci_description = config.get('PROJECT', 'ci_description')
        cp_description = config.get('PROJECT', 'cp_description')
        
        '''test label template parsing
        cp_checkpointUnchangedSubprojects = config.getboolean('IMS', 'cp_checkpointUnchangedSubprojects')
        cp_labelUnchangedSubprojects = config.getboolean('IMS', 'cp_labelUnchangedSubprojects')
        custom_subprojs = config.sections()
        custom_subprojs.remove('IMS')
        for item in custom_subprojs:
            rev = config.get(item, 'revision')
            #print 'REVISION: ' + rev
            custom_subprojects[item] = rev
        '''

        build_units = config.getlist('BUILD_UNITS', 'build_units')
        if not build_units:
            logger.error('Mandatory option empty or not found in section [BUILD_UNITS]: build_units!')
            sys.exit(2)

        description_overall = config.getlist('OVERALL', 'description_overall')
        update_member_rev_overall = config.getlist('OVERALL', 'update_member_rev')
        build_script_1_overall = config.get('OVERALL', 'build_script_1')
        build_script_2_overall = config.get('OVERALL', 'build_script_2')
        build_script_3_overall = config.get('OVERALL', 'build_script_3')
        ci_files_overall = config.getlist('OVERALL', 'ci_files')

        if 'IUC' in build_units:
            build_unit_iuc = config.get('IUC', 'build_unit')
            if not build_unit_iuc:
                logger.error('Mandatory option empty or not found in section [IUC]: build_unit!')
                sys.exit(2)
            cp_label_iuc = config.get('IUC', 'cp_label')
            cp_label_iuc = expand_label(cp_label_iuc, 'SWI_{project}_IuC_{date}_{time}', timestamp)
            ci_branch_iuc = config.getboolean('IUC', 'ci_branch')
            cfg_outside_buildunit_iuc = config.getboolean('IUC', 'cfg_outside_buildunit')
            sw_ver_iuc = config.get('IUC', 'sw_ver')
            sw_ver_type_iuc = config.get('IUC', 'sw_ver_type')
            co_latest_cp_iuc = config.get('IUC', 'co_latest_cp')
            deliverables_iuc = config.get('IUC', 'deliverables')
            build_script_1_iuc = config.get('IUC', 'build_script_1')
            build_script_2_iuc = config.get('IUC', 'build_script_2')
            build_script_3_iuc = config.get('IUC', 'build_script_3')
            build_script_4_iuc = config.get('IUC', 'build_script_4')
            cpy_out_script_1_iuc = config.getlist('IUC', 'cpy_out_script_1')
            if cpy_out_script_1_iuc:
                cpy_out_script_1_iuc[:] = [get_absolute_path(item) for item in cpy_out_script_1_iuc]
            cpy_out_script_2_iuc = config.getlist('IUC', 'cpy_out_script_2')
            if cpy_out_script_2_iuc:
                cpy_out_script_2_iuc[:] = [get_absolute_path(item) for item in cpy_out_script_2_iuc]
            cpy_out_script_3_iuc = config.getlist('IUC', 'cpy_out_script_3')
            if cpy_out_script_3_iuc:
                cpy_out_script_3_iuc[:] = [get_absolute_path(item) for item in cpy_out_script_3_iuc]
            cpy_out_script_4_iuc = config.getlist('IUC', 'cpy_out_script_4')
            if cpy_out_script_4_iuc:
                cpy_out_script_4_iuc[:] = [get_absolute_path(item) for item in cpy_out_script_4_iuc]
            cp_subpj_iuc = config.getlist('IUC', 'cp_subpj', [])
            shared_buildunit_iuc = config.getlist('IUC', 'shared_buildunit', [])
            if set(cp_subpj_iuc) & set(shared_buildunit_iuc):
                logger.error('The lists "cp_subpj" and "shared_buildunit" cannot have items in common (iuc)!')
                sys.exit(2)
            devpath_buildunits_iuc = config.getlist('IUC', 'devpath_buildunits', [])
            if devpath_buildunits_iuc:
                #devpath_buildunits_iuc = dict(itertools.izip_longest([get_proj_subproj(item)[0] for item in devpath_buildunits_iuc[::2]], devpath_buildunits_iuc[1::2]))
                devpath_buildunits_iuc = dict(itertools.izip_longest(devpath_buildunits_iuc[::2], devpath_buildunits_iuc[1::2]))
            cfg_prev_cp_iuc = config.getlist('IUC', 'cfg_prev_cp')
            ci_files_iuc = config.getlist('IUC', 'ci_files')
            ex_files_iuc = config.getlist('IUC', 'ex_files')
            ex_files_releaseID_iuc = config.getlist('IUC', 'ex_files_releaseID')
            if ex_files_releaseID_iuc:
                if ex_files_releaseID_iuc[0] == 'ex_files':
                    ex_files_releaseID_iuc = ex_files_iuc
                    logger.info('Using "ex_files" list for integration based on a releaseID as well (iuc)')
                else:
                    logger.info('Using a separated list of exclude for integration based on a releaseID (iuc)')
            else:
                logger.info('No list of exclude will be used for integration based on a releaseID (iuc)')

            update_members_to_trunk_rev_iuc = config.getlist('IUC', 'update_members_to_trunk_rev', [])
            #update_members_to_trunk_rev_iuc[:] = [get_absolute_path(item) for item in update_members_to_trunk_rev_iuc]
            update_subpj_to_trunk_rev_iuc = config.getlist('IUC', 'update_subpj_to_trunk_rev', [])
            #update_subpj_to_trunk_rev_iuc[:] = [get_absolute_path(item) for item in update_subpj_to_trunk_rev_iuc]
            update_all_subpj_to_trunk_rev_iuc = config.getboolean('IUC', 'update_all_subpj_to_trunk_rev')
        else:
            build_unit_iuc = None

        if 'DPU' in build_units:
            build_unit_dpu = config.get('DPU', 'build_unit')
            if not build_unit_dpu:
                logger.error('Mandatory option empty or not found in section [DPU]: build_unit!')
                sys.exit(2)
            cp_label_dpu = config.get('DPU', 'cp_label')
            cp_label_dpu = expand_label(cp_label_dpu, 'SWI_{project}_DPU_{date}_{time}', timestamp)
            ci_branch_dpu = config.getboolean('DPU', 'ci_branch')
            cfg_outside_buildunit_dpu = config.getboolean('DPU', 'cfg_outside_buildunit')
            sw_ver_dpu = config.get('DPU', 'sw_ver') #sw_ver_2_dpu = config.get('DPU', 'sw_ver_2')
            sw_ver_type_dpu = config.get('DPU', 'sw_ver_type')
            co_latest_cp_dpu = config.get('DPU', 'co_latest_cp')
            deliverables_dpu = config.get('DPU', 'deliverables')
            build_script_1_dpu = config.get('DPU', 'build_script_1')
            build_script_2_dpu = config.get('DPU', 'build_script_2')
            build_script_3_dpu = config.get('DPU', 'build_script_3')
            build_script_4_dpu = config.get('DPU', 'build_script_4')
            cpy_out_script_1_dpu = config.getlist('DPU', 'cpy_out_script_1')
            if cpy_out_script_1_dpu:
                cpy_out_script_1_dpu[:] = [get_absolute_path(item) for item in cpy_out_script_1_dpu]
            cpy_out_script_2_dpu = config.getlist('DPU', 'cpy_out_script_2')
            if cpy_out_script_2_dpu:
                cpy_out_script_2_dpu[:] = [get_absolute_path(item) for item in cpy_out_script_2_dpu]
            cpy_out_script_3_dpu = config.getlist('DPU', 'cpy_out_script_3')
            if cpy_out_script_3_dpu:
                cpy_out_script_3_dpu[:] = [get_absolute_path(item) for item in cpy_out_script_3_dpu]
            cpy_out_script_4_dpu = config.getlist('DPU', 'cpy_out_script_4')
            if cpy_out_script_4_dpu:
                cpy_out_script_4_dpu[:] = [get_absolute_path(item) for item in cpy_out_script_4_dpu]
            cp_subpj_dpu = config.getlist('DPU', 'cp_subpj', [])
            shared_buildunit_dpu = config.getlist('DPU', 'shared_buildunit', [])
            if set(cp_subpj_dpu) & set(shared_buildunit_dpu):
                logger.error('The lists "cp_subpj" and "shared_buildunit" cannot have items in common (dpu)!')
                sys.exit(2)
            devpath_buildunits_dpu = config.getlist('DPU', 'devpath_buildunits', [])
            if devpath_buildunits_dpu:
                #devpath_buildunits_dpu = dict(itertools.izip_longest([get_proj_subproj(item)[0] for item in devpath_buildunits_dpu[::2]], devpath_buildunits_dpu[1::2]))
                devpath_buildunits_dpu = dict(itertools.izip_longest(devpath_buildunits_dpu[::2], devpath_buildunits_dpu[1::2]))
            cfg_prev_cp_dpu = config.getlist('DPU', 'cfg_prev_cp')
            ci_files_dpu = config.getlist('DPU', 'ci_files')
            ex_files_dpu = config.getlist('DPU', 'ex_files')
            ex_files_releaseID_dpu = config.getlist('DPU', 'ex_files_releaseID')
            if ex_files_releaseID_dpu:
                if ex_files_releaseID_dpu[0] == 'ex_files':
                    ex_files_releaseID_dpu = ex_files_dpu
                    logger.info('Using "ex_files" list for integration based on a releaseID as well (dpu)')
                else:
                    logger.info('Using a separated list of exclude for integration based on a releaseID (dpu)')
            else:
                logger.info('No list of exclude will be used for integration based on a releaseID (dpu)')

            update_members_to_trunk_rev_dpu = config.getlist('DPU', 'update_members_to_trunk_rev', [])
            #update_members_to_trunk_rev_dpu[:] = [get_absolute_path(item) for item in update_members_to_trunk_rev_dpu]
            update_subpj_to_trunk_rev_dpu = config.getlist('DPU', 'update_subpj_to_trunk_rev', [])
            #update_subpj_to_trunk_rev_dpu[:] = [get_absolute_path(item) for item in update_subpj_to_trunk_rev_dpu]
            update_all_subpj_to_trunk_rev_dpu = config.getboolean('DPU', 'update_all_subpj_to_trunk_rev')
        else:
            build_unit_dpu = None

        if 'SIL' in build_units:
            build_unit_sil = config.get('SIL', 'build_unit')
            if not build_unit_sil:
                logger.error('Mandatory option empty or not found in section [SIL]: build_unit!')
                sys.exit(2)
            cp_label_sil = config.get('SIL', 'cp_label')
            cp_label_sil = expand_label(cp_label_sil, 'SWI_DPU_{project}_{date}_{time}', timestamp)
            ci_branch_sil = config.getboolean('SIL', 'ci_branch')
            cfg_outside_buildunit_sil = config.getboolean('DPU', 'cfg_outside_buildunit')
            sw_ver_sil = config.get('SIL', 'sw_ver')
            sw_ver_type_sil = config.get('SIL', 'sw_ver_type')
            co_latest_cp_sil = config.get('SIL', 'co_latest_cp')
            deliverables_sil = config.get('SIL', 'deliverables')
            build_script_1_sil = config.get('SIL', 'build_script_1')
            build_script_2_sil = config.get('SIL', 'build_script_2')
            build_script_3_sil = config.get('SIL', 'build_script_3')
            build_script_4_sil = config.get('SIL', 'build_script_4')
            cpy_out_script_1_sil = config.getlist('SIL', 'cpy_out_script_1')
            if cpy_out_script_1_sil:
                cpy_out_script_1_sil[:] = [get_absolute_path(item) for item in cpy_out_script_1_sil]
            cpy_out_script_2_sil = config.getlist('SIL', 'cpy_out_script_2')
            if cpy_out_script_2_sil:
                cpy_out_script_2_sil[:] = [get_absolute_path(item) for item in cpy_out_script_2_sil]
            cpy_out_script_3_sil = config.getlist('SIL', 'cpy_out_script_3')
            if cpy_out_script_3_sil:
                cpy_out_script_3_sil[:] = [get_absolute_path(item) for item in cpy_out_script_3_sil]
            cpy_out_script_4_sil = config.getlist('SIL', 'cpy_out_script_4')
            if cpy_out_script_4_sil:
                cpy_out_script_4_sil[:] = [get_absolute_path(item) for item in cpy_out_script_4_sil]
            cp_subpj_sil = config.getlist('SIL', 'cp_subpj', [])
            shared_buildunit_sil = config.getlist('SIL', 'shared_buildunit', [])
            if set(cp_subpj_sil) & set(shared_buildunit_sil):
                logger.error('The lists "cp_subpj" and "shared_buildunit" cannot have items in common (sil)!')
                sys.exit(2)
            devpath_buildunits_sil = config.getlist('SIL', 'devpath_buildunits', [])
            if devpath_buildunits_sil:
                #devpath_buildunits_sil = dict(itertools.izip_longest([get_proj_subproj(item)[0] for item in devpath_buildunits_sil[::2]], devpath_buildunits_sil[1::2]))
                devpath_buildunits_sil = dict(itertools.izip_longest(devpath_buildunits_sil[::2], devpath_buildunits_sil[1::2]))
            cfg_prev_cp_sil = config.getlist('SIL', 'cfg_prev_cp')
            ci_files_sil = config.getlist('SIL', 'ci_files')
            ex_files_sil = config.getlist('SIL', 'ex_files')
            ex_files_releaseID_sil = config.getlist('SIL', 'ex_files_releaseID')
            if ex_files_releaseID_sil:
                if ex_files_releaseID_sil[0] == 'ex_files':
                    ex_files_releaseID_sil = ex_files_sil
                    logger.info('Using "ex_files" list for integration based on a releaseID as well (sil)')
                else:
                    logger.info('Using a separated list of exclude for integration based on a releaseID (sil)')
            else:
                logger.info('No list of exclude will be used for integration based on a releaseID (sil)')

            update_members_to_trunk_rev_sil = config.getlist('SIL', 'update_members_to_trunk_rev', [])
            #update_members_to_trunk_rev_sil[:] = [get_absolute_path(item) for item in update_members_to_trunk_rev_sil]
            update_subpj_to_trunk_rev_sil = config.getlist('SIL', 'update_subpj_to_trunk_rev', [])
            #update_subpj_to_trunk_rev_sil[:] = [get_absolute_path(item) for item in update_subpj_to_trunk_rev_sil]
            update_all_subpj_to_trunk_rev_sil = config.getboolean('SIL', 'update_all_subpj_to_trunk_rev')
        else:
            build_unit_sil = None


        ex_sections_files = config.get_ex_sections() #default='1.1'

        '''copy_output
        copy_output = []
        for option in config.options('OUTPUT_FOLDER'):
            opt = config.getlist('OUTPUT_FOLDER', option)
            if opt:
                input, output = (get_absolute_path(item) for item in opt)
                copy_output.append((input, output))
        '''
    except (ConfigParser.ParsingError, ConfigParser.MissingSectionHeaderError, ConfigParser.NoSectionError, ConfigParser.NoOptionError) as e:
        logger.exception('Exception occurred:')
        return False
    except (pickle.PicklingError, EOFError, IOError) as e:
        logger.exception('Exception occurred:')
        return False
    except ValueError as e:
        logger.exception('Exception occurred:')
        return False
        #sys.exit(1)
    finally:
        logger.info('End reading configurations!')

    '''Print some mandatory options from configuration file
    logger.info('Read from config file:')
    logger.info('hostname: %s', hostname)
    logger.info('portSI: %s', portSI)
    logger.info('portIM: %s', portIM)
    logger.info('user: %s', user)
    logger.info('password: %s', '********' if password else '')
    logger.info('base_project: %s', base_project)
    logger.info('family: %s', family)
    logger.info('project: %s', project)
    logger.info('devpath: %s', devpath)
    #logger.info('projectRevision: %s', projectRevision)
    logger.info('cpid: %s', cpid)
    logger.info('configure_mode: %s', configure_mode)
    logger.info('releaseID: %s', releaseID)
    logger.info('ci_description: %s', ci_description)
    logger.info('cp_description: %s', cp_description)
    logger.info('sandbox: %s', sandbox)
    #logger.info('Custom subprojects: %s', custom_subprojs)
    '''
    return True


def main():
    pass

if __name__ == '__main__':
    global kwargs

    head, tail = os.path.split(__file__)
    root, ext = os.path.splitext(tail)
    loggerName = root
    create_logger(loggerName + '.log', False)
    logger = logging.getLogger(loggerName)
    init_logging(loggerName)

    logger.debug('Start ' + __file__ + ' script')

    #main(sys.argv)
    #print sys.argv[0]
    '''TODO: Parse overwriting parameters
    parser = argparse.ArgumentParser()
    #parser.add_argument("echo", help="echo the string you use here")
    parser.add_argument("-v", "--verbose", help="increase output verbosity", action="store_true")
    args = parser.parse_args()
    #print args.echo
    if args.verbose:
        print "verbosity turned on"
    '''

    #Parsing parameters (sub-commands)
    parser = argparse.ArgumentParser()
    parser.add_argument('-p', '--project', dest='project', default=None, help='Project specific configuration to be used')
    parser.add_argument('--user', dest='user', default=None, help='Username to login to IMS server')
    parser.add_argument('--password', dest='password', default=None, help='Password to login to IMS server') #%env_var%
    parser.add_argument('--timeout_ims', dest='timeout_ims', default=None, help='Timeout for each command to IMS server (in seconds)')
    parser.add_argument('--timeout_cmd', dest='timeout_cmd', default=None, help='Timeout for each command run with CMD (in seconds)')
    #parser.add_argument('--timeout_iuc_release', dest='timeout_iuc_release', default=None, help='Timeout for build IuC release (in seconds)')
    #parser.add_argument('--timeout_iuc_debug', dest='timeout_iuc_debug', default=None, help='Timeout for build IuC debug (in seconds)')
    #parser.add_argument('--timeout_dpu', dest='timeout_dpu', default=None, help='Timeout for build DPU (in seconds)')
    #parser.add_argument('--timeout_sil', dest='timeout_sil', default=None, help='Timeout for build SIL (in seconds)')

    subparsers = parser.add_subparsers(dest='subcommand')
    
    parser_s10 = subparsers.add_parser('create_sandbox')
    parser_s10.add_argument('-d', '--drop', dest='drop', default=False, help='Drop the sandbox if exists', action="store_true")
    parser_s10.add_argument('-r', '--resync', dest='resync', default=False, help='Resync the sandbox if exists', action="store_true")

    parser_s0 = subparsers.add_parser('get_diff')
    parser_s0.add_argument('-s', '--subprojects', dest='only_subpj', default=False, help='Get diff only for subprojects', action="store_true")

    parser_s1 = subparsers.add_parser('configure_subprojects')
    parser_s1.add_argument('-f', '--force', dest='force', default=False, help='Force overwriting revisions file', action="store_true")
    parser_s1.add_argument('-r', '--recover', dest='recover', default=False, help='Recover using revisions file', action="store_true")
    parser_s1.add_argument('-i', '--iuc', dest='iuc', default=False, help='Reconfigure IuC (releaseID)', action="store_true")
    parser_s1.add_argument('-d', '--dpu', dest='dpu', default=False, help='Reconfigure DPU (releaseID)', action="store_true")
    parser_s1.add_argument('-s', '--sil', dest='sil', default=False, help='Reconfigure SIL (releaseID)', action="store_true")

    parser_s2 = subparsers.add_parser('project_resync')
    parser_s2.add_argument('-d', '--delnonmembers', dest='del_non_members', default=False, help='Delete non-members', action="store_true")
    parser_s2.add_argument('-r', '--resynclist', dest='resync_list', default=None, help='Only resync subsandboxes from the list')

    parser_s3 = subparsers.add_parser('update_sw_ver_no')
    parser_s3.add_argument('-f', '--family', dest='family', default=False, help='Update all Version Header Files from Project Family', action="store_true")
    parser_s3.add_argument('-i', '--iuc', dest='iuc', default=False, help='Update IuC Version Header Files', action="store_true")
    parser_s3.add_argument('-d', '--dpu', dest='dpu', default=False, help='Update DPU Version Header Files', action="store_true")
    parser_s3.add_argument('-s', '--sil', dest='sil', default=False, help='Update SIL Version Header Files', action="store_true")

    parser_s5 = subparsers.add_parser('build_project')
    parser_s5.add_argument('-i', '--iuc', dest='iuc', default=False, help='Build IuC', action="store_true")
    parser_s5.add_argument('-d', '--dpu', dest='dpu', default=False, help='Build DPU', action="store_true")
    parser_s5.add_argument('-s', '--sil', dest='sil', default=False, help='Build SIL', action="store_true")

    parser_s6 = subparsers.add_parser('flash_ECU')

    parser_s7 = subparsers.add_parser('trigger_BAT_test')

    parser_s8 = subparsers.add_parser('check_in_files')
    parser_s8.add_argument('-f', '--family', dest='family', default=False, help='Checkin all Version Header Files from Project Family', action="store_true")
    parser_s8.add_argument('-i', '--iuc', dest='iuc', default=False, help='Checkin files for IuC', action="store_true")
    parser_s8.add_argument('-d', '--dpu', dest='dpu', default=False, help='Checkin files for DPU', action="store_true")
    parser_s8.add_argument('-s', '--sil', dest='sil', default=False, help='Checkin files for SIL', action="store_true")

    parser_s9 = subparsers.add_parser('checkpoint_subprojects')
    parser_s9.add_argument('-l', '--label', dest='label', default=None, help='Label to be set used by checkpoint')
    parser_s9.add_argument('-b', '--broken', dest='broken', default=False, help='Set the label as broken (the build was unsuccessfully)', action="store_true")
    parser_s9.add_argument('-u', '--unstable', dest='unstable', default=False, help='Set the label as unstable (the BAT was unsuccessfully)', action="store_true")
    parser_s9.add_argument('-o', '--overall', dest='overall', default=False, help='Checkpoint Overall (only)', action="store_true")
    parser_s9.add_argument('-i', '--iuc', dest='iuc', default=False, help='Checkpoint IuC', action="store_true")
    parser_s9.add_argument('-d', '--dpu', dest='dpu', default=False, help='Checkpoint DPU', action="store_true")
    parser_s9.add_argument('-s', '--sil', dest='sil', default=False, help='Checkpoint SIL', action="store_true")

    try:
        #['configure_subprojects', '--force'], ['project_resync', '--delnonmembers'], ['update_sw_ver_no'], ['build_project'], ['check_in_files'], ['checkpoint_subprojects']
        #['--project=MFC431', 'sub_command', '--param'] ([get_diff])
        kwargs = vars(parser.parse_args())
    except Exception as e:
        logger.exception('Exception occcured in parser.parse_args: %s', e.message)
        #print 'Exception occcured in parser.parse_args: %s' % (e.message)
        sys.exit(1)
    '''SystemExit
    except SystemExit as e:
        logger.debug('Exit code: %s', e.code)
        #print 'Exit code: %s' % e.code
        sys.exit(1)
    '''

    #TODO: Remove file_timestamp file if configure_subprojects subcommands is run
    if kwargs['subcommand'] == 'configure_subprojects':
        first_subcommand = True
    else:
        first_subcommand = False

    config_name = 'generic.ini'
    #create_config(config_name)
    config_files = [config_name]
    

    proj = kwargs.pop('project')
    if proj:
        specific_config_path = os.path.join(os.getcwd(), os.pardir, '00_Projects', proj, 'AIS')
        project_config = os.path.join(specific_config_path, 'specific.ini')
        user_config = os.path.join(specific_config_path, 'user_specific.ini')
        config_files.extend([project_config, user_config])

    if not read_config(config_files, first_subcommand):
        sys.exit(1)


    localIntegrationPoint = True

    p = kwargs.pop('password')
    u = kwargs.pop('user')
    if u: # we can have only the user specified, but not only the password
        user = u
        if p:
           #if both user and password were submitted we can bypass the local client and use the remote server directly
           #localIntegrationPoint = False
           password = p

    timeout = num(float, kwargs.pop('timeout_ims'))
    if timeout:
        timeout_ims = timeout
    timeout = num(float, kwargs.pop('timeout_cmd'))
    if timeout:
        timeout_cmd = timeout

    '''unused timeouts
    timeout = num(float, kwargs.pop('timeout_iuc_release'))
    if timeout:
        timeout_iuc_release = timeout
    timeout = num(float, kwargs.pop('timeout_iuc_debug'))
    if timeout:
        timeout_iuc_debug = timeout
    timeout = num(float, kwargs.pop('timeout_dpu'))
    if timeout:
        timeout_dpu = timeout
    timeout = num(float, kwargs.pop('timeout_sil'))
    if timeout:
        timeout_sil = timeout
    '''

    #ims = IMS(hostname='ims-adas', portSI=7001, portIM=7002, localIntegrationPoint=True)
    #None value for user and password is handled in the IMS class
    ims = IMS(hostname, portSI, portIM, no_retries=no_retries, timeout=timeout_ims, localIntegrationPoint=localIntegrationPoint, user=user, password=password) #, version=APIVersion.API_4_16

    #TODO: Only connect to IMS server if the command requires it.
    try:
        resp = ims.connect_source()
        #print 'resp.exit_code:', resp.exit_code
        #print 'resp.result: ', resp.result.message
    #TODO: To be moved in IMS class
    except CommandError as e:
        logger.exception('Exception occurred:')
        sys.exit(1)
    except APIException as e:
        logger.exception('Exception occurred:\n\t%s', e.message) # connection canceled (refused)
        sys.exit(1)
    except TimeoutError as e:
        logger.exception('Exception occurred:')
        sys.exit(1)
    except Exception as e:
        logger.exception('Exception occurred:\n\t%s', e.message)
        sys.exit(1)


    logger.debug('Provided arguments: %s', kwargs)
    try:
        globals()[kwargs.pop('subcommand')](**kwargs)
    except KeyboardInterrupt as e:
        logger.exception('Exception occurred: User pressed CTRL-C!')
    #except:
    #    sys.exit(1)


    '''Step by step execution...
    #configure_subprojects(force=True)  #Step 1
    project_resync(del_non_members=True)#Step 2
    update_sw_ver_no()                  #Step 3
    lock_files()                        #Step 4
    build_project()                     #Step 5
    flash_ECU()                         #Step 6
    trigger_BAT_test()                  #Step 7
    check_in_files()                    #Step 8
    checkpoint_subprojects()            #Step 9
    '''

    '''disconnect from the server
    try:
        resp = ims.disconnect_source()
        print 'resp.result:', resp.result.message
        print 'resp.exit_code:', resp.exit_code
    #TODO: To be moved in IMS class
    except CommandError as e:
        logger.exception('Exception occurred:')
    except Exception as e:
        logger.exception('Exception occurred:\n\t%s', e.message)
    '''

    logger.debug('End ' + __file__ + ' script')
