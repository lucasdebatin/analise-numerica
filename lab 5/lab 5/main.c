#include "interp.h"

static double fat(double n)
{
	if (n == 1)
		return 1.0;
	else
		return n*fat(n - 1);
}

int main(void)
{
	int n = 6,i;
	double x;
	double a = 0.0;
	double b = PI / 2;
	double* amostras = Chebyshev(n,a,b);
	double* coef = NewtonCoef(n, amostras, cos);
	double tol = pow((b - a) / 2, n) / (pow(2.0, n - 1) * fat(n));
	double p;


	printf("amostras de chebyshev:\n");
	for (i = 0; i < n; i++) {
		printf("%g", amostras[i]);
		printf(" ");
	}

	printf("\n\ncoeficientes:\n");
	for (i = 0; i < n; i++) {
		printf("%g", coef[i]);
		printf(" ");
	} 

	printf("\n\n");
	for (x = -2 * PI; x <= 2 * PI; x += PI/2) {
		p = NewtonAval(n, amostras, coef, x);

		printf("cos %.3g = %g\n", x, cos(x));
		printf("aproximacao: %g\n", p);
	
		if (fabs(p - cos(x)) <= tol) {
			printf("precisao atendida\n\n");
		}
		else
			printf("precisao nao atendida\n\n");

	}

	free(amostras);
	free(coef);
	return 0;
}