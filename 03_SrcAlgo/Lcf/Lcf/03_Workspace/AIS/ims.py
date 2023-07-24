from collections import namedtuple, OrderedDict
from threading import Timer, _Timer
import subprocess
import traceback
import inspect
import logging
import time
import sys
import re
import os
import re
from shutil import copyfile

try:
    #import xml.etree.ElementTree as etree
    from lxml import etree
    print "running with lxml.etree"
except ImportError:
    try:
        # Python 2.5
        import xml.etree.cElementTree as etree
        print "running with cElementTree on Python 2.5+"
    #except Exception:
    #    #print sys.exc_info()
    #    pass
    except ImportError:
        try:
            # Python 2.5
            import xml.etree.ElementTree as etree
            print "running with ElementTree on Python 2.5+"
        except ImportError:
            try:
                # normal cElementTree install
                import cElementTree as etree
                print "running with cElementTree"
            except ImportError:
                try:
                    # normal ElementTree install
                    import elementtree.ElementTree as etree
                    print "running with ElementTree"
                except ImportError:
                    print "Failed to import ElementTree from any known place"

class TimeoutError(Exception):
    pass

class CommandError(Exception):
    pass

class APIVersion(object):

    API_4_10 = '4.10'
    API_4_11 = '4.11'
    API_4_12 = '4.12'
    API_4_13 = '4.13'
    API_4_14 = '4.14'
    API_4_15 = '4.15'
    API_4_16 = '4.16'

class CmdRunner(object):

    def __init__(self, hostname, port, version, localIntegrationPoint=True, user=None, password=None, impersonatedUser=None, vendor='mks'):

        self.hostname = hostname
        self.port = port
        self.version = version
        self.localIntegrationPoint = localIntegrationPoint
        self.user = user
        self.password = password
        
        self.impersonatedUser = impersonatedUser
        self.vendor = vendor
        #self.invocationID = self.vendor

    '''Interim functionality...
    def executeWithInterim(self, command, enableCache, vendor='mks'):
        pass
    def interrupt(self):
        pass
    def isFinished(self):
        pass
    '''

    def __str__(self):
        pass

    @staticmethod
    def kill_process(proc, command_string, timeout_occured):
        #TODO: Check here for deadlock!
        proc.kill()
        timeout_occured[0] = True
        logger.error('Timeout has occured on command: "%s". Operation cancelled.', command_string)

    def execute(self, command, timeout=None, show_time=False):
        # Inititialize 'mksapiviewer' command parameters
        options = []
        options.append('--iphostname=%s' % self.hostname)
        options.append('--ipport=%s' % self.port)
        if self.version:
            options.append('--ipversion="%s"' % self.version)
        if self.localIntegrationPoint:
            options.append('--iplocal')
            if self.user:
                options.append('--defaultuser="%s"' % self.user)
                if self.password:
                    options.append('--defaultpassword="%s"' % self.password)
            # when --iplocal is used hostname and port must be present in command as well so it will overwrite default client settings
            if not any('--hostname' in opt for opt in command.options):
                #print "There is no hostname in command's options!"
                command.add_option(hostname=self.hostname)
            if not any('--port' in opt for opt in command.options):
                #print "There is no port in command's options!"
                command.add_option(port=self.port)
        else:
            options.append('--namedsession')
            if self.user and self.password:
                options.append('--sessionuser="%s"' % self.user)
                options.append('--sessionpassword="%s"' % self.password)
                # when --namedsession is used user and password must be present in command as well
                if not any('--user' in opt for opt in command.options):
                    #print "There is no user in command's options!"
                    command.add_option(user=self.user)
                if not any('--password' in opt for opt in command.options):
                    #print "There is no password in command's options!"
                    command.add_option(password=self.password)
            else:
                raise ValueError('If --namedsession is specified (localIntegrationPoint == False) both user and password must be specified!') # AttributeError()
        options.append('--xml')

        cmd = '%s %s %s' % ('mksapiviewer', ' '.join(options) , str(command))
        #print 'Command: ' + cmd

        # Execute the command. Sometimes first time when you run the command it just returns, you need to run it again.
        tmpFile = command.command_name + '.xml'
        with open(tmpFile, 'w+') as f:
            #if exists, replace the password (and only the password) with '********'
            command_string = cmd
            pattern = '--(?:default)?password="(.*?)"' # handle both --defaultpassword and --password
            match = re.search(pattern, cmd)
            if match:
                psw = cmd[match.regs[1][0]:match.regs[1][1]]
                command_string = command_string.replace(psw, '*'*8)
            if show_time: logger.debug('mksAPIViewer command: %s', command_string)

            try:                
                if show_time: start = time.time()
                proc = subprocess.Popen(cmd, stdout = subprocess.PIPE, stderr = subprocess.PIPE) #s = cmd[:75]+'1'+cmd[75:], s = cmd[:1]+'1'+cmd[1:]
                timeout_occured = [False]
                #print '***TIMEOUT = %s***' % timeout
                if timeout: timer = Timer(timeout, CmdRunner.kill_process, [proc, command_string, timeout_occured])
                if timeout: timer.start()
                #initialize variabiles in case user manually stops the script before proc.communicate() call return
                stdout, stderr = ('Command not run/interrupted...', 'Command not run/interrupted...')
                stdout, stderr = proc.communicate()
            except WindowsError as e:
                logger.exception('Exception occurred: %s', e.strerror)
                pass
            except Exception as e:
                logger.exception('Exception occurred:')
                #print "Unexpected error:\n\t" + sys.exc_info()
                pass
            #else: TODO: Move here file generating...
            #    f.write(stdout)
            finally:
                #TODO: Check here for deadlock!
                #if isinstance(timer, _Timer):
                if timeout: timer.cancel()
                if show_time: end = time.time()
                if show_time: logger.debug('Time command "%s": %.2fs', command.command_name, end - start)
                f.write(stdout)

            f.seek(0)
            #UTF-8, UTF-16, US-ASCII, ISO-8859-1, ISO-8859-2, Big5
            #<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
            content = '<?xml version="1.1" encoding="ISO-8859-1" ?>\n' + ''.join([line for line in f.readlines()][1:])
            f.seek(0)
            f.write(content)

        # TODO: Properly handle this
        if timeout_occured[0]:
            errMessage = 'Command: "%s" timeouts (%.2fs)!' % (cmd, timeout)
            raise TimeoutError(errMessage)
        elif proc.returncode != 0:
            errMessage = 'Command: "%s" failed with the error: "%s" (code: %d)!' % (cmd, proc.stderr, proc.returncode)
            raise CommandError(errMessage)

        # Parse xml file and build the response
        start = time.time()
        resp = Response(tmpFile, command_string)
        #os.remove(tmpFile)
        end = time.time()
        if show_time: logger.debug('Time parsing response file (total): %.2fs', end - start)

        return resp

