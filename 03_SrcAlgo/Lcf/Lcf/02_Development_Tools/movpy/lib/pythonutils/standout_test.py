# standout_test.py

# Unit tests for standout

# Copyright (C) 2006 Michael Foord
# E-mail: fuzzyman AT voidspace DOT org DOT uk

# http://www.voidspace.org.uk/python/standout.html

# Released subject to the BSD License
# Please see http://www.voidspace.org.uk/python/license.shtml

# Scripts maintained at http://www.voidspace.org.uk/python/index.shtml
# For information about bugfixes, updates and support, please join the
# Pythonutils mailing list:
# http://groups.google.com/group/pythonutils/
# Comments, suggestions and bug reports welcome.

import os
import sys
import traceback
from unittest import TestCase, main
from StringIO import StringIO

from standout3 import StandOut
import standout3
_Stream = standout3._Stream


testFile = os.path.join(os.path.expanduser('~'), 'testStandout.txt')

class TrackStream(object):
    def __init__(self):
        self.output = ''
        self.stream = sys.stdout
        self.flushed = False
    
    def write(self, data):
        self.output += data
        self.stream.write(data)

    def flush(self):
        self.flushed = True

class TestStandOut(TestCase):
    
    def tearDown(self):
        sys.stdout = sys.__stdout__
        sys.stderr = sys.__stderr__
        if os.path.isfile(testFile):
            os.remove(testFile)


    def testTrackStream(self):
        mockStream = TrackStream()
        sys.stdout = mockStream
        print 'hello'
        sys.stdout = sys.__stdout__
        self.assertEquals(mockStream.output, 'hello\n', "TrackStream not passing on output.")
        #
        self.assertFalse(mockStream.flushed, "Trackstream flushed attribute not initially False")
        mockStream.flush()
        self.assertTrue(mockStream.flushed, "Trackstream flushed attribute not True after calling flush")
        


    def testStream(self):
        mockStream = TrackStream()
        sys.stdout = mockStream
        stream = _Stream(sys.stdout)
        sys.stdout = stream
        self.assertNotEquals(sys.stdout, sys.__stdout__, "stdout not diverted")
        self.assertEquals(sys.stdout._outfile, None, "stdout._outfile incorrect")
        self.assertEquals(sys.stdout._stream, mockStream, "stdout._stream incorrect")
        print 'hello'
        self.assertEquals(mockStream.output, 'hello\n', "_Stream not passing on output.")
        
        mockStream.output = ''
        stream.write('hello\n')
        self.assertEquals(mockStream.output, 'hello\n', "_Stream not passing on output.")
        sys.stdout = mockStream
        
        mockStream.output = ''
        openFile = StringIO()
        sys.stdout = _Stream(sys.stdout, openFile)
        self.assertTrue(isinstance(sys.stdout._outfile, StringIO), "stdout._outfile incorrect")
        self.assertEquals(sys.stdout._stream, mockStream, "stdout._stream incorrect")
        print 'hello'
        sys.stdout = mockStream
        openFile.seek(0)
        self.assertEquals(openFile.read(), 'hello\n', "Open File incorrectly written to")
        openFile.seek(0)
        
        mockStream.output = ''
        sys.stdout = _Stream(sys.stdout, openFile, prefix='xxx')
        self.assertTrue(isinstance(sys.stdout._outfile, StringIO), "stdout._outfile incorrect")
        self.assertEquals(sys.stdout._stream, mockStream, "stdout._stream incorrect")
        print 'hello'
        sys.stdout = sys.__stdout__
        openFile.seek(0)
        self.assertEquals(mockStream.output, 'xxxhello\n', "_Stream incorrectly passing on output.")
        self.assertEquals(openFile.read(), 'xxxhello\n', "Open File incorrectly written to")


    def testStreamWritelines(self):
        mockStream = TrackStream()
        sys.stdout = mockStream
        sys.stdout = _Stream(sys.stdout)
        self.assertNotEquals(sys.stdout, sys.__stdout__, "stdout not diverted")
        self.assertEquals(sys.stdout._outfile, None, "stdout._outfile incorrect")
        self.assertEquals(sys.stdout._stream, mockStream, "stdout._stream incorrect")
        sys.stdout.writelines(['h', 'e', 'l', 'l', 'o', '\n'])
        sys.stdout = mockStream
        self.assertEquals(mockStream.output, 'hello\n', "_Stream not passing on writelines.")


    def testStreamAttributes(self):
        not_proxied = ['write', 'writelines', 'next']
        attrs = dict([(attr, getattr(sys.stdout, attr)) for attr in dir(sys.stdout)
            if attr not in not_proxied and not attr.startswith('__')])
        standout = StandOut()
        self.assertNotEquals(sys.stdout, sys.__stdout__, "Stdout not diverted")
        for attr, value in attrs.items():
            self.assertEquals(value, getattr(sys.stdout, attr), "Attribute %s not proxied" % attr)
        standout.close()


    def testStreamPriority(self):
        mockStream = TrackStream()
        sys.stdout = mockStream
        stream = _Stream(sys.stdout, priority=5)
        sys.stdout = stream
        print 'hello'
        self.assertEquals(mockStream.output, 'hello\n', "_Stream not passing on output.")
        mockStream.output = ''
        stream._priority = 4
        print 'hello'
        self.assertEquals(mockStream.output, '', "_Stream passing on low priority output.")
        
        mockStream.output = ''
        stream._priority = 6
        print 'hello'
        self.assertEquals(mockStream.output, 'hello\n', "_Stream not passing on output.")
        
        mockStream.output = ''
        stream._priority = 5
        print 'hello'
        self.assertEquals(mockStream.output, 'hello\n', "_Stream not passing on output.")

        mockStream.output = ''
        stream.write('hello\n')
        self.assertEquals(mockStream.output, 'hello\n', "_Stream not passing on output.")
        
        mockStream.output = ''
        stream.write('hello\n', 4)
        self.assertEquals(mockStream.output, '', "_Stream unexpectedly passing on output.")
        stream.write('hello\n', 5)
        self.assertEquals(mockStream.output, 'hello\n', "_Stream not passing on output.")


    def testStreamStreamThreshold(self):
        mockStream = TrackStream()
        sys.stdout = mockStream
        stream = _Stream(sys.stdout, streamThreshold=5)
        sys.stdout = stream
        print 'hello'
        self.assertEquals(mockStream.output, 'hello\n', "_Stream not passing on output.")
        mockStream.output = ''
        stream._streamThreshold = 6
        print 'hello'
        self.assertEquals(mockStream.output, '', "_Stream passing on low priority output.")
        
        mockStream.output = ''
        stream.write('hello\n', 5)
        self.assertEquals(mockStream.output, '', "_Stream passing on low priority output.")
        stream.write('hello\n', 6)
        self.assertEquals(mockStream.output, 'hello\n', "_Stream not passing on output.")
        
        sys.stdout = mockStream
        stream = _Stream(sys.stdout, streamThreshold=6)
        sys.stdout = stream
        mockStream.output = ''
        print 'hello'
        self.assertEquals(mockStream.output, '', "_Stream unexpectedly passing on output.")
        mockStream.output = ''
        stream._streamThreshold = 5
        print 'hello'
        self.assertEquals(mockStream.output, 'hello\n', "_Stream not passing on output.")
        
        stream._streamThreshold = 6
        mockStream.output = ''
        stream.write('hello\n', 5)
        self.assertEquals(mockStream.output, '', "_Stream unexpectedly passing on output.")
        stream.write('hello\n', 6)
        self.assertEquals(mockStream.output, 'hello\n', "_Stream not passing on output.")


    def testStreamLogfileThreshold(self):
        mockStream = TrackStream()
        sys.stdout = mockStream
        openFile = StringIO()
        stream = _Stream(sys.stdout, openFile, streamThreshold=0, logfileThreshold=5)
        sys.stdout = stream
        
        print 'hello'
        openFile.seek(0)
        self.assertEquals(mockStream.output, 'hello\n', "stream not passing on output.")
        self.assertEquals(openFile.read(), 'hello\n', "stream not writing to log file.")
        
        sys.stdout.write('hello\n', 4)
        openFile.seek(0)
        self.assertEquals(mockStream.output, 'hello\nhello\n', "stream not passing on output.")
        self.assertEquals(openFile.read(), 'hello\n', "stream unexpectedly writing to log file.")
        openFile.close()
        
        mockStream.output = ''
        sys.stdout = mockStream
        openFile = StringIO()
        stream = _Stream(sys.stdout, openFile, logfileThreshold=6)
        sys.stdout = stream
        
        print 'hello'
        openFile.seek(0)
        self.assertEquals(mockStream.output, 'hello\n', "stream not passing on output.")
        self.assertEquals(openFile.read(), '', "stream unexpectedly writing to log file.")
        
        sys.stdout.write('hello\n', 6)
        openFile.seek(0)
        self.assertEquals(mockStream.output, 'hello\nhello\n', "stream not passing on output.")
        self.assertEquals(openFile.read(), 'hello\n', "stream not writing to log file.")
        openFile.close()


    def testStreamUnbuffered(self):
        mockStream = TrackStream()
        sys.stdout = mockStream
        stream = _Stream(sys.stdout, unbuffered=False)
        sys.stdout = stream
        self.assertFalse(mockStream.flushed, "Outputstream unexpectedly flushed")
        print 'hello'
        self.assertFalse(mockStream.flushed, "Outputstream unexpectedly flushed")
        
        sys.stdout = mockStream
        stream = _Stream(sys.stdout, unbuffered=True)
        sys.stdout = stream
        self.assertFalse(mockStream.flushed, "Outputstream unexpectedly flushed")
        print 'hello'
        self.assertTrue(mockStream.flushed, "Outputstream not flushed")


    def testStdoutDiversion(self):
        previousStream = sys.stdout
        mockStream = TrackStream()
        sys.stdout = mockStream
        standout = StandOut()
        self.assertNotEquals(sys.stdout, sys.__stdout__, "stdout not diverted")
        print 'hello'
        sys.stdout = previousStream
        self.assertEquals(mockStream.output, 'hello\n', "standout not passing on output.")


    def testClose(self):
        self.assertEquals(sys.stdout, sys.__stdout__, "Stdout unexpectedly diverted")
        self.assertEquals(sys.stderr, sys.__stderr__, "Stderr unexpectedly diverted")
        standout = StandOut()
        self.assertNotEquals(sys.stdout, sys.__stdout__, "Stdout unexpectedly not diverted")
        self.assertNotEquals(sys.stderr, sys.__stderr__, "Stderr unexpectedly not diverted")
        standout.close()
        self.assertEquals(sys.stdout, sys.__stdout__, "Stdout not restored")
        self.assertEquals(sys.stderr, sys.__stderr__, "Stderr not restored")


    def testLogFile(self):
        standout = StandOut(testFile)
        self.assertEquals(standout.logfile, testFile, "logfile attribute incorrectly set")
        self.assertTrue(os.path.isfile(testFile), "Log file not created")
        
        self.assertEquals(type(standout._logfile), file, "Log file not stored")
        self.assertEquals(standout._logfile.mode, 'w', "Stored file not in write mode")
        self.assertFalse(standout._logfile.closed, "Stored file unexpectedly closed")
        
        print 'hello'
        standout.close()
        self.assertTrue(standout._logfile.closed, "Stored file not closed")
        self.assertEquals(open(testFile).read(), 'hello\n', "Output not logged correctly")
        
        os.remove(testFile)
        standout = StandOut()
        self.assertEquals(standout.logfile, None, "Unexpected logfile value")
        self.assertEquals(standout._logfile, None, "Unexpected _logfile value")
        standout.close()
        self.assertFalse(os.path.isfile(testFile), "Stored file not closed")


    def testLogMode(self):
        open(testFile, 'w').write('Not Hello\n')
        standout = StandOut(testFile, logmode="w")
        self.assertEquals(standout.logfile, testFile, "logfile attribute incorrectly set")
        self.assertTrue(os.path.isfile(testFile), "Log file not created")
        
        self.assertEquals(type(standout._logfile), file, "Log file not stored")
        self.assertEquals(standout._logfile.mode, 'w', "Stored file not in write mode")
        self.assertFalse(standout._logfile.closed, "Stored file unexpectedly closed")
        
        print 'hello'
        standout.close()
        self.assertTrue(standout._logfile.closed, "Stored file not closed")
        self.assertEquals(open(testFile).read(), 'hello\n', "Output not logged correctly")

        standout = StandOut(testFile, logmode="a")
        self.assertEquals(standout.logfile, testFile, "logfile attribute incorrectly set")
        self.assertTrue(os.path.isfile(testFile), "Log file not created")
        
        self.assertEquals(type(standout._logfile), file, "Log file not stored")
        self.assertEquals(standout._logfile.mode, 'a', "Stored file not in append mode")
        self.assertFalse(standout._logfile.closed, "Stored file unexpectedly closed")
        
        print 'hello'
        standout.close()
        self.assertTrue(standout._logfile.closed, "Stored file not closed")
        self.assertEquals(open(testFile).read(), 'hello\nhello\n', "Output not appended")


    def testStdOutExplicit(self):
        standout = StandOut(stdout=False)
        self.assertEquals(sys.stdout, sys.__stdout__, "Stdout unexpectedly diverted")
        standout.close()
        
        standout = StandOut(testFile, stdout=False)
        print 'hello'
        standout.close()
        self.assertEquals(open(testFile).read(), '', "Logfile unexpectedly written to")

        standout = StandOut(stdout=True)
        self.assertNotEquals(sys.stdout, sys.__stdout__, "Stdout unexpectedly not diverted")
        standout.close()
        
        standout = StandOut(testFile, stdout=True)
        print 'hello'
        standout.close()
        self.assertEquals(open(testFile).read(), 'hello\n', "Logfile not written to")


    def testStdErrCreation(self):
        standout = StandOut()
        self.assertNotEquals(sys.stderr, sys.__stderr__, "Stderr not diverted")
        standout.close()
        standout = StandOut(stdout=True)
        self.assertNotEquals(sys.stderr, sys.__stderr__, "Stderr not diverted")
        standout.close()
        
        standout = StandOut(stderr=True)
        self.assertNotEquals(sys.stderr, sys.__stderr__, "Stderr not diverted")
        self.assertNotEquals(sys.stdout, sys.__stdout__, "Stdout unexpectedly not diverted")
        standout.close()
        self.assertEquals(sys.stderr, sys.__stderr__, "Stderr not restored")

        standout = StandOut(stderr=True, stdout=False)
        self.assertNotEquals(sys.stderr, sys.__stderr__, "Stderr not diverted")
        self.assertEquals(sys.stdout, sys.__stdout__, "Stdout unexpectedly diverted")
        standout.close()
        self.assertEquals(sys.stderr, sys.__stderr__, "Stderr not restored")

        standout = StandOut(stderr=False)
        self.assertEquals(sys.stderr, sys.__stderr__, "Stderr unexpectedly diverted")
        self.assertNotEquals(sys.stdout, sys.__stdout__, "Stdout unexpectedly not diverted")
        standout.close()
        self.assertEquals(sys.stdout, sys.__stdout__, "Stdout unexpectedly diverted")

        standout = StandOut(stderr=False, stdout=False)
        self.assertEquals(sys.stderr, sys.__stderr__, "Stderr unexpectedly diverted")
        self.assertEquals(sys.stdout, sys.__stdout__, "Stdout unexpectedly diverted")
        standout.close()
        self.assertEquals(sys.stdout, sys.__stdout__, "Stdout unexpectedly diverted")
        self.assertEquals(sys.stderr, sys.__stderr__, "Stderr unexpectedly diverted")


    def testStdErrDiversion(self):
        previousStream = sys.stderr
        mockStream = TrackStream()
        sys.stderr = mockStream
        standout = StandOut(stderr=True, stdout=False)
        self.assertNotEquals(sys.stderr, sys.__stderr__, "stderr not diverted")
        print 'hello'
        print >> sys.stderr, 'hello'
        sys.stderr = previousStream
        self.assertEquals(mockStream.output, '[err] hello\n', "standout not passing on output to stderr.")
        standout.close()
        
        previousErr = sys.stderr
        previousOut = sys.stdout
        mockErr = TrackStream()
        mockOut = TrackStream()
        sys.stderr = mockErr
        sys.stdout = mockOut
        standout = StandOut(stderr=True)
        self.assertNotEquals(sys.stderr, sys.__stderr__, "stderr not diverted")
        self.assertNotEquals(sys.stdout, sys.__stdout__, "stdout not diverted")
        print >> sys.stderr, 'hello'
        sys.stderr = previousErr
        sys.stdout = previousOut
        self.assertEquals(mockErr.output, '[err] hello\n', "standout not passing on output to stderr.")
        self.assertEquals(mockOut.output, '', "standout unexpectedly passing on output from stderr to stdout.")
        standout.close()
        
        standout = StandOut(testFile, stderr=True, stdout=False)
        print 'hello'
        print >> sys.stderr, 'hello'
        standout.close()
        self.assertEquals(open(testFile).read(), '[err] hello\n', "Logfile incorrectly written to")
        
        standout = StandOut(testFile, stderr=True)
        print 'hello'
        print >> sys.stderr, 'hello'
        standout.close()
        self.assertEquals(open(testFile).read(), 'hello\n[err] hello\n', "Logfile incorrectly written to")


    def testErrPrefix(self):
        previousStream = sys.stderr
        mockStream = TrackStream()
        sys.stderr = mockStream
        standout = StandOut(stderr=True, stdout=False)
        print >> sys.stderr, 'hello'
        errString = '[err] hello\n'
        self.assertEquals(mockStream.output, errString, "standout incorrectly passing on output to stderr.")
        
        print >> sys.stderr, 'hello again\nand again'
        errString += '[err] hello again\n[err] and again\n'
        self.assertEquals(mockStream.output, errString, "standout incorrectly passing on output to stderr.")
        
        sys.stderr.write('')
        self.assertEquals(mockStream.output, errString, "standout incorrectly passed on null string to stderr.")

        print >> sys.stderr, 'test1', 'test2'
        errString += '[err] test1 test2\n'
        self.assertEquals(mockStream.output, errString, "standout incorrectly passing on output to stderr.")

        sys.stderr.write('test3')
        errString += '[err] test3'
        self.assertEquals(mockStream.output, errString, "standout incorrectly passing on output to stderr.")
        sys.stderr.write('test4')
        errString += 'test4'
        self.assertEquals(mockStream.output, errString, "standout incorrectly passing on output to stderr.")

        standout.close()
        mockStream.output = ''
        standout = StandOut(stderr=True, stdout=False, errPrefix='[xxx] ')
        print >> sys.stderr, 'hello'
        errString = '[xxx] hello\n'
        self.assertEquals(mockStream.output, errString, "standout incorrectly passing on output to stderr.")
        
        print >> sys.stderr, 'hello again\nand again'
        errString += '[xxx] hello again\n[xxx] and again\n'
        self.assertEquals(mockStream.output, errString, "standout incorrectly passing on output to stderr.")
        
        sys.stderr.write('')
        self.assertEquals(mockStream.output, errString, "standout incorrectly passed on null string to stderr.")

        print >> sys.stderr, 'test1', 'test2'
        errString += '[xxx] test1 test2\n'
        self.assertEquals(mockStream.output, errString, "standout incorrectly passing on output to stderr.")

        sys.stderr.write('test3')
        errString += '[xxx] test3'
        self.assertEquals(mockStream.output, errString, "standout incorrectly passing on output to stderr.")
        sys.stderr.write('test4')
        errString += 'test4'
        self.assertEquals(mockStream.output, errString, "standout incorrectly passing on output to stderr.")
        standout.close()


    def testPriority(self):
        standout = StandOut(priority=5)
        self.assertEquals(standout.priority, 5, "incorrect value for standout.priority")
        standout.priority = 6
        self.assertEquals(standout.priority, 6, "incorrect value for standout.priority")
        standout.close()
        
        
        standout = StandOut(priority=4)
        self.assertEquals(standout.priority, 4, "incorrect value for standout.threshold")
        standout.priority = 3
        self.assertEquals(standout.priority, 3, "incorrect value for standout.threshold")
        standout.close()
        
        
        previousStream = sys.stdout
        mockStream = TrackStream()
        sys.stdout = mockStream
        standout = StandOut(priority=5)
        self.assertNotEquals(sys.stdout, sys.__stdout__, "stdout not diverted")
        print 'hello'
        self.assertEquals(mockStream.output, 'hello\n', "standout not passing on output.")
        
        standout.priority = 4
        print 'hello again'
        self.assertEquals(mockStream.output, 'hello\n', "standout passing on low priority output.")
        standout.close()
        
        mockStream.output = ''
        standout = StandOut(priority=4)
        self.assertNotEquals(sys.stdout, sys.__stdout__, "stdout not diverted")
        print 'hello'
        self.assertEquals(mockStream.output, '', "standout unexpectedly passing on output.")
        
        standout.priority = 5
        print 'hello'
        self.assertEquals(mockStream.output, 'hello\n', "standout not passing on output.")
        
        mockStream.output = ''
        sys.stdout.write('hello\n', 5)
        self.assertEquals(mockStream.output, 'hello\n', "stream.write not passing on output.")
        
        standout.close()
        sys.stdout = previousStream
        

    def testWriteWithPriority(self):
        previousStream = sys.stdout
        mockStream = TrackStream()
        sys.stdout = mockStream
        standout = StandOut()
        self.assertNotEquals(sys.stdout, sys.__stdout__, "stdout not diverted")
        
        sys.stdout.write('hello\n')
        self.assertEquals(mockStream.output, 'hello\n', "standout not passing on output.")
        mockStream.output = ''
        sys.stdout.write('hello\n', 5)
        self.assertEquals(mockStream.output, 'hello\n', "standout not passing on output.")
        mockStream.output = ''
        sys.stdout.write('hello\n', 4)
        self.assertEquals(mockStream.output, '', "standout unexpectedly passing on output.")
        mockStream.output = ''
        
        standout.close()
        sys.stdout = previousStream
        
        previousStream = sys.stderr
        mockStream = TrackStream()
        sys.stderr = mockStream
        # NB. This also tests threshold, but as the default error threshold
        # is zero it can't be helped
        standout = StandOut(stderr=True, stdout=False, threshold=5)
        self.assertNotEquals(sys.stderr, sys.__stderr__, "stderr not diverted")
        
        sys.stderr.write('hello\n')
        self.assertEquals(mockStream.output, '[err] hello\n', "standout not passing on errors.")
        mockStream.output = ''
        sys.stderr.write('hello\n', 5)
        self.assertEquals(mockStream.output, '[err] hello\n', "standout not passing on errors.")
        mockStream.output = ''
        sys.stderr.write('hello\n', 4)
        self.assertEquals(mockStream.output, '', "standout unexpectedly passing on errors.")
        mockStream.output = ''
        
        standout.close()
        sys.stdout = previousStream


    def testThreshold(self):
        standout = StandOut(threshold=5)
        self.assertEquals(standout.threshold, 5, "incorrect value for standout.threshold")
        standout.threshold = 6
        self.assertEquals(standout.threshold, 6, "incorrect value for standout.threshold")
        standout.close()
        
        standout = StandOut(threshold=4)
        self.assertEquals(standout.threshold, 4, "incorrect value for standout.threshold")
        standout.threshold = 3
        self.assertEquals(standout.threshold, 3, "incorrect value for standout.threshold")
        standout.close()
        
        previousStream = sys.stdout
        mockStream = TrackStream()
        sys.stdout = mockStream
        standout = StandOut(threshold=5)
        self.assertNotEquals(sys.stdout, sys.__stdout__, "stdout not diverted")
        print 'hello'
        self.assertEquals(mockStream.output, 'hello\n', "standout not passing on output.")
        
        standout.threshold = 6
        print 'hello'
        self.assertEquals(mockStream.output, 'hello\n', "standout passing on low priority output.")
        standout.close()
        
        mockStream.output = ''
        standout = StandOut(threshold=6)
        self.assertNotEquals(sys.stdout, sys.__stdout__, "stdout not diverted")
        print 'hello'
        self.assertEquals(mockStream.output, '', "standout unexpectedly passing on output.")
        
        standout.threshold = 5
        print 'hello'
        self.assertEquals(mockStream.output, 'hello\n', "standout not passing on output.")
        
        mockStream.output = ''
        sys.stdout.write('hello\n', 5)
        self.assertEquals(mockStream.output, 'hello\n', "stream.write not passing on output.")
        
        standout.close()
        sys.stdout = previousStream
        
        previousStream = sys.stderr
        mockStream = TrackStream()
        sys.stderr = mockStream
        standout = StandOut(threshold=5, stdout=False, stderr=True)
        self.assertNotEquals(sys.stderr, sys.__stderr__, "stderr not diverted")
        print >> sys.stderr, 'hello'
        self.assertEquals(mockStream.output, '[err] hello\n', "standout not passing on errors.")
        
        standout.threshold = 6
        print >> sys.stderr, 'hello'
        self.assertEquals(mockStream.output, '[err] hello\n', "standout passing on low priority errors.")
        standout.close()
        
        mockStream.output = ''
        standout = StandOut(threshold=6, stdout=False, stderr=True)
        self.assertNotEquals(sys.stderr, sys.__stderr__, "stderr not diverted")
        print >> sys.stderr, 'hello'
        self.assertEquals(mockStream.output, '', "standout unexpectedly passing on errors.")
        
        standout.threshold = 5
        print >> sys.stderr, 'hello'
        self.assertEquals(mockStream.output, '[err] hello\n', "standout passing on low priority errors.")
        standout.close()
        sys.stderr = previousStream
        
        # test logfileThreshold
        
        standout = StandOut(testFile, threshold=5)
        self.assertNotEquals(sys.stdout, sys.__stdout__, "stdout not diverted")
        print 'hello'
        standout.close()
        self.assertEquals(open(testFile).read(), 'hello\n', "standout not logging output.")
        
        standout = StandOut(testFile, threshold=6)
        self.assertNotEquals(sys.stdout, sys.__stdout__, "stdout not diverted")
        print 'hello'
        standout.close()
        self.assertEquals(open(testFile).read(), '', "standout unexpectedly logging output.")
        
        standout = StandOut(testFile, threshold=6)
        self.assertNotEquals(sys.stdout, sys.__stdout__, "stdout not diverted")
        print 'hello'
        sys.stdout.write('hello again\n', 6)
        standout.close()
        self.assertEquals(open(testFile).read(), 'hello again\n', "standout not logging output.")
        
        standout = StandOut(testFile, stdout=False, threshold=5)
        self.assertEquals(sys.stdout, sys.__stdout__, "stdout unexpectedly diverted")
        self.assertNotEquals(sys.stderr, sys.__stderr__, "stderr not diverted")
        print >> sys.stderr, 'hello'
        standout.close()
        self.assertEquals(open(testFile).read(), '[err] hello\n', "standout not logging output.")
        
        standout = StandOut(testFile, stdout=False, threshold=6)
        self.assertNotEquals(sys.stderr, sys.__stderr__, "stderr not diverted")
        print >> sys.stderr, 'hello'
        standout.close()
        self.assertEquals(open(testFile).read(), '', "standout unexpectedly logging output.")
        
        standout = StandOut(testFile, threshold=6)
        self.assertNotEquals(sys.stdout, sys.__stdout__, "stdout not diverted")
        print >> sys.stderr, 'hello'
        sys.stderr.write('hello again\n', 6)
        standout.close()
        self.assertEquals(open(testFile).read(), '[err] hello again\n', "standout not logging output.")


    def testErrAndOutThreshold(self):
        stand = StandOut()
        self.assertEquals(stand.errThreshold, 0, "unexpected value for stand.errThreshold")
        self.assertEquals(stand.threshold, -1, "unexpected value for stand.threshold")
        stand.close()
        
        stand = StandOut(outThreshold=0)
        self.assertEquals(stand.outThreshold, 0, "unexpected value for stand.errThreshold")
        self.assertEquals(stand.threshold, 0, "unexpected value for stand.threshold")
        stand.outThreshold = 5
        self.assertEquals(stand.outThreshold, 5, "unexpected value for stand.errThreshold")
        self.assertEquals(stand.threshold, -1, "unexpected value for stand.threshold")
        stand.errThreshold = 5
        self.assertEquals(stand.threshold, 5, "unexpected value for stand.threshold")
        stand.close()
        
        previousStream = sys.stdout
        mockStream = TrackStream()
        sys.stderr = mockStream
        stand = StandOut(errThreshold=5)
        print >> sys.stderr, 'hello'
        self.assertEquals(mockStream.output, '[err] hello\n', "StandOut not passing on error stream")
        sys.stderr.write('hello again\n', 4)
        self.assertEquals(mockStream.output, '[err] hello\n', "StandOut unexpectedly passing on error stream")
        self.assertEquals(stand.threshold, 5, "unexpected value for stand.threshold")
        self.assertEquals(stand.errThreshold, 5, "unexpected value for stand.errThreshold")
        stand.errThreshold = 4
        self.assertEquals(stand.threshold, -1, "unexpected value for stand.threshold")
        self.assertEquals(stand.errThreshold, 4, "unexpected value for stand.errThreshold")
        sys.stderr.write('hello again\n', 4)
        self.assertEquals(mockStream.output, '[err] hello\n[err] hello again\n', "StandOut unexpectedly passing on error stream")
        stand.close()


    def testLogfileThreshold(self):
        standout = StandOut(testFile, outLogfileThreshold=0, errLogfileThreshold=2)
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, -1)
        self.assertEquals(standout.outThreshold, -1)
        self.assertEquals(standout.outLogfileThreshold, 0)
        self.assertEquals(standout.errLogfileThreshold, 2)
        self.assertEquals(standout.outStreamThreshold, 5)
        self.assertEquals(standout.errStreamThreshold, 0)
        sys.stderr.write("hello, I'm an error\n", 1)
        sys.stdout.write("and I'm not\n", 1)
        standout.close()
        self.assertEquals(open(testFile).read(), "and I'm not\n", "standout not logging output correctly.")
        
        standout = StandOut(testFile, outLogfileThreshold=2, errLogfileThreshold=1)
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, -1)
        self.assertEquals(standout.outThreshold, -1)
        self.assertEquals(standout.outLogfileThreshold, 2)
        self.assertEquals(standout.errLogfileThreshold, 1)
        self.assertEquals(standout.outStreamThreshold, 5)
        self.assertEquals(standout.errStreamThreshold, 0)
        sys.stderr.write("hello, I'm an error\n", 1)
        sys.stdout.write("and I'm not\n", 1)
        standout.close()
        self.assertEquals(open(testFile).read(), "[err] hello, I'm an error\n",
                          "standout not logging output correctly.")
        

    def testStreamThreshold(self):
        mockStream = TrackStream()
        sys.stdout = mockStream
        standout = StandOut(outStreamThreshold=0, errStreamThreshold=2)
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, -1)
        self.assertEquals(standout.outThreshold, -1)
        self.assertEquals(standout.outStreamThreshold, 0)
        self.assertEquals(standout.errStreamThreshold, 2)
        self.assertEquals(standout.outLogfileThreshold, -1) # Should this raise an error ?
        self.assertEquals(standout.errLogfileThreshold, -1) # Should this raise an error ?
        sys.stderr.write("hello, I'm an error\n", 1)
        sys.stdout.write("and I'm not\n", 1)
        standout.close()
        self.assertEquals(mockStream.output, "and I'm not\n", "standout not logging output correctly.")
        
        sys.stderr = mockStream
        mockStream.output = ''
        standout = StandOut(outStreamThreshold=2, errStreamThreshold=1)
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, -1)
        self.assertEquals(standout.outThreshold, -1)
        self.assertEquals(standout.outStreamThreshold, 2)
        self.assertEquals(standout.errStreamThreshold, 1)
        self.assertEquals(standout.outLogfileThreshold, -1) # Should this raise an error ?
        self.assertEquals(standout.errLogfileThreshold, -1) # Should this raise an error ?
        sys.stderr.write("hello, I'm an error\n", 1)
        sys.stdout.write("and I'm not\n", 1)
        standout.close()
        self.assertEquals(mockStream.output, "[err] hello, I'm an error\n",
                          "standout not logging output correctly.")


    def testSettingProperties(self):
        standout = StandOut(testFile)
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, 0)
        self.assertEquals(standout.outThreshold, 5)
        self.assertEquals(standout.outStreamThreshold, 5)
        self.assertEquals(standout.errStreamThreshold, 0)
        self.assertEquals(standout.outLogfileThreshold, 5)
        self.assertEquals(standout.errLogfileThreshold, 0)
        
        standout.threshold = 5
        self.assertEquals(standout.threshold, 5)
        self.assertEquals(standout.errThreshold, 5)
        self.assertEquals(standout.outThreshold, 5)
        self.assertEquals(standout.outStreamThreshold, 5)
        self.assertEquals(standout.errStreamThreshold, 5)
        self.assertEquals(standout.outLogfileThreshold, 5)
        self.assertEquals(standout.errLogfileThreshold, 5)
        
        standout.errThreshold = 9
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, 9)
        self.assertEquals(standout.outThreshold, 5)
        self.assertEquals(standout.outStreamThreshold, 5)
        self.assertEquals(standout.errStreamThreshold, 9)
        self.assertEquals(standout.outLogfileThreshold, 5)
        self.assertEquals(standout.errLogfileThreshold, 9)
        
        standout.outThreshold = 6
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, 9)
        self.assertEquals(standout.outThreshold, 6)
        self.assertEquals(standout.outStreamThreshold, 6)
        self.assertEquals(standout.errStreamThreshold, 9)
        self.assertEquals(standout.outLogfileThreshold, 6)
        self.assertEquals(standout.errLogfileThreshold, 9)
        
        standout.errLogfileThreshold = 8
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, -1)
        self.assertEquals(standout.outThreshold, 6)
        self.assertEquals(standout.outStreamThreshold, 6)
        self.assertEquals(standout.errStreamThreshold, 9)
        self.assertEquals(standout.outLogfileThreshold, 6)
        self.assertEquals(standout.errLogfileThreshold, 8)
        
        standout.errStreamThreshold = 7
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, -1)
        self.assertEquals(standout.outThreshold, 6)
        self.assertEquals(standout.outStreamThreshold, 6)
        self.assertEquals(standout.errStreamThreshold, 7)
        self.assertEquals(standout.outLogfileThreshold, 6)
        self.assertEquals(standout.errLogfileThreshold, 8)
        
        standout.outLogfileThreshold = 3
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, -1)
        self.assertEquals(standout.outThreshold, -1)
        self.assertEquals(standout.outStreamThreshold, 6)
        self.assertEquals(standout.errStreamThreshold, 7)
        self.assertEquals(standout.outLogfileThreshold, 3)
        self.assertEquals(standout.errLogfileThreshold, 8)
        
        standout.outStreamThreshold = 2
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, -1)
        self.assertEquals(standout.outThreshold, -1)
        self.assertEquals(standout.outStreamThreshold, 2)
        self.assertEquals(standout.errStreamThreshold, 7)
        self.assertEquals(standout.outLogfileThreshold, 3)
        self.assertEquals(standout.errLogfileThreshold, 8)
        
        standout.close()
        
        standout = StandOut()
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, 0)
        self.assertEquals(standout.outThreshold, 5)
        self.assertEquals(standout.outStreamThreshold, 5)
        self.assertEquals(standout.errStreamThreshold, 0)
        self.assertEquals(standout.outLogfileThreshold, -1)
        self.assertEquals(standout.errLogfileThreshold, -1)
        
        standout.threshold = 5
        self.assertEquals(standout.threshold, 5)
        self.assertEquals(standout.errThreshold, 5)
        self.assertEquals(standout.outThreshold, 5)
        self.assertEquals(standout.outStreamThreshold, 5)
        self.assertEquals(standout.errStreamThreshold, 5)
        self.assertEquals(standout.outLogfileThreshold, -1)
        self.assertEquals(standout.errLogfileThreshold, -1)
        
        standout.errThreshold = 9
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, 9)
        self.assertEquals(standout.outThreshold, 5)
        self.assertEquals(standout.outStreamThreshold, 5)
        self.assertEquals(standout.errStreamThreshold, 9)
        self.assertEquals(standout.outLogfileThreshold, -1)
        self.assertEquals(standout.errLogfileThreshold, -1)
        
        standout.outThreshold = 6
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, 9)
        self.assertEquals(standout.outThreshold, 6)
        self.assertEquals(standout.outStreamThreshold, 6)
        self.assertEquals(standout.errStreamThreshold, 9)
        self.assertEquals(standout.outLogfileThreshold, -1)
        self.assertEquals(standout.errLogfileThreshold, -1)
        
        standout.errLogfileThreshold = 8
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, -1)
        self.assertEquals(standout.outThreshold, 6)
        self.assertEquals(standout.outStreamThreshold, 6)
        self.assertEquals(standout.errStreamThreshold, 9)
        self.assertEquals(standout.outLogfileThreshold, -1)
        self.assertEquals(standout.errLogfileThreshold, -1)
        
        standout.errStreamThreshold = 7
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, -1)
        self.assertEquals(standout.outThreshold, 6)
        self.assertEquals(standout.outStreamThreshold, 6)
        self.assertEquals(standout.errStreamThreshold, 7)
        self.assertEquals(standout.outLogfileThreshold, -1)
        self.assertEquals(standout.errLogfileThreshold, -1)
        
        standout.outLogfileThreshold = 3
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, -1)
        self.assertEquals(standout.outThreshold, -1)
        self.assertEquals(standout.outStreamThreshold, 6)
        self.assertEquals(standout.errStreamThreshold, 7)
        self.assertEquals(standout.outLogfileThreshold, -1)
        self.assertEquals(standout.errLogfileThreshold, -1)
        
        standout.outStreamThreshold = 2
        self.assertEquals(standout.threshold, -1)
        self.assertEquals(standout.errThreshold, -1)
        self.assertEquals(standout.outThreshold, -1)
        self.assertEquals(standout.outStreamThreshold, 2)
        self.assertEquals(standout.errStreamThreshold, 7)
        self.assertEquals(standout.outLogfileThreshold, -1)
        self.assertEquals(standout.errLogfileThreshold, -1)
        
        standout.close()


    def testUnbuffered(self):
        mockStream = TrackStream()
        sys.stdout = mockStream
        standout = StandOut(unbuffered=False)
        self.assertFalse(mockStream.flushed, "Outputstream unexpectedly flushed")
        print 'hello'
        self.assertFalse(mockStream.flushed, "Outputstream unexpectedly flushed")
        standout.close()
        
        standout = StandOut(unbuffered=True)
        self.assertFalse(mockStream.flushed, "Outputstream unexpectedly flushed")
        print 'hello'
        self.assertTrue(mockStream.flushed, "Outputstream not flushed")
        standout.close()


if __name__ == '__main__':
    try:
        main()
    except SystemExit:
        pass
    except Exception, e:
        traceback.print_exc()
    raw_input('>>> ')


"""

If there is no error stream, what should getting the errThreshold return ? (and
the converse if there is no output stream)

Should errPrefix be sent to the stream as well as the logfile ?

Should we be able to pass in an open file (or StringIO) as well as a filename ?

Stdout Attributes not implemented :

    next not proxied
    allow setting of softspace (and use it)
    implement flush ? (currently proxied to the real one)

"""
