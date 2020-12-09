#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"
#include "sistlinear.h"

double* mmq (int m, int n, double** A, double* b);
double norma2 (int m, int n, double** A, double* b, double* x);
double concentracao (int n, double* t, double* c, double* pa, double* pb);