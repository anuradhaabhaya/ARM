import os

def mediane(L):
    L.sort()
    N = len(L)
    n = N/2.0
    p = int(n)
    if n == p:
        return (float(L[p-1])+float(L[p]))/2.0
    else:
        return float(L[p])

def get_cmd_line(N, nb_reps):
	return "./run.sh " + str(N) + " " + str(nb_reps)
	
def main():
	N = 10
	nb_reps=1000
	
	out = os.popen(get_cmd_line(N, nb_reps),"r").readlines() 
	results = []
	
	for i in range(0, len(out)):
		results.append(out[i].replace('\n',''));

	print mediane(results)

if __name__ == '__main__':
	main()
