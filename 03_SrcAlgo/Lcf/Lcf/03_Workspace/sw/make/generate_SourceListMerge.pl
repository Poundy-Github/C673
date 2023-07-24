#!/usr/local/bin/perl
use strict;
use warnings;


my $project   = $ARGV[0];
my $core      = $ARGV[1];
my $path      = "04_Engineering/03_Workspace/sw/make/source_list_".$project."/";


print "Running generate_SourceListMerge.pl \n";

# Load current file as starting point for merge
my @mergedFileList = do {
    open my $fh, "<", $path."build_sources_".$core."_extract.txt"
        or die "could not open file!";
    <$fh>;
};


# arm-a_0
if (-e $path."build_sources_arm-a_0_extract.txt") {
	my @nextFileList = do {
		open my $fh, "<", $path."build_sources_arm-a_0_extract.txt"
			or die "could not open file!";
		<$fh>;
	};
	my %numbOfLines = map {$_=>1} @mergedFileList;
	my @only_in_second = grep { !$numbOfLines{$_} } @nextFileList; 
	@mergedFileList = (@mergedFileList, @only_in_second);
}

# arm-a_1
if (-e $path."build_sources_arm-a_1_extract.txt") {
	my @nextFileList = do {
		open my $fh, "<", $path."build_sources_arm-a_1_extract.txt"
			or die "could not open file!";
		<$fh>;
	};
	my %numbOfLines = map {$_=>1} @mergedFileList;
	my @only_in_second = grep { !$numbOfLines{$_} } @nextFileList; 
	@mergedFileList = (@mergedFileList, @only_in_second);
}

# arm-m_0
if (-e $path."build_sources_arm-m_0_extract.txt") {
	my @nextFileList = do {
		open my $fh, "<", $path."build_sources_arm-m_0_extract.txt"
			or die "could not open file!";
		<$fh>;
	};
	my %numbOfLines = map {$_=>1} @mergedFileList;
	my @only_in_second = grep { !$numbOfLines{$_} } @nextFileList; 
	@mergedFileList = (@mergedFileList, @only_in_second);
}

# arm-m_1
if (-e $path."build_sources_arm-m_1_extract.txt") {
	my @nextFileList = do {
		open my $fh, "<", $path."build_sources_arm-m_1_extract.txt"
			or die "could not open file!";
		<$fh>;
	};
	my %numbOfLines = map {$_=>1} @mergedFileList;
	my @only_in_second = grep { !$numbOfLines{$_} } @nextFileList; 
	@mergedFileList = (@mergedFileList, @only_in_second);
}

# arm-m_2
if (-e $path."build_sources_arm-m_2_extract.txt") {
	my @nextFileList = do {
		open my $fh, "<", $path."build_sources_arm-m_2_extract.txt"
			or die "could not open file!";
		<$fh>;
	};
	my %numbOfLines = map {$_=>1} @mergedFileList;
	my @only_in_second = grep { !$numbOfLines{$_} } @nextFileList; 
	@mergedFileList = (@mergedFileList, @only_in_second);
}

# dsp_0
if (-e $path."build_sources_dsp_0_extract.txt") {
	my @nextFileList = do {
		open my $fh, "<", $path."build_sources_dsp_0_extract.txt"
			or die "could not open file!";
		<$fh>;
	};
	my %numbOfLines = map {$_=>1} @mergedFileList;
	my @only_in_second = grep { !$numbOfLines{$_} } @nextFileList; 
	@mergedFileList = (@mergedFileList, @only_in_second);
}

# dsp_1
if (-e $path."build_sources_dsp_1_extract.txt") {
	my @nextFileList = do {
		open my $fh, "<", $path."build_sources_dsp_1_extract.txt"
			or die "could not open file!";
		<$fh>;
	};
	my %numbOfLines = map {$_=>1} @mergedFileList;
	my @only_in_second = grep { !$numbOfLines{$_} } @nextFileList; 
	@mergedFileList = (@mergedFileList, @only_in_second);
}

# eve_0
if (-e $path."build_sources_eve_0_extract.txt") {
	my @nextFileList = do {
		open my $fh, "<", $path."build_sources_eve_0_extract.txt"
			or die "could not open file!";
		<$fh>;
	};
	my %numbOfLines = map {$_=>1} @mergedFileList;
	my @only_in_second = grep { !$numbOfLines{$_} } @nextFileList; 
	@mergedFileList = (@mergedFileList, @only_in_second);
}

# eve_1
if (-e $path."build_sources_eve_1_extract.txt") {
	my @nextFileList = do {
		open my $fh, "<", $path."build_sources_eve_1_extract.txt"
			or die "could not open file!";
		<$fh>;
	};
	my %numbOfLines = map {$_=>1} @mergedFileList;
	my @only_in_second = grep { !$numbOfLines{$_} } @nextFileList; 
	@mergedFileList = (@mergedFileList, @only_in_second);
}


#Write array to file
my @mergedFileListSorted = sort { "\L$a" cmp "\L$b" } @mergedFileList;
my $file = $path."build_sources_extract.txt";
open (my $out, ">$file") or die "Cannot open $file: $!";
foreach (@mergedFileListSorted) {
  print $out $_;
}

close $out;
