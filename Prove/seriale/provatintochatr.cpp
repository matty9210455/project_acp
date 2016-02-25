/* itoa example */
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main ()
{
  int i;
string Result;

stringstream convert; 



Result = convert.str();
  std::string buffer ;
  printf ("Enter a number: ");
  scanf ("%d",&i);
  convert << i;
buffer=convert.str();
  buffer.push_back('.');
  buffer.push_back('c');
  buffer.push_back('s');
  buffer.push_back('v');
std::cout<<buffer<<endl;
  return 0;
}
