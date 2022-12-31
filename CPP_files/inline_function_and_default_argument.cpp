#include <iostream>

using namespace std ;

 int money(int intial , double interest = 1.05)    // defalut agrument declartion.
{                                        // it give a defaut value of argument.
  return (intial*interest);                // if value not send it take default value.
}

inline int sub(int a,int b)    // inline keyword use. 
{                            // it request compliler put function boby in calling place of function.
  return (a-b);
}

int main()
 {
    int intial_money ;
    cout<<"Enter the intial money : ";
    cin>>intial_money ;
    cout << "final value of general case is "<<money(intial_money)<<endl ;
    cout<<"so interest for general is "<<sub(money(intial_money),intial_money)<<endl ;
    cout << "final value of special person is "<<money(intial_money,1.1)<<endl ;
    cout<<"so interest for special is "<<sub(money(intial_money,1.1),intial_money)<<endl ;
  
  return 0;
 }