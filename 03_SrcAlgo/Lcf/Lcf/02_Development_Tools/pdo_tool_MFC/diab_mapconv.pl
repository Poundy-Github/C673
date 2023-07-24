#!perl -w
#
# Perl script for printing basic information on a binary created
# by the Freescale MWCW tool-chain. This basic information includes
# RAM/ROM use as well as a few basic warnings about sections
# spanning multiple address ranges etc.
#
# Version:			$Revision: 1.1 $
# Change history:
#					$Log: diab_mapconv.pl  $
#					Revision 1.1 2021/12/13 18:43:16CET Wang, David (Wangd3) 
#					Initial revision
#					Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/pdo_tool_MFC/project.pj
#					Revision 1.1 2016/01/14 18:08:33CET Ungvary, Gergely (Ungvary) 
#					Initial revision
#					Member added to project /nfs/projekte1/tools/custom/pdo/distribution/project.pj
#					Revision 1.1 2012/12/11 09:59:47CET Puscas, Radu (uidl6390) 
#					Initial revision
#					Member added to project /nfs/projekte1/SW/SW_MFC4xx/SW_SMFC400_PR/M11_APPL/04_Engineering/03_Workspace/make/project.pj
#					Revision 1.3 2010/05/11 16:14:22CEST gungvary 
#					Fix error message generation for symbol with multiple different addresses
#					Note: this is a benign error as synatactically seperate translation units may use the same symbol with
#					different meanings. The problem with this is, that it can confuse external tools/editors and developers
#					themselves. For this reason only define a single address for a symbol in the output map file.
#					--- Added comments ---  gungvary [2010/05/11 14:14:23Z]
#					Change Package : 39685:2 http://LISS014:6001/im/viewissue?selection=39685
#					Revision 1.2 2010/04/22 10:17:00CEST gungvary 
#					Bugfix: Symbol name match missing escapes for at signs (discovered and fixed by David Muscat)
#					Add additional sanity check for multiply defined symbols
#					--- Added comments ---  gungvary [2010/04/22 08:17:00Z]
#					Change Package : 39685:2 http://LISS014:6001/im/viewissue?selection=39685
#					Revision 1.1 2010/03/03 17:53:37CET gungvary 
#					Initial revision
#					Member added to project /nfs/projekte1/PROJECTS/ARS301/05_Software/04_Engineering/03_Workspace/make/project.pj
#
# Gergely Ungvary 2005-2010
# 

# Get number of arguments passed to script
my $ARGC = @ARGV;
# If too few arguments, then abort
my $UsageStr = "You have to specfiy the Freescale MAP file and the output standard map file to generate information from!";
die $UsageStr if ($ARGC < 2);
my $MapFile = shift @ARGV;
my $OutFile = shift @ARGV;
# If the named map file does not exist, abort
die "The file \"${MapFile}\" does not exist! Please provide name of Freescale map file name as parameter!" if (!-f $MapFile);
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
    # See if it is module size declaration with section name declaration
    # if (/^([\.a-z_][\.a-z_0-9]*)[ \t]+section layout[ \t]*$/i) {
    if (/^\s*(\.[^\s]*)\s*([\da-f]{8})\s([\da-f]{8})$/i) {
        # A DIAB section declaration
        $CurSectionName = $1;
		my $VirtualAddress = $2;
		my $UsedSize = $3;
        if (!defined $Sections{$1}) {
            # Create a new section
            $Sections{$CurSectionName} = { 'VirtualAddress'=>$VirtualAddress, 'UsedSize'=>$UsedSize, 'ModuleInfo'=>[] };
        }
	# get setion module name
	} elsif (/^\s*(\.[^ ]*)\s*([\da-f]{8})\s([\da-f]{8})\s*([^\s]*)$/i) {
		# Matches a line describing a section variable/symbol line:
        # \1 is the of the: input section, 
		# \2 is the: virtual start address of the input section 
		# \3 is the: size of the input section
		# \4 is the: file in which the input section is located(module name)
		my $FileName = $4;	
    } elsif (/^\s*([^\.][^\s]*)\s*([\da-f]{8})\s([\da-f]{8})$/i) {
        # Matches a line describing a section variable/symbol line:
        # \1 is the: symbol name
        # \2 is the: virtual start address of the symbol
        # \3 is the: size of the symbol
        my $SymbolName = $1;
        my $Address = $2;
        my $Size = $3;        
        if ($CurSectionName ne "") {
            # Also ignore any special symbols beginning with '.'
            if ($SymbolName =~ /^[a-zA-Z_\@][a-zA-Z0-9\@_]*$/) {
                if (!defined $Symbol2Addr{$SymbolName}) {
                    print OUTFILE "${SymbolName} 0x${Address} 0x${Size}\n";
					push(@{$Sections{$CurSectionName}{'ModuleInfo'}},{'SymbolName' => $SymbolName, 'Address' => $Address, 'Size' => $Size});
                    $Symbol2Addr{$SymbolName} = $Address;					
                } else {
                    if ($Symbol2Addr{$SymbolName} ne $Address) {
                        print "Warning: The map file declares multiple addresses for symbol '${SymbolName}' (0x${Address} 0x${Symbol2Addr{$SymbolName}})\n";
                    }
                }
            }
        } else {
            print "Warning: Found a stray line '${_}' without knowing which section it belongs to\n";
        }
    } elsif (/^[ \t]*([0-9a-f]{8})[ \t]+([0-9a-f]{6})[ \t]+([0-9a-f]{8})[ \t]+([0-9a-f]{8})[ \t]+([0-9]+)[ \t]+\*fill\*[ \t]*$/i) {
        # Filling bytes
        # Set the real (un-padded) size
    } elsif (/^[ \t]*([\._a-z0-9]+)[ \t]+([0-9a-f]{8})[ \t]+([0-9a-f]{8})[ \t]+([0-9a-f]{8})[ \t]+([0-9a-f]{8})[ \t]+([0-9a-f]{8})[ \t]+[0-9]+$/) {
        # Matches a line assigning a given section to a given address
        # \1 is the name of the section
        # \2 is the starting address,
        # \3 is the size
        # \4 is the file offset
        # \5 is the ROM address
        # \6 is the RAM buffer address
        #print "Found section ${1}\n";
        $CurSectionName = $1;
    } else {
        # Other lines can be safely ignored for our purposes
    }
}
# Now we can close the mapfile, we have all information we need in RAM
close MAPFILE;
close OUTFILE;

# create aditional info file if needed
# file in which we will put additional information from map file
my $auxFile = "";
if($OutFile=~m/(^.*[\/]|[\\])/)
{
	$auxFile = "summery.txt"; #filn
	$auxFile = "$1$auxFile";
}
#print $auxFile;

foreach my $key ( keys %Sections )  {
    # print "$key $Sections{$key}{VirtualAddress} $Sections{$key}{UsedSize} \n" ;
	my $hash = $Sections{$key}{'ModuleInfo'};
	
	# print Dumper($hash);
	for $key2 ( @$hash ) {
		# print "\t $key2->{SymbolName} $key2->{Address} $key2->{Size}\n";
	}
}
# End-of-file

