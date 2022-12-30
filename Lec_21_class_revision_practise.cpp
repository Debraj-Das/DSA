#include <iostream>
#include <string>

using namespace std;

class Binary_number
{
private:
     string binary;
     int binary_length;
     void binary_check();

public:
     void getstring();
     void ones_compliment();
};

int main()
{
     Binary_number num;
     num.getstring();
     num.ones_compliment();
     return 0;
}

void Binary_number::getstring()
{
     cout << "Enter a Binary number :: ";
     cin >> binary;
     binary_length = binary.length();
     binary_check();
     return ;
}

void Binary_number ::binary_check()
{
     for (int i = 0; i < binary_length; ++i)
     {
          if ((binary[i] != '0') && (binary[i] != '1'))
          {
               cout << binary << " is not a binary number" << endl;
               cout<<"So Again ";
               getstring();
          }
     }
     return;
}

void Binary_number ::ones_compliment()
{
     cout<<"One compliment of "<<binary<<" :: ";
     for (int i = 0; i < binary_length; ++i)
     {
          if (binary[i] == '1')
               cout << "0";
          else
               cout << "1";
     }
     cout << endl;
     return;
}