class Field(object):

    def __init__(self, elem):

        self.name = None
        self.value = None
        self.item = None
        self.item_list = None

        el = elem.find("./Value")
        if el is not None:
            self.name = elem.get('name')
            self.value = el.text if el.text is not None else '' # <Value></Value> => None
        el = elem.find("./Item")
        if el is not None:
            self.name = elem.get('name')
            self.item = Item(el)
        el = elem.find("./List")
        if el is not None:
            self.name = elem.get('name')
            self.item_list = []
            #<List elementType="item"></List>
            for i in el.findall('./Item'):
                self.item_list.append(Item(i))
            #TODO: Handle this better!
            for i in el.findall('./Value'):
                self.item_list.append(i.text)
                #break #only the first one will be returned

    def __str__(self):
        if self.value is not None:
            return '[Field] name = ' + self.name + '\n\tValue: ' + self.value
        elif self.item is not None:
            return '[Field] name = ' + self.name + '\n\t' + str(self.item)
        elif self.item_list is not None:
            if self.item_list:
                s = '\n\t' + '\n\t'.join(str(item) for item in self.item_list)
            else:
                s = ' []'
            return '[Field] name = ' + self.name + '\n\tList:' + s
        else:
            return None

class Dummy(object):
    def __init__(self, *args):
        pass

class FieldContainer(Dummy):

    def __init__(self, elem):
        """elem is supposed to have <Field> subelements."""
        #print 'FieldContainer: %s' % self.__class__
        super(FieldContainer, self).__init__(elem)
        self.fields = None
        if elem is None:
            return None

        self.fields = []
        for item in elem.findall("./Field"):
            self.fields.append(Field(item))
        #if not self.fields:
        #    self.fields = None        

    #def __iter__(self):
    #    pass

    def contains(self, id):
        for field in self.fields:
            if field.name == id:
                return True
        return False

    def getField(self, id):
        for field in self.fields:
            if field.name == id:
                return field

    '''Field functionality
    def getFieldListSize(self):
        return len(self.fields) if self.fields is not None else 0
    '''

