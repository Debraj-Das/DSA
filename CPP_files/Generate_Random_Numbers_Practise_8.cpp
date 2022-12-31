#include <iostream>
#include <ctime>

using namespace std;

int main()
{
  cout << "Generating Tandom Numbers below :: " << endl
       << endl;
  srand(time(0));
  for (int i = 0; i < 10; ++i)
  {
    cout << " " << (rand() % 100) << " ";
  }
  cout << endl;
  return 0;
}