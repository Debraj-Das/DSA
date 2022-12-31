#include <iostream>
#include <string>

using namespace std ;


int main()
 {
    string s ;
    cout <<"Enter the string :\n\t";
    cin>>s ;
    cout <<"string before change\n\t"<< s <<endl ;
    cout <<"Lenth of string is "<<s.length()<<endl ;
    
    register int  i , n ;
    n = 'a' - 'A' ;
    for( i = 0;s[i]!='\0';++i)
      if(s.at(i)>='a' && s.at(i)<='z')  s.at(i)-=n  ;
    cout <<"string after change\n\t"<< s <<endl ;
  
  return 0;
 }