class Result(FieldContainer):

    def __init__(self, item):

        #print 'Result: Before FieldContainer init'
        if item is None:
            return None
        result = item.find('Result')
        super(Result, self).__init__(result)
        #print 'Result: after FieldContainer init'

        self.message = None
        if result is not None:
            message = item.find('Message')
            if message is not None:
                self.message = message.text
            #print '***Message***\t' + self.message
            #self.primary_value = Item(result) #duplicate...
            #TODO: Get the field with name == 'resultant'
            self.primary_value = self.getField('resultant')

    def __str__(self):
        return str(self.primary_value)

class Item(FieldContainer):

    SI_PROJECT = "si.Project"
    SI_SUBPROJECT = "si.Subproject"
    SI_MEMBER = "si.Member"
    SI_REVISION = "si.Revision"
    SI_ARCHIVE = "si.Archive"
    SI_CHANGE_PACKAGE = "si.ChangePackage"
    SI_LOCK = "si.Lock"
    SI_USER = "si.User"

    def __init__(self, elem):
        #print 'Item: %s' % self.__class__
        self.context = elem.get('context', None)
        self.context_keys = None
        self.display_id = elem.get('displayId', None)
        self.id = elem.get('id', None)
        self.model_type = elem.get('modelType', None)
        self.parent_id = elem.get('parentID', None)
        return super(Item, self).__init__(elem)

    def __str__(self):
        # TODO: Proper message needed
        s = ''
        if self.fields:
            s = '\n\tFields:\n\t' + '\n\t'.join(str(field) for field in self.fields)
        #return self.context + self.display_id + self.id + self.model_type + self.parent_id + s
        attrib = ''
        if self.context is not None:
            attrib += ' context = ' + self.context
        if self.display_id is not None:
            attrib += ' displayId = ' + self.display_id
        if self.id is not None:
            attrib += ' id = ' + self.id
        if self.model_type is not None:
            attrib += ' modelType = ' + self.model_type
        return '[Item]:' + attrib + s

class APIException(FieldContainer, Exception):

    def __init__(self, api_exception, response=None):
        #print '\t\t\tAPIException Init begin'
        exception_class = api_exception.attrib['class']
        #print "Exception class: " + exception_class
        self.exception_class = exception_class
        message = api_exception.find('Message')
        if message is None:
            exception_message = 'Please see "response.work_items" for this exception!'
        else:
            exception_message = message.text
        #print "\tException message: " + exception_message
        self.message = exception_message
        self.response = response #linked response
        #print '\t\t\tAPIException Init end'
        #print 'APIException: %s\t%s' % (exception_class, response)
        super(APIException, self).__init__(api_exception) # only FieldContainer __init__ is called (Exception is not old-style object, but is implemented in C and store it's data internally differently)
        #self.args = (exception_class, self.fields)
        #print '\t\t\tAPIException Init after super (no "Inside FieldContainer" message?)'

class APIExceptionContainer(Dummy):

    def __init__(self, api_exception):
        #print 'APIExceptionContainer: %s\t%s' % (self.__class__, self.id)
        self.api_exception = None
        exception = api_exception.find('Exception')
        if exception is not None:
            self.api_exception = APIException(exception)
            #print self.api_exception.message + '\t' + str([str(field) for field in self.api_exception.fields])
        #super(APIExceptionContainer, self).__init__()

class WorkItemContainer(object):

    def __init__(self, elem, show_time=False):
        """elem is supposed to have <WorkItem> subelements."""
        self.work_items = None
        if elem is None:
            return None
        self.work_items = []

        if show_time: start = time.time()
        for item in elem.findall("./WorkItem"):
            self.work_items.append(WorkItem(item))
        #if not self.work_items:
        #    self.work_items = None
        if show_time: end = time.time()
        if show_time: logger.debug('Time parse work items: %.2fs', end - start)

    #def __iter__(self):
    #    pass

    '''WorkItem functionality
    def containsWorkItem(self, id, context=None):
        pass

    def getWorkItem(self, id, context=None):
        pass

    def getWorkItemListSize(self):
        return len(self.work_items) if self.work_items is not None else 0
    '''

