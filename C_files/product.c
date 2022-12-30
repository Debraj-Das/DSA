#include <stdio.h>
#include <stdlib.h>

int **inputmatrix(int );
int addition(int *,int *);

int clomn;

int main()
 {
    int row1 ,row2 , **a , **b;
    while(1) {
    printf("Enter the number of row and coloum of A matrix : ");
    scanf("%d%d",&row1,&clomn);
    printf("Enter the of row and coloum of B matrix : ");
    scanf("%d",&row2);
    if(row2!=clomn)
    {
        printf("matrix product is not defined.\n");
        printf("If you exit the programme then enter Zero or not than enter any nonzero number.\n\t");
        scanf("%d",&row1);
        if(row1!=0) continue;
         else  break;
    }
    scanf("%d",&row2);
    printf("\nEnter the element of A matrix :\n");
    a = inputmatrix(row1);
    printf("\nEnter the element of B matrix :\n");
    b = inputmatrix(row2);
    printf("A*B =\n");
    for(int i=0,j;i<row1;++i)
    {   
        printf("\t|");
        for(j=0;j<row2;++j)
        {
            printf(" %3d ",addition(a[i],b[j]));
        }
        printf(" |\n");
    }
    printf("\nIF you want to exit from programme than enter Zero or than enter any nonzero number.\n\t");
    scanf("%d",&clomn);
    if(!clomn) break;
    printf("Programme is again began.\n\n");
    }
    return 0;
 }

 int **inputmatrix(int row)
 {
     int **matrix;
     matrix=(int **)malloc(row*sizeof(int *));
     for(int i=0,j;i<row;++i) 
     {
         matrix[i] =(int *)malloc(clomn*sizeof(int));
         for(j=0;j<clomn;++j)
         {
             scanf("%d",&matrix[i][j]);
         }
     }
     return matrix;
 }

 int addition(int *a,int *b)
 {
     int add=0;
     for(int i=0;i<clomn;++i)
     {
         add+=a[i]*b[i];
     }
     return add;
 }
 