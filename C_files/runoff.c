#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate
{
    char name[10];
    int vote;
    short int absent;
} * candidates ;

int **preference, num;

short int vote(int);
void tabulate(int);
short int print_winner(int);
int find_min();
short int is_tie(int);
void elmination(int);

int main(int argc, char *argv[])
{
    int votes, i;
    num = argc - 1;
    printf("Enter the voter number : ");
    scanf("%d", &votes);
    preference = (int **)malloc((votes) * sizeof(int *));
    for (i = 0; i < votes; ++i)
    {
        preference[i] = (int *)malloc(num * sizeof(int));
    }
    candidates = (struct candidate *)malloc(num * sizeof(struct candidate));
    for (i = 0; i < num; ++i)
    {
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].vote = 0;
        candidates[i].absent = 0;
    }

    for (i = 0; i < votes; ++i)
    {
        printf("\nvoter %d \n", i + 1);
        if (vote(i))
            exit(-1);
    }
    while (1)
    {
        tabulate(votes);
        for (i = 0; i < num; ++i)
        {
            printf("%d ", candidates[i].vote);
        }
        printf("\n");
        if (print_winner(votes))
            return 0;
        i = find_min();
        if (is_tie(i))
        {
            for (i = 0; i < num; ++i)
            {
                if (candidates[i].absent == 1)
                    ++i;
                printf("winners are %s\n", candidates[i].name);
            }
            return 0;
        }
        elmination(i);
    }
    return 0;
}

short int vote(int n)
{
    char choice[10];
    for (int j = 0, m = 0; j < num; ++j)
    {
        printf("choice %d : ", j + 1);
        scanf("%s", choice);
        for (int i = 0; i < num; ++i)
        {
            if (strcmp(choice, candidates[i].name) == 0)
            {
                preference[n][j] = i;
                m = 1;
                break;
            }
        }
        if (m == 0)
        {
            printf("wrong choice name.\n");
            return 1;
        }
        else
            m = 0;
    }
    return 0;
}

void tabulate(int votes)
{
    static int fact = 0;
    for (int i = 0; i < votes; ++i)
    {
        for (int j = 0; j < num; ++j)
        {
            printf("%d ", candidates[preference[i][j]].absent);
            if (candidates[preference[i][j]].absent == 0)
            {
               if(j>=fact) ++candidates[preference[i][j]].vote;
                break;
            }
        }
        printf("\t");
    }
    printf("\n");
    ++fact;
    return;
}

short int print_winner(int votes)
{
    for (int i = 0; i < num; ++i)
    {
        if (candidates[i].vote > (votes / 2))
        {
            printf("\nwinner %s\n", candidates[i].name);
            return 1;
        }
    }
    return 0;
}

int find_min()
{
    int min = candidates[0].vote;
    for (int i = 0; i < num; ++i)
    {
        if ((candidates[i].absent == 0) && (candidates[i].vote < min))
            min = candidates[i].vote;
    }
    return min;
}

short int is_tie(int min)
{
    for (int i = 0; i < num; ++i)
    {
        if ((min != candidates[i].vote) && (candidates[i].absent == 0))
            return 0;
    }
    return 1;
}

void elmination(int min)
{
    for (int i = 0; i < num; ++i)
    {
        if (candidates[i].vote == min)
            candidates[i].absent = 1;
    }
    return;
}