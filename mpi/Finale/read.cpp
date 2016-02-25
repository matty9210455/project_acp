#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<classi.hpp>
#include<string>
#include<sstream>
#include <mpi.h>
using namespace std;


void BLUE::add(int row, int col){

    if(col>N_col){
        int j(Blue.size());
        vector<int> aux;
        aux.push_back(0);
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
        vector<int> aux;
        aux.push_back(0);
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
        vector<int> aux;
        aux.push_back(0);
        Blue.push_back(aux);
        N_col=N_col+1;
    }
};

void RED::add_last_row(int Row){
    while(N_row!=Row){
        vector<int> aux;
        aux.push_back(0);
        Red.push_back(aux);
        N_row=1+N_row;
    }
};

void Matrix::compile(string input_aux){
        int value;
        string s;

    int K=input_aux.size();
    char input[K];
    for(int i=0;i<K;i++){
    input[i]=input_aux[i];
    }
        ifstream f(input);
        if(!f){//check file giusto

            cout<<"file non esiste"<<endl;
            MPI_Finalize();
            exit(1);
        }
        getline(f,s);
        int first=1;
        int col(1); //indice colonna che sto leggendo
        int row(1); //indice riga che sto leggendo
	while(getline(f,s)){
            for(string::iterator it=s.begin();it<s.end();it++){//prima riga

                value=atoi(&(*it));
                if(value==1){
                    blue.add(row,col);
                }else{
                    if(value==2){
                        red.add(row,col);
                    }else{
                        if(value!=0) {
                        cout<<"dato anomalo"<<endl;
                        MPI_Finalize();
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
                    MPI_Finalize();
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


void Matrix::print(int iteration){
    string output;
    stringstream convert;
    convert<<iteration;
    output=convert.str();
    output.push_back('.');
    output.push_back('c');
    output.push_back('s');
    output.push_back('v');
    ofstream out;
    int K=output.size();
    char output_aux[K];
    for(int i=0;i<K;i++){
    output_aux[i]=output[i];
    }
    out.open(output_aux,ios::trunc);

    for(int i=1; i<=N_row;i++){
     for(int j=1; j<N_col;j++){
        int b=blue.exist(i,j);
        int r=red.exist(i,j);

        out<<b+2*r<<",";
        }
        int b=blue.exist(i,N_col);

        int r=red.exist(i,N_col);
        out<<b+2*r<<endl;
    }
    out.close();
 }
