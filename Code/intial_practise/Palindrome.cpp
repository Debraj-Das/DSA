#include <iostream>

using namespace std ;


int main()
 {
    string s ;
    cout<<"Enter the string :\n\t" ;
    cin>>s;
    const int n = s.length();
    for(int i =0 ;i<(n/2);++i)
    {
        if(s[i]!=s[n-i-1])
        {
            cout<<s<<" is not a Palindrome string."<<endl;
            exit(0);
        }
    }
    cout<<s<<" is a Palindrome string."<<endl;
    return 0;
 }