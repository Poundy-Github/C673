"""
stk_image_extractor
===================

:org:           Continental AG
:author:        Sorin Mogos

:version:       $Revision: 1.1 $
:date:          $Date: 2021/12/13 17:58:29CET $
"""

# Import Python Modules -----------------------------------------------------------------------------------------------
from sys import argv
from os import path, getcwd, makedirs, removedirs, listdir, unlink, remove, sep
from subprocess import Popen, PIPE
from shutil import copy
from re import search as research, findall

# Import STK Modules --------------------------------------------------------------------------------------------------
from stk.util.logger import Logger

# Defines -------------------------------------------------------------------------------------------------------------
DEFAULT_OUTPUT_DIR_PATH = getcwd()
DEFAULT_GFX_OUTPUT_SUBDIR = "gfx"
SEQ_FOLDER_NAME = "video"
SEQ_FILE_EXT = ".seq"

RECFILEEXTRACTOR_SKIP_MICROS = 500000

# Classes -------------------------------------------------------------------------------------------------------------


class Extractor(object):
    """recfile extractor wrapper around RecFileExtractor binary
    """
    def __init__(self, output_dir_path=None, video_device=None, img_channel=None):

        self.__logger = Logger("Extractor")
        self.__logger.debug()

        if output_dir_path is None:
            self.__outdir_pathname = path.join(DEFAULT_OUTPUT_DIR_PATH, DEFAULT_GFX_OUTPUT_SUBDIR)
        else:
            self.__outdir_pathname = output_dir_path

        self.__extractor_path = None
        self.__rec_file_extractor_path = None
        self.__event_video_dir = None

        # Create ouput folders
        if not path.exists(self.__outdir_pathname):
            makedirs(self.__outdir_pathname)
        else:
            for entry in listdir(self.__outdir_pathname):
                if path.isdir(path.join(self.__outdir_pathname, entry)):
                    for fn in listdir(path.join(self.__outdir_pathname, entry)):
                        unlink(path.join(path.join(self.__outdir_pathname, entry), fn))
                    removedirs(path.join(self.__outdir_pathname, entry))
                else:
                    unlink(path.join(self.__outdir_pathname, entry))

        self.__video_device = video_device
        self.__channel = img_channel

    def SetOutputDirPath(self, output_dir):
        """sets the out dir, where to store the images
        """
        self.__outdir_pathname = output_dir

        # Create ouput folders
        if not path.exists(self.__outdir_pathname):
            makedirs(self.__outdir_pathname)
        else:
            for entry in listdir(self.__outdir_pathname):
                if path.isdir(path.join(self.__outdir_pathname, entry)):
                    for fn in listdir(path.join(self.__outdir_pathname, entry)):
                        unlink(path.join(path.join(self.__outdir_pathname, entry), fn))
                    removedirs(path.join(self.__outdir_pathname, entry))
                else:
                    unlink(path.join(self.__outdir_pathname, entry))

    def MakeVideoDirPath(self, video_dir_path=None):
        """creates event video output folder
        """
        if video_dir_path is not None:
            self.__event_video_dir = video_dir_path
        else:
            self.__event_video_dir = path.join(self.__outdir_pathname, SEQ_FOLDER_NAME)

        if not path.exists(self.__event_video_dir):
            makedirs(self.__event_video_dir)

    def SetRecFileExtractor(self, extractor_path):
        """sets the extractor executable path
        """
        self.__rec_file_extractor_path = path.abspath(path.join(extractor_path))
        if not path.exists(self.__rec_file_extractor_path):
            self.__logger.error("Rec File Extractor path: '%s' doesn't exist." % self.__rec_file_extractor_path)
            return None

    def SaveRecSeqFile(self, current_meas_file, video_list, start_timestamp,  # pylint: disable=R0912
                       seq_count, copy_files=False):
        """saves the file sequence
        """
        if not isinstance(video_list, list):
            self.__logger.error("Expected instance of type 'list'. Instance of type '%s' found." % type(video_list))
            return None

        video_seq_file_path = path.join(self.__event_video_dir, "%s_%s_%s%s" %
                                        (path.splitext(path.basename(current_meas_file))[0],
                                         str(start_timestamp), str(seq_count), SEQ_FILE_EXT))
        video_seq_dir_path = "SEQ" + str(start_timestamp) + "_" + str(seq_count)

        if copy_files:  # make the seq dir
            full_video_seq_dir_path = path.join(self.__event_video_dir, video_seq_dir_path)
            if not path.exists(full_video_seq_dir_path):
                makedirs(full_video_seq_dir_path)

        try:
            fp = open(video_seq_file_path, "w")
        except IOError as ex:
            self.__logger.exception(str(ex))
            return None

        plot_video_list = []
        try:
            for idx in xrange(len(video_list)):
                if idx != len(video_list) - 1:
                    fp.write(video_seq_dir_path + sep + path.basename(video_list[idx]) + "\n")
                else:
                    fp.write(video_seq_dir_path + sep + path.basename(video_list[idx]))

                plot_video_list.append(str(video_list[idx]))

                if copy_files:
                    copy(video_list[idx], full_video_seq_dir_path)

        except Exception as ex:
            self.__logger.exception(str(ex))
            self.__logger.error("Error while writting image sequence file: '%s'" % video_seq_file_path)
            video_seq_file_path = None
        finally:
            fp.close()

        # remove not necessary video files
        removed_timestamp_list = []
        for timestamp in video_list:
            if str(timestamp) not in plot_video_list:
                try:
                    if not timestamp in removed_timestamp_list:
                        remove(timestamp)
                        removed_timestamp_list.append(timestamp)
                except Exception as ex:
                    self.__logger.exception(str(ex))

        return video_seq_file_path

    def __extract_images(self, meas_file_path, index, from_timestamp, to_timestamp=None):
        """unused method?
        """
        if not path.exists(meas_file_path):
            self.__logger.error("Measurement file doesn't exist: '%s'" % meas_file_path)
            return None

        if not path.exists(self.__rec_file_extractor_path):
            self.__logger.error("Invalid rec file extractor path " + str(self.__extractor_path))
            return None

        video_dir_path = path.join(self.__event_video_dir, "SEQ" + str(from_timestamp) + "_" + str(index))

        self.SetOutputDirPath(video_dir_path)

        # extracted_timestamp_list = []
        extracted_timestamp_list = self.GetImage(self.__rec_file_extractor_path,
                                                 meas_file_path, from_timestamp, to_timestamp)

        if len(extracted_timestamp_list) == 0:
            return None

        image_timestamp_list = []
        for image in extracted_timestamp_list:
            try:
                timestamp = long(image.split('.jpeg')[0])
                image_timestamp_list.append(timestamp)
            except ValueError:
                self.__logger.error('while converting timestamp: %s.' % image)
                continue

        if len(image_timestamp_list):
            return image_timestamp_list

        return None

    def GetImage(self, extractor_path, recfilepath, rel_start_timestamp,  # pylint: disable=R0912
                 rel_stop_timestamp=None, bmpFormat=False):
        """ Reads image from recording
        @param recfilepath The path of the recording file.
        @param rel_start_timestamp The relative timestamp of the first image.
        @param rel_stop_timestamp The relative timestamp of the last image that is being extracted.
        @return Path to the image file.
        """
        self.__extractor_path = path.abspath(path.join(extractor_path))
        # file_path = None

        if not path.exists(self.__extractor_path):
            self.__logger.error("Invalid extractor path " + str(self.__extractor_path))
            return []

        if path.exists(recfilepath):
            try:
                cd = path.split(argv[0])[0]
                recfilepath = "\"%s\"" % recfilepath
                cmd = path.join(cd, self.__extractor_path) + " " + recfilepath + " /T:0 /I /D"
                if bmpFormat:
                    cmd += ' /F:"bmp"'
                sysret = Popen(cmd, shell=False, stdout=PIPE).communicate()[0]
            except OSError as ex:
                self.__logger.warning("Couldn't create image " + str(ex))
            else:
                times = research(r"StartTime:\s(\d*)\sStopTime:\s(\d*)(\r\n.*|$)", sysret)
                if times is not None and len(times.groups()) == 3:
                    try:
                        # imgts_start = absts + max(rel_imgts, RECFILEEXTRACTOR_SKIP_MICROS)
                        # imgts_start = absts + rel_start_timestamp
                        cmd = ('%s %s /T:%d /O:"%s"' % (path.join(cd, self.__extractor_path), recfilepath,
                                                        max(rel_start_timestamp, int(times.groups()[0])),
                                                        self.__outdir_pathname))
                        if rel_stop_timestamp is not None:
                            cmd += (' /U:%d' % min(rel_stop_timestamp, int(times.groups()[1])))

                        try:
                            if self.__video_device is not None:
                                cmd += ' /D:"' + str(self.__video_device) + '"'
                        except:
                            pass

                        try:
                            if self.__channel is not None:
                                cmd += ' /C:"' + str(self.__channel) + '"'
                        except:
                            pass

                        cmd += ' /F:"' + ('bmp' if bmpFormat else 'jpeg') + '"'

                        sysret = Popen(cmd, shell=False, stdout=PIPE).communicate()[0]
                    except OSError as ex:
                        self.__logger.warning("Couldn't create image " + str(ex))
                    else:
                        err = research(r"Error:\s(.*)", sysret)
                        if err is not None and err.groups()[0] != '-1':
                            self.__logger.warning(err.groups()[0])
                        else:
                            return findall(r"Extract\sImage:\s((?i)\d*\.%s)\r" % ("bmp" if bmpFormat else "jpeg"),
                                           sysret)
        else:
            self.__logger.warning("File '%s' doesn't exist." % recfilepath)
        # done
        return []

    def GetImageSequence(self, recfilepath, timestamps, is_list=True, bmpFormat=False):  # pylint: disable=R0912,R0915
        """ Reads image from recording
        @param recfilepath: The path of the recording file.
        @param timestamps: list of times images should be extracted from
        @param is_list: indication wether timestamps list only contains 1 or 2 stamps

        @return: Path to the image file.
        """
        self.__extractor_path = path.abspath(path.join(self.__rec_file_extractor_path))
        video_file_list = []
        # file_path = None

        if not path.exists(self.__extractor_path):
            self.__logger.error("Invalid extractor path " + str(self.__extractor_path))
            return video_file_list

        if path.exists(recfilepath):
            try:
                cd = path.split(argv[0])[0]
                recfilepath = "\"%s\"" % recfilepath
                cmd = path.join(cd, self.__extractor_path) + " " + recfilepath + " /T:0 /I /D"
                if bmpFormat:
                    cmd += ' /F:"bmp"'
                sysret = Popen(cmd, shell=False, stdout=PIPE).communicate()[0]
            except OSError as ex:
                self.__logger.warning("Couldn't create image " + str(ex))
            else:
                times = research(r"StartTime:\s(\d*)\sStopTime:\s(\d*)(\r\n.*|$)", sysret)
                if times is not None and len(times.groups()) == 3:
                    start_timestamp_list = []
                    stop_timestamp_list = []

                    # the timestamps is a list of 1 or 2 timestamps (ts_start and optional ts_stop)
                    if is_list is False:
                        if len(timestamps) == 1:
                            start_timestamp_list.append(timestamps[0])
                            stop_timestamp_list.append(None)
                        elif len(timestamps) > 1:
                            start_timestamp_list.append(timestamps[0])
                            stop_timestamp_list.append(timestamps[1])
                        else:  # no timestamps in the list
                            return video_file_list
                    else:  # the timestamps is a list of individual image timestamps
                        start_timestamp_list = timestamps
                        stop_timestamp_list = [None] * len(start_timestamp_list)

                    for rel_start_timestamp, rel_stop_timestamp in zip(start_timestamp_list, stop_timestamp_list):
                        try:
                            cmd = ('%s %s /T:%d /O:"%s"' % (path.join(cd, self.__extractor_path), recfilepath,
                                                            max(rel_start_timestamp, int(times.groups()[0])),
                                                            self.__outdir_pathname))
                            if rel_stop_timestamp is not None:
                                cmd += (' /U:%d' % min(rel_stop_timestamp, int(times.groups()[1])))

                            try:
                                if self.__video_device is not None:
                                    cmd += ' /D:"' + str(self.__video_device) + '"'
                            except:
                                pass

                            try:
                                if self.__channel is not None:
                                    cmd += ' /C:"' + str(self.__channel) + '"'
                            except:
                                pass

                            cmd += ' /F:"' + ('bmp' if bmpFormat else 'jpeg') + '"'

                            sysret = Popen(cmd, shell=False, stdout=PIPE).communicate()[0]
                        except OSError as ex:
                            self.__logger.warning("Couldn't create image " + str(ex))
                        else:
                            p0 = sysret.find("Extract Image: ")
                            image_ext = ".bmp" if bmpFormat else ".jpeg"

                            p1 = sysret.find(image_ext)

                            if p0 > -1 and p1 > -1:
                                # file_path = path.join(self.__outdir_pathname, sysret[p0 + 15 : p1 - p0 + 5])

                                video_file_list.extend(sysret.replace("Extract Image: ", "").split("\r"))
                                if "" in video_file_list:
                                    video_file_list.remove("")

                            else:
                                p0 = sysret.find("Error: ")
                                p1 = sysret.find("\r")
                                if p0 > -1 and p1 > -1:
                                    error = sysret[p0:p1]
                                    self.__logger.warning(error)
                                else:
                                    self.__logger.warning("Couldn't find the image frame")

        else:
            self.__logger.warning("File '%s' doesn't exist." % recfilepath)
        # done
        return video_file_list

