"""
Filename                  :  scons_adas_extensions\help_menu.py
Description               :  Script that contains functions for the creation of a help menu.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: help_menu.py
#
# DESCRIPTION: Script that contains functions for the creation of a help menu.
#
# INITIAL AUTHOR: Fischer-EXT, Andre (uidg5297)
#
# CREATION DATE: - 2014/10/07
#
# LAST CHANGE:      $Date: 2021/12/13 19:03:55CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: help_menu.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:55CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.7 2016/05/27 11:49:25CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.6 2015/06/26 05:17:44CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 5:17:44 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

import os

PATH_SEPARATOR = ":"

TARGET_INDENTATION_DEPTH = 2
SUBSEQUENT_DESCRIPTION_LINES_INDENTATION_OFFSET = 3

ROOT_TARGET_NAME = "root"

class AliasInfo(object):
    def __init__(self, alias, tree_pos = "", descriptions = []):
        """
        Function                   :  __init__
        Description                :  Constructor.
        alias                      :  Name of the Alias.
        tree_pos                   :  Position of the alias.
        descriptions               :  Description of the alias.
        Returns                    :  
        """
        self.alias = alias
        self.tree_pos = tree_pos
        self.descriptions = descriptions
    def __str__(self):
        """
        Function        :  __str__
        Description     :  Contains info of the alias.
        Returns         :  
        """
        return "AliasInfo alias = " + self.alias + " tree_pos = " + self.tree_pos + " descriptions: " + str(self.descriptions)
        
class TargetInformation(object):
    """ Instances represent build targets """
    def __init__(self, tree_pos):
        """
        Function              :  __init__
        Description           :  Constructor.
        tree_pos              :  Position of the alias.
        Returns               :  
        """
        self.tree_pos = tree_pos
        self.alias = ""
        self.descriptions = []
        self.children = {}

    def __str__(self):
        """
        Function        :  __str__
        Description     :  Contains info of target.
        Returns         :  
        """
        return "TargetInformation[name = " + self.alias + "; description = " + str(len(self.descriptions)) \
               + "; children = " + str(len(self.children))  + "; fullPath = " + self.tree_pos + "]"


def collectTargetInformation(aliasInfos, rootTarget):
    """
    Function                :  collectTargetInformation
    Description             :  Collect info of the target.
    aliasInfos              :  Info of the Alias.
    rootTarget              :  
    Returns                 :  
    """
    for aliasInfo in aliasInfos:
        tree_pos = aliasInfo.tree_pos
        if not tree_pos:
            continue

        pathList = tree_pos.split(PATH_SEPARATOR)
        currentTarget = rootTarget
        for currentPath in pathList:
            if currentPath in currentTarget.children.keys():
                currentTarget = currentTarget.children[currentPath]
            else:
                newTarget = TargetInformation(tree_pos)
                currentTarget.children[currentPath] = newTarget
                currentTarget = newTarget
        currentTarget.alias = aliasInfo.alias
        currentTarget.descriptions = aliasInfo.descriptions
        if not currentTarget.descriptions:
            currentTarget.descriptions = [""]


def traverseTargets(rootTarget, operation):
    """
    Function               :  traverseTargets
    Description            :  Traverses over the hierarchy of build targets specified by the rootTarget and performs the
                              operation on every TargetInformation object.
    rootTarget             :  A TargetInformation object specifying the hierarchy to traverse.
    operation              :  Operation to be performed for every TargetInformation object.
    Returns                :  
    """
    def doTraverseTargets(rootTarget, level, operation):
        """
        Function               :  doTraverseTargets
        Description            :  Traverses over the hierarchy of build targets specified by the rootTarget and performs the
                                  operation on every TargetInformation object.
        rootTarget             :  A TargetInformation object specifying the hierarchy to traverse.
        level                  :  Current hierarchy level.
        operation              :  Operation to be performed for every TargetInformation object.
        Returns                :  
        """
        if rootTarget.children:
            operation(rootTarget, level)
            sortedChildrenList = sorted(list(rootTarget.children.values()), key=lambda target:target.alias)
            for currentTarget in sortedChildrenList:
                doTraverseTargets(currentTarget, level + 1, operation)
        else:
            operation(rootTarget, level)


    sortedChildrenList = sorted(list(rootTarget.children.values()), key=lambda target:target.alias)
    for currentTarget in sortedChildrenList:
        doTraverseTargets(currentTarget, 0, operation)


def printAllTargets(rootTarget, maxTargetWidth):
    """
    Function                    :  printAllTargets
    Description                 :  Print all the targets of the help menu.
    rootTarget                  :  Root target.
    maxTargetWidth              :  Max width of the target.
    Returns                     :  
    """
    """ Prints all targets. """
    f = open('aliases.txt', 'w')
    def printTargetName(target, level):
        """
        Function           :  printTargetName
        Description        :  
        target             :  
        level              :  
        Returns            :  
        """
        print >>f, " " * (TARGET_INDENTATION_DEPTH * level), target.alias,#, end=""


    def printTargetDescription(target, level):
        """
        Function           :  printTargetDescription
        Description        :  Contains the description of the target.
        target             :  Target to be executed.
        level              :  Current hierarchy level.
        Returns            :  
        """
        for i, description in enumerate(target.descriptions):
            if i == 0:
                print >>f, " " * (maxTargetWidth - TARGET_INDENTATION_DEPTH * level - len(target.alias)), "> " + description 
            else:
                print >>f, " " * (maxTargetWidth + SUBSEQUENT_DESCRIPTION_LINES_INDENTATION_OFFSET), description 

    def printTargetInformation(target, level):
        """
        Function           :  printTargetInformation
        Description        :  
        target             :  
        level              :  
        Returns            :  
        """
        if target.alias:
            printTargetName(target, level)
            printTargetDescription(target, level)


    traverseTargets(rootTarget, printTargetInformation)
    f.close()


def calculateMaxTargetWidth(rootTarget):
    """
    Function               :  calculateMaxTargetWidth
    Description            :  Calculates the maximum width of the target name including indentation.
    rootTarget             :  
    Returns                :  
    """
    """  Calculates the maximum width of the target name including indentation """
    def checkMaxTargetWidth(target, level):
        """
        Function           :  checkMaxTargetWidth
        Description        :  Calculates the maximum width of the target name including indentation.
        target             :  Target to be executed.
        level              :  Current hierarchy level.
        Returns            :  
        """
        #nonlocal maxTargetWidth
        maxTargetWidth["value"] = max((maxTargetWidth["value"], len(target.alias) + TARGET_INDENTATION_DEPTH * level))

    maxTargetWidth = {"value" : 0}
    traverseTargets(rootTarget, checkMaxTargetWidth)
    return maxTargetWidth["value"]

    
# generalized Alias-function compared to the one provided by scons itself:
# In addition to the Alias itself, information about its position in the 
# hierarchy and some help information text can be included
def generate_alias(alias, target, tree_pos = '', descriptions = []):
    """
    Function                   :  generate_alias
    Description                :  Generate a new Alias.
    alias                      :  Name of the Alias.
    target                     :  Target to be executed on invoking of the Alias.
    tree_pos                   :  Position of the alias.
    descriptions               :  Description of the alias.
    Returns                    :  
    """
    Alias(alias, target)
    if not tree_pos == '':
        help_dict[alias] = AliasInfo(alias, tree_pos, descriptions)
    
def create_help_menu():
    """
    Function        :  create_help_menu
    Description     :  Generate the help menu.
    Returns         :  
    """
    root_target = TargetInformation(ROOT_TARGET_NAME)
    root_target.alias = ROOT_TARGET_NAME
    collectTargetInformation(help_dict.values(), root_target)
    maxTargetWidth = calculateMaxTargetWidth(root_target)
    printAllTargets(root_target, maxTargetWidth)
    
    