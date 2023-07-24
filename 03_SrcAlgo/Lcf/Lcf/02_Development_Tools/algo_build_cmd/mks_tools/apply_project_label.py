from CLI_tools import cli_proc_handler
import argparse

subprojects = {}


def joinMksPath(root, path):
    if (root[-11:] == '/project.pj'):
        if (path[-11:] == '/project.pj'):
            return root[:-10] + path
        else:
            print "Error: path is wrong: " + path
    else:
        print "Error: root is wrong: " + root


def addProjectLabelRecursive(projects, label):
    global subprojects

    cliProcHandler = cli_proc_handler()

    for project, revision in projects.iteritems():
        cmd = "si addprojectlabel --project=" + project + "  --projectRevision=" + revision + " --label=" + label + ' -Y'
        cliProcHandler.SiCLIHandler_wait(cmd)

        cmd = "si viewproject -N --filter=file:*.pj --project=" + project + " --projectrevision=" + revision
        cliProcHandler.SiCLIHandler_wait(cmd)

        localSubprojects = {}
        lines = ret.splitlines()
        for line in lines:
            lnsplt = line.split()
            if (len(lnsplt) == 4):
                if lnsplt[2] == 'build-subproject':
                    localSubprojects[joinMksPath(project, lnsplt[0])] = lnsplt[3]
            else:
                print "Warning: something was wrong with " + "".join(lnsplt)

        addProjectLabelRecursive(localSubprojects, label)
        subprojects.update(localSubprojects)


def delProjectLabelRecursive(projects, label):
    global subprojects

    cliProcHandler = cli_proc_handler()

    for project, revision in projects.iteritems():
        cmd = "si deleteprojectlabel --project=" + project + "  --projectRevision=" + revision + " --label=" + label + ' -Y'
        cliProcHandler.SiCLIHandler_wait(cmd)

        cmd = "si viewproject -N --filter=file:*.pj --project=" + project + " --projectrevision=" + revision
        cliProcHandler.SiCLIHandler_wait(cmd)
        lines = cliProcHandler.getstdout_split()

        localSubprojects = {}
        for line in lines:
            lnsplt = line.split()
            if (len(lnsplt) == 4):
                if lnsplt[2] == 'build-subproject':
                    localSubprojects[joinMksPath(project, lnsplt[0])] = lnsplt[3]
            else:
                print "Warning: something was wrong with " + "".join(lnsplt)

        delProjectLabelRecursive(localSubprojects, label)
        subprojects.update(localSubprojects)


def main():
    global subprojects

    # get arguments
    argParser = argparse.ArgumentParser(description='Manages project and member labels recursively',
                                        formatter_class=argparse.RawTextHelpFormatter)
    argParser.add_argument("project", help="Path to project")
    argParser.add_argument("revision", help="Revision")
    argParser.add_argument("label", help="Label to be added / removed")
    argParser.add_argument("--action", choices=['add', 'del'], default='add',
                           help="Specify what action to perform. Default: %(default)s")

    args = argParser.parse_args()

    PROJECT_PATH = {args.project: args.revision}

    if args.action == 'add':
        addProjectLabelRecursive(PROJECT_PATH, args.label)
    elif args.action == 'del':
        delProjectLabelRecursive(PROJECT_PATH, args.label)
    else:
        print "Error: Can't handle action '%s'" % args.action
        exit(1)

    print "Subprojects labelled:"
    print subprojects


if __name__ == "__main__":
    main()
