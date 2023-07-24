import copy
import logging
import sys
import time
from argparse import ArgumentDefaultsHelpFormatter, ArgumentParser

from openpyxl import load_workbook

from ims import IMS, APIException


FORMAT = "%(asctime)s [%(levelname)s]: [%(module)s][%(funcName)s] %(message)s"
logging.basicConfig(level=logging.DEBUG, format=FORMAT, datefmt="%d/%m/%Y %H:%M:%S")
logger = logging.getLogger()  # pylint: disable=invalid-name


def get_exception_message(ex):
    if not isinstance(ex, Exception):
        #exc_info = sys.exc_info()
        #raise exc_info[0], exc_info[1], exc_info[2]
        return 'The exception is NOT a subtype of Exception!'

    message = ex.message
    if isinstance(ex, APIException):
        ex_resp = ex.response
        if ex_resp.work_items is not None:
            for work_item in ex_resp.work_items:
                if work_item.api_exception is not None:
                    message += '\n\t%s' % work_item.api_exception.message
                    message += '\n\t%s' % [str(field) for field in work_item.api_exception.fields]
    return message

def connect_ims(hostname, source, integrity, user, password):
    ims = IMS(hostname=hostname, portSI=source, portIM=integrity, no_retries=3, user=user, password=password)
    ims.connect_source()
    ims.connect_integrity()
    return ims

def extract_components(config_file):
    logger.debug('Parse components from "%s"', config_file)

    workbook = load_workbook(filename=config_file)
    # worksheet = workbook['Tabelle1']
    worksheet = workbook.worksheets[0]

    sheet_range = worksheet.calculate_dimension()
    logger.debug('Detected range to be parsed: %s', sheet_range)

    header = worksheet[sheet_range][0]
    logger.debug('%-15s%s', header[0].value, header[1].value)
    logger.debug('%s', '='*19)

    components = {}
    for component, config_path in worksheet[sheet_range][1:]:
        component = component.value
        config_path = config_path.value

        components[component] = config_path
        logger.debug('%-15s%s', component, config_path)
    return components

def create_reports(components_devpaths):
    timestamp = time.localtime()
    date = '{:4d}{:02d}{:02d}'.format(timestamp.tm_year, timestamp.tm_mon, timestamp.tm_mday)
    timeofday = '{:02d}{:02d}{:02d}'.format(timestamp.tm_hour, timestamp.tm_min, timestamp.tm_sec)
    configured = 'components_to_be_configured_{}_{}.txt'.format(date, timeofday)

    with open(configured, 'w') as stream:
        for component, devpath in components_devpaths.items():
            stream.write('{}\t{}\n'.format(component, devpath))

def expand_label_datetime(label, date, timeofday):
    label = label.replace('{date}', date)
    label = label.replace('{time}', timeofday)

    return label

def expand_label_component(label, component):
    label = label.replace('{component}', component)
    return label

def checkpoint_components(arguments):
    ims = connect_ims(arguments.hostname, arguments.source, arguments.integrity, arguments.user, arguments.password)

    label = arguments.label
    description = arguments.description
    config_file = arguments.config_file
    dry_run = arguments.dry_run

    components_devpaths = extract_components(config_file)
    create_reports(components_devpaths)

    timestamp = time.localtime()
    logger.debug('Timestamp: %s', time.strftime('Date %d.%m.%Y\tTime %H:%M:%S', timestamp))
    date = time.strftime('%Y%m%d', timestamp)
    timeofday = time.strftime('%H%M%S', timestamp)

    logger.debug('Label template for checkpoints: %s', label)
    logger.debug('Description template for checkpoints: %s', description)
    label = expand_label_datetime(label, date, timeofday)
    description = expand_label_datetime(description, date, timeofday)

    for component, config_path in components_devpaths.items():
        lbl = expand_label_component(label, component)
        descr = expand_label_component(description, component)
        if not dry_run:
            try:
                logger.debug('Checkpoint component "%s" ("%s")!', component, config_path)
                ims.checkpoint(batch=None, project=config_path, label=lbl, description=descr,
                               checkpointUnchangedSubprojects=None, nolabelUnchangedSubprojects=None)
            except APIException as ex:
                message = get_exception_message(ex)
                logger.error('Could NOT checkpoint component "%s" ("%s")!', component, config_path)
                logger.exception('Exception occurred: %s', message)
                # sys.exit(10)

def parse_arguments(argv):
    logger.info('Parsing the arguments...')
    parser = ArgumentParser(description='Checkpoint components on devpaths specified in xlsx file',
                            formatter_class=ArgumentDefaultsHelpFormatter)

    parser.add_argument('-d', '--dry_run', dest='dry_run', help='Dry run', default=False, action="store_true")

    parser.add_argument('-a', '--hostname', dest='hostname', help='IMS server', default='ims-adas')
    parser.add_argument('-o', '--source_port', dest='source', help='IMS source port', default='7001')
    parser.add_argument('-i', '--integrity_port', dest='integrity', help='IMS integrity port', default='7002')
    parser.add_argument('-u', '--user', dest='user', help='IMS user', default=None)
    parser.add_argument('-w', '--password', dest='password', help='IMS password', default=None)

    # parser.add_argument('-p', '--prj_path', dest='project_path', help='IMS project flat path', default=None,
    #                     required=True)
    # parser.add_argument('-s', '--prj_dp', dest='project_devpath', help='Source devpath', default=None, required=True)
    # parser.add_argument('-b', '--build_units', dest='build_units', help='Project build unit(s) to be configured',
    #                     default=None, nargs='*')

    parser.add_argument('-c', '--cp_description', dest='description', help='Description of checkpoint',
                        default='SW_{component}_{date}_{time}')
    parser.add_argument('-l', '--cp_label', dest='label', help='Label of checkpoint',
                        default='SW_{component}_{date}_{time}')
    parser.add_argument('-f', '--config_file', dest='config_file', help='Excel file containing components devpaths',
                        default=None, required=True)

    arguments = parser.parse_args(argv)
    args = copy.deepcopy(vars(arguments))
    if args['password']:
        args.update(password='********')
    logger.debug('Command line parameters: %s', args)
    return arguments

def main(argv):
    logger.debug('START')

    arguments = parse_arguments(argv)
    checkpoint_components(arguments)

    logger.debug('END')


if __name__ == "__main__":
    main(sys.argv[1:])
