#!/bin/bash

gnuplot << EOF
set term postscript
set output "test.eps"
# set dgrid3d
# set parametric
 set contour base
 set view map
# set view 0,0,1
unset surface
set title ""
 set cntrparam levels 200
splot "the_datafile.dat" using 2:1:3 with lines notitle	# line for contour plot
EOF

