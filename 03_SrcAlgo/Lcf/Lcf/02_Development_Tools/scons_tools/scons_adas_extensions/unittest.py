"""
Filename                  :  scons_adas_extensions\unittest.py
Description               :  Script that setup the environment for unit test.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: unittest.py
#
# DESCRIPTION: Script that setup the environment for unit test.
#
# INITIAL AUTHOR: Spruck, Jochen (spruckj)
#
# CREATION DATE: - 2013/01/29
#
# LAST CHANGE:      $Date: 2021/12/13 19:04:01CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: unittest.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:04:01CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.5 2016/05/27 14:34:30CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.4 2015/06/26 05:17:39CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 5:17:39 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

# Taken from SCons wiki.
# Chris Winstanley September 2012 - tweaked to allow specification of unittest
#                                   alias via parameter. Added os.path.basename
#                                   to ensure individual unit test aliases
#                                   are a single name, not a path.
#                                   Added chdir to builder to ensure output
#                                   files created by running the tests are
#                                   output to the build directory.  

import os
def unitTestAction(target, source, env):
        """
        Function            :  unitTestAction
        Description         :  
        target              :  
        source              :  
        env                 :  
        Returns             :  
        """
        '''
        Action for a 'UnitTest' builder object.
        Runs the supplied executable.
        When the test succeeds, the file target.passed is created to indicate
	that the test was successful and doesn't need running again unless
	dependencies change.
        '''
        app = str(source[0].abspath)
        if os.spawnle(os.P_WAIT, app, app, env['ENV'])==0:
		try:
		    print "Writing "+os.path.basename(str(target[0]))
                    passedFile = open(os.path.basename(str(target[0])),'w')
		except:
		    print "Can't write "+ os.path.basename(str(target[0]))
		else:
                    passedFile.write("PASSED\n")


def unitTestActionString(target, source, env):
        """
        Function            :  unitTestActionString
        Description         :  
        target              :  
        source              :  
        env                 :  
        Returns             :  
        """
        '''
        Return output string which will be seen when running unit tests.
        '''
        return 'Running tests in ' + str(source[0])

def addUnitTest(env, target=None, source=None, alias='unittests', *args, **kwargs):
        """
        Function              :  addUnitTest
        Description           :  
        env                   :  
        target                :  
        source                :  
        alias                 :  
        *args                 :  
        **kwargs              :  
        Returns               :  
        """
        '''
        Add a unit test
        Parameters:
                target - If the target parameter is present, it is the name of the test
                                executable
                source - list of source files to create the test executable.
                any additional parameters are passed along directly to env.Program().
        Returns:
                The scons node for the unit test.
        Any additional files listed in the env['UTEST_MAIN_SRC'] build variable are
        also included in the source list.
        All tests added with addUnitTest can be run with the test alias:
                "scons unittests"
        Any test can be run in isolation from other tests, using the name of the
        test executable provided in the target parameter:
                "scons target"
        '''
        if source is None:
                source = target
                target = None
        source = [source, env['UTEST_MAIN_SRC']]
        program = env.Program(target, source, *args, **kwargs)
        utest = env.UnitTest(program)
        # add alias to run all unit tests.
        env.Alias(alias, utest)
        # make an alias to run the test in isolation from the rest of the tests.
        env.Alias(os.path.basename(target)+"_ut", utest)
        return [program, utest]

#-------------------------------------------------------------------------------
# Functions used to initialize the unit test tool.
def generate(env, UTEST_MAIN_SRC=[], LIBS=[]):
    """
    Function                    :  generate
    Description                 :  Standard SCons function.
    env                         :  Environment variable.
    UTEST_MAIN_SRC              :  
    LIBS                        :  
    Returns                     :  
    """
    env['BUILDERS']['UnitTest'] = \
        env.Builder(action = env.Action(unitTestAction, unitTestActionString),
                    suffix='.passed',
                    chdir=1)
    env['UTEST_MAIN_SRC'] = UTEST_MAIN_SRC
    env.AppendUnique(LIBS=LIBS)

    try:
        env.AddMethod(addUnitTest, "addUnitTest")
    except AttributeError:
        # The following is a bit of a nasty hack to add a wrapper function for the
        # UnitTest builder, see http://www.scons.org/wiki/WrapperFunctions
        from SCons.Script.SConscript import SConsEnvironment
        SConsEnvironment.addUnitTest = addUnitTest

def exists(env):
    """
    Function        :  exists
    Description     :  Standard SCons function.
    env             :  Environment variable.
    Returns         :  
    """
    return 1
