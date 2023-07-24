#!/usr/local/bin/perl

use strict;
use warnings FATAL => 'all';
#use diagnostics;

'$Revision: 1.1 $' =~ /([\d.]+)/;
our $mksversion = $1 || 0;
my $command = $0;
$command =~ m-[/\\]+([^/\\]+)$- and $command = $1;

#print ("\n--- Start: search_map.pl \n");

my $usage = <<fred;
$command project
   project is srlcam or mono (nothing specifies smfc400)
fred

my $long_usage = <<fred;
$command project
   project is srlcam or mono (no value specifies smfc4b0)

The parameter can also be a project name such as (case insensitive)
   smfc4b0
   srlcam4t0
   mfl420ta46 (srlcam)
   mfc4t0, mfc430ta16 (mono)

Output is a series of files defining column values for an excel spreadsheet.
fred

while (defined ($_ = $ARGV[0])) {
  last unless /^-/;
  shift;
  $_ eq '--'           and last;
  $_ eq '-h'           and print $usage and exit;
  $_ =~ /^-h(?:elp)?/i and print $long_usage and exit;
  $_ eq '-v'           and print "$0 mks version $mksversion\n" and exit;
  print STDERR "$0: unrecognised option $_\n" and exit 1;
}
my $prj = lc($ARGV[0] || 'smfc4b0'); # default project, map to lowercase

my %projects = ( # this maps identifying tags for each project to the corresponding properties
  mfc431 => {
    projectname => 'mfc431',
    buildOut    => 'mfc431',
    used_cores  => [ qw/arm-a_0 arm-m_0 arm-m_1 dsp_0 dsp_1 eve_0 eve_1/ ],
 },
  mfc431lo19 => {
    projectname => 'mfc431lo19',
    buildOut    => 'mfc431lo19',
    used_cores  => [ qw/arm-a_0 arm-m_0 arm-m_1 dsp_0 dsp_1 eve_0 eve_1/ ],
 },
   mfc431lo20 => {
    projectname => 'mfc431lo20',
    buildOut    => 'mfc431lo20',
    used_cores  => [ qw/arm-a_0 arm-m_0 arm-m_1 dsp_0 dsp_1 eve_0 eve_1/ ],
 },
  mfc431sc19 => {
    projectname => 'mfc431sc19',
    buildOut    => 'mfc431sc19',
    used_cores  => [ qw/arm-a_0 arm-m_0 arm-m_1 dsp_0 dsp_1 eve_0 eve_1/ ],
 },
    mfc431hi28 => {
    projectname => 'mfc431hi28',
    buildOut    => 'mfc431hi28',
    used_cores  => [ qw/arm-a_0 arm-m_0 arm-m_1 dsp_0 dsp_1 eve_0 eve_1/ ],
 },
    mfc431ta19 => {
    projectname => 'mfc431ta19',
    buildOut    => 'mfc431ta19',
    used_cores  => [ qw/arm-a_0 arm-m_0 arm-m_1 dsp_0 dsp_1 eve_0 eve_1/ ],
 },
    mfc431sw19 => {
    projectname => 'mfc431sw19',
    buildOut    => 'mfc431sw19',
    used_cores  => [ qw/arm-a_0 arm-m_0 arm-m_1 dsp_0 dsp_1 eve_0 eve_1/ ],
 },
    mfc431bd10 => {
    projectname => 'mfc431bd10',
    buildOut    => 'mfc431bd10',
    used_cores  => [ qw/arm-a_0 arm-m_0 arm-m_1 dsp_0 dsp_1 eve_0 eve_1/ ],
 },
    mfc431va10 => {
    projectname => 'mfc431va10',
    buildOut    => 'mfc431va10',
    used_cores  => [ qw/arm-a_0 arm-m_0 arm-m_1 dsp_0 dsp_1 eve_0 eve_1/ ],
 },
    mfc431va21 => {
    projectname => 'mfc431va21',
    buildOut    => 'mfc431va21',
    used_cores  => [ qw/arm-a_0 arm-m_0 arm-m_1 dsp_0 dsp_1 eve_0 eve_1/ ],
 },
  ars441 => {
    projectname => 'ars441',
    buildOut    => 'ars441',
    used_cores  => [ qw/arm-m_0 dsp_0 dsp_1/ ],
 }, 
  hfl110 => {
    projectname => 'hfl110',
    buildOut    => 'hfl110',
    used_cores  => [ qw/arm-a_0 arm-m_0 arm-m_1 dsp_0 dsp_1 eve_0 eve_1/ ],
 }, 
  hfl110ta10 => {
    projectname => 'hfl110ta10',
    buildOut    => 'hfl110ta10',
    used_cores  => [ qw/arm-a_0 arm-m_0 arm-m_1 dsp_0 dsp_1 eve_0 eve_1/ ],
 }, 
   ncapx => {
    projectname => 'NCAPx',
    buildOut    => 'NCAPx',
    used_cores  => [ qw/arm-a_0 arm-m_0 arm-m_1 dsp_0 dsp_1 eve_0 eve_1/ ],
 },
);
my %alias = ( # these are names given to the scons build for each project
  ars441     => 'ars441',
  mfc431     => 'mfc431',
  mfc431lo19 => 'mfc431lo19',
  mfc431lo20 => 'mfc431lo20',
  mfc431bd10 => 'mfc431bd10',
  mfc431sc19 => 'mfc431sc19',
  mfc431hi28 => 'mfc431hi28',
  mfc431ta19 => 'mfc431ta19',
  mfc431sw19 => 'mfc431sw19',
  mfc431va10 => 'mfc431va10',
  hfl110     => 'hfl110',
  hfl110ta10     => 'hfl110ta10',
  ncapx      => 'ncapx'
);
if (not $projects{$prj} and $alias{$prj}) {
  $prj = $alias{$prj};
}
$projects{$prj} or die "undefined project $prj\n";
my ($projectname, $buildOut, $memory_file, $build_config, $motfile) =
  @{$projects{$prj}}{qw/projectname buildOut memory_file build_config motfile/};

