#include "NumericalMethod.h"

//Soften the resolution
double fNt(double l1,double l2, double N1, double N2)
	{
	return l1*N1+l2*N2;
	}

//Resolving with Runge Kutta
double NumericalMethod::rk4(double l1,double l2, double N1, double N2)
	{
	int fpas = 180; //Plus petite demi-vie
  double k1=fpas*fNt(l1,l2,N1,N2);
	double k2=fpas*fNt(l1,l2,N1+k1/2,N2);
	double k3=fpas*fNt(l1,l2,N1+k2/2,N2);
	double k4=fpas*fNt(l1,l2,N1+k3,N2);
	return (k1+2*k2+2*k3+k4)/6;
	}
