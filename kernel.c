#include "kernel.h"
#include <emmintrin.h>





/**
 * Utilisation des intrinsics de "non temporal store" (NTS)
 * void _mm_stream_pd(double * p, __m128d b)
 * _mm_store_sd ?
 * __m128d _mm_set1_pd(double w)
 * __m128d _mm_load1_pd( double const * dp)
 */
void kernelNTS(int n, double a[n], double b[n], double c[n])
{
	int i;
	int k = n/2;
	int step = 2;
	__m128d aVal, bVal, two;
	two = _mm_set_pd(2.0, 2.0);
	
	for(i=0; i< k - (k%step) ; i+=step)
	{		
		aVal = _mm_load_pd( a+i );
		bVal = _mm_load_pd( b+i );
		_mm_store_pd( c+i, _mm_mul_pd(two , _mm_mul_pd(aVal, bVal) ) );
	}
	
	//Le restant
	for( ; i < k; i++)
	{
		c[i] = 2 * (a[i] * b[i]) ;	
	}
	//i=k
	for( ; i < k + step -(k%step); i++ )
	{
		c[i] = 2 * (a[i] + b[i]) ;	
	}

	for( ; i<n - (n%step) ; i+=step)
	{
		aVal = _mm_load_pd( a+i );
		bVal = _mm_load_pd( b+i );
		_mm_store_pd( c+i,  _mm_mul_pd(two , _mm_add_pd(aVal, bVal) ) ) ;
	}
	
	for( ; i < n; i++)
	{
		c[i] = 2 * (a[i] + b[i]) ;	
	}
	
	c[0] = a[0] * b[0];
}

void kernel8(int n, double a[n], double b[n], double c[n])
{
	int i;
	int k = n/2;
	int step = 4; 
	
	for(i=0; i< k - (k%step) ; i+=step)
	{		
		c[i+0] = 2 * (a[i+0] * b[i+0]) ;
		c[i+1] = 2 * (a[i+1] * b[i+1]) ;	
		c[i+2] = 2 * (a[i+2] * b[i+2]) ;	
		c[i+3] = 2 * (a[i+3] * b[i+3]) ;	
	}
	
	//Le restant
	for( ; i < k; i++)
	{
		c[i] = 2 * (a[i] * b[i]) ;	
	}
	//i=k

	for( ; i < k + step -(k%step); i++ )
	{
		c[i] = 2 * (a[i] + b[i]) ;	
	}

	for( ; i<n - (n%step) ; i+=step)
	{
		c[i+0] = 2 * (a[i+0] + b[i+0]) ;
		c[i+1] = 2 * (a[i+1] + b[i+1]) ;	
		c[i+2] = 2 * (a[i+2] + b[i+2]) ;	
		c[i+3] = 2 * (a[i+3] + b[i+3]) ;	

	}
	
	for( ; i < n; i++)
	{
		c[i] = 2 * (a[i] + b[i]) ;	
	}
	
	c[0] = a[0] * b[0]; // On le fait ici, quitte à faire une itération en plus
}


//Load = bottle neck !
void kernel7(int n, double a[n], double b[n], double c[n])
{
	int i;
	int k = n/2;
	int step = 64/8; //64 = cache line L3  8 = sizeof double

	
	for(i=0; i< k - (k%step) ; i+=step)
	{		
		c[i+0] = 2 * (a[i+0] * b[i+0]) ;
		c[i+1] = 2 * (a[i+1] * b[i+1]) ;	
		c[i+2] = 2 * (a[i+2] * b[i+2]) ;	
		c[i+3] = 2 * (a[i+3] * b[i+3]) ;	
		c[i+4] = 2 * (a[i+4] * b[i+4]) ;	
		c[i+5] = 2 * (a[i+5] * b[i+5]) ;	
		c[i+6] = 2 * (a[i+6] * b[i+6]) ;	
		c[i+7] = 2 * (a[i+7] * b[i+7]) ;	
	}
	
	//Le restant
	for( ; i < k; i++)
	{
		c[i] = 2 * (a[i] * b[i]) ;	
	}
	//i=k

	for( ; i < k + step -(k%step); i++ )
	{
		c[i] = 2 * (a[i] + b[i]) ;	
	}

	for( ; i<n - (n%step) ; i+=step)
	{
		c[i+0] = 2 * (a[i+0] + b[i+0]) ;
		c[i+1] = 2 * (a[i+1] + b[i+1]) ;	
		c[i+2] = 2 * (a[i+2] + b[i+2]) ;	
		c[i+3] = 2 * (a[i+3] + b[i+3]) ;	
		c[i+4] = 2 * (a[i+4] + b[i+4]) ;	
		c[i+5] = 2 * (a[i+5] + b[i+5]) ;	
		c[i+6] = 2 * (a[i+6] + b[i+6]) ;	
		c[i+7] = 2 * (a[i+7] + b[i+7]) ;
	}
	
	for( ; i < n; i++)
	{
		c[i] = 2 * (a[i] + b[i]) ;	
	}
	
	c[0] = a[0] * b[0]; // On le fait ici, quitte à faire une itération en plus
}

