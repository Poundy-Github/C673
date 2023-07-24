use strict;
use warnings;


my $full      = "";
my $subst     = "";
my $foundFlag = 0;
my $project   = $ARGV[0];
my $core      = $ARGV[1];
my $path      = "04_Engineering/03_Workspace/sw/make/source_list_".$project."/";


print "Running generate_SourceList.pl \n";

# Open file
open (my $IN, "<", $path."build_sources_".$core.".txt") || die "Error: $!";

# Write new file
open (OUT, ">", $path."build_sources_".$core."_extract.txt") or die $!;

# print "\nExtracting used source files from ".$core."\n";
# Extract content
while (<$IN>){
  # Ignor all sub-elements under a already found content
  if ((index($_, $subst."| ") != -1) && ($foundFlag == 1)) {
	$full = "ignored".$_;
	# print $full;

  # Search for exclude content
  } elsif ((index($_, '04_Engineering\01_Source_Code\3rdParty') != -1) || 
		   (index($_, '04_Engineering\01_Source_Code\Algo_'.$project) != -1) ||
		   (index($_, '04_Engineering\01_Source_Code\common_'.$project.'\DEM') != -1) ||
		   (index($_, '04_Engineering\01_Source_Code\common_'.$project.'\rte') != -1) ||
		   (index($_, 'Dem_IntErrIdSlv.h') != -1) ||
		   # DEM files 
		   (index($_, 'Dem_Client.') != -1) ||
		   (index($_, 'Dem_ClientCustom.') != -1) ||
		   (index($_, 'Dem_ClientCustom_') != -1) ||
		   (index($_, 'Dem_Common') != -1) ||
		   (index($_, 'Dem_IpcIo') != -1) ||
		   (index($_, 'Std_Types') != -1) ||
		   (index($_, 'Sys_Mem') != -1) ||
		   # End DEM files
		   (index($_, '04_Engineering\03_Workspace') != -1) ||
		   (index($_, '04_Engineering\04_Build') != -1) ||
		   (index($_, '05_Deliverables') != -1)) {
	$subst = substr($_, 0, index($_, "+-"));
	# print "sString".$subst."... \n";
	$foundFlag = 1;
	$full = "IGNORED".$_;
	# print $full;

  # Left over content found for testing
  } else {
	$foundFlag = 0;
	$full = "extract".$_;
	# print $full;
	# Just write .c, .cpp and .h files into the output ifle
	if ((index($_, '.c') != -1) ||
		(index($_, '.cpp') != -1) ||
		(index($_, '.h') != -1)) {
	  # print substr($_, index($_, "+-")+2);
	  print OUT substr($_, index($_, "+-")+2);
	}
  }
}
# print "Extracted  used source files from ".$core."\n";

close $IN;
close (OUT);

if(-e $path."build_sources_".$core.".txt")
{
    unlink $path."build_sources_".$core.".txt";
}