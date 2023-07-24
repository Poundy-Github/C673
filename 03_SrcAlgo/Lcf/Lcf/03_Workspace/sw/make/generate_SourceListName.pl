#!/usr/local/bin/perl
use strict;
use warnings;


my $project   = $ARGV[0];
my $path      = "source_list_".$project."/";
my $foundIt;
my @sourceFileListResponsible;


print "Running generate_SourceListName.pl \n";

# Load current source file list as starting point for merge
my @buildSourcesExtract = do {
    open my $fh, "<", $path."build_sources_extract.txt"
        or die "could not open file!";
    <$fh>;
};
my $sizebuildSourcesExtract = @buildSourcesExtract;
# Remove leading path elements to be able to compare to input from xls sheet
my @buildSourcesExtractShort = map(substr($_, 30), @buildSourcesExtract);

# Load the list generated from xls sheet
my @sourceFileListName = do {
    open my $fh, "<", $path."fromXLS_SourceListNames.txt"
        or die "could not open file!";
    <$fh>;
};

# Check for each source file if there is a name in the xls sheet
for (my $count = 0; $count < $sizebuildSourcesExtract; $count++) {
	foreach (@sourceFileListName) {
		if (index(lc($_), lc($buildSourcesExtractShort[$count])) != -1) {
			$foundIt = 1;
			# print substr($sourceFileListName[$count], 0, index($sourceFileListName[$count], ";")+1).$buildSourcesExtract[$count];
			$sourceFileListResponsible[$count] = substr($_, 0, index($_, ";")+1).$buildSourcesExtract[$count];
		}
	}
	if ($foundIt == 1) {
		$foundIt = 0;
	} else {
		# print "NotInXLS SoFar;".$buildSourcesExtract[$count];
		$sourceFileListResponsible[$count] = "NotInXLS SoFar;".$buildSourcesExtract[$count];
	}
}


#Write array to file
my $file = $path.$project."_SourceListNames.txt";
open (my $out, ">$file") or die "Cannot open $file: $!";
foreach (@sourceFileListResponsible) {
  print $out $_;
}

close $out;
