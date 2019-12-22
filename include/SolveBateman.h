#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Nucleus.h"
#include "NumericalMethod.h"
#include "Reader.h"
using namespace std;

class SolveBateman
	{
	private :
	vector<Nucleus*> fNuclList;
	int fIJ;

	public :

	SolveBateman(){}
	~SolveBateman(){}

	void SetListOfNuclei(vector<Nucleus*>);
	void Process();
	void SetIJ(int);
	int GetIJ();
	};
