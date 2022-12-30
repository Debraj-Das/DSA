//name-Debraj Das
//roll no-21CH30010

#include <stdio.h>
#include <stdlib.h>

void clear() {
  while(getchar()!='\n');
}

int main()
{
    char y,c;
    int i=0,x,w=0,d=0,l=0;
    printf("Start the rock paper sizer Game : \n");
    while(1)
    {
        printf("If you want to choice Rock type r.\n\t\t     Paper type p.\n\t\t     Scissor type s.\n\t\t if you want to see result than type a.\n");
        printf("Choice your option : ");
        scanf("%c",&y);
        clear();
        if(y=='a')
        {
            printf("\nOver result untill now,\n\tyou win overall %d.\n\t\t Lose %d\n\t\t Draw %d\n",w,l,d);
            printf("Choice your option : ");
            scanf("%c",&y);
             clear();
        }
         if(y != 'r'&&y != 'p'&& y != 's')  break ;
         i=(i+3)%10;
        srand(i);
        x=rand()%100;
        if(x%3==0) c='r';
        else if(x%3==1) c='p';
        else c='s';
        printf("  Computer choice %c,\n So,",c);
        if(y==c)  {
            printf("match is draw,\n");
            ++d;
        }
        else if((y=='p'&&c=='r')||(y=='s'&&c=='p')||(y=='r'&&c=='s'))
        {
            printf("you are win the match.\n");
            ++w;
        }
        else {
            printf("you are lose the match.Best of luck for again,\n");
            ++l;
        }
        printf("\nMatch is start again.if you exit from the game than choice other any character.\n\n");
    }
    printf("\nGame is over now,\n\tyou win overall %d.\n\t\t Lose %d\n\t\t Draw %d\n",w,l,d);
    return 0;
}
