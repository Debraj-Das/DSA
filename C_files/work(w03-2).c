/*name-Debraj Das
   roll no-21CH30010*/

#include <stdio.h>

int main()
{
   int a,b;
   double x;
    printf("Following are 12 items and their rates (INR): \n\n");
    printf("SN           ITEM                                        RATE \n");
    printf(" --         ----                                            ---- \n\n");
    printf("01:          BUTTER COOKIES                        25 \n");
    printf("02:          CASHEW COOKIES                       30\n");
    printf("03:          CREAM CAKE                                  22\n");
    printf("04:          LEMON JUICE                                 35 \n");
    printf("05:          VEG CASHEW CAKE                     18 \n");
    printf("06:          MANGO JUICE                                78\n");
    printf("07:          COOKIES (PLAIN)                          15\n");
    printf("08:          ORANGE JUICE                              73 \n");
    printf("09:          MILK BISCUITS                               12 \n");
    printf("10:          PLAIN VEG CAKE                            20\n");
    printf("11:          BUTTER FRUIT CAKE                   25 \n");
    printf("12:          PINEAPPLE JUICE                          65\n\n");
    printf("Enter the Serial Number (SN) of item and the quantity you want: ");
    scanf("%d%d",&a,&b);
    printf("Your item is ");
    switch(a){
    case 1:  {printf("BUTTER COOKIES x%d\n",b); a=25*b;}
    break ;
     case 2:  {printf("CASHEW COOKIES x%d\n",b); a=30*b;}
    break ;
     case 3:  {printf("CREAM CAKEx%d\n",b); a=22*b;}
    break ;
     case 4: { printf("LEMON JUICE x%d\n",b);  a=35*b;}
    break ;
     case 5:  {printf("VEG CASHEW CAKE x%d\n",b);  a=18*b;}
    break ;
     case 6:  {printf(" MANGO JUICE x%d\n",b); a=78*b;}
    break ;
     case 7:  {printf(" COOKIES (PLAIN) x%d\n",b);  a=15*b;}
    break ;
     case 8: { printf("ORANGE JUICE x%d\n",b); a=73*b;}
    break ;
     case 9:  {printf("MILK BISCUITSx%d\n",b);  a=12*b;}
    break ;
     case 10:  {printf(" PLAIN VEG CAKE x%d\n",b); a=20*b;}
    break ;
     case 11: { printf("BUTTER FRUIT CAKEx%d\n",b);  a=25*b;}
    break ;
     case 12:  {printf("PINEAPPLE JUICEx%d\n",b);  a=65*b;}
    break ;
    }
    x=a;
    printf("Basic price        = Rs. %6.2lf \n",x);
    printf("Tax @12.5%          = Rs. %6.2lf\n",x=x*0.125);
    printf("Total price        =  Rs.%6.2lf\n",a+x);
    printf("=========================\n");
  if((((int)(x*100))%100)<50)  a=a+x;
  else a=a+x+1;
    printf("To pay            =Rs.   %6d.00\n",a);
    printf("=========================\nThank you! \nPlease visit us again.\n");

    return 0;
}
