#include "taylor.h"


int main(void){

	double a = PI;
	double b = PI/4;
	double c = PI/6;
	double d = PI/8;

	printf("fcos:\npara x = PI\n");
	if(fabs(fcos(a) - cos(a)) <= fcos_erro(a)){
		printf("ok\n");
	}
	else printf("erro\n");

	printf("para x = PI/4\n");
	if(fabs(fcos(b) - cos(b)) <= fcos_erro(b)){
		printf("ok\n");
	}
	else printf("erro\n");

	printf("para x = PI/6\n");
	if(fabs(fcos(c) - cos(c)) <= fcos_erro(c)){
		printf("ok\n");
	}
	else printf("erro\n");

	printf("para x = PI/8\n");
	if(fabs(fcos(d) - cos(d)) <= fcos_erro(d)){
		printf("ok\n");
	}
	else printf("erro\n");

	printf("\n");
	printf("fsqrt\npara x = 1\n");
	if (fabs(fsqrt(1.0) - pow(1.0,-0.5)) <= fsqrt_erro(1.0)) {
		printf("ok\n");
	}
	else printf("erro\n");

	printf("para x = 2.0\n");
	if (fabs(fsqrt(2.0) - pow(2.0, -1.0/2.0)) <= fsqrt_erro(2.0)) {
		printf("ok\n");
	}
	else printf("erro\n");


	printf("para x = 1.5\n");
	if (fabs(fsqrt(1.5) - pow(1.5, -1.0/2.0)) <= fsqrt_erro(1.5)) {
		printf("ok\n");
	}
	else printf("erro\n");

	printf("para x = 1.8\n");
	if (fabs(fsqrt(1.8) - pow(1.8, -0.5)) <= fsqrt_erro(1.8)) {
		printf("ok\n");
	}
	else printf("erro\n");


	printf("para x = 1.2\n");
	if (fabs(fsqrt(1.2) - pow(1.2, -0.5)) <= fsqrt_erro(1.2)) {
		printf("ok\n");
	}
	else printf("erro\n");

	return 0;
}