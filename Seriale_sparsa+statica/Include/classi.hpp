#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>

using namespace std;


class Matrix{
	private:
        vector<int> data; //dimensione N_rowxN_col seganata per righe
        vector<int> Blue; // segnati a coppie di due adiacenti, il primo e la riga e il secondo la colonna
        vector<int> Red; //  segnati a coppie di due adiacenti, il primo e la riga e il secondo la colonna
        int         N_row=0;
        int         N_col=0;
        bool        move_blue=true;
	public:
                Matrix(string input);
                void print(int iteration);
                void update(int iteration);
};

