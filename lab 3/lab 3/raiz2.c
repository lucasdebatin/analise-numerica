#include "raiz2.h"

int secante (double x0, double x1, int p, double (*f) (double x), double* r)
{
	double tol = 0.5*pow(10.0,-p);
	int i;
	double d;
	double xi = x1;
	double xim = x0;
	double xii;
	double fxi,fxim;

	for(i = 1; i <= 50; i++){

		fxi = f(xi); fxim = f(xim);
		d = (fxi - fxim)/(xi-xim);

		if(fabs(fxi) < tol){
			*r = xi;
			return i;
		}

		xii = xi - fxi/d;
		xim = xi;
		xi = xii;
		
	}

	return 0;
}

int IQI (double x0, double x1, double x2, int p, double (*f) (double x), double* r)
{
	int i;
	double tol = 0.5*pow(10.0,-p);
	double A[3][3];
	double Ac[3][3];
	double c; 
	double detA;
	double detAc;
	double xii, xi = x2, xim = x1, ximm = x0;
	double fxi, fxim,fximm;
	double s1, s2, s3;

	for(i = 1; i<=50; i++){
		fxim = f(xim); fxi = f(xi); fximm = f(ximm);
		
		if (fabs(fxi) < tol) {
			*r = xi;
			return i;
		}

		A[0][0] = fximm*fximm; A[0][1] = fximm; A[0][2] = 1.0;
		A[1][0] = fxim*fxim; A[1][1] = fxim; A[1][2] = 1.0;
		A[2][0] = fxi*fxi; A[2][1] = fxi; A[2][2] = 1.0;

		Ac[0][0] = fximm*fximm; Ac[0][1] = fximm; Ac[0][2] = ximm;
		Ac[1][0] = fxim*fxim; Ac[1][1] = fxim; Ac[1][2] = xim;
		Ac[2][0] = fxi*fxi; Ac[2][1] = fxi; Ac[2][2] = xi;

		detA = ( (A[0][0]*A[1][1]*A[2][2]) + (A[0][1]*A[1][2]*A[2][0]) + (A[0][2]*A[1][0]*A[2][1]) ) - ( (A[0][0]*A[1][2]*A[2][1]) + (A[0][1]*A[1][0]*A[2][2]) + (A[0][2]*A[1][1]*A[2][0]) );
		detAc = ( (Ac[0][0]*Ac[1][1]*Ac[2][2]) + (Ac[0][1]*Ac[1][2]*Ac[2][0]) + (Ac[0][2]*Ac[1][0]*Ac[2][1]) ) - ( (Ac[0][0]*Ac[1][2]*Ac[2][1]) + (Ac[0][1]*Ac[1][0]*Ac[2][2]) + (Ac[0][2]*Ac[1][1]*Ac[2][0]) );
		
		if (detA == 0.0)
			return -1;

		c = detAc/detA;
		xii = c;
		s1 = fabs(xii - xi); s2 = fabs(xii - xim); s3 = fabs(xii - ximm);

		//ponto xi é o mais distante da raiz
		if (s1 > s2 && s1 > s3) {
			xi = xii;
		}
		//ponto xim é o mais distante 
		else if (s2 > s1 && s2 > s3) {
			xim = xii;
		}
		//ponto ximm é o mais distante
		else if (s3 > s1 && s3 > s2) {
			ximm = xii;
		}

	}

	return 0;
}