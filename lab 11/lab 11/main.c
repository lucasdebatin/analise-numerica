#include "gradconj.h"

int main(void)
{
	double** M1 = mat_cria(3,3);
	double** M2 = mat_cria(3,3);
	double* b1 = (double*)malloc(sizeof(double)*3);
	double* b2 = (double*)malloc(sizeof(double)*3);
	double* x1 = (double*)malloc(sizeof(double)*3);
	double* x2 = (double*)malloc(sizeof(double)*3);
	double tol = 0.1;
	int i, iter1, iter2;

	M1[0][0] = 1.0; M1[0][1] = -1.0; M1[0][2] = 0.0;
	M1[1][0] = -1.0; M1[1][1] = 2.0; M1[1][2] = 1.0;
	M1[2][0] = 0.0; M1[2][1] = 1.0; M1[2][2] = 2.0;

	M2[0][0] = 1.0; M2[0][1] = -1.0; M2[0][2] = 0.0;
	M2[1][0] = -1.0; M2[1][1] = 2.0; M2[1][2] = 1.0;
	M2[2][0] = 0.0; M2[2][1] = 1.0; M2[2][2] = 5.0;

	b1[0] = 0.0; b1[1] = 2.0; b1[2] = 3.0;
	b2[0] = 3.0; b2[1] = -3.0; b2[2] = 4.0;

	x1[0] = 0.9; x1[1] = 0.9; x1[2] = 0.5;
	x2[0] = 0.9; x2[1] = 0.9; x2[2] = 0.5;

	iter1 = GradienteConjugado(3, M1, b1, x1, tol);
	printf("solucao da matriz 1\n\niteracoes: %d\n\n", iter1);
	for (i = 0; i < 3; i++) {
		printf("%.6g\t", x1[i]);
	}
	printf("\n\n------------------------\n"); 

	iter2 = GradienteConjugado(3, M2, b2, x2, tol);
	printf("solucao da matriz 2\n\niteracoes: %d\n\n", iter2);
	for (i = 0; i < 3; i++) {
		printf("%.6g\t", x2[i]);
	}
	printf("\n\n\n"); 

	free(x1);
	free(x2);
	free(b1);
	free(b2);
	mat_libera(3,M1);
	mat_libera(3,M2);
	return 0;
}