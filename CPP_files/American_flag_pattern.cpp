#include <iostream>

using namespace std;

void printequal(int n)
{
     for(int i =0 ; i<n;++i)
     cout<<"=";
     cout<<endl;
     return ;
}

int main()
{
     cout<<" Print the Ameriacn flag:"<<endl
          <<"----------------------------"<<endl;
     for(int i = 0 , j ;i<15;++i)
     {
          if(i<9)
          {
               for(j=0;j<11;++j)
               ((i+j)%2)?cout<<" ":cout<<"*";
               cout<<" ";
               printequal(33);
          }
          else 
               printequal(45);
     }

     return 0;
}