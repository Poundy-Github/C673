import sys
import copy
import math
import time
import logging
from argparse import ArgumentParser, ArgumentDefaultsHelpFormatter
from ims import IMS, Response, Item, ShareType, APIException, ChangePackageState

logger = logging.getLogger()
logging.basicConfig(level=logging.DEBUG, format="%(asctime)s [%(levelname)s]: [%(module)s][%(funcName)s] %(message)s", datefmt="%d/%m/%Y %H:%M:%S")

BUILD_UNITS = ['APPL', 'DPU', 'M11_APPL', 'MTS']

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

def connect_ims(hostname, source, integrity, user, password):
    ims = IMS(hostname=hostname, portSI=source, portIM=integrity, no_retries=3, user=user, password=password)
    ims.connect_source()
    ims.connect_integrity()
    return ims

def get_build_units(ims, project_path, build_units=None, devpath=None):
    if build_units:
        logger.info('Build unit(s) specified, use it/them (%s)!', ', '.join(build_units))
        for i, build_unit in enumerate(build_units):
            build_units[i] = build_unit + '/project.pj'
        return build_units
    else:
        logger.info('No build unit specified, try to detect all build units!')
    build_units = []
    project_pj = len('/project.pj')
    resp = ims.viewproject(batch=None, norecurse=None, project=project_path, filter='!file:*')  # devpath=devpath,
    for wi in resp.work_items:
        # wi.getField('name').value
        idx = len(project_path) - project_pj + 1
        build_unit = wi.display_id[idx:]
        if build_unit[:-project_pj].upper() in BUILD_UNITS:
            build_units.append(build_unit)  # wi.display_id
    logger.info('Build units detected: %s!', ', '.join([build_unit[:-project_pj] for build_unit in build_units]))
    return build_units

def get_subprojects(ims, project_path, devpath, build_units=None):
    subpjs = {}
    for build_unit in build_units:
        exception_list = []
        build_unit_subpjs = []
        resp = ims.viewproject(build_unit, batch=None, recurse=None, project=project_path, devpath=devpath, filter='!file:*')

        # TODO: Skip the buildunit itself. Better only skip in case its SHARED_VARIANT_SUBPROJECT
        for wi in resp.work_items[1:]:
            # if wi.model_type == Item.SI_SUBPROJECT:
            # if wi.display_id.endswith('/project.pj'):
            #     wi.display_id
            # Ignore the children of a subprojects of type ShareType.SHARED_VARIANT_SUBPROJECT or ShareType.SHARED_BUILD_SUBPROJECT
            # 04_Engineering/01_Source_Code/GIA_sim
            # TODO: Check if the subproject is in pending state, because this will impacts both source and target branch
            # Mainly for target branch when parent or child subproject is going to be reconfigured,
            # but also for source branch when that subproject is the one that needs to be recongired on target branch!
            if wi.parent_id.upper() not in exception_list:
                typ = wi.getField('type').value
                if typ == ShareType.PENDING_CONFIGURE_SUBPROJECT:
                    # TODO: Create a file containing the subprojects in pending state (for both source and target branch)!
                    # r = ims.viewproject(batch=None, norecurse=None, project=wi.parent_id, fields='state,cpid,pendingcpid', filter='!file:*')
                    logger.error('{} is in pending state!'.format(wi.id))
                    exception_list.append(wi.id.upper())
                elif typ == ShareType.SHARED_VARIANT_SUBPROJECT:
                    build_unit_subpjs.append(wi)  # '{}\t{}'.format(wi.id, typ)
                    exception_list.append(wi.id.upper())
                elif typ == ShareType.SHARED_BUILD_SUBPROJECT:
                    build_unit_subpjs.append(wi)  # '{}\t{}'.format(wi.id, typ)
                    exception_list.append(wi.id.upper())
            else:
                exception_list.append(wi.id.upper())
        subpjs[build_unit] = build_unit_subpjs
    return subpjs

def get_members(ims, project_path, devpath, update_members_rev):
    members = []
    for update_member in update_members_rev:
        member = update_member.split('/')[-1]
        idx = project_path.rfind('/') + 1
        project = project_path[:idx] + update_member[:-len(member)] + project_path[idx:]
        resp = ims.memberinfo(member, batch=None, project=project, devpath=devpath)
        wi = resp.work_items[0]
        members.append((wi, devpath))
    return members

