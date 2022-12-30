#include <iostream>
#include <vector>

using namespace std ;

template <class T>
void display(vector<T> &vec )
{
     const int n = vec.size();
     cout<<endl ;
    for(register int i = 0; i<n ;++i)
    {
        cout<<((i%10 == 0)?"\n":" ")<<vec[i];
    }
    cout<<endl ;
    return ;
}

int main()
 {
    int i ;
    vector<int> vec1(65,156);
    display(vec1);
    cout<<"size of vector :: "<<vec1.size() ;
    vec1.push_back(4);
    vector<int> ::iterator iter = vec1.begin() ;
    for(i=0 ; i<6 ;++i)
    {
        vec1.insert(iter+5*i,i);
    }
    display(vec1);
    for(i = 0 ; i<60 ;++i)
    vec1.pop_back();
    display(vec1);
    cout<<"size of vector :: "<<vec1.size()<<endl ;

    return 0;
 }