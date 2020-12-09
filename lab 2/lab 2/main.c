#include "raiz.h"

int main(void)
{
	double v = PI*2.0 / 3.0;
	double r = 1.0;
	double h = altura_agua(v, r);
	printf("dado volume = %.4g e raio = %.4g, altura = %.4g\n\n",v,r,h);

	double z = 9.0;
	double resultado = fraiz(z);
	printf("dado z = %.6g, raiz = %.6g\n",z,resultado);

	return 0;
}