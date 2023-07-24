import os
import sys
import argparse
import subprocess
import multiprocessing
import xml.etree.ElementTree as ET
from difflib import SequenceMatcher as SM
try:
  import xlwt
except ImportError:
  print 'You need to have xlwt installed. Either install Python(x,y) or find it here: https://pypi.python.org/pypi/xlwt'
  sys.exit()

class MemberItem():
  def __init__(self, oldRev='', oldPjRev='', newRev='', newPjRev='', ratio=0.0):
    self.newRevision        = newRev
    self.oldRevision        = oldRev
    self.oldProjectRevision = oldPjRev
    self.newProjectRevision = newPjRev
    self.ratio              = ratio

def newProcess(cmdLine):
  proc = subprocess.Popen(
    cmdLine,
    bufsize=1024,
    stdout = subprocess.PIPE,
    stderr = subprocess.PIPE,
    stdin  = subprocess.PIPE,
    creationflags=0x08000000 )
  return proc

def deformat(string):
  return string.decode('cp852').encode('utf-8')

# The magic component paths. Needed, because our integrators are not able to maintain the root of the projects...
COMPONENT_PATHS = {}

# global error list
ERRORS = []

def joinMksPath(base, append):
  if base.endswith('.pj'):
    base = os.path.dirname(base)

  ret = os.path.join(base, append).replace('\\', '/')

  return ret

def getProjectAndMemberFromPath(member):
  path, file = os.path.split(member)
  while path.endswith('/rcs'):
    path = os.path.dirname(path)
  path += '/project.pj'
  return path, file

def collectAllComponentsInRepo():
  global COMPONENT_PATHS

  cmd = ['mksapiviewer', '--iplocal', '--xml', 'si', 'viewproject', '--hostname=ims-adas', '--port=7001', '--project=/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/project.pj', '--norecurse']
  proc = newProcess(cmd)
  ret, err = proc.communicate()

  root = ET.fromstring( deformat(ret) )

  items = root.findall('./WorkItems/WorkItem')

  for item in items:
    cmpPath = item.attrib['displayId']

    cmp = getCmpFromPath( cmpPath ).split('_')[0].lower()

    if cmp == 'cb':
      COMPONENT_PATHS[cmp]        = joinMksPath( cmpPath, os.path.join('04_Engineering/01_Source_Code/algo/gb/project.pj' ) )
    elif cmp == 'ofc':
      COMPONENT_PATHS[cmp]        = joinMksPath( cmpPath, os.path.join('04_Engineering/01_Source_Code/algo/pfc/project.pj') )
    else:
      COMPONENT_PATHS[cmp]        = joinMksPath( cmpPath, os.path.join('04_Engineering/01_Source_Code/algo'          , cmp         , 'project.pj') )
    COMPONENT_PATHS[cmp + '_wrp'] = joinMksPath( cmpPath, os.path.join('04_Engineering/01_Source_Code/algo/00_Custom', cmp + '_wrp', 'project.pj') )

  # handle also specialities
  COMPONENT_PATHS['gb']       = COMPONENT_PATHS['cb']
  COMPONENT_PATHS['gb_wrp']   = COMPONENT_PATHS['cb_wrp']
  COMPONENT_PATHS['memo']     = COMPONENT_PATHS['emo']
  COMPONENT_PATHS['memo_wrp'] = COMPONENT_PATHS['emo_wrp']
  COMPONENT_PATHS['semo']     = COMPONENT_PATHS['emo']
  COMPONENT_PATHS['semo_wrp'] = COMPONENT_PATHS['emo_wrp']
  COMPONENT_PATHS['pfc']      = COMPONENT_PATHS['ofc']
  COMPONENT_PATHS['pfc_wrp']  = COMPONENT_PATHS['ofc_wrp']

# Input:  MKS project path + label
# Outout: Corresponding revision number on that particular path
def getRevisionFromCheckpointLabel( project, label ):
  if label == '':
    return ''

  cmd = ['mksapiviewer', '--iplocal', '--xml', 'si', 'viewprojecthistory', '--hostname=ims-adas', '--port=7001', '--project=' + project, '--fields=revision', '--rfilter=labeled:' + label]
  proc = newProcess(cmd)
  ret, err = proc.communicate()

  if proc.returncode != 0:
    ERRORS.append(err)
    print err
    return ''

  root = ET.fromstring( deformat(ret) )
  revisionItem = root.find('./WorkItems/WorkItem[@displayId="' + project + '"]/Field[@name="revisions"]/List[@elementType="item"]/Item[@modelType="si.Revision"]')

  if revisionItem is not None:
    return revisionItem.attrib['id']
  else:
    return ''

