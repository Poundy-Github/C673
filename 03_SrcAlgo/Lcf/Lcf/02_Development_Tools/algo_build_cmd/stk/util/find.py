"""
stk/util/find.py
-------------------

Stand alone utility functions for class searches based on subclassing.


:org:           Continental AG
:author:        Sven Mertens

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:38CET $
"""

# pylint: disable=W0702

# Import Python Modules ----------------------------------------------------------------------------------------------
from os import path as oPath, listdir
from sys import path as sPath
from inspect import ismodule
import traceback

# Functions ----------------------------------------------------------------------------------------------------------


def instantiateClass(baseClass, search, *args, **kwargs):
    """uses findClass to search first for relevant classes, next to it uses
    first found and instantiates it and if available calling Initialize method.
    This is good to search for BaseDB related DB classes based upon SQLite or Oracle based.
    for a short test see the unit test under test_util/test_find.py.

    Additional parameters (*args, **kwargs) will be pushed through to class which will be
    instantiated and returned.

    :param baseClass: find the class based on, e.g. stk.db.cl.SQLite3BaseDB
    :param search: could be path e.g. "stk\\db\\cl" or module, e.g. stk.db.cl
    :return: instance of found class, already initialized
    """
    cls = findClass(baseClass, search, kwargs.get('removeDuplicates', True))
    kwargs.pop('removeDuplicates', None)
    mod = cls[0]['type'](*args, **kwargs)
    if hasattr(mod, 'Initialize'):
        mod.Initialize()
    return mod


def findClass(baseClass, search, removeDuplicates=True, with_error_list=False):  # pylint: disable=R0912,R0915
    """Returns the classes found under search(path(s)) based upon baseClass as list of dict.
    Dictionary contains the type and name of the item found.
    removeDuplicates indicates whether to remove found duplicates.
    If wanted it also returns the list of errors raised during the imports of the modules

    :param baseClass: class name to search for
    :param search: path(s) or file(s) (string or list of strings) or module object (already imported) /
                   list of modules to search inside
    :param removeDuplicates: removes duplicates found, default: True
    :param with_error_list: returns additional list of errors raised during module import, default: False
    :return: list of dict of candidates found: [{'type': ..., 'name': ...}, ...]
    """
    # recursive call to 'unpack' lists of paths or modules:
    if type(search) == list:
        if with_error_list:
            clist = []
            elist = []
            for i in search:
                ctmp, etmp = findClass(baseClass, i, removeDuplicates, True)
                clist.extend(ctmp)
                elist.extend(etmp)
            return (clist, elist)
        else:
            classlist = []
            for entry in search:
                found = findClass(baseClass, entry, removeDuplicates)
                classlist.extend(found)
            return classlist
    # for single path, file or module continue here:

    # return already imported module (module != file), mainly used in stk.db
    if ismodule(search):
        return (findEntry(baseClass, search), []) if with_error_list else findEntry(baseClass, search)

    modList = []
    errList = []

    folder = search
    try:
        files = listdir(folder)
    except Exception as ex:  # pylint: disable=W0703
        # if listdir was called with file name:
        if oPath.exists(search):
            files = [oPath.basename(search)]
            folder = oPath.dirname(search)
        else:
            # otherwise search was a not readable entry or empty resp. None
            # if needed classes were found in other paths/files then valf can continue, otherwise
            # to let valf on HPC close correctly we return logging that error
            print("ERROR: '%s' (path not existing: %s)" % (str(ex), folder))
            return ([], ["ERROR on %s: '%s'" % (search, str(ex))]) if with_error_list else []

    # For all modules within the stk use absolute module path to
    # avoid problems with duplicate package names
    lst = []
    fpath = folder
    modPath = ""

    while True:
        head, tail = oPath.split(fpath)

        if tail == '':
            if head != '':
                lst.insert(0, head)
            break
        else:
            lst.insert(0, tail)
            if tail == 'stk':
                modPath += ".".join(lst) + "."
                break
            fpath = head

    # now find the files inside
    for fileName in files:
        if (not fileName.startswith("__")) and fileName.endswith(".py"):
            modName = fileName.rsplit('.', 1)[0]
            if modPath == "":
                if folder not in sPath:
                    sPath.append(folder)
                modList.append(modName)
            else:
                # add stk path to module name
                modList.append([modPath + modName, modName])

    # try to import and check internals
    plugList = []
    for modName in modList:
        try:
            # use relative or absolute (for all stk modules) import method
            if isinstance(modName, (list, tuple)):
                module = __import__(modName[0], globals(), locals(), modName[1], 0)
            else:
                module = __import__(modName)
        except StandardError:
            errList.append((modName, traceback.format_exc()))
            continue

        plugList.extend(findEntry(baseClass, module))
        try:
            del module
        except:
            pass

    if removeDuplicates and len(plugList) > 1:
        dups = []
        for idx0 in range(0, len(plugList)):
            for idx1 in range(idx0 + 1, len(plugList)):
                if plugList[idx0]["name"] == plugList[idx1]["name"]:
                    dups.append(idx1)

        for idx in sorted(set(dups), reverse=True):
            plugList.pop(idx)

    return plugList if not with_error_list else (plugList, errList)


