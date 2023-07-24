"""
stk/io/bsig
--------

Binary Signal Read Class

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:58:04CET $
"""


# Imports -------------------------------------------------------------------------------------------------------------
from ctypes import c_int8, memmove, c_float, c_uint8, c_double, byref, c_int16, c_uint16, c_int32, c_int64, \
    c_uint32, c_uint64
import os
import struct
import zlib

DEFAULT_SIGNATURE = 'BIN\0'
HDR_SIZE = 24
MAX_VERSION = {'Major': 1, 'Minor': 1, 'Patch': 0}


def TypeToSize(sType):
    if(sType == 0):  # Unknown
        return -1
    elif(sType == 1):  # U8
        return 1
    elif(sType == 2):  # I8
        return 1
    elif(sType == 3):  # U16
        return 2
    elif(sType == 4):  # I16
        return 2
    elif(sType == 5):  # U32
        return 4
    elif(sType == 6):  # I32
        return 4
    elif(sType == 7):  # U64
        return 8
    elif(sType == 8):  # I64
        return 8
    elif(sType == 9):  # FLT
        return 4
    elif(sType == 10):  # DBL
        return 8

# Class ---------------------------------------------------------------------------------------------------------------


class file_bsig(file):
    """
    Class for Binary Signal File Read. (*.bsig)
    Base class for File I/O Handling and conversion of Signal Data

    :note:          usage : ...

    :author:        Robert Hecker
    """
    def __init__(self, Filename, mode):
        file.__init__(self, Filename, mode)

    def __del__(self):
        pass

    def read_sig(self, sType):

        if(sType == 0):  # Unknown
            return self.read_ui8()
        elif(sType == 1):  # U8
            return self.read_ui8()
        elif(sType == 2):  # I8
            return self.read_i8()
        elif(sType == 3):  # U16
            return self.read_ui16()
        elif(sType == 4):  # I16
            return self.read_i16()
        elif(sType == 5):  # U32
            return self.read_ui32()
        elif(sType == 6):  # I32
            return self.read_i32()
        elif(sType == 7):  # U64
            return self.read_ui64()
        elif(sType == 8):  # I64
            return self.read_i64()
        elif(sType == 9):  # FLT
            return self.read_flt()
        elif(sType == 10):  # DBL
            return self.read_dbl()

    def read_str(self):
        """
        Read String Len
        """
        # Read String
        return file.read(self, struct.unpack('L', file.read(self, 4))[0])

    def read_ui8(self):
        """
        Read unsigned char
        """
        return struct.unpack('B', file.read(self, 1))[0]

    def read_i8(self):
        """
        Read signed char
        """
        return struct.unpack('b', file.read(self, 1))[0]

    def read_ui16(self):
        """
        Read unsigned short
        """
        return struct.unpack('H', file.read(self, 2))[0]

    def read_i16(self):
        """
        Read signed short
        """
        return struct.unpack('h', file.read(self, 2))[0]

    def read_ui32(self):
        """
        Read unsigned long
        """
        return struct.unpack('L', file.read(self, 4))[0]

    def read_i32(self):
        """
        Read signed long
        """
        return struct.unpack('l', file.read(self, 4))[0]

    def read_ui64(self):
        """
        Read unsigned __int64
        """
        return struct.unpack('Q', file.read(self, 8))[0]

    def read_i64(self):
        """
        Read signed __int64
        """
        return struct.unpack('q', file.read(self, 8))[0]

    def read_dbl(self):
        """
        Read double
        """
        return struct.unpack('d', file.read(self, 8))[0]

    def read_flt(self):
        """
        Read float
        """
        return struct.unpack('f', file.read(self, 4))[0]


class bsig_100:
    """
    Class for Binary Signal File Read. (*.bsig)
    Class for Reading Binary Signal Files Version 1.0.0

    :note:          usage : ...

    :author:        Robert Hecker
    """
    def __init__(self, bsig_100):
        """
        Initialize all unused Variables
        """
        self.__f = bsig_100
        self.__NumSignals = 0
        self.__DataOffset = 0
        self.__data = {}
        self.__data2 = []
        self._NumRows = 0
        self.__Rowsize = 0
        self.__startoffset = 0

    def __del__(self):
        pass

    def __read_signal_hdr_blk(self):
        """
        ReadSignalName
        """
        name = self.__f.read_str()

        # ReadSignalSize
        size = self.__f.read_ui32()

        # Read Signal Type
#        sType = self.__f.read_ui8()

        jumplen = 0

        self.__data[name] = [size, type, self.__startoffset, jumplen]
        self.__data2.append(name)
        self.__startoffset += size  # TypeToSize(type)

    def read_file_header(self):
        """
        Read Number of Signals
        """
        self.__NumSignals = self.__f.read_ui64()
        self.__startoffset = 0

        for _ in range(0, self.__NumSignals):
            self.__read_signal_hdr_blk()

        # Remember current File Pos
        self.__DataOffset = self.__f.tell()

        self.__f.seek(0, 2)
        size = self.__f.tell()
        self.__f.seek(self.__DataOffset)

        for item in self.__data:
            self.__Rowsize = self.__Rowsize + self.__data[item][0]

        # Calculate Jumplen
        for item in self.__data2:
            self.__data[item][3] = self.__Rowsize - self.__data[item][0]

        self._NumRows = (size - self.__DataOffset) / self.__Rowsize

    def get_num_signals(self):
        return self.__NumSignals

    def get_signal_name(self, idx):
        return self.__data2[idx]

    def get_signal_by_name(self, name):
        data = []
        jumplen = self.__data[name][3]
