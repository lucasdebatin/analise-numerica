#include "taylor.h"

double fcos (double x){
	double p = -1.0*(x-PI/2)+((x-PI/2)*(x-PI/2)*(x-PI/2)/6);
	return p;
}

double fcos_erro (double x){
	double p = fabs(((x-PI/2.0)*(x-PI/2.0)*(x-PI/2.0)*(x-PI/2.0)*(x-PI/2.0))/(5.0*4.0*3.0*2.0*1.0));
	return p;
}

double fsqrt (double x){

	//1 + (-1/2)(x-1) + (3/4)(x-1)(x-1) + (-15/8)(x-1)(x-1)(x-1)
	double p = 1 + (-0.5)*(x-1) + (3*(x-1)*(x-1)/8) + (-15.0*(x-1)*(x-1)*(x-1)/48); 
	return p;
}

double fsqrt_erro (double x){
	//(105/16x^(9/2))/4! * (x-1)^4
	double p = fabs((35.0*(x-1)*(x-1)*(x-1)*(x-1))/128);
	return p;
}