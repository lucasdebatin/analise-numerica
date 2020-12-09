#include "mmq.h"

double* mmq (int m, int n, double** A, double* b){
	double** T = mat_cria(n,m);
	double* Tb = (double*)malloc(sizeof(double)*n);
	double** TA = mat_cria(n,n);
	int* indice;
	double* x;

	mat_transposta(m, n, A, T);
	mat_multm(n, m, n, T, A, TA);
	mat_multv(n, m, T, b, Tb);

	indice = fatoracao(n, TA);
	x = substituicao(n, TA, indice, Tb);

	free(indice);
	free(Tb);
	mat_libera(n,TA);
	mat_libera(n,T);

	return x;
}


double norma2 (int m, int n, double** A, double* b, double* x){
	double norma = 0.0;
	int i;
	double* r = (double*)malloc(sizeof(double)*m);
	double* Ax = (double*)malloc(sizeof(double)*m);

	mat_multv(m, n, A, x, Ax);

	for (i = 0; i < m; i++)
	{
		r[i] = b[i] - Ax[i];
		norma += r[i] * r[i];

	}

	norma = sqrt(norma);

	free(r);
	free(Ax);
	return norma;
}

double concentracao(int n, double* t, double* c, double* pa, double* pb)
{
	double norma = 0.0;
	int i;
	double* v = (double*)malloc(sizeof(double)*n);
	double** M = mat_cria(n, 2);
	double* sol;

	//ln(a) + bti = ln(ci) - ln(ti)
	//vi = ln(a)+bti
	for (i = 0; i < n; i++)
	{
		v[i] = log(c[i]) - log(t[i]);
	}

	//ln(a)+bti = M*sol = vi
	//sol = (ln(a),b)
	//M = ( (1,t1), (1,t2), (1,t3),...,(1,tn))


	for (i = 0; i < n; i++)
	{
		M[i][0] = 1.0;
		M[i][1] = t[i];
	}

	sol = mmq(n, 2, M, v);
	norma = norma2(n, 2, M, v, sol);
	//sol[0] = ln(a)
	*pa = exp(sol[0]);
	*pb = sol[1];

	free(sol);
	mat_libera(n, M);
	free(v);
	return norma;
}