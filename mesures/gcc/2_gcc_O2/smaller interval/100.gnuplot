set terminal png medium
set output 'driver.png'
set title 'Mesure de performance'
set xlabel 'N'
set ylabel 'Nombre de cycles'
set key on outside
set grid ytics xtics mxtics
plot 'driver.data'using 1:3 with linespoints title 'Mediane', 	'driver.data'using 1:4 with linespoints title 'Minimum'