# Input:  MKS project path + revision number
# Output: corresponding attached label
def getLabelsFromCheckpointRevision( project, revision ):
  if revision == '':
    return ''

  cmd = ['mksapiviewer', '--iplocal', '--xml', 'si', 'viewprojecthistory', '--hostname=ims-adas', '--port=7001', '--project=' + project, '--projectRevision=' + revision, '--fields=labels', '--rfilter=range:' + revision + '-' + revision]
  proc = newProcess(cmd)
  ret, err = proc.communicate()

  root = ET.fromstring( deformat(ret) )

  if proc.returncode != 0:
    err = root.find('./Exception[@class="ItemNotFoundException"]/Message').text
    ERRORS.append(err)
    print err
    return ''

  label = root.find('./WorkItems/WorkItem[@displayId="' + project + '"]/Field[@name="revisions"]/List[@elementType="item"]/Item[@id="' + revision + '"]/Field[@name="labels"]/List/Value[@dataType="string"]')

  if label is not None:
    return label.text
  else:
    return ''

# Input:  Path of a shared subproject + revision
# Output: Archive where it's shared from
def getSourceFromSharedSubProject( project, revision ):
  cmd = ['mksapiviewer', '--iplocal', '--xml', 'si', 'projectinfo', '--hostname=ims-adas', '--port=7001', '--nodevpaths', '--noassociatedissues', '--noacl', '--noattributes', '--project=' + project, '--projectRevision=' + revision]

  proc = newProcess(cmd)
  ret, err = proc.communicate()

  root = ET.fromstring( deformat(ret) )
  sharedItem = root.find('./WorkItems/WorkItem[@displayId="' + project + '"]/Field[@name="sharedFrom"]/Value[@dataType="string"]')

  source = ''
  if sharedItem is None:
    # Handle integrators inabilities
    cmp = getCmpFromPath(project)
    if not COMPONENT_PATHS.has_key(cmp):
      ERRORS.append(err)
      print 'Missing:', cmp
    else:
      source = COMPONENT_PATHS[cmp]
      # Another magic trick to get the custom share :(
      if ('00_Custom' in project) and ('00_Custom' not in source):
        source = os.path.split( os.path.split(source)[0] )[0] + '/00_Custom/' + cmp + '/project.pj'
  else:
    source = sharedItem.text

  return source

class ComponentEntry():
  def __init__(self, label, revision):
    self.label    = label
    self.revision = revision

# collect all shared compoents under a given MKS project path + label
# Input:  MKS project + label
# Output: dictionary of shared components plus corresponding revision and label
def collectComponentsAndPaths(project, label):
  print '\nGet revision from checkpoint label:', label,
  revision = getRevisionFromCheckpointLabel(project, label)
  print revision

  cmd = ['mksapiviewer', '--iplocal', '--xml', 'si', 'viewproject', '--hostname=ims-adas', '--port=7001', '--project=' + project, '--projectRevision=' + revision, '--norecurse', '--filter=file:*.pj']

  print 'Get project info:', project, '\n'
  proc = newProcess(cmd)
  ret, err = proc.communicate()

  if proc.returncode != 0:
    ERRORS.append(err)
    print err

  root = ET.fromstring( deformat(ret) )
  shares = [ item for item in root.findall('./WorkItems/WorkItem[@modelType="si.Subproject"]') if (item.find('./Field[@name="type"]/Value[@dataType="string"]').text == 'shared-build-subproject') ]

  components = {}

  for share in shares:
    name = share.find('./Field[@name="name"]/Value[@dataType="string"]').text
    cmp  = getCmpFromPath( name )

    print 'Processing Component:', cmp.upper()

    cmpRev = share.find('./Field[@name="memberrev"]/Item[@modelType="si.Revision"]').attrib['id']

    source = getSourceFromSharedSubProject( name, cmpRev )
    if source == '':
      continue
    cmpLabel = getLabelsFromCheckpointRevision( source, cmpRev )

    if components.has_key(source) and (components[source].label != cmpLabel):
      print 'Already had component', cmp, 'with label:', compareContents[source].label
      print '  Now we found another one:', cmpLabel
    components[source] = ComponentEntry( revision=cmpRev, label=cmpLabel )

  return components

