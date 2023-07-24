"""
stk/mts/cfg
-----------

Read MTS Config an write a sorted version
Class to sort the MTS Config file


:org:           Continental AG
:author:        Anne Skerl

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:58:28CET $
"""
# Import Python Modules -------------------------------------------------------

# Import STK Modules ----------------------------------------------------------

# Defines ---------------------------------------------------------------------
MODES = {'0': 'only sections = default',
         '1': 'sections + properties'}

# Functions -------------------------------------------------------------------


def __splitStripString(strng, delimiter, stripchars=' \'"'):
    """
    split input string at delimiters and remove stripchars from each split result.

    :param strng:      input string
    :type strng:       string
    :param delimiter:   delimiter where to split
    :type delimiter:   string
    :param stripchars: chars to strip
    :type stripchars:  string
    :return:           list of split and strip results
    :rtype:            list
    :author:           Anne Skerl
    :date:             27.06.2013
    """
    string_out = []
    for element in strng.split(delimiter):
        if len(element.strip(stripchars)) > 0:
            string_out.append(element.strip(stripchars))

    return string_out

def __getSections(hfile, lines):
    """
    Get all Section out of the Lines, other lines are
    detected as HeaderLines, and will be written directly to the
    output file.

    :param hfile: Handle for outputfile
    :type hfile:  file
    :return:      found Sections
    :rtype:       dictionary
    :author:      Robert Hecker
    :date:        27.06.2013
    """

    # find sections
    section = ''
    sections = {}

    for line in lines:
        if len(line.strip()) > 0:  # ignore empty lines
            # line is section start
            if line.startswith('['):
                section = line

            # line is property
            elif section:
                if section in sections:
                    # append to  sections-entry
                    sections[section].append(line)
                else:
                    # start new sections-entry
                    sections[section] = [line, ]

            # line is header
            else:
                hfile.write(line)  # write header lines

    return sections

def __sortSections(hfile, sections, mode):
    """
    Sort the given sections regarding the mode, and write them to file.

    :param hfile: Handle for outputfile
    :type hfile:  file
    :return:      found Sections
    :rtype:       dictionary
    :author:      Robert Hecker
    :date:        27.06.2013
    """
    # sort sections
    sect_keys = sections.keys()
    sect_keys.sort()

    for key in sect_keys:
        # write section
        hfile.write('\n')
        hfile.write(key)

        if mode == 1:
            # find properties
            prop = ''
            properties = {}
            for prop_line in sections[key]:
                prop_split = prop_line.split('=', 1)
                if len(prop_split) > 1:
                    prop = prop_split[0]
                    properties[prop] = prop_line
                elif prop in properties:
                    properties[prop] += prop_line
                else:
                    raise 'error in properties in line %s!' % prop_line

            # process properties
            if properties:
                # sort properties
                prop_keys = properties.keys()
                prop_keys.sort()

                # write properties
                for prop_key in prop_keys:
                    hfile.write(properties[prop_key])

        else:
            # write values per section
            vals = sections[key]
            for val in vals:
                if val[-1] == "\\":  # if value containes a list
                    hfile.write(val + '\t')  # then indent the line
                else:
                    hfile.write(val)

def sort(infile, outfile, mode):
    """
    Parse a give mts cfg file and sort it to be comparable with an ASCII
    File Compare Utility.

    :param infile:     Input File Path
    :type infile:      string
    :param outfile:    Output File Path
    :type outfile:     string
    :param mode:       0: Sort Section Only.
                       1: Sort Sections and Properties
    :type mode:        int
    :return:           -
    :rtype:            -
    :author:           Robert Hecker
    :date:             27.06.2013
    """
    # read infile
    hFileIn = file(infile)
    lines = hFileIn.readlines()
    hFileIn.close()

    # open outfile
    fobj = open(outfile, "w")

    sections = __getSections(fobj, lines)

    # process sections
    if sections:
        __sortSections(fobj, sections, mode)

    fobj.close()


"""
Log:
$Log: cfg.py  $
Revision 1.1 2021/12/13 17:58:28CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/mts/project.pj
Revision 1.1 2013/06/27 16:01:40CEST Hecker, Robert (heckerr) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/mts/project.pj
"""
