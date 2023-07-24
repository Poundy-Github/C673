#!/usr/local/bin/perl
use strict;
use warnings;
#print ("\n--- Start: generateIB.pl \n");

my $buildconfig = $ARGV[0];
my $projectname = $ARGV[1];
my $path = "";

# Set default buildconfig to debug if it is empty
if (!$buildconfig) {
	# set default
	$buildconfig = "debug";
}

# Set default projectname if it is empty
if (!$projectname) {
	# set default
	$projectname = "SMFC4B0";
}

$path = "<..\\..\\..\\00_Projects\\$projectname\\cfg_buildinfo.h";

if ($buildconfig eq "debug") {
	print ("\n--- Generating Infoblock. Debug build type detected. \n");
	print ("--- Release Version will be 00.00.00. Release Type will be 0x02: Testversion. \n\n"); }
elsif ($buildconfig eq "release") {
	print ("\n--- Generating Infoblock. Release build type detected. \n");
	print ("--- Release Version and Release Type will be taken from cfg_buildinfo.h file. \n\n"); }
else {
	die("Error: No valid build type selected!");
}

#Get user name
my $username;
if ($ENV{COMPUTERNAME} eq "LUD24TVG") {
	$username = 'JenkinsBuild';
}
else {
	$username = $ENV{USERNAME};
}

#Get the local time
my ($second, $minute, $hour, $dayOfMonth, $month, $yearOffset, $dayOfWeek, $dayOfYear, $daylightSavings) = localtime();

my $year = substr(1900 + $yearOffset, 2, 2);
my $date= sprintf("%d%02d%02d", $year, $month + 1, $dayOfMonth);++$month;
if ($month < 10) {
	$month = "0$month";
}
if ($dayOfMonth < 10) {
	$dayOfMonth = "0$dayOfMonth";
}
$date eq "$year$month$dayOfMonth" or die "bad date $date ne $year$month$dayOfMonth\n";
# my $date = "$year$month$dayOfMonth";
# well, the year will wrap around to 00 eventually...
$date =~ s/^0+//;
# but $month and $dayOfMonth will never be 0
# $date ||= 0;

my $time= sprintf("%d%02d%02d", $hour, $minute, $second);
if ($minute < 10) {
	$minute = "0$minute";
}
if ($second < 10) {
	$second = "0$second";
}
$time eq "$hour$minute$second" or die "bad time $time ne $hour$minute$second\n";
# my $time = "$hour$minute$second";
# without this, builds do not work from midnight to 1:00:00
$time =~ s/^0+//;
$time ||= 0;

#Open build.h file
my @build;
open (my $fh, $path) || die "Error: $!";
#Extract date and time lines
while (<$fh>){
  if ($_=~ /MK_BTIME/i) {
		$_= "#define MK_BTIME $time" . "U\n";
  }
	if ($_=~ /MK_BDATE/i) {
		$_= "#define MK_BDATE $date" . "U\n";
	}
	if ($_=~ /MK_BNAME/i) {
		$_= "#define MK_BNAME $username\n";
	}
	if ($_=~ /MK_EXE_BTYPE/i) {
		if ($buildconfig eq "debug") {
		  $_= "#define MK_EXE_BTYPE 0x02U\n";
		}
		elsif ($buildconfig eq "release") {
			# Use build type from cfg_buildinfo.h
		}
		else {
			die("Error: No valid build type selected!"); }
		}
	if ($_=~ /MK_EXE_VERSION/i) {
		if ($buildconfig eq "debug") {
	  	$_= "#define MK_EXE_VERSION 0x000000U\n";
		}
		elsif ($buildconfig eq "release") {
			# Use release version from cfg_buildinfo.h
		}
		else {
			die("Error: No valid build type selected!");
		}
	}
	push @build, $_;
}
close $fh; undef $fh;

#Write new buildinfo file
open (my $fho, ">new_buildinfo.h") or die "Error: cannot open new_buildinfo.h: $!\n";
print $fho @build;
close $fho;

# end of file
