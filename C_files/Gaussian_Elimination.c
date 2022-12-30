#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, n, row, clomn; // varible declaration part.
    double **augmented, t;
    do
    {
        printf("Enter the order of Augmented Matrix : "); // input part form user.
        scanf("%d%d", &row, &clomn);
        augmented = (double **)malloc(row * sizeof(double *));
        for (i = 0; i < row; ++i)
        {
            augmented[i] = (double *)malloc(clomn * sizeof(double));
        }
        printf("Enter the element of Augmented Matrix :\n");
        for (i = 0; i < row; ++i)
        {
            printf("\t");
            for (j = 0; j < clomn; ++j)
            {
                scanf("%lf", &augmented[i][j]);
            }
        }

        for (i = 0, j = 0; i < row && j < clomn; ++i, ++j) // Algorithm code for Gaussian Elimination.
        {
            while (augmented[i][j] == 0) // rearrange martix due to first element is zero.
            {
                for (k = i + 1; k < row; ++k)
                {
                    if (augmented[k][i] != 0)
                        break;
                }
                if (k >= row)
                    {
                        ++j;
                        continue;
                    }
                for (n = j; n < clomn; ++n)
                {
                    t = augmented[i][n];
                    augmented[i][n] = augmented[k][n];
                    augmented[n][j] = t;
                }
            }

            for (k = clomn - 1; k >= j; --k) // unit of first element of row.
            {
                augmented[i][k] /= augmented[i][i];
            }

            for (n = i + 1; n < row; ++n) // Eliminated lower part of Martix.
            {
                for (k = clomn - 1; k >= j; --k)
                {
                    augmented[n][k] -= (augmented[i][k] * augmented[n][i]);
                }
            }
        }
        printf("\n\n Augmented Matrix after apply Gaussian Elimination :\n");
        for (i = 0; i < row; ++i)
        {
            printf("\t");
            for (j = 0; j < clomn; ++j)
            {
                printf("%0.2lf ", augmented[i][j]);
            }
            printf("\n");
        }
        for (i = 0; i < row; ++i)
        {
            free(augmented[i]);
        }
        free(augmented);
        printf("For next process enter nonzero number or enter zero.\n \t Enter input :");
        scanf("%d", &i);
    } while (i);
    return 0;
}