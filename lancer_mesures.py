import os
import argparse



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
# Construit une ligne de commande a 
# partir de N et nb_reps 
#
def get_cmd_line(N, nb_reps):
	return "./metarepets.sh" + " " + str(N) + " " + str(nb_reps)
	
def main():
	# On recupere les options
	parser = argparse.ArgumentParser()
	parser.add_argument('-o', '--output')
	args = parser.parse_args()

	print args

	# On verifie que le driver a ete compile 
	if not os.path.exists("driver"):
		print "Pas de driver, compilez (make) puis relancez"
		exit()
	N = 10
	nb_reps=1000
	
	out = os.popen(get_cmd_line(N, nb_reps),"r").readlines() 
	results = []
	
	for i in range(0, len(out)):
		results.append(out[i].replace('\n',''));

	print mediane(results)

if __name__ == '__main__':
	main()
