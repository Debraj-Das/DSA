#include <stdio.h>
#include <stdlib.h>

void exchance(int ** ,int ,int ,int );  // exchance row and colomn.
int subcodinard(int ** ,int ); // determind subcoordinate by recuirtion.

int main()
 {
    int n, **matrix ,add=0 , i, j, value, sign;
    while(1)
    {
    printf("\nEnter the order of the Matrix : ");   // In main n variable use as a order of matrix.
    scanf("%d",&n);
    // Allocated space for 2D array dynamically.                                            
    matrix=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;++i)
    {
        matrix[i] =(int *)malloc(n*sizeof(int ));
    }
     // Scanned the input by for loop.
    printf("\nEnter the element of nxn order Matrix : \n");
    for( i=0;i<n;++i)
    { 
        printf("\t");
        for(j=0;j<n;++j)
        {
            scanf("%d",&matrix[i][j]);
        }
    }

    //determind the subcoordined of Matrix.
    printf("\nAdjugate Matrix of input Matrix \n\t");
   for(i=0;i<n;++i)
   {
       if(i%2==0) sign=-1;
       else sign=1;
       for(j=0;j<n;++j)
       {
           exchance(matrix,j,i,n);
           sign*=(-1);
        if((((n-i)>2)&&((n-j)<=2))||(((n-i)<=2)&&((n-j)>2))) 
               {
                   value=(-1)*sign*subcodinard(matrix,n-1);
                   printf("%d ",value);
               }
        else 
              {   
                  value=subcodinard(matrix,n-1)*sign;
                  printf("%d ",value);
              }
        exchance(matrix,j,i,n);
       }
       printf("\n\t");
   }

    printf("\nDetermined of  the matrix : %d \n\n",subcodinard(matrix,n));
    free(matrix);
                        // for continous or break for this desetion.
    printf("IF you want to exit from computation Enter Zero.\n Enter input : ");
    scanf("%d",&value);
    if(value==0) break;
    }
    printf("\nComputation is finished.\n\n");
    return 0;
 }
  
 void exchance(int **matrix, int row , int colomn ,int order )
 {
     int chance,i;
     // first exchance row
     for(i=0;i<order;++i)
     {
         chance=matrix[order-1][i];
         matrix[order-1][i]=matrix[row][i];
         matrix[row][i]=chance;
     }
    // Then exchance colomn.
    for(i=0;i<order;++i)
    {
        chance=matrix[i][order-1];
         matrix[i][order-1]=matrix[i][colomn];
         matrix[i][colomn]=chance;
    }
    return ;
 }

 int subcodinard(int **matrix,int n)
 {     
     int add=0;
     //Base condition.
     if(n==1) return matrix[0][0];
     // Recuition of the function.
     for(int i=0,sign=-1;i<n;++i)
    {
        exchance(matrix,0,i,n);
        sign*=(-1);
        if(((n-0)>2&&(n-i)<=2)||((n-0)<=2&&(n-i)>2)) 
               add+=matrix[n-1][n-1]*subcodinard(matrix,n-1)*sign*(-1);
        else 
              add+=matrix[n-1][n-1]*subcodinard(matrix,n-1)*sign;
        exchance(matrix,0,i,n);
    }
     return add ;
 }