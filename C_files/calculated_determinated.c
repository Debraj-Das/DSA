#include <stdio.h>
#include <stdlib.h>


 double determinated(double **matrix,int n)
 {     
     double det=1 ,change ;
     int i=0,j;
     for (int k; i <n ; ++i) // Algorithm code for Gaussian Elimination.
        {
            while (matrix[i][i] == 0) // rearrange martix due to first element is zero.
            {
                for(j=i+1;j<n;++j)
                {
                    if(matrix[j][i] != 0) break;
                }
                if(j==n)
                {
                    return 0;
                }
                for(k=i;k<n;++k)
                {
                    change =matrix[i][k];
                    matrix[i][k]=matrix[j][k];
                    matrix[j][k]=change;
                }
                det *=(-1);
            }
            det *= matrix[i][i];
            for (j = n - 1; j>= i; --j) // unit of first element of row.
            {
                matrix[i][j] /= matrix[i][i];
            }
            for (j=i+1; j < n; ++j) // Eliminated lower part of Martix.
            {
                for (k = n - 1; k >= i; --k)
                {
                     matrix[j][k] -= ( matrix[j][i] *  matrix[i][k]);
                }
            }
        }
        printf("\n\n Augmented Matrix after apply Gaussian Elimination :\n");
        for (int i = 0; i < n; ++i)
        {
            printf("\t");
            for (j = 0; j < n; ++j)
            {
                printf("%0.2lf ",matrix[i][j]);
            }
            printf("\n");
        }
     return  det ;
 }

int main()
 {
    double **matrix ;
    int n , i;
    while(1)
    {
    printf("Enter the order of determinated : ");
    scanf("%d",&n);
    if(n==0) break;
    matrix =(double **)malloc(n*sizeof( double *));
    for(i=0;i<n;++i)
    {
        matrix[i]=(double *)malloc(n*sizeof(double));
    }
    printf("\nEnter the element of their arrangment :\n");
    for(i=0;i<n;++i)
    {
        printf("\t ");
        for(int j=0;j<n;++j)
        {
            scanf("%lf",&matrix[i][j]);
        }
    }
    printf("\nVaule of determinated is %lf\n",determinated(matrix,n));
     free(matrix);
      printf("\n\nComputation again started if enter the degree is Zero(0) for exit the computation.\n\n");
    }
     printf("\n\n computation is finished\n");
    return 0;
 }