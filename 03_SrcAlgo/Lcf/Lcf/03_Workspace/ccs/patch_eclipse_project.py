"""Parse the SCons scripts and patch the CCS project."""
import argparse
import glob
import os
import fnmatch
import sys
import xml.etree.ElementTree as ElementTree
import copy
import stat

# ----------------------- globals -----------------------


def indent(element, level=0, has_sibling=False):
    """Element is a (top-lvl) element of an ElementTree.

    This function recursively corrects the indentation of
    this element and all its children and strips empty text.
    For a better understanding, here's some ascii art:
      X denotes text, T denotes tail
    <a>X            // text of a
    XXX<b>XXX</b>T  // still text of a, then text of b, then tail of b
    TTT<c>X         // still tail of b, then text of c
    XXX</c>T        // still text of c, then tail of c
    </a>T           // still tail of c (the newline counts :)), then (possibly empty) tail of a.
    """
    indentation = 4 * " "
    same_indent = level * indentation
    less_indent = (level - 1) * indentation
    more_indent = (level + 1) * indentation
    # print "len(" + element.tag + ") = " + str(len(element))
    if len(element):  # if it has subelements (len(element) = num children)
        if not element.text or element.text.strip() == "":
            element.text = "\n" + more_indent
        for sub_element in element[:-1]:
            indent(sub_element, level + 1, True)

        indent(element[-1], level + 1)
    else:
        if not element.text or element.text.strip() == "":
            element.text = None

    element.tail = '\n'
    if level:
        if has_sibling:
            element.tail += same_indent
        else:
            element.tail += less_indent

    return element


class BuildEnvironment:
    """The build environment as specified by Scons.

    Not all of the variables are in here. Some are in public variables.
    """

    def __init__(self):
        """Constructor."""
        self.compiler      = ""
        self.include_paths = set()
        self.files         = set()
        self.defines       = set()
        self.custom_paths  = set()

    def __str__(self):
        """For debugging purposes."""
        str_list = []
        for var in vars(self):
            str_list += [str(var), ":\n"]
            if isinstance(getattr(self, var), set):
                for item in sorted(getattr(self, var)):
                    str_list.append("    ")
                    str_list.append(item)
                    str_list.append("\n")
            elif isinstance(getattr(self, var), basestring):
                str_list.append("    ")
                str_list.append(getattr(self, var))
                str_list.append("\n")
            else:
                return "ERROR\n"
        str_list.append("\n")
        return ''.join(str_list)  # more efficient than string concatenation

    def join(self, other):
        """Join build_envthis BuildEnvironment with another by joining its sets."""
        for var in vars(self):
            # since we are working with sets, we get the union of the sets and the entries will still be unique.
            if isinstance(getattr(self, var), basestring):
                setattr(self, var, '&'.join([getattr(self, var), getattr(other, var)]))
            else:
                setattr(self, var, getattr(self, var) | getattr(other, var))

    def extract_file_folders(self):
        """Return a set of folders that contain all the source files listed in files."""
        result_set = set()
        for f in self.files:
            result_set.add(os.path.dirname(f))
        return result_set


sandbox_root = os.path.abspath(os.path.join(os.path.dirname(os.path.realpath(__file__)), '..', '..', '..'))


class BuildEnvTree:
    """The BuildEnvironment with files and include_paths represented as nested dictionaries."""

    class EnvTreeElement:
        """A single element of the BuildEnvTree."""

        def __init__(self, type=2, name="", virtual=True):
            """Constructor."""
            self.children = {}
            self.name = name
            self.type = type
            self.virtual = virtual

        def to_string(self, strlist, indent=""):
            """Recursive function that returns a list of strings that represents the given EnvTreeElement."""
            for key in sorted(self.children):
                strlist.append(indent + key + ":" + str(self.children[key].type) +
                               (":nv" if not self.children[key].virtual else ":v"))
                self.children[key].to_string(strlist, indent + "    ")
            return strlist

        def __str__(self):
            """Stringify method."""
            str_list = []
            return '\n'.join(self.to_string(str_list))

        def join(self, other):
            """Recursively join this EnvTreeElement with another (e.g. for joining include paths with file paths)."""
            for key, element in other.children.iteritems():
                if key in self.children:
                    self.children[key].virtual = self.children[key].virtual & element.virtual
                    self.children[key].join(element)
                else:
                    self.children[key] = element
            return self

    def convert_set_to_tree(self, path_set, type):
        """Create a path tree from the given path_set."""
        def add_to_node(node, path, type):
            """Add a path to an existing node."""
            path_list = path.split(os.sep)
            for p in path_list[:-1]:
                if not node.virtual:
                    break
                if p not in node.children:
                    node.children[p] = self.EnvTreeElement(2, p, True)
                node = node.children[p]
            if node.virtual:
                if path_list[-1] not in node.children:
                    node.children[path_list[-1]] = self.EnvTreeElement(type, path_list[-1], False)
                else:
                    # leaf nodes are not virtual (there might be files in it, which we want to include automatically)
                    node.children[path_list[-1]].virtual = False
                    # node.children[path_list[-1]].children = {}  # delete possible children

        root = self.EnvTreeElement()
        for path in path_set:
            path = os.path.relpath(path, sandbox_root)
            add_to_node(root, path, type)
        return root

    def __init__(self, build_env):
        """Constructor, that gets a BuildEnvironment."""
        self.compiler      = build_env.compiler
        self.include_paths = self.convert_set_to_tree(build_env.include_paths, 2)
        self.files         = self.convert_set_to_tree(build_env.files, 1)
        self.file_paths    = self.convert_set_to_tree(build_env.extract_file_folders(), 2)
        self.file_paths.join(self.convert_set_to_tree(build_env.custom_paths, 2))
        self.all_paths     = self.file_paths.join(self.include_paths)
        self.defines       = build_env.defines

    def __str__(self):
        """String method."""
        strlist = ["Include Paths:"]
        strlist = self.include_paths.to_string(strlist, "")
        strlist.append("\nFiles:")
        strlist = self.files.to_string(strlist, "")
        strlist.append("\nFiles Paths:")
        strlist = self.file_paths.to_string(strlist, "")
        return '\n'.join(strlist)


