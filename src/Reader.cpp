#include "Reader.h"

void Reader::SetInputFile(const char* input)
	{
	fIn=input;
	}

void Reader::SetNumber(int nb)
	{
	fNCol=nb;
	}

int Reader::GetNumberOfLinesInTextFile()
	{
  // Get the number of lines of the input text file
  int nb = 0;
  ifstream in(fIn , ios::in);
  string ligne;
  while(getline(in, ligne)) nb++;
  in.close();
  cout << "The file " << fIn << " contains " << nb << " lines." <<endl;
  SetNumber(nb);
  return nb;
	}

//Fill the array of Nucleus with the entery file infos
void Reader::FillListOfNuclei()
	{
	GetNumberOfLinesInTextFile();
	ifstream in(fIn , ios::in);
	string ligne;
	fTab = new string[fNCol];
	for(int i=0 ; i < fNCol ; i++)
		{
		getline(in, ligne);
		istringstream iss(ligne);

		iss>>fTab[0]>>fTab[1]>>fTab[2]>>fTab[3]>>fTab[4]>>fTab[5]>>fTab[6];

		Nucleus* Ni= new Nucleus(fTab[3],atoi(fTab[0].c_str()),atoi(fTab[1].c_str()));
		Ni->SetHalfLife(atof(fTab[6].c_str()));
		Ni->Setlambda();

		fNuclList.push_back(Ni);
		cout<<fNuclList[i]->Getz()<<endl;
		}
	}
	vector<Nucleus*> Reader::GetListOfNuclei(){
	return fNuclList;
}
