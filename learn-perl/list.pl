use strict;
use warnings;

# a list is not a variable. a list is an ephemeral value which can be
# assigned to an array or a hash variable. this is why the syntax for
# declaring array and hash variable is identical. there are many
# situations where the terms "list" and "array" can be used interchan-
# geably, but there are equally many where lists and arrays display
# subtly different and extremely confusing behaviour. 
(
  "print",
  "these",
  "strings",
  "out",
  "for",
  "me"
);

(
  "chiayo" => "lin",
  "natalie" => "lee" 
);

# `=>` (fat comma) is just `,` (comma)
("one", 1, "three", 3, "five", 5);
("one" => 1, "three" => 3, "five" =>);
# the use of `=>` hints that one of these lists is an array declaration
# and the other is a hash declaration. but on theirowen, neither of them
# are declarations of anything. they are just "list"

# also: 
();
# this list can be declare as an empty array or an empty hash and the
# `perl` interpreter clearly has no way of telling either way.
# once tou understand this odd aspect of perl, you will also understand
# why the following fact must be true: *list values cannot be nested.*
# e.g.)
my @array = (
  "apple",
  "bananas",
  (
    "inner",
    "list",
    "several",
    "entries"
  ),
  "orange"
);
# `perl` has no way of knowing whether ("inner", "list", "several", "entries")
# is supposed to be an inner array or an inner hash. therefore, `perl` assumes
# that it is neither and *flattens the list out into a single long list: 
print $array[0];
print $array[1];
print $array[2];
print $array[3];
print $array[4];
print $array[5];
print $array[6];
