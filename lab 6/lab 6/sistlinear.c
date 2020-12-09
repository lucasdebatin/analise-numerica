#include "sistlinear.h"
#include "matriz.h"

static void pivotamento(int n, int *p, double** A) {
	int i, j, t, pivo;
	double temp;

	//percorre colunas
	for (j = 0; j < n - 1; j++)
	{
		//encontra o pivo
		pivo = j;
		for (i = j+1; i < n;i++) {
			if (fabs(A[i][j]) > fabs(A[pivo][j])) {
				pivo = i;
			}
		} 
		//troca as linhas
		if (pivo != j) {
			for (t = 0; t < n; t++) {
				temp = A[j][t];
				A[j][t] = A[pivo][t];
				A[pivo][t] = temp;
			}
			t = p[j];
			p[j] = p[pivo];
			p[pivo] = t; 

		} 

	} 
}

int* fatoracao (int n, double** A)
{
	int *p = (int*)malloc(n*sizeof(int));
	int i,j,k;
	double f;


	for (i = 0; i < n; i++)
	{
		p[i] = i;
	}

	pivotamento(n, p, A);

	//fatoramento
	for (j = 0; j < n - 1; j++)
	{
		for (i = j + 1; i < n; i++)
		{
			
			f = A[i][j] / A[j][j];
			for (k = j + 1; k < n; k++)
			{
				A[i][k] -= f*A[j][k];
			}
			A[i][j] = f; 
		}
	} 
	
	return p;
}

double* substituicao(int n, double** A, int* p, double* b)
{
	double* x = (double*)malloc(n*sizeof(double));
	int i, j;

	for (i = 0; i < n; i++)
	{
		x[i] = b[p[i]];

		for (j = 0; j < i; j++)
		{
			x[i] -= A[i][j] * x[j];
		}

	}

	for (i = n - 1; i >= 0; i--)
	{
		for (j = i + 1; j < n;j++)
		{
			x[i] -= A[i][j] * x[j];
		}

		x[i] = x[i] / A[i][i];
	}

	return x;
}
