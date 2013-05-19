#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "cycle.h"
#include "kernel.h"

void init(double tab[], int N)
{
	int i;
	
	for(i=0; i<N; i=i+1)
	{
		tab[i] = (double)rand() / RAND_MAX;
	}
}

void verifier_resultats(int N, double a[], double b[])
{
	int i;
	
	for(i=0; i<N;i++)
	{	
		assert(a[i] == b[i]);
	}
}

int main(int argc, char **argv)
{
	int N, nb_repets, i; 
	ticks t1, t2;
	double cycles = 0;
	
	double *a, *b, *c, *standard;
	void *pa, *pb, *pc, *ps;
	
	if(argc != 3)
	{
		printf("usage: ./kernel <N> <nb_repets>\n");
		exit(1);
	}
	
	/* Recuperation arguments */
	N = atoi(argv[1]);
	nb_repets = atoi(argv[2]);
	
	/* Initialisation graine */
	srand(0);
	
	/* Initialisation tableaux */
	a = malloc(N*sizeof(double)); 
	b = malloc(N*sizeof(double));
	c = malloc(N*sizeof(double));
	standard = malloc(N*sizeof(double));
	
	/*
	posix_memalign(&pa, 16, N*sizeof(double));
	posix_memalign(&pb, 16, N*sizeof(double));
	posix_memalign(&pc, 16, N*sizeof(double));
	posix_memalign(&ps, 16, N*sizeof(double));
	
	a = pa;
	b = pb;
	c = pc;
	standard = ps;
	*/

	if(a == NULL || b == NULL || c == NULL || standard == NULL)
	{
		printf("Erreur malloc\n");
		
		if(a != NULL)
			free(a);
		if(b != NULL)
			free(b);
		if(c != NULL)
			free(c);
		if(standard != NULL)
			free(standard);
		
		exit(1);
	}
	
	init(a, N);
	init(b, N);
	
	/* Tour de chauffe */
	/* ATTENTION : DOIT ETRE LE MEME KERNEL QUE DANS LA BOUCLE !!! */
	kernel0(N, a, b, c);
	
	/* Lancement du kernel */
	
	t1 = getticks();
	
	for(i = 0; i < nb_repets; i=i+1)
	{
		kernel0(N, a, b, c);
	}
	
	t2 = getticks();
	cycles = (double) elapsed(t2,t1) / ((double)nb_repets*N);

	/* Vérification */
	kernel0(N, a, b, standard);	
	verifier_resultats(N, standard, c);
	
	/* Affichage du résultat */	
	
	printf("%.2f\n", cycles);
	
	/* Liberation memoire */
	free(a);
	free(b);
	free(c);
	free(standard);
	
	return 0;
}
