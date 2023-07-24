"""
trie
-------------

documentation of trie
docu docu

:org:           Continental AG
:author:        Sven Mertens

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:39CET $
"""

# Import Python Modules -----------------------------------------------------------------------------------------------

# TODO: implementation of a save and a load method (json?)
# next question: what to support: txt / xml / etc ?


class CTrie():
    """Tree implementation initiated by use case validation sets
    """
    def __init__(self, ident, parent, value):
        """
        constraint trie implementation
        :param ident: constraint (/ set) ID
        :param parent: parent id
        :param value: initial value
        """
        self.kids = []
        self.parent = parent
        self.ident = ident
        self.value = list(value) if isinstance(value, tuple) else value
        # TODO: appendValue only works for lists! - so if you want to use that method, value must always be list
        #self.value = list(value) if isinstance(value, tuple) else [value]
        self.result = None

    def addKid(self, kidID, parent, value):
        """
        adds a kid underneath parent with value
        :param kidID: new ID of kid
        :param parent: parent ID
        :param value: kid value
        :return: True / False
        """
        if parent == self.ident:
            self.kids.append(CTrie(kidID, parent, value))
            return True

        for kk in self.kids:
            if kk.addKid(kidID, parent, value):
                return True
        return False

    def appendValue(self, kidID, value):
        """
        appends value to a kid by ID
        :param kidID: kid ID
        :param value: value to add to existing
        :return: True / False
        """
        # TODO: why not appending value to kid with sub-kids?
        #if len(self.kids) == 0 and self.ident == kidID:
        if self.ident == kidID:
            self.value.append(value)
            return True

        for kk in self.kids:
            if kk.appendValue(kidID, value):
                return True
        return False

    def kidValue(self, kidID):
        """
        :param kidID: kid ID to search for
        :return: value of kid
        """
        if len(self.kids) == 0 and self.ident == kidID:
            return self.value

        for kk in self.kids:
            vv = kk.kidValue(kidID)
            if vv is not None:
                return vv
        return None

    def kidResult(self, kidID):
        """
        :param kidID: kid ID to search for
        :return: result of kid
        """
        # if len(self.kids) == 0 and self.ident == kidID:
        if self.ident == kidID:
            return self.result

        for kk in self.kids:
            vv = kk.kidResult(kidID)
            if vv is not None:
                return vv
        return None

    def evalKids(self, func):
        """evaluate the value by using func.
        Result(s) saved to local variable result.
        :param func: evaluation function
        """
        # how to prevent endless loop?
        #if len(self.kids) == 0:
        #self.result = func(self.value)
        #else:
        for kk in self.kids:
            kk.evalKids(func)

        #put it to end, so first eval kids
        self.result = func(self)

    def evalResults(self, func):
        """evaluate the results by using func.
        :param func: evaluation function
        :return: func result
        """
        '''
        #returning this value will not check kids
        # TODO: evalResults not needed any more?
        if self.result is not None:
            return self.result
        '''
        res = []
        res.append(self.result)
        for kk in self.kids:
            res.append(kk.evalResults(func))

        # return func[self.value[0]['Operant']](res)
        return func[self.value](res)

    @property
    def allKidIDs(self):
        """
        :return: ID's of only kids
        """
        #TODO: why returning ident if no kid? so you never know what you get!
        '''
        if len(self.kids) == 0:
            return [self.ident]
        '''

        ids = []
        for kk in self.kids:
            ids.append(kk.ident)
            ids.extend(kk.allKidIDs)
        return ids

    @property
    def allIDs(self):
        """
        :return: all sub ID's
        """
        ids = [self.ident]
        for kk in self.kids:
            ids.extend(kk.allIDs)
        return ids

    @property
    def values(self):
        """
        :return: list of [kid, value] (list of lists)
        # TODO: why only values of kids?
        """
        vals = []
        # for kk in self.allKidIDs:
        '''
        for kk in self.allIDs:
            vv = [kk]
            vv.append(self.kidValue(kk))
            vals.append(vv)
        '''

        vals.append([self.ident, self.value])

        for kk in self.kids:
            vals.extend(kk.values)

        return vals

"""
CHANGE LOG:
-----------
$Log: trie.py  $
Revision 1.1 2021/12/13 17:59:39CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/util/project.pj
Revision 1.9 2013/11/29 16:41:02CET Skerl, Anne (uid19464) 
*pep8
- Added comments -  uid19464 [Nov 29, 2013 4:41:03 PM CET]
Change Package : 198254:3 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.8 2013/11/29 15:12:05CET Skerl, Anne (uid19464)
*changes for module test: add methode kidResult(), bugfixes values(), evalResults()
--- Added comments ---  uid19464 [Nov 29, 2013 3:12:06 PM CET]
Change Package : 198254:3 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.7 2013/11/26 19:11:22CET Skerl, Anne (uid19464)
*change: appendValue, evalKids, evalResults, allKidIDs
--- Added comments ---  uid19464 [Nov 26, 2013 7:11:22 PM CET]
Change Package : 198254:2 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.6 2013/04/03 08:02:15CEST Mertens, Sven (uidv7805)
pylint: minor error, warnings fix
--- Added comments ---  uidv7805 [Apr 3, 2013 8:02:16 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.5 2013/03/22 08:24:25CET Mertens, Sven (uidv7805)
aligning bulk of files again for peping 8
Revision 1.4 2013/03/06 10:21:23CET Mertens, Sven (uidv7805)
done, pep8 styling
--- Added comments ---  uidv7805 [Mar 6, 2013 10:21:24 AM CET]
Change Package : 176171:7 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.3 2013/03/01 10:29:41CET Mertens, Sven (uidv7805)
bugfixing STK imports
--- Added comments ---  uidv7805 [Mar 1, 2013 10:29:42 AM CET]
Change Package : 176171:2 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.2 2013/02/28 17:09:53CET Mertens, Sven (uidv7805)
initial version of constraint related classes
--- Added comments ---  uidv7805 [Feb 28, 2013 5:09:54 PM CET]
Change Package : 176171:1 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.1 2013/02/21 12:42:48CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/
    stk/util/project.pj
"""
