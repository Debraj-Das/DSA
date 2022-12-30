#include <iostream>

using namespace std;

template <class type1 = int, class type2 = char, class type3 = string>
class Store
{
  type1 da;
  type2 db;
  type3 dc;

public:
  Store(type1 a, type2 b, type3 c)
  {
    da = a;
    db = b;
    dc = c;
  }
  void display()
  {
    cout << "data1 is " << da << "\ndata2 is " << db << "\ndata3 is " << dc << endl;
    return;
  }
};

int main()
{
   Store <> obj(8,'x',"debraj");
   obj.display();
  return 0;
}