# Input:  /path/to/[..]/some/_CMP_/any_file.end
# Output: _CMP_
def getCmpFromPath(path):
  return os.path.basename( os.path.dirname( path ) )

# Returns the content of a project (members and revisions
def getProjectContent( project, projectRevision ):
  cmd = ['mksapiviewer', '--iplocal', '--xml', 'si', 'viewproject', '--hostname=ims-adas', '--port=7001', '--recurse', '--project=' + project, '--projectRevision=' + projectRevision]

  proc = newProcess( cmd )
  ret, err = proc.communicate()

  if proc.returncode != 0:
    ERRORS.append(err)
    print err

  root = ET.fromstring( deformat(ret) )

  items = root.findall('./WorkItems/WorkItem[@modelType="si.Subproject"]')
  subPjRevs = { item.find('./Field[@name="name"]/Value[@dataType="string"]').text : item.find('./Field[@name="memberrev"]/Item').attrib['id'] for item in items }
  subPjRevs[project] = projectRevision

  items = root.findall('./WorkItems/WorkItem[@modelType="si.Member"]')
  members = {}
  for item in items:
    name     = item.find('./Field[@name="name"]/Value[@dataType="string"]').text
    revision = item.find('./Field[@name="memberrev"]/Item').attrib['id']
    parent   = item.find('./Field[@name="parent"]/Value[@dataType="string"]').text
    pjRev    = subPjRevs[parent]

    members[name] = MemberItem( oldRev=revision, oldPjRev=pjRev, newRev=revision, newPjRev=pjRev )

  return members

# evaluate the difference of two project revisions
# Input:  MKS project path + two revisions (old and new)
# Output: dictionary of full member paths and their respective revisions (old, new) in both checkpoints ('n/a' if not found in respective checkpoint)
def getProjectDiff( project, oldPjRevision, newPjRevision ):
  cmd = ['si', 'mods', '--hostname=ims-adas', '--port=7001', '--recurse', '--project=' + project, '-r' + oldPjRevision, '-r' + newPjRevision]

  proc = newProcess(cmd)
  ret, err = proc.communicate()

  if proc.returncode != 0:
    ERRORS.append(err)
    print err

  memberDiffs = {}
  currentPj = os.path.split(project)[0]
  currentOldPjRev = oldPjRevision
  currentNewPjRev = newPjRevision

  # parse the return lines from MKS to collect member and their respective paths
  for line in ret.splitlines():
    line = line.strip()
    if line.startswith('Member revision changed: '):
      split = line[len('Member revision changed: '):].split()

      assert len(split) == 5
      assert ( (split[1] == 'from') and (split[3] == 'to') )
      memberPath = currentPj + '/' + split[0]
      if memberDiffs.has_key(memberPath):
          print 'Warning: Member', memberPath
          print '  Already got with rev1 =', memberDiffs[memberPath].oldRevision, 'and rev2 =', memberDiffs[memberPath].newRevision + '. Trying to add rev:', split[-1]
      else:
        memberDiffs[ memberPath ] = MemberItem( oldRev=split[2], newRev=split[4], oldPjRev=currentOldPjRev, newPjRev=currentNewPjRev )

    elif line.startswith('Added member: '):
      split = line[len('Added member: '):].split()
      memberPath = currentPj + '/' + split[0]
      if memberDiffs.has_key(memberPath):
        if memberDiffs[memberPath].newRevision == 'n/a':
          memberDiffs[memberPath].newRevision = split[-1]
        else:
          print 'Warning: Member', memberPath
          print '  Already got with rev1 =', memberDiffs[memberPath].oldRevision, 'and rev2 =', memberDiffs[memberPath].newRevision + '. Trying to add rev:', split[-1]
      else:
        memberDiffs[memberPath] = MemberItem( oldRev='n/a', newRev=split[-1], oldPjRev='n/a', newPjRev=currentNewPjRev )

    elif line.startswith('Dropped member: '):
      split = line[len('Dropped member: '):].split()
      memberPath = currentPj + '/' + split[0]
      if memberDiffs.has_key(memberPath):
        if memberDiffs[memberPath].oldRevision == 'n/a':
          memberDiffs[memberPath].oldRevision = split[-1]
        else:
          print 'Warning: Member', memberPath
          print '  Already got with rev1 =', memberDiffs[memberPath].oldRevision, 'and rev2 =', memberDiffs[memberPath].newRevision + '. Trying to add rev:', split[-1]
      else:
        memberDiffs[memberPath] = MemberItem( oldRev=split[-1], newRev='n/a', oldPjRev=currentOldPjRev, newPjRev='n/a' )

    elif line.startswith('Subproject changed: '):
      split = line[len('Subproject changed: '):].split()
      currentPj = os.path.dirname(split[0])

    elif line.startswith('Subproject checkpoint changed: '):
      split = line[len('Subproject checkpoint changed: '):].split()
      currentPj = os.path.dirname(split[0])
      currentOldPjRev = split[2]
      currentNewPjRev = split[4]

    elif line.startswith('Dropped subproject: '):
      split = line[len('Dropped subproject: '):].split()
      currentPj = os.path.dirname(split[0])
      currentOldPjRev = split[3]
      currentNewPjRev = 'n/a'

    elif line.startswith('Added subproject: '):
      split = line[len('Added subproject: '):].split()
      currentPj = os.path.dirname(split[0])
      currentOldPjRev = 'n/a'
      currentNewPjRev = split[3]

  return memberDiffs

