#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int secante (double x0, double x1, int p, double (*f) (double x), double* r); //teste: secante 1.0 e 3.0, IQI 0.0, 1.5, 3.0
int IQI (double x0, double x1, double x2, int p, double (*f) (double x), double* r);