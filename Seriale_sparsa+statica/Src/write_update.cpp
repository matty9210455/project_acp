#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<classi.hpp>
#include<string>
#include<sstream>



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
    out.open(output,ios::trunc);

    for(int i=0; i<N_row;i++){
     for(int j=0; j<N_col-1;j++){

        out<<data[j+N_col*i]<<",";
        }
        out<<data[N_col*(i+1)-1]<<endl;
    }
    out.close();
 }





void Matrix::update(int iteration){
    int N_blue=Blue.size();
    int N_red=Red.size();
    for(int it=0;it<iteration;it++){
        vector<int> position_in_data;//metto posizione nei dati da azzerare
        if(move_blue){
        vector<int> move_blu;
            for(int j=0;j<N_blue-1;j=j+2){
                int row=Blue[j];
                int col=Blue[j+1];
                if(row<N_row-1){//non è ultima riga
                    if(data[col+(row+1)*N_col]==0){
                        Blue[j]=Blue[j]+1;//update
                        move_blu.push_back(j);
                        position_in_data.push_back(col+row*N_col);
                    }
                }else{//è ultima riga
                    if(data[col]==0){
                        Blue[j]=0;//update
                        move_blu.push_back(j);
                        position_in_data.push_back(col+row*N_col);
                    }
                }
            }
            //aggiornamento
            int N_move=position_in_data.size();
            for(int k=0;k<N_move;k++){
                int pos_data=position_in_data[k];
                int j=move_blu[k];
                data[pos_data]=0;
                if(Blue[j]==0){
                    data[Blue[j+1]]=1;
                }else{
                    data[pos_data+N_col]=1;
                    }
                }
            //cambio iterazione
            move_blue=false;
        }else{
            vector<int> move_red;
            for(int j=0;j<N_red-1;j=j+2){
                int row=Red[j];
                int col=Red[j+1];
                if(col<N_col-1){
                    if(data[col+row*N_col+1]==0){
                        Red[j+1]=Red[j+1]+1;
                        move_red.push_back(j+1);
                        position_in_data.push_back(col+row*N_col);
                    }
                }else{
                    if(data[row*N_col]==0){
                        Red[j+1]=0;
                        move_red.push_back(j+1);
                        position_in_data.push_back(col+row*N_col);
                    }
                }
            }
            //aggiornamento
            int N_move=position_in_data.size();
            for(int k=0;k<N_move;k++){
            int j=move_red[k];
            int pos_data=position_in_data[k];
                data[pos_data]=0;
                if(Red[j]==0){
                    data[Red[j-1]*N_col]=2;
                }else{
                    data[pos_data+1]=2;
                    }
                }

            //cambio iterazione
            move_blue=true;
        }
    }
}
