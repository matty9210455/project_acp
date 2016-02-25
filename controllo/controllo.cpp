#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>

using namespace std;

int main(){
    int value;
    string s_mie;
    string s_prof;
    ifstream f_mie("3.csv",ios::in);
    ifstream f_prof("problem.csv",ios::in);
	vector< vector<int> > mie;
	vector< vector<int> > prof;
	getline(f_prof,s_prof);
    while(getline(f_mie,s_mie) && getline(f_prof,s_prof)){
        vector<int> aux_1;
        vector<int> aux_2;
        for(string::iterator it=s_mie.begin();it<s_mie.end();it++){//prima riga
            value=atoi(&(*it));
            aux_1.push_back(value);
        }
        for(string::iterator it=s_prof.begin();it<s_prof.end();it++){//prima riga
            value=atoi(&(*it));
            aux_2.push_back(value);
        }
        mie.push_back(aux_1);
        prof.push_back(aux_2);
    }
	f_mie.close();
	f_prof.close();
	int N_1=mie.size();
	int N_2=prof.size();
    for(int i=0;i<N_1;i++){
        for(int j=0;j<N_2;j++){
            if(mie[i][j]-prof[i][j]!=0){
                cout<<"no riga "<<i<<" colonna "<<j<<endl;
            }
        }

    }
return 0;
};