#        sType = self.__data[name][1]

        # Go to start of Data Section
        self.__f.seek(self.__DataOffset + self.__data[name][2])

        for _ in range(0, self._NumRows):
            # Read Data Element
            if self.__data[name][0] > TypeToSize(type):
                tmp = []
                for _ in range(0, self.__data[name][0] / TypeToSize(type)):
                    tmp.append(self.__f.read_sig(type))
                data.append(tmp)
            else:
                data.append(self.__f.read_sig(type))
            # Jump to Next Element
            self.__f.seek(jumplen, 1)

        return data

    def get_signal_by_index(self, idx):
        return self.get_signal_by_name(self.__data2[idx])

    def get_signals_by_list(self, names):

        data = []
        for item in names:
            data.append(self.get_signal_by_name(item))

        return data


# try:
#     from exceptions import StandardError as _BaseException
# except ImportError:
#     _BaseException = Exception


class bsig_200_exception(StandardError):
    def __init__(self, description):
        self.__description = str(description)

    def __str__(self):
        errror_description = "=====================================================\n"
        errror_description += "ERROR: " + self.__description
        errror_description += "\n=====================================================\n"
        return str(errror_description)

    def Description(self):
        return self.__description


class bsig_200:
    """Class constructor.
    """
    def __init__(self):
        self.__block_size = 0
        self.__file_size = 0
        self.__hdr_size = 0
        self.__hdr_offset = 0
        self.__signals_count = 0
        self.__index_table_size = 0
        self.__index_table_offset = 0
        self.__index_table = None
        self.__f = None
        self.__file_name = ''
        self.__signal_data = []
        self.__bCompression = False
        self.__version = {'Major': 0, 'Minor': 0, 'Patch': 0}

    def __del__(self):
        self.close()

    def read_file_header(self):
        """ Just for compatibility with bsig_100
        """
        pass

    def __get_signal_format_str(self, sType):
        """Function returns the format string needed for unpacking the binary data.

        :param sType: The type of the signal. The values match eDataType define in
                     CSignalData as defined in gex_datawriterifc.h.

        """
        if sType == 32776:
            return 'b'
        elif sType == 32784:
            return 'h'
        elif sType == 32800:
            return 'l'
        elif sType == 32832:
            return 'q'
        elif sType == 8:
            return 'B'
        elif sType == 16:
            return 'H'
        elif sType == 32:
            return 'L'
        elif sType == 64:
            return 'Q'
        elif sType == 36880:
            return 'f'
        elif sType == 36896:
            return 'd'
        else:
            raise bsig_200_exception("Unknown format.")

    def __get_signal_type_size(self, sType):
        """Function returns the size of a signal sample with the specified type.

        :param sType: The type of the signal. The values match eDataType define
                     in CSignalData as defined in gex_datawriterifc.h
        """
        if sType == 32776:
            return 1
        elif sType == 32784:
            return 2
        elif sType == 32800:
            return 4
        elif sType == 32832:
            return 8
        elif sType == 8:
            return 1
        elif sType == 16:
            return 2
        elif sType == 32:
            return 4
        elif sType == 64:
            return 8
        elif sType == 36880:
            return 4
        elif sType == 36896:
            return 8
        else:
            raise bsig_200_exception("Unknown format.")

    def __read_i8(self, count=1):
        """Function reads and returns the specified count of i8 items.

       :param count: The number of items to read. By default 1 item will be read.
       """
        value = []
        fmt = 'b'
        try:
            for _ in range(count):
                bin_data = self.__f.read(1)
                value.append(struct.unpack(fmt, bin_data)[0])
        except:
            raise bsig_200_exception("An error occured while unpacking binary data.")
        return value

    def __read_ui8(self, count=1):
        """Function reads and returns the specified count of ui8 items.

       :param count: The number of items to read. By default 1 item will be read.
       """
        value = []
        fmt = 'B'
        try:
            for _ in xrange(count):
                bin_data = self.__f.read(1)
                value.append(struct.unpack(fmt, bin_data)[0])
        except:
            raise bsig_200_exception("An error occured while unpacking binary data.")
        return value

    def __read_i16(self, count=1):
        """Function reads and returns the specified count of i16 items.

       :param count: The number of items to read. By default 1 item will be read.
       """
        value = []
        fmt = 'h'
        try:
            for _ in xrange(count):
                bin_data = self.__f.read(2)
                value.append(struct.unpack(fmt, bin_data)[0])
        except:
            raise bsig_200_exception("An error occured while unpacking binary data.")
        return value

    def __read_ui16(self, count=1):
        """Function reads and returns the specified count of ui16 items.

        :param count: The number of items to read. By default 1 item will be read.
        """
        value = []
        fmt = 'H'
        try:
            for _ in xrange(count):
                bin_data = self.__f.read(2)
                value.append(struct.unpack(fmt, bin_data)[0])
        except:
            raise bsig_200_exception("An error occured while unpacking binary data.")
        return value

    def __read_i32(self, count=1):
        """Function reads and returns the specified count of i32 items.

        :param count: The number of items to read. By default 1 item will be read.
        """
        value = []
        fmt = 'i'
        try:
            for _ in xrange(count):
                bin_data = self.__f.read(4)
                value.append(struct.unpack(fmt, bin_data)[0])
        except:
            raise bsig_200_exception("An error occured while unpacking binary data.")
        return value

    def __read_ui32(self, count=1):
        """Function reads and returns the specified count of ui32 items.

        :param count: The number of items to read. By default 1 item will be read.
        """
        value = []
        fmt = 'I'
        try:
            for _ in xrange(count):
                bin_data = self.__f.read(4)
                value.append(struct.unpack(fmt, bin_data)[0])
        except:
            raise bsig_200_exception("An occured while unpacking binary data.")
        return value

    def __read_i64(self, count=1):
        """Function reads and returns the specified count of i64 items.

        :param count: The number of items to read. By default 1 item will be read.
        """
        value = []
        fmt = 'q'
        try:
            for _ in xrange(count):
                bin_data = self.__f.read(8)
                value.append(struct.unpack(fmt, bin_data)[0])
        except:
            raise bsig_200_exception("An occured while unpacking binary data.")
        return value

    def __read_ui64(self, count=1):
        """Function reads and returns the specified count of ui64 items.

        :param count: The number of items to read. By default 1 item will be read.
        """
        value = []
        fmt = 'Q'
        try:
            for _ in xrange(count):
                bin_data = self.__f.read(8)
                value.append(struct.unpack(fmt, bin_data)[0])
        except:
            raise bsig_200_exception("An occured while unpacking binary data.")
        return value

    def __read_f32(self, count):
        """Function reads and returns the specified count of f32 items.

        :param count: The number of items to read. By default 1 item will be read.
        """
        value = []
        fmt = 'f'
        try:
            for _ in xrange(count):
                bin_data = self.__f.read(4)
                value.append(struct.unpack(fmt, bin_data)[0])
        except:
            raise bsig_200_exception("An occured while unpacking binary data.")

    def __read_f64(self, count):
        """Function reads and returns the specified count of i8 items.

        :param count: The number of items to read. By default 1 item will be read.
        """
        value = []
        fmt = 'd'
        try:
            for _ in xrange(count):
                bin_data = self.__f.read(8)
                value.append(struct.unpack(fmt, bin_data)[0])
        except:
            raise bsig_200_exception("An occured while unpacking binary data.")

    def __read_block(self, abs_offset, size):
        """Function reads and returns a block of data from the file.

        :param abs_offset: Offset relative to the begining of the file.
        :param size: The size of the block.
        :return: The block of data as a str object.
        """

        try:
            self.__f.seek(abs_offset)
            result = self.__f.read(size)
        except:
            raise bsig_200_exception("An occured while reading the binary file.")

        return result

    def __CheckVersion(self, file_version):
        if not isinstance(file_version, dict):
            return False
        else:
            if file_version['Major'] < MAX_VERSION['Major']:
                return True
            elif file_version['Major'] == MAX_VERSION['Major']:
                if file_version['Minor'] <= MAX_VERSION['Minor']:
                    return True
                else:
                    # Patch should not matter only for bug fixes.
                    # if the file format is changed Minor should be incremented.
                    return False
            else:
                return False

    def __is_valid_file(self):
        """Function tests the file specified in the open function to see if it is a valid binary file.
        :return: True or False depending whether the file is valid or not.
        """
        self.__f.seek(0, os.SEEK_END)
        self.__file_size = self.__f.tell()
        if self.__file_size == 0:
            return False
        self.__f.seek(self.__file_size - HDR_SIZE)
        try:
            self.__signals_count = self.__read_ui32()[0]
            self.__block_size = self.__read_ui32()[0]
            self.__hdr_size = self.__read_ui32()[0]
            self.__index_table_size = self.__read_ui32()[0]
            bin_data = self.__read_ui8(3)
            self.__version['Major'] = bin_data[0]
            self.__version['Minor'] = bin_data[1]
            self.__version['Patch'] = bin_data[2]
            if self.__CheckVersion(self.__version) is False:
                return False
            self.__bCompression = self.__read_ui8()[0]

            bin_data = self.__read_block(self.__f.tell(), 4)
        except:
            return False
        if bin_data != DEFAULT_SIGNATURE:
            return False
        return True

    def __read_next_signal_info(self):
        """Function reads signal information.
        :return: A dictionary with signal information.
        """
        try:
            signal_name_len = self.__read_ui16()[0]
            signal_name = self.__read_block(self.__f.tell(), signal_name_len)
            array_len = self.__read_ui32()[0]
            sType = self.__read_ui32()[0]
        except:
            raise bsig_200_exception("An error occured while reading signal information.")
        return {'SignalName': signal_name, 'SignalType': sType, 'ArrayLength': array_len,
                'Offsets': [], 'SampleCount': 0}

    def __read_signal_offsets(self, signal):
        """Function reads signal data offsets.
        :param signal: The signal for which to read the offsets.
        """
        try:
            offset_count = self.__read_ui32()[0]
            signal['SampleCount'] = self.__read_ui32()[0]
            signal['Offsets'] = self.__read_ui32(offset_count)
        except:
            raise bsig_200_exception("An exception occured while reading signal offsets.")

    def __read_file_data(self):
        """Function reads the data in the binary file such as signal information and offsets for the signals.
        :return: True or False depending of the success.
        """
        self.__hdr_offset = self.__file_size - HDR_SIZE - self.__hdr_size
        self.__index_table_offset = self.__hdr_offset - self.__index_table_size
        if self.__hdr_offset <= 0 or self.__index_table_offset <= 0:
            return False

        self.__f.seek(self.__hdr_offset)
        try:
            for _ in xrange(self.__signals_count):
                self.__signal_data.append(self.__read_next_signal_info())
        except:
            return False

        self.__f.seek(self.__index_table_offset)
        try:
            for signal in self.__signal_data:
                self.__read_signal_offsets(signal)
        except:
            return False
        return True

    def __clear(self):
        """Function clears the class variables.
        """
        self.__block_size = 0
        self.__file_size = 0
        self.__hdr_size = 0
        self.__hdr_offset = 0
        self.__index_table_size = 0
        self.__index_table_offset = 0
        self.__signals_count = 0
        self.__file_name = ''
        self.__index_table = None
        self.__f = None
        self.__version = None
        self.__version = {'Major': 0, 'Minor': 0, 'Patch': 0}
        self.__bCompression = False
        for i in xrange(len(self.__signal_data)):
            self.__signal_data[i] = None
        self.__signal_data = []

    def open(self, file_name):
        """Function opens the specified binary file.
        :param file_name: The path to the binary file.
        """
        if self.__f is not None:
            raise bsig_200_exception("A binary file is already opened.")
        if not isinstance(file_name, str):
            raise bsig_200_exception("Expecting str type as file name.")
        self.__file_name = file_name
        if os.path.exists(self.__file_name) is not True:
            raise bsig_200_exception('The path %s not found.' % self.__file_name)
        self.__f = open(self.__file_name, "rb")
        if self.__f is None:
            raise bsig_200_exception('The file %s could not be opened.' % self.__file_name)
        if self.__is_valid_file() is False:
            self.close()
            raise bsig_200_exception('The file %s is not a valid binary file.' % self.__file_name)
        if self.__read_file_data() is False:
            self.close()
            raise bsig_200_exception('The file %s is not a valid binary file.Possible corruption of data.' %
                                     self.__file_name)

    def close(self):
        """Function reads signal information.
        :return: A dictionary with signal information.
        """
        if self.__f is not None:
            try:
                self.__f.close()
            except:
                raise bsig_200_exception("An occured while closing the file.")
        self.__clear()

    def get_num_signals(self):
        """Function returns the number of signals in the binary file.
        :return: The number of signals in the binary file.
        """
        if self.__f is not None:
            return self.__signals_count
        else:
            return 0

    def get_signal_name(self, idx):
        """Function returns the name of the signal with the specified index.
        :param idx: The index of the signal.
        :return: The name of the signal if it exists.
        """
        if self.__f is None:
            raise bsig_200_exception("No file currently opened.")
        if isinstance(idx, int) is False:
            raise bsig_200_exception("Expecting type int and found %s " % type(idx).__name__)
        try:
            return self.__signal_data[idx]['SignalName']
        except:
            raise bsig_200_exception("Signal index out of bounds.")

    def __read_signal_data(self, signal):
        """Function reads all the signal data merging all the block in the binary file.
        :param signal: The signal for which to read the data.
        :return: The data for the signal as a str object.
        """
        signal_data = {'Data': "", 'Size': 0}
        try:
            for offset in signal['Offsets']:
                if self.__bCompression != 0:
                    self.__f.seek(offset)
                    block_size = self.__read_ui32(1)[0]
                    temp_data = self.__read_block(offset + 4, block_size)
                    signal_data['Data'] += zlib.decompress(temp_data)
                else:
                    signal_data['Data'] += self.__read_block(offset, self.__block_size)
                signal_data['Size'] += self.__block_size
            return signal_data
        except:
            raise bsig_200_exception("An occured while reading signal data for signal %s " % signal['SignalName'])

    def __read_signal_block(self, BlockOffset):
        if self.__bCompression != 0:
            self.__f.seek(BlockOffset)
            block_size = self.__read_ui32(1)[0]
            temp_data = self.__read_block(BlockOffset + 4, block_size)
            current_block = zlib.decompress(temp_data)
        else:
            current_block = self.__read_block(BlockOffset, self.__block_size)
        return current_block

    def __process_signal_data_block(self, signal, Offset, SampleCount):

        """Function processes all the signal data.
        :param signal: The signal for which to process the data.
        :param data:   The data for the signal.
        :return:  The processed data as a list with values. If the signal is
                  an array the returned list will have list with each sample value.
        """
        if Offset < 0 or SampleCount < 0:
            raise bsig_200_exception("An invalid offset or number of samples were specified  for signal %s " %
                                     signal['SignalName'])

        type_size = self.__get_signal_type_size(signal['SignalType'])
        fmt_str = self.__get_signal_format_str(signal['SignalType'])
        sample_size = type_size * signal['ArrayLength']

        if SampleCount > signal['SampleCount'] - Offset:
            sample_count = signal['SampleCount'] - Offset
        else:
            sample_count = SampleCount

        start_block_index = (Offset * sample_size) / self.__block_size
        start_block_offset = (Offset * sample_size) % self.__block_size

        if(Offset + sample_size * sample_count) % self.__block_size:
            end_block_index = ((Offset * sample_size + sample_size * sample_count) / self.__block_size) + 1
        else:
            end_block_index = (Offset * sample_size + sample_size * sample_count) / self.__block_size

