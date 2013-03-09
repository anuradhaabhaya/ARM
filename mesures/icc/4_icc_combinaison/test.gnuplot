set terminal png medium
set output 'test.png'
set title 'Mesure de performance'
set xlabel 'N'
set ylabel 'Nombre de cycles'
set key on outside
set grid ytics xtics mxtics
plot 'test.data'using 1:3 with linespoints title 'Mediane', 	'test.data'using 1:4 with linespoints title 'Minimum'
