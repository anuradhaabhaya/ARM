set terminal png medium
set output "output.png"
set title 'Mesure de performance'
set xlabel 'N'
set xrange [0:1000000]
set ylabel 'Nombre de cycles'
set key on outside 
set tics out
set grid ytics xtics mxtics


plot 'comparaison.data' using 1:2 with lines title 'gcc_O2', \
	     'comparaison.data' using 1:3 with lines title 'gcc_O3', \
	     'comparaison.data' using 1:4 with lines title 'gcc_O3_march', \
	     'comparaison.data' using 1:5 with lines title 'gcc_combinaison_options'
