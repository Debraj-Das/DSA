#include <iostream>


using namespace std ;

 int variable = 45 ;

int main()
 {   
    /* ****** scope change of a variable ********
    genarally scope of variable is local but by "::" oprator we can change the scope to gobal .  */

   int variable = 12 ;
   cout << "\nlocal variable = "<< variable <<endl ;
   cout << "gobal variable = "<< ::variable << endl ; // "::" change the scope of varible local to gobal.
   

  /* ******** Float, Double and Long Double Literals *********
      generally any float type store by default double but f or l letter we can change it . */
      
      cout<< "\nsize of 34.4 = "<<sizeof(34.4)<<endl ;
      cout<< "size of 34.4f = "<<sizeof(34.4f)<<endl ;  // f change the store method double to float.
      cout<< "size of 34.4F = "<<sizeof(34.4F)<<endl ;  // F do same work as f do.
      cout<< "size of 34.4l = "<<sizeof(34.4l)<<endl ;  // l change the store method double to long double.
      cout<< "size of 34.4L = "<<sizeof(34.4L)<<endl ;  // L do same work as l do.

  /* *********Reference Variable ********
     same variable but different identity. */

     float x[2]  ;
     float &y = x[0] ;                       // this type of declaration use for reference variable. 
     x[1] = 45 ;
     x[0] = 15 ;
     cout <<"vaule of x = "<<x[1] <<endl<<"address of x = "<<&x[1] <<endl  ;
     cout << "vaule of y = "<<y<<endl<<"address of y = "<<&y<<endl  ;

  /* ***********typecasting************
     typecasting is  change the type of the varible. */

     double var = 45.56622 ;
     cout << "\ndouble vaule of var = "<< var << endl ;
     cout << "int vaule of var = "<< (int )var<<endl ;
     cout << "int vaule of var(another expression) = "<< int(var)<<endl ;

  return 0;
 }
    // completed the task of tutorial 7 .