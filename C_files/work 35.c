/*Name-Debraj Das
 Roll no-21CH30010*/

#include <stdio.h>
#include <string.h>

int main()
 {
    char name[20],a[10];
    int d, m, y;
    printf("Enter your name :");
    scanf("%[^\n]s",name);
    printf("Enter your Date of birth(DD MM YYYY) : ");
    scanf("%d%d%d",&d,&m,&y);
    switch(m)
    {
    default:
    {
        printf("\nYou enter wrong mouth.So again enter the mouth : ");
        scanf("%d",&m);
        printf("\n");
    }
    case 1:
    {
        char mon[10]="January";
        strcpy(a,mon);
    }
    break;
    case 2:
    {
        char mon[10]="February";
        strcpy(a,mon);
    }
    break;
    case 3:
    {
        char mon[10]="March";
        strcpy(a,mon);
    }
    break;
    case 4:
    {
        char mon[10]="March";
        strcpy(a,mon);
    }
    break;
    case 5:
    {
        char mon[10]="May";
        strcpy(a,mon);
    }
    break;
    case 6:
    {
        char mon[10]="June";
        strcpy(a,mon);
    }
    break;
    case 7:
    {
        char mon[10]="July";
        strcpy(a,mon);
    }
    break;
    case 8:
    {
        char mon[10]="August";
        strcpy(a,mon);
    }
    break;
    case 9:
    {
        char mon[10]="September";
        strcpy(a,mon);
    }
    break;
    case 10:
    {
        char mon[10]="October";
        strcpy(a,mon);
    }
    break;
    case 11:
    {
        char mon[10]="November";
        strcpy(a,mon);
    }
    break;
    case 12:
    {
        char mon[10]="December";
        strcpy(a,mon);
    }
    break;

    }
    printf("Your name is %s\n Your Date of birth is %d",name,d);
    if(d==1) printf("st ");
    else if(d==2)  printf("nd ");
    else if(d==3)  printf("rd ");
    else  printf("th ");
    printf(" %s %d\n",a,y);
    return 0 ;
}
