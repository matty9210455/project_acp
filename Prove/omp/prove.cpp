#include"omp.h"
#include<iostream>
#include<vector>

using namespace std;

/*int main(){
#pragma omp parallel num_threads(5)
{
int n_thread=omp_get_thread_num();
if(n_thread==0) cout<<n_thread<<endl;
#pragma omp barrier

if(n_thread==1) cout<<n_thread<<endl;
#pragma omp barrier


if(n_thread==2) cout<<n_thread<<endl;
#pragma omp barrier


if(n_thread==3) cout<<n_thread<<endl;
#pragma omp barrier


if(n_thread==4) cout<<n_thread<<endl;
#pragma omp barrier
}
}*/

int main(){
vector<int> v;
for(int k=1;k<23;k++) v.push_back(k);
#pragma omp parallel num_threads(4)
{
int n_thread=omp_get_thread_num();
int n_tot=omp_get_num_threads();
for(int j=n_thread;j<v.size();j=j+n_tot){
for(int i=0; i<n_tot; i++){
    if(n_thread==i) {cout<<v[j]<<" num thread "<<n_thread<<endl;}
    #pragma omp barrier
}
}
}
}