class WorkItem(Item, APIExceptionContainer):

    def __init__(self, elem):
        #print 'WorkItem: %s' % self.__class__
        self.result = Result(elem)
        return super(WorkItem, self).__init__(elem)
    
class Response(WorkItemContainer):
    subproject = 'si.Subproject'
    member = 'si.Member'

    def __init__(self, xml_file, command_string, show_time=False):

        #self.xml_file = xml_file
        self.command_string = command_string
        self.exit_code = 0
        self.api_exception = None
        #self.subroutines = None

        try:
            if show_time: start = time.time()
            #parser = etree.XMLParser(encoding="UTF-8")
            #tree = etree.parse(xml_file, parser=parser)
            tree = etree.parse(xml_file)
            if show_time: end = time.time()
            if show_time: logger.debug('Time ET.parse: %.2fs', end - start)
        except etree.ParseError:
            #print sys.exc_info()
            logger.error('For some reasons sometimes the server returns an empty response for connect command...')
            exc_info = sys.exc_info()
            raise exc_info[0], exc_info[1], exc_info[2]
        '''https://docs.python.org/2.7/library/traceback.html#traceback.print_stack
        except:
            traceback.print_stack()
            print '_'*70
            print traceback.print_exc()
            print '_'*70
            print sys.exc_info()
        '''

        root = tree.getroot()
        
        self.application_name = root.attrib['app']
        self.api_version = root.attrib['version']
        self.command_name = root.attrib['command']

        connection = root.find('App-Connection')
        if connection is not None:
            self.connection_hostname = connection.attrib['server']
            self.connection_port = connection.attrib['port']
            self.connection_username = connection.attrib['userID']
        else:
            self.connection_hostname = self.connection_port = self.connection_username = None

        result = root #we search for a 'Result' element in Result.__init__ (item.find('Result'))
        self.result = Result(result)

        work_items = root.find('WorkItems')
        #print work_items.attrib['selectionType']
        #start = time.time()
        #self.work_items = self._parse_work_items(work_items)
        #end = time.time()
        #print 'Time parse work items: ', end - start
        super(Response, self).__init__(work_items) #, self
        
        api_exception = root.find('Exception')
        #self.api_exception = self._parse_api_exception(api_exception)
        if api_exception is not None:
            self.api_exception = APIException(api_exception, self)

        exit_code = root.find('ExitCode').text
        self.exit_code = int(exit_code)
        #print "ExitCode: " + exit_code
        if self.api_exception is not None:
            #print 'Exception message: ' + self.api_exception.message
            #print 'Exception message: ' + str(self.api_exception.args)
            raise self.api_exception
            pass
        #'''TODO: Check if it is possible to initialize here "self.api_exception" and throw it. Find a better location to throw it, or consider it ok to ignore.
        elif self.work_items is not None:
            for wi in self.work_items:
                if wi.api_exception is not None:
                    wi.api_exception.response = self
                    raise wi.api_exception
            else:
                #self.api_exception = APIException('Create dummy xml exception!', self)
                pass            
        #'''
        
    #def getCommandString(self):
    #    return self.command

    '''InvocationID functionality
    def getInvocationID(self):
        return self.invocationID
    def interrupt():
        pass
    '''
    '''WorkItem functionality
    def containsWorkItem(self, id, context=None):
        pass
    def getWorkItem(self, id, context=None):
        pass
    def getWorkItemListSize(self):
        return len(self.workitems)
    '''
    '''Subrutine functionality
    def containsSubRoutine(self, name):
        pass
    def getSubRoutine(self, name):
        pass
    def getSubRoutineListSize(self):
        return len(self.subroutines)
    def getSubRoutines(self):
        self.subroutines = SubRoutines(xml_file) #load only first time
        return self.subroutines
    '''
    '''Parsing objects...
    @staticmethod
    def _parse_work_items(work_items):
        if work_items is None:
            return None

        wi = []
        for work_item in work_items.getchildren(): #iter('WorkItem'):
            if work_item.attrib['modelType'] == Response.subproject:
                wi.append(work_item.attrib['id'])
                #print work_item.attrib['id']
            elif work_item.attrib['modelType'] == Response.member:
                #print work_item[0][0].text
                """
                for field in work_item.findall('Field'): #[:]
                    if field.attrib['name'] == 'name':
                        for value in field.findall('Value'): #[:]
                            if value.attrib['dataType'] == 'string':
                                print value.text

                for field in work-item.iter('Field'):
                    if field.get('name') == 'name':
                        for value in field.iter('Value'):
                            if value.get('dataType') == 'string':
                                print value.text
                """
                for value in work_item.findall("./Field[@name='name']/Value"): #[@dataType='string']
                    wi.append(value.text)
                    #print value.text
        return wi

    @staticmethod
    def _parse_api_exception(api_exception):
        if api_exception is None:
            return None

        exception_class = api_exception.attrib['class']
        #print "Exception class: " + exception_class
        exception_message = api_exception.find('Message').text
        #print "\tException message: " + exception_message
        options = OrderedDict()
        for field in api_exception.findall('Field'):
            for value in field.findall('Value'):
                if value.attrib['dataType'] == 'string':
                    options[field.attrib['name']] = value.text
                    #print '\t%s: %s' % (field.attrib['name'], value.text)
        return APIException(exception_message, exception_class, options)
    '''

