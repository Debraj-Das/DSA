#include <iostream>
#include <forward_list>
using namespace std ;

int main()
{
    forward_list<int> v = {10 , 20 , 40 , 90};
    v.push_front(25);
    v.push_front(47);
    printf("iterator using iterator ::\n");
    forward_list<int> :: iterator itr ;
    for(itr = v.begin();itr != v.end();++itr)
    cout<<*itr<<endl;
    cout<<endl<<endl;
    v.pop_front();
    printf("iterator using each loop::\n");
    for(int x:v)
    cout<<x<<endl;
    
    return 0 ;
}