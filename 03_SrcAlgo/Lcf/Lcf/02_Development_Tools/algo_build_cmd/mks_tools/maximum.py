# -*- coding: latin1 -*-
import os
import re
import subprocess
from CLI_tools import cli_proc_handler
import ctypes
import urllib
import argparse
import pprint
import datetime
import Tkinter, tkFileDialog
import xml.etree.ElementTree as et

show_debug = False


# copied from http://coffeeghost.net/src/pyperclip.py
def winSetClipboard(text):
    GMEM_DDESHARE = 0x2000
    ctypes.windll.user32.OpenClipboard(0)
    ctypes.windll.user32.EmptyClipboard()
    try:
        # works on Python 2 (bytes() only takes one argument)
        hCd = ctypes.windll.kernel32.GlobalAlloc(GMEM_DDESHARE, len(bytes(text)) + 1)
    except TypeError:
        # works on Python 3 (bytes() requires an encoding)
        hCd = ctypes.windll.kernel32.GlobalAlloc(GMEM_DDESHARE, len(bytes(text, 'ascii')) + 1)
    pchData = ctypes.windll.kernel32.GlobalLock(hCd)
    try:
        # works on Python 2 (bytes() only takes one argument)
        ctypes.cdll.msvcrt.strcpy(ctypes.c_char_p(pchData), bytes(text))
    except TypeError:
        # works on Python 3 (bytes() requires an encoding)
        ctypes.cdll.msvcrt.strcpy(ctypes.c_char_p(pchData), bytes(text, 'ascii'))
    ctypes.windll.kernel32.GlobalUnlock(hCd)
    ctypes.windll.user32.SetClipboardData(1, hCd)
    ctypes.windll.user32.CloseClipboard()


# copied from http://coffeeghost.net/src/pyperclip.py
def winGetClipboard():
    CF_UNICODETEXT = 13
    d = ctypes.windll
    d.user32.OpenClipboard(None)
    handle = d.user32.GetClipboardData(CF_UNICODETEXT)
    data = ctypes.c_wchar_p(handle).value
    d.user32.CloseClipboard()
    return data


def getWindow():
    if os.environ.has_key('MKSSI_WINDOW'):
        return os.environ['MKSSI_WINDOW']
    else:
        return ''


def getProjectInfoFromSandbox(s):
    project = {}
    # enter sandbox path
    project['sandbox'] = {'path': s}

    # call si client
    si_out = subprocess.check_output(['si', 'projectinfo', '--sandbox=' + s])

    # fetch project path
    match_project_path = re.search(r'Shared\sFrom\:\s+([^\s]+)', si_out)
    if match_project_path:
        project['path'] = match_project_path.group(1)
    else:
        match_project_path = re.search(r'Project\sName\:\s+([^\s]+)', si_out)
        if match_project_path:
            project['path'] = match_project_path.group(1)
        else:
            print "ERROR: project path not found in si output"
            print si_out
            exit(1)

    # fetch kind of project
    match_kind = re.search(r'Build\sProject\sName\:', si_out)
    if match_kind:
        project['kind'] = 'build';
    else:
        match_kind = re.search(r'Variant\sProject\sName\:', si_out)
        if match_kind:
            project['kind'] = 'variant';
        else:
            project['kind'] = 'normal';

    if re.match(r'build', project['kind']):
        # fetch revision
        match_revision = re.search(r'Revision\:\s+([^\s]+)', si_out)
        if match_revision:
            project['revision'] = match_revision.group(1)
    elif re.match(r'variant', project['kind']):
        # fetch devpath
        match_dev_path = re.search(r'Development\sPath\:\s+([^\s]+)', si_out)
        if match_dev_path:
            project['devpath'] = match_dev_path.group(1)

    return project


