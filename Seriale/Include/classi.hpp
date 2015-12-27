#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>

using namespace std;

//matrici in base 1

//blue scritta per colonna
//primo indice colonna inserito numero di riga
class BLUE{
private:
    vector< vector<int> > Blue;
    int N_col=0;
public:
    int exist(int row, int col);
    void add(int row, int col);
    void update(vector<int>::iterator point ,int col, int N_row);
    int operator[] (int i) {return Blue[i-1][0];};
    vector<int>::iterator begin (int col) {return Blue[col-1].begin();};
    vector<int>::iterator end (int col) {return Blue[col-1].end();};
};

//rossa scritta per riga
//primo indice riga inserito numero colonna
class RED{
private:
    vector< vector<int> > Red;
    int N_row=0;
public:
    int exist(int row, int col);
    void add(int row, int col);
    void update(vector<int>::iterator point ,int row, int N_col);
    int operator[] (int i) {return Red[i-1][0];};
    vector<int>::iterator begin (int row) {return Red[row-1].begin();};
    vector<int>::iterator end (int row) {return Red[row-1].end();};
 };

class Matrix{
	private:
                BLUE blue; //primo indice da colonna
                RED red;  //primo indice da riga
		int N_col=0;
		int N_row=0;
                bool move_blue=true;
	public:
                Matrix(string input);
                void print(string output, int first, int iteration);
                void update(int iteration);
};

