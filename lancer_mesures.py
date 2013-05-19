import os
import argparse
import csv
from math import log

class mesure:
	def __init__(self, N, nb_repets):
		self.N = N
		self.nb_repets = nb_repets

# variable globale
liste_N = []
liste_N.append(mesure(50,       3500000))
liste_N.append(mesure(100,       1500000))
liste_N.append(mesure(200,         800000))
liste_N.append(mesure(300,         600000))
liste_N.append(mesure(400,         500000))
liste_N.append(mesure(500,         400000))
liste_N.append(mesure(600,          350000))
liste_N.append(mesure(700,          300000))
liste_N.append(mesure(800,          250000))
liste_N.append(mesure(900,          200000))
liste_N.append(mesure(1000,         200000))
liste_N.append(mesure(1100,          200000))
liste_N.append(mesure(1200,          150000))
liste_N.append(mesure(1300,          150000))
liste_N.append(mesure(1400,           150000))
liste_N.append(mesure(1500,           150000))
liste_N.append(mesure(1600,           150000))
liste_N.append(mesure(1700,           150000))
liste_N.append(mesure(1800,           150000))
liste_N.append(mesure(2000,           120000))
liste_N.append(mesure(2500,           100000))
liste_N.append(mesure(3000,            70000))
liste_N.append(mesure(4000,             50000))
liste_N.append(mesure(5000,             30000))
liste_N.append(mesure(6000,             30000))
liste_N.append(mesure(7000,             30000))
liste_N.append(mesure(8000,             30000))
liste_N.append(mesure(9000,             20000))
liste_N.append(mesure(10000,            20000))
liste_N.append(mesure(10500,             15000))
liste_N.append(mesure(11000,             15000))
liste_N.append(mesure(11500,             15000))
liste_N.append(mesure(12000,             15000))
liste_N.append(mesure(13000,             12000))
liste_N.append(mesure(14000,             11000))
liste_N.append(mesure(15000,              10000))
liste_N.append(mesure(16000,              10000))
liste_N.append(mesure(17000,              10000))
liste_N.append(mesure(18000,              10000))
liste_N.append(mesure(19000,                8000))
liste_N.append(mesure(20000,                8000))
liste_N.append(mesure(30000,                7000))
liste_N.append(mesure(40000,                3000))
liste_N.append(mesure(50000,                3000))
liste_N.append(mesure(75000,                2000))
liste_N.append(mesure(100000,               1000))
liste_N.append(mesure(110000,               1000))
liste_N.append(mesure(120000,               1000))
liste_N.append(mesure(130000,               1000))
liste_N.append(mesure(140000,               1000))
liste_N.append(mesure(150000,               1000))
liste_N.append(mesure(175000,               1000))
liste_N.append(mesure(200000,               1000))
liste_N.append(mesure(500000,               100))
liste_N.append(mesure(1000000,               10))


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
	med = mediane(liste_resultats)
	csv_writer.writerow([N, float(N*3*8)/1024, med])
	return med

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
	f = open(args.csv_file, 'w')
	
	# En-tete du fichier csv
	csv_writer.writerow(['N', 'Taille (Ko)', 'Nombre de cycles par instruction', ])
	
	
	#####################
	# Debut des mesures #
	#####################

	# On concatene dans liste_N, toutes les valeurs 
	# qui seront prises par N


	print "\n-------------------------------------------------------"
	print "Lancement des mesures sur les valeurs de N suivantes : "
	print "-------------------------------------------------------\n\n"
	
	# Creation du fichier contenant les resultats
	for m in liste_N:
		res = stocker_resultats_csv(m.N, lancer_metareps(m.N, m.nb_repets), csv_writer)
		print "[INFO] N=" + str(m.N) + "   mediane :" + str(res)		
		
	
	
	

if __name__ == '__main__':
	main()