#        end_offset = (Offset + sample_size * sample_count) % self.__block_size

        # current_block = ""
        # raw_data      = ""
        byte_size = sample_count * sample_size
        raw_data = (c_int8 * byte_size)()
        raw_block_offset = 0
        raw_offset_data = byref(raw_data)

        try:
            # Merge all data for the samples from different blocks
            for block_offset in signal['Offsets'][start_block_index:end_block_index]:
                current_block = ""
                current_block = self.__read_signal_block(block_offset)
                current_block = current_block[start_block_offset:len(current_block)]
                start_block_offset = 0
                # raw_data += current_block
                block_byte_size = len(current_block)
                if raw_block_offset + block_byte_size > byte_size:
                    block_byte_size = byte_size - raw_block_offset
                    if block_byte_size <= 0:
                        break
                memmove(raw_offset_data, current_block, block_byte_size)
                raw_block_offset += block_byte_size
                raw_offset_data = byref(raw_data, raw_block_offset)
        except:
            raise bsig_200_exception("An occured while reading signal data block for signal %s " %
                                     signal['SignalName'])

        if signal['ArrayLength'] == 1:
            # count = sample_count

            if fmt_str == "f":
                signal_data = (c_float * sample_count)()
            elif fmt_str == "c":
                signal_data = (c_int8 * sample_count)()
            elif fmt_str == "b":
                signal_data = (c_int8 * sample_count)()
            elif fmt_str == "B":
                signal_data = (c_uint8 * sample_count)()
            elif fmt_str == "h":
                signal_data = (c_int16 * sample_count)()
            elif fmt_str == "H":
                signal_data = (c_uint16 * sample_count)()
            elif fmt_str == "l":
                signal_data = (c_int32 * sample_count)()
            elif fmt_str == "L":
                signal_data = (c_uint32 * sample_count)()
            elif fmt_str == "q":
                signal_data = (c_int64 * sample_count)()
            elif fmt_str == "Q":
                signal_data = (c_uint64 * sample_count)()
            elif fmt_str == "d":
                signal_data = (c_double * sample_count)()
            else:
                raise bsig_200_exception("Unknown format.")

            byte_size = sample_count * sample_size

            memmove(signal_data, raw_data, byte_size)

            data_list = signal_data[0:-1]
            signal_data = None

            return data_list
        # else:

        signal_data = []
        # signal_data = [0]* signal['SampleCount'] * signal['ArrayLength']

        try:
            signal_samples = 0