# filter out unwanted findings
# In/Out: dictionary of full member paths and their respective revisions (old, new) in both checkpoints ('n/a' if not found in respective checkpoint)
def filterMembers(diffs):
  delList = []
  for member, item in diffs.iteritems():
    rev1 = item.oldRevision.split('.')
    rev2 = item.newRevision.split('.')

    # base assumption: filter out
    discard = True
    if rev1[0] == 'n/a':
      # filter out, if member was not part of old checkpoint and added in the new one
      discard = True
    elif len(rev1) == len(rev2):
      # same member branch depth in both checkpoints
      for i in range(len(rev1)-1):
        if rev1[i] != rev2[i]:
          # do not filter out if members are not on the same member branch
          discard = False

      if discard and (int(rev2[-1]) < int(rev1[-1])):
        # if they are on the same member branch, do not filter out if oldRev is newer than newRev
        discard = False
    elif len(rev1) < len(rev2):
      # higher member branch in new checkpoint
      for i in range(len(rev1)-1):
        if rev1[i] != rev2[i]:
          # do not filter out, if new member branch was not created from old member branch
          discard = False

      if discard and (int(rev2[i+1]) < int(rev1[i+1])):
        # if same 'root-branch', do not filter out, if newRev was branched before old rev
        discard = False
    else:
      # do not filter out in any other case
      discard = False

    if discard:
      delList.append(member)

  # remove items from dict
  for item in delList:
    del diffs[item]

  return diffs

# Append a list of strings to the next free row in a worksheet
def write_row(worksheet, list, style = xlwt.Style.easyxf('')):
  lineCnt = worksheet.last_used_row + 1

  for item in enumerate(list):
    worksheet.write( lineCnt, item[0], item[1], style )

# Calculate ratio of two revisions of the same file
def calcRatio( member, memberItem, oldRoot, newRoot, complexRatio ):
  project, file = getProjectAndMemberFromPath(member)

  cmd = ['si', 'viewrevision', '--hostname=ims-adas', '--port=7001', '--project=' + project]

  relPath = os.path.join( os.path.dirname( project[project.find('04_Engineering'):] ), file )

  ratio = 0.0
  if (memberItem.oldRevision != 'n/a') and (memberItem.newRevision != 'n/a'):
    path1 = os.path.join( oldRoot, relPath )
    if os.path.isfile( path1 ):
      fid = open(path1, 'r')
      ret1 = ''.join(fid.readlines())
      fid.close()
    else:
      proc1 = newProcess( cmd + ['--revision=' + memberItem.oldRevision, '--projectRevision=' + memberItem.oldProjectRevision, file] )
      ret1, err1 = proc1.communicate()

    path2 = os.path.join( newRoot, relPath )
    if os.path.isfile( path2 ):
      fid = open(path2, 'r')
      ret2 = ''.join(fid.readlines())
      fid.close()
    else:
      proc2 = newProcess( cmd + ['--revision=' + memberItem.newRevision, '--projectRevision=' + memberItem.newProjectRevision, file] )
      ret2, err2 = proc2.communicate()

    diff = SM()
    diff.set_seqs(ret1, ret2)

    ratio = diff.ratio() if complexRatio else diff.quick_ratio()

  return ratio

