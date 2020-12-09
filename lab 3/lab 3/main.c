#include "raiz2.h"

double func(double x) {
	return cos(x) - (x*x*x) + x;
}

int main(void)
{
	int p = 6;
	double r1,r2;

	int it1 = secante(1.0, 3.0,p, func, &r1);
	int it2 = IQI(0.0, 1.5, 3.0, p, func, &r2);

	printf("Metodo da secante:\nx0 = 1.0, x1 = 3.0, raiz: %g, iteracoes: %d\n\n", r1, it1);
	printf("Metodo IQI:\nx0 = 0.0, x1 = 1.5, x2 = 3.0, raiz: %g, iteracoes: %d\n\n", r2, it2);

	return 0;
}