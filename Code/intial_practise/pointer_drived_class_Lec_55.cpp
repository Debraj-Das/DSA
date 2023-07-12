#include <iostream>

using namespace std;

class Base1
{
public:
  int basedata1;
  void display()
  {
    cout << "value of basedate1 " << basedata1 << endl;
    return;
  }
};
class Base2
{
public:
  int basedata2;
  void display()
  {
    cout << "value of basedate1 " << basedata2 << endl;
    return;
  }
};

class Drive : public Base1, public Base2  //! this pointing idea work for only public mode.
{
public:
  int drivedata;
  void display()
  {
     Base1 :: display();
     Base2 :: display() ;
    cout  << "value of drivedata " << drivedata << endl;
    return;
  }
};

int main()
{
  Base1 *base_obj_ptr;
  Drive drive_obj;
  base_obj_ptr = &drive_obj;  //? only base pointer or it's own pointer assigned addressed of drived pointer.
  base_obj_ptr->basedata1 = 34;
  base_obj_ptr->display();   //@ use only associated inheritance base members only
  cout<<endl ;

  Base2 *ptr_base_2;
  ptr_base_2 = &drive_obj;
  ptr_base_2->basedata2 = 235;
  ptr_base_2->display();
  cout<<endl ;

  Drive *ptr_drive = &drive_obj;
  ptr_drive->drivedata = 456;
  ptr_drive->display() ;
  cout<<endl ;

  return 0;
}