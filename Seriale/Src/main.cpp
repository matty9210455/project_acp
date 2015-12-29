#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<classi.hpp>
#include<string>


using namespace std;



int main (int argc, char* argv[]){

    vector<int> iteration;

    
    //iterazioni

    int value;

    //apertura e controllo file
    if(argc<3){	
		if(argc<2){
    		cout<<"non ho nome file input"<<endl;
    		return 0;
		}
		cout<<"non ho nome file output"<<endl;
		//return 0;	
	}	
	
    ifstream f(argv[1]);
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

        Matrix A(argv[1]);
    
	    A.print(argv[2],1,0);
    auto N=iteration.size();
    for (unsigned int i=0;i<N;i++){
    A.update(iteration[i]);
    A.print(argv[2],0,iteration[i]);
    }
	return 0;
};


