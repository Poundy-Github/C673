#!/bin/perl
use strict;
use Cwd;

package Main;

my @virtFolders;
my @linkFolders;

# This is the replacement list that replaces physical paths to CCS virtual paths.
# This allows to have a clean directory structure in the CCS project tree, which
# is much easier to navigate.
my @pathReplaceList = (
    [ "04_Engineering/03_Workspace/sw/make",                     "make"                      ],
    [ "04_Engineering/04_Build/tools",                           "tools"                     ],
    [ "04_Engineering/04_Build/out",                             "out"                       ]
);

my %additionalIncludes = (
    "arm-m_0"   => [
                        "04_Engineering/03_Workspace/sw/make",
                        "04_Engineering/04_Build/tools/bios/packages",
                        "04_Engineering/04_Build/tools/xdctools/packages",
                   ],
    "arm-m_1"   => [
                        "04_Engineering/03_Workspace/sw/make",
                        "04_Engineering/04_Build/tools/bios/packages",
                        "04_Engineering/04_Build/tools/xdctools/packages",
                   ],
    "arm-a_0"   => [
                        "04_Engineering/03_Workspace/sw/make",
                        "04_Engineering/04_Build/tools/bios/packages",
                        "04_Engineering/04_Build/tools/xdctools/packages",
                   ],
    "dsp_0"     => [
                        "04_Engineering/03_Workspace/sw/make",
                        "04_Engineering/04_Build/tools/bios/packages",
                        "04_Engineering/04_Build/tools/xdctools/packages",
                   ],
    "dsp_1"     => [
                        "04_Engineering/03_Workspace/sw/make",
                        "04_Engineering/04_Build/tools/bios/packages",
                        "04_Engineering/04_Build/tools/xdctools/packages",
                   ],
    "eve_0"     => [
                        "04_Engineering/03_Workspace/sw/make",
                   ],
    "eve_1"     => [
                        "04_Engineering/03_Workspace/sw/make",
                   ],
);

# Root node for CCS project tree
my $rootNode = new ProjectTreeNode('', 2);

sub ApplyReplacementList
{
    my $pathIn = shift;
    
    foreach (@pathReplaceList) {
        my $path = @{$_}[0];
        my $repl = @{$_}[1];

        if ($pathIn =~ s/$path/$repl/i) {
            last;
        }
    }
    return $pathIn;
}

sub ExtractLstBlock
{
    my ($lstFileContents, $block) = @_;
    
    # Extract block from listing file
    if ($lstFileContents =~ /^$block {\r?\n?(.*?)}/ms) {
        # Remove leading and trailing spaces
        my $blockContents = $1;
        $blockContents =~ s/^\s+//gm;
        $blockContents =~ s/\s+$//gm;
        return $blockContents;
    } else {
        die "Could not find block '$block' in scons listing file!";
    }
}

