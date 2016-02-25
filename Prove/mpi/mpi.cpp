#include <mpi.h>
#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char ** argv ){
MPI_Init(&argc, &argv);

    int n_pr;
    MPI_Comm_rank(MPI_COMM_WORLD, &n_pr);
    int p;
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    vector< vector<int> > A;
    int buf;

if(n_pr==0){
    for(int i=0;i<5;i++){
        vector<int> v;
        for(int j=0;j<3; j++){
            v.push_back(j+i*3);
        }
        A.push_back(v);
    }
    cout<<"ok num proc "<<n_pr<<endl;
}

MPI_Barrier(MPI_COMM_WORLD);
/*
for(int j=0;j<p;j++){
    if (n_pr==j) {cout<<"num processore "<<n_pr<<endl;}
    MPI_Barrier(MPI_COMM_WORLD);
}
*/



for(int i=0;i<5;i++){
    vector<int> v;
        for(int j=0;j<3;j++){
            if(n_pr==0) buf=A[i][j];
            MPI_Bcast( &buf,1, MPI_INT, 0, MPI_COMM_WORLD);
            if(n_pr!=0) v.push_back(buf);
        }
        if(n_pr!=0) A.push_back(v);
}

MPI_Barrier(MPI_COMM_WORLD);
int row=0;
int j=1;
while(row<5){
if(n_pr==j){
    for(int i=0;i<3;i++){
        cout<<A[row][i]<<" ";
    }
    cout<<"processore "<<n_pr<<endl;
}

    if(j<p-1) j++;
    else j=1;
row++;
MPI_Barrier(MPI_COMM_WORLD);
}



MPI_Finalize();
/*
for(int i=0;i<5;i++){
    vector<int> v;
    for(int j=0;j<3; j++){
        cout<<A[i][j]<<" ";
    }
    cout<<endl;*/
}


