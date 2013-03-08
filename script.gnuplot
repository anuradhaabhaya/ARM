set terminal png medium
set output "output.png"
set title 'Mesure de performance'
set xlabel 'N'
set ylabel 'Nombre de cycles'
set nokey
plot 'test.data' using 2:3 with linespoints title 'Mediane', \
	'test.data' using 2:4 with linespoints title 'Minimum'
