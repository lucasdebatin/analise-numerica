#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846
#define NMAX 1000000

double bissecao (double a, double b, int p, double (*f) (double x));
double altura_agua (double r, double v); //4 digitos de precisão
double pontofixo (double x0, double epsilon, double (*g) (double x));
double fraiz (double z); //g(x) = (x+x/2)/2