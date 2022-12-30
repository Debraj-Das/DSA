#include <stdio.h>
#include <stdlib.h>

typedef struct numset
{
    long int prime[1000];
    struct numset *next;
} set;

int main(int argc, char *argv[])
{
    set *head, *p, *q;
    long int n, last_num;
    int no_prime, i;
    head = (set *)malloc(sizeof(set));
    head->next = NULL;
    p = head;

    printf("Enter the final degree of number for finding prime number : ");
    scanf("%d", &no_prime);
    for (n = 1, last_num = 1; n < no_prime; ++n)
        last_num *= 10;

    p->prime[0] = 3;
    for (n = 5, no_prime = 1; n < last_num; n += 2)
    {
        for (i = 0, q = head; i < no_prime; ++i) // Find the prime number.
        {
            if ((i % 1000) == 0 && (i != 0))
                q = q->next;
            if ((n % (q->prime[i % 1000])) == 0)
            {
                break;
            }
        }

        if (i == no_prime) // Store the find prime number.
        {
            ++no_prime;
            i = (no_prime - 1) % 1000;
            if ((i == 0) && (no_prime != 1))
            {
                p->next = (set *)malloc(sizeof(set));
                p = p->next;
                p->next = NULL;
            }
            p->prime[i] = n;
        }
    }

    FILE *fptw; // Store the prime number in file.
    fptw = fopen(argv[1], "a");
    if (fptw == NULL)
    {
        printf("Error! for open the %s file.\n", argv[1]);
        for (i = 0, n = 0, q = head; i < no_prime; ++i, ++n)
        {
            if (n == 1000)
            {
                p = q->next;
                free(q);
                q = p;
                n = 0;
            }
        }
        exit(-1);
    }

    fprintf(fptw, "No of Prime number in between 0 to %ld is %d.\n", last_num, no_prime + 1);
    fprintf(fptw, "Below the following prime number\n 2\n");
    for (i = 0, n = 0, q = head; i < no_prime; ++i, ++n)
    {
        if (n == 1000)
        {
            p = q->next;
            free(q);
            q = p;
            n = 0;
        }
        fprintf(fptw, " %ld\n", q->prime[n]);
    }
    fprintf(fptw, "number is finished.\n");
    fclose(fptw);
    printf("\ncomputation is finished.\n");

    return 0;
}