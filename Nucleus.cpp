#include "Nucleus.h"

int Nucleus::Getz(){
	return	fz;
	}

int Nucleus::Geta(){
	return fa;
	}

void Nucleus::Setza(int n_protons,int n_nucleons){
	fa = n_nucleons;
	fz= n_protons;
	}

void Nucleus::Setname(string name){
	fname= name;
	}

void Nucleus::Setlambda(){
	fLambda = log(2)/fHalfLife;
	}

void Nucleus::SetHalfLife(double halflife){
	fHalfLife = halflife;
	}

string Nucleus::Getname(){
	return fname;
	}

double Nucleus::Getlambda(){
	return fLambda;
	}
