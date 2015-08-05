use strict;
use warnings;

my @array = (
  "print",
  "these",
  "strings",
  "out",
  "for",
  "me", # trailing comma is okay
);

# use a dollar sign to access a value from an array,
# because the value being retrieved is not an array but a scalar:
print $array[0];
print $array[1];
print $array[2];
print $array[3];
print $array[4];
print $array[5] . "\n";
print $array[6]; # returns undef, print "" and raises a warning.

# use nagative indices to retrieve value backwards.
print $array[-1];
print $array[-2];
print $array[-3];
print $array[-5];
print $array[-6] . "\n";
print $array[-7];

# there is no collision between a scalar $var and an array @var.
# They may, however, be reader confusion, so avoid this. 
