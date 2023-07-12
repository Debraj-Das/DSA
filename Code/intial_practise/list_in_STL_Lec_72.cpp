#include <iostream>
#include <list>
using namespace std ;

void display(list<int> &lt)
{
    // const int n = lt.size();
    list<int> :: iterator iter ;
    
  for(iter = lt.begin();iter!= lt.end();++iter)
  {
     cout<<" "<< *iter ;
  }
    cout<<endl ;
    return ;
}

int main()
 {
    list<int> :: iterator iter ;
    int n ;
    cout<<"\nEnter the number of input for first list:: ";
    cin>>n ;
    list<int> lt1(n) ;
     for(iter = lt1.begin() ;iter!=lt1.end();++iter)
    {
         cin>>*iter ;
    }
    cout<<"contain in lt1 ::"<<endl ;
    display(lt1);
    lt1.reverse();
    cout<<"After reverse  :: "<<endl ;
    display(lt1);
    // lt1.sort();
    // cout<<"After sorted :: "<<endl ;
    // display(lt1);
    // lt1.reverse();
    cout<<"After reverse  :: "<<endl ;
    display(lt1);

    cout<<"\nEnter the number of input for second list:: ";
    cin>>n ;
    list<int> lt2(n) ;
    for(iter = lt2.begin() ;iter!=lt2.end();++iter)
    {
         cin>>*iter ;
    }
    cout<<"contain in lt2 ::"<<endl ;
    display(lt2) ;
    lt1.merge(lt2);
    cout<<"After mergeing :: "<<endl ;
    display(lt1);
    lt1.sort();
    cout<<"After sorted :: "<<endl ;
    display(lt1);
    return 0;
 }