#            sample_value = []
#            offset = 0
            array_lenght = signal['ArrayLength']

            if fmt_str == "f":
                sample_value = (c_float * array_lenght)()
            elif fmt_str == "c":
                sample_value = (c_int8 * array_lenght)()
            elif fmt_str == "b":
                sample_value = (c_int8 * array_lenght)()
            elif fmt_str == "B":
                sample_value = (c_uint8 * array_lenght)()
            elif fmt_str == "h":
                sample_value = (c_int16 * array_lenght)()
            elif fmt_str == "H":
                sample_value = (c_uint16 * array_lenght)()
            elif fmt_str == "l":
                sample_value = (c_int32 * array_lenght)()
            elif fmt_str == "L":
                sample_value = (c_uint32 * array_lenght)()
            elif fmt_str == "q":
                sample_value = (c_int64 * array_lenght)()
            elif fmt_str == "Q":
                sample_value = (c_uint64 * array_lenght)()
            elif fmt_str == "d":
                sample_value = (c_double * array_lenght)()
            else:
                raise bsig_200_exception("Unknown format.")

            byte_size = array_lenght * type_size

            raw_block_offset = 0
            raw_offset_data = byref(raw_data)

            while signal_samples < sample_count:
#                for i in xrange(signal['ArrayLength']):
#                    sample_value.append(struct.unpack_from(fmt_str, raw_data, offset)[0])
#                    offset += type_size
                # print sample_value
                memmove(sample_value, raw_offset_data, byte_size)
                raw_block_offset += byte_size
                raw_offset_data = byref(raw_data, raw_block_offset)

                data_list = sample_value[0:-1]

                signal_data.append(data_list)
