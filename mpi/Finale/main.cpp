#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<classi.hpp>
#include<string>
#include <mpi.h>

using namespace std;

void update(Matrix &A,int n_pr,int p, vector<int>* rossi, vector<int>* blu){
    int N_row=A.get_N_row();
    int N_col=A.get_N_col();
        if(A.who_move()){
        //controllo e aggiornamento a processore
            for(int col=n_pr+1; col<=N_col; col=col+p){
                A.update_blue(col,blu);
            }
        }else{
            for(int row=n_pr+1;row<=N_row;row=row+p)
                A.update_red(row,rossi);
        }
        A.update_who_move();
}

void transfer(vector<int>* recv, int root,int n_pr, vector<int>& send ){
    int aux;
    int N;
    if(n_pr==root){ N=send.size();}
    MPI_Bcast( &N,1, MPI_INT,root, MPI_COMM_WORLD);
    for(int j=0;j<N;j++){
        if(n_pr==root){ aux=send[j];}
        MPI_Bcast(&aux,1, MPI_INT,root, MPI_COMM_WORLD);
        if(n_pr!=root){ (*recv).push_back(aux);}
    }

}

void transfer(Matrix &A, int root){
    int n_pr;//numero processore
    MPI_Comm_rank(MPI_COMM_WORLD, &n_pr);
    int p;//numero totali processori
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    int N_row;
    int N_col;
    if(n_pr==0){
        N_row=A.get_N_row();
        N_col=A.get_N_col();
    }

    MPI_Bcast( &N_row,1, MPI_INT,root, MPI_COMM_WORLD);
    MPI_Bcast( &N_col,1, MPI_INT,root, MPI_COMM_WORLD);

    if(n_pr!=0){
        A.update_N_row(N_row);
        A.update_N_col(N_col);
    }
    //mandiamo i red
    for(int row=1; row<=N_row; row++){
        int N;
        if(n_pr==root) {N=A.red_size(row);}
        MPI_Bcast( &N,1, MPI_INT,root, MPI_COMM_WORLD);
        for(int j=0;j<N;j++){
            int aux;
            if(n_pr==root) aux=A.red_element(row,j);
            MPI_Bcast( &aux,1, MPI_INT,root, MPI_COMM_WORLD);
            if(n_pr!=root) A.red_add(row,aux);
        }

    }


    for(int col=1; col<=N_col; col++) {
        int N;
        if(n_pr==root) {N=A.blue_size(col);}
        MPI_Bcast( &N,1, MPI_INT,root, MPI_COMM_WORLD);
        for(int j=0;j<N;j++){
            int aux;
            if(n_pr==root) aux=A.blue_element(col,j);
            MPI_Bcast( &aux,1, MPI_INT,root, MPI_COMM_WORLD);
            if(n_pr!=root) A.blue_add(aux,col);
        }

    }
}


int main (int argc, char ** argv){
    MPI_Init(&argc, &argv);
    //parte processori
    int n_pr;//numero processore
    MPI_Comm_rank(MPI_COMM_WORLD, &n_pr);
    int p;//numero totali processori
    MPI_Comm_size(MPI_COMM_WORLD, &p);


    vector<int> iteration;
    Matrix A;

    if(n_pr==0){
    //iterazioni

    int value;

    //apertura e controllo file
    string input_aux("problem.csv");
    int K=input_aux.size();
    char input[K];
    for(int i=0;i<K;i++){
    input[i]=input_aux[i];
    }
    ifstream f(input);
    string s;
    if(!f){//check file giusto

            cout<<"file non esiste"<<endl;
            MPI_Finalize();
            return 0;
    }

    //numero iterazioni
    getline(f,s);
    for(string::iterator it=s.begin();it<s.end();it++){//iterazioni
            value=atoi(&(*it));
            iteration.push_back(value);
            while((*it)!=','&& it<s.end()) it++;
    }
    f.close();

    A.compile(input_aux);
    }
    transfer(A,0);

    A.print(n_pr);
    //trasferisco iterazioni
    int N_it=0;
    if(n_pr==0) N_it=iteration.size();
    MPI_Bcast( &N_it,1, MPI_INT,0, MPI_COMM_WORLD);
    for(int i=0;i<N_it;i++){
        int aux;
        if(n_pr==0) aux=iteration[i];
        MPI_Bcast( &aux,1, MPI_INT,0, MPI_COMM_WORLD);
        if(n_pr!=0) iteration.push_back(aux);
    }
    MPI_Barrier(MPI_COMM_WORLD);

    if(N_it==0){
        cout<<"non ho iterazioni"<<endl;
        MPI_Finalize();
        exit(1);
    }
    MPI_Barrier(MPI_COMM_WORLD);
//update
int iter;
iter=iteration[0];
for(int it=0;it<iter;it++){
    vector<int> rossi;
    vector<int> blu;
    vector<int> fix_blu;
    vector<int> fix_rossi;

    update(A,n_pr,p,&rossi,&blu);
    MPI_Barrier(MPI_COMM_WORLD);

    for( int proc=0; proc<p;proc++){
        transfer(&fix_blu, proc, n_pr, blu );
        transfer(&fix_rossi, proc, n_pr, rossi );
    }

    MPI_Barrier(MPI_COMM_WORLD);
    A.update(fix_blu,true);
    A.update(fix_rossi,false);

}
    MPI_Barrier(MPI_COMM_WORLD);
    if(n_pr==0) A.print(iteration[0]);

    for (unsigned int i=1;i<N_it;i++){
        iter=iteration[i]-iteration[i-1];
        for(int it=0;it<iter;it++){
            vector<int> rossi;
            vector<int> blu;
            vector<int> fix_blu;
            vector<int> fix_rossi;

            update(A,n_pr,p,&rossi,&blu);
            MPI_Barrier(MPI_COMM_WORLD);

            for( int proc=0; proc<p;proc++){
                transfer(&fix_blu, proc, n_pr, blu );
                transfer(&fix_rossi, proc, n_pr, rossi );
            }

            MPI_Barrier(MPI_COMM_WORLD);
            A.update(fix_blu,true);
            A.update(fix_rossi,false);

        }
        MPI_Barrier(MPI_COMM_WORLD);
        if(n_pr==0) A.print(iteration[i]);
    }

    MPI_Finalize();
	return 0;
};






