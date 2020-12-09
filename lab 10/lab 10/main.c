#include "methiter.h"

int main(void)
{
	double** M1 = mat_cria(2,2);
	double* v1 = (double*)malloc(sizeof(double)*2);
	double** M2 = mat_cria(6,6);
	double* v2 = (double*)malloc(sizeof(double)*6);
	double* x1 = (double*)malloc(sizeof(double)*2);
	double* x2 = (double*)malloc(sizeof(double) * 6);
	double tol = pow(10.0, -7);
	double fr = 1.1;
	int j1, j2, gs1, gs2, sor1, sor2, i;

	x1[0] = 0.0; x1[1] = 0.0;
	x2[0] = 0.0; x2[1] = 0.0; x2[2] = 0.0; x2[3] = 0.0; x2[4] = 0.0; x2[5] = 0.0;

	M1[0][0] = 3.0; M1[0][1] = 1.0;
	M1[1][0] = 1.0; M1[1][1] = 2.0;

	v1[0] = 5.0; v1[1] = 5.0;

	M2[0][0] = 3.0; M2[0][1] = -1.0; M2[0][2] = 0.0; M2[0][3] = 0.0; M2[0][4] = 0.0; M2[0][5] = 0.5;
	M2[1][0] = -1.0; M2[1][1] = 3.0; M2[1][2] = -1.0; M2[1][3] = 0.0; M2[1][4] = 0.5; M2[1][5] = 0.0;
	M2[2][0] = 0.0; M2[2][1] = -1.0; M2[2][2] = 3.0; M2[2][3] = -1.0; M2[2][4] = 0.0; M2[2][5] = 0.0;
	M2[3][0] = 0.0; M2[3][1] = 0.0; M2[3][2] = -1.0; M2[3][3] = 3.0; M2[3][4] = -1.0; M2[3][5] = 0.0;
	M2[4][0] = 0.0; M2[4][1] = 0.5; M2[4][2] = 0.0; M2[4][3] = -1.0; M2[4][4] = 3.0; M2[4][5] = -1.0;
	M2[5][0] = 0.5; M2[5][1] = 0.0; M2[5][2] = 0.0; M2[5][3] = 0.0; M2[5][4] = -1.0; M2[5][5] = 3.0;

	v2[0] = 2.5; v2[1] = 1.5; v2[2] = 1.0; v2[3] = 1.0; v2[4] = 1.5; v2[5] = 2.5;


	j1 = Jacobi(2, M1, v1, x1, tol);
	j2 = Jacobi(6, M2, v2, x2, tol);

	printf("\nmetodo de Jacobi\n");
	printf("numero de iteracoes do sistema 1: %d\nsolucao:\n", j1);
	printf("%.16g\t%.16g\n\n", x1[0], x1[1]);

	printf("numero de iteracoes do sistema 2: %d\nsolucao:\n", j2);
	for (i = 0; i < 6; i++) {
		printf("%.6g\t", x2[i]);
	}
	printf("\n\n"); 
	printf("-----------------------------------------------\n\n");

	x1[0] = 0.0; x1[1] = 0.0;
	x2[0] = 0.0; x2[1] = 0.0; x2[2] = 0.0; x2[3] = 0.0; x2[4] = 0.0; x2[5] = 0.0;
	gs1 = GaussSeidel(2, M1, v1, x1, tol);
	gs2 = GaussSeidel(6, M2, v2, x2, tol);

	printf("metodo Gauss-Seidel\n");
	printf("numero de iteracoes do sistema 1: %d\nsolucao:\n", gs1);
	printf("%.16g\t%.16g\n\n", x1[0], x1[1]);

	printf("numero iteracoes do sistema 2: %d\nsolucao:\n", gs2);
	for (i = 0; i < 6; i++) {
		printf("%.6g\t", x2[i]);
	} 
	printf("\n\n");
	printf("-----------------------------------------------\n\n");

	x1[0] = 0.0; x1[1] = 0.0;
	x2[0] = 0.0; x2[1] = 0.0; x2[2] = 0.0; x2[3] = 0.0; x2[4] = 0.0; x2[5] = 0.0;
	sor1 = SOR(2, M1, v1, x1, tol, fr);
	sor2 = SOR(6, M2, v2, x2, tol, fr);

	printf("metodo SOR\n");
	printf("numero de iteracoes do sistema 1: %d\nsolucao:\n", sor1);
	printf("%.16g\t%.16g\n\n", x1[0], x1[1]);

	printf("numero iteracoes do sistema 2: %d\nsolucao:\n", sor2);
	for (i = 0; i < 6; i++) {
		printf("%.6g\t", x2[i]);
	}
	printf("\n\n");
	printf("-----------------------------------------------\n\n");

	
	free(x1);
	free(x2);
	mat_libera(2,M1);
	mat_libera(6,M2);
	free(v2);
	free(v1);
	return 0;
}
