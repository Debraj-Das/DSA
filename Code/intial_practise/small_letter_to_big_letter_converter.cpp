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
    for(int i = 0;s[i]!='\0';++i)
      if(s.at(i)>96&& s.at(i)<123)  s.at(i)-=32 ;
    cout <<"string after change\n\t"<< s <<endl ;
  
  return 0;
 }