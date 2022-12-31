#include <iostream>
using namespace std ;

int main()
{
    string text ;
    text = "My name is Debraj Das";
    cout<<"Length of lenth is "<<text.length()<<endl;
    string in ;
    getline(cin , in);
    cout<<in.substr(4,5)<<endl;
    text.push_back('\t');
    text.append(in);
    text.insert(7,"insert");
    cout<<endl<<text<<endl;
    
    return 0 ;
}