print "projectname $projectname\n";

# defaults for the new directory structure and scons
$memory_file ||= "../../../../04_Engineering/00_Projects/$projectname/MEMMAP_DPU/memory_soc0.cmd";
$build_config ||= 'ContiRelease';
$motfile ||= "../../../../04_Engineering/04_Build/mot/release_${projectname}_soc.mot";

# core-specific definitions: soc chip and map file
my %cores;
if ($projects{$prj}{old_tree}) {
  # keys %cores is the list of all expected cores
  # this is only for the mfc4t0_branch project, for which we are only listing the release builds
  %cores = (
    'arm-a_0' => { qw( soc soc1 mapfile ../../../S11_APPL/04_Engineering/03_Workspace/CCS/VH28_Release/CA8.map ) },
    'arm-m_0' => { qw( soc soc1 mapfile ../../../S12_APPL/04_Engineering/03_Workspace/CCS/VH28_Release/M3VIDEO.map ) },
    'arm-m_1' => { qw( soc soc1 mapfile ../../../S13_APPL/04_Engineering/03_Workspace/CCS/VH28_Release/MXVPSS_ALGO.map ) },
    dsp_0     => { qw( soc soc1 mapfile ../../../S14_APPL/04_Engineering/03_Workspace/CCS/VH28_Release/DSP_0.map ) },
    dsp_1     => { qw( soc soc1 mapfile ../../../S25_APPL/04_Engineering/03_Workspace/CCS/VH28_Release/DSP_1.map ) },
    eve_0     => { qw( soc soc1 mapfile ../../../S16_APPL/04_Engineering/03_Workspace/CCS/ContiRelease/ARP32_0.map ) },
    eve_1     => { qw( soc soc1 mapfile ../../../S27_APPL/04_Engineering/03_Workspace/CCS/ContiRelease/ARP32_1.map ) },
  );
}
else {
  # rather more systematic...
  if ($projects{$prj}{dual_soc}) {
    foreach my $core (qw/arm-a_1 arm-m_2 arm-m_3 dsp_1 eve_1/) {
      $cores{$core}{soc} = 'soc2';
    }
  }
  # keys %cores is the list of all possible cores
  foreach my $core (@{$projects{$prj}{used_cores}}) {
    $cores{$core}{mapfile} = "../../../../04_Engineering/04_Build/out/$buildOut/release_$core/$core.map";
    $cores{$core}{soc} ||= 'soc1';
  }
}

my $IN;
# we get the basic information from the cmd file, check it with the dsp_0 map file and use it in the other map files
my ($ddrcount, @ddrarr, @sorted, @name, @org, @len, $sizesorted);

$ddrcount = 0;

