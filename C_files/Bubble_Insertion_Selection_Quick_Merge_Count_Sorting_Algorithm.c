/*
* Code for Bubble sorting algorithm.
* Code for Insertion sorting algorithm.
* Code for Selection sorting algorithm.
* Code for Quick sorting algorithm.
* Code for Merge sorting algorithm.
* Code for Count sorting algorithm.
# it complied by pass and pass
*/
#include <stdio.h>
#include <stdlib.h>

void array_print(int arr[], int n)
{
   for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
   printf("\n");
   return;
}

void bubble_sort(int arr[], int n)
{
   for (int i = 1, j, m, k, temp; i < n; ++i)
   {
      m = n - i;
      for (j = 0, k = 0; j < m; ++j)
      {
         if (arr[j] > arr[j + 1])
         {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            ++k;
         }
      }
      if (k == 0)
         break;
   }
   return;
}

void insertion_sort(int arr[], int n)
{
   for (int i = 1, temp, j; i < n; ++i)
   {
      temp = arr[i];
      for (j = i - 1; j >= 0; j--)
      {
         if (temp < arr[j])
            arr[j + 1] = arr[j];
         else
            break;
      }
      arr[j + 1] = temp;
   }
   return;
}

void selection_sort(int arr[], int n)
{
   for (int i = 1, j, min_index, temp; i < n; ++i)
   {
      min_index = i - 1;
      for (j = i, temp = 0; j < n; ++j)
      {
         if (arr[min_index] > arr[j])
            min_index = j;
      }
      temp = arr[min_index]; //* Here k used as a temp variable
      arr[min_index] = arr[i - 1];
      arr[i - 1] = temp;
   }
   return;
}

void quick_sort(int arr[], int low, int high)
{
   if (low >= high) //* base condition of recursion.
      return;

   int i = low + 1, j = high, pivot = low, temp;
   while (1)
   {
      while ((arr[i] <= arr[pivot]) && (i <= j))
         ++i;
      while ((arr[j] > arr[pivot]) && (j >= i))
         --j;
      if (i <= j)
      {
         temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
      }
      else
         break;
   }
   temp = arr[j];
   arr[j] = arr[pivot];
   arr[pivot] = temp;
   quick_sort(arr, low, j - 1);
   quick_sort(arr, j + 1, high);
   return;
}

void Merging(int arr[], int arr1[], int n, int arr2[], int m)
{
   int i = 0, j = 0, k = 0;
   while ((i < n) && (j < m))
   {
      if (arr1[i] < arr2[j])
      {
         arr[k] = arr1[i];
         ++i;
         ++k;
      }
      else
      {
         arr[k] = arr2[j];
         ++j;
         ++k;
      }
   }
   while ((i < n))
   {
      arr[k] = arr1[i];
      ++i;
      ++k;
   }
   while (j < m)
   {
      arr[k] = arr2[j];
      ++j;
      ++k;
   }
   free(arr1);
   free(arr2);
   return;
}

void merge_sort(int arr[], const int n)
{
   if (n <= 1) //# Base condition
      return;
   //# preparation of recursion
   const int n1 = (n / 2);
   int i;
   int *arr1 = (int *)malloc(n1 * sizeof(int));
   for (i = 0; i < n1; i++)
      arr1[i] = arr[i];
   int *arr2 = (int *)malloc((n - n1) * sizeof(int));
   for (int j = 0; i < n; ++i, ++j)
      arr2[j] = arr[i];
   //# Recursion merging
   merge_sort(arr1, n1);
   merge_sort(arr2, n - n1);
   Merging(arr, arr1, n1, arr2, (n - n1));
   return;
}

void count_sort(int arr[], int n)
{
   //# first find maximum number in array.
   int max_num, i, temp;
   for (i = 1, max_num = arr[0]; i < n; ++i)
   {
      if (max_num < arr[i])
      {
         temp = arr[i];
         arr[i] = max_num;
         max_num = temp;
      }
   }
   //# define a dynamic array of max_num size.
   int *b = (int *)malloc((max_num + 1) * sizeof(int));
   for (i = 0; i <= max_num; ++i)
      b[i] = 0;
   for (i = 0; i < n; ++i)
      ++b[arr[i]];

   //# sort array
   i = 0;
   int j = 0;
   while (i <= max_num)
   {
      if (b[i])
      {
         arr[j] = i;
         ++j;
         --b[i];
      }
      else
         ++i;
   }
   free(b);
   return;
}

int main()
{
   int arr1[] = {3, 2, 5, 4, 54, 7, 24, 23, 34, 351, 13, 135};
   printf("Unsorted array ::\n");
   array_print(arr1, 12);
   bubble_sort(arr1, 12);
   printf("Bubble sorting result ::\n");
   array_print(arr1, 12);
   printf("\n");

   int arr2[] = {3, 2, 5, 4, 54, 7, 24, 23, 34, 351, 13, 135};
   printf("Unsorted array ::\n");
   array_print(arr2, 12);
   insertion_sort(arr2, 12);
   printf("Insertion sorting result ::\n");
   array_print(arr2, 12);
   printf("\n");

   int arr3[] = {3, 2, 5, 4, 54, 7, 24, 23, 34, 351, 13, 135};
   printf("Unsorted array ::\n");
   array_print(arr3, 12);
   selection_sort(arr3, 12);
   printf("Selection sorting result ::\n");
   array_print(arr3, 12);
   printf("\n");

   int arr4[] = {3, 2, 5, 4, 54, 7, 24, 23, 4, 351, 13, 135};
   printf("Unsorted array ::\n");
   array_print(arr4, 12);
   quick_sort(arr4, 0, 11);
   printf("Quick sorting result ::\n");
   array_print(arr4, 12);
   printf("\n");

   int arr5[] = {3, 2, 5, 4, 54, 7, 24, 23, 4, 351, 13, 135};
   printf("Unsorted array ::\n");
   array_print(arr5, 12);
   merge_sort(arr5, 12);
   printf("Merge sorting result ::\n");
   array_print(arr5, 12);
   printf("\n");

   int arr6[] = {3, 2, 5, 4, 44, 7, 24, 23, 4, 35, 13, 15};
   printf("Unsorted array ::\n");
   array_print(arr6, 12);
   count_sort(arr6, 12);
   printf("Count sorting result ::\n");
   array_print(arr6, 12);
   printf("\n");

   return 0;
}