def getProjectInfoFromProject(parent_pj, sub_pj, build, variant):
    project = {}
    # build call to si
    host = ""
    port = ""
    if os.environ.has_key('MKSSI_HOST'):
        host = os.environ['MKSSI_HOST']
    if os.environ.has_key('MKSSI_PORT'):
        port = os.environ['MKSSI_PORT']

    # ask parent project about the subproject
    si_args = ['si', 'viewproject', '--forceConfirm=no', '--project=' + parent_pj]
    if host:
        si_args.append('--hostname=' + host)
    if port:
        si_args.append('--port=' + port)
    if build:
        si_args.append('--projectRevision=' + build)
    elif variant:
        si_args.append('--devpath=' + variant)
    si_args.append(sub_pj)

    if show_debug:
        print "getProjectInfos: si arguments"
        print si_args

    # call si client
    si_out = subprocess.check_output(si_args)

    if show_debug:
        print "getProjectInfos: si output"
        print si_out

    # parse output
    match_viewproject = re.search(r'\s*[^\s]+\s+(\((?P<label_content>[^\)]+)\)\s+)?(?P<kind>.*)-?subproject', si_out)

    if show_debug:
        if match_viewproject:
            print "getProjectInfos: match_viewproject"
            if match_viewproject.group('kind'):
                print "  kind:  " + match_viewproject.group('kind')
            if match_viewproject.group('label_content'):
                print "  label: " + match_viewproject.group('label_content')
        else:
            print "Parsing of si output failed"

    if match_viewproject:
        if re.match(r'.*build', match_viewproject.group('kind')):
            project['kind'] = 'build'
            project['revision'] = match_viewproject.group('label_content')
        elif re.match(r'.*variant', match_viewproject.group('kind')):
            project['kind'] = 'variant'
            project['devpath'] = match_viewproject.group('label_content')
        else:
            project['kind'] = 'normal'

        if re.match(r'shared.*', match_viewproject.group('kind')):
            # this is a shared project, the real project path has to be retrieved
            # separately by a call to projectinfo

            si_args = ['si', 'projectinfo', '--project=' + sub_pj]
            if host:
                si_args.append('--hostname=' + host)
            if port:
                si_args.append('--port=' + port)

            if show_debug:
                print "getProjectInfos (shared subproject): si arguments"
                print si_args

            si_out = subprocess.check_output(si_args)

            if show_debug:
                print "getProjectInfos (shared subproject): si output"
                print si_out

            # extract real project path
            match_projectinfo = re.search(r'Shared\sFrom\:\s+([^\s]+)', si_out)
            if match_projectinfo:
                project['path'] = match_projectinfo.group(1)
            else:
                print "ERROR: project path not found in si output"
                print si_out
        else:
            # standard project, directly take the path of the project from the environment
            project['path'] = sub_pj
    return project


def getConnectionArgumentListIM():
    # builds the array of MKS connection setting arguments for IM based on environment
    connectionArgs = []
    if os.environ.has_key('MKSIM_HOST'):
        connectionArgs.append('--hostname=' + os.environ['MKSIM_HOST'])
    if os.environ.has_key('MKSIM_PORT'):
        connectionArgs.append('--port=' + os.environ['MKSIM_PORT'])
    if os.environ.has_key('MKSIM_USER'):
        connectionArgs.append('--user=' + os.environ['MKSIM_PORT'])
    return connectionArgs


def viewQcTicket(qcTicketId):
    # connection arguments
    connectionArgs = getConnectionArgumentListIM()

    # search for corresponding IMS ticket
    queryDefinition = '--queryDefinition=(field["Collaboration Partner ID"] contains "%s")' % qcTicketId
    cmd = ['im', 'issues', queryDefinition, '--fields=ID'];
    cmd = cmd + connectionArgs
    si_out = subprocess.check_output(cmd)

    # it is currently unknown whether there can be multiple IMS issues with the same collaboration partner ID
    # the following code assumes there is only one
    imsId = si_out.strip()

    # open IMS ticket
    cmd = ['im', 'viewissue', '-g', imsId];
    cmd = cmd + connectionArgs
    subprocess.check_output(cmd)


def getAllLinks(path):
    links = []

    cliProcHandler = cli_proc_handler()

    if os.path.isdir(path):
        cmd = (['cmd', '/c', 'dir', '/al', '/s', '/b'], path)
        cliProcHandler.SiCLIHandler_wait(cmd)
    return cliProcHandler.getstdout_split()


def dropSandbox():
    # collect sandboxes
    idx = 1
    sandboxes = []
    while os.environ.has_key("MKSSI_PROJECT%s_SANDBOX" % (str(idx))):
        sandboxes.append(os.environ["MKSSI_PROJECT%s_SANDBOX" % (str(idx))])
        idx += 1

    for sandbox in sandboxes:
        reallyDrop = raw_input('Do you really want to drop %s [y/n] ' % (sandbox))

        if reallyDrop.lower() == 'y':
            if not os.path.exists(sandbox):
                print 'Error: Sandbox does not exist\n' + sandbox
                return

            # before dropping sandbox, take care of all symlinked folders
            for link in getAllLinks(os.path.dirname(sandbox)):
                os.rmdir(link)

            si_cmd = ['si', 'dropsandbox', '--hostname=ims-adas', '--port=7001', '-Y', '--delete=all', sandbox]

            subprocess.check_output(si_cmd)


