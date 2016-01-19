#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<classi.hpp>
#include<string>


using namespace std;



int main (){

    vector<int> iteration;


    //iterazioni

    int value;

    //apertura e controllo file
    string input("problem.csv");
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
            while((*it)!=','&& it<s.end()) it++;
    }
    f.close();

    Matrix A(input);

    auto N=iteration.size();
    if(N==0){
        cout<<"non ho iterazioni"<<endl;
        exit(1);
    }
        A.print(0);
    A.update(iteration[0]);
    A.print(iteration[0]);
    for (unsigned int i=1;i<N;i++){
    A.update(iteration[i]-iteration[i-1]);
    A.print(iteration[i]);
    }

	return 0;
};


