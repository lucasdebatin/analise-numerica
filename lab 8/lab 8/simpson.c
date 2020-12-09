#include "simpson.h"

double DoubleSimpson (double a, double b, double (*f) (double x), double* v)
{
	double Sab, Sac, Scb;
	double erro;
	double c = (a + b)/2;
	double fa = f(a), fb = f(b), fc = f(c);

	Sab = ((b-a)/6)*(fa + 6*f((a+b)/2) + fb);
	Sac = ((c-a)/6)*(fa + 6*f((a+c)/2) + fc);
	Scb = ((b-c)/6)*(fc + 6*f((c+b)/2) + fb);

	//Eab = -(1/90)*((b-a)/2)*((b-a)/2)*((b-a)/2)*((b-a)/2)*((b-a)/2)*f(c);
	//erro = Eab/16;
	erro = fabs(Sab - Sac - Scb) / 15;
	*v = Sac + Scb + erro;

	return erro;
}


double AdaptiveSimpson (double a, double b, double (*f) (double x), double tol)
{
	double integral, Sac, Scb;
	double erro = DoubleSimpson(a, b, f, &integral);
	double c = (a + b) / 2;

	if (erro <= tol) {
		return integral;
	}
	else {
		Sac = AdaptiveSimpson(a, c, f, tol / 2);
		Scb = AdaptiveSimpson(c, b, f, tol / 2);
		return Sac + Scb;
	}

}