/*
* Code for Bubble sorting algorithm.
# it complied by pass and pass
*/
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n)
{
   for(int i = 1 , j , m , k , temp ; i < n ; ++i)
   {
      m = n - i ;
      for(j = 0 , k = 0 ; j < m ; ++j)
      {
         if(arr[j] > arr[j+1]) 
         {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp ;
            ++k ;
         }
      }
      if(k == 0) break;
   }
   return ;
}

int main()
{
   int arr[] = {3 , 2 , 5 , 4 , 54 , 7 , 24,23,34 ,351,13,135} ;
   bubble_sort(arr, 12);
   for(int i =0 ; i < 12; ++i)
   printf("%d ",arr[i]);
   printf("\n");
   return 0;
}