#                signal_data.append(sample_value)
                signal_samples += 1
#                sample_value = []
        except:
            raise bsig_200_exception("An error occured while processing signal data for signal %s " %
                                     signal['SignalName'])

        return signal_data

    def __process_signal_data(self, signal, data):
        """Function processes all the signal data.
        :param signal: The signal for which to process the data.
        :param data:   The data for the signal.
        :return:  The processed data as a list with values. If the signal is
                  an array the returned list will have list with each sample value.
        """
        offset = 0
        type_size = self.__get_signal_type_size(signal['SignalType'])
        fmt_str = self.__get_signal_format_str(signal['SignalType'])
        signal_samples = 0
        sample_value = []

        max_samples = signal['SampleCount']
        raw_data = data['Data']
        max_size = data['Size']

        try:
            if signal['ArrayLength'] == 1:
                type_size = self.__get_signal_type_size(signal['SignalType'])
                count = signal['SampleCount']

                if fmt_str == "f":
                    signal_data = (c_float * count)()
                elif fmt_str == "c":
                    signal_data = (c_int8 * count)()
                elif fmt_str == "b":
                    signal_data = (c_int8 * count)()
                elif fmt_str == "B":
                    signal_data = (c_uint8 * count)()
                elif fmt_str == "h":
                    signal_data = (c_int16 * count)()
                elif fmt_str == "H":
                    signal_data = (c_uint16 * count)()
                elif fmt_str == "l":
                    signal_data = (c_int32 * count)()
                elif fmt_str == "L":
                    signal_data = (c_uint32 * count)()
                elif fmt_str == "q":
                    signal_data = (c_int64 * count)()
                elif fmt_str == "Q":
                    signal_data = (c_uint64 * count)()
                elif fmt_str == "d":
                    signal_data = (c_double * count)()
                else:
                    raise bsig_200_exception("Unknown format.")

                byte_size = count * type_size

                if byte_size <= data['Size']:
                    memmove(signal_data, raw_data, byte_size)
                else:
                    raise bsig_200_exception("Samples count does not match. The binary file might be corrupted.")

                data_list = signal_data[0:-1]
                signal_data = None

                return data_list

            else:
                signal_data = []  # [0]* signal['SampleCount']

                while signal_samples != max_samples and offset != max_size:
                    for _ in xrange(signal['ArrayLength']):
                        sample_value.append(struct.unpack_from(fmt_str, raw_data, offset)[0])
                        offset += type_size
                    signal_data.append(sample_value)
                    signal_samples += 1
                    sample_value = []
        except:
            raise bsig_200_exception("An error occured while processing signal data for signal %s " %
                                     signal['SignalName'])

        if signal_samples != signal['SampleCount']:
            raise bsig_200_exception("Samples count does not match. The binary file might be corrupted.")
        return signal_data

    def get_signal_sample_count_by_index(self, idx):
        """Function returns the data for the signal with the specified index.
        :param idx: The index of the signal.
        :return: The signal data as a list.
        """
        if isinstance(idx, int) is False:
            raise bsig_200_exception("Expecting type int and found %s" % type(signal_name).__name__)
        try:
            signal = self.__signal_data[idx]
        except:
            bsig_200_exception("Signal index out of bounds.")
        return signal['SampleCount']

    def get_signal_sample_count_by_name(self, name):
        """Function returns the data for the signal with the specified index.
        :param name: The name of the signal.
        :return: The signal data as a list.
        """
        if isinstance(signal_name, str) is False:
            raise bsig_200_exception("Expecting str type and found %s" % type(signal_name))
        for signal in self.__signal_data:
            if signal['SignalName'] == signal_name:
                return signal['SampleCount']
        raise bsig_200_exception("The signal %s could not be found in the file." % signal_name)

    def get_signal_by_index(self, idx):
        """Function returns the data for the signal with the specified index.
        :param idx: The index of the signal.
        :return: The signal data as a list.
        """
        if isinstance(idx, int) is False:
            raise bsig_200_exception("Expecting type int and found %s" % type(signal_name).__name__)
        try:
            signal = self.__signal_data[idx]
        except:
            bsig_200_exception("Signal index out of bounds.")
        return self.__process_signal_data(signal, self.__read_signal_data(signal))

    def get_signal_by_index2(self, idx, Offset, SampleCount):
        """Function returns the data for the signal with the specified index.
        :param idx: The index of the signal.
        :return: The signal data as a list.
        """
        if isinstance(idx, int) is False:
            raise bsig_200_exception("Expecting type int and found %s" % type(signal_name).__name__)
        try:
            signal = self.__signal_data[idx]
        except:
            bsig_200_exception("Signal index out of bounds.")
        return self.__process_signal_data_block(signal, Offset, SampleCount)
        # self.__process_signal_data(signal,self.__read_signal_data(signal))[Offset:Offset+SampleCount]

    def get_signal_by_name(self, signal_name):
        """Function returns the data for the signal with the specified index.
        :param signal_name: The name of the signal.
        :return: The signal data as a list.
        """
        if isinstance(signal_name, str) is False:
            raise bsig_200_exception("Expecting str type and found %s" % type(signal_name))
        for signal in self.__signal_data:
            if signal['SignalName'] == signal_name:
                return self.__process_signal_data(signal, self.__read_signal_data(signal))
        raise bsig_200_exception("The signal %s could not be found in the file." % signal_name)

    def get_signal_by_name2(self, signal_name, Offset, SampleCount):
        """Function returns the data for the signal with the specified index.
        :param signal_name: The name of the signal.
        :return: The signal data as a list.
        """
        if isinstance(signal_name, str) is False:
            raise bsig_200_exception("Expecting str type and found %s" % type(signal_name))
        for signal in self.__signal_data:
            if signal['SignalName'] == signal_name:
                return self.__process_signal_data_block(signal, Offset, SampleCount)
        raise bsig_200_exception("The signal %s could not be found in the file." % signal_name)

    def get_signal_name_list(self):
        """Function returns the signal name in the binary file.
        :return: The signal names for the signals in the binary file or None if there is no binary file opened.
        """
        if self.__f is None:
            return None
        signal_name_list = []
        for signal in self.__signal_data:
            signal_name_list.append(signal['SignalName'])
        return signal_name_list

    def get_file_version(self):
        """Function returns the version of the binary format.
        :return: The version of the binary file format as a dictionary.
        """
        return self.__version

    def get_signals_by_list(self, names):
        """Function returns the values for the specified signals .
        :return: the values for the specified signals .
        """
        value_list = []
        for signal_name in names:
            try:
                signal_values = self.get_signal_by_name(signal_name)
            except bsig_200_exception, ex:
                raise ex
            value_list.append(signal_values)
        return value_list


