#include "ode.h"

double func(double t) {
	return exp(t*t / 2) - t*t - 2.0;
}

double f_derivada(double t, double y) {
	return t*y + t*t*t;
}

int main(void)
{
	int i;
	double h_euler = 0.1;
	double h_mp = 0.2;
	double h_rk = 0.4;
	double t1 = 2.4, t0 = 0.0;
	double sol_euler, sol_mp, sol_rk, erro_euler, erro_mp, erro_rk;
	double x0 = -1.0;
	double funcao = func(t1);


	printf("Metodo\t\t h\t\t y(2.4)\t\t\t erro\n");
	for(i = 0; i < 3; i++){

		sol_euler = Euler(t0, t1, h_euler, x0, f_derivada);
		erro_euler = fabs(funcao - sol_euler) / funcao;

		sol_mp = MidPoint(t0, t1, h_mp, x0, f_derivada);
		erro_mp = fabs(funcao - sol_mp) / funcao;

		sol_rk = RungeKutta(t0, t1, h_rk, x0, f_derivada);
		erro_rk = fabs(funcao - sol_rk) / funcao;

		printf("----------\n");
		printf("Euler\t\t %g\t\t %g\t\t %g\n", h_euler, sol_euler, erro_euler);
		printf("MidPoint\t %g\t\t %g\t\t  %g\n", h_mp,sol_mp,erro_mp);
		printf("Runge-Kutta\t %g\t\t %lf\t\t %g\n", h_rk, sol_rk, erro_rk);

		h_euler /= 10;
		h_mp /= 10;
		h_rk /= 10;
	}
	printf("\n\n");

	return 0;
}