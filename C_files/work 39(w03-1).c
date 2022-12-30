/*name-Debraj Das
  roll no-21CH30010*/

#include <stdio.h>

int main()
{
    int d,m,y;
    printf("Execution Start :\n");
      while(1){
            printf("If you want to exit form execution : enter Zero.\n\n");
    printf("Enter the date : ");
    scanf("%d",&d);
    if(d==0)  break ;
    y=d%10000;
    d=d/10000;
    m=d%100;
    d=d/100;
    printf("Day : %d\nMonth : %d\nYear : %d\n",d,m,y);
    if(y>2099)
    {
        printf("After 2099.\n");
        continue ;
    }
    if(y<2021)
    {
        printf("Before 2021.\n");
        continue ;
    }
    if(m>12)
    {
        printf("Month out of range.\n");
        continue ;
    }
    switch(m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        if(d>31)
        {
            printf("Day out of range.\n");
           continue ;
        }
    } break ;
    case 2:
    {
        if(d>29&&y%4==0)
        {
            printf("Day out of range.\n");
           continue ;
        }
        else if(d>28)
        {
            printf("Day out of range.\n");
            continue ;
        }
    }  break ;
    default :
    {
        if(d>30)
        {
            printf("Day out of range.\n");
            continue ;
        }
    }
    }
    switch(m-1)
    {
    case 1:
        d=d+3;
        break ;
    case 2:
    {
        if(y%4==0) d=d+4;
        else d=d+3;
    }
break ;
    case 3:
    {
        if(y%4==0) d=d+0;
        else d=d+6;
    }
break ;
    case 4:
    {
        if(y%4==0) d=d+2;
        else d=d+1;
    }
break ;
    case 5:
    {
        if(y%4==0) d=d+5;
        else d=d+4;
    }
break ;
    case 6:
    {
        if(y%4==0) d=d+0;
        else d=d+6;
    }
break ;
    case 7:
    {
        if(y%4==0) d=d+3;
        else d=d+2;
    }
break ;
    case 8:
    {
        if(y%4==0) d=d+6;
        else d=d+5;
    }
break ;
    case 9:
    {
        if(y%4==0) d=d+1;
        else d=d+0;
    }
break ;
    case 10:
    {
        if(y%4==0) d=d+4;
        else d=d+3;
    }
break ;
    case 11:
    {
        if(y%4==0) d=d+6;
        else d=d+5;
    }
break ;
    }
    y=y-2021;
    d=d+y+y%4;
    d=(d+4)%7;
    switch(d)
    {
    case 0:
        printf("It's a Sunday of ");
        break ;
    case 1:
        printf("It's a Monday of ");
        break ;
    case 2:
        printf("It's a Tuesday of ");
        break ;
    case 3:
        printf("It's a Wednesday of ");
        break ;
    case 4:
        printf("It's a Thursday of ");
        break ;
    case 5:
        printf("It's a Friday of ");
        break ;
    case 6:
        printf("It's a Saturday of");
        break ;
    }
    switch(m)
    {
    case 1:
        printf("January.\n");
        break ;
    case 2:
        printf("February.\n");
        break ;
    case 3:
        printf("March.\n");
        break ;
    case 4:
        printf("April.\n");
        break ;
    case 5:
        printf("May.\n");
        break ;
    case 6:
        printf("June.\n");
        break ;
    case 7:
        printf("July.\n");
        break ;
    case 8:
        printf("August.\n");
        break ;
    case 9:
        printf("September.\n");
        break ;
    case 10:
        printf("October.\n");
        break ;
    case 11:
        printf("November.\n");
        break ;
    case 12:
        printf("December.\n");
        break ;
    }
    printf("\nRe again Execution Start :\n");
    }
    printf("Execution code is finish.\n");
    return 0;
}
