#include <iostream>

using namespace std;

int main()
{
  register int *pointer, i;
  pointer = new int(43); /// new syntex of singal dynamic allocated memory.
  cout << "The value of dynamic allocated memory is " << *pointer << endl;
  delete pointer; //@ delete syntex of singal dynamic allocated memory.

  pointer = new int[40]; /// new syntex of  dynamic allocated array memory.
  for (i = 0; i < 40; ++i)
  {
    pointer[i] = (5 * i);
  }
  cout << endl;
  for (i = 0; i < 40; ++i)
  {
    cout << "The value of pointer[" << i << "] is " << pointer[i] << endl;
  }
  delete[] pointer; //@ delete syntex of  dynamic allocated array memory.

  return 0;
}