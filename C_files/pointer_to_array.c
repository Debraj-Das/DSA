#include <stdio.h>
#include <stdlib.h>


int main()
{
    int arr[] = { 3 , 2 , 8 , 32 , 83 , 92 , 11 , 38 , 93 , 81} , *arr_pointer ;
    arr_pointer = arr ;   //~ intially the arr_pointer by intial address of array.
    printf("Third element of pointer :: %d\n",*(arr_pointer + 2)); //# (arr_pointer +2) == &arr[2]
    return 0;
}