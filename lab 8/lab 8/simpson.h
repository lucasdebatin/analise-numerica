#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846
//tol = 0.5*10^-7 
double DoubleSimpson (double a, double b, double (*f) (double x), double* v);
double AdaptiveSimpson (double a, double b, double (*f) (double x), double tol); //retornar a integral