class BsigReader:
    """
    MAIN Class for Binary Signal File Read. (*.bsig)
    Class which hase Base Methods for Reading Binary Signal Files
    :note:          usage : <usage description> (optional)

    :author:        Robert Hecker
    """

    # # The constructor.
    def __init__(self):
        # Initialize all unused Variables
        self.__f = None
        self.__reader = {}

    # # The destructor.
    def __del__(self):
        # self.__FilePath = ""
        pass

    def __read_glob_header(self):
        """
        Reads the Global File Header of the BCSV File.

        :author:        Robert Hecker
        """
        # Read "BSIG" tag from the File and check if Tag matches
        tag = self.__f.read(4)

        if(tag != "BSIG"):
            return "No BSIG File"

        # Read Version of BSIG File
        version = self.__f.read(3)
        version = struct.unpack('BBB', version)

        return version

    def open(self, FilePath):
        """
        Open the Binary BEX File and read the Global File Header
        and the Signal Header.

        :author:        Robert Hecker
        """
        # Open File
        self.__f = file_bsig(FilePath, 'rb')

        # Read Ini File
        version = self.__read_glob_header()

        if(version == (1, 0, 0)):
            self.__reader = bsig_100(self.__f)
        elif (version == 2, 0, 0):
            self.__f.close()
            self.__f = None
            self.__reader = bsig_200()
            self.__reader.open(FilePath)
        else:
            return version

        self.__reader.read_file_header()

    def close(self):
        """
        Close the open *.bex file.

        :author:        Robert Hecker
        """
        # Destroy Reader
        del self.__reader

        # Close File
        if self.__f is not None:
            self.__f.close()

    def get_num_signals(self):
        """
        Return the Number of Signals from an opened file.

        :return:        Number of Signals
        :author:        Robert Hecker
        """
        return self.__reader.get_num_signals()

    def get_signal_name(self, Index):
        """
        Return the Signal Name, specified by Index

        :param Index:   Index
        :return:        Signalname
        :author:        Robert Hecker
        """
        return self.__reader.get_signal_name(Index)

    def get_signal_by_index(self, Index, Offset=None, SampleCount=None):
        """
        Return an array of signal values specified by Index

        :param Index:       Signal index
        :param Offset:      Sample offset from the start sample 0.
        :param SampleCount  The number of samples.
        :return:        Array of Signal Values
        :author:        Ovidiu Raicu
        """
        if Offset is None and SampleCount is None:
            return self.__reader.get_signal_by_index(Index)
        else:
            if isinstance(self.__reader, bsig_200) is False:
                print "Function available only for binary files with version 2.0.0 or higher."
            else:
                return self.__reader.get_signal_by_index2(Index, Offset, SampleCount)

    def get_signal_by_name(self, name, Offset=None, SampleCount=None):
        """
        Return an array of signal values specified by the Signal Name

        :param name:    name
        :return:        Array of Signal Values
        :author:        Robert Hecker
        """
        if Offset is None and SampleCount is None:
            return self.__reader.get_signal_by_name(name)
        else:
            if isinstance(self.__reader, bsig_200) is False:
                print "Function available only for binary files with version 2.0.0 or higher."
            else:
                return self.__reader.get_signal_by_name2(name, Offset, SampleCount)

    def get_signal_sample_count_by_name(self, name):
        """
        Return an array of signal values specified by the Signal Name

        :param name:    name
        :param Offset:
        :return:        Array of Signal Values
        :author:        Ovidiu Raicu
        """
        if isinstance(self.__reader, bsig_200) is False:
            print "Function available only for binary files with version 2.0.0 or higher."
        else:
            return self.__reader.get_signal_sample_count_by_name(name)

    def get_signal_sample_count_by_index(self, signal_index):
        """
        Return an array of signal values specified by the Signal Name

        :param name:    name
        :param Offset:
        :return:        Array of Signal Values
        :author:        Ovidiu Raicu
        """
        if isinstance(self.__reader, bsig_200) is False:
            print "Function available only for binary files with version 2.0.0 or higher."
        else:
            return self.__reader.get_signal_sample_count_by_index(signal_index)

    def get_signals_by_list(self, names):
        """
        Return an array of arrays of signal values specified by an array of
        Signal Names.

        :param names:   Array of names
        :return:        Array of Array of Signal Values
        :author:        Robert Hecker
        """
        return self.__reader.get_signals_by_list(names)