{
  #Open Linker Command File
  undef $IN;
  open ($IN, $memory_file) || die "Error: cannot open $memory_file: $!";
  #Extract mem name lines
  while (<$IN>){
    if ($_=~ /: org =/i) {  	
    	$ddrarr[$ddrcount] = $_;
  	  ++$ddrcount;
    }
  }
  close $IN;
  
  #Sort the DDR mem names according to start address.
  #Write the sorted names to a new array.
  @sorted = sort {
    my @a = split(/: org = 0x/, $a);
    my @b = split(/: org = 0x/, $b);
    $a[1] cmp $b[1];
    } @ddrarr;
  
  #Remove first four blanks
  @sorted = map(substr($_, 4), @sorted);
  
  #Find the first blank after the name and skip all the rest.
  #Write the mem name to a new array.
  @name = map(substr($_, 0, index($_, " ")), @sorted);
  #foreach (@name) {print "$_ \n";}
  
  #Find the start address and skip all the rest.
  #Write the address to a new array.
  @org = map(substr($_, index($_, "org = 0x")+8, 8,), @sorted);
  #foreach (@org) {print "$_ \n";}
  
  #Find the length and skip all the rest.
  #Write the address to a new array.
  @len = map(substr($_, index($_, "len = 0x")+8, 8,), @sorted);
  #foreach (@len) {print "$_ \n";}
  
  $ddrcount=0;
  $sizesorted = @sorted;
  my $lastindex = $sizesorted - 2;
  for ($ddrcount = 0; $ddrcount <= $lastindex; $ddrcount++) {
  	if ((hex($org[$ddrcount]) + hex($len[$ddrcount])) > hex($org[$ddrcount+1]) && ($ddrcount < $sizesorted-1)) {
  		print ("\n!!! Error in Memory Map - Overlapping area: ".$name[$ddrcount]." ! \n");
  		die "Error: $!";
  	}
  }
}

print ("\n--- Analyze SoC - ".$build_config." - map files ! \n");

my ($i, $from_line);

my %socs = (
  soc1 => { name => [], origin => [], reserved => [], used => [], },
  soc2 => { name => [], origin => [], reserved => [], used => [], },
);
my @mapname;


#-------------------
if ($cores{dsp_0}) {
  my $core = 'dsp_0';
  my $soc = $cores{$core}{soc};
  print ("$core on $soc\n");

  # S14/dsp_0 is used to extract the name, start address (origin), length, and used RAM,
  # Other map files are just used to extract the length.
  
  my (@arrdsp_0, @maporigin, @lendsp_0, @usedsp_0);
  my $mapfile = $cores{$core}{mapfile};
  undef $IN;
  open ($IN, $mapfile) || die "Cannot open $mapfile: $!";
  $ddrcount=0;
  $from_line=8192;
  while (<$IN>){
    if ($_=~ /----------------------/i) {$from_line = $ddrcount + 1;}
    if (($ddrcount >= $from_line) && ($ddrcount < $from_line + $sizesorted)) {$arrdsp_0[$ddrcount - $from_line] = $_;}
    ++$ddrcount;
    }
  close $IN;
  
  #Remove first two blanks
  @arrdsp_0 = map(substr($_, 2), @arrdsp_0);
  
  #Find the first blank after the name and skip all the rest.
  @mapname = map(substr($_, 0, index($_, " ")), @arrdsp_0);
  
  for ($i = 0; $i < $sizesorted; $i++) {
    if ($name[$i] ne $mapname[$i]) {
    	print ("\n!!! Error in dsp_0 Memory Map - Different Names in cmd and map file: ".$name[$i]."  -  ".$mapname[$i]." \n");
    	# extra information like this would be quite useful in the event of an error
    	# but better to provide a generic error handler than to add this everywhere
    	# print ("    cmd file $memory_file\n    map file $mapfile\n");
    	die "Error: different names for dsp_0";
    }
  }
  
  #Find the start address and skip all the rest.
  @maporigin = map(substr($_, 22, 8,), @arrdsp_0);
  
  for ($i = 0; $i < $sizesorted; $i++) {
    if (lc($org[$i]) ne $maporigin[$i]) {
    	print ("\n!!! Error in dsp_0 Memory Map - Different Start Addresses in cmd and map file for: ".$name[$i]."  -  ".$mapname[$i]." \n");
    	print ("!!!                                                                             ".$org[$i]."  -  ".$maporigin[$i]." \n");
    	die "Error: different start addresses for dsp_0";
    }
  }
  
  #Find the length and skip all the rest.
  @lendsp_0 = map(substr($_, 33, 8,), @arrdsp_0);
  
  for ($i = 0; $i < $sizesorted; $i++) {
    if (lc($len[$i]) ne $lendsp_0[$i]) {
    	print ("\n!!! Error in dsp_0 Memory Map - Different Length in cmd and map file for: ".$name[$i]."  -  ".$mapname[$i]." \n");
    	print ("!!!                                                                    ".$len[$i]."  -  ".$lendsp_0[$i]." \n");
    	die "Error: different lengths for dsp0";
    }
  }
  
  #Find used and skip all the rest.
  @usedsp_0 = map(substr($_, 43, 8,), @arrdsp_0);
  
  for ($i = 0; $i < $sizesorted; $i++) {
  	$socs{$soc}{used}[$i] = "00000000";
    if (hex($usedsp_0[$i]) > hex($socs{$soc}{used}[$i])) {
  		$socs{$soc}{used}[$i] = $usedsp_0[$i];
  	 	#print ("!!! Note: Size non-zero for ".$socs{$soc}{used}[$i]." - ".$name[$i]." ! Changed in $soc used list.\n");
    }
  }
}


