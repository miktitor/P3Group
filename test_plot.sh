#!/bin/bash

gnuplot << EOF
set term postscript
set output "test.eps"
set dgrid3d
set parametric
set contour base
set view 0,0,1
unset surface
set cntrparam levels 20
splot "the_datafile.dat" using 1:2:3 with line notitle
EOF

