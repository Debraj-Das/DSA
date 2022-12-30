#include <iostream>

using namespace std ;

class Emplee
{
  public: 
  int id ;
  int salary ;
  Emplee() {  }
  Emplee(int a , int b)   //#  Base class of programmer class.
  {
    id = a ;
    salary = b ;
  }
  void display()
  {
    cout<<"id of emplee "<<id<<" and his salary "<<salary<<endl ;
    return ;
  }

};
  /*
      //! some improtance point of inheritance -->
      1.inheritance happened for only public member.
      2.constructed member do not inheritance.
      3.default mode of visibily in inheritance is private.
      4.in private mode public member of base class inheritance as a private member of drived class.
      5.in public mode public member of base class inheritance as a public  member of drived class.
      6.base function's variable always use base variable not use same name drived class variable.
        so some time it creat problem for me.
  */


class Programmer : public Emplee  // syntex of inheritance where Programmer is drived class and 
{                                  // Emplee is base class and visibily mode is public.
  private: 
  int programming_languague = 2 ;
  public:
  Programmer(int a ,int b , int c)     //? there are no default constructor so always give input.
  {
    id = a ;
    salary = b ;
    programming_languague = c ;
  }
  void pro_display()
  {
    cout << "id of emplee "<<id<<" and he know programming language "
         <<programming_languague<<" and his salary "<< salary<<endl ;
    return ;
  }
};

int main()
 {
   Emplee obj1(1,526);
   obj1.display();
   Programmer pobj(5,1352,5), p2obj(8,200,1) ;
   pobj.pro_display() ;
   p2obj.display();
  
  return 0;
 }