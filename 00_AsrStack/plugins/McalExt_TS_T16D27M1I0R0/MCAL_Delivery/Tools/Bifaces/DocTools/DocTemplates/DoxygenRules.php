<?php $info= $this->infoSourceObject; ?>
INPUT                  = <?php echo $info->inputs . PHP_EOL ?>
INCLUDE_PATH           = 
OUTPUT_DIRECTORY       = <?php echo $info->docOutPath . PHP_EOL ?>
FULL_PATH_NAMES        = NO
STRIP_FROM_PATH        = <?php echo $info->stripPath . PHP_EOL ?>
STRIP_FROM_INC_PATH    = <?php echo $info->stripPath . PHP_EOL ?>
INPUT_ENCODING         = UTF-8
FILE_PATTERNS          = *.c \
                         *.h
RECURSIVE              = NO
EXCLUDE                = 
EXCLUDE_SYMLINKS       = NO
EXCLUDE_PATTERNS       = 
EXCLUDE_SYMBOLS        = 
EXAMPLE_PATH           = 
EXAMPLE_PATTERNS       = *
EXAMPLE_RECURSIVE      = NO
IMAGE_PATH             = <?php echo $info->imageIncludePaths . PHP_EOL ?>
INPUT_FILTER           = 
FILTER_PATTERNS        = 
FILTER_SOURCE_FILES    = NO
DOXYFILE_ENCODING      = UTF-8
PROJECT_NAME           = <?php echo $info->docName . PHP_EOL ?>
PROJECT_NUMBER         = 
CREATE_SUBDIRS         = NO
OUTPUT_LANGUAGE        = English
BRIEF_MEMBER_DESC      = YES
REPEAT_BRIEF           = YES
ABBREVIATE_BRIEF       = "The $name class" \
                         "The $name widget" \
                         "The $name file" \
                         is \
                         provides \
                         specifies \
                         contains \
                         represents \
                         a \
                         an \
                         the
