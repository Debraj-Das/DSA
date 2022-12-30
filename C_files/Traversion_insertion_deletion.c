#include <stdio.h>

void display(int arr[],int n )
{
    //Traversal 
    for(int i = 0;i<n;++i)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return ;
}

int indInsertion(int arr[],int size , int capacity ,int element , int index)
{
    // code for insertion
    if(size>=capacity)
        return 0 ;
    
    for(int i= (size-1) ; i>=index;--i)
        arr[i+1]=arr[i];
    arr[index] = element ;
    return 1 ;
}

int deletion(int arr[],int size,int index)
{
    // code of deletion operation
    if(size < index)
        return 0 ;
    for(int i = index ; i<(size-1);++i)
        arr[i] = arr[i+1];
    return 1 ;
}

int main()
{
    int arr[100] = {1,3 , 35 , 234};
    int size = 4 , element = 45 ;
    display(arr,size);
    printf("Try to insert 100 in 4 place of arr :: \n\t");
    if(indInsertion(arr,size, element , 100 , 3)) 
    display(arr , size+=1);
    else
    printf("insert falled due to capacity is full\n");
    printf("Try to delet 2 element of arr :: \n\t");
    if(deletion(arr,size,1))
    display(arr,size-=1);
    else 
    printf("Deleted operation not occured\n");
    return 0;
}

