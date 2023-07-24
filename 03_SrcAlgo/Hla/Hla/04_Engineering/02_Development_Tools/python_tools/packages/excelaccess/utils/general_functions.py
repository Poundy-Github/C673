"""
@author: uidq3472
"""

execute_on_import = False


def local_packages(site_packages_paths=None, logging_level=None):
    """Adds given paths to sys.path in order to provide imports of packages from other directories. Could also be moved
    outside a function to be directly executed on import
    
    :param site_packages_paths: (relative) path(s) to site-package(s)
    :type site_packages_paths: str or list(str)
    :param int logging_level: logging level to be used, defaults to logging.NOTSET
    """
    # TODO: look for better solution
    import sys
    import logging
    import os.path

    if site_packages_paths is None:
        from defs import site_packages_paths
    if logging_level is None:
        logging_level = logging.NOTSET

    # set up logging
    logger = logging.getLogger(__name__)
    logger.setLevel(logging_level)
    # avoid multiple handlers respectively logs
    if not len(logger.handlers):
        stream_handler = logging.StreamHandler()
        stream_handler.setLevel(logging_level)
        formatter = logging.Formatter("(l.%(lineno)d) - %(asctime)s - %(name)s - %(levelname)s - %(message)s")
        stream_handler.setFormatter(formatter)
        logger.addHandler(stream_handler)

    logger.debug("Sys.path (unmodified): {0}".format(sys.path))

    #  check for iterator (list)
    if hasattr(site_packages_paths, "__iter__"):
        for site_packages_path in site_packages_paths:
            add_path = os.path.abspath(os.path.join(os.path.dirname(__file__), site_packages_path))
            logger.debug("Adding '{0}' so sys.path.".format(os.path.abspath(add_path)))
            if add_path not in sys.path:
                sys.path.insert(0, add_path)
    else:
        # only one path
        add_path = os.path.abspath(os.path.join(os.path.dirname(__file__), site_packages_paths))
        if add_path not in sys.path:
            sys.path.insert(0, add_path)
        logger.debug("Adding '{0}' so sys.path.".format(os.path.abspath(site_packages_paths)))

    logger.debug("Sys.path (modified): {0}".format(sys.path))


if execute_on_import:
    local_packages()


def recursive_print(source, _depth=1, _key=None):
    """Recursively composes and finally returns a printable string.

    :param source: target to be printed
    :param int _depth: used for braces
    :param _key: used for dicts
    :return: printable string
    :rtype str
    """
    if _key is None:
        _key = ""
    # src = unicode(src).encode("utf-8")
    #  if unicode is needed
    tabs = lambda n: ' ' * max((n - 1, 0)) * 4  # or 2 or 8 or...
    brace = lambda s, n: '%s%s%s' % ('[' * n, s, ']' * n)

    out_str = ""

    if isinstance(source, dict):
        for _key, value in source.iteritems():
            out_str += tabs(_depth) + brace(_key, _depth) + "\n"
            out_str += recursive_print(value, _depth + 1, _key)
    elif isinstance(source, list):
        for list_item in source:
            out_str += recursive_print(list_item, _depth + 2)
    else:
        if _key:
            out_str += tabs(_depth) + '%s = %s' % (_key, source) + "\n"
        else:
            out_str += tabs(_depth) + '- %s' % (source + "\n")

    return out_str


def get_dict_key_for_name(name):
    """Simply returns the provided string as lowercase string. (in order to have a centralized convention)
    
    :param str name: name string
    :return: name string lowercase
    :rtype: str
    """
    return name.lower()


def get_doxygen_legacy(fn_name, brief, description, param, param_desc, return_val, line_border, line_start):
    """Creates and returns an old doxygen header as formatted string.

    :param str fn_name: function name
    :param str brief: brief for function
    :param str description: function description
    :param str param: parameter
    :param str param_desc: parameter description
    :param str return_val: return value
    :param int line_border: line end for doxygen header
    :param int line_start: line start for doxygen header content
    :return: doxygen header
    :rtype str
    """
    header = """\n/* *******************************************************************************
  @fn             {fn_name} */ /*!

  @brief          {brief}

  @description    {description}

  @param[in]      {param_line}

  @return         {return_val}
******************************************************************************** */"""
    fn_name = fn_name + " " * (line_border - len(fn_name) - 6)
    buf = "{param}       {param_desc}".format(param=param, param_desc=param_desc)
    return header.format(fn_name=fn_name, brief=split_lines(brief, line_border, line_start),
                         description=split_lines(description, line_border, line_start), param=param,
                         param_line=split_lines(buf, line_border, line_start), return_val=return_val)


