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
my $UsageStr = "You have to specfiy the ARM-A MAP file and the output standard map file to generate information from!";
die $UsageStr if ($ARGC < 2);
my $MapFile = shift @ARGV;
my $OutFile = shift @ARGV;
# If the named map file does not exist, abort
die "The file \"${MapFile}\" does not exist! Please provide name of ARM-A map file name as parameter!" if (!-f $MapFile);
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

#regular expressions to find symbol names, addresses and sizes

#symbol name and size in same line
my $SymbolExp1 = 	qr{\A	(\w+)							#symbol name
					\s+0x	([0-9a-f]+)						#size
					\s+		(\w[^x][0-9a-z_:.\/\\()\-]+)	#path
					\z}mixs;

#symbol name only
my $SymbolExp2 = 	qr{\A	\w+								#symbol name
					\z}mixs;
				
#size only				
my $SymbolExp3 = 	qr{\A
					\s+0x	([0-9a-f]+)						#size
					\s+		(\w[^x][0-9a-z_:.\/\\()\-]+)	#path
					\z}mixs;

#adress and symbol name
my $SymbolExp4 = 	qr{\A
					\s+0x	([0-9a-f]{8})					#address
					\s+		(\w+)							#symbol name
					\z}mixs;

my %Symbols;
my $Address;
my $Size;
my $SymbolName;
my $Path;
my $lf = 0;
					
while (my $line = <MAPFILE>) {
	chomp($line);
    # ARGH: Chomp does not always work for different perl versions	
    $line =~ s/\n//g;	
	if ((my $Name, $Size, $Path) = $line =~ /$SymbolExp1/) {
		if (!defined $Symbols{$Name}){
			while (length($Size)<8){
				$Size = "0" . $Size;
			}
			$Symbols{$Name} = [$Size];
		}
	} elsif ($line =~ /$SymbolExp2/) {
		$SymbolName = $line;
		$lf = 1;
	} elsif ((($Size, $Path) = $line =~ /$SymbolExp3/) && $lf == 1) {
		while (length($Size)<8){
			$Size = "0" . $Size;
		}
		$Symbols{$SymbolName} = [$Size];
		$lf = 0;
	} elsif (($Address, $SymbolName) = $line =~ /$SymbolExp4/) {
		if (defined $Symbols{$SymbolName}) {
			unshift @{$Symbols{$SymbolName}}, $Address;
		}
	} else {
    # Other lines can be safely ignored for our purposes
	$lf = 0;
	}
}
#delete sybols without addresses
my @ToBeDeleted;
for my $SymKey (keys %Symbols){
	if (!defined $Symbols{$SymKey}[1]){
		push @ToBeDeleted, $SymKey;
	}
}
delete @Symbols{@ToBeDeleted};

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

	#Add Offset to Address
	my $RealAddress = hex($Symbols{$key}[0]) + hex($Offset);
	my $LocAddress = sprintf("%x",$RealAddress);
	while (length($LocAddress)<8){
		$LocAddress = "0" . $LocAddress;
	}
	$Size = $Symbols{$key}[1];
	print OUTFILE "${key} 0x${LocAddress} 0x${Size}\n";
}
# Now we can close the mapfile, we have all information we need in RAM
close MAPFILE;
close OUTFILE;

# End-of-file
