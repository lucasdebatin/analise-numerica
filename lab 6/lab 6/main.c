#include "mmq.h"

int main(void)
{
	double** M1 = mat_cria(5,3);
	double* v1 = (double*)malloc(sizeof(double)*5);
	double** M2 = mat_cria(5,4);
	double* v2 = (double*)malloc(sizeof(double)*5);	
	int i;
	double* t = (double*)malloc(sizeof(double) * 8);
	double* c = (double*)malloc(sizeof(double) * 8);
	double conc, a, b;

	t[0] = 1.0; t[1] = 2.0; t[2] = 3.0; t[3] = 4.0; t[4] = 5.0; t[5] = 6.0; t[6] = 7.0;  t[7] = 8.0;
	c[0] = 8.0; c[1] = 12.3; c[2] = 15.5; c[3] = 16.8; c[4] = 17.1; c[5] = 15.8; c[6] = 15.2;  c[7] = 14.0;

	v1[0] = 10.0; v1[1] = 10.0; v1[2] = -5.0; v1[3] = 15.0; v1[4] = 0.0;
	v2[0] = 10.0; v1[1] = 0.0; v1[2] = 2.0; v1[3] = 0.0; v1[4] = 5.0;

	M1[0][0] = 3.0; M1[0][1] = -1.0; M1[0][2] = 2.0;
	M1[1][0] = 4.0; M1[1][1] = 1.0; M1[1][2] = 0.0;
	M1[2][0] = -3.0; M1[2][1] = 2.0; M1[2][2] = 1.0;
	M1[3][0] = 1.0; M1[3][1] = 1.0; M1[3][2] = 5.0;
	M1[4][0] = -2.0; M1[4][1] = 0.0; M1[4][2] = 3.0;

	M2[0][0] = 4.0; M2[0][1] = 2.0; M2[0][2] = 3.0; M2[0][3] = 0.0;
	M2[1][0] = -2.0; M2[1][1] = 3.0; M2[1][2] = -1.0; M2[1][3] = 1.0;
	M2[2][0] = 1.0; M2[2][1] = 3.0; M2[2][2] = -4.0; M2[2][3] = 2.0;
	M2[3][0] = 1.0; M2[3][1] = 0.0; M2[3][2] = 1.0; M2[3][3] = -1.0;
	M2[4][0] = 3.0; M2[4][1] = 1.0; M2[4][2] = 3.0; M2[4][3] = -2.0;


	double* x1 = mmq(5, 3, M1, v1);
	double e1 = norma2(5, 3, M1, v1, x1);

	double* x2 = mmq(5, 4, M2, v2);
	double e2 = norma2(5, 4, M2, v2, x2);

	printf("vetor 1:\n");
	for (i = 0; i < 3; i++) {
		printf("%.6g\t", x1[i]);
	} 
	printf("\nerro associado: %.6g\n\n", e1);

	printf("vetor 2:\n");
	for (i = 0; i < 4; i++) {
		printf("%.6g\t", x2[i]);
	}
	printf("\nerro associado: %.6g\n\n", e2); 

	conc = concentracao(8, t, c, &a, &b);
	printf("coeficientes:\n");
	printf("a: %.6g\n", a);
	printf("b: %.6g\n", b);
	printf("norma2: %.6g\n\n", conc);


	free(t);
	free(c);
	free(x1);
	free(x2);
	mat_libera(5,M1);
	mat_libera(5,M2);
	free(v1);
	free(v2);
	return 0;
}