#-----------------------
if ($cores{'arm-a_1'}) {
  my $core = 'arm-a_1';
  my $soc = $cores{$core}{soc};
  print ("$core on $soc\n");

  my (@arrca8_1, @nameca8_1, @orgca8_1, @lenca8_1, @useca8_1, @sorted_ca8_1, $sDDR_CA8_DATA);
  my $mapfile = $cores{$core}{mapfile};
  undef $IN;
	open ($IN, $mapfile) || die "Cannot open $mapfile: $!";
	$ddrcount=0;
	$from_line=15000;
	while (<$IN>){
  	if ($_=~ /Memory Configuration/i) {
 			$from_line = $ddrcount + 3;
  		}
  	if (($ddrcount >= $from_line) && ($ddrcount < $from_line + $sizesorted)) {
  		$arrca8_1[$ddrcount - $from_line] = $_;
    	}  
  	++$ddrcount;
  	}
	close $IN;

	#Sort the arm-a_1 section names according to start address.
	#Write the sorted names to a new array.
	@sorted_ca8_1 = sort {
	  my @a = split(/ 0x/, $a);
	  my @b = split(/ 0x/, $b);
	  $a[1] cmp $b[1];
  	} @arrca8_1;

	#Find the first blank after the name and skip all the reset.
	@nameca8_1 = map(substr($_, 0, index($_, " ")), @sorted_ca8_1);

 #Check if the found names from the map file are the same like in the linker command file
	for ($i = 0; $i < $sizesorted; $i++) {
		if ($name[$i] ne $nameca8_1[$i]) {
			print ("\n!!! Error in $core Memory Map - Different Names in cmd and map file: ".$name[$i]."  -  ".$nameca8_1[$i]." \n");
			die "Error: $!";
		}
	}

	#Find the start address and skip all the rest.
	@orgca8_1 = map(substr($_, index($_, "0x"), 10,), @sorted_ca8_1);

  #Now check each start address
  for ($i = 0; $i < $sizesorted; $i++) {

  	my $start_addr =0;
  	my $end_addr   =0;
  	my $sum_used   =0;
  
  	my $ca8_helper_01=0;
  	my $ca8_helper_02=0;
  	my $ca8_helper_03=0;

    undef $IN;
		open ($IN, "../../../04_Build/out/$projectname/release_arm-a_1/arm-a_1_objdump.map") || die "Cannot open $mapfile: $!";
		$ddrcount=0;
		$from_line=15000;

    #print "Section: ".$nameca8_1[$i]." - ".$orgca8_1[$i]."\n";
		#Go through each line of the objdump.map file
		while (<$IN>){
  		#If section is available look for start address and add length to get end address
    	if ($_=~ substr($orgca8_1[$i],2,10)) {
    		$start_addr = hex(substr($orgca8_1[$i],2));
				$end_addr   = hex(substr($orgca8_1[$i],2)) + hex($len[$i]);
 				$from_line = $ddrcount;
  	}
	
	#Extract all available sections and add the length if it is inside the checked area
    	if ($_=~ /^....\./i) {  
    		$ca8_helper_01=substr($_, 6);
    		$ca8_helper_02=substr($ca8_helper_01, index($ca8_helper_01, " 0")+1, 18)."\n";
    		$ca8_helper_03=hex(substr($ca8_helper_02, 10, 8));
    		
    		if (($ca8_helper_03 >= $start_addr) && ($ca8_helper_03 < $end_addr)) {
    			#print "Addr: ".substr($ca8_helper_02, 10, 8)." - Len: ".substr($ca8_helper_02, 0, 8)."\n";
    			$sum_used=$sum_used+hex(substr($ca8_helper_02, 0, 8));
    		}
			}
  		++$ddrcount;
  		}
		close $IN;

		#print "Summe[dec]: ".$sum_used."\n";
		#print "Summe[hex]: ".sprintf("%X",$sum_used)."\n";
		#Write the caluclated section sum to the used array
		$useca8_1[$i]=sprintf("%X",$sum_used);
  }

	#Expand with leading zerros to a length of 8
  foreach (@useca8_1) {
  	$_ = sprintf('%08s', $_);
  }

  #Update the list of used memory if size is bigger like before. 
	for ($i = 0; $i < $sizesorted; $i++) {
		$socs{$soc}{used}[$i] = "00000000";
		if (hex($useca8_1[$i]) > hex($socs{$soc}{used}[$i])) {
			$socs{$soc}{used}[$i] = $useca8_1[$i];
			#print ("!!! Note: Size non-zero for ".$socs{$soc}{used}[$i]." - ".$name[$i]." ! Changed in $soc used list.\n");
		}
	}
}


