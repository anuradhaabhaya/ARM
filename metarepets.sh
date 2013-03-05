#!/bin/bash


metaRepet=30
file=driver

if [ ! -f $file ] # si pas de driver
then
   echo "[ERREUR] Pas de driver, lancez make"

elif [ $# -ne 2 ] # si le nombre d'arguments est different de 2 
then
   echo "[ERREUR] Mauvaise utilisation"
   echo "[HELP]   run <N> <nb_repets>"

else # Sinon, tout va bien, on lance les metarepetitions
	n=$1
	nb_rep=$2
	for i in `seq 1 1 $metaRepet`
	do
		./driver $n $nb_rep
	done
fi
