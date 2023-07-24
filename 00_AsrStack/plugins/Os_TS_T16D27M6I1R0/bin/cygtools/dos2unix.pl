#!/usr/bin/perl

sub usage {
	print STDERR "Usage: $0 <file>\n";
	exit 1;
}

usage() unless @ARGV==1;

my $file = $ARGV[0];
my $FILEH;

# Read the file with the CRLF translation layer turned on
open($FILEH, '<:crlf', $file) or die "cannot open $file: $!\n";
my @lines = <$FILEH>;
close($FILEH);

# Write back the file in raw mode
open($FILEH, '>:raw', $file) or die "cannot open $file for writing: $!\n";
print $FILEH @lines;
close($FILEH);

