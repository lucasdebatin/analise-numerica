#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

double* Chebyshev (int n, double a, double b);
double* NewtonCoef (int n, double* xi, double (*f) (double));
double NewtonAval (int n, double* xi, double* bi, double x);