class ProjectType(object):

    NORMAL = 'Normal'
    BUILD = 'Build'
    VARIANT = 'Variant'

class ShareType(object):

    ARCHIVED = 'archived'
    SUBPROJECT = 'subproject' # normal subproject
    BUILD_SUBPROJECT = 'build-subproject' # if it is under 'shared-build-subproject' or if it was configured as so (revision/checkpoint)
    VARIANT_SUBPROJECT = 'variant-subproject' # subprojects under this won't be 'shared-subproject'
    SHARED_SUBPROJECT = 'shared-subproject' # shared normal project
    SHARED_BUILD_SUBPROJECT = 'shared-build-subproject' # subprojects under this will be 'build-subproject'
    SHARED_VARIANT_SUBPROJECT = 'shared-variant-subproject'
    PENDING_CONFIGURE_SUBPROJECT = 'pending-configure-subproject'

class State(object):

    NEW = 'New'
    PLANNED = 'Planned'
    OBSOLETE = 'Obsolete'
    CANCELED = 'Canceled'
    REALIZED = 'Realized'
    INTEGRATED = 'Integrated'
    TESTED = 'Tested'
    RELEASED = 'Released'
    CLOSED = 'Closed'

class ChangePackageState(object):

    OPEN = 'Open'
    CLOSED = 'Closed'
    SUBMITTED = 'Submitted'
    REJECTED = 'Rejected'
    ACCEPTED = 'Accepted'
    COMMITFAILED = 'CommitFailed'
    DISCARDED = 'Discarded'

class Command(object):
    """Class used to represent a command. Each Command object will have any number of options and an optional selection."""
    SI = 'si'
    IM = 'im'
    AA = 'aa'
    TM = 'tm'
    RQ = 'rq'
    WF = 'wf'
    SD = 'sd'
    INTEGRITY = 'integrity'
    NONE_CP_ID = 'none_cp_id'
    apps = [SI, IM, AA, TM, RQ, WF, SD, INTEGRITY, NONE_CP_ID]

    def __init__(self, app, command_name, vendor=None):

        if app.lower() not in self.apps:
            raise ValueError('Parameter "app" must one of {}!'.format(self.apps))
        if not command_name:
            raise ValueError('Parameter "command_name" must be non empty!')
        self.app = app
        self.command_name = command_name
        self.vendor = vendor
        self.options = [] # each item is a str that has an option prefix (- or --), a command name and optionally a value enclosed in "" (prefixed by =, can be empty)
        self.selections = [] # each item is a str enclosed in ""

    def __str__(self):
        cmd = '%s %s' % (self.app, self.command_name)
        opts = ' '.join(self.options)
        if opts: cmd += ' ' + opts
        sels = ' '.join(self.selections)
        if sels: cmd += ' ' + sels

        return cmd

    def add_option(self, **kwargs):
        """Add each key-value pair parameter in options list formatted as '-[-]key[=value]'. Also remove suffix '_NUMBER' from key name, if applicable."""
        for key, value in kwargs.iteritems():
            numbers = [number.span() for number in re.finditer(r'\d+', key)]
            if len(numbers) and numbers[-1][1] == len(key) and key[numbers[-1][0]-1] == '_':
                key = key[:numbers[-1][0]-1]
            opt = '-%s%s' % ('-' * (len(key) > 1), key)
            if value != None:
                opt += '="%s"' % value
            self.options.append(opt)
        
    def add_selection(self, *args):
        """Add each paramater in selections list enclosed in double quotes."""
        for arg in args:
            sel = '"%s"' % arg
            self.selections.append(sel)