def get_doxygen(brief, pre, post, param, ret, globals_, in_out_cor, callseq, testmthd, traceab,
                line_border,
                line_start):
    """Creates and returns a doxygen header as formatted string.

    :param str brief: brief for function
    :param str pre: pre conditions
    :param str post: post conditions
    :param str param: parameter
    :param str ret: return value
    :param str globals_:
    :param str in_out_cor: input output correlations
    :param str callseq:
    :param str testmthd:
    :param str traceab:
    :param int line_border: line end for doxygen header
    :param int line_start: line start for doxygen header content
    :return: doxygen header
    :rtype str
    """
    # TODO: more generation instead of hardcoding?; move defs to defs.py?
    params = locals()
    params_list = [
        ("brief", "  \\brief            {0}"),
        ("pre", "  \\pre              {0}"),
        ("post", "  \\post             {0}"),
        ("param", "  \\param[in]        {0}"),
        ("ret", "  \\return           {0}"),
        ("globals_", "  \\globals          {0}"),
        ("in_out_cor", "  \\InOutCorrelation {0}"),
        ("callseq", "  \\callsequence     {0}"),
        ("testmthd", "  \\testmethod       {0}"),
        ("traceab", "  \\traceability     {0}")
    ]

    line_first = "/** ************************************************************************************************"
    line_end = "***************************************************************************************************/"

    content = ""

    for param_name, doxygen in params_list:
        param_buf = params.get(param_name)
        if hasattr(param_buf, "__iter__"):
            for item in param_buf:
                content += doxygen.format(split_lines(item, line_border, line_start))
                if item is not param_buf[-1]:
                    content += "\n"
        else:
            content += doxygen.format(split_lines(param_buf, line_border, line_start))
        content += "\n\n" if not param_name == params_list[-1][0] else "\n"

    frame = "\n{start}\n{content}{end}".format(start=line_first, content=content, end=line_end)

    return frame


def split_lines(string_to_split, line_border, line_start):
    """Splits a string to fit the provided line start and line border. Returns a formatted string.

    :param str string_to_split: string to be split
    :param int line_border: line end to be respected
    :param int line_start: line start to be respected
    :return: formatted
    :rtype str
    """
    string_to_split = string_to_split.replace("\r", "").replace("\n", "")
    used_indices = []
    lines = []
    i = 0
    while i < len(string_to_split):
        # in unrealistic case of every time leading to breaking point branch and every time 0, which would create an
        # infinite loop
        if i in used_indices:
            break
        else:
            used_indices.append(i)

        # split line if there is a space char at the end or right after it; otherwise look for next space to the "left"
        # if there is one, use it as breaking point; if there's not, just cut the line at the border (then there seems
        # to be a very large single word
        if i < (len(string_to_split) - line_border - 1):
            if string_to_split[i + line_border] == " " or string_to_split[i + line_border + 1] == " ":
                lines.append(string_to_split[i:i + line_border])
                i += line_border
            else:
                breaking_point = string_to_split.rfind(" ", i, i + line_border) + 1
                if breaking_point > 0:
                    lines.append(string_to_split[i:breaking_point])
                    i = breaking_point
                else:
                    lines.append(string_to_split[i:i + line_border])
                    i += line_border
        else:
            lines.append(string_to_split[i:i + line_border])
            i += line_border

    return ("\n" + " " * line_start).join(lines)


def is_sequence(item):
    """Check if provided argument is a sequence.

    :param item: argument to be checked
    :return: True if sequence, False otherwise
    :rtype bool
    """
    return (not hasattr(item, "strip") and
            hasattr(item, "__getitem__") or
            hasattr(item, "__iter__"))
