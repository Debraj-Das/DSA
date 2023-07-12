#include <iostream>


using namespace std ;

int main()
 {
   int room ;
   cout << "Enter the calculation room : ";
   cin >> room ;
   for(int i = 1 ; i<=10 ;++i)
     cout<<room<<"x"<<i<<" = "<<room*i<<endl ;
   
   return 0;
 }