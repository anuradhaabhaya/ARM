#include "kernel.h"


/**
 * Utilisation des intrinsics de "non temporal store" (NTS)
 * void _mm_stream_pd(double * p, __m128d b)
 * __m128d _mm_set1_pd(double w)
 * __m128d _mm_load1_pd( double const * dp)
 */
void kernelNTS(int n, double a[n], double b[n], double c[n])
{
	int i;
	int k = n/2;
	__m128d aVal, bVal, two;
	two = _mm_set_sd(2.0);

	c[0] = a[0] * b[0];
	
	for(i=1; i<k ; i++)
	{		
		aVal = _mm_load1_pd( a+i );
		bVal = _mm_load1_pd( b+i );
		_mm_stream_pd( c+i, _mm_mul_pd(two , _mm_mul_pd(aVal, bVal) ) );
	
	}

	for(i=k; i<n; i++)
	{
		aVal = _mm_load1_pd( a+i );
		bVal = _mm_load1_pd( b+i );
		_mm_stream_pd( c+i,  _mm_mul_pd(two , _mm_add_pd(aVal, bVal) ) ) ;
	}
}

void kernel3(int n, double a[n], double b[n], double c[n])
{
	int i;
	int k = n/2;

	c[0] = a[0] * b[0];
	
	for(i=1; i<k ; i++)
	{		
		c[i] = 2 * (a[i] * b[i]) ;
	
	}

	for(i=k; i<n; i++)
	{
		c[i] = 2*(a[i] + b[i]);
	}
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
