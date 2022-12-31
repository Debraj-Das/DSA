// vector assignment
#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> &vec)
{
  const int n = vec.size();
  for(int i = 0;i<n;++i)
  {
     cout<<((i%10 == 0)?"\n":" ") << vec[i] ;
  }
    cout<<endl ;
    return ;
}

int main()
{
    vector<int> foo(3, 2);
    vector<int> bar(foo);   /// copy constractor
 
    // bar = foo;           //*  assign operator in vector STL.
    // foo = vector<int>(); //@ similare here declear a new vector and assign it.

     display(bar);
     display(foo);
    cout << "Size of foo: " << int(foo.size()) << '\n';
    cout << "Size of bar: " << int(bar.size()) << '\n';
    return 0;
}