#-----------------------
if ($cores{'arm-a_0'}) {
  my $core = 'arm-a_0';
  my $soc = $cores{$core}{soc};
  print ("$core on $soc\n");

  my (@arrca8_0, @nameca8_0, @orgca8_0, @lenca8_0, @useca8_0, @sorted_ca8_0, $sDDR_CA8_DATA);
  my $mapfile = $cores{$core}{mapfile};
  undef $IN;
  open ($IN, $mapfile) || die "Cannot open $mapfile: $!";
  $ddrcount=0;
  $from_line=15000;
  while (<$IN>){
    if ($_=~ /Memory Configuration/i) {
   		$from_line = $ddrcount + 3;
    	}
    if (($ddrcount >= $from_line) && ($ddrcount < $from_line + $sizesorted)) {
    	$arrca8_0[$ddrcount - $from_line] = $_;
      }
    ++$ddrcount;
    }
  close $IN;
    
  #Sort the arm-a_0 section names according to start address.
  #Write the sorted names to a new array.
  @sorted_ca8_0 = sort {
    my @a = split(/ 0x/, $a);
    my @b = split(/ 0x/, $b);
    $a[1] cmp $b[1];
    } @arrca8_0;
  
  #Find the first blank after the name and skip all the rest.
  @nameca8_0 = map(substr($_, 0, index($_, " ")), @sorted_ca8_0);
    
  #Check if the found names from the map file are the same like in the linker command file
  for ($i = 0; $i < $sizesorted; $i++) {
    if ($name[$i] ne $nameca8_0[$i]) {
      print ("\n!!! Error in $core Memory Map - Different Names in cmd and map file: ".$name[$i]."  -  ".$mapname[$i]." \n");
      die "Error: $!";
    }
  }
  
  #Find the start address and skip all the rest.
  @orgca8_0 = map(substr($_, index($_, "0x"), 10,), @sorted_ca8_0);

  #Now check each start address
  for ($i = 0; $i < $sizesorted; $i++) {

  	my $start_addr =0;
  	my $end_addr   =0;
  	my $sum_used   =0;
  
  	my $ca8_helper_01=0;
  	my $ca8_helper_02=0;
  	my $ca8_helper_03=0;

    undef $IN;
  	open ($IN, "../../../04_Build/out/$projectname/release_arm-a_0/arm-a_0_objdump.map") || die "Cannot open $mapfile: $!";
  	$ddrcount=0;
  	$from_line=15000;

    #print "Section: ".$nameca8_0[$i]." - ".$orgca8_0[$i]."\n";
		#Go through each line of the objdump.map file
  	while (<$IN>){
  		#If section is available look for start address and add length to get end address
    	if ($_=~ substr($orgca8_0[$i],2,10)) {
    		$start_addr = hex(substr($orgca8_0[$i],2));
				$end_addr   = hex(substr($orgca8_0[$i],2)) + hex($len[$i]);
   			$from_line = $ddrcount;
    	  }
    	
    	#Extract all available sections and add the length if it is inside the checked area
    	if ($_=~ /^....\./i) {  
    		$ca8_helper_01=substr($_, 6);
    		$ca8_helper_02=substr($ca8_helper_01, index($ca8_helper_01, " 0")+1, 18)."\n";
    		$ca8_helper_03=hex(substr($ca8_helper_02, 10, 8));
    		
    		if (($ca8_helper_03 >= $start_addr) && ($ca8_helper_03 < $end_addr)) {
    			#print "Addr: ".substr($ca8_helper_02, 10, 8)." - Len: ".substr($ca8_helper_02, 0, 8)."\n";
    			$sum_used=$sum_used+hex(substr($ca8_helper_02, 0, 8));
    		}
			}
    	++$ddrcount;
    }
  	close $IN;

		#print "Summe[dec]: ".$sum_used."\n";
		#print "Summe[hex]: ".sprintf("%X",$sum_used)."\n";
		#Write the caluclated section sum to the used array
		$useca8_0[$i]=sprintf("%X",$sum_used);
  }

	#Expand with leading zerros to a length of 8
  foreach (@useca8_0) {
  	$_ = sprintf('%08s', $_);
  }

  #Update the list of used memory if size is bigger like before. 
  for ($i = 0; $i < $sizesorted; $i++) {
    if (hex($useca8_0[$i]) > hex($socs{$soc}{used}[$i])) {
  		$socs{$soc}{used}[$i] = $useca8_0[$i];
  	 	#print ("!!! Note: Size non-zero for ".$socs{$soc}{used}[$i]." - ".$name[$i]." ! Changed in $soc used list.\n");
    }
  }
}