def getIssueInfos():
    items = []

    cmd = ['im', 'viewissue']

    if os.environ.has_key('MKSSI_HOST'):
        cmd.append('--hostname=' + os.environ['MKSSI_HOST'])
    if os.environ.has_key('MKSSI_PORT'):
        cmd.append('--port=' + os.environ['MKSSI_PORT'])

    # get issue items
    if os.environ.has_key('MKSSI_NISSUE'):
        issues_count = int(os.environ['MKSSI_NISSUE'])

        for i in range(0, issues_count):
            current_key = "MKSSI_ISSUE%d" % i

            if (os.environ.has_key(current_key)):
                item = {}
                item['issue'] = {'id': os.environ[current_key]}

                # get more info from the server
                im_out = subprocess.check_output(cmd + [item['issue']['id']])
                if show_debug:
                    print im_out

                m = re.search(r'^Type:\s(.*)$', im_out, re.MULTILINE)
                if m:
                    item['issue']['type'] = m.group(1)

                m = re.search(r'^Summary:\s(.*)$', im_out, re.MULTILINE)
                if m:
                    item['issue']['summary'] = m.group(1)

                m = re.search(r'^State:\s(.*)$', im_out, re.MULTILINE)
                if m:
                    item['issue']['state'] = m.group(1)

                m = re.search(r'^Structure\sElement:\s(.*)$', im_out, re.MULTILINE)
                if m:
                    item['issue']['structure_element'] = m.group(1)

                m = re.search(r'^Ordered\sby:\s(\d*)$', im_out, re.MULTILINE)
                if m:
                    item['issue']['ordered_by'] = m.group(1)

                m = re.search(r'^Assigned\sUser:\s(.*)$', im_out, re.MULTILINE)
                if m:
                    item['issue']['assigned_user'] = m.group(1)

                m = re.search(r'^Planned\sRelease:\s([^,]*).*$', im_out, re.MULTILINE)
                if m:
                    item['issue']['planned_release'] = m.group(1)

                items.append(item)

    return items


def getVariantOfROChanges(item):
    cmd = ['si', 'viewcp', '--fields=variant, id', '--noshowPropagationInfo']

    if item['issue']['type'] == 'Realization Order':
        cmd.append(item['issue']['id'])

    # execute command
    if show_debug:
        print " ".join(cmd)
    si_out = subprocess.check_output(cmd)

    if show_debug:
        print si_out

    # parse for development path
    variants = {}
    for line in si_out.splitlines():

        match = re.search(r'^(.+)\s+[\d]+\:[\d]$', line)
        if match:
            variant = match.group(1)

            if not variants.has_key(variant):
                variants[variant] = 0

            variants[variant] += 1

    if show_debug:
        for variant in variants.keys():
            print 'variant: ' + variant + ', ' + str(variants[variant]) + ' times'

    return variants


def copyToMergeRO(items):
    cmd = ['im', 'copyissue', '--copyFields', '--type=Realization Order', '-g']

    if os.environ.has_key('MKSSI_HOST'):
        cmd.append('--hostname=' + os.environ['MKSSI_HOST'])
    if os.environ.has_key('MKSSI_PORT'):
        cmd.append('--port=' + os.environ['MKSSI_PORT'])

    # work on all realization orders
    for i in items:
        if i.has_key('issue'):
            if i['issue']['type'] == 'Realization Order':
                # create additional options for the command
                cmd_add = []

                # copy ordered by field if existing
                if i['issue'].has_key('ordered_by'):
                    cmd_add.append('--addRelationships=Ordered by:' + i['issue']['ordered_by'])

                # modify summary
                # fetch variants worked on
                originalVariants = getVariantOfROChanges(i)
                # fetch original summary
                if i['issue'].has_key('summary'):
                    originalSummary = i['issue']['summary']
                else:
                    originalSummary = ''
                # fetch original id  
                originalId = i['issue']['id']

                # change summary to summary (Source: RO-ID, RO-Branch)
                summary = "%s (Merged from %s, %s)" % (originalSummary, originalId, ', '.join(originalVariants.keys()))

                # exchange evil umlauts in summary
                summary = re.sub('\x84', r'ae', summary)
                summary = re.sub('\x8e', r'AE', summary)
                summary = re.sub('\x94', r'ue', summary)
                summary = re.sub('\x99', r'UE', summary)
                summary = re.sub('\x9A', r'OE', summary)
                summary = re.sub('\x94', r'oe', summary)

                # create command
                cmd_add.append('--field=Summary=' + summary)

                # finaly the id
                cmd_add.append(i['issue']['id'])

                # execute command
                if show_debug:
                    print " ".join(cmd + cmd_add)
                subprocess.check_output(cmd + cmd_add)


