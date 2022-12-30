#include <iostream>

using namespace std;
int n;

bool check(int array[], int c)
{
  for (int i = 0; i < n; ++i)
  {
    if ((array[i] % c) != 0)
      return false;
  }
  return true;
}

void divided(int array[], int c)
{
  for (int i = 0; i < n; ++i)
  {
    array[i] /= c;
  }
  return;
}

inline void small(int array[])
{
  int *tem = array;
  for (int i = 0; i < n; ++i)
  {
    if (array[i] < *tem)
      tem = &array[i];
  }
  int t = array[0];
  array[0] = *tem;
  *tem = t;
  return;
}

int main()
{
  register long long int lcm ;
  register int *array, i;
  cout << "Enter the no of number :: ";
  cin >> n;
  array = new int[n];
  for (i = 0; i < n; ++i)
  {
    cout << (i + 1) << ") ";
    cin >> array[i];
  }
  small(array);

  lcm = 1 ;
  while (check(array, 2))
  {
    lcm *= 2;
    divided(array, 2);
  }

  for (i = 3; i <= array[0]; i += 2)
  {
    while (check(array, i))
    {
      lcm *= i;
      divided(array, i);
    }
  }

  for (i = 0; i < n; ++i)
  {
    lcm *= array[i];
  }
   delete array ;
  cout << "\tlcm is : " << lcm << endl;

  return 0;
}