/* name-Debraj Das
   Roll no-21CH30010*/

#include <stdio.h>
#include<math.h>

int main()
{
    double x,n;
    int p=0;
    char c;
    while(1)
    {
        printf("1.For input final amount : \n\t\t a.For normal amount f__ .\n \t\t b.For multiple of initial amount  m__. ");
        printf("\n2.For input pride type __d __m __y .");
        printf("\n3.Interest(alway percentage)\n \t\t a.for simple s__.\n\t\t b.for complex c__ .");
        printf("\n4.For exit give initial amount zero(0).\n");
        printf("Enter the initial amount :");
        scanf("%lf",&x);
        if(x==0)
        {
            printf("Finish the Execution.\n");
            break;
        }
        printf("Enter the final amount : ");
        c=getchar();
        scanf("%lf",&n);
       if(c=='f') n/=x;
        printf("Enter the pride :");
       while(c!='\n')
       {
            scanf("%lf",&x);
            c=getchar();
            if(c=='d') p+=x;
            else if(c=='m') p+=x*30;
            else p+=x*365 ;
            scanf("%c",&c);
        }
        printf("\nEnter the interest :");
       c=getchar();
        scanf("%lf",&x);
        if(c=='c')    n= (log(n)/log(1+x/100));
        else n=((n-1)*100)/x;
        p*=n;
        printf("\nNeed time is : %d Days ",p%30);
        if(p/30!=0) printf("%d Mouths",(p/30)%12);
        if(p/365!=0) printf("%d Years",(p/365));
        printf(".(%d)\n",p);
    }
    printf("For next Execution Run the code again.\n");
    return 0;
}
