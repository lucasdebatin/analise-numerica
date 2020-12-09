#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"
#define NMAX 10000


int Jacobi (int n, double** A, double* b, double* x, double tol);
int GaussSeidel (int n, double** A, double* b, double* x, double tol);
int SOR (int n, double** A, double* b, double* x, double tol, double w);
