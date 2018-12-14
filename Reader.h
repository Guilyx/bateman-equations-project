#ifndef READER_H
#define READER_H

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Nucleus.h"
using namespace std;

class Reader {

	private :
	const char* fIn;
	int fNCol;
	string* fTab;
	vector<Nucleus*> fNuclList;

	public :
	Reader();
	Reader(const char* name):fIn(name){}
	~Reader(){}
	void SetInputFile(const char*);
	int GetNumberOfLinesInTextFile();
	void SetNumber(int);
	void FillListOfNuclei();
	vector<Nucleus*> GetListOfNuclei();


};
#endif
