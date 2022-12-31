#include <iostream>


using namespace std ;

 int* swap_pointer(int *a, int *b)   // return a address.
{
  return a ;
}
 
int & swap_referce(int &a,int &b)   // return reference of a ;
{
  return a ;
}

int main()
 {
  int* p ,q ;      //this declaration only p is int pointer but q in simple int variable.
  cout<<"size of q = "<<sizeof(q)<<endl; 

  int a = 0 , b = 0 ;
  *swap_pointer(&a,&b)=25 ;
  cout<<"play with function by pointer, a = "<<a<< " b = "<< b <<endl ;
  *swap_pointer(&b,&a)=16  ;
  cout<<"play with function by pointer, a = "<<a<< " b = "<< b <<endl ;
   
   a = 0 ;
   b = 0 ;
   swap_referce(a,b) = 156 ;
  cout<<"play with function by pointer, a = "<<a<< " b = "<< b <<endl ;
   swap_referce(b,a) = 165 ;
  cout<<"play with function by pointer, a = "<<a<< " b = "<< b <<endl ;
  
  return 0;
 }