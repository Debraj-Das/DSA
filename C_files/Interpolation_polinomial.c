#include <stdio.h>
#include <stdlib.h>

double determinant(double **matrix,int n)
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
     return  det ;
 }

int main()
{
    double **matrix, **determinated, *f, var, point;
    int n, i, j;
    while (1)
    {
        printf("Enter the no of given points \n\t for find out coeffient of Interpolation polinomial : ");
        scanf("%d", &n);
        if (n == 0)
            break;

        // decleration of matrix variable and varible of funtion of vaule.
        matrix = (double **)malloc(n * sizeof(double *));
        f = (double *)malloc(n * sizeof(double));
        for (i = 0; i < n; ++i)
        {
            matrix[i] = (double *)malloc(n * sizeof(double));
        }

        // Take vaule of point and function from user.
        printf("\nEnter the point and corresponding vaule of function : \n");
        for (j = 0; j < n; ++j)
        {
            printf("\t(x%d ,f%d )= ", j, j);
            scanf("%lf%lf", &var, &f[j]);
            point = 1;
            for (i = n - 1; i >= 0; --i)
            {
                matrix[j][i] = point;
                point *= var;
            }
        }
        printf("\n");

        determinated = (double **)malloc(n * sizeof(double *));
        for (i = 0; i < n; ++i)
        {
            determinated[i] = (double *)malloc(n * sizeof(double));
            for (j = 0; j < n; ++j)
            {
                determinated[i][j] = matrix[i][j];
            }
        }

        // finding the coefficient of polynomial.
        var = determinant(determinated, n);

        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                point = matrix[j][i];
                matrix[j][i] = f[j];
                f[j] = point;
            }
            for (int k = 0; k < n; ++k)
            {
                for (j = 0; j < n; ++j)
                {
                    determinated[k][j] = matrix[k][j];
                }
            }
            point = determinant(determinated, n);
            printf("coefficient of x^[%d] is %lf\n", n - i - 1, point / var);
            for (j = 0; j < n; ++j)
            {
                point = matrix[j][i];
                matrix[j][i] = f[j];
                f[j] = point;
            }
        }

        free(matrix);
        free(f);
        free(determinated);
        printf("\n\nComputation again started if enter the degree is Zero(0) for exit the computation.\n\n");
    }
    printf("\n\n computation is finished\n");
    return 0;
}
