#include "SolveBateman.h"


void SolveBateman ::SetListOfNuclei(vector<Nucleus*> list)
	{
	fNuclList = list;
	}

void SolveBateman::SetIJ(int i_j)
	{
	fIJ=i_j;
	}

int SolveBateman::GetIJ()
	{
  return fIJ;
	}

NumericalMethod* nm = new NumericalMethod("RK4");

/*former function used to return the half life
double lambda(double T_12)
	{
	double lambda = log(2)/T_12;
	return lambda;
}*/

double pas= 36000;

void SolveBateman ::Process()
	{
	int i,IJ,t;
	double check;
	IJ = GetIJ();
	double *M_dt=new double[IJ-1]; //Time Matrix
	double *V_Ni=new double[IJ]; //Cores Matrix

	for(i=0 ; i < (IJ-1) ; i++)
		{
		M_dt[i]= fNuclList[i]->Getlambda(); //Fill up the Time matrix in function of lambdas
		cout<<M_dt[i]<<endl;
		}


	V_Ni[0]=pow(10,8);
	double **M_lamb = new double*[IJ];

	//Init
	for(i=0;i<IJ;++i)
    {
		M_lamb[i]=new double [IJ];
		if(i==0)
			{
			M_lamb[i][i]=(-1)*M_dt[0];
			M_lamb[i][i+1]=0;
			}
		else
			{
			if(i==IJ-1)
				{
				M_lamb[i][i]=0;
				M_lamb[i][i-1]= M_dt[i-1];
				}
			else
				{
				M_lamb[i][i] = (-1)*M_dt[i];
				M_lamb[i][i-1]= M_dt[i-1];
				}
			}
		}

  //Time loop
	for (t=0 ; t <= 350*24*60*60 ; t++)
		{
		for (i=0 ; i<IJ ; i++)
			{
			if(i==0)
				{
				V_Ni[0] = V_Ni[0] + nm->rk4(M_lamb[0][0],0,V_Ni[0],0);
				}
			else
				{
				V_Ni[i] = V_Ni[i] + nm->rk4(M_lamb[i][i],M_lamb[i][i-1],V_Ni[i],V_Ni[i-1]);
				}
			}
		if(t==0)
			{
			V_Ni[0]=pow(10,8);
			for(i=1; i < IJ ;i++)
				{
				V_Ni[i]=0;
				}
			}
		for (i=0 ; i < IJ ; i++)
			{
			cout<<"Le nombre de noyau(x) du " << fNuclList[i]->Getname() <<"  à t = "<<t*180<<" secondes vaut : "<<V_Ni[i]<<endl;
			check=V_Ni[0]+V_Ni[1]+V_Ni[2]+V_Ni[3]+V_Ni[4]+V_Ni[5]+V_Ni[6]+V_Ni[7];
			cout << "Somme des noyaux = " << check << endl;
			}
		//ISSUE : Check = 10^7 whereas we should have Check = 10^8 (init value)
		}
		}
