#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<classi.hpp>
#include<string>
#include<sstream>
#include <mpi.h>
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

//passo iterator dell'elemento da modificare e l'indice di colonna se ritorna alla prima riga
void BLUE::update(int point ,int col, int N_row){
    if(Blue[col-1][point]<N_row){
        Blue[col-1][point]=Blue[col-1][point]+1;
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
void RED::update(int point ,int row, int N_col){
    if(Red[row-1][point]<N_col) {
        Red[row-1][point]=Red[row-1][point]+1;
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

void Matrix::update_blue(int col, vector<int>* v){
    int N=blue.size(col);
    vector<int> aux_1;
        if(blue[col]!=0){
                    for(int i=0;i<N;i++){
                        int aux=blue.element(col,i);
                        if(aux<N_row){
                            int r=red.exist(aux+1,col);
                            int b=blue.exist(aux+1,col);
                            if(r+b==0){
                                (*v).push_back(i);
                                (*v).push_back(col);
                                aux_1.push_back(i);
                                aux_1.push_back(col);
                            }

                        }else{
                            int r=red.exist(1,col);
                            int b=blue.exist(1,col);
                            if(r+b==0){
                                (*v).push_back(i);
                                (*v).push_back(col);
                                aux_1.push_back(i);
                                aux_1.push_back(col);
                            }
                        }

                    }
        }
        int K;
        K=aux_1.size();
        for(int j=0;j<K-1;j=j+2){
            blue.update(aux_1[j],aux_1[j+1],N_row);
        }
}

void Matrix::update_red(int row, vector<int>* v){
        int N=red.size(row);
        vector<int> aux_1;
        if(red[row]!=0){
                    for(int i=0;i<N;i++){
                        int aux=red.element(row,i);
                        if(aux<N_col){
                            int r=red.exist(row,aux+1);
                            int b=blue.exist(row,aux+1);
                            if(r+b==0){
                                (*v).push_back(i);
                                (*v).push_back(row);
                                aux_1.push_back(i);
                                aux_1.push_back(row);
                            }

                        }else{
                            int r=red.exist(row,1);
                            int b=blue.exist(row,1);
                            if(r+b==0){
                                (*v).push_back(i);
                                (*v).push_back(row);
                                aux_1.push_back(i);
                                aux_1.push_back(row);
                            }
                        }

                    }
        }
        int K;
        K=aux_1.size();
        for(int j=0;j<K-1;j=j+2){
            red.update(aux_1[j],aux_1[j+1],N_col);
        }
}

void Matrix::update(vector<int>& v, bool blu){
    int N=v.size();
    if(blu){
        for(int i=0; i<N-1;i=i+2){
            blue.update(v[i],v[i+1],N_row);
        }
    }else{
        for(int i=0; i<N-1;i=i+2){
            red.update(v[i],v[i+1],N_col);
        }
    };
}


