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
    int N_col;
public:
    BLUE(){N_col=0;}
    int exist(int row, int col);
    void add(int row, int col);
    void add_last_col(int Col);
    void update(int point ,int col, int N_row);
    int operator[] (int i) {return Blue[i-1][0];};
    vector<int>::iterator begin (int col) {return Blue[col-1].begin();};
    vector<int>::iterator end (int col) {return Blue[col-1].end();};
    int size(int col) {return Blue[col-1].size();};
    int element(int col, int j) {return Blue[col-1][j];};
};

//rossa scritta per riga
//primo indice riga inserito numero colonna
class RED{
private:
    vector< vector<int> > Red;
    int N_row;
public:
    RED(){N_row=0;}
    int exist(int row, int col);
    void add(int row, int col);
    void add_last_row(int Row);
    void update(int point ,int row, int N_col);
    int operator[] (int i) {return Red[i-1][0];};
    vector<int>::iterator begin (int row) {return Red[row-1].begin();};
    vector<int>::iterator end (int row) {return Red[row-1].end();};
    int element(int row, int j) {return Red[row-1][j];};
    int size(int row) {return Red[row-1].size();};
 };

class Matrix{
	private:
                BLUE blue; //primo indice da colonna
                RED red;  //primo indice da riga
                int N_col;
                int N_row;
                bool move_blue;
	public:
                Matrix(){N_col=0; N_row=0; move_blue=true;}
                int get_N_row(){return N_row;};
                int get_N_col(){return N_col;};
                void update_N_row(int n){N_row=n;};
                void update_N_col(int n){N_col=n;};
                int red_size(int row){return red.size(row);}
                int red_element(int row, int j){return red.element(row,j);};
                void red_add(int row, int col){red.add(row,col);};
                int blue_size(int col){return blue.size(col);}
                int blue_element(int col, int j){return blue.element(col,j);};
                void blue_add(int row, int col){blue.add(row,col);};
                void compile(string input);
                void print(int iteration);
                void update(int iteration);
                void transfer(int root);
                void update(vector<int>& v, bool blu);
                void update_who_move(){if(move_blue) move_blue=false;
                                        else move_blue=true;};
                bool who_move(){return move_blue;};
                void update_blue(int col, vector<int> * v);
                void update_red(int row, vector<int> * v);
};

