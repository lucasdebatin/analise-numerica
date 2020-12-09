#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include <math.h>

double** mat_cria(int m, int n)
{
	int i;
	double** matriz = (double**)malloc(m*sizeof(double*));

	for (i = 0; i < m; i++)
	{
		matriz[i] = (double*)malloc(n*sizeof(double));
	}

	return matriz;
}

void mat_libera(int m, double** A)
{
	int i;
	
	for (i = 0; i < m; i++)
	{
		free(A[i]);
	}

	free(A);
}

void mat_transposta(int m, int n, double** A, double** T)
{
	int i, j;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			T[j][i] = A[i][j];
		}
	}

}

void mat_multv(int m, int n, double** A, double* v, double* w)
{
	int i, j;
	double temp = 0.0;

	for (i = 0; i < m; i++)
	{
		temp = 0.0;

		for (j = 0; j < n; j++)
		{
			temp = temp + A[i][j] * v[j];
		}

		w[i] = temp;
	}	
}

void mat_multm(int m, int n, int q, double** A, double** B, double** C)
{
	int i, j, k;
	double temp = 0.0;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < q; j++)
		{
			temp = 0.0;

			for (k = 0; k < n; k++)
			{
				temp = temp + A[i][k] * B[k][j];
			}

			C[i][j] = temp;
		}

	}
}

int mat_iguais (int m, int n, double** A, double** B, double tol)
{
	int i,j;
	double temp;

	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			temp = A[i][j] - B[i][j];
			if(fabs(temp) > tol){
				return 0;
			}
		}
	}

	return 1;
}

void mat_imprime (int m, int n, double** A, char* format)
{
	int i, j;

	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf(format,A[i][j]);
			printf(" ");
		}
		printf("\n");
	}
	printf("\n");
}
