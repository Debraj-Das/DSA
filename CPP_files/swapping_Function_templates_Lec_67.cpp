#include <iostream>

using namespace std;

template <class type>
void swp(type &a, type &b)
{
  type tem = a;
  a = b;
  b = tem ;
  return;
}

int main()
{
  cout << "Option of swaping type :" << endl
       << "1.int " << endl
       << "2. double " << endl
       << "3. char " << endl
       << "4. string " << endl
       << "0. For exit the programme." << endl;
  int i;
  while (true)
  {
    cout << "Enter the option number : ";
    cin >> i;
    switch (i)
    {
    case 0:
    {
      cout << "\nProgram is finished." << endl;
      goto jump;
    }
    case 1:
    {
       int a , b ;
       cout<<"Enter the a(int ) , b(int ) :\n";
       cin>>a>>b ;
       swp(a,b);
       cout<<"After swapping:\n\t a = "<<a<<"\n\t b = "<<b<<endl ;
       break ;
    }
    case 2:
    {
       double a , b ;
       cout<<"Enter the a(double ) , b(double ) : \n";
       cin>>a>>b ;
       swp(a,b);
       cout<<"After swapping:\n\t a = "<<a<<"\n\t b = "<<b<<endl ;
       break ;
    }
    case 3:
    {
       char a , b ;
       cout<<"Enter the a(char ) , b(char ) :\n";
       cin>>a>>b ;
       swp(a,b);
       cout<<"After swapping:\n\t a = "<<a<<"\n\t b = "<<b<<endl ;
       break ;
    }
    case 4:
    {
       string  a , b ;
       cout<<"Enter the a(string ) , b(string ) :\n" ;
       cin>>a>>b ;
       swp(a,b);
       cout<<"After swapping:\n\t a = "<<a<<"\n\t b = "<<b<<endl ;
       break ;
    }
    default:
    {
      cout<<"YOU enter wrong option."<<endl ;
    }
    }
    cout<<"\nAgaing swapping process start.\n\n";
  }
jump:
  return 0;
}