def projectChangeQuery():
    # check precondition
    isValidProjectHistorySelection = (getWindow() == 'projecthistory') \
                                     and (os.environ.has_key('MKSSI_FILE')) \
                                     and (os.environ.has_key('MKSSI_REVISION1')) \
                                     and (os.environ.has_key('MKSSI_REVISION2')) \
                                     and (not os.environ.has_key('MKSSI_REVISION3'))

    isValidSandboxRootSelection = (getWindow() == 'sandbox') \
                                  and (os.environ.has_key('MKSSI_FILE')) \
                                  and (os.environ.has_key('MKSSI_NSUBPROJECT')) \
                                  and (int(os.environ['MKSSI_NSUBPROJECT']) == 0)

    isValidSandboxSubprojectSelection = (getWindow() == 'sandbox') \
                                        and (os.environ.has_key('MKSSI_NSUBPROJECT')) \
                                        and (int(os.environ['MKSSI_NSUBPROJECT']) > 0)

    if not (isValidProjectHistorySelection or isValidSandboxRootSelection or isValidSandboxSubprojectSelection):
        print 'ERROR: You have not done a valid selection. You must select two revisions in the history or a sandbox folder.'
        return

    if show_debug:
        print 'isValidProjectHistorySelection   ', isValidProjectHistorySelection
        print 'isValidSandboxRootSelection      ', isValidSandboxRootSelection
        print 'isValidSandboxSubprojectSelection', isValidSandboxSubprojectSelection

    # create command to fetch the changes
    si_cmd = ['si', 'mods', '-R', '--showChangePackages']

    if os.environ.has_key('MKSSI_HOST'):
        si_cmd.append('--hostname=' + os.environ['MKSSI_HOST'])
    if os.environ.has_key('MKSSI_PORT'):
        si_cmd.append('--port=' + os.environ['MKSSI_PORT'])

    sandboxes = []

    if isValidSandboxSubprojectSelection:
        for i in range(1, int(os.environ['MKSSI_NSUBPROJECT']) + 1):
            sbxPath = 'MKSSI_SUBPROJECT' + str(i) + '_SANDBOX'
            sandboxes.append(os.environ[sbxPath])
            if show_debug:
                print os.environ[sbxPath]
    elif isValidSandboxRootSelection:
        sandboxes.append(os.environ['MKSSI_FILE'])
    elif isValidProjectHistorySelection:
        si_cmd.append('--project=' + os.environ['MKSSI_FILE'])

        cp1time = getTimeOfCheckpoint(os.environ['MKSSI_FILE'], os.environ['MKSSI_REVISION1'])
        cp2time = getTimeOfCheckpoint(os.environ['MKSSI_FILE'], os.environ['MKSSI_REVISION2'])

        if cp1time < cp2time:
            si_cmd.extend(['-r', os.environ['MKSSI_REVISION1'], '-r', os.environ['MKSSI_REVISION2']])
        else:
            si_cmd.extend(['-r', os.environ['MKSSI_REVISION2'], '-r', os.environ['MKSSI_REVISION1']])

    si_out = ''
    if sandboxes:
        for sandbox in sandboxes:
            si_cmd_local = si_cmd + ['--sandbox=' + sandbox]

            projectRevision = raw_input("Specify some project revision for %s to diff to. [latest] " % sandbox)
            if len(projectRevision) > 0:
                si_cmd_local += ['-r', projectRevision]

            if show_debug:
                print si_cmd_local
            si_out += subprocess.check_output(si_cmd_local)
    else:
        if show_debug:
            print si_cmd
        si_out = subprocess.check_output(si_cmd)

    if show_debug:
        print ''
        print 'si_out:'
        print si_out
        print ''

    # parse change packages at the end of the output
    changes = {}
    for line in si_out.splitlines():
        match = re.search(r'^([\d]+)\:([\d]+)\s+(.+)$', line)
        if match:
            id = match.group(1)
            cp_id = match.group(2)
            cp_summary = match.group(3)

            if not changes.has_key(id):
                changes[id] = {}

            changes[id][cp_id] = cp_summary

    if show_debug:
        print "Changes:"
        pp = pprint.PrettyPrinter(indent=2)
        pp.pprint(changes)

    if changes.keys():
        createQueryFromIds(changes.keys())


def getTimeOfCheckpoint(project, revision):
    si_cmd = ['si', 'projectinfo', '--project=' + project, '--projectRevision=' + revision]

    if os.environ.has_key('MKSSI_HOST'):
        si_cmd.append('--hostname=' + os.environ['MKSSI_HOST'])
    if os.environ.has_key('MKSSI_PORT'):
        si_cmd.append('--port=' + os.environ['MKSSI_PORT'])

    si_out = subprocess.check_output(si_cmd)

    checkPointTime = datetime.datetime(1900, 1, 1)

    keyword = 'Last Checkpointed: '
    for line in si_out.splitlines():
        if line.startswith(keyword):
            timeString = line[len(keyword):]
            checkPointTime = datetime.datetime.strptime(timeString, '%b %d, %Y %I:%M:%S %p')
            break

    if show_debug:
        print si_cmd
        print 'Project        :', project
        print 'Revision       :', revision
        print 'Checkpoint time:', checkPointTime

    return checkPointTime


