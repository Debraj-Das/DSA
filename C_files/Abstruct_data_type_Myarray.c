#include <stdio.h>
#include <stdlib.h>

typedef struct myArry
{
    int total_size ;
    int used_size ;
    int *ptr ;
}myArry ;

void createArray(myArry *a,int tSize,int uSize)
{
    a->total_size = tSize ;
    a->used_size = uSize ;
    a->ptr = (int *)malloc(tSize*sizeof(int ));
    return ;
}

void setVal(myArry *a)
{
    for(int i=0;i<a->used_size;++i)
    {
        printf("Enter %d element\t",(i+1));
        scanf("%d",&(a->ptr)[i]);
    }
    return ;
}

void show(myArry *a)
{
    for(int i = 0;i<a->used_size;++i)
    printf("%d\n",(a->ptr)[i]);
    return ;
}

int main()
{
    myArry marks ;
    createArray(&marks, 10 , 4);
    setVal(&marks);
    show(&marks);
    free(marks.ptr);
    return 0 ;
}