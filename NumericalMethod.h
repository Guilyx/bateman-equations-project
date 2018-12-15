#ifndef NUMERICALMETHOD_H
#define NUMERICALMETHOD_H

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class NumericalMethod
	{
	private :
	string fname;

	public :
	NumericalMethod();
	~NumericalMethod(){}
	NumericalMethod(string name):fname(name){}
	double rk4(double,double,double,double);
	};
#endif
