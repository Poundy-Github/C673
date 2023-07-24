#!/usr/bin/perl 
use strict; 
use warnings; 
 
 
# Get number of arguments passed to script
my $ARGC = @ARGV;
# If too few arguments, then abort
my $UsageStr = "You have to specfiy at least 1 core a2l files!";
die $UsageStr if ($ARGC < 2); 
 
 
# 1 Argument must be the Project-Name like MFC4T0, SMFC4B0 or SRLCAM
# 2 - n Arguments are the A2L files to be merged
 
# Defines
my $string;
my $OutA2LName			= shift @ARGV;
my $FirstFile 			= shift @ARGV;
my $CombinedString 	= "";
my $RefStringStart 	= "/begin MODULE";
my $RefStringEnd 		= "/end MODULE";
my $StartIndex 			= 0;
my $Offset 					= 1024;
my $EndIndex 				= 0;
my $FileName				= "$OutA2LName" . "_PR_soc_rel.a2l";
my $File 						= "$FileName";

# Unset $/, the Input Record Separator, to make <> give you the whole file at once.
local $/=undef; 

# Open the first core a2l file in the list and trim the "/end PROJECT" end
print "$FirstFile\n";
open FILE, "$FirstFile" or die "Couldn't open file: $FirstFile";
$string = <FILE>;
$EndIndex = index($string, "/end PROJECT");
$string = substr $string, 0, $EndIndex;
$CombinedString = $string . "\n\t";

 
# Loop through the other a2l files in the list and concat the "MODULEs" (core contents)
foreach my $CurA2lFile(@ARGV)
{
 	print "$CurA2lFile \n";
 	# Open the current file 	 	 	
	open FILE, "$CurA2lFile" or die "Couldn't open file: $CurA2lFile";
	# Get the complete file content into a string
  $string = <FILE>;
  # Get the start of the "MODULE"
  $StartIndex = index($string, $RefStringStart);
  # Get the end of the "MODULE"
  $EndIndex = index($string, $RefStringEnd, $Offset) + length $RefStringEnd;
	# Trim everything before and after the "MODULE" definition
  $string = substr $string, $StartIndex, $EndIndex - $StartIndex;
  # Close the current file
  close FILE;
	# Concat the "MODULE" content of the core a2l files to one string
  $CombinedString = $CombinedString . $string . "\n\n\t";
}
# Add the "/end PROJECT" at the end of the merged a2l file string
$CombinedString = $CombinedString . "/end PROJECT\n";
# Write the merged a2l file string to a single SOC a2l file
open FILE, '>' ."$File" or die "Couldn't open file: $File";
print FILE $CombinedString;
close FILE;

