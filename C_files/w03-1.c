//Name:Debraj Das
//Roll no-21CH30010

#include <stdio.h>

int main()
{
    int y,m,d,a;
    printf("Enter date: ");
    scanf("%d",&a);
    y=a%10000;
    a=a/10000,m=a%100;
    a=a/100,d=a%100;
    printf("Day:%d\nMouth:%d\nYear:%d\n",d,m,y);
    if(y<2021) printf("Bofore 2021");
    else if(y>2099) printf("After 2099");
    else if (m>12) printf("Mouth out of range.");
    else if (d>28) {
        switch(m) {
      case 1:
      case 3:
       case 5:
      case 7:
      case 8:
      case 10:
      case 12:  {if(d>31) printf("Day out of range.");}
      break;
      case 4:
      case 6:
      case 9:
      case 11: {if(d>30) printf("Day out of range."); }
      break ;
      case 2: { if((d>29)||(d=29&&y%4!=0)) printf("Day out of range.");}
      break ; }
    }
    else {
        a=d+((13*m-1)/5)+(y%100)+(y%100)/4-35 ;
    a=a%7 ;
    switch(a) {
    case 0: printf("It's a Sunday of ");
    break ;
    case 1: printf("It's a Monday of ");
    break ;
    case 2: printf("It's a Tuesday of ");
    break ;
    case 3: printf("It's a Wednesday of ");
    break ;
    case 4: printf("It's a Thursday of ");
    break ;
    case 5: printf("It's a Friday of ");
    break ;
    case 6: printf("It's a Saturday of ");
    break ; }
    switch(m) {
    case 1:printf("January.");
    break ;
    case 2:printf("February.");
    break ;
    case 3:printf("March.");
    break ;
    case 4:printf("April.");
    break ;
    case 5:printf("May.");
    break ;
    case 6:printf("June.");
    break ;
    case 7:printf("July.");
    break ;
    case 8:printf("August.");
    break ;
    case 9:printf("September.");
    break ;
    case 10:printf("October.");
    break ;
    case 11:printf("November.");
    break ;
    case 12:printf("December.");
    break ; }
    }

    return 0;
}