class IMS(object):
    """Provides a wrapper for 'mksAPIViewer.exe'."""
    def __init__(self, hostname, portSI, portIM, no_retries=None, timeout=None, version=None, localIntegrationPoint=True, user=None, password=None): #, loggerName=None

        #self.hostname = hostname
        self.portSI = portSI #port
        self.portIM = portIM #port[:-1]+str(int(port[-1])+1)
        self.no_retries = no_retries
        self.timeout_default = timeout
        #self.localIntegrationPoint = localIntegrationPoint
        self.version = version # APIVersion.API_4_16
        #self.user = user
        #self.password = password

        #if loggerName:
        #self.logger = logging.getLogger(loggerName)
        
        self.cmdRunner = CmdRunner(hostname, portSI, version, localIntegrationPoint, user, password)

    def connect_source(self, *args, **kwargs):
        #try:
            resp = self._parse_option(Command.SI, 'connect', *args, **kwargs) #app=Command.SI, command_name='connect'
            return resp
        #except:
        #    logger.exception('Exception occurred:')
            pass

    def connect_integrity(self, *args, **kwargs):
        resp = self._parse_option(Command.IM, 'connect', *args, **kwargs)
        return resp

    @staticmethod
    def whoami():
        return inspect.stack()[1][3]

    def viewproject(self, *args, **kwargs):
        """No need to specify hostname, port, user or password."""
        #try:
        resp = self._parse_option(Command.SI, 'viewproject', *args, **kwargs) # inspect.stack()[0][3], self.whoami(), self.viewproject.__name__
        return resp
        #except:
        #    logger.exception('Exception occurred:')
        pass

    def disconnect_source(self, *args, **kwargs):
        #try:
            resp = self._parse_option(Command.SI, 'disconnect', *args, **kwargs)
            return resp
        #except:
        #    logger.exception('Exception occurred:')
            pass

    def locate(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'locate', *args, **kwargs)
        return resp

    def projectinfo(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'projectinfo', *args, **kwargs)
        return resp

    def viewissue(self, *args, **kwargs):
        resp = self._parse_option(Command.IM, 'viewissue', *args, **kwargs)
        return resp

    def issues(self, *args, **kwargs):
        resp = self._parse_option(Command.IM, 'issues', *args, **kwargs)
        return resp

    def lock(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'lock', *args, **kwargs)
        return resp

    def unlock(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'unlock', *args, **kwargs)
        return resp

    def projectadd(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'projectadd', *args, **kwargs)
        return resp

    def projectco(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'projectco', *args, **kwargs)
        return resp

    def projectci(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'projectci', *args, **kwargs)
        return resp

    def sandboxes(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'sandboxes', *args, **kwargs)
        return resp

    def createsandbox(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'createsandbox', *args, **kwargs)
        return resp

    def dropsandbox(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'dropsandbox', *args, **kwargs)
        return resp

    def co(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'co', *args, **kwargs)
        return resp

    def ci(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'ci', *args, **kwargs)
        return resp

    def archiveinfo(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'archiveinfo', *args, **kwargs)
        return resp

    def configuresubproject(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'configuresubproject', *args, **kwargs)
        return resp

    def checkpoint(self, *args, **kwargs):
        try:
            #TODO: Recheck this.
            resp = self._parse_option(Command.SI, 'checkpoint', *args, **kwargs)
        except APIException as e:
            if e.getField('exception-name').value != 'common.CommandPanic':
                exc_info = sys.exc_info()
                raise exc_info[0], exc_info[1], exc_info[2]
            else:
                logger.error('IGNORE Checkpointing Exception: "%s"!', e.message)
                return e.response
        else:
            return resp
    
    def resync(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'resync', *args, **kwargs)
        return resp

    def viewnonmembers(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'viewnonmembers', *args, **kwargs)
        return resp

    def viewprojecthistory(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'viewprojecthistory', *args, **kwargs)
        return resp

    def addlabel(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'addlabel', *args, **kwargs)
        return resp

    def addprojectlabel(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'addprojectlabel', *args, **kwargs)
        return resp

    def viewlabels(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'viewlabels', *args, **kwargs)
        return resp

    def updaterevision(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'updaterevision', *args, **kwargs)
        return resp

    def memberinfo(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'memberinfo', *args, **kwargs)
        return resp

    def viewcp(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'viewcp', *args, **kwargs)
        return resp

    def createcp(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'createcp', *args, **kwargs)
        return resp

    def editcp(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'editcp', *args, **kwargs)
        return resp

    def closecp(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'closecp', *args, **kwargs)
        return resp

    def submitcp(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'submitcp', *args, **kwargs)
        return resp

    def acceptcp(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'acceptcp', *args, **kwargs)
        return resp

    def opencp(self, *args, **kwargs):
        resp = self._parse_option(Command.SI, 'opencp', *args, **kwargs)
        return resp

    def _parse_option(self, app, command_name, *args, **kwargs):
        cmd = Command(app, command_name)
        cmd.add_option(**kwargs)
        cmd.add_selection(*args)
        #print 'IMS command: ' + str(cmd)

        if cmd.app == Command.IM:
            self.cmdRunner.port = self.portIM
        else:
            self.cmdRunner.port = self.portSI

        retries = self.no_retries
        while True:
            exc_info = None
            response = None
            try:
                response = self.cmdRunner.execute(cmd, timeout=self.timeout_default, show_time=True)
            except APIException as e:
                logger.exception('Exception occurred: %s', e.message)
                exception_name = e.getField('exception-name').value
                if exception_name == 'si.ProjectBusy': # special retry
                    logger.info('Wait a little bit more to be sure (60s)...')
                    time.sleep(60)
                    exc_info = sys.exc_info()
                elif exception_name in ['si.ProjectNotRegistered', 'si.NoSuchSubproject'] and command_name == 'locate':
                    logger.warning('Disable retry functionality for "locate" command (exceptions: si.ProjectNotRegistered and si.NoSuchSubproject) ["%s"]...', exception_name)
                    exc_info = sys.exc_info()
                    retries = 0
                elif exception_name == 'common.ViewWarnings' and command_name == 'locate':
                    logger.warning('Disable retry functionality for "locate" command (exceptions: common.ViewWarnings {governorLimitReached, hasFilteredRecords}...')
                    exc_info = sys.exc_info()
                    retries = 0
                elif exception_name in ['si.ProjectNotRegistered', 'si.NoSuchSubproject'] and command_name == 'projectinfo': #e.exception_class == 'ItemNotFoundException' and 
                    logger.warning('Disable retry functionality for "projectinfo" command (exceptions: si.ProjectNotRegistered and si.NoSuchSubproject). Possibly subproject was dropped from the location in the meantime...')
                    exc_info = sys.exc_info()
                    retries = 0
                elif exception_name in ['common.CommandFailed', 'si.GeneralFailure'] and command_name == 'acceptcp':
                    logger.warning('Disable retry functionality for "acceptcp" command (exceptions: common.CommandFailed and si.GeneralFailure) ["%s"]...', exception_name)
                    exc_info = sys.exc_info()
                    retries = 0
                else:
                    exc_info = sys.exc_info()
            except TimeoutError as e:
                logger.exception('Exception occurred:')
                exc_info = sys.exc_info()
            except Exception as e:
                logger.exception('Exception occurred:')
                exc_info = sys.exc_info()
            else:
                break
            finally:
                if exc_info:
                    if retries == 0:
                        #TODO: Make a copy of the file in case of error...
                        tmpFile = command_name + '.xml'
                        t = time.localtime()
                        timestamp = '_error_%d%02d%02d_%02d%02d%02d' % (t.tm_year, t.tm_mon, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec)
                        root, ext = os.path.splitext(tmpFile)
                        new_file = root + timestamp + ext
                        copyfile(tmpFile, new_file)

                        raise exc_info[0], exc_info[1], exc_info[2]
                    logger.info('Wait for 10s and retry %s/%s...', self.no_retries - retries + 1, self.no_retries)
                    time.sleep(10)
                elif not exc_info and retries < self.no_retries:
                    logger.info('Retrying really works!')
                retries -= 1

        return response


logger = logging.getLogger('ims')

def init_logging(loggerName):
    global logger
    logger = logging.getLogger(loggerName)
    #return logger
    