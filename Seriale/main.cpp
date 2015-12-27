#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<classi.hpp>
#include<string>


using namespace std;



int main (){

    vector<int> iteration;
    string input("prova.txt");

    //iterazioni

    int value;

    //apertura e controllo file
    ifstream f(input);
    string s;
    if(!f){//check file giusto
            cout<<"file non esiste"<<endl;
            return 0;
    }

    //numero iterazioni
    getline(f,s);
    for(auto it=s.begin();it<s.end();it++){//iterazioni
            value=atoi(&(*it));
            iteration.push_back(value);
            it++;
    }
    f.close();
        Matrix A(input);
        A.print();
    for (int i=0;i<iteration.size();i++){
    cout<<iteration[i]<<endl;
    A.update(iteration[i]);
    A.print();
    }
	return 0;
};