def get_revisions(ims, source_subpjs, target_subpjs, build_units):
    configure_subpjs = {}
    dropped_subpjs = []
    missing_subpjs = []
    for build_unit in build_units:
        configure_build_unit_subpjs = []
        logger.debug('Build unit: {}'.format(build_unit))
        src_subprojs = [item.display_id.upper() for item in source_subpjs[build_unit]]
        tgt_subprojs = [item.display_id.upper() for item in target_subpjs[build_unit]]

        for src_index, src_subproj in enumerate(src_subprojs):
            src_subpj = source_subpjs[build_unit][src_index]
            try:
                tgt_index = tgt_subprojs.index(src_subproj)
                tgt_subpj = target_subpjs[build_unit][tgt_index]

                src_rev_field = src_subpj.getField('memberrev')
                tgt_rev_field = tgt_subpj.getField('memberrev')

                if src_rev_field and tgt_rev_field:
                    src_rev = src_rev_field.item.id
                    tgt_rev = tgt_rev_field.item.id
                    if src_rev != tgt_rev:
                        logger.debug('{} was found in both branches with different revisions - to be set to source revision ({} != {})!'.format(src_subpj.display_id, src_rev, tgt_rev))
                        configure_build_unit_subpjs.append((tgt_subpj, src_rev, tgt_rev))
                    else:
                        logger.debug('{} was found in both branches with same revisions ({} == {})!'.format(src_subpj.display_id, src_rev, tgt_rev))
                        pass
                elif src_rev_field:
                    src_rev = src_rev_field.item.id
                    logger.debug('{} was found in target branch configured as normal/variant - to be set to source revision {}!'.format(src_subpj.display_id, src_rev))
                    configure_build_unit_subpjs.append((tgt_subpj, src_rev, 'variant'))
                elif tgt_rev_field:
                    resp = ims.projectinfo(batch=None, project=src_subpj.id)
                    src_rev = resp.work_items[0].getField('revision').item.id
                    logger.debug('{} was found in source branch configured as normal/variant - to be set as latest source revision {}!'.format(src_subpj.display_id, src_rev))
                    if tgt_rev_field.item.id == src_rev:
                        logger.debug('Latest source revision is the same as target revision ({})'.format(src_rev))
                    else:
                        configure_build_unit_subpjs.append((tgt_subpj, src_rev, 'head'))
            except ValueError:
                logger.info('{} was NOT found in target branch!'.format(src_subpj.display_id))
                missing_subpjs.append(src_subpj.id)

        for tgt_index, tgt_subproj in enumerate(tgt_subprojs):
            tgt_subpj = target_subpjs[build_unit][tgt_index]
            try:
                src_index = src_subprojs.index(tgt_subproj)
            except ValueError:
                logger.info('{} was NOT found in source branch!'.format(tgt_subpj.display_id))
                dropped_subpjs.append(tgt_subpj.id)

        configure_subpjs[build_unit] = configure_build_unit_subpjs
    return configure_subpjs, dropped_subpjs, missing_subpjs

def get_members_revs(ims, source_members, target_members):
    configure_members = []
    dropped_members = []
    missing_members = []

    for source_wi, _ in source_members:
        source_project = source_wi.context
        source_member = source_wi.display_id
        source_member_path = source_project.replace("project.pj", source_member)
        for target_wi, target_devpath in target_members:
            target_project = target_wi.context
            target_member = target_wi.display_id
            target_member_path = target_project.replace("project.pj", target_member)
            if source_member_path == target_member_path:
                source_member_rev = source_wi.getField('memberrevision').value
                target_member_rev = target_wi.getField('memberrevision').value
                if source_member_rev != target_member_rev:
                    logger.debug("%s was found in both branches with different revisions - to be set to source revision (%s != %s)!", source_member_path, source_member_rev, target_member_rev)
                    configure_members.append((target_member_path, source_member_rev, target_member_rev, target_devpath))
                else:
                    logger.debug("'%s was found in both branches with same revisions (%s == %s)!", source_member_path, source_member_rev, target_member_rev)
                    pass
                break
        else:
            logger.info("%s was NOT found in target branch!", source_member_path)
            missing_members.append(source_member_path)

    for target_wi, _ in target_members:
        target_member_path = target_wi.context.replace("project.pj", target_wi.display_id)
        for source_wi, _ in source_members:
            source_member_path = source_wi.context.replace("project.pj", source_wi.display_id)
            if source_member_path == target_member_path:
                break
        else:
            logger.info("%s was NOT found in source branch!", target_member_path)
            dropped_members.append(target_member_path)

    return configure_members, dropped_members, missing_members

