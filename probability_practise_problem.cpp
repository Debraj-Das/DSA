#include <iostream>
#include <ctime>
using namespace std;

int main()
{
     int no_of_input,*input;
     long long int no_of_experiment , i;
     cout<<"Enter the input number :: ";
     cin>>no_of_input;
     input = new int[no_of_input];
     cout<<"Enter the no of experiment :: ";
     cin>>no_of_experiment ;
     srand(time(0)%1000);
     for(i = 0 ; i<no_of_experiment;++i)
               ++input[rand()%no_of_input];
     for(i=0;i<no_of_input;i++)
     cout<<(i+1)<<")th input probability :: "<<(((double)input[i])/no_of_experiment)<<endl;
     cout << endl;
     return 0;
}