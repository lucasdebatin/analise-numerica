#include "gradconj.h"

double norma2(int n, double* x){
	int i;
	double sol = 0.0;

	for(i = 0; i < n; i++){
		sol += x[i]*x[i]; 
	}

	return sqrt(sol);
}

double multv(int n, double* v1, double* v2)
{
	int i;
	double sol = 0.0;

	for (i = 0; i < n; i++)
	{
		sol += v1[i] * v2[i];
	}

	return sol;
}



int GradienteConjugado (int n, double** A, double* b, double* x, double tol)
{
	int k, i;
	double n2, alpha, beta;
	double* res = (double*)malloc(sizeof(double)*n);
	double* temp = (double*)malloc(sizeof(double)*n);
	double* Ax = (double*)malloc(sizeof(double)*n);
	double* d = (double*)malloc(sizeof(double)*n);
	double* Ad = (double*)malloc(sizeof(double)*n);


	mat_multv(n, n, A, x, Ax);
	for(i = 0; i < n; i++){
		res[i] = b[i] - Ax[i];
		d[i] = res[i]; 
	}

	for(k = 0; k < n; k++){

		n2 = norma2(n, res);
	
		if(n2 <= tol){
		//	printf("norma2: %.16g\n\n\n", n2);
			break;
		}

		mat_multv(n, n, A, d, Ad);
		alpha = multv(n, res, res) / multv(n, d, Ad);

		for (i = 0; i < n; i++) {
			x[i] += alpha*d[i];
		}

		for (i = 0; i < n; i++) {
			temp[i] = res[i];
		}

		for (i = 0; i < n; i++) {
			res[i] -= alpha*Ad[i];
		} 

		beta = multv(n, res, res) / multv(n, temp, temp);

		for (i = 0; i < n; i++) {
			d[i] = res[i] + beta* d[i];
		}
		
	}

	free(temp);
	free(Ad);
	free(d);
	free(Ax);
	free(res);
	return k;
}