def create_reports(configure_subpjs, dropped_subpjs, missing_subpjs, build_units):
    date = time.gmtime()
    s = '{:4d}{:02d}{:02d}_{:02d}{:02d}{:02d}'.format(date.tm_year, date.tm_mon, date.tm_mday, date.tm_hour, date.tm_min, date.tm_sec)
    configured = 'subprojects_to_be_configured_{}.txt'.format(s)
    dropped = 'subprojects_to_be_dropped_{}.txt'.format(s)
    missing = 'subprojects_to_be_added_{}.txt'.format(s)

    with open(configured, 'w') as f:
        for build_unit in build_units:
            for subpj, crt_rev, old_rev in configure_subpjs[build_unit]:
                f.write('{}\t{}\t{}\n'.format(subpj.id, crt_rev, old_rev))

    with open(dropped, 'w') as f:
        for subpj in dropped_subpjs:
            f.write('{}\n'.format(subpj))

    with open(missing, 'w') as f:
        for subpj in missing_subpjs:
            f.write('{}\n'.format(subpj))

def create_members_reports(configure_members, dropped_members, missing_members):
    date = time.gmtime()
    s = '{:4d}{:02d}{:02d}_{:02d}{:02d}{:02d}'.format(date.tm_year, date.tm_mon, date.tm_mday, date.tm_hour, date.tm_min, date.tm_sec)
    configured = 'members_to_be_configured_{}.txt'.format(s)
    dropped = 'members_to_be_dropped_{}.txt'.format(s)
    missing = 'members_to_be_added_{}.txt'.format(s)

    with open(configured, 'w') as f:
        for member, crt_rev, old_rev, devpath in configure_members:
            f.write('{}\t{}\t{}\t{}\n'.format(member, crt_rev, old_rev, devpath))

    with open(dropped, 'w') as f:
        for member in dropped_members:
            f.write('{}\n'.format(member))

    with open(missing, 'w') as f:
        for member in missing_members:
            f.write('{}\n'.format(member))

def create_cp(ims, ro, summary):
    try:
        resp = ims.createcp(batch=None, issueId=ro, summary=summary, description='Automatically created change package')
        cpid = resp.result.primary_value.item.id
        return cpid
    except APIException as e:
        message = get_exception_message(e)
        logger.exception('Exception occurred: %s', message)
        sys.exit(10)

def submitted_cp(ims, cpid):
    resp = ims.viewcp(cpid)
    if resp.work_items[0].getField('state').value == ChangePackageState.SUBMITTED:
        return True
    else:
        return False

def close_cp(ims, cpid):
    no_retries = 2
    retries = 2
    while True:
        exc_info = None
        # review_needed = pending_entries_cp(cpid)
        resp = ims.submitcp(cpid, batch=None, closeCP=None) #, nocloseCP=None, confirmcommit=None
        #review_needed = not closed_cp(cpid)
        review_needed = submitted_cp(ims, cpid)
        if review_needed:
            try:
                resp = ims.acceptcp(cpid, batch=None, comments='Automatically accepted change package by configure_branch', reviewer='group:__MainstreamReviewer') #, forceconfirm=None, yes=None | super, all
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

def set_revisions(ims, project_path, configure_subpjs, ro, no_cp_entries, build_units, dry_run):
    project = project_path.split('/')[-2]
    for build_unit in build_units:
        configure_build_unit_subpjs = configure_subpjs[build_unit]
        max_cp = int(math.ceil(len(configure_build_unit_subpjs)/float(no_cp_entries)))
        indexes = [(i, i+no_cp_entries) for i in range(0, len(configure_build_unit_subpjs), no_cp_entries)]
        for i, j in indexes:
            configure_subpjs_cp = configure_build_unit_subpjs[i:j]
            summary = '[configure_branch][{}] {} ({}/{})'.format(project, build_unit, j/no_cp_entries, max_cp)
            logger.info('Create change package: {}'.format(summary))
            if not dry_run:
                cpid = create_cp(ims, ro, summary)
            for subpj, rev, _ in configure_subpjs_cp:
                logger.info('Configure: "{}" to revision "{}"'.format(subpj.id, rev))
                if not dry_run:
                    resp = ims.configuresubproject(subpj.display_id, batch=None, cpid=cpid, type='build', subprojectRevision=rev, project=subpj.parent_id)
            if not dry_run:
                close_cp(ims, cpid)

