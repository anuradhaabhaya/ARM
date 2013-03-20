#ifndef KERNEL_H
#define KERNEL_H

#include <emmintrin.h>

void kernelNTS(int n, double a[n], double b[n], double c[n]);

void kernel3(int n, double a[n], double b[n], double c[n]);

void kernel2(int n, double a[n], double b[n], double c[n]);

void kernel1(int n, double a[n], double b[n], double c[n]);

void kernel0(int n, double a[n], double b[n], double c[n]);

#endif