def getProjectInfoFromConfigPath(configPath):
    variantMatch = re.search(r'#d=([^#]+)', configPath)
    buildMatch = re.search(r'#b=([0-9\.]+)', configPath)

    project = {'config_path': configPath, 'kind': 'normal'}

    if variantMatch:
        project['kind'] = 'variant'
        project['devpath'] = variantMatch.group(1)
    if buildMatch:
        project['kind'] = 'build'
        project['revsion'] = buildMatch.group(1)

    siCmd = ['mksapiviewer', '--iplocal', '--xml', 'si', 'projectinfo', '-P', configPath]

    if os.environ.has_key('MKSSI_HOST'):
        siCmd += ['--hostname', os.environ['MKSSI_HOST']]
    if os.environ.has_key('MKSSI_PORT'):
        siCmd += ['--port', os.environ['MKSSI_PORT']]

    try:
        xmlOut = et.fromstring(subprocess.check_output(siCmd))
        xmlProjectName = xmlOut.findtext(
            "./WorkItems/WorkItem[@id='%s']/Field[@name='projectName']/Value" % configPath)
        project['path'] = xmlProjectName
    except:
        print "si returned error for", siCmd
        pass

    return project


def getMemberFromEnv(memberKey, memberProjectConfigKey, memberSandboxKey):
    if show_debug: print "getMemberFromEnv: memberKey:              %s" % memberKey
    if show_debug: print "getMemberFromEnv: memberProjectConfigKey: %s" % memberProjectConfigKey
    if show_debug: print "getMemberFromEnv: memberSandboxKey:       %s" % memberSandboxKey

    memberName = os.environ[memberKey]
    memberPj = os.environ[memberProjectConfigKey]

    member = {
        'member':  {'name': memberName},
        'project': getProjectInfoFromConfigPath(memberPj)
    }

    if show_debug: print "getMemberFromEnv: memberName: %s" % memberName
    if show_debug: print "getMemberFromEnv: memberPj:   %s" % memberPj

    if os.environ.has_key(memberSandboxKey):
        memberSb = os.environ[memberSandboxKey]
        member['sandbox'] = {'path': memberSb}
        member['member']['working'] = re.sub(r'(.+\\)[^\\]+$', '\g<1>' + memberName, memberSb)

    if show_debug: print "getMemberFromEnv: member:\n%s" % pprint.pformat(member)
    return member


def getMemberInfos():
    members = []

    if getWindow() == "":
        return members

    host = ""
    port = ""
    devpath = ""

    if os.environ.has_key('MKSSI_HOST'):
        host = os.environ['MKSSI_HOST']
    if os.environ.has_key('MKSSI_PORT'):
        port = os.environ['MKSSI_PORT']
    if os.environ.has_key('MKSSI_VARIANT'):
        devpath = os.environ['MKSSI_VARIANT']
    # fetch member infos
    members = []

    if getWindow() == 'archive':
        # archive window, only one member selected, but possibly multiple revsions
        memberKey = "MKSSI_FILE"
        memberProjectConfigKey = "MKSSI_PROJECT_CONFIG_PATH"
        memberSandboxKey = "MKSSI_SANDBOX"

        member = getMemberFromEnv("MKSSI_FILE", "MKSSI_PROJECT_CONFIG_PATH", "MKSSI_SANDBOX")

        # fetch all revisions
        for i in range(1, 256):
            memberRevisionKey = "MKSSI_REVISION%d" % i

            if not os.environ.has_key(memberRevisionKey):
                break

            member['member']['revision'] = os.environ[memberRevisionKey]
            members.append(member)

    elif getWindow() in ['sandbox', 'project']:
        # sandbox or project view, multiple members might be selected
        if os.environ.has_key('MKSSI_NMEMBER'):
            memberCount = int(os.environ['MKSSI_NMEMBER'])
            if show_debug: print "memberCount: %d" % memberCount
            for i in range(1, memberCount + 1):
                member = getMemberFromEnv("MKSSI_MEMBER%d" % i, "MKSSI_MEMBER%d_PROJECT_CONFIG_PATH" % i,
                                          "MKSSI_MEMBER%d_SANDBOX" % i)
                members.append(member)

    # use si to fetch the archive
    for m in members:
        m['kind'] = 'member'

        if not m.has_key('path'):
            # build si call to get archive path
            si_args = ['si', 'archiveinfo', '--nolabels']
            if host:
                si_args.append('--hostname=' + host)
            if port:
                si_args.append('--port=' + port)
            si_args += ['-P', m['project']['config_path']]
            si_args += [m['member']['name']]

            si_out = subprocess.check_output(si_args)
            match = re.search(r'Archive\sName\:\s+([^\s]+)', si_out)
            if match:
                m['path'] = match.group(1)

        if not m['member'].has_key('revision'):
            # build si call to get member revision
            si_args = ['si', 'viewproject', '-N']
            if host:
                si_args.append('--hostname=' + host)
            if port:
                si_args.append('--port=' + port)
            si_args += ['-P', m['project']['config_path']]

            si_out = subprocess.check_output(si_args)
            match = re.search(r'\s+' + m['member']['name'] + r'.*?([0-9\.]+)', si_out)
            if match:
                m['member']['revision'] = match.group(1)

    return members