vl_scons_scripts = ['04_Engineering/03_Workspace/sw/make/SConscript_arm-m_0',
                    '04_Engineering/03_Workspace/sw/make/SConscript_arm-m_1',
                    '04_Engineering/03_Workspace/sw/make/SConscript_dsp_0',
                    '04_Engineering/03_Workspace/sw/make/SConscript_eve_0',
                    '04_Engineering/03_Workspace/sw/make/SConscript_eve_memtest',
                    '04_Engineering/03_Workspace/sw/make/SConscript_presbl',
                    '04_Engineering/03_Workspace/sw/make/SConscript_sbl',
                    '04_Engineering/03_Workspace/sw/make/SConscript_sbl_loop']

vh_scons_scripts = ['04_Engineering/03_Workspace/sw/make/SConscript_arm-a_0',
                    '04_Engineering/03_Workspace/sw/make/SConscript_arm-m_0',
                    '04_Engineering/03_Workspace/sw/make/SConscript_arm-m_1',
                    '04_Engineering/03_Workspace/sw/make/SConscript_dsp_0',
                    '04_Engineering/03_Workspace/sw/make/SConscript_dsp_1',
                    '04_Engineering/03_Workspace/sw/make/SConscript_eve_0',
                    '04_Engineering/03_Workspace/sw/make/SConscript_eve_1',
                    '04_Engineering/03_Workspace/sw/make/SConscript_eve_memtest',
                    '04_Engineering/03_Workspace/sw/make/SConscript_sbl',
                    '04_Engineering/03_Workspace/sw/make/SConscript_sbl_loop']

device = None
family = None
build_env = BuildEnvironment()
product = None
prj_build_envs = {}


def reset_globals():
    """Reset the global variables that are then written by the SCons parser."""
    global build_env
    global compilers
    global device
    global family
    build_env = BuildEnvironment()
    compilers = None
    device    = None
    family    = None

# ----------------------- SCons interface -----------------------


def Import(value):
    """Just to fulfill the SCons interface."""
    pass


def setCompiler(value):
    """Remember the compiler in the BuildEnvironment."""
    build_env.compiler = value


def setIncludePath(include_paths):
    """Add an include path to the environment."""
    for inc in include_paths.split():
        build_env.include_paths.add(os.path.join(sandbox_root, inc.replace("$product", product)))


def addCompilerDefine(define):
    """Add a compiler define to the environment."""
    build_env.defines.add(define)


def addFiles(rel_path, file_glob):
    """Add files that match file_glob within the given directory (not recursive!)."""
    current_source_path = os.path.join(sandbox_root, rel_path.replace("$product", product))
    if isinstance(file_glob, basestring):
        # if it's a string, make it a list of one element
        file_glob = [file_glob]

    for file_spec in file_glob:
        for f in glob.iglob(os.path.join(current_source_path, file_spec)):
            build_env.files.add(f)
    # also grab all header files in that directory, which don't necessarily have to be in the include path!
    for f in glob.iglob(os.path.join(current_source_path, '*.h')):
        build_env.files.add(f)


def addDirs(rel_path, file_glob):
    """Add files that match file_glob within the given directory and subdirectories (recursive!)."""
    current_source_path = os.path.join(sandbox_root, rel_path.replace("$product", product))
    if isinstance(file_glob, basestring):
        # if it's a string, make it a list of one element
        file_glob = [file_glob]
    for root, dirs, current_files in os.walk(current_source_path):
        for file_spec in file_glob:
            for f in fnmatch.filter(current_files, file_spec):
                build_env.files.add(os.path.join(root, f))
        for f in fnmatch.filter(current_files, '*.h'):
            build_env.files.add(os.path.join(root, f))


def removeFiles(rel_path, file_glob):
    """Remove files that are already in the file list."""
    current_source_path = os.path.join(sandbox_root, rel_path.replace("$product", product))
    if isinstance(file_glob, basestring):
        # if it's a string, make it a list of one element
        file_glob = [file_glob]

    for file_spec in file_glob:
        for f in glob.iglob(os.path.join(current_source_path, file_spec)):
            if f in build_env.files:
                build_env.files.remove(f)
                # print "INFO: removed file \"" + f + "\"."
            else:
                print "INFO: You tried to remove file \"" + f + "\", which is not preset in the current list of files."


