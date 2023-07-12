#include <iostream>


using namespace std ;

 void swap_by_value(int x ,int y);
 void swap_by_referrence_by_pointer(int *x , int *y);
 void swap_by_referrence_by_reference(int &x ,int &y);


int main()
 {
   int a = 3 , b = 5 ;   // Here a and b are actuall parameter but x and y are formal parameter.
   cout<< "vaule of a = "<< a<< " value of b = "<<b<<endl ;
   swap_by_value(a,b);                       // call by value so no chance show in main function.
   cout<< "vaule of a = "<< a<< " value of b = "<<b<<endl ;  
   swap_by_referrence_by_pointer(&a,&b);     // call by refference by pointer so chance show in main function.
   cout<< "vaule of a = "<< a<< " value of b = "<<b<<endl ;  
    swap_by_referrence_by_reference(a, b);   // call by refference by referce so chance show in main function.
   cout<< "vaule of a = "<< a<< " value of b = "<<b<<endl ;  
   
   
   return 0;
 }

 void swap_by_value(int x ,int y)
 {
    int tem = x ;
    x = y ;
    y = tem ;
    return ;
 }

 void swap_by_referrence_by_pointer(int *x , int *y)
 {
    int tem = *x ;
    *x = *y ;
    *y = tem ;
    return ;
 }

 void swap_by_referrence_by_reference(int &x ,int &y)
{
     int tem = x ;
     x = y ;
     y = tem ;
     return ;
}