#include <iostream>

using namespace std ;

class Employee 
{
  private:                    // private variable is only accessble for this class's function.
          int a , b , c ;
  public:                     // public variable accessble for all function.
         int d , e ;
  void setdate(int ,int , int );  //decleartion of setdate function.
  void getprint()                 // define and decleartion of getprint function.
  {
    cout << "The value of a : "<< a << endl ; 
    cout << "The value of b : "<< b << endl ; 
    cout << "The value of c : "<< c << endl ; 
    cout << "The value of d : "<< d << endl ; 
    cout << "The value of e : "<< e << endl ; 
    return ;
  }
};

void Employee:: setdate(int x,int y,int z)   // syntex of define the class function outside of this function.
{
     a = x ;
     b = y ;
     c = z ;
     return ;
}

int main()
 {
    Employee debraj_das ;
    debraj_das.d = 32 ;      // 'd' and 'e' are public variable.so it can accessable outside of function.
    debraj_das.e = 45;
    debraj_das.setdate(20,25,30);
    debraj_das.getprint();
    // cout<<"vaule of private variable "<<debraj_das.a<<endl ; --> this gives error because 'a' is a private variable.
  
  return 0;
 }