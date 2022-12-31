#include <iostream>
#include <stdlib.h>

using namespace std;

struct product
{
  string product_Id;
  int price;
};

class Shop
{
private:
  product item[100];
  int count = 0;

public:
  void set_product_information();
  void print_all_product_information();

};

void Shop::set_product_information()
{
  cout << "Enter the product Id for " << (count + 1) << "th : ";
  cin >> item[count].product_Id;
  cout << "And also Enter the price of this product :  ";
  cin >> item[count].price;
  ++count;
  return;
}

void Shop::print_all_product_information()
{
  for (int i = 0; i < count; ++i)
    cout << "Price of Product Id \"" << item[i].product_Id << "\" is " << item[i].price << endl;
  return;
}

int main()
{
  int  enter_no;
  Shop com_Shop;
  cout << "now how many product information you want to enter(max 100 product information) :";
  do
  {
    cin >> enter_no;
    if (enter_no > 100)
      cout << "you enter more than total product.\nSo again enter no of product ";
  } while (enter_no > 100);

  for (int i = 0; i < enter_no; ++i)
  {
    com_Shop.set_product_information();
  }
  cout <<endl ;
  com_Shop.print_all_product_information();

  return 0;
}