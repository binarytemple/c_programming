#!/usr/bin/perl
use strict;
use warnings;
use area;

my $area_of_cir = area::area_of_circle(5);
my $area_of_squ = area::area_of_square(5);
print "Area of Circle: $area_of_cir\n";
print "Area of Square: $area_of_squ\n";
print "$area::pi\n";
