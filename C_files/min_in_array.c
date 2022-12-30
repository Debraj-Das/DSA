#include <stdio.h>
#include <stdlib.h>

int return_min(int array[], int size_of_array)
{
  int min = array[0];
  for (register int i = 1; i < size_of_array; ++i)
  {
    if (min > array[i])
      min = array[i];
  }
  return min;
}

int main()
{
  int arr[] = {280, 8, 825, 83, 91, 38};
  int min = return_min(arr, 6);
  printf("min member of the array is %d\n", min);
  return 0;
}