#-------------------
if ($cores{dsp_1}) {
  my $core = 'dsp_1';
  my $soc = $cores{$core}{soc};
  print ("$core on $soc\n");

  my (@arrdsp_1, @usedsp_1);
  my $mapfile = $cores{$core}{mapfile};
  undef $IN;
	open ($IN, $mapfile) || die "Cannot open $mapfile: $!";
	$ddrcount=0;
	$from_line=8192;
	while (<$IN>){
		if ($_=~ /----------------------/i) {$from_line = $ddrcount + 1;}
		if (($ddrcount >= $from_line) && ($ddrcount < $from_line + $sizesorted)) {$arrdsp_1[$ddrcount - $from_line] = $_;}
		++$ddrcount;
	}
	close $IN;

	#Find used and skip all the rest.
	@usedsp_1 = map(substr($_, 45, 8,), @arrdsp_1);

	for ($i = 0; $i < $sizesorted; $i++) {
		if (hex($usedsp_1[$i]) > hex($socs{$soc}{used}[$i])) {
			$socs{$soc}{used}[$i] = $usedsp_1[$i];
			#print ("!!! Note: Size non-zero for ".$socs{$soc}{used}[$i]." - ".$name[$i]." ! Changed in $soc used list.\n");
		}
	}
}


#-------------------
if ($cores{eve_0}) {
  my $core = 'eve_0';
  my $soc = $cores{$core}{soc};
  print ("$core on $soc\n");

  my (@arrarp32_0, @usearp32_0);
  my $mapfile = $cores{$core}{mapfile};
  undef $IN;
  open ($IN, $mapfile) || die "Cannot open $mapfile: $!";
  $ddrcount=0;
  $from_line=8192;
  while (<$IN>){
    if ($_=~ /----------------------/i) {$from_line = $ddrcount + 2;}
    if (($ddrcount >= $from_line) && ($ddrcount < $from_line + $sizesorted)) {$arrarp32_0[$ddrcount - $from_line] = $_;}
    ++$ddrcount;
    }
  close $IN;
  
  #Find used and skip all the rest.
  @usearp32_0 = map(substr($_, 45, 8,), @arrarp32_0);
  
  for ($i = 0; $i < $sizesorted; $i++) {
    if (hex($usearp32_0[$i]) > hex($socs{$soc}{used}[$i])) {
  		$socs{$soc}{used}[$i] = $usearp32_0[$i];
  	 	#print ("!!! Note: Size non-zero for ".$socs{$soc}{used}[$i]." - ".$name[$i]." ! Changed in $soc used list.\n");
    }
  }
}


#-------------------
if ($cores{eve_1}) {
  my $core = 'eve_1';
  my $soc = $cores{$core}{soc};
  print ("$core on $soc\n");
  my $mapfile = $cores{$core}{mapfile};
  if (not -f $mapfile) {
    print "Cannot find $mapfile - skipping $core\n"; # not being built in early scons mono releases
  } else {
    my (@arrarp32_1, @usearp32_1);
    undef $IN;
  	open ($IN, $mapfile) || die "Cannot open $mapfile: $!";
  	$ddrcount=0;
  	$from_line=8192;
  	while (<$IN>){
  		if ($_=~ /----------------------/i) {$from_line = $ddrcount + 2;}
  		if (($ddrcount >= $from_line) && ($ddrcount < $from_line + $sizesorted)) {$arrarp32_1[$ddrcount - $from_line] = $_;}
  		++$ddrcount;
  	}
  	close $IN;
  
  	#Find used and skip all the rest.
  	@usearp32_1 = map(substr($_, 45, 8,), @arrarp32_1);
  
  	for ($i = 0; $i < $sizesorted; $i++) {
  		if (hex($usearp32_1[$i]) > hex($socs{$soc}{used}[$i])) {
  			$socs{$soc}{used}[$i] = $usearp32_1[$i];
  			#print ("!!! Note: Size non-zero for ".$socs{$soc}{used}[$i]." - ".$name[$i]." ! Changed in $soc used list.\n");
  		}
  	}
  }
}