void kernel_omp(int n, double a[n], double b[n], double c[n])
{
	int i;
	int k = n/2;

	#pragma omp parallel for	
	for(i=0; i<k ; i++)
	{		
		c[i] = 2 * (a[i] * b[i]) ;
	}

	#pragma omp parallel for
	for(i=k; i<n; i++)
	{
		c[i] = 2*(a[i] + b[i]);
	}

	c[0] = a[0] * b[0];
}

void kernel6(int n, double a[n], double b[n], double c[n])
{
	int i;

	#pragma vector aligned
	#pragma ivdep
	for(i=0; i<n/2 ; i++)
	{		
		c[i] = (a[i] * b[i]) + (a[i] * b[i]) ;	
	}

	#pragma vector aligned
	#pragma ivdep
	for(i=n/2; i<n; i++)
	{
		c[i] = 2*(a[i] + b[i]);
	}
	
	
	c[0] = a[0] * b[0];
}



void kernel5(int n, double a[n], double b[n], double c[n])
{
	int i;
	int k = n/2;

	#pragma vector aligned
	for(i=0; i<k ; i++)
	{		
		c[i] = 2 * (a[i] * b[i]) ;	
	}

	#pragma vector aligned
	for(i=k; i<n; i++)
	{
		c[i] = 2*(a[i] + b[i]);
	}
	
	
	c[0] = a[0] * b[0];
	
}

/**
 * Utilisation des restrict, pour indiquer au compilateur (gcc) la proximité spatiale des
 * accés au pointeur. Cela offre un gain de perfomance, petit, mais présent.
 */
void kernel4(int n, double *__restrict__ a, double *__restrict__ b, double *__restrict__ c)
{
	int i;
	int k = n/2;

	for(i=0; i<k ; i++)
	{		
		c[i] = 2 * (a[i] * b[i]) ;	
	}

	for(i=k; i<n; i++)
	{
		c[i] = 2*(a[i] + b[i]);
	}
	
	c[0] = a[0] * b[0];	
}

void kernel3(int n, double a[n], double b[n], double c[n])
{
	int i;
	int k = n/2;
	
	for(i=0; i<k ; i++)
	{		
		c[i] = 2 * (a[i] * b[i]) ;	
	}

	for(i=k; i<n; i++)
	{
		c[i] = 2*(a[i] + b[i]);
	}

	c[0] = a[0] * b[0];
}


void kernel2(int n, double a[n], double b[n], double c[n])
{
	int i;
	
	c[0] = a[0] * b[0];
	
	for(i=1; i<n/2 ; i++)
	{		
		c[i] = 2 * (a[i] * b[i]) ;
	
	}

	for(i=n/2; i<n; i++)
	{
		c[i] = 2*(a[i] + b[i]);
	}
}


void kernel1(int n, double a[n], double b[n], double c[n])
{
	int i;
	
	for(i=0; i<n/2 ; i++)
	{
		c[i] = a[i] * b[i];
	}
	
	for(i=n/2; i<n;i++)
	{
		c[i] = a[i] + b[i];
	}
	
	for(i=1; i<n;i++)
	{
		c[i] *=2;
	}
}

void kernel0(int n, double a[n], double b[n], double c[n])
{
	int i;
	
	for(i=0; i<n ; i++)
	{
		if(i<(n/2))
		{
			c[i] = a[i] * b[i];
		}
		else
		{
			c[i] = a[i] + b[i];
		}
	}
	for(i=1; i<n;i++)
	{
		c[i] *=2;
	}
	
}
