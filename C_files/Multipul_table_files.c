#include <stdio.h>
#include <stdlib.h>

int main(int agc, char *agv[])
{
    FILE *fptw;
    if (agc == 1)
        fptw = fopen("Multiply_table.txt", "a");
    else
        fptw = fopen(agv[1], "a");
    if (fptw == NULL)
    {
        printf("Problem occured to open file.");
        exit(1);
    }
    while (1)
    {
        int n;
        printf("Enter the number ::");
        scanf("%d", &n);
        if (n == 0)
            break;
        fprintf(fptw, "Multipul table for %d :: \n", n);
        for (int i = 0; i < 10; ++i)
        {
            fprintf(fptw, "%d * %d = %d\n", n, (i + 1), (n * (i + 1)));
        }
    }
    fprintf(fptw, "Multipul table is finished.");
    fclose(fptw);
    printf("work is finished.\n");
    return 0;
}