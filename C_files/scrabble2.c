#include <stdio.h>
#include <stdlib.h>

int point()
{
    static int i=0;
    int n=0,p[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    char s;
    printf("player %d : ",++i);
    while (1)
    {
        scanf("%c",&s);
        if(s=='\n') break;
        if(s>='a'&&s<='z') {
        s-='a';
        n+=p[s];
        }
        if(s>='A'&&s<='Z') 
        {
            s-='A';
            n+=p[s] ;
        }
    }
    return n;
}

int main()
 {
    int p[10],higher;
    higher= p[0]=point();
    for(int i=1;p[i-1]!=0;++i)
     {
         p[i]=point();
         if(higher<p[i]) higher=p[i];
     }
     for(int j=0;p[j]!=0;++j)
     {
         if(higher==p[j]) printf("player %d is one of the first.\n",j+1);
     }
     for(int j=0;p[j]!=0;++j) printf("points of player %d is %d\n",j+1,p[j]);
    return 0;
 }