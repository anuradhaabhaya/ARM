set terminal png medium
set output 'icc_O3_xHost.png'
set title 'Mesure de performance'
set xlabel 'N'
set ylabel 'Nombre de cycles'
set key on outside
set grid ytics xtics mxtics
plot 'icc_O3_xHost.data'using 1:3 with linespoints title 'Mediane', 	'icc_O3_xHost.data'using 1:4 with linespoints title 'Minimum'