def set_members_revs(ims, project_path, configure_members, ro, dry_run):
    project = project_path.split('/')[-2]
    summary = '[configure_branch][{}] Update members revisions'.format(project)
    logger.info('Create change package: {}'.format(summary))
    if not dry_run:
        cpid = create_cp(ims, ro, summary)
    for memb, new_rev, crt_rev, devpath in configure_members:
        logger.info('Configure "%s" from rev. "%s" to rev. "%s" on devpath "%s"', memb, crt_rev, new_rev, devpath)
        member = memb.split('/')[-1]
        idx = memb.rfind('/')
        proj = '{}/project.pj'.format(memb[:idx])
        if not dry_run:
            resp = ims.updaterevision(member, batch=None, cpid=cpid, nocloseCP=None, revision=new_rev, project=proj, devpath=devpath)
    if not dry_run:
        close_cp(ims, cpid)

def configure_branch(arguments):
    ims = connect_ims(arguments.hostname, arguments.source, arguments.integrity, arguments.user, arguments.password)

    project_path = arguments.project_path
    source_devpath = arguments.source_devpath
    target_devpath = arguments.target_devpath
    update_members_rev = arguments.update_members_rev

    build_units = get_build_units(ims, project_path, arguments.build_units)
    source_subpjs = get_subprojects(ims, project_path, source_devpath, build_units=build_units)
    target_subpjs = get_subprojects(ims, project_path, target_devpath, build_units=build_units)

    configure_subpjs, dropped_subpjs, missing_subpjs = get_revisions(ims, source_subpjs, target_subpjs, build_units)
    create_reports(configure_subpjs, dropped_subpjs, missing_subpjs, build_units)
    set_revisions(ims, project_path, configure_subpjs, arguments.ro, arguments.no_cp_entries, build_units, arguments.dry_run)

    if update_members_rev:
        source_members = get_members(ims, project_path, source_devpath, update_members_rev)
        target_members = get_members(ims, project_path, target_devpath, update_members_rev)

        configure_members, dropped_members, missing_members = get_members_revs(ims, source_members, target_members)
        create_members_reports(configure_members, dropped_members, missing_members)
        set_members_revs(ims, project_path, configure_members, arguments.ro, arguments.dry_run)
    else:
        logger.info('No member revision specified to be updated!')

def parse_arguments(argv):
    logger.info('Parsing the arguments...')
    parser = ArgumentParser(description='Configure a branch based on another branch', formatter_class=ArgumentDefaultsHelpFormatter)

    parser.add_argument('-p', '--prj_path', dest='project_path', help='IMS project flat path', default=None, required=True)
    parser.add_argument('-s', '--src_dp', dest='source_devpath', help='Source devpath', default=None, required=True)
    parser.add_argument('-t', '--tgt_dp', dest='target_devpath', help='Target devpath', default=None, required=True)
    parser.add_argument('-r', '--ro', dest='ro', help='IMS Realization Order', default=None, required=True)
    parser.add_argument('-d', '--dry_run', dest='dry_run', help='Dry run', default=False, action="store_true")
    parser.add_argument('-n', '--no_cp_entries', dest='no_cp_entries', help='Number of change packages entries', default=20, type=int)
    parser.add_argument('-a', '--hostname', dest='hostname', help='IMS server', default='ims-adas')
    parser.add_argument('-o', '--source_port', dest='source', help='IMS source port', default='7001')
    parser.add_argument('-i', '--integrity_port', dest='integrity', help='IMS integrity port', default='7002')
    parser.add_argument('-u', '--user', dest='user', help='IMS user', default=None)
    parser.add_argument('-w', '--password', dest='password', help='IMS password', default=None)
    parser.add_argument('-b', '--build_units', dest='build_units', help='Project build unit(s) to be configured', default=None, nargs='*')
    parser.add_argument('-m', '--update_members_rev', dest='update_members_rev', help='Update revision for members', default=None, nargs='*')

    arguments = parser.parse_args(argv)
    args = copy.deepcopy(vars(arguments))
    if args['password']:
        args.update(password='********')
    logger.debug('Command line parameters: %s', args)
    return arguments

def main(argv):
    logger.debug('START')

    arguments = parse_arguments(argv)
    configure_branch(arguments)

    logger.debug('END')


if __name__ == "__main__":
    main(sys.argv[1:])
