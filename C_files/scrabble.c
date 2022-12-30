#include <stdio.h>
#include <stdlib.h>

int pointstring(int i)
{
    int p[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int n = 0;
    char s[20];
    printf("player %d :",i);
    scanf("%s",s);
    for(int j=0;s[j]!='\0';++j)
    {
        i=s[j]-'a';
        n+=p[i];
    }
    printf("%d\n", n);
    return n;
}

int main()
{
    int p[2];
    for (int i = 0; i < 2; ++i)
    {
        p[i] = pointstring(i + 1);
         while(getchar()!='\n');
    }
    if (p[0] < p[1])
        printf("\nplayer 2 win.");
    else if (p[0] > p[1])
        printf("\nplayer 1 win.");
    else
        printf("\nMatch is drawing.");
    return 0;
}