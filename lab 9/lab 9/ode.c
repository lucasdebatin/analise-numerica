#include "ode.h"

double Euler (double t0, double t1, double h, double x0, double (*f) (double t, double x))
{
	double x1 = x0, t;

	for(t = t0; t < t1; t = t + h)
	{
		x1 += h*f(t,x1);

	}
	
	return x1;
}

double MidPoint (double t0, double t1, double h, double x0,double (*f) (double t, double x)){
	double x1 = x0;
	double k1, t;
	

	for (t = t0; t < t1; t += h)
	{
		k1 = h*f(t, x1);
		x1 += h*f(t + h / 2, x1 + k1 / 2);

	}

	return x1;
}

double RungeKutta(double t0, double t1, double h, double x0, double(*f) (double t, double x))
{
	double x1 = x0;
	double t, k1, k2, k3, k4;

	for (t = t0; t < t1; t += h)
	{
		k1 = h*f(t, x1);
		k2 = h*f(t + h / 2, x1 + k1 / 2);
		k3 = h*f(t + h / 2, x1 + k2 / 2);
		k4 = h*f(t + h , x1 + k3);
		x1 += (k1 + (2.0 * k2) + (2.0 * k3) + k4)/6;

	}

	return x1;
}