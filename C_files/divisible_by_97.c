#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num ;
    printf("Enter a number :: ");
    scanf("%d",&num);
    (num%97)? printf("number %d is not divisible by 97.\n",num) :  printf("number %d is divisible by 97.\n",num);   
    return 0;
}