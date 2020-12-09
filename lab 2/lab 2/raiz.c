#include "raiz.h"
static double vol;
static double raio;
static double valor;

static double func(double x){
	return (PI*x*x*raio) - (PI*x*x*x/3) - vol;
}

static double func2(double x) {
	return (x + valor/x) / 2.0;
}

double bissecao (double a, double b, int p, double (*f) (double x)){

	double e = (0.5*pow(10.0,-p));
	int i = 0;
	double c;
	double erro = fabs((b - a) / 4);

	while(i<NMAX)
	{
		c = (a+b)/2;

		if( f(c) == 0.0 ||  erro < e )
		{
			return c;
		}

		if( f(c)*f(a)>0 )
		{
			a = c;
		}
		else b = c;
		i++;
		erro = erro / 2;
	}

	return -1;

}


double altura_agua (double r, double v){
	vol = v;
	raio = r;
	double h = bissecao (0.0, 2*raio, 4, func);
	return h;

}

double pontofixo(double x0, double epsilon, double(*g) (double x))
{
	double xn;
	int i = 0;

	if (g(x0) == x0)
		return x0;

	while (i < NMAX)
	{
		xn = g(x0);
		if (g(xn) == xn || fabs(xn - x0) < epsilon)
			return xn;
		x0 = xn;
		i++;

	}

	return -1;
}

double fraiz(double z)
{
	valor = z;
	double tol = 0.5*pow(10, -6);
	double p = pontofixo(z/2, tol, func2);
	return p;
}