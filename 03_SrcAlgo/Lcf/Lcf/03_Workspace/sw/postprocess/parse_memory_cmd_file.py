#!/usr/bin/env python

import sys

def _main():
    
#	sys.argv[1]	input file path that should be parsed
#	sys.argv[2]	token-string that should be found in file
#	sys.argv[3]	output file path where the address is stored
	return_address = "0"
	
	filepath_in = sys.argv[1]
	filepath_out = (sys.argv[3])

	# read file
	# parse the file line by line for token
	file_in = open(filepath_in, "r")
	for line in file_in:
		if sys.argv[2] in line:
			index = line.find('0x')
			new_sub_string = line[index:index + 10]
			return_address = new_sub_string + "\n"
	file_in.close()

	# write file
	# write address into tempfile
	file_out = open(filepath_out, "w")
	file_out.write(return_address)
	file_out.close()

# Call main function
_main()