sub GetDirsFromString()
{
    my $text = shift;
    
    # Add directories to array and make them unique
    my @dirs = split(/\r?\n/, $text);
 
    # Replace backslashes by slashes
    for (@dirs) { s/\\/\//g };
    
    # Make paths relative
    for (@dirs) { $_ = MakePathRelative($_); };

    # Make entries unique
    @dirs = sort(keys %{{ map { $_ => 1 } @dirs }});
    
    #print join("\n-> ", @dirs);

    return @dirs;
}

sub GetDirsFromLst()
{
    my ($lstFileContents, $blockName) = @_;

    # Get whole block containing directories from input file
    my $srcDirList = &ExtractLstBlock($lstFileContents, $blockName);
    
    # Extract and return individual directories
    return &GetDirsFromString($srcDirList);
}

sub MakePathRelative()
{
    my $path = shift;
    $path =~ s/\\/\//g; # replace '\' by '/'
    my $cwd = Cwd::cwd();
    $path =~ s/^$cwd\///i;
    return $path;
}

sub PatchFile()
{
    my ($filename, $search, $replace) = @_;
    
    # Read XML file contents
    open(XMLFILE, "<$filename") || die "Could not open file '$filename' for reading!";
    my @fileContentsLines = <XMLFILE>;
    close(XMLFILE);
    my $fileContents = join("", @fileContentsLines);
    my $fileContentsOrig = $fileContents;
    
    # Now replace XML node contents
    if (!($fileContents =~ s/$search/"$1".$replace."$2"/geis)) {
        die "Error replacing '$search' in file '$filename' !";
    }
    
    # Write back to original file, but only when there are changes
    if ($fileContents ne $fileContentsOrig) {
        # Remove read-only flag and write contents to file
        chmod 0777, $filename;
        open(XMLFILE, ">$filename") || die "Could not open file '$filename' for writing!";
        print XMLFILE $fileContents;
        close(XMLFILE);
        
        # Signal caller that something changed
        return 1;
    } else {
        return 0;
    }
}

sub dieShowUsage
{
    my $text = shift;
    print STDERR $text . "\n";
    print STDERR "USAGE: $0 <core_name> <projects>\n";
    exit(1);
}

sub main()
{
    our @virtFolders;
    our @linkFolders;
    
    # Flag that indicates whether we changed some file
    my $fileChanged = 0;
    
    # Check input arguments
    my $core     = $ARGV[0];
    my @projects = split(/,/, $ARGV[1]);
    $core ne "" || dieShowUsage "Please pass core names!";
    @projects > 0 || dieShowUsage "Please pass project names!";
    
    # Setup common directories
    my $ccsProjectPath = "04_Engineering/03_Workspace/ccs/cores/$core";
    print "Patching CCS project $ccsProjectPath ... ";

    # Read all the scons generated listing files from build folder
    my @dirs;
    foreach (@projects) {
        # Construct path
        my $project = $_;
        my $projectLc = lc($_);
        my $inFile = "04_Engineering/04_Build/out/$projectLc/release_$core/$core.lst";
    
        # Read file listing file
        open(FILE, "<$inFile") || die "Could not open file '$inFile'!";
        my @lines = <FILE>;
        my $fileContents = join("", @lines);
        close(FILE);
        
        # Add all source directories of this project to project tree
        my @dirs = &GetDirsFromLst($fileContents, "source_directories");
        foreach (@dirs) {
            $rootNode->addDir($_, $project);
        }

        # Add all files to project tree
        my @files;
        foreach (("release", "debug")) {
            my $config = $_;
            push (@files, "04_Engineering/04_Build/out/$projectLc/${config}_$core/$core.out");
            push (@files, "04_Engineering/04_Build/out/$projectLc/${config}_$core/$core.map");
        }
        foreach (@files) {
            $rootNode->addFile($_, $project);
        }
        
        # Get include paths from listing file
        my @includes = &GetDirsFromLst($fileContents, "include_directories");
        
        # Add also includes from core specific list
        my $coreIncludes = $additionalIncludes{$core};
        push (@includes, @$coreIncludes);
        
        # Now generate XML code for includes and add them to eclipse project structure
        my $includesXml;
        foreach (@includes) {
            if (index($_,"c:/tools/"))
            {
                $includesXml .= '									<listOptionValue builtIn="false" value="../../../../../../'.$_."\"/>\n";
            }
            else
            {
                $includesXml .= '									<listOptionValue builtIn="false" value="'.$_."\"/>\n";
            }

            # Add include path also to source folders, as we want to have them visible
            # in the CCS project explorer too
            $rootNode->addDir($_, $project);
        }
        
        # Patch XML file with include paths, respecting the configuration
        my $pattern = '(<configuration [^>]*?name="'.$project.'".*?>.*?<option [^>]*?valueType="includePath".*?>\r?\n?).*?(								<\/option>)';
        $fileChanged |= &PatchFile($ccsProjectPath."/.cproject", $pattern, $includesXml);
        
        # Get #defines from listing file
        my $definesBlock = &ExtractLstBlock($fileContents, "defines");
        my @defines = split(/\r?\n/, $definesBlock);
        my $definesXml;
        foreach (@defines) {
            $definesXml .= '									<listOptionValue builtIn="false" value="'.$_.'"/>' . "\n";
        }
        
        # Patch defines into eclipse project file
        $pattern = '(<configuration [^>]*?name="'.$project.'".*?>.*?<option [^>]*?valueType="definedSymbols".*?>\r?\n?).*?(								<\/option>)';
        $fileChanged |= &PatchFile($ccsProjectPath."/.cproject", $pattern, $definesXml);
    }
    
    # Generate CCS XML code for linked resources and patch CCS project XML file
    {
        my $newResourceList = &GetCcsLinkedRessources($rootNode);
        my $pattern = '(<linkedResources>\r?\n?).*?([ \t]*?<\/linkedResources>)';
        $fileChanged |= &PatchFile($ccsProjectPath."/.project", $pattern, $newResourceList);
    }
    
    # Now iterate a second time through the projects and check which resources are *not*
    # assigned to a particular project. Use this to generate the CCS resource exclusion lists:
    foreach (@projects) {
        my $project = $_;
        my $excludes = &FindExcludes($rootNode, $project);
        
        # Debug output:
        #print "\nExcludes for $project:\n";
        #foreach (@$excludes) { print "  $_\n"; }
        
        # Generate exclusion string for eclipse project
        my $excludeText = join("|", @$excludes);
        #print "EXCLUDE: $excludeText\n";
        
        # Patch CCS file
        my $pattern = '(<configuration [^>]*?name="'.$project.'".*?>.*?<sourceEntries>.*?<entry [^>]*?excluding=").*?(".*?\/>.*?<\/sourceEntries>)';
        if (scalar(@$excludes) >= 1) {  # avoids errors when there are is no exclusion list
            $fileChanged |= &PatchFile($ccsProjectPath."/.cproject", $pattern, $excludeText);
        }
    }
    
    # Did we change anything?
    if ($fileChanged) {
        print "done, patched.\n";
    } else {
        print "done, nothing changed.\n";
    }
}

sub FindExcludes
{
    my ($node, $project) = @_;
    my $excludes = [];
    
    # Recursively iterate through list of children and collect paths that are
    # not part of the selected project
    my $childsHref = $node->{_childs};
    foreach (keys %$childsHref) {
        my $child = $childsHref->{$_};
        if ($child->hasProject($project)) {
            # Child is part of this project: Recursively check subnodes
            my $childExcludes = &FindExcludes($child, $project);
            # Merge results into our list
            push (@$excludes, @$childExcludes);
        } else {
            # Child is *not* part of this project: Add path to exclude list
            push (@$excludes, $child->getProjectPath());
        }
    };
    
    return $excludes;
}

sub GetVirtDirs
{
    my $node = shift;
    my $childs = $node->getChilds();
    my $virtFolders = [];
    foreach (@$childs) {
        # If this is a virtual folder node, add it to the array
        if ($_->isVirtual()) {
            push(@$virtFolders, $_->getProjectPath());
            #print "Adding ".$_->getProjectPath()."\n";
        }
        
        # Add virtual folders for all child nodes
        my $virtFoldersChilds = &GetVirtDirs($_);
        push(@$virtFolders, @$virtFoldersChilds);
    }
    return $virtFolders;
}

sub GetCcsLinkedRessources
{
    my $node = shift;
    my $childs = $node->getChilds();
    my $out;
    
    foreach (@$childs) {
        # Get project path and node type
        my $prjPath = $_->getProjectPath();
        my $type = $_->{_type};
        
        # If this is a virtual folder node, add it as virtual resource
        if ($_->isVirtual()) {
            if (index($prjPath,"c:"))
            {
            # Do not add a virtual resource if it is on local drive c:
            $out .=
                  "		<link>\n"
                . "			<name>$prjPath</name>\n"
                . "			<type>2</type>\n"
                . "			<locationURI>virtual:/virtual</locationURI>\n"
                . "		</link>\n";
            # print "Adding ".$_->getProjectPath()."\n";
            }
        } else {
            # Real path: Add as linked resource
            my $realPath = $_->getPhysPath();
            if (index($realPath,"c:/tools"))
            {
            # Real path is inside sandbox
            $out .=
                  "		<link>\n"
                . "			<name>$prjPath</name>\n"
                . "			<type>$type</type>\n"
                . "			<location>PARENT-5-PROJECT_LOC/$realPath</location>\n"
                . "		</link>\n";
            }
            else
            {
            # Real path is on local drive c:
            my $cprjPath = substr($realPath,3);
            $out .=
                  "		<link>\n"
                . "			<name>$cprjPath</name>\n"
                . "			<type>$type</type>\n"
                . "			<location>$realPath</location>\n"
                . "		</link>\n";
            }
        }
        
        # Add resources of all child nodes
        $out .= &GetCcsLinkedRessources($_);
    }
    return $out;
}

&main();
#$rootNode->printTree();



###############################################################################################
# Class: ProjectTreeNode
###############################################################################################
package ProjectTreeNode;

# Adds directory to project tree, including applying the path replacement list
sub addDir
{
    my $self = shift;
    $self->addResource(2, @_);
}

# Adds a file link to this node
sub addFile
{
    my $self = shift;
    $self->addResource(1, @_);
}

# Adds directory to project tree, including applying the path replacement list
#
#  type 1 ==> FILE
#  type 2 ==> DIRECTORY
sub addResource
{
    my ($self, $type, $pathOrig, $project) = @_;
    
    # If path is absolute, make it relative
    my $pathRel = &Main::MakePathRelative($pathOrig);
    
    # Apply path replacement list to generate a virtual path
    my $pathVirt = &Main::ApplyReplacementList($pathRel);
    
    # Split virtual path into single segments
    my @dirs = split(/\//, $pathVirt);
    my $dir = $dirs[-1];

    # Now traverse through the tree, adding all intermediate missing nodes
    my $curNode = $self;
    for (my $i=0; $i<@dirs - 1; $i++) {
        my $dirPart = $dirs[$i];
        
        # Check whether child node already exists. Create it if it doesn't exist:
        if (!defined($curNode->{_childs}->{$dirPart}))
        {
            #print "Creating $dirPart\n";
            my $newNode = $curNode->addNode(new ProjectTreeNode($dirPart, $type));
        }
        
        # Select child node to be processed next
        $curNode = $curNode->{_childs}->{$dirPart};
        $curNode->addProject($project);
    }
    
    # Add physical directory to last node, if it does not exist yet
    if (!defined($curNode->{_childs}->{$dir})) {
        my $newNode = $curNode->addNode(new ProjectTreeNode($dir, $type, $pathRel));
        #print "Created " . $curNode->{_childs}->{$dir}->getProjectPath() ."\n";
    }
    $curNode->{_childs}->{$dir}->addProject($project);
}

# Adds a child node to this node
sub addNode
{
    my ($self, $node) = @_;
    my $name = $node->{_name};
    $self->{_childs}->{$name} = $node;
    $node->{_parent} = $self;
    return $node;
}

# Prints the whole tree on the screen, including virtual to real path mappings
sub printTree
{
    my ($self, $indentDepth) = @_;
    my $childsHref = $self->{_childs};
    
    if (keys %$childsHref eq 0) {
        my $projects = $self->{_projects};
        print $self->getProjectPath() . " --> " . $self->{_realPath} . join("|", @$projects) . "\n";
    } else {
        foreach (sort keys %$childsHref) {
            $childsHref->{$_}->printTree();
        }
    }
}

# Returns the virtual project path of this node
sub getProjectPath
{
    my $self = shift;
    my $path = $self->{_name};
    if (defined($self->{_parent})) {
        $path = $self->{_parent}->getProjectPath() . '/'. $path;
    }
    
    # Strip leading '/' from path and return it
    $path =~ s/^\///;
    return $path;
}

# Returns the physical path of this node, if it's not a virtual node
sub getPhysPath
{
    my $self = shift;
    return $self->{_realPath};
}

# Returns all child nodes of this node
sub getChilds
{
    my $self = shift;
    my $childs = [];
    my $childsHref = $self->{_childs};
    foreach (sort keys %$childsHref) {
        push (@$childs, $childsHref->{$_});
    }
    return $childs;
}

# Returns '1' if this node is eclipse virtual project node
sub isVirtual
{
    my $self = shift;
    if ($self->{_realPath} eq "") {
        return 1;
    } else {
        return 0;
    }
}

# Marks this node as used by a particular project
sub addProject
{
    my ($self, $project) = @_;
    my $prjAref = $self->{_projects};
    push(@$prjAref, $project) if (!$self->hasProject($project));
}

# Returns '1' in case this node has a specific project associated
sub hasProject
{
    my ($self, $project) = @_;
    my $prjAref = $self->{_projects};
    if (grep(/^$project$/, @$prjAref)) {
        return 1;
    } else {
        return 0;
    }
}

# Constructor
sub new
{
    my $class = shift;
    my $self = {
        _name       => shift,
        _type       => shift,
        _realPath   => shift,
        _parent     => undef,
        _childs     => {},
        _projects   => []
    };
    
    bless $self, $class;
    return $self;
}

1;
