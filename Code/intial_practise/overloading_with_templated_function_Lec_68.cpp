#include <iostream>

using namespace std;

template <class type>
class Store
{
public:
  type data;
  Store(type a)
  {
    data = a;
  }
  void display();
};

template <class type>     //~ SYNTEX of  template class member outside of class.
void Store<type>::display()
{
  cout << "The data value is " << data << endl;
  return;
}

void print(int a)  //* Exact match takes the highest priority.
{
  cout << "the frist print function " << endl
       <<" the value is "<<a<<endl ;
       return ;
}

template <class T>
void print(T a)
{
  cout << "the templated print function " << endl
       <<" the value is "<<a<<endl ;
       return ;
}

int main()
{
  Store<string> obj("Debraj Das");
  cout<<"data is "<<obj.data<<endl ;
  obj.display();
  print(4);  /// Exact match takes the highest priority, so frist print function is invoked in this case.
  print(1.2);  //* but this case templated print function is invoked.
  return 0;
}