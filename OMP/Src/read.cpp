#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<classi.hpp>

using namespace std;


void BLUE::add(int row, int col){

    if(col>N_col){
        int j(Blue.size());
        vector<int> aux{0};
        while(j<col-1){
            Blue.push_back(aux);
            j++;
        };
        aux[0]=row;
        Blue.push_back(aux);
        N_col=col;
        return;
    }else{
        if(Blue[col-1][0]!=0){
            Blue[col-1].push_back(row);
            return;
        }else{
            Blue[col-1][0]=row;
            return;
        }
    }
};


void RED::add(int row, int col){
    if(row>N_row){
        int i(Red.size());
        vector<int> aux{0};
        while(i<row-1){
            Red.push_back(aux);
            i++;
        }
        aux[0]=col;
        Red.push_back(aux);
        N_row=row;
        return;
    }else{
        if(Red[row-1][0]!=0){
            Red[row-1].push_back(col);
            return;
        }else{
            Red[row-1][0]=col;
            return;
        }
    }
};


void BLUE::add_last_col(int Col){
    while(N_col!=Col){
        vector<int> aux{0};
        Blue.push_back(aux);
        N_col=N_col+1;
    }
};

void RED::add_last_row(int Row){
    while(N_row!=Row){
        vector<int> aux{0};
        Red.push_back(aux);
        N_row=1+N_row;
    }
};

Matrix::Matrix(string input){
        int value;
        string s;
        ifstream f(input);
        getline(f,s);
        int first=1;
        int col(1); //indice colonna che sto leggendo
        int row(1); //indice riga che sto leggendo
	while(getline(f,s)){
            for(auto it=s.begin();it<s.end();it++){//prima riga

                value=atoi(&(*it));
                if(value==1){
                    blue.add(row,col);
                }else{
                    if(value==2){
                        red.add(row,col);
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
            if(first){
                N_col=col-1;
                first=0;
            }else{
                if(col!=N_col+1){
                    cout<<"numero di colonne sbagliato: colonne lette "<<col<<", colonne attese "<<N_col<<endl;
                    exit(1);
                }
            }
            col=1;
            N_row=row;
            row=row+1;
	}
	f.close();
	red.add_last_row(N_row);
	blue.add_last_col(N_col);
};