def getProjectInfos():
    projects = []

    if getWindow() == "":
        return projects

    # selection counters
    project_count = 0
    sub_project_count = 0
    member_count = 0
    if (os.environ.has_key('MKSSI_NPROJECT')):
        project_count = int(os.environ['MKSSI_NPROJECT'])
    if (os.environ.has_key('MKSSI_NSUBPROJECT')):
        sub_project_count = int(os.environ['MKSSI_NSUBPROJECT'])
    if (os.environ.has_key('MKSSI_NMEMBER')):
        member_count = int(os.environ['MKSSI_NMEMBER'])

    # check window
    if re.match(r'sandbox|si\.mysandboxes', getWindow()):
        # sandbox view

        # collect sandboxes to parse
        sandboxes = []
        if (project_count == 0) and (sub_project_count == 0) and (member_count == 0):
            # only root selected -> check for mkssi_file
            if (os.environ.has_key('MKSSI_FILE')):
                sandboxes.append(os.environ['MKSSI_FILE'])
            else:
                print "no sandbox found. aborting."
        else:
            # add project sandboxes
            for i in range(1, project_count + 1):
                sandboxes.append(os.environ["MKSSI_PROJECT%d" % i + "_SANDBOX"])
            # add sub project sandboxes
            for i in range(1, sub_project_count + 1):
                sandboxes.append(os.environ["MKSSI_SUBPROJECT%d" % i + "_SANDBOX"])

        # parse sandboxes
        for s in sandboxes:
            # add project info to output
            projects.append(getProjectInfoFromSandbox(s))

    elif re.match(r'project|si\.projects', getWindow()):
        # project view or project list view

        # collect projects to parse
        if (project_count == 0) and (sub_project_count == 0) and (member_count == 0):
            # only root selected -> check for mkssi_file
            if os.environ.has_key('MKSSI_FILE'):
                project = {}
                project['path'] = os.environ['MKSSI_FILE']
                # fetch kind of project
                if os.environ.has_key('MKSSI_BUILD'):
                    project['kind'] = 'build'
                    project['revision'] = os.environ['MKSSI_BUILD']
                elif os.environ.has_key('MKSSI_VARIANT'):
                    project['kind'] = 'variant'
                    project['devpath'] = os.environ['MKSSI_VARIANT']
                else:
                    project['kind'] = 'normal'
                # append to list
                projects.append(project)
            else:
                print "no project found. aborting."
        else:
            # fetch projects
            for i in range(1, project_count + 1):
                project = {}
                project['path'] = os.environ['MKSSI_PROJECT%d' % i]
                project['kind'] = 'normal'
                # append to list
                projects.append(project)

            # fetch subprojects
            for i in range(1, sub_project_count + 1):
                # master and servant
                parent_pj = os.environ['MKSSI_SUBPROJECT%d_PROJECT' % i]
                sub_pj = os.environ['MKSSI_SUBPROJECT%d' % i]
                # fetch project infos
                build = ''
                variant = ''
                if os.environ.has_key('MKSSI_BUILD'):
                    build = os.environ['MKSSI_BUILD']
                elif os.environ.has_key('MKSSI_VARIANT'):
                    variant = os.environ['MKSSI_VARIANT']

                project = getProjectInfoFromProject(parent_pj, sub_pj, build, variant)

                # append to list
                if project:
                    projects.append(project)
    elif re.match(r'projecthistory', getWindow()):
        # project history view
        sub_project_count = 0
    return projects


def makeUrls(items):
    host = "ims-adas"
    port = "7001"

    if os.environ.has_key('MKSSI_HOST'):
        host = os.environ['MKSSI_HOST']
    if os.environ.has_key('MKSSI_PORT'):
        port = os.environ['MKSSI_PORT']

    server = r'http://' + host + r':' + port

    for i in items:
        if i.has_key('path') and i.has_key('kind'):
            # members
            if i['kind'] == 'member':
                prj = i['project']
                mbr = i['member']

                # command view revsion
                url = server + r'/si/viewrevision'
            else:
                prj = i
                mbr = None

                # command view project
                url = server + r'/si/viewproject'

            if prj.has_key('path'):
                url = url + '?projectName=' + urllib.quote(prj['path'])

                # project attributes
                if prj['kind'] == 'build' and prj.has_key('revision'):
                    url = url + r'&projectRevision=' + urllib.quote(prj['revision'])
                elif prj['kind'] == 'variant' and prj.has_key('devpath'):
                    url = url + r'&developmentPath=' + urllib.quote(prj['devpath'])

                # member attributes
                if mbr:
                    # member name
                    url = url + r'&selection=' + urllib.quote(mbr['name'])
                    # member revision
                    if i['member'].has_key('revision'):
                        url = url + '&revision=' + mbr['revision']

                # set the url
                i['url'] = url

        elif i.has_key('issue'):
            i['url'] = "http://%s:%s/im/issues?selection=%s" % (host, port, urllib.quote(i['issue']['id']))
            i['issue']['integrity_url'] = "integrity://%s:%s/im/viewissue?selection=%s" % (
            host, port, urllib.quote(i['issue']['id']))

    return items


