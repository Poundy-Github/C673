#!/usr/local/bin/perl
#print ("\n--- Start: extractPrjDiff \n");

my $line_count = 0;
my $prev_line;
my $headerflag = 0;

#Scrips runs with all options set if no exclude options are set.
#Exlude options are '.' for changes, '+' for adds and '-' for drops.
my $changed = 1;
my $added   = 1;
my $dropped = 1;

if (($ARGV[0] eq ".")||($ARGV[1] eq ".")||($ARGV[2] eq ".")) {$changed = 0;}
if (($ARGV[0] eq "+")||($ARGV[1] eq "+")||($ARGV[2] eq "+")) {$added = 0;}
if (($ARGV[0] eq "-")||($ARGV[1] eq "-")||($ARGV[2] eq "-")) {$dropped = 0;}

#Open file
open (my $IN,'<mks_diff.txt') || die "Error: $!";
#Extract content
while (<$IN>){
	if ($_=~ /Subproject ch/i) {
		# Just a sub-project change. Used as header line if members have changed.
		$prev_line = substr($_, index($_, "/SW/"));
	  $headerflag = 0;
	}
	elsif ($_=~ /Dropped subproject/i) {
		# Just a sub-project change. Used as header line if members have changed.
		$prev_line = substr($_, index($_, "/SW/"));
	  $headerflag = 0;
	}
		elsif ($_=~ /Added subproject/i) {
		# Just a sub-project change. Used as header line if members have changed.
		$prev_line = substr($_, index($_, "/SW/"));
	  $headerflag = 0;
	}
	else {
		# Not just a sub-project change. Can be a member revision change, a drop or a member add.
  	if (($_=~ /Member revision changed/i)&&($changed == 1)) {
  		# Member revison changed
    	$_ =~ s/Member revision changed/ \t...  Changed/;
  		if ($headerflag == 0) {
	  		$build[$line_count] = "\n".substr($prev_line, 0, index($prev_line, "project.pj"))."  \n";
				print $build[$line_count];
				$headerflag = 1;
	  		++$line_count;
			}
			$build[$line_count] = substr($_, index($_, "..."));
			print $build[$line_count];
			++$line_count;
		}
		elsif (($_=~ /Dropped member/i)&&($dropped == 1)) {
			# Member dropped
    	$_ =~ s/Dropped member/ \t---  Dropped/;
  		if ($headerflag == 0) {
	  		$build[$line_count] = "\n".substr($prev_line, 0, index($prev_line, "project.pj"))."  \n";
				print $build[$line_count];
				$headerflag = 1;
	  		++$line_count;
			}
			$build[$line_count] = substr($_, index($_, "---  Dropped"));
			print $build[$line_count];
			++$line_count;			
		}
		elsif (($_=~ /Added member/i)&&($added == 1)) {
			# Member added
    	$_ =~ s/Added member/ \t+++  Added  /;
  		if ($headerflag == 0) {
	  		$build[$line_count] = "\n".substr($prev_line, 0, index($prev_line, "project.pj"))."  \n";
				print $build[$line_count];
				$headerflag = 1;
	  		++$line_count;
			}
			$build[$line_count] = substr($_, index($_, "+++  Added"));
			print $build[$line_count];
			++$line_count;			
		}
	}
}
close $IN;

#print @build;

#Write new file
open (OUT, ">mks_members_diff.txt") or die $!;
foreach (@build) {
  print OUT "$_";
}
close (OUT);



#Find the length and skip all the reset.
#Write the address to a new array.
#@len = map(substr($_, index($_, "len = 0x")+8, 8,), @sorted);
#foreach (@len) {print "$_ \n";}