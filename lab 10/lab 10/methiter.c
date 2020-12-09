#include "methiter.h"

double norma2(double* x, int n) {
	int i;
	double norma = 0.0;

	for (i = 0; i < n; i++) {
		norma += x[i] * x[i];
	}

	return sqrt(norma);
}

int Jacobi (int n, double** A, double* b, double* x, double tol)
{
	int i,j,it;
	double *dif = (double*)malloc(sizeof(double)*n);
	double soma = 0.0;
	double n2;

	for (it = 1; it < NMAX; it++) {

		for (i = 0; i < n; i++) {
			soma = 0.0;

			for (j = 0; j < n; j++) {

				if (i != j) {
					soma += A[i][j] * x[j];
				}
			}
			dif[i] = x[i];
			x[i] = (b[i] - soma) / A[i][i];
	
		}

		for (i = 0; i < n; i++) {
			dif[i] = x[i] - dif[i];
		}

		n2 = norma2(dif, n);

		if (n2 <= tol) {
			break;
		}

	}

	if (it == NMAX) {
		printf("solucao divergiu\n\n");
	}

	free(dif);
	return it;
}

int GaussSeidel(int n, double** A, double* b, double* x, double tol)
{
	int i, j, it;
	double n2;
	double soma = 0.0;
	double *dif = (double*)malloc(sizeof(double)*n);

	for (it = 1; it < NMAX; it++)
	{

		for (i = 0; i < n; i++)
		{
			soma = 0.0;
			for (j = 0; j < i; j++)
			{
				soma += A[i][j] * x[j];
			}

			for (j = i + 1; j < n; j++) {
				soma += A[i][j] * x[j];
			}

			dif[i] = x[i];
			x[i] = (b[i] - soma) / A[i][i];

		}

		for (i = 0; i < n; i++) {
			dif[i] = x[i] - dif[i];
		}

		n2 = norma2(dif, n);

		if (n2 <= tol) {
			break;
		}
	}

	if (it == NMAX) {
		printf("solucao divergiu\n\n");
	}

	free(dif);
	return it;
}

int SOR(int n, double** A, double* b, double* x, double tol, double w)
{
	int i, j, it;
	double soma = 0.0, n2;
	double *dif = (double*)malloc(sizeof(double)*n);

	for (it = 1; it < NMAX; it++)
	{

		for (i = 0; i < n; i++) {
			soma = 0.0;

			for (j = 0; j < i; j++)
			{
				soma += A[i][j] * x[j];
			}

			for (j = i + 1; j < n; j++) {
				soma += A[i][j] * x[j];
			}

			dif[i] = x[i];
			x[i] = (1.0 - w)*x[i] + w*(b[i] - soma) / A[i][i];

		}

		for (i = 0; i < n; i++) {
			dif[i] = x[i] - dif[i];
		}

		n2 = norma2(dif, n);

		if (n2 <= tol) {
			break;
		}


	}

	if (it == NMAX) {
		printf("solucao divergiu\n\n");
	}


	return it;
}