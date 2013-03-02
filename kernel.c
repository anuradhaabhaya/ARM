#include "kernel.h"


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
