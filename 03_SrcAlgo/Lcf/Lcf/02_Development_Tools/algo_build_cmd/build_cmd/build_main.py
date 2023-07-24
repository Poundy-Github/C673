###########
#Script for calling build lib
#
#:org:           Continental AG
#
###########
print "%s" % (__file__)

from build_lib import *
from optparse import OptionParser
from mks_config_tools import formatExceptionInfo

class AlgoBuild_obj():
    ###########
    # Description: Config shared sup projects class
    ###########

    def AlgoBuild(self, argu):
        ###########
        # AlgoBuild(self,argu)
        # 
        # Description: the AlgoBuild main function
        # 
        # Parameter:    -argu the command line options and arguments
        ###########

        usage = """usage : %prog AlgoBuild [options]
Example: python %prog AlgoBuild -c d:\\SWProjects\\MFC400\\06_algo\\04_eng\\03_Workspace\\xyz.xml -l -o c:\BuildLogging"""

        # parse the arguments
        parser = OptionParser(usage)
        parser.add_option("-c", "--config", dest="ConfigFileName",
                  help="BuildConfig FileName ", metavar="FILE")
        parser.add_option("-p", "--projects", dest="projects_filter", default=None,
                  help="Build Project filters, e.g MFC4xx,MFS430BW15 ", metavar="project_filter")
        parser.add_option("-v", "--vcvarsbat", dest="vcvarsbat2005",
                  help="Build environment file for Visual Studio 2005", metavar="BUILD_ENVIRONMENT_FILE", default="")
        parser.add_option("-w", "--vcvarsbat2010", dest="vcvarsbat2010",
                  help="Build environment file for Visual Studio 2010", metavar="BUILD_ENVIRONMENT_FILE", default="")
        parser.add_option("-t", "--type", dest="type",
                  help="BuildConfig type, e.g. Release, Debug, *", metavar="config_type", default="Release")
        parser.add_option("-f", "--name-filter", dest="namefilter",
                  help="If target name contains this string the build is executed, e.g. ecu, sim, unittest, doxy, ide", metavar="namefilter", default="*")
        parser.add_option("-r", "--rebuild", dest="rebuild", action="store_true",
                  help="if true a complete rebuild is done", metavar="namefilter", default=False)
        parser.add_option("-j", "--cores", dest="cores", default=None,
                  help="sets the number of cores that should be used for the build", metavar="number_of_cores")
        parser.add_option("-l", "--log", dest="Logging", action="store_true", default=False,
                  help="log(on/off)")
        parser.add_option("-o", "--outputdir", dest="OutputDir",
                  help="working direcory")
        parser.add_option("--verbose", dest="verbose", action="store_true", default=False,
        					help="verbose = True prints out compiler options used by scons build as well")

        (options, args) = parser.parse_args(argu)

        # create list of possible vcVarsCandidates locations for
        vcVarsCandidates = {'vcbuild': [], 'msbuild': []}

        vcVarsCandidates['vcbuild'].append(options.vcvarsbat2005)
        vcVarsCandidates['vcbuild'].append(r'C:\Win16App\VisualStudio2005\Common7\Tools\vsvars32.bat')  # Win XP VS 2005 default
        vcVarsCandidates['vcbuild'].append(r'C:\LegacyApp\VisualStudio2005\Common7\Tools\vsvars32.bat')  # Win 7  VS 2005 default

        vcVarsCandidates['msbuild'].append(options.vcvarsbat2010)
        vcVarsCandidates['msbuild'].append(r'C:\LegacyApp\VisualStudio2010\Common7\Tools\vsvars32.bat')  # Win 7 VS 2010 default

        # choose first item that exists
        self.vcVars = {}
        for buildName in vcVarsCandidates.keys():
            for path in vcVarsCandidates[buildName]:
                if os.path.isfile(path):
                    self.vcVars[buildName] = path
                    break

        # setup the local members to the arguments
        self.Logging = options.Logging
        self.OutputDir = options.OutputDir

        self.ConfigFileName = options.ConfigFileName
        if os.path.isfile(self.ConfigFileName) == False:
            print "Error: ConfigFile does not exist: %s" % (self.ConfigFileName)
            return 1

        # create object
        BuildLib = BuildLibV2_obj()

        err = 0
        # check output log directory
        if ((os.path.isdir(self.OutputDir) == 0) and (self.Logging == True)):
            print "Error: log directory does not exist e.g. -o c:\temp"
            err = 1
        else:
            logTypes = {}
            logTypes["Info"] = 1
            # logTypes["Warn"]=2
            # logTypes["Debug"]=3

            # create copy of log file
            fnamelog = "%s\logging_%s_%s.txt" % (self.OutputDir, options.namefilter, datetime.now().strftime("%Y.%m.%d_%H.%M.%S"))
            print "fname_log=%s%s" % (os.getcwd(), fnamelog)

            if self.Logging == True:
                BuildLib.SetupLogging(fnamelog, "file", logTypes)
            else:
                BuildLib.SetupLogging(fnamelog, "console", logTypes)

            try:
                StartTime, err_cnt = BuildLib.DoBuild(self.ConfigFileName, options.type, self.vcVars, os.path.dirname(self.ConfigFileName), options.namefilter, options.rebuild, options.cores, options.projects_filter, options.verbose)
                print BuildLib
                if (err_cnt > 0) or (StartTime == 0) :
                    err = 1

            except Exception, e:
                print formatExceptionInfo()
                BuildLib.Log("Error", "Exception within DoBuild: %s" % (str(e)))
                err = 1

        return (err)

def PrintHelp():
    ###########
    # PrintHelp()
    # 
    # Description: Print the Help menu 
    ###########
    print """Usage: 
python algo_main.py AlgoBuild [options e.g. -h for help]
"""

def main(argv):
    ###########
    # main()
    # 
    # Description: the main function 
    ###########

    # check for script
    err = 1
    if (argv[1] == "AlgoBuild"):
        if len(argv) < 3:
            argv.append("-h")
        err = AlgoBuild_obj().AlgoBuild(argv)
    else:
        PrintHelp()

    sys.exit(err)

# check input args
if (len(sys.argv) > 1):
    main(sys.argv)
else:
    PrintHelp()
