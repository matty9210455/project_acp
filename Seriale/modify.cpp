#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<classi.hpp>

using namespace std;

int search(vector< vector<int> >& A, int row, int el){
    int move; // quanto tolgo o metto
    int n(0);//indice in cui cerco
    int i(row-1);
    move=A[i].size()/2;
    n=move;
    if(n==0) return A[i][0]==el;
    while(move!=0){
        if(A[i][n]==el) return 1;
        if(A[i][n]<el) n=n+move;
        else n=n-move;
        move=move/2;
    }
    if(A[i][0]==el) return 1;
    if(A[i][A[i].size()-1]==el) return 1;

    /*int N=A[row-1].size();
    for(int i=0;i<N;i++){
        if(A[row-1][i]==el) return 1;
        if(A[row-1][i]>el) return 0;
    }*/
    return 0;
}

int check_blue(vector< vector<int> > & Blue, vector< vector<int> > & Red, int row, int col, int N_row){
	int start=row;
        if(row<=N_row-1){
                if(!search(Red,row+1,col)) return (!search(Blue,col,row+1))
	}else{
                if(!search(Red,1,col)) return (!search(Blue,col,1))
	}
        return 1;
}

int check_red(vector< vector<int> > & Blue, vector< vector<int> > & Red, int row, int col, int N_col){
	int start=col;
	if(col<N_col-1){
                if(!search(Blue,col+1,row)) return (!search(Red,row,col+1))
	}else{
                if(!search(Blue,1,row)) return (!search(Red,row,1))
	}
        return 1;
};



void Matrix::modify(int iteration){
                for(int i=0;i<iteration;i++){
                        vector<point> v;
			//sposto blu
                        if(move_blu){
				//segno chi sposto
                            for(int j=1;j<=N_col;j++)
				// rendo vuote le caselle dove macchina si sposta
				for(int j=0;j<N_blue;j++){
					if(v[j]==1) A[blue[j].row()][blue[j].col()]=0;
				}
				// aggiorno i punti nel vector points e aggiorno matrice con nuove pos
				for(int j=0;j<N_blue;j++){
					if(v[j]==1){
						blue[j].upgrade_blue(N_row);
						A[blue[j].row()][blue[j].col()]=1;
					}
				}
			//sposto rosse
			}else{
                //segno chi sposto
				for(int j=0;j<N_blue;j++){
                   v.push_back(check_red(A,red[j].row(),red[j].col(),N_col));
                }
                // rendo vuote le caselle dove macchina si sposta
				for(int j=0;j<N_red;j++){
					if(v[j]==1) A[red[j].row()][red[j].col()]=0;
				}
				// aggiorno i punti nel vector points e aggiorno matrice con nuove pos
				for(int j=0;j<N_red;j++){
					if(v[j]==1){
						red[j].upgrade_red(N_col);
						A[red[j].row()][red[j].col()]=2;
                    }

                }
            }
        }


}




