#include <iostream>

using namespace std;

class Shopitem
{
  int id;
  float price;

public:
  void getdata(int a, float b)
  {
    id = a;
    price = b;
    return;
  }
  void print()
  {
    cout << "Id of the iteam is " << id << " and price is " << price << endl;
    return ;
  }
};

int main()
{
    Shopitem *ptrobj , *headptrobj;
    const int size = 8 ;
    int  i ;
    float num ;
    ptrobj = new Shopitem[size];
    headptrobj = ptrobj ;
    for(i = 0 ;i<size;++i)
    {
       ptrobj->getdata((1000+i*10),1.1*(i+1));
       ++ptrobj;
    }
    ptrobj = headptrobj ;
    for(i=0;i<size;++i)
    {
      ptrobj->print();
      ++ptrobj ;
    }
    delete[] headptrobj ;


  return 0;
}