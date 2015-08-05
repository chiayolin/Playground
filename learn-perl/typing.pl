use strict;
use warnings;

my $str1 = "4g";
my $str2 = "4h";

print $str1 .  $str2 . "\n";
print $str1 +  $str2 . "\n";
print $str1 eq $str2 . "\n";
print $str1 == $str2 . "\n";

# the classic error:
# both  values evaluate to 0 when used as number
print "yes" == "no" . "\n";