def addException(ignore_me):
    """Just to fulfill the SCons interface."""
    pass


def addLibrary(path, libraryName=''):
    """Just to fulfill the SCons interface."""
    pass


def addLibraryElement(path, libraryName=''):
    """Just to fulfill the SCons interface."""
    pass


def compile(core):
    """Actually do something here."""
    global prj_build_envs
    # TODO check if project is available: yes => patch, no => create
    if core not in ['eve_memtest', 'sbl_loop']:
        if core not in prj_build_envs:
            prj_build_envs[core] = copy.deepcopy(build_env)
        else:
            prj_build_envs[core].join(build_env)

# ----------------------- implementation of the patcher -----------------------


class Arguments:
    """Command line arguments."""

    def __init__(self, projects):
        """Constructor."""
        self.projects = projects


def patch_ccs_project(build_env, core):
    """Actually patch the ccs project.

    xml structure:
    projectDescription
        name
        comment
        projects
        buildSpec
            buildCommand
                name
                triggers
                arguments
        natures
            nature
            nature
        linkedResources
            link
                name
                type (1 = file, 2 = folder)
                locationURI
        filteredResources
            filter
                id
                name
                type
                matcher
                    id
                    arguments
        variableList
    """
    def add_links(node, env_tree_element, project_location_ref, prefix=""):
        def create_link(name, element, locationURI):
            link_element = ElementTree.Element("link")
            name_element = ElementTree.Element("name")
            name_element.text = name
            type_element = ElementTree.Element("type")
            type_element.text = str(element.type)
            location_element = ElementTree.Element("location" if not element.virtual else "locationURI")
            location_element.text = locationURI
            link_element.extend([name_element, type_element, location_element])
            return link_element

        for key, element in sorted(env_tree_element.children.iteritems()):
            new_prefix = (("/".join([prefix, element.name])) if prefix != "" else element.name)
            # construct new link element
            link_element = create_link(new_prefix, element,
                                       "/".join([project_location_ref, new_prefix])
                                       if (not element.virtual) else "virtual:/virtual")
            # append it to the list
            node.append(link_element)
            # add subelements
            if element.virtual:     # only add subfolders if the current folder is virtual, otherwise,
                                    # we have already everything there.
                # recursion ends when env_tree_element.children is empty
                add_links(node, element, project_location_ref, new_prefix)

    rel_ccs_project_path = "04_Engineering/03_Workspace/ccs/cores"
    # + 1 for the additional "core" subfolder, + 1 because one "/" divides two subfolders.
    ups = rel_ccs_project_path.count("/") + 2
    abs_ccs_project_path = os.path.abspath(os.path.join(sandbox_root, rel_ccs_project_path, core, '.project'))
    xml_root = ElementTree.parse(abs_ccs_project_path).getroot()
    linkedResources = xml_root.findall("linkedResources")
    if len(linkedResources) != 1:
        print "ERROR: there are 0 or multiple linkedResources."
        sys.exit(1)
    else:
        linkedResources[0].clear()
        build_env_tree = BuildEnvTree(build_env)
        add_links(linkedResources[0], build_env_tree.all_paths, "PARENT-" + str(ups) + "-PROJECT_LOC")
        # Make file writable if it isn't yet.
        os.chmod(abs_ccs_project_path, stat.S_IWRITE)
        with open(abs_ccs_project_path, 'w') as f:
            ElementTree.ElementTree(indent(xml_root)).write(f, xml_declaration=True)


def parse_args():
    """Parse command line arguments and returns them as Arguments."""
    parser = argparse.ArgumentParser(description='Updates / patches existing CSS projects with possible new files',
                                     prefix_chars='/-')
    parser.add_argument(  # "-p", "--projects",
        action='store',
        metavar='<project list>',
        dest='projects',
        help="Comma separated list of projects (e.g. ars441,mfc431,etc.)")
    args = parser.parse_args()
    return Arguments([prj.strip() for prj in args.projects.split(',')])


def add_custom_folders(build_env):
    """Do custom changes to the build environment."""
    build_env.custom_paths.add(os.path.join(sandbox_root, "04_Engineering", "04_Build", "out"))


def main():
    """The main function that is only executed if this module is executed as "main module"."""
    global product
    global device
    global family
    args = parse_args()

    if args.projects == []:
        print "Error, you didn't provide any project!"
        sys.exit(1)

    for prj in args.projects:
        product = prj.lower()
        if product == "ars441":
            scons_scripts = vl_scons_scripts
            device = 'low'
            family = 'radar'
        else:
            scons_scripts = vh_scons_scripts
            device = 'high'
            family = 'mono'
        for script in scons_scripts:
            reset_globals()
            execfile(os.path.join(sandbox_root, script))

    for core in prj_build_envs:
        add_custom_folders(prj_build_envs[core])
        patch_ccs_project(prj_build_envs[core], core)


if __name__ == "__main__":
    main()
