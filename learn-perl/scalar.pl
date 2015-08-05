# perl variables come in three types" scalars, arrays, and hashes.
# each type has its own sigil: $, @, and % respectively.
# variable are declared using my, and remain in scope untill the 
# end of the enclosing block or file.

use strict;
use warnings;

my $undef = undef;
print $undef;

# implicit undef
my $undef2;
print $undef2;

my $num = 4040.5;
print "$num\n";

my $string = "world";
print "$string\n";

# string concatenation using the . 
print "hello, "."$string\n"

# perl has no boolean data type. a scalar in a if statement
# evaluates to boolean "false" if and only if it is one of
# the following: 
# o   undef
# o   number 0
# o   string ""
# o   string "0"