"""
CHANGE LOG:
-----------
$Log: rec.py  $
Revision 1.1 2021/12/13 17:58:29CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/mts/project.pj
Revision 1.8 2013/11/27 16:30:09CET Mertens, Sven (uidv7805) 
cleanup
- Added comments -  uidv7805 [Nov 27, 2013 4:30:10 PM CET]
Change Package : 208576:1 http://mks-psad:7002/im/viewissue?selection=208576
Revision 1.7 2013/11/27 16:04:30CET Mertens, Sven (uidv7805)
update to work with V01.00.01 of RecFileExtractor
--- Added comments ---  uidv7805 [Nov 27, 2013 4:04:31 PM CET]
Change Package : 208576:1 http://mks-psad:7002/im/viewissue?selection=208576
Revision 1.6 2013/03/28 13:31:13CET Mertens, Sven (uidv7805)
minor pep8
Revision 1.5 2013/03/28 11:10:53CET Mertens, Sven (uidv7805)
pylint: last unused import removed
--- Added comments ---  uidv7805 [Mar 28, 2013 11:10:53 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.4 2013/02/28 16:43:31CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguide.
--- Added comments ---  heckerr [Feb 28, 2013 4:43:31 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/28 08:12:08CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:09 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/27 16:19:51CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 27, 2013 4:19:51 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2013/02/13 09:36:19CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/mts/project.pj
Revision 1.6 2012/04/30 10:20:32CEST Mogos, Sorin (mogoss)
* update: added new methods to create image sequences
--- Added comments ---  mogoss [Apr 30, 2012 10:20:33 AM CEST]
Change Package : 104217:1 http://mks-psad:7002/im/viewissue?selection=104217
Revision 1.5 2011/06/30 13:27:25CEST Marius Dinu (DinuM)
added another optional constructor parameter for image channel
--- Added comments ---  DinuM [Jun 30, 2011 1:27:25 PM CEST]
Change Package : 68186:1 http://mks-psad:7002/im/viewissue?selection=68186
Revision 1.4 2010/10/18 13:30:07CEST Marius Dinu (DinuM)
Added " " to recfile path
--- Added comments ---  DinuM [Oct 18, 2010 1:30:08 PM CEST]
Change Package : 41612:12 http://mks-psad:7002/im/viewissue?selection=41612
Revision 1.3 2010/10/14 12:32:31CEST Marius Dinu (DinuM)
Added additional parameter to class constructor  for video device
--- Added comments ---  DinuM [Oct 14, 2010 12:32:31 PM CEST]
Change Package : 41612:12 http://mks-psad:7002/im/viewissue?selection=41612
Revision 1.2 2010/02/19 11:14:37CET dkubera
header and footer added
--- Added comments ---  dkubera [2010/02/19 10:14:37Z]
Change Package : 33974:2 http://LISS014:6001/im/viewissue?selection=33974
"""
