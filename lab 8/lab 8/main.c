#include "simpson.h"

double f1(double x){
	return x/(sqrt(x*x + 9));
}

double f2(double x)
{
	return exp(-x*x/2);
}

double f3(double x)
{
	return exp(-x*x);
}

int main(void)
{
	double tol = 0.5*pow(10.0, -7);

	double i1 = AdaptiveSimpson(0.0, 1.0, f1, tol);
	printf("1a integral = %.7g\n", i1);

	double i2 = (1.0/sqrt(2*PI)) * AdaptiveSimpson(-1.0, 1.0, f2, tol);
	printf("2a integral = %.7g\n", i2);

	double i3 = (2.0 / (sqrt(PI)))* AdaptiveSimpson(0.0, 3.0, f3, tol);
	printf("3a integral = %.7g\n\n", i3);

	return 0;
}