set terminal png medium
set output 'combinaison_options.png'
set title 'Mesure de performance'
set xlabel 'N'
set ylabel 'Nombre de cycles'
set key on outside
set grid ytics xtics mxtics
plot 'combinaison_options.data'using 1:3 with linespoints title 'Mediane', 	'combinaison_options.data'using 1:4 with linespoints title 'Minimum'
