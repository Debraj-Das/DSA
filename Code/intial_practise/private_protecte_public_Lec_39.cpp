#include <iostream>

using namespace std ;

class Base
{
  private:
   int a ;
  protected:
     int b ;
  public:
     int c ;   
  
};

class Drive_private : private Base
{
   private:
    int private_a ;
  protected:
    int private_b ;
  public:
   int private_c ;

};
class Drive_protected : protected Base
{
   private:
    int protected_a ;
  protected:
    int protected_b ;
  public:
   int protected_c ;

};
class Drive_public : public Base
{
   private:
    int public_a ;
  protected:
    int public_b ;
  public:
   int public_c ;

};
  //! protected mode member are inheritence type but not access of outside.
   

int main()
 {
    Drive_private obj_private ;
    Drive_protected obj_protected ;
    Drive_public obj_public ;

    int val ;
  // val = obj_private.c  or obj_private.b ; but base member a not inheritence due to it private member of class.
      //# give error because Base class is inheritence by private so all inheritence Base class member are private.
  val = obj_private.private_c ; // only member of Drive_private class are public.

  // val = obj_protected.c or obj_protected.b are not accessable due to protected member of obj_protected.
        //# give error because Base class is inheritence by protected so all inheritence Base class member are protected.
    val = obj_protected.protected_c ; // only member of Drive_protected class are public.
    
  // val = obj_public.b is  not accessable due to protected member of obj_protected.
        //# give error because Base class is inheritence by protected so all inheritence Base class member are there own type.
    val = obj_public.public_c ; // only member of Drive_public class are public.

  
  return 0;
 }