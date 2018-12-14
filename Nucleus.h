//Classe Nucleus

#ifndef NUCLEUS_H
#define NUCLEUS_H
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Nucleus
	{
	private:
	string fname;
	int fz,fa;
	double fHalfLife,fLambda;


	public:
	Nucleus();
	Nucleus(int protons,int nucleons):fz(protons),fa(nucleons){}
	Nucleus(string name,int protons,int nucleons):fname(name),fz(protons),fa(nucleons){}

	~Nucleus(){}

	int Getz();
	int Geta();
	void Setza(int,int);
	string Getname();
	void Setname(string);
	void Setlambda();
	void SetHalfLife(double);
	double Getlambda();
	};

#endif
