#include <iostream>

using namespace std;

struct product
{
  string product_Id;
  int price;
};

class Shop
{
private:
  product *item;
  int count = 0;

public:
  void dynamic_allocation(int num)
  {
    item = new product[num]; // malloc function created problem for string type date.
    if (item == NULL)
    {
      cout << "Error in dynamic allocation." << endl;
      exit(-1);
    }
    return;
  }

  void set_product_information();
  void print_all_product_information();

  void delet_information()
  {
    delete item;
    return;
  }
};

void Shop::set_product_information()
{
  cout << "Enter the product Id for " << (count + 1) << "th : ";
  cin >> item[count].product_Id;
  cout << "And also Enter the price of this product : ";
  cin >> item[count].price;
  ++count;
  return;
}

void Shop::print_all_product_information()
{
  if (count == 0)
    cout << "\nThere are no product information.\n";
  for (int i = 0; i < count; ++i)
    cout << "Price of Product Id  is \"" << item[i].product_Id << "\" price " << item[i].price << endl;
  return;
}

int main()
{
  int num, enter_no, i;
  cout << "Enter the max number of product : ";
  cin >> num;
  Shop com_Shop;
  com_Shop.dynamic_allocation(num);
  cout << "For take action give according their input :\n"
       << "\t1. For exit of process enter : 0\n"
       << "\t2. For set the product information enter : 1\n"
       << "\t3. For see information of all product enter : 2\n"
       << endl;
  while (num > 0)
  {
    cout << "Enter the input for according your choice of action : ";
    cin >> i;
    switch (i)
    {
    case 0:
    {
      com_Shop.delet_information();
      goto jump;
    }
    case 1:
    {
      cout << "\nnow how many product information you want to enter : ";
      do
      {
        cin >> enter_no;
        if (enter_no > num)
          cout << "you enter more than total product.\nSo again enter no of product ";
      } while (enter_no > num);
      for (i = 0; i < enter_no; ++i)
        com_Shop.set_product_information();
      cout << endl;
      num -= enter_no;
      break;
    }
    case 2:
    {
      cout <<endl ;
      com_Shop.print_all_product_information();
      cout <<endl ;
      break;
    }
    default:
    {
      cout << "\nyou give wrong input. so,Please enter again number for take action.\n";
      break;
    }
    }
  }
   cout << "\nyour product information completed.so last time printed all information you gave :\n";
   com_Shop.print_all_product_information();
   jump:
  cout << "\n process are finished.\n";
  return 0;
}