def findEntry(baseClass, module):
    """iterator through that module to search for baseClass,
    used by findClass function

    :param baseClass: class name to search for
    :param module: module to search for
    :return: list of pluggable interfaces (classes)
    """
    plugs = []
    for className, entry in module.__dict__.items():
        try:
            if entry is None or str(entry).find("PyQt4") >= 0:
                continue

            if issubclass(entry, baseClass) and entry != baseClass:
                # self.__logger.debug("Found plugin.[Module: '%s', Class: '%s']." % (module_name, class_name))
                plugs.append({"type": entry, "name": className})
        except TypeError:
            # this happens when a non-type is passed in to issubclass. We
            # don't care as it can't be a subclass of PluginInterface if
            # it isn't a type
            continue
    return plugs

"""
CHANGE LOG:
-----------
$Log: find.py  $
Revision 1.1 2021/12/13 17:59:38CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/util/project.pj
Revision 1.6 2013/11/22 15:45:56CET Hospes, Gerd-Joachim (uidv8815) 
fixed list of paths/files, logging error for unreadable entries, expand test suite to check lists
- Added comments -  uidv8815 [Nov 22, 2013 3:45:56 PM CET]
Change Package : 207698:1 http://mks-psad:7002/im/viewissue?selection=207698
Revision 1.5 2013/10/01 15:05:22CEST Hospes, Gerd-Joachim (uidv8815)
internal list adaption to simple format, '-->' added during output
--- Added comments ---  uidv8815 [Oct 1, 2013 3:05:23 PM CEST]
Change Package : 196951:1 http://mks-psad:7002/im/viewissue?selection=196951
Revision 1.4 2013/10/01 14:21:16CEST Hospes, Gerd-Joachim (uidv8815)
FR199155: fix error msg for observer load problems
--- Added comments ---  uidv8815 [Oct 1, 2013 2:21:16 PM CEST]
Change Package : 196951:1 http://mks-psad:7002/im/viewissue?selection=196951
Revision 1.3 2013/06/21 14:24:53CEST Mertens, Sven (uidv7805)
findClass returns instance when searching for module instead of list of dict.
adding new function to search and doing the instance actually.
--- Added comments ---  uidv7805 [Jun 21, 2013 2:24:53 PM CEST]
Change Package : 185933:1 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.2 2013/06/13 15:26:01CEST Mertens, Sven (uidv7805)
fix: adaptation for single file as search argument
--- Added comments ---  uidv7805 [Jun 13, 2013 3:26:01 PM CEST]
Change Package : 185933:3 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.1 2013/05/23 06:28:03CEST Mertens, Sven (uidv7805)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/
    stk/util/project.pj
"""