ALWAYS_DETAILED_SEC    = NO
INLINE_INHERITED_MEMB  = NO
SHORT_NAMES            = NO
JAVADOC_AUTOBRIEF      = NO
QT_AUTOBRIEF           = NO
MULTILINE_CPP_IS_BRIEF = NO
INHERIT_DOCS           = YES
SEPARATE_MEMBER_PAGES  = NO
TAB_SIZE               = 8
ALIASES                = 
OPTIMIZE_OUTPUT_FOR_C  = YES
OPTIMIZE_OUTPUT_JAVA   = NO
OPTIMIZE_FOR_FORTRAN   = NO
OPTIMIZE_OUTPUT_VHDL   = NO
EXTENSION_MAPPING      = 
BUILTIN_STL_SUPPORT    = NO
CPP_CLI_SUPPORT        = NO
SIP_SUPPORT            = NO
IDL_PROPERTY_SUPPORT   = YES
DISTRIBUTE_GROUP_DOC   = NO
SUBGROUPING            = YES
TYPEDEF_HIDES_STRUCT   = NO
EXTRACT_ALL            = NO
EXTRACT_PRIVATE        = NO
EXTRACT_STATIC         = NO
EXTRACT_LOCAL_CLASSES  = YES
EXTRACT_LOCAL_METHODS  = NO
EXTRACT_ANON_NSPACES   = NO
HIDE_UNDOC_MEMBERS     = NO
HIDE_UNDOC_CLASSES     = NO
HIDE_FRIEND_COMPOUNDS  = NO
HIDE_IN_BODY_DOCS      = NO
INTERNAL_DOCS          = NO
CASE_SENSE_NAMES       = NO
HIDE_SCOPE_NAMES       = YES
SHOW_INCLUDE_FILES     = YES
INLINE_INFO            = YES
SORT_MEMBER_DOCS       = YES
SORT_BRIEF_DOCS        = NO
SORT_GROUP_NAMES       = NO
SORT_BY_SCOPE_NAME     = NO
GENERATE_TODOLIST      = YES
GENERATE_TESTLIST      = YES
GENERATE_BUGLIST       = YES
GENERATE_DEPRECATEDLIST= YES
ENABLED_SECTIONS       = 
MAX_INITIALIZER_LINES  = 30
SHOW_FILES             = YES
SHOW_NAMESPACES        = YES
FILE_VERSION_FILTER    = 
LAYOUT_FILE            = 
QUIET                  = NO
WARNINGS               = YES
WARN_IF_UNDOCUMENTED   = YES
WARN_IF_DOC_ERROR      = YES
WARN_NO_PARAMDOC       = NO
WARN_FORMAT            = "$file:$line: $text"
WARN_LOGFILE           = 
SOURCE_BROWSER         = YES
INLINE_SOURCES         = NO
STRIP_CODE_COMMENTS    = YES
REFERENCED_BY_RELATION = NO
REFERENCES_RELATION    = NO
REFERENCES_LINK_SOURCE = YES
USE_HTAGS              = NO
VERBATIM_HEADERS       = YES
ALPHABETICAL_INDEX     = NO
COLS_IN_ALPHA_INDEX    = 5
IGNORE_PREFIX          = 
GENERATE_HTML          = YES
HTML_OUTPUT            = <?php if(count($info->targetFullNames) > 0) echo str_replace(".", "_", $info->docName); else echo $info->projectName; echo PHP_EOL ?>
HTML_FILE_EXTENSION    = .html
PROJECT_LOGO           = <?php echo $info->docTemplatesPath . "/InfineonLogo.png" . PHP_EOL ?>
HTML_HEADER            = <?php echo $info->docTemplatesPath . "/Header.html" . PHP_EOL ?>
HTML_FOOTER            = <?php echo $info->rulesFilePath . "/Footer.html" . PHP_EOL ?>
HTML_STYLESHEET        = <?php echo $info->docTemplatesPath . "/IfxAtv_DoxygenDoc.css" . PHP_EOL ?>
HTML_DYNAMIC_SECTIONS  = NO
GENERATE_DOCSET        = NO
DOCSET_FEEDNAME        = "Doxygen generated docs"
DOCSET_BUNDLE_ID       = org.doxygen.Project
GENERATE_HTMLHELP      = <?php if($info->hhcToolPath !== NULL) echo "YES"; else echo "NO"; echo PHP_EOL ?>
CHM_FILE               = <?php echo str_replace(".", "_", $info->docName) . ".chm" . PHP_EOL ?>
HHC_LOCATION           = "<?php if($info->hhcToolPath !== NULL) echo $info->hhcToolPath . "/hhc.exe" ?>"
GENERATE_CHI           = NO
CHM_INDEX_ENCODING     = 
BINARY_TOC             = YES
TOC_EXPAND             = YES
GENERATE_QHP           = NO
QCH_FILE               = 
QHP_NAMESPACE          = 
QHP_VIRTUAL_FOLDER     = doc
QHP_CUST_FILTER_NAME   = 
QHP_CUST_FILTER_ATTRS  = 
QHP_SECT_FILTER_ATTRS  = 
QHG_LOCATION           = 
DISABLE_INDEX          = YES
ENUM_VALUES_PER_LINE   = 4
GENERATE_TREEVIEW      = NO
TREEVIEW_WIDTH         = 250
FORMULA_FONTSIZE       = 10
GENERATE_LATEX         = NO
LATEX_OUTPUT           = latex
LATEX_CMD_NAME         = latex
MAKEINDEX_CMD_NAME     = makeindex
COMPACT_LATEX          = NO
PAPER_TYPE             = a4wide
EXTRA_PACKAGES         = 
LATEX_HEADER           = 
PDF_HYPERLINKS         = YES
USE_PDFLATEX           = YES
LATEX_BATCHMODE        = NO
LATEX_HIDE_INDICES     = NO
LATEX_SOURCE_CODE      = NO
GENERATE_RTF           = NO
RTF_OUTPUT             = rtf
COMPACT_RTF            = NO
RTF_HYPERLINKS         = YES
RTF_STYLESHEET_FILE    = 
RTF_EXTENSIONS_FILE    = 
GENERATE_MAN           = NO
MAN_OUTPUT             = man
MAN_EXTENSION          = .3
MAN_LINKS              = NO
GENERATE_XML           = NO
XML_OUTPUT             = xml
XML_PROGRAMLISTING     = YES
GENERATE_AUTOGEN_DEF   = NO
GENERATE_PERLMOD       = NO
PERLMOD_LATEX          = NO
PERLMOD_PRETTY         = YES
PERLMOD_MAKEVAR_PREFIX = 
ENABLE_PREPROCESSING   = YES
MACRO_EXPANSION        = NO
EXPAND_ONLY_PREDEF     = NO
SEARCH_INCLUDES        = YES
INCLUDE_FILE_PATTERNS  = 
PREDEFINED             = 
EXPAND_AS_DEFINED      = 
SKIP_FUNCTION_MACROS   = YES
TAGFILES               = 
GENERATE_TAGFILE       = 
ALLEXTERNALS           = NO
EXTERNAL_GROUPS        = YES
PERL_PATH              = /usr/bin/perl
CLASS_DIAGRAMS         = YES
MSCGEN_PATH            = 
HIDE_UNDOC_RELATIONS   = YES
HAVE_DOT               = YES
DOT_FONTNAME           = 
DOT_FONTSIZE           = 10
DOT_FONTPATH           = 
CLASS_GRAPH            = YES
COLLABORATION_GRAPH    = YES
GROUP_GRAPHS           = YES
UML_LOOK               = NO
TEMPLATE_RELATIONS     = NO
INCLUDE_GRAPH          = YES
INCLUDED_BY_GRAPH      = YES
CALL_GRAPH             = YES
CALLER_GRAPH           = YES
GRAPHICAL_HIERARCHY    = YES
DIRECTORY_GRAPH        = YES
DOT_IMAGE_FORMAT       = png
DOT_PATH               = "<?php echo $info->dotToolPath ?>"
DOTFILE_DIRS           = "<?php echo $info->docOutPath ?>"
DOT_GRAPH_MAX_NODES    = 50
MAX_DOT_GRAPH_DEPTH    = 0
DOT_TRANSPARENT        = NO
DOT_MULTI_TARGETS      = NO
GENERATE_LEGEND        = YES
DOT_CLEANUP            = YES
SEARCHENGINE           = NO