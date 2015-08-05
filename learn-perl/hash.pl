use strict;
use warnings;

# the double arrow symbol => is called a "fat comma",
# because it is just a synonym for the comma separator.
# a hash is declared using a list with an even number of
# elements, when the even-numbered elements (0, 2, ..)
# are all taken as strings. 
my %scientists = (
  "newton"   => "isaac",
  "einstein" => "albert",
  "darwin"   => "charles" 
);

# once again, remenber to use a dollar sign to access a 
# value from a hash, becasue the value being retieved is
# not a hash but a scalar:
print $scientists{"newton"} . "\n";
print $scientists{"einstein"} . "\n";
print $scientists{"darwin"} . "\n";
print $scientists{"chiayo"};
