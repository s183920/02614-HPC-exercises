#!/bin/bash

awk '{print $1, $2}' wave.dat > plot.dat

gnuplot <<- EOF
set terminal eps
set output 'plot.eps'
set title 'Waveform'
set xlabel 'Time (s)'
plot 'plot.dat' using 1:2 with lines
EOF