def downloadMember(m, target=""):
    si_cmd = ['si', 'viewrevision', '--forceConfirm=no']

    if os.environ.has_key('MKSSI_HOST'):
        si_cmd.append('--hostname=' + os.environ['MKSSI_HOST'])
    if os.environ.has_key('MKSSI_PORT'):
        si_cmd.append('--port=' + os.environ['MKSSI_PORT'])

    if m.has_key('sandbox'):
        si_cmd.append('--sandbox=' + m['sandbox']['path'])
    elif m.has_key('project'):
        si_cmd += ['-P', m['project']['config_path']]

    if m['member'].has_key('revision'):
        si_cmd.append('--revision=' + m['member']['revision'])

    si_cmd.append(m['member']['name'])

    if target == "":
        # nothing given -> ask
        root = Tkinter.Tk()
        root.withdraw()
        target = tkFileDialog.askdirectory(parent=root, initialdir="/", title='Select a directory to store the file(s)')

    if target == "":
        # nothing given -> target to temp
        target = os.environ['TEMP']

    if os.path.isdir(target):
        # target directory given -> add member name
        if m['member'].has_key('revision'):
            member_name, member_ext = os.path.splitext(m['member']['name'])
            target = os.path.join(target, member_name + '_' + m['member']['revision'] + member_ext)
        else:
            target = os.path.join(target, m['member']['name'])

    # add to cmd
    si_cmd.append('>' + target)

    # debug
    if show_debug:
        print "si cmd:"
        print si_cmd

    # run command
    try:
        print "Fetching member " + m['member']['name'] + " ..."
        subprocess.Popen(" ".join(si_cmd), shell=True, stdout=subprocess.PIPE).communicate()[0]
        return target
    except:
        print "Download of '" + m['member']['name'] + "' to '" + target + "' failed."
        return ''


def createQueryFromIds(idList):
    if len(idList):
        # build query based on ro ids
        im_cmd = ['im', 'issues', '-g']

        query_def = '('
        for id in idList:
            query_def += '(field["ID"]=' + id + ') or '
        # remove ' or', add ')'
        query_def = query_def[:-4] + ')'

        im_cmd += ['--querydefinition=' + query_def]

        if show_debug:
            print im_cmd

        subprocess.call(im_cmd)


def query(items):
    ids = []

    for item in items:
        if item.has_key('issue'):
            if item['issue'].has_key('id'):
                ids.append(item['issue']['id'])

    createQueryFromIds(ids)


def queryFromClip():
    clip = winGetClipboard()

    ids = re.findall(r'\d+', clip, re.MULTILINE)

    if show_debug:
        print "Clipboard:\n%s" % clip
        print "Ids:\n%s" % str(ids)

    createQueryFromIds(ids)


