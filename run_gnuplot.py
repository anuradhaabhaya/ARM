import os
import argparse
import csv
from math import log

##
# Retourne la mediane de la liste L 
#
def mediane(L):
    L.sort()
    N = len(L)
    n = N/2.0
    p = int(n)
    if n == p:
        return (float(L[p-1])+float(L[p]))/2.0
    else:
        return float(L[p])

##
# Retourne la plus petite valeur de la serie
#
def min(L):
	L.sort()
	# selon la version de libre office, on remplace le .
	return float(L[0])


##
# Construit une ligne de commande a 
# partir de N et nb_reps 
#
def get_cmd_line(N, nb_reps):
	return "./metarepets.sh" + " " + str(N) + " " + str(nb_reps)


##
# Lancer une mesure avec N et nb_repets
# Retourne une liste des resultats (tout ce qu'affiche metarepets)
#
def lancer_metareps(N, nb_reps):
	out = os.popen(get_cmd_line(N, nb_reps),"r").readlines() 
	results = []
	
	for i in range(0, len(out)):
		results.append(out[i].replace('\n',''));

	return results


##
# Ajoute les resultats dans le fichier csv
#
def stocker_resultats_csv(N, liste_resultats, csv_writer):
	csv_writer.writerow([N, float(N*3*8)/1024, mediane(liste_resultats), min(liste_resultats)])


def stocker_resultats(N, liste_resultats):
	return str(N) + ' ' + str(float(N*3*8)/1024) + ' ' + \
		str(mediane(liste_resultats)) + ' ' + str(min(liste_resultats)) + '\n'


##
# Retourne un nombre de repetition pour N approximatif 
# pour la mesure
#
def approximation_nb_reps(N):
	#return pow(10, log(100000000, 10)-int(log(N, 10)))
	return pow(10, log(100000000, 10)-int(log(N, 10)))

##
# Fonction main
#	
def main():
	# description du script
	desc = "Lancement de mesures et generation \
			d'un fichier .csv contenant les resultats"
	
	# On recupere les options
	parser = argparse.ArgumentParser(description=desc)
	parser.add_argument('-o', action="store", dest="csv_file",  
						help='Nom du fichier qui contiendra les resultats',  
						required=True)
	args = parser.parse_args()

	# On verifie que le driver a ete compile 
	if not os.path.exists("driver"):
		print "Pas de driver, compilez (make) puis relancez"
		exit()

	# Ouverture du fichier csv en mode ecrite (ecrase si existe deja)
	#csv_writer = csv.writer(open(args.csv_file, 'w')) 	
	f = open(args.csv_file + ".data", 'w')
	
	# En-tete du fichier csv
	#csv_writer.writerow(['N', 'Taille (Mo)', 'Mediane', 'Min' ])
	
	
	#####################
	# Debut des mesures #
	#####################

	# On concatene dans liste_N, toutes les valeurs 
	# qui seront prises par N

	# [10; 90] par pas de 10
	liste_N = range(10, 100, 10) 

	# [100; 900] par pas de 100
	liste_N += range(100, 1000, 100) 
	
	# [1000; 9000] par pas de 1000
	liste_N += range(1000, 10000, 1000)
	
	# [10000; 90000] par pas de 10000
	liste_N += range(10000, 100000, 10000) 
	
	# [100000; 900000] par pas de 100000
	liste_N += range(100000, 1000000, 100000) 
	
	# [1000000; 10000000] par pas de 1000000
	liste_N += range(1000000, 11000000, 1000000) 
	
	print "\n-------------------------------------------------------"
	print "Lancement des mesures sur les valeurs de N suivantes : "
	print liste_N
	print "-------------------------------------------------------\n\n"
	
	# Creation du fichier contenant les resultats
	for N in liste_N:
		nb_reps = approximation_nb_reps(N)
		out = stocker_resultats(N, lancer_metareps(N, nb_reps))
		print out
		f.write(out)
	f.close()
	
	# Creation du graphe
	
	datafile = "'" + args.csv_file + ".data'"
	print datafile
	
	
	f = os.popen("/usr/bin/gnuplot", "w")
	f.write("set terminal png medium\n")
	f.write("set output '" + args.csv_file + ".png'\n")
	f.write("set title 'Mesure de performance'\n")
	f.write("set xlabel 'N'\n")
	f.write("set ylabel 'Nombre de cycles'\n")
	f.write("set nokey\n")
	f.write("plot " + datafile + "using 1:3 with linespoints title 'Mediane', \
	" +  datafile + "using 1:4 with linespoints title 'Minimum'\n")
	f.close()

if __name__ == '__main__':
	main()
