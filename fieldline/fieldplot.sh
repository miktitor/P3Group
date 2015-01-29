#!/bin/bash

gnuplot << EOF
set term postscript
set output "test2.eps"
set contour base
set view map
#set view 0,0,1
unset surface
set title ""
 set cntrparam levels 200
plot "field.dat" using 2:1:3:4 with vectors notitle

EOF

