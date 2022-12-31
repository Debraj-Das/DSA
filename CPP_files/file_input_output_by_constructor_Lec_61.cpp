#include <iostream>
#include <fstream>

using namespace std ;

int main()
 {
  ofstream fout("new.txt");
  string st ;
  cout << "Enter your name "<<endl ;
  cin>>st ;
  fout<<st+" is user name." ;
  fout.close();
  st = "not take";
  ifstream fin("new.txt");
  fin>>st ;
  cout <<st<<" good morning!!"<<endl ;
  fin.close();
  return 0;
 }