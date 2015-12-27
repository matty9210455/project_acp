#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<classi.hpp>

using namespace std;


void BLUE::add(int row, int col){

    if(col>N_col){
        int j(N_col);
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
        int i(N_row);
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




Matrix::Matrix(string input){
        int value;
        string s;
        ifstream f(input);
	getline(f,s);
        getline(f,s);
        int first=1;
        int col(1); //indice colonna che sto leggendo
        int row(1); //indice riga che sto leggendo
	while(f.good()){
            for(auto it=s.begin();it<s.end();it++){//prima riga

                value=atoi(&(*it));
                if(value==1){
                    blue.add(row,col);
                }else{
                    if(value==2){
                        red.add(row,col);
                    }
                //controllo errore se diverso da 0
                }
                col+=1;//indice colonna
                it++; //vado su virgola
            }
            //controllo ho tutte colonne scritte
            if(first){
                N_col=col-1;
                first=0;
            }
            col=1;
            row+=1;
            N_row=row-1;
            getline(f,s);
	
	}

	f.close();
};