#-----------------------
if ($cores{'arm-m_2'}) {
  my $core = 'arm-m_2';
  my $soc = $cores{$core}{soc};
  print ("$core on $soc\n");

  my (@arrm3infra, $namem3infra, $orgm3infra, $lenm3infra, @usem3infra);
  my $mapfile = $cores{$core}{mapfile};
  undef $IN;
	open ($IN, $mapfile) || die "Cannot open $mapfile: $!";
	$ddrcount=0;
	$from_line=8192;
	while (<$IN>){
		if ($_=~ /----------------------/i) {$from_line = $ddrcount + 1;}
		if (($ddrcount >= $from_line) && ($ddrcount < $from_line + $sizesorted)) {$arrm3infra[$ddrcount - $from_line] = $_;}
		++$ddrcount;
	}
	close $IN;

	#Remove first two blanks
	@arrm3infra = map(substr($_, 2), @arrm3infra);

	#Find used and skip all the rest.
	@usem3infra = map(substr($_, 43, 8,), @arrm3infra);

	@{$socs{$soc}{name}} = @name;
	@{$socs{$soc}{origin}} = @org;
	@{$socs{$soc}{reserved}} = @len;

  no warnings;
	for ($i = 0; $i < $sizesorted+1; $i++) {
		if (hex($usem3infra[$i+1]) > hex($socs{$soc}{used}[$i])) {
			# $i+1 to skip first element of the the used list. Not needed because not in RAM.
			$socs{$soc}{used}[$i] = $usem3infra[$i+1];
			#print ("!!! Note: Size non-zero for ".$socs{$soc}{used}[$i]." - ".$socs{$soc}{name}[$i]." ! Changed in $soc used list.\n");
		}
	}
}


#-----------------------
if ($cores{'arm-m_0'}) {
  my $core = 'arm-m_0';
  my $soc = $cores{$core}{soc};
  print ("$core on $soc\n");

  my (@arrm3video, $namem3video, $orgm3video, $lenm3video, @usem3video, $size_arrm3video, @part1_arrm3video, @part2_arrm3video);
  my $mapfile = $cores{$core}{mapfile};
  undef $IN;
  open ($IN, $mapfile) || die "Cannot open $mapfile: $!";
  $ddrcount=0;
  $from_line=8192;
  while (<$IN>){
    if ($_=~ /----------------------/i) {$from_line = $ddrcount + 1;}
    if (($ddrcount >= $from_line) && ($ddrcount < $from_line + $sizesorted+1)) {$arrm3video[$ddrcount - $from_line] = $_;}
    ++$ddrcount;
    }
  close $IN;
  
  no warnings;
 
#Remove some lines from array. Not needed because not in RAM.
$size_arrm3video = @arrm3video;
#for($i=0; $i<$size_arrm3video;$i++)
#{
#	print ("Read from Core MapFile: ".$arrm3video[$i]);
#}

if(substr($projectname, 0, 6) eq 'mfc431')
{
	@part1_arrm3video = @arrm3video[2..30];
	@part2_arrm3video = @arrm3video[33..$size_arrm3video];
}
else
{
	@part1_arrm3video = @arrm3video[2..10];
	@part2_arrm3video = @arrm3video[13..$size_arrm3video];
}


@arrm3video = (@part1_arrm3video, @part2_arrm3video);

#for($i=0; $i<$size_arrm3video;$i++)
#{
#	print ("Read from Core MapFile: ".$arrm3video[$i]);
#}
  #Remove first two blanks
  ############# fixme string can be < 2 chars long
  
  @arrm3video = map(substr($_, 2), @arrm3video);
  
  #Find used and skip all the rest.
  @usem3video = map(substr($_, 43, 8,), @arrm3video);
    
  @{$socs{$soc}{name}} = @name;
  @{$socs{$soc}{origin}} = @org;
  @{$socs{$soc}{reserved}} = @len;
  
  for ($i = 0; $i < $sizesorted+1; $i++) {
    #print $socs{$soc}{name}[$i]." - ".$usem3video[$i]." - ".$socs{$soc}{used}[$i]."\n";
    if (hex($usem3video[$i]) > hex($socs{$soc}{used}[$i])) {
  		$socs{$soc}{used}[$i] = $usem3video[$i];
  	 	#print ("!!! Note: Size non-zero for ".$socs{$soc}{used}[$i]." - ".$socs{$soc}{name}[$i]." ! Changed in $soc used list.\n");
    }
  }
}


