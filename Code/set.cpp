#include <iostream>
#include <set>
using namespace std ;

int main()
{
    set<int> v = {10 , 20 , 40 , 90};
    v.insert(25);
    v.insert(70);
    printf("iterator using iterator ::\n");
    set<int> :: iterator itr ;
    for(itr = v.begin();itr != v.end();++itr)
    cout<<*itr<<endl;
    cout<<endl<<endl;
    v.insert(25);
    printf("iterator using each loop::\n");
    for(int x:v)
    cout<<x<<endl;
    
    return 0 ;
}