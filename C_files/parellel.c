#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct cox
{
     double real;
     double imaginary;
} element;

int main()
{
    int n, i;
    double magnatude;
    element *p, final;
    while (1)
    {
        printf("Enter the parallel element : ");
        scanf("%d", &n);
        if (n == 0)
            break;

        p = (element *)malloc(n * sizeof(element));
        for (i = 0; i < n; ++i)
        {
            printf("Enter the %d element(in this form (a,b)) : ", i + 1);
            scanf("%lf%lf", &p[i].real, &p[i].imaginary);
        }
        final.real = 0;
        final.imaginary = 0;
        for (i = 0; i < n; ++i)
        {
            magnatude = (pow(p[i].real, 2) + pow(p[i].imaginary, 2));
            final.real += (p[i].real/magnatude);
            final.imaginary -= (p[i].imaginary/magnatude);
        }
        free(p);
        magnatude = (pow(final.real, 2) + pow(final.imaginary, 2));
            final.real = (final.real/magnatude);
            final.imaginary = (-1)*(final.imaginary/magnatude);
        printf("\n equvalent impedents is %lf +i*%lf .", final.real, final.imaginary);
        printf("\n\nif you want to enter element number is Zero .\n\n");
        printf("Again process is start \n");
    }
    printf("\n\n computation is completed.\n");
    return 0;
}