#-----------------------
if ($cores{'arm-m_1'}) {  
  my $core = 'arm-m_1';
  my $soc = $cores{$core}{soc};
  print ("$core on $soc\n");

  my (@arrm3vpss, @usem3vpss);
  my $mapfile = $cores{$core}{mapfile};
  undef $IN;
  open ($IN, $mapfile) || die "Cannot open $mapfile: $!";
  $ddrcount=0;
  $from_line=8192;
  while (<$IN>){
    if ($_=~ /----------------------/i) {$from_line = $ddrcount + 1;}
    if (($ddrcount >= $from_line) && ($ddrcount < $from_line + $sizesorted+1)) {$arrm3vpss[$ddrcount - $from_line] = $_;}
    ++$ddrcount;
    }
  close $IN;
  
  no warnings;
  #Find used and skip all the rest.
  @usem3vpss = map(substr($_, 45, 8,), @arrm3vpss);
  
  for ($i = 0; $i < $sizesorted+1; $i++) {
  	#print $socs{$soc}{name}[$i]." - ".$usem3vpss[$i+1]." - ".$socs{$soc}{used}[$i]."\n";
    if (hex($usem3vpss[$i+1]) > hex($socs{$soc}{used}[$i])) {
  		$socs{$soc}{used}[$i] = $usem3vpss[$i+1];
  	 	#print ("!!! Note: Size non-zero for ".$socs{$soc}{used}[$i]." - ".$socs{$soc}{name}[$i]." ! Changed in $soc used list.\n");
    }
  }
}

print ("--- SoC - ".$build_config." - analyzing done ! \n");


#Write arrays to files
foreach my $column (qw/name origin reserved used/) {
  foreach my $ucsoc (qw/SoC1 SoC2/) {
    my $file = "_${column}_sorted_$ucsoc.txt";
    open (my $out, ">$file")                             or die "Cannot open $file: $!";
    foreach (@{$socs{lc $ucsoc}{$column}}) {
      print $out "$_\n";
    }
    close $out;
  }
}

if (not $motfile) {
  print "No motfile specified - skipping write to _flash_end_address.txt\n";
}
elsif (not -f $motfile) {
  print "Cannot find motfile $motfile - skipping write to _flash_end_address.txt\n";
}
else {
	#Open ContiRelease mot file
	my $final_line = '';
    my $last_line = '';
	my ($zeros, $zstart, $zend);
	open(my $IN, $motfile)                   or die "Error: cannot open $motfile: $!\n";
	while (<$IN>){
	  #          8 hex    64 zeros
	  if (/^S325(........)0000000000000000000000000000000000000000000000000000000000000000../i) {
	    unless ($zeros) {
	      $zstart = $1;
  	      #print "! zstart $1, $_";
	      $zeros = 1;
	    }
	    next;
	  }
	  if (/^S3..(........)/i) {              # strictly speaking hexadecimal chars here and elsewhere
  	  if ($zeros) {
  	    $zend = $_;                        # FIXME: error handling here?
  	    #print "! zend $1, $_";
  	    undef $zeros;
  	  }
	    $final_line = $_;                    # in case we never get a last line
  		#if ($_=~ /^S315/i) {                 # FIXME: is the /i really necessary here and elsewhere?
  		#	$last_line = $_;
  		#  print "last line: $last_line";
  		#	last;
  		#}
  	  }
	}
	close $IN;
  if ($zeros) {
    $zend = '00000000';                    # FIXME: error handling here?
    undef $zeros;
  }
  #print "final line: $final_line";
	open(my $OUT, ">_flash_end_address.txt") or die "Cannot write to _flash_end_address.txt: $!\n";
	my ($flash_end_address, $flash_bound, $byte_count);
	$flash_end_address = substr($last_line || $final_line, 4, 8);
	$flash_end_address = hex $flash_end_address;
	#Extract the byte count from S-record, subtract 4 for S3 byte count, 
	# 1 for checksum and 1 because first address of this line is already known.
    $byte_count = (hex substr($final_line, 2, 2)) - 6;
    $flash_end_address += $byte_count;
	#Format first to HEX and then to string
    $flash_end_address = sprintf("%08X", $flash_end_address);
    $flash_end_address = sprintf("%s", $flash_end_address);
	if ($zend and $zend =~ /^S325(........)55AA55AA/i) {              # is this heuristic strict enough?
	  $flash_bound = $flash_end_address;
	  $flash_end_address = $zstart;
	  print "\n--- SoC Flash End Address: $flash_end_address, bound: $flash_bound\n";
	} else {
	  print "\n--- SoC Flash End Address: $flash_end_address\n";
	}
	# print $OUT "SoC Flash End Address:\n";
	# print $OUT substr($last_line, 4, 8);
	print $OUT "SoC Flash End Address:\n$flash_end_address\n"; # this with a terminating newline
	close $OUT;
}
#print "\nPress ENTER ...";
#$enter = <STDIN>;