"""
CHANGE LOG:
-----------
$Log: bsig.py  $
Revision 1.1 2021/12/13 17:58:04CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/io/project.pj
Revision 1.10 2013/03/28 14:43:04CET Mertens, Sven (uidv7805) 
pylint: resolving some R0904, R0913, R0914, W0107
- Added comments -  uidv7805 [Mar 28, 2013 2:43:05 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.9 2013/03/28 14:20:05CET Mertens, Sven (uidv7805)
pylint: solving some W0201 (Attribute %r defined outside __init__) errors
--- Added comments ---  uidv7805 [Mar 28, 2013 2:20:06 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.8 2013/03/28 11:10:53CET Mertens, Sven (uidv7805)
pylint: last unused import removed
--- Added comments ---  uidv7805 [Mar 28, 2013 11:10:54 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.7 2013/03/28 09:33:15CET Mertens, Sven (uidv7805)
pylint: removing unused imports
--- Added comments ---  uidv7805 [Mar 28, 2013 9:33:16 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.6 2013/03/27 13:51:22CET Mertens, Sven (uidv7805)
pylint: bugfixing and error reduction
--- Added comments ---  uidv7805 [Mar 27, 2013 1:51:22 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.5 2013/03/22 08:24:27CET Mertens, Sven (uidv7805)
aligning bulk of files again for peping 8
Revision 1.4 2013/02/28 16:02:09CET Hecker, Robert (heckerr)
Updates Regarding Pep8 Style Guide.
--- Added comments ---  heckerr [Feb 28, 2013 4:02:09 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/26 15:10:03CET Hecker, Robert (heckerr)
Updated Code partly regarding Pep8.
--- Added comments ---  heckerr [Feb 26, 2013 3:10:04 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/11 10:48:49CET Raedler, Guenther (uidt9430)
- fixed docu sections
--- Added comments ---  uidt9430 [Feb 11, 2013 10:48:50 AM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.1 2013/02/11 10:32:43CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/io/project.pj
------------------------------------------------------------------------------
-- from stk 1.0 stk_bsig.py Archive
------------------------------------------------------------------------------
Revision 1.14 2012/07/17 12:01:14CEST Mogos, Sorin (mogoss)
* code improvements
--- Added comments ---  mogoss [Jul 17, 2012 12:01:14 PM CEST]
Change Package : 117828:1 http://mks-psad:7002/im/viewissue?selection=117828
Revision 1.13 2012/05/30 13:41:42CEST Mogos, Sorin (mogoss)
* code improvements
--- Added comments ---  mogoss [May 30, 2012 1:41:42 PM CEST]
Change Package : 104217:1 http://mks-psad:7002/im/viewissue?selection=104217
Revision 1.12 2012/04/30 13:14:46CEST Mogos, Sorin (mogoss)
* fix: code improvements to avoid crash for the case when big amount of files being processed
--- Added comments ---  mogoss [Apr 30, 2012 1:14:46 PM CEST]
Change Package : 104217:1 http://mks-psad:7002/im/viewissue?selection=104217
Revision 1.11 2011/10/11 14:57:01CEST Ovidiu Raicu (RaicuO)
Bugfix for reading signals with array length >1 for bsig 2.0.
--- Added comments ---  RaicuO [Oct 11, 2011 2:57:03 PM CEST]
Change Package : 79585:1 http://mks-psad:7002/im/viewissue?selection=79585
Revision 1.10 2011/05/23 10:27:57CEST Paulig Ralf (uidt3509) (uidt3509)
Bugfix for reading bsig files of version 1.0.0 with array signals.
--- Added comments ---  uidt3509 [May 23, 2011 10:27:59 AM CEST]
Change Package : 65266:1 http://mks-psad:7002/im/viewissue?selection=65266
Revision 1.9 2011/01/26 12:28:48CET Ovidiu Raicu (RaicuO)
Changed output of __process_signal_data_block function to be a list.
--- Added comments ---  RaicuO [Jan 26, 2011 12:28:49 PM CET]
Change Package : 37852:2 http://mks-psad:7002/im/viewissue?selection=37852
Revision 1.8 2011/01/25 15:23:10CET Ovidiu Raicu (RaicuO)
Bug fix for get_signal_by_name function.
--- Added comments ---  RaicuO [Jan 25, 2011 3:23:10 PM CET]
Change Package : 37852:2 http://mks-psad:7002/im/viewissue?selection=37852
Revision 1.7 2011/01/25 12:21:42CET Ovidiu Raicu (RaicuO)
Added new functions to stkBsig and new functionality for bsig files version 2.0.0 and higher.
--- Added comments ---  RaicuO [Jan 25, 2011 12:21:42 PM CET]
Change Package : 37852:2 http://mks-psad:7002/im/viewissue?selection=37852
Revision 1.6 2010/04/29 13:48:21CEST gbenchea
Convert the result to python list
--- Added comments ---  gbenchea [2010/04/29 11:48:21Z]
Change Package : 41177:1 http://LISS014:6001/im/viewissue?selection=41177
Revision 1.5 2010/04/28 17:11:15EEST Gicu Benchea (gbenchea)
Improve the speed for the binary data parser
--- Added comments ---  gbenchea [2010/04/28 14:11:15Z]
Change Package : 41177:1 http://LISS014:6001/im/viewissue?selection=41177
Revision 1.4 2010/02/24 17:05:06EET Ovidiu Raicu (oraicu)
Bugfix for signals with Double type.
--- Added comments ---  oraicu [2010/02/24 15:05:06Z]
Change Package : 37852:1 http://LISS014:6001/im/viewissue?selection=37852
Revision 1.3 2010/02/11 12:54:56CET Ovidiu Raicu (oraicu)
Added suport for bsig file with global version 2.0.0.
Bug fixes related to BSIG signature and some functions.
--- Added comments ---  oraicu [2010/02/11 11:54:56Z]
Change Package : 37587:1 http://LISS014:6001/im/viewissue?selection=37587
Revision 1.2 2009/11/18 14:45:01CET dkubera
bugfix: opening file "rw" instead "r+w"
comments reworked
--- Added comments ---  dkubera [2009/11/18 13:45:01Z]
Change Package : 33974:2 http://LISS014:6001/im/viewissue?selection=33974
Revision 1.1 2009/09/21 17:56:56CEST Robert Hecker (rhecker)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/
    31_PyLib/project.pj
"""
