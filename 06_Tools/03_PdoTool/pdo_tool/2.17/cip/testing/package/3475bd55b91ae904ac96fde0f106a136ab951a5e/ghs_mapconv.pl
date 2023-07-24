#!perl -w
#
# Version:			$Revision: 1.1 $
# Change history:
# 

# Get number of arguments passed to script
my $ARGC = @ARGV;
# If too few arguments, then abort
my $UsageStr = "You have to specfiy the Green Hils MAP file and the output standard map file to generate information from!";
die $UsageStr if ($ARGC < 2);
my $MapFile = shift @ARGV;
my $OutFile = shift @ARGV;
# If the named map file does not exist, abort
die "The file \"${MapFile}\" does not exist! Please provide name of GHS map file name as parameter!" if (!-f $MapFile);
# Now open the mapfile for input
open MAPFILE, "<$MapFile" or die "The file \"${MapFile}\" could not be opened for reading!";
open OUTFILE, ">$OutFile" or die "The file \"${OutFile}\" could not be opened for writing!";

# Set default option values and process options passed
my $EnableEmptyAddrRangeInfo = 0;
my $EnableNotFitingSectionAssign	= 1;
my $EnableAddressRangeCfgVerify		= 1;
# We may have further options on the command line, process them
foreach my $CurOption (@ARGV) {
    if ($CurOption =~ /^-enable-empty-range$/) {
        $EnableEmptyAddrRangeInfo = 1;
    } elsif ($CurOption =~ /^-disable-section-overlap-search$/) {
        $EnableNotFitingSectionAssign = 0;
    } else {
        die "Unknown option \"${CurOption}\"! Aborting!";
    }
}

# Section name hash, index is the name of the section, the value is a hash containing all sorts
# of information on the sections. Fields are 'RealSize' the real size of the section including
# any alignment padding added, except for the final padding (which is actualy a consequence of
# the alignment of the next section). 'UsedSize' is the size actually used. 'VirtualAddress' is the
# starting address of the section. 'Type' is usually the string 'DATA' or 'CODE' which appears
# in the TYPE column of the Renesas map file. 'Joint' is the data which appears in the JOINT
# column of the map file. If support for a new compiler needs to be added, then this while
# loop needs to be modified in such a way, that after it was run, the same hashes are created
# in memory for the (different) map file. Note that during later processing a further field
# is added to the hash, indicating which address range it was assigned to 'AddrRangeName'.
my %Sections = ();
# The source resources hash uses the source file names as keys, and has hashes as values. The
# value hashes keys are the section names, while the values are the sizes.
my %SourceResources = ();
# The name of the current section, or empty if not in one
my $CurSectionName = "";
my $FileName;
# A map of names where we already have addresses defined. This is used to keep track of symbols
# to addresses, for special cases when the map-file redeclares the same symbol with a different
# address
my %Symbol2Addr = ();
# While there are lines in the mapfile
while (<MAPFILE>) {
    chomp;
    # ARGH: Chomp does not always work for different perl versions
    s/[\r\f\n]+//g;
    

    if (/^\s*(\.[^\s]*)\s*([\da-f]{8})\s*([\da-f]{8})\s*([\d]{1,10})\s*([\da-f]{7})$/i) {
        # Get information from section: Image Summary
        # Section sample from GHS for the pattern: 
        #  Section              Base      Size(hex)    Size(dec)  SecOffs
        #  .text                0004a400  0002b166       176486   0009c00
        # \1 Section: is the output section name
        # \2 Base: is the virtual address of the section (starting address)
        # \3 Size(hex): is the size of the section in hex
        # \4 Size(dec): is the size of the section in decimal
        # \5 SecOffs
           $CurSectionName = $1;
		    my $VirtualAddress = $2;
		    my $SizeHex = $3;
		    my $SizeDec = $4;
		    my $SecOffs = $5;
        if (!defined $Sections{$1}) {
            # Create a new section
            $Sections{$CurSectionName} = { 
              'VirtualAddress'=>$VirtualAddress, 
              'SizeHex'=>$SizeHex, 
              'SizeDec'=>$SizeDec, 
              'SecOffs'=>$SecOffs, 
              'ModuleInfo'=>[] };
        }
        #nothing to do, no symbol in this section

    } elsif (/^([\da-f]{8})\+([\da-f]{6,8})\s*([^\s]*)\s*(?:->\s*([^\s]*)\s*)?(.*)$/i) {
        # Get information from section: Module Summary
        # Section sample from GHS for the pattern: 
        #  Origin+Size    Section          Module
        #0004a400+0000f0  .text            crt0.o
        #fe9e5000+004e1b  .bss -> .IPC_BSS_SECTION ipc_sync_base.o
        # \1 is the virtual address,
        # \2 is the size,
        # \3 is the main section if \4 is empty else will be sub section type
        # \4 is the input section name, 
        # \5 is the file name (module name)
        my $SectionAddress = $1;
        my $SectionSize    = $2;
        my $SubSectionName = $3;  
        my $SectionName    = $4; # if empty, then SubSectionName contains the section name
        my $ModuleName     = $5;  
        
        if (!defined($SectionName)) {
          $SectionName = $SubSectionName;
        }
        #nothing to do, no symbol in this section
        
	} elsif (/^\s*(\.[^\s]*)\s*([\da-f]{8})\+([\da-f]{6,8})\s*_(.*)$/i) {
        # Get information from section: Global Symbols (sorted alphabetically)
        # Section sample from GHS for the pattern: 
        # .text            00056636+000034 _BAI_b_Init
        # .bss             febec894+000004 _Dem_GlobalVars
        my $Section  = $1;
        my $Address  = $2;
        my $SizeHex  = $3;  
        my $Symbol   = $4;   
        
        # for static variables strip away the src path starting after '..'
        if ($Symbol =~ /([^\.\.]*)/) {
          $Symbol = $1;
          print OUTFILE "${Symbol} 0x${Address} 0x${SizeHex}\n";  
        }
      
  } elsif (/^\s*(\.[^\s]*)\s*([\da-f]{8})\+([\da-f]{6,8})\s*(.*)$/i) {    
    print "Warning: found an unknow symbol, you need to update mapconv.pl, error while parsing map file, Line text: ${_}'\n";
  } else {
      # Other lines can be safely ignored for our purposes
  }
}
# Now we can close the mapfile, we have all information we need in RAM
close MAPFILE;
close OUTFILE;

# create additional info file if needed
# file in which we will put additional information from map file
my $auxFile = "";
if($OutFile=~m/(^.*[\/]|[\\])/)
{
	$auxFile = "summery.txt"; #filn
	$auxFile = "$1$auxFile";
}
#print $auxFile;
# End-of-file

