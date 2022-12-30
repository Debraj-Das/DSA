/*Name-Debraj Das
  Roll no-21CH30010*/

#include <stdio.h>
typedef struct
{
    int n;
    char su;
} card;

#if defined(_WIN32) || defined(__MSDOS__)
#define club    "\x05"
#define diamond "\x04"
#define heart   "\x03"
#define spade   "\x06"
#else
#define club    "\xe2\x99\xa3"
#define diamond "\xe2\x99\xa6"
#define heart   "\xe2\x99\xa5"
#define spade   "\xe2\x99\xa0"
#endif

int main()
{
    card cd[48],t;
    char s[144];
    int i,j,k;
    printf("Enter the sequence of cards: \n");
    scanf("%[^\n]s",s);
    for(i=0,j=0; (i==0||s[i-1]!='\0'); i+=3,++j)
    {
        cd[j].su=s[i+1];
        switch(s[i])
        {
        case '2':
            cd[j].n=2;
            break ;
        case '3':
            cd[j].n=3;
            break ;
        case '4':
            cd[j].n=4;
            break ;
        case '5':
            cd[j].n=5;
            break ;
        case '6':
            cd[j].n=6;
            break ;
        case '7':
            cd[j].n=7;
            break ;
        case '8':
            cd[j].n=8;
            break ;
        case '9':
            cd[j].n=9;
            break ;
        case 'J':
            cd[j].n=11;
            break ;
        case 'Q':
            cd[j].n=12;
            break ;
        case 'K':
            cd[j].n=13;
            break ;
        case 'A':
            cd[j].n=14;
            break ;
        }
    }
     printf("\nAfter ordering: \n");
    for(i=0; i<j; ++i)
    {
        for(k=i+1; k<j; ++k)
        {
            if((cd[i].su>cd[k].su)||(cd[i].su==cd[k].su&&cd[i].n>cd[k].n))
            {
                t=cd[i];
                cd[i]=cd[k];
                cd[k]=t;
            }
        }
        switch(cd[i].n)
        {
        case 1:
            printf("1");
            break ;
        case 2:
            printf("2");
            break ;
        case 3:
            printf("3");
            break ;
        case 4:
            printf("4");
            break ;
        case 5:
            printf("5");
            break ;
        case 6:
            printf("6");
            break ;
        case 7:
            printf("7");
            break ;
        case 8:
            printf("8");
            break ;
        case 9:
            printf("9");
            break ;
        case 11:
            printf("J");
            break ;
        case 12:
            printf("Q");
            break ;
        case 13:
            printf("K");
            break ;
        case 14:
            printf("A");
            break ;
        }
        switch(cd[i].su)
        {
        case 'C':
            printf("%s ",club);
            break ;
        case 'D':
            printf("%s ",diamond);
            break ;
        case 'H':
            printf("%s ",heart);
            break ;
        case 'S':
            printf("%s ",spade);
            break ;
        }
    }
 printf("\n\n");
    return 0;
}
