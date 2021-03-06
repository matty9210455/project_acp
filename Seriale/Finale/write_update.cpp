#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<classi.hpp>
#include<string>
#include<sstream>
#include<algorithm>

//ritorn 1 se ho elemento
int BLUE::exist(int row, int col){
    if(binary_search(Blue[col-1].begin(),Blue[col-1].end(),row)) return 1;
    return 0;
}

//ritorn 1 se ho elemento
int RED::exist(int row, int col){
    if(binary_search(Red[row-1].begin(),Red[row-1].end(),col)) return 1;
    return 0;
}


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



//passo iterator dell'elemento da modificare e l'indice di colonna se ritorna alla prima riga
void BLUE::update(vector<int>::iterator point ,int col, int N_row){
    if((*point)<N_row){
        (*point)=(*point)+1;
        return;
    }else{
        int N=Blue[col-1].size();
        vector<int> aux(N);
        aux[0]=1;
        for(int i=1;i<N;i++){
            aux[i]=Blue[col-1][i-1];
            Blue[col-1][i-1]=aux[i-1];
        }
        Blue[col-1][N-1]=aux[N-1];
        return;
    }

}



//passo iterator dell'elemento da modificare e l'indice di riga se ritorna alla prima colonna
void RED::update(vector<int>::iterator point ,int row, int N_col){
    if((*point)<N_col) {
        (*point)=(*point)+1;
        return;
    }else{
        int N=Red[row-1].size();
        vector<int> aux(N);
        aux[0]=1;
        for(int i=1;i<N;i++){
            aux[i]=Red[row-1][i-1];
            Red[row-1][i-1]=aux[i-1];
        }
        Red[row-1][N-1]=aux[N-1];
        return;
    }
}


void Matrix::update(int iteration){
    for(int it=0;it<iteration;it++){
        vector<int> position;
        vector< vector<int>::iterator> points;
        if(move_blue){
            for(int j=1;j<=N_col;j++){
                if(blue[j]!=0){
                    auto last=blue.end(j);
                    for(auto i=blue.begin(j);i<last;i++){
                        if((*i)<N_row){
                            int r=red.exist((*i)+1,j);
                            int b=blue.exist((*i)+1,j);
                            if(r+b==0){
                                points.push_back(i);
                                position.push_back(j);
                            }
                        }else{
                            int r=red.exist(1,j);
                            int b=blue.exist(1,j);
                            if(r+b==0){
                                points.push_back(i);
                                position.push_back(j);
                            }
                        }
                    }
                }
            }
            //aggiornamento
            int N_move=position.size();
            for(int k=0;k<N_move;k++){
                blue.update(points[k],position[k],N_row);
            }
            //cambio iterazione
            move_blue=false;
        }else{
            for(int i=1;i<=N_row;i++){
                if(red[i]!=0){
                    auto last=red.end(i);
                    for(auto j=red.begin(i);j<last;j++){
                        if((*j)<N_col){
                            int r=red.exist(i,(*j)+1);
                            int b=blue.exist(i,(*j)+1);
                            if(r+b==0){
                                points.push_back(j);
                                position.push_back(i);
                            }

                        }else{
                            int r=red.exist(i,1);
                            int b=blue.exist(i,1);
                            if(r+b==0){
                                points.push_back(j);
                                position.push_back(i);
                            }
                        }
                    }
                }
            }
            //aggiornamento
            int N_move=position.size();
            for(int k=0;k<N_move;k++){
                red.update(points[k],position[k],N_col);
            }
            //cambio iterazione
            move_blue=true;
        }
    }
}
