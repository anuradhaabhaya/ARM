import os
import argparse
import csv


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
	csv_writer.writerow([N, mediane(liste_resultats), min(liste_resultats)])

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
	csv_writer = csv.writer(open(args.csv_file, 'w')) 	

	# En-tete du fichier csv
	csv_writer.writerow(['N', 'Mediane', 'Min' ])
	
	
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
	
	# [1000000; 9000000] par pas de 1000000
	liste_N += range(1000000, 10000000, 1000000) 
	
	print "\n-------------------------------------------------------"
	print "Lancement des mesures sur les valeurs de N suivantes : "
	print liste_N
	print "-------------------------------------------------------\n\n"
	

	for N in liste_N:
		print "N=" + str(N) + " ..."
		nb_reps = 10
		stocker_resultats_csv(N, lancer_metareps(N, nb_reps), csv_writer)

	

if __name__ == '__main__':
	main()
