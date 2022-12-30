/*
Unsorted and sorted both case work for linear search
But case of Binary seaching array to be sorted 
*/
#include <stdio.h>
#include <stdlib.h>

int linear_seaching(int arr[],int size , int element)  // linear seaching code
{
    for(int i = 0 ; i < size ; ++i)
        if(arr[i]==element)
            return i ;
    return (-1);
}

int binary_seaching_by_iteration(int arr[],int size ,int element)
{
    int low_index = 0  , high_index = (size - 1) , mid ;
    while(low_index <= high_index)
    {
        mid = (low_index + high_index)/2 ;
        if(arr[mid] == element)
            return mid ;
        else if(arr[mid]>element)
            high_index = mid - 1 ;
        else 
            low_index = mid + 1 ;
    }
    return -1 ;
}

int binary_seaching_by_recurtion(int arr[], int element, int lower_end, int higher_end)   // binary seaching code
{
    if (lower_end > higher_end) // base condition of recursion problem
        return -1;

    int mid = (lower_end + higher_end) / 2;
    if (arr[mid] == element)
        return mid;
    else if (arr[mid] > element)
        return binary_seaching_by_recurtion(arr, element, lower_end, mid - 1);
    else
        return binary_seaching_by_recurtion(arr, element, mid + 1, higher_end);
}

int main()      // drive function of C languege
{
    int arr[100] , element ;
    for(int i = 0 ; i<100 ; ++i)
    arr[i] = i+1 ;
    printf("Enter a number for seaching :: ");
    scanf("%d",&element);

    int index_of_element ;
    //index_of_element = linear_seaching(arr,100,element); //seaching through linear algorithm
    index_of_element = binary_seaching_by_iteration(arr,100,element); //seaching through binary algorithm by iteration technic
    //index_of_element = binary_seaching_by_recurtion(arr,element,0,99); //seaching through binary algorithm by recursion technic

    if(index_of_element != (-1))
    printf("index of the seaching element is %d\n",index_of_element);
    else 
    printf("element is not present in array\n");
    return 0;
}
