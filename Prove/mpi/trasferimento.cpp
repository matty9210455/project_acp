



        //merge
        for (int proc=0; proc<p;proc++){
            int aux;
            vector<int> fix;
            int N;
            if(n_pr==proc) N=v.size();
            MPI_Bcast( &N,1, MPI_INT,proc, MPI_COMM_WORLD);
            for(int i=0;i<N;i++){
                if(n_pr==proc) aux=v[i];
                MPI_Bcast( &aux,1, MPI_INT,proc, MPI_COMM_WORLD);
                if(n_pr!=proc) fix.push_back(aux);
            }

            if(n_pr!=proc) A.update(fix,true);
            MPI_Barrier(MPI_COMM_WORLD);
        }
        A.update_who_move();
        for(int k=0;k<p;k++){
            if(n_pr==k ) cout<<"proc "<<k<<" "<<A.who_move()<<endl;
            MPI_Barrier(MPI_COMM_WORLD);
        }
    }else{
        vector<int> v;
        //controllo e aggiornamento a processore
        for(int row=n_pr+1; row<=N_row; row=row+p){
            A.update_red(row,&v);
        }

        MPI_Barrier(MPI_COMM_WORLD);
        //merge
        for (int proc=0; proc<p;proc++){
            int aux;
            vector<int> fix;
            int N;
            if(n_pr==proc) N=v.size();
            MPI_Bcast( &N,1, MPI_INT,proc, MPI_COMM_WORLD);
            for(int i=0;i<N;i++){
                if(n_pr==proc) aux=v[i];
                MPI_Bcast( &aux,1, MPI_INT,proc, MPI_COMM_WORLD);
                if(n_pr!=proc) fix.push_back(aux);
            }
            if(n_pr!=proc) A.update(fix,false);
            MPI_Barrier(MPI_COMM_WORLD);
        }
        A.update_who_move();
        for(int k=0;k<p;k++){
            if(n_pr==k ) cout<<"proc "<<k<<" "<<A.who_move()<<endl;
            MPI_Barrier(MPI_COMM_WORLD);
        }
    }
}

}















void update(Matrix &A, int iteration){

    int n_pr;//numero processore
    MPI_Comm_rank(MPI_COMM_WORLD, &n_pr);
    int p;//numero totali processori
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    int N_col=A.get_N_col();
    int N_row=A.get_N_row();

for(int it=0;it<iteration;it++){
    if(A.who_move()){
        vector<int> v;
        //controllo e aggiornamento a processore
        for(int col=n_pr+1; col<=N_col; col=col+p){
            A.update_blue(col,&v);
        }
        MPI_Barrier(MPI_COMM_WORLD);
        //merge
        for (int proc=0; proc<p;proc++){
            int aux;
            vector<int> fix;
            int N;
            if(n_pr==proc) N=v.size();
            MPI_Bcast( &N,1, MPI_INT,proc, MPI_COMM_WORLD);
            for(int i=0;i<N;i++){
                if(n_pr==proc) aux=v[i];
                MPI_Bcast( &aux,1, MPI_INT,proc, MPI_COMM_WORLD);
                if(n_pr!=proc) fix.push_back(aux);
            }

            if(n_pr!=proc) A.update(fix,true);
            MPI_Barrier(MPI_COMM_WORLD);
        }
        A.update_who_move();
        for(int k=0;k<p;k++){
            if(n_pr==k ) cout<<"proc "<<k<<" "<<A.who_move()<<endl;
            MPI_Barrier(MPI_COMM_WORLD);
        }
    }else{
        vector<int> v;
        //controllo e aggiornamento a processore
        for(int row=n_pr+1; row<=N_row; row=row+p){
            A.update_red(row,&v);
        }

        MPI_Barrier(MPI_COMM_WORLD);
        //merge
        for (int proc=0; proc<p;proc++){
            int aux;
            vector<int> fix;
            int N;
            if(n_pr==proc) N=v.size();
            MPI_Bcast( &N,1, MPI_INT,proc, MPI_COMM_WORLD);
            for(int i=0;i<N;i++){
                if(n_pr==proc) aux=v[i];
                MPI_Bcast( &aux,1, MPI_INT,proc, MPI_COMM_WORLD);
                if(n_pr!=proc) fix.push_back(aux);
            }
            if(n_pr!=proc) A.update(fix,false);
            MPI_Barrier(MPI_COMM_WORLD);
        }
        A.update_who_move();
        for(int k=0;k<p;k++){
            if(n_pr==k ) cout<<"proc "<<k<<" "<<A.who_move()<<endl;
            MPI_Barrier(MPI_COMM_WORLD);
        }
    }
}

}
