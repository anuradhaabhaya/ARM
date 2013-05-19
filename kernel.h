#ifndef KERNEL_H
#define KERNEL_H



#include "kernel.h"
#include <emmintrin.h>


void kernelNTS(int n, double a[n], double b[n], double c[n]);
void kernel8(int n, double a[n], double b[n], double c[n]);
void kernel7(int n, double a[n], double b[n], double c[n]);
void kernel_omp(int n, double a[n], double b[n], double c[n]);
void kernel6(int n, double a[n], double b[n], double c[n]);
void kernel5(int n, double a[n], double b[n], double c[n]);
void kernel4(int n, double *__restrict__ a, double *__restrict__ b, double *__restrict__ c);
void kernel3(int n, double a[n], double b[n], double c[n]);
void kernel2(int n, double a[n], double b[n], double c[n]);
void kernel1(int n, double a[n], double b[n], double c[n]);
void kernel0(int n, double a[n], double b[n], double c[n]);


#endif
