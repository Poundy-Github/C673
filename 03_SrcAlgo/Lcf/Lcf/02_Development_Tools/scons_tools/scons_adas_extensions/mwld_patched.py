"""SCons.Tool.mwld
Filename                  :  scons_adas_extensions\mwld_patched.py

Tool-specific initialization for the Metrowerks CodeWarrior linker.

There normally shouldn't be any need to import this module directly.
It will usually be imported through the generic SCons.Tool.Tool()
selection method.
"""

#
# Copyright (c) 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010 The SCons Foundation
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
# KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
# WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#

__revision__ = "src/engine/SCons/Tool/mwld.py 4720 2010/03/24 03:14:11 jars"

import SCons.Tool


def generate(env):
    """
    Function        :  generate
    Description     :  
    env             :  
    Returns         :  
    """
    """Add Builders and construction variables for lib to an Environment."""
    SCons.Tool.createStaticLibBuilder(env)
    SCons.Tool.createSharedLibBuilder(env)
    SCons.Tool.createProgBuilder(env)

    env['AR'] = 'mwldeppc'
    env['ARCOM'] = '$AR $ARFLAGS -library -o $TARGET $SOURCES'

    env['LIBDIRPREFIX'] = '-L'
    env['LIBDIRSUFFIX'] = ''
    env['LIBLINKPREFIX'] = '-l'
    env['LIBLINKSUFFIX'] = '.a'
    env['LIBSUFFIXES']=[".a"]
    env['LIBPREFIXES']=[""]
    env['LIBSUFFIX']=".a"
    env['LIBPREFIX']=""

    env['LINK'] = 'mwldeppc'
    env['LINKCOM'] = '$LINK $LINKFLAGS -o $TARGET $SOURCES $_LIBDIRFLAGS $_LIBFLAGS'

    env['SHLINK'] = '$LINK'
    env['SHLINKFLAGS'] = '$LINKFLAGS'
    env['SHLINKCOM']   = shlib_action
    env['SHLIBEMITTER']= shlib_emitter


def exists(env):
    """
    Function        :  exists
    Description     :  
    env             :  
    Returns         :  
    """
    import SCons.Tool.mwcc
    return SCons.Tool.mwcc.set_vars(env)


def shlib_generator(target, source, env, for_signature):
    """
    Function                   :  shlib_generator
    Description                :  
    target                     :  
    source                     :  
    env                        :  
    for_signature              :  
    Returns                    :  
    """
    cmd = ['$SHLINK', '$SHLINKFLAGS', '-shared']

    no_import_lib = env.get('no_import_lib', 0)
    if no_import_lib: cmd.extend('-noimplib')

    dll = env.FindIxes(target, 'SHLIBPREFIX', 'SHLIBSUFFIX')
    if dll: cmd.extend(['-o', dll])

    implib = env.FindIxes(target, 'LIBPREFIX', 'LIBSUFFIX')
    if implib: cmd.extend(['-implib', implib.get_string(for_signature)])

    cmd.extend(['$SOURCES', '$_LIBDIRFLAGS', '$_LIBFLAGS'])

    return [cmd]


def shlib_emitter(target, source, env):
    """
    Function            :  shlib_emitter
    Description         :  
    target              :  
    source              :  
    env                 :  
    Returns             :  
    """
    dll = env.FindIxes(target, 'SHLIBPREFIX', 'SHLIBSUFFIX')
    no_import_lib = env.get('no_import_lib', 0)

    if not dll:
        raise SCons.Errors.UserError, "A shared library should have exactly one target with the suffix: %s" % env.subst("$SHLIBSUFFIX")

    if not no_import_lib and \
       not env.FindIxes(target, 'LIBPREFIX', 'LIBSUFFIX'):

        # Append an import library to the list of targets.
        target.append(env.ReplaceIxes(dll,
                                      'SHLIBPREFIX', 'SHLIBSUFFIX',
                                      'LIBPREFIX', 'LIBSUFFIX'))

    return target, source


shlib_action = SCons.Action.Action(shlib_generator, generator=1)

# Local Variables:
# tab-width:4
# indent-tabs-mode:nil
# End:
# vim: set expandtab tabstop=4 shiftwidth=4:
