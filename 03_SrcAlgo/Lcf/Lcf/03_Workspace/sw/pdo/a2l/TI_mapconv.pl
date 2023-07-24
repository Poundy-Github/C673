#!perl -w
#
# Perl script for printing basic information on a binary created
# by the ARM_TI tool-chain. This basic information includes
# RAM/ROM use as well as a few basic warnings about sections
# spanning multiple address ranges etc.
#
use warnings;
use strict;

# Get number of arguments passed to script
my $ARGC = @ARGV;
# If too few arguments, then abort
my $UsageStr = "You have to specfiy the ARM-M, EVE or DSP MAP file and the output standard map file to generate information from!";
die $UsageStr if ($ARGC < 2);
my $MapFile = shift @ARGV;
my $OutFile = shift @ARGV;
# If the named map file does not exist, abort
die "The file \"${MapFile}\" does not exist! Please provide name of ARM-M, EVE or DSP map file name as parameter!" if (!-f $MapFile);
# Now open the mapfile for input
open MAPFILE, "<$MapFile" or die "The file \"${MapFile}\" could not be opened for reading!";
open OUTFILE, ">$OutFile" or die "The file \"${OutFile}\" could not be opened for writing!";

# Set default option values and process options passed
my $EnableEmptyAddrRangeInfo = 0;
my $Offset = 0;
my @OffsetArray;
my $OffsetArrayLength = 0;
my $OffsetRangeCounter = 0;
my $EnableNotFitingSectionAssign	= 1;
my $EnableAddressRangeCfgVerify		= 1;
my $Prefix;
# We may have further options on the command line, process them
foreach my $CurOption (@ARGV) {
    if ($CurOption =~ /^-enable-empty-range$/) {
        $EnableEmptyAddrRangeInfo = 1;
    } elsif (my ($Prefix, $TempOffset) = $CurOption =~ /\A(0x){0,1}([0-9a-f]{8})\z/i) {
		# Add the current get hex offset value to an array
		$OffsetArray[$OffsetArrayLength] = $TempOffset;
		$OffsetArrayLength++;
	} elsif ($CurOption =~ /^-disable-section-overlap-search$/) {
        $EnableNotFitingSectionAssign = 0;
    } else {
        die "Unknown option \"${CurOption}\"! Aborting!";
    }
}

# Check the number of offset entries in the array
if ($OffsetArrayLength == 0) {
	#Do nothing with eOffset
} elsif ($OffsetArrayLength == 1) {
	$Offset = $OffsetArray[0];
} elsif ( ($OffsetArrayLength % 3) == 0 ) {
	$OffsetRangeCounter = $OffsetArrayLength / 3;
} else {
	die "Invalid number of offset parameters. Must be either only one or a multiple of 3!";
}


#regular expression to find symbol names, addresses and sizes
my $SymbolExp1 = 	qr{\A\s+	([0-9a-f]{8})			#address
					\s+			([0-9a-f]{8})			#size
					.+:			(\w+)					#symbol name
					\)}mixs;
					
my $SymbolExp2 = 	qr{\A		([0-9a-f]{8})			#address
					\s+			(\w+)					#symbol name
					\z}mixs;

my %Symbols;
my $Address;
my $Size;
my $SymbolName;
					
while (<MAPFILE>) {
	chomp;
    # ARGH: Chomp does not always work for different perl versions
    s/[\r\f\n]+//g;	
	if (($Address, $Size, $SymbolName) = $_ =~ /$SymbolExp1/){
		if (!defined $Symbols{$SymbolName}){
			$Symbols{$SymbolName} = [$Address, $Size];
		}
		else {
			if ($Symbols{$SymbolName}[0] ne $Address) {
				$Symbols{$SymbolName}[0] = $Address;
			}
			elsif (!defined $Symbols{$SymbolName}[1]){
				push @{$Symbols{$SymbolName}}, $Size;
			}
		}
	} elsif (($Address, $SymbolName) = $_ =~ /$SymbolExp2/) {
		if (!defined $Symbols{$SymbolName}){
			$Symbols{$SymbolName} = [$Address];
		}
		else {
			if ($Symbols{$SymbolName}[0] ne $Address) {
				$Symbols{$SymbolName}[0] = $Address;
			}
		}
	} else {
    # Other lines can be safely ignored for our purposes
	}
}

#Write Output
keys %Symbols;
my $key;
my $cnt;
my $minAddress = 0;
my $maxAddress = 0;
my $values = ();
while (($key, $values) = each %Symbols) {

	#Get address and check against the range(s) to set the correct $Offset
	#Go through all offset ranges and check the against the current symbol's address
	$cnt = $OffsetRangeCounter;
	while($cnt > 0) {
		# Decrement the counter by 1 for the index in the array
		$cnt--;	
		# Calc the index of the min address in the array for the current range
		$minAddress = $OffsetArray[($cnt * 3)];
		# Calc the index of the max address in the array for the current range
		$maxAddress = $OffsetArray[($cnt * 3) + 1];
		# Check if the address is in the current range values
		if ( (hex($Symbols{$key}[0]) >=  hex($minAddress)) && (hex($Symbols{$key}[0]) <=  hex($maxAddress)) ) {
			# Set Offset
			$Offset = $OffsetArray[($cnt * 3) + 2];
		} 
	}
	
	if (!defined $Symbols{$key}[1]){
		#Add Offset to Address
		my $RealAddress = hex($Symbols{$key}[0]) + hex($Offset);
		my $LocAddress = sprintf("%x",$RealAddress);
		while (length($LocAddress)<8){
			$LocAddress = "0" . $LocAddress;
		}
		print OUTFILE "${key} 0x${LocAddress}\n";
	}
	else {
		#Add Offset to Address
		my $RealAddress = hex($Symbols{$key}[0]) + hex($Offset);
		my $LocAddress = sprintf("%x",$RealAddress);
		while (length($LocAddress)<8){
			$LocAddress = "0" . $LocAddress;
		}
		$Size = $Symbols{$key}[1];
		print OUTFILE "${key} 0x${LocAddress} 0x${Size}\n";
	}
}
# Now we can close the mapfile, we have all information we need in RAM
close MAPFILE;
close OUTFILE;

# End-of-file