def main():
    global show_debug

    # get arguments
    argParser = argparse.ArgumentParser(description="""
MAxiMUm - MAke Mks Usable

To unleash the power of MAxiMUm, it has to be started from the MKS Gui that
sets the required environment variables. The environment set by the GUI tells
MAxiMUm what element is selected, wich server you are connected to and what
window you selection was in.
                                                      """,
                                        formatter_class=argparse.RawTextHelpFormatter, )
    argParser.add_argument("-u", "--clip_url", "--clipUrl", action='store_true',
                           help="Copy URL to selected items to clip board")
    argParser.add_argument("-a", "--clip_archive", "--clipArchive", action='store_true',
                           help="Copy archive / project path to selected items into clip board")
    argParser.add_argument("--clip",
                           help="""
Copies customized string into the clipboard
Syntax structure (plain python dictionary):
 "i['field'] + ' : ' + i['field']['subfield']"
Existing fields:
 kind
 url
 path
 devpath
 sandbox
   path
 issue
   id
   type
   state
   structure_element
   summary
   ordered_by
   assigned_user
   planned_release
   integrity_url
 member
   name
   working
 project
   devpath
   kind
   path
   sandbox
     path
                           """)
    argParser.add_argument('--cmd', metavar='CMD',
                           help="Run specified command with each selected member / project")
    argParser.add_argument('--cmd_on_dir', metavar='CMD',
                           help="Run specified command with the directory of each selected member / project")
    argParser.add_argument('--fetch',
                           help="Download selected members to directory if specified")
    argParser.add_argument('--copy_to_merge_ro', action='store_true',
                           help="Copies selected Realization Orders to new one intended to merge the contents of the source RO to another development path")
    argParser.add_argument('--project_change_query', action='store_true',
                           help="Creates a new query that includes all change Realization Orders")
    argParser.add_argument('--query', action='store_true',
                           help="Create a new query, that holds the elements currently selected")
    argParser.add_argument('--query_from_clip', action='store_true',
                           help="Create a new query, that holds the elements currently stored in clipboard as ids")
    argParser.add_argument('--viewqc', type=int,
                           help="Search for IMS-Issue with corresponding QC ticket ID")
    argParser.add_argument('--dropSbx', action='store_true',
                           help="Drop a selected sandbox. Advantage: takes care of all your symlinked folders inside. MKS will remove their content as well...")
    argParser.add_argument('-d', '--debug', action='store_true',
                           help="Print debug info and wait for keypress ")

    args = argParser.parse_args()

    # debugging as global variable
    show_debug = args.debug

    # debug
    if args.debug:
        print "Input args:"
        for k, v in vars(args).iteritems():
            print "  %s: '%s'" % (k, str(v))

        print "MKS Environment:"
        for key in sorted(os.environ.keys()):
            if re.match(r'^MKSSI_.+', key):
                print "  " + key + ": " + os.environ[key]
        print

    if args.dropSbx:
        if os.environ['MKSSI_WINDOW'] == 'si.mysandboxes':
            dropSandbox()
        else:
            raw_input('You have to select a sandbox in the sandboxes view. Press enter...')
            exit()

    # check environment
    if (not os.environ.has_key('MKSSI_HOST')) \
            or (not os.environ.has_key('MKSSI_PORT')) \
            or (not os.environ.has_key('MKSSI_USER')):
        print "ERROR: Missing MKS environment. Either start it from within MKS or set MKSSI_HOST, MKSSI_PORT, MKSSI_USER in your environment"
        exit(1)

    # retrieve members and projects
    items = getMemberInfos()
    items += getProjectInfos()
    items += getIssueInfos()

    # add urls
    items = makeUrls(items)

    # debug
    if show_debug:
        print "Condensed information:"
        pp = pprint.PrettyPrinter(indent=2)
        pp.pprint(items)

    # build clipboard string
    if args.clip_url or args.clip_archive or args.clip:
        clip = []
        if args.clip_archive:
            for i in items:
                if i.has_key('path'):
                    clip.append(i['path'])
        if args.clip_url:
            for i in items:
                if i.has_key('url'):
                    clip.append(i['url'])

        if args.clip:
            for i in items:
                clip.append(eval(args.clip))

        clip_str = '\n'.join(clip)

        # push to clibpboard
        winSetClipboard(clip_str)

        # debug
        if show_debug:
            print "Copied to clipboard:"
            print "  " + clip_str

    # download target
    if args.fetch != None:
        # debug
        if show_debug:
            print "download_path: " + args.fetch

        for i in items:
            if i.has_key('kind') and i['kind'] == 'member':
                download_path = os.path.dirname(downloadMember(i, args.fetch))

    # run run_cmd_file on every member
    if args.cmd or args.cmd_on_dir:
        for i in items:
            if i.has_key('kind'):
                local_path = ''

                if i['kind'] == 'member':
                    if i['member'].has_key('revision') and not i['member'].has_key('working'):
                        local_path = downloadMember(i, os.environ['TEMP'])
                    elif i['member'].has_key('working'):
                        local_path = i['member']['working']
                elif i.has_key('sandbox') and i['sandbox'].has_key('path'):
                    local_path = i['sandbox']['path']

                if args.cmd:
                    # open if existing
                    if os.path.exists(local_path):
                        if show_debug:
                            print "command: " + args.cmd + " " + local_path
                        subprocess.call(args.cmd + " " + local_path)

                if args.cmd_on_dir:
                    local_dir = os.path.dirname(local_path)
                    # open if existing
                    if os.path.exists(local_dir):

                        if '%s' not in args.cmd_on_dir:
                            args.cmd_on_dir += ' %s'

                        if show_debug:
                            print "command: " + args.cmd_on_dir % local_dir
                        subprocess.call(args.cmd_on_dir % local_dir)

    # create merge ro
    if args.copy_to_merge_ro:
        copyToMergeRO(items)

    if args.query:
        query(items)

    if args.query_from_clip:
        queryFromClip()

    # create query of all project changes
    if args.project_change_query:
        projectChangeQuery()

    # view the IMS ticket corresponding to the given QC id
    if args.viewqc:
        viewQcTicket(viewqcId)

    # debug
    if show_debug:
        raw_input("Press Enter to continue...")


if __name__ == "__main__":
    main()
