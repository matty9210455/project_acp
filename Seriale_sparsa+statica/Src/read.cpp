#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<classi.hpp>

using namespace std;

Matrix::Matrix(string input){
        int value;
        string s;
        ifstream f(input,ios::in);
        //salto riga iterazioni
        getline(f,s);
        //indice riga che sto leggendo
        //trovo dimensione matrice
        bool first=true;
        while(getline(f,s)){
            if(first){
                for(auto it=s.begin();it<s.end();it++){//prima riga
                    N_col=N_col+1;//indice colonna
                    it++; //vado su virgola
                }
            }
            first=false;
            N_row=N_row+1;
        }
	f.close();

	vector<int> aux(N_row*N_col);

	f.open(input,ios::in);
	//salto iterazioni
	getline(f,s);
    int col=0;
    int row=0;
    while(getline(f,s)){
        col=0;
        for(auto it=s.begin();it<s.end();it++){//prima riga
                value=atoi(&(*it));
                aux[col+row*N_col]=value;
                if(value==1){
                    Blue.push_back(row);
                    Blue.push_back(col);
                }else{
                    if(value==2){
                        Red.push_back(row);
                        Red.push_back(col);
                    }else{
                        if(value!=0) {
                        cout<<"dato anomalo"<<endl;
                        exit(1);
                        }
                    }
                }
                col=col+1;//indice colonna
                it++; //vado su virgola
            }
                if(col!=N_col){
                    cout<<"numero di colonne sbagliato: colonne lette "<<col<<", colonne attese "<<N_col<<endl;
                    exit(1);
                }
                row=row+1;
    }
	f.close();
	data=aux;

};




