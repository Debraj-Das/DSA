#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int getint()
{
    printf("Enter the number for finding prime in 0 to that number(>10^20) :");
    unsigned long long int power;
    scanf("%llu", &power);
    return power;
}

int main(int argc, char *argv[])
{
    register FILE *fpta;
    if (argc == 1)
        fpta = fopen("prime.txt", "a");
    else
        fpta = fopen(argv[1], "a");
    if (fpta == NULL)
    {
        printf("Error! for open the %s file.\n", argv[1]);
        exit(-1);
    }

    register unsigned long long int last_num, *array, no_prime, number;
    register unsigned int n, i;
    register char ch;
    last_num = getint();
    n = ((1.01 * sqrt(last_num) / (0.5 * log(last_num) - 1)));
    array = (long long int *)malloc(n * sizeof(long long int));
    fprintf(fpta, "Prime number in between 0 to %llu array -->\n", last_num);
    fprintf(fpta, "Below the following prime number\n 2 ,\tdelt(prime)\n");
    for (number = 5, no_prime = 1, array[0] = 3; number <= last_num; number += 2)
    {
        for (i = 0, ch = 'y'; (array[i] * array[i]) <= number; ++i) // Find the prime number.
        {
            if ((number % (array[i])) == 0)
            {
                ch = '\0';
                break;
            }
        }

        if (ch) // Store the find prime number.
        {

            if (no_prime < n)
                array[no_prime] = number;
            ++no_prime;
            fprintf(fpta, " %llu \n", number);
        }
    }
    fprintf(fpta, "No of Prime number in between 0 to %llu is %llu.\n", last_num, no_prime + 1);
    fprintf(fpta, "number is finished.\n");
    fclose(fpta);
    free(array);
    printf("\ncomputation is finished.\n");
    return 0;
}