/*name-Debraj Das
  roll no-21CH30010*/

#include <stdio.h>

int main()
{
   int a,b,c;
   while(1){
   printf("Enter the numerator : ");
   scanf("%d",&a);
     if(a==0) break ;
    printf("Enter the denominator : ");
   scanf("%d",&b);
   if(b==0) break ;
   printf("[%d",a/b);
   c=a;
   a=b;
   b=(c%b);
   if(b!=0) printf("; ");
   while(b!=0){
    printf("%d",a/b);
   c=a;
   a=b;
   b=(c%b);
   if(b!=0) printf(", ");
   }
   printf("].\n\n");
   printf("If you want to exit from execution,Then enter the numerator Zero.\n\n");
   }
   if(a==0) printf("You finish your execution.\n");
   else printf("Your number is indeterminate.So Execution is terminate.\n ");
    return 0;
}
