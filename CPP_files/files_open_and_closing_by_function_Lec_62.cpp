#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
  register int i;
  ofstream fout;
  fout.open("new.txt");  ///  use open function for open file.
  string st;
  cout << "Enter the number of line : ";
  cin >> i;
  cout << "Enter  lines " << endl;
  getline(cin, st);   //* this line because clean the buffer of previous input.
  while (i--)
  {
    cout << "\t";
    getline(cin, st);
    fout << st + "\n";
  }
  fout.close();   ///  use close function for close the file.
  cout<<endl ;
  ifstream fin;
  fin.open("new.txt");
  while (fin.eof() == 0)   ///  use eof function for check to end of files.
  {
    getline(fin, st);
    cout << st << endl;
  }
  fin.close();
  return 0;
}