def generateOutput(worksheet, diffs, oldValues, newValues):
  if len(diffs) > 0:
    write_row(worksheet, [''])
    write_row(worksheet, ['Member', 'Rev. in ' + oldValues.label, 'Rev. in ' + newValues.label, 'Estimated difference [%]'], xlwt.Style.easyxf('font: bold True'))
    for member, item in sorted(diffs.iteritems()):
      project, file = getProjectAndMemberFromPath(member)

      if item.newRevision == 'n/a':
        diffStr = 'Dropped'
        ratio   = 'n/a'
      elif item.oldRevision == 'n/a':
        diffStr = 'Added'
        ratio   = '100%'
      elif item.oldRevision == item.newRevision:
        diffStr = 'Same'
        ratio   = '0%'
      else:
        diffStr = 'diff --hostname=ims-adas --port=7001 --ignoreblanks --ignoreWhitespace -g -P ' + project + ' --projectRevision=' + item.newProjectRevision + ' -r ' + item.oldRevision + ' -r ' + item.newRevision + ' ' + file
        if args.calcDiff:
          ratio = '%.0f' % ((1.0 - item.ratio)*100) + '%'
        else:
          ratio = 'Not calculated'

      write_row( worksheet, [os.path.basename(member), item.oldRevision, item.newRevision, ratio, diffStr] )
  else:
    write_row(worksheet, ['no changes'])

  write_row(worksheet, [''])
  write_row(worksheet, [''])

# Generate XLS report
# input:  - old project name
#         - dictionary of shared components plus corresponding revision and label for old checkpoint
#         - new project name
#         - dictionary of shared components plus corresponding revision and label for new checkpoint
# output: Excel sheet with an overview of the resulting differences
def compareContents(oldName, oldContent, newName, newContent):
  xlsName = oldName + '_' + newName + '.xls'

  diffs = {}
  pool = multiprocessing.Pool(multiprocessing.cpu_count())
  threads = {}
  
  for cmpPath, oldValues in sorted(oldContent.iteritems()):
    print '\nComparing component:', getCmpFromPath(cmpPath), '\n'
      
    if not diffs.has_key(cmpPath):
      diffs[cmpPath]   = {}
      threads[cmpPath] = {}
    
    if newContent.has_key(cmpPath):
      newValues = newContent[cmpPath]
      
      if args.showall:
        diffs[cmpPath] = getProjectContent( cmpPath, newValues.revision )

      diffs[cmpPath].update( getProjectDiff( cmpPath, oldValues.revision, newValues.revision ) )

      if args.filter:
        diffs[cmpPath] = filterMembers(diffs[cmpPath])

      if args.calcDiff:
        if args.useMultiProcessing:
          for member, item in diffs[cmpPath].iteritems():
            current = pool.apply_async( func=calcRatio, args=(member, item, args.oldRoot, args.newRoot, args.complexRatio) )
            threads[cmpPath][member] = current

        else:
          for member, item in diffs[cmpPath].iteritems():
            print "Getting ratio for file", os.path.basename(member)
            ratio = calcRatio(member, item, args.oldRoot, args.newRoot, args.complexRatio)
            diffs[cmpPath][member].ratio = ratio
  
  pool.close()
  
  for cmpPath, subThreads in threads.iteritems():
    for member, thread in subThreads.iteritems():
      print "Getting ratio for file", os.path.basename(member)
      try:
        ratio = thread.get(timeout = float(args.timeout))
      except:
        ratio = calcRatio( member, item, args.oldRoot, args.newRoot, False )
      diffs[cmpPath][member].ratio = ratio
  
  if os.path.exists(xlsName):
    os.remove(xlsName)

  workbook = xlwt.Workbook()
  worksheets = {}

  for cmpPath, oldValues in sorted(oldContent.iteritems()):
    cmp = getCmpFromPath(cmpPath)

    if not worksheets.has_key(cmp):
      worksheets[cmp] = workbook.add_sheet(cmp)
      worksheets[cmp].last_used_row = -1

    worksheet = worksheets[cmp]

    if newContent.has_key(cmpPath):
      newValues = newContent[cmpPath]
      write_row( worksheet, ['Old overall checkpoint', 'Old component checkpoint', 'New overall checkpoint', 'New component checkpoint'], xlwt.Style.easyxf('font: bold True') )
      write_row( worksheet, [oldName, oldValues.label, newName, newValues.label if (newValues.label != oldValues.label) else 'same'] )

      generateOutput(worksheet, diffs[cmpPath], oldValues, newValues)
    else:
      worksheet.write( worksheet.last_used_row + 1, 0, cmp.upper() + ' is not part of ' + newName )

  for cmpPath in sorted(newContent.keys()):
    if not oldContent.has_key(cmpPath):
      cmp = getCmpFromPath(cmpPath)

      if not worksheets.has_key(cmp):
        worksheets[cmp] = workbook.add_sheet(cmp)

      worksheet = worksheets[cmp]
      worksheet.write( worksheet.last_used_row + 1, 0, cmp.upper() + ' is not part of ' + oldName )

  for worksheet in worksheets.itervalues():
    for i in range(4):
      worksheet.col(i).width = 256*40

  workbook.save(xlsName)

