#!/usr/local/bin/perl
use strict;
use warnings FATAL => 'all';
# use diagnostics;

print ("\n--- Start: search_mapfile_common.pl \n");
my $platform = $ARGV[0];
my $buildconfig = $ARGV[1] . "_arm-m_0";
my $mapfile = "..\\..\\..\\04_Build\\out\\$platform\\$buildconfig\\arm-m_0.map";
print "\nSearchpath for map file: $mapfile \n\n";

my $postprocfile = "MulticorePostprocCommon.bat";
my $postprocoutfile = "MulticorePostprocCommonExe.bat";

my $infoblock_addr;                                             # taken from the map file
my $infoblock_length;                                           # taken from the map file
my $infoblock_end;                                              # calculated here
my $infoblock_file = 'infoblock.asc';                           # we might want to parametrise these later
my $infoblock_mapfile = 'hex6xinfoblock.map';

open(my $fh, $mapfile)                                          or die "Cannot open $mapfile: $!\n";
while (<$fh>) {
  if (/\.infoblock$/) {
    /^\s*(\S+)\s*(\S+)\s*(\S+)\s*(\S+)/                         or die "Strange line in $mapfile: $_";
    $infoblock_addr = $2;                                       # $1 seems to be same as $2
    $infoblock_length = $4;                                     # $3 seems to be same as $4
    last;
  }
}
close $fh;
defined $infoblock_addr                                         or die "no infoblock_addr in $mapfile\n";
defined $infoblock_length                                       or die "no infoblock_addr in $mapfile\n";

$infoblock_addr =~ s/^0*/0x/;
$infoblock_length =~ s/^0*/0x/;
$infoblock_end = eval "$infoblock_addr + $infoblock_length";    # changed fixed 256 to $infoblock_length here, output mot and bin files unchanged
$@                                                              and die "strange address expr $infoblock_addr + $infoblock_length: $@\n";
$infoblock_end = sprintf "0x%x", $infoblock_end;

print "$mapfile: infoblock at $infoblock_addr original length $infoblock_length, end $infoblock_end\n";

# write the little batch file to set the new variables
{
  my $batch = <<fred;
\@echo off
rem this is a generated file
rem usage: call infoblock_details.bat infoblock_addr infoblock_length infoblock_end
set "%~1=$infoblock_addr"
set "%~2=$infoblock_length"
set "%~3=$infoblock_end"
rem end of file
fred
  open(my $fho, ">infoblock_details.bat")                       or die "cannot open infoblock_details.bat: $!\n";
  print $fho $batch;
  close $fho;
}

# write the infoblock linker command file
{
  my $hexcmd = <<fred;
/* --- this is a generated file --- */
-a
-datawidth 8
-romwidth 8
-order MS
SECTIONS
{
  .infoblock:
}
ROMS
{
  infoblock:
  origin=$infoblock_addr,
  length=$infoblock_length,
  romwidth=8,
  memwidth=8,
  fill=0
  files={ $infoblock_file }
}
-image
-map $infoblock_mapfile
/* --- EOF --- */
fred
  open(my $fho, ">hex6x_infoblock.cmd")                         or die "cannot open hex6x_infoblock.cmd: $!\n";
  print $fho $hexcmd;
  close $fho;
}

print ("\n--- Done:  search_mapfile_common.pl\n");
exit 0;