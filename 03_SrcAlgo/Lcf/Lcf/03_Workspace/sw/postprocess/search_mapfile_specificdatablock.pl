#!/usr/local/bin/perl
use strict;
use warnings FATAL => 'all';
# use diagnostics;

print ("\n--- Start: search_mapfile_specificdatablock.pl \n");
my $platform = $ARGV[0];
my $buildconfig = $ARGV[1] . "_arm-m_0";
my $mapfile = "..\\..\\..\\04_Build\\out\\$platform\\$buildconfig\\arm-m_0.map";
print "\nSearchpath for map file: $mapfile \n\n";

my $postprocfile = "MulticorePostprocCommon.bat";
my $postprocoutfile = "MulticorePostprocCommonExe.bat";

my $specificdatablock_addr;                                             # taken from the map file
my $specificdatablock_length;                                           # taken from the map file
my $specificdatablock_end;                                              # calculated here
my $specificdatablock_file = 'specificdatablock.asc';                   # we might want to parametrise these later
my $specificdatablock_mapfile = 'hex6xspecificdatablock.map';

open(my $fh, $mapfile)                                          		or die "Cannot open $mapfile: $!\n";
while (<$fh>) {
  if (/\.specificdatablock$/) {
    /^\s*(\S+)\s*(\S+)\s*(\S+)\s*(\S+)/                         		or die "Strange line in $mapfile: $_";
    $specificdatablock_addr = $2;                                       # $1 seems to be same as $2
    $specificdatablock_length = $4;                                     # $3 seems to be same as $4
    last;
  }
}
close $fh;
defined $specificdatablock_addr                                         or die "no infoblock_addr in $mapfile\n";
defined $specificdatablock_length                                       or die "no infoblock_addr in $mapfile\n";

$specificdatablock_addr =~ s/^0*/0x/;
$specificdatablock_length =~ s/^0*/0x/;
$specificdatablock_end = eval "$specificdatablock_addr + $specificdatablock_length";    # changed fixed 256 to $specificdatablock_length here, output mot and bin files unchanged
$@                                                              		and die "strange address expr $specificdatablock_addr + $specificdatablock_length: $@\n";
$specificdatablock_end = sprintf "0x%x", $specificdatablock_end;

print "$mapfile: specificdatablock at $specificdatablock_addr original length $specificdatablock_length, end $specificdatablock_end\n";

# write the little batch file to set the new variables
{
  my $batch = <<fred;
\@echo off
rem this is a generated file
rem usage: call specificdatablock_details.bat specificdatablock_addr specificdatablock_length specificdatablock_end
set "%~1=$specificdatablock_addr"
set "%~2=$specificdatablock_length"
set "%~3=$specificdatablock_end"
rem end of file
fred
  open(my $fho, ">specificdatablock_details.bat")                       or die "cannot open specificdatablock_details.bat: $!\n";
  print $fho $batch;
  close $fho;
}

# write the specificdatablock linker command file
{
  my $hexcmd = <<fred;
/* --- this is a generated file --- */
-a
-datawidth 8
-romwidth 8
-order MS
SECTIONS
{
  .specificdatablock:
}
ROMS
{
  specificdatablock:
  origin=$specificdatablock_addr,
  length=$specificdatablock_length,
  romwidth=8,
  memwidth=8,
  fill=0
  files={ $specificdatablock_file }
}
-image
-map $specificdatablock_mapfile
/* --- EOF --- */
fred
  open(my $fho, ">hex6x_specificdatablock.cmd")                         or die "cannot open hex6x_specificdatablock.cmd: $!\n";
  print $fho $hexcmd;
  close $fho;
}

print ("\n--- Done:  search_mapfile_specificdatablock.pl\n");
exit 0;