argParser = argparse.ArgumentParser(description =
"""
Compare different Algo checkpoints which might be located in different projects.

e.g.:

compare_algo_cps.py /nfs/projekte1/PROJECTS/ARS400/06_Algorithm AL_ARS4T0_01.05.01_INT-31 /nfs/projekte1/PROJECTS/MFC400/06_Algorithm AL_MFC4T0_560A_03.05.00_INT06

or:

compare_algo_cps.py /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/EM_EnvironmentModel AL_EM_MFC400_01.10.80_INT-5C /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/EM_EnvironmentModel AL_EM_MFC400_01.13.00_INT-2
""",
formatter_class=argparse.RawTextHelpFormatter)

argParser.add_argument("oldPj", default="", help="Old checkpoint project root path.")
argParser.add_argument("oldCp", default="", help="Old checkpoint label.")
argParser.add_argument("newPj", default="", help="New checkpoint project root path.")
argParser.add_argument("newCp", default="", help="New checkpoint label.")
argParser.add_argument("-ro", "--oldRoot", default="", help="Sandbox location of the old content.")
argParser.add_argument("-rn", "--newRoot", default="", help="Sandbox location of the new content.")
argParser.add_argument("-f", "--filter", action="store_true", default=False, help="Filters files based on a specific ruleset. Used only in specific use-cases.")
argParser.add_argument("-a", "--showall", action="store_true", default=False, help="Shows all files in comparison, including equal revisions.")
argParser.add_argument("-d", "--calcDiff", action="store_true", default=False, help="Estimates the difference ratio between the files (Caution: This is really slow using MKS).")
argParser.add_argument("-c", "--complexRatio", action="store_true", default=False, help="Calculates the difference ratio between the files (Caution: This can be very computational expensive).")
argParser.add_argument("-mp", "--useMultiProcessing", action="store_true", default=False, help="Make use of multiprocessing for file comparison.")
argParser.add_argument("-t", "--timeout", default=10, help="Timeout for complex ratio calculation using multiprocessing. Fallback: Ratio is estimated. Default: 10 s.")

args = argParser.parse_args()

def main():
  if not 'Integrity\\IntegrityClient' in os.environ['Path']:
    print 'The path to the MKS binaries must be part of your \'Path\' environment variable'
    sys.exit()

  if args.oldPj.endswith('.pj'):
    args.oldPj = os.path.dirname(args.oldPj)
  elif args.oldPj.endswith('/'):
    args.oldPj = args.oldPj[:-1]

  oldPjSource = args.oldPj + '/04_Engineering/01_Source_Code/algo/project.pj'
  oldPjCustom = args.oldPj + '/04_Engineering/01_Source_Code/algo/00_Custom/project.pj'

  if args.newPj.endswith('.pj'):
    args.newPj = os.path.dirname(args.newPj)
  elif args.newPj.endswith('/'):
    args.newPj = args.newPj[:-1]

  newPjSource = args.newPj + '/04_Engineering/01_Source_Code/algo/project.pj'
  newPjCustom = args.newPj + '/04_Engineering/01_Source_Code/algo/00_Custom/project.pj'

  collectAllComponentsInRepo()

  oldContent      = collectComponentsAndPaths( oldPjSource, args.oldCp )
  oldContent.update(collectComponentsAndPaths( oldPjCustom, args.oldCp ))

  newContent      = collectComponentsAndPaths( newPjSource, args.newCp )
  newContent.update(collectComponentsAndPaths( newPjCustom, args.newCp ))

  compareContents( args.oldCp, oldContent, args.newCp, newContent )

if __name__ == "__main__":
  main()
