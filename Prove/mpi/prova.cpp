#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<string>

using namespace std;

void riempovector(vector<int>* v){
int N=(*v).size();
for(int i=0;i<5;i++ ){
    (*v).push_back(N+i);
}
}


int main(){
vector<int> aux;
riempovector(&aux);
riempovector(&aux);
riempovector(&aux);
int N=aux.size();
for (int j=0;j<N;j++) cout<<aux[j]<<" ";
cout<<endl;

}
