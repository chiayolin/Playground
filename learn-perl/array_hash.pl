use strict; 
use warnings;

my %people = ( 
  "chiayo " => "lin ",
  "natalie " => "lee ",
  "ryo " => "budiwarman ",
  "hang " => "chan "
);

# convert a hash in to array: 
my @people = %people;
print "@people";

# unlinke an array, the keys of a hash have no
# underlying order. they'll be returned in
# whatever order is more efficient. so, notice 
# the rearranged order but preserved pairs in the
# resulting array. e.g.):
# ryo  budiwarman  chiayo  lin  hang  chan  natalie  lee

print "--------\n";
# you have to use *square brackets* to retrieve a value from
# an array, but you have to use *braces* to retrieve a value 
# from a hash.
my $data = "chiayo";
my @data = (
  "natalie"
);
my %data = (
  "0" => "ll"
);

print $data; # "chiayo"

print $data[0]; # "natalie"
print $data["0"]; # "natalie"

print $data{0}; # "ll"
print $data{"0"}; # "ll"
