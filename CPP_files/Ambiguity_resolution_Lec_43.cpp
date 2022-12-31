#include <iostream>

using namespace std;

class Base1
{
  public:
  void greeding(int a)
  {
    cout<<a<<endl ;
    cout <<"\nHello everyone "<<endl ;
    return ;
  }
};

class Base2
{
  public:
  void greeding(int a)
  {
    cout<<a<<endl ;
    cout <<"\nGood morning everyone "<<endl ;
    return ;
  }
};

class Drive : public Base1, public Base2
{
  public:
   void greeding(int a)     //~  Ambiguity resolution in ingeritance for same base functions(only );
   {                        //! always drived same prototype function highest periodity.
      Base1::greeding(a);  /// defind by resolved the ambiguity member inside same name drided class member.
   }
};

int main()
{
  Drive obj;
  obj.greeding(5);

  return 0;
}