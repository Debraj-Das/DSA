#include <iostream>

using namespace std;

class Base1
{
public:
  int basedata1 = 1;
  virtual void display() //* use "virtual" keyword for chance default behavior of base pointer pointed drived objected.
  {
    cout << "value of basedate1 " << basedata1 << endl;
    return;
  }
};
class Base2
{
public:
  int basedata2 = 2; //! varible with virtual keyword not support.
  void display()     //* thus here virtual keyword not use, so default behavior show.
  {
    cout << "value of basedate1 " << basedata2 << endl;
    return;
  }
};

class Drive : public Base1, public Base2 //! this pointing idea work for only public mode.
{
public:
  int drivedata = 3;
  int basedata2 = 4;
  void display()
  {
    Base1 ::display(); /// Base1 :: syntex use for use particularly base1's display function
    Base2 ::display(); /// similary this case
    cout << "value of basedata2 in drived class " << basedata2 << endl;
    cout << "value of drivedata " << drivedata << endl;
    return;
  }
};

int main()
{
  Base1 *base_obj_ptr;
  Drive drive_obj;
  base_obj_ptr = &drive_obj;    //? only base pointer or it's own pointer assigned addressed of drived pointer.
  base_obj_ptr->basedata1 = 34; //@ use only associated inheritance base members only except virtual associated functions.
  base_obj_ptr->display();      //* invoked drived display function because virtual keyword use
  cout << endl;                 //* before  display function decleration time in Base1 class.

  Base2 *ptr_base_2;
  ptr_base_2 = &drive_obj;
  ptr_base_2->basedata2 = 235; //* this basedata2 is member of Base2 class.
  ptr_base_2->display();       //@ use only associated inheritance base members only
  cout << endl;                //@ because virtual keyword not use declearation time in Base2 class.

  Drive *ptr_drive = &drive_obj;
  ptr_drive->drivedata = 456;
  ptr_drive->basedata2 = 325; /// own class member priodity maximum ;
                              //* this basedata2 is member of Drive class.
  ptr_drive->display();
  cout << endl;

  return 0;
}