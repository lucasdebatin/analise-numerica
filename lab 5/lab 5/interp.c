#include "interp.h"

double* Chebyshev (int n, double a, double b)
{
	double* x = (double*) malloc (sizeof(double)*n);
	double beta = 1.0;
	double m1 = (b - a)/2;
	double m2 = (b + a)/2;
	int i;

	for(i = 0; i < n; i++)
	{
		beta = 2.0 * i + 1.0;
		x[i] =( m1*cos(beta*PI/(2*n)) ) + m2;

	}

	return x;
}

double calculadif(int i, int j, double* xi, double(*f) (double))
{
	if (i == j)
	{
		return f(xi[i]);
	}
	else
		return (calculadif(i+1, j, xi, f) - calculadif(i, j -1, xi, f)) / (xi[j] - xi[i]);
}

double* NewtonCoef (int n, double* xi, double (*f) (double))
{
	double* b = (double*)malloc(sizeof(double)*n);
	int i;

	for (i = 0; i < n; i++) {
		b[i] = calculadif(0, i, xi, f);
	}

	return b;
}

double NewtonAval (int n, double* xi, double* bi, double x)
{
	double p = 0.0;
	double* f = (double*)malloc(sizeof(double)*n);
	int i;
	f[0] = 1.0;
	for (i = 1; i < n; i++) {
		f[i] = f[i - 1] * (x - xi[i-1]);
	}

	for(i = 0; i < n; i++)
	{
		p = p + bi[i] * f[i];
	}

	free(f);
	return p;
}