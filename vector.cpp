#include <iostream>
#include <vector>
using namespace std ;

int main()
{
    vector<int> v = {10 , 20 , 40 , 90};
    v.push_back(25);
    v.push_back(70);
    printf("iterator using iterator ::\n");
    vector<int> :: iterator itr ;
    for(itr = v.begin();itr != v.end();++itr)
    cout<<*itr<<endl;
    cout<<endl<<endl;
    v.pop_back();
    printf("iterator using each loop::\n");
    for(int x:v)
    cout<<x<<endl;
    
    return 0 ;
}