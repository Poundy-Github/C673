
import os
import re
from SCons.Platform.posix import exitvalmap 

def exec_spawn(l, env):
    try:
        result = os.spawnve(os.P_WAIT, l[0], l, env)
    except OSError, e:
        try:
            result = exitvalmap[e[0]]
            sys.stderr.write("scons: %s: %s\n" % (l[0], e[1]))
        except KeyError:
            result = 127
            if len(l) > 2:
                if len(l[2]) < 1000:
                    command = ' '.join(l[0:3])
                else:
                    command = l[0]
            else:
                command = l[0]
            sys.stderr.write("scons: unknown OSError exception code %d - '%s': %s\n" % (e[0], command, e[1]))
    return result

def spawn(sh, escape, cmd, args, env):
    # Check for any special operating system commands
    # cmd == args[0]
    if args[0] == 'del':
        #args[0] = r'C:\Tools\Eclipse\17.4.0\eclipse\x86-win32\bin\rm.exe'
        # Or you could just manually delete them
        import win32file
        for arg in args[1:]:
            win32file.DeleteFile(arg)
        return 0
    # For all args[i] that contains ':' replace '\' with '/'.
    # Maybe do some more checkings to be sure that it is a path and not some weird flag/parameter: use os.path.exists(transformed_path(args[i]))
    # Be careful that some paths can start with '@' (when you use TEMPFILE mechanism),
    # or '"' (path to .rc file) or can contains ':' before the path as a part of a flag (/PDB:file)
    for i, arg in enumerate(args):
        # In Windows just paths contains '\'s so it is pretty safe to replace them with '/' 
        if arg.find(':') != -1:
            args[i] = arg.replace('\\', '/')
    if not sh:
        sys.stderr.write("scons: Could not find command interpreter, is it in your PATH?\n")
        return 127
    return exec_spawn([sh, '-c', escape(' '.join(args))], env)

def exec_spawn(l, env):
    try:
        result = os.spawnve(os.P_WAIT, l[0], l, env)
    except OSError, e:
        try:
            result = exitvalmap[e[0]]
            sys.stderr.write("scons: %s: %s\n" % (l[0], e[1]))
        except KeyError:
            result = 127
            if len(l) > 2:
                if len(l[2]) < 1000:
                    command = ' '.join(l[0:3])
                else:
                    command = l[0]
            else:
                command = l[0]
            sys.stderr.write("scons: unknown OSError exception code %d - '%s': %s\n" % (e[0], command, e[1]))
    return result

