#include <mpi.h>
#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char ** argv ){

MPI_Init(&argc, &argv);
int RIGHE=2;
    MPI_Status Stat;
    int n_pr;
    MPI_Comm_rank(MPI_COMM_WORLD, &n_pr);
    int p;
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    vector< vector<int> > A;
    int buf;
//riempimento fa solo il primo th
if(n_pr==0){
    for(int i=1;i<=RIGHE;i++){
        vector<int> v;
        for(int j=0;j<i; j++){
            v.push_back(j);
        }
        A.push_back(v);
    }
    cout<<"ok num proc "<<n_pr<<endl;
}

MPI_Barrier(MPI_COMM_WORLD);

/*
int N_row[RIGHE];
if(n_pr==0){
    for(int k=0;k<RIGHE;k++)
    N_row[k]=A[k].size();
}

for(int j=0;j<RIGHE;j++){
    for(int proc=1;proc<p;proc++){
        if (n_pr==0) MPI_Send(&N_row[j],1,MPI_INT,proc,MPI_ANY_TAG,MPI_COMM_WORLD);
        if(n_pr==proc) {
            int aux;
            MPI_Recv(&aux,1,MPI_INT,0,MPI_ANY_TAG,MPI_COMM_WORLD,&Stat);
            N_row[j]=aux;
        }
    }
}
*/
//Stampa prima volta
if(n_pr==0){
    for(int i=0;i<A.size();i++){
        vector<int> v;
        for(int j=0;j<A[i].size(); j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

MPI_Barrier(MPI_COMM_WORLD);

//invio colonne ai vari processori
int proc=1;
int aux;
int N_1=0;
vector<int> rows;
if(n_pr==0) rows.push_back(0);
for(int i=1;i<RIGHE;i++){
//processo diverso da zero
    if(proc!=0){
        //indice colonna che invio
        if(n_pr==0){
            N_1=A[i].size();
            MPI_Send(&i,1,MPI_INT,proc,MPI_ANY_TAG,MPI_COMM_WORLD);
            MPI_Send(&N_1,1,MPI_INT,proc,MPI_ANY_TAG,MPI_COMM_WORLD);
        }
        if(n_pr==proc) {
            MPI_Recv(&aux,1,MPI_INT,0,MPI_ANY_TAG,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            MPI_Recv(&N_1,1,MPI_INT,0,MPI_ANY_TAG,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            rows.push_back(aux);
        }
        //invio colonna
        if(n_pr==0){
            for(int j=0;j<N_1;j++){
                int aux=A[i][j];
                MPI_Send(&aux,1,MPI_INT,proc,MPI_ANY_TAG,MPI_COMM_WORLD);
            }
        }
        //ricevo colonna
        if(n_pr==proc){
            vector<int> aux2;
            A.push_back(aux2);
            int last=A.size();
            for(int j=0;j<N_1;j++){
                int aux;
                MPI_Recv(&aux,1,MPI_INT,0,MPI_ANY_TAG,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
                A[last-1].push_back(aux);
            }
        }
    //colonna del processore zero
    }else{
        if(proc==n_pr){
            rows.push_back(i);
        }
    }
    //aggiornamento
    if(proc<p-1){    proc++;
    }else{    proc=0;}
    MPI_Barrier(MPI_COMM_WORLD);
}

if(n_pr==0){
    for(int i=0;i<A.size();i++){
        vector<int> v;
        for(int j=0;j<A[i].size(); j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
MPI_Barrier(MPI_COMM_WORLD);
//aggiornamento su tutto
if(n_pr!=0){
    int N=rows.size();
    for(int i=0;i<N;i++){
        int K=A[i].size();
        for(int j=0;j<K;j++){
            A[i][j]=A[i][j]+1;
        }
    }
}else{
    int N=rows.size();
    for(int i=0;i<N;i++){
        int K=A[rows[i]].size();
        for(int j=0;j<K;j++){
            A[rows[i]][j]=A[rows[i]][j]+1;
        }
    }
}
MPI_Barrier(MPI_COMM_WORLD);

//ritorno indietro
for(int proc=1;proc<p;proc ++){
    if(n_pr==proc){
        int Le=A.size();
        for(int i=0;i<Le;i++ ){
            int K_l=A[i].size();
            int aux=rows[i];
            MPI_Send(&aux,1,MPI_INT,0,MPI_ANY_TAG,MPI_COMM_WORLD);
            for(int j=1;j<K_l;j++){
                aux=A[i][j];
                MPI_Send(&aux,1,MPI_INT,0,MPI_ANY_TAG,MPI_COMM_WORLD);
            }
        }

    }
    if(n_pr==0){
        int row;
        MPI_Recv(&row,1,MPI_INT,proc,MPI_ANY_TAG,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        int K_l=A[row].size();
        for(int j=0;j<K_l;j++){
            int aux;
            MPI_Recv(&aux,1,MPI_INT,proc,MPI_ANY_TAG,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            A[row][j]=aux;
        }

    }

}
MPI_Barrier(MPI_COMM_WORLD);
//stampa finale
if(n_pr==0){
for(int i=0;i<A.size();i++){
    vector<int> v;
    for(int j=0;j<A[i].size(); j++){
        cout<<A[i][j]<<" ";
    }
    cout<<endl;
}
}
MPI_Barrier(MPI_COMM_WORLD);
MPI_Finalize();



}

