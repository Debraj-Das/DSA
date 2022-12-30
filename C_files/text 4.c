//Name-Debraj Das
//Roll no-21CH30010

#include <stdio.h>

int main()
{
    int a[204],n,i,A,B,temp;
    printf("Enter numerator and denominator of fraction 1 in reduced form ");
    scanf("%d%d",&a[0],&a[1]);
    printf("Enter numerator and denominator of fraction 2 in reduced form ");
    scanf("%d%d",&a[202],&a[203]);
    printf("Enter number of fractions:");
    scanf("%d",&n);
    for(i=0;i<=n;i=i+2){
     A=a[i+2]=a[i]+a[202];
     B=a[i+3]=a[i+1]+a[203] ;
     printf("Fraction %d:%d/%d",i/2+1,a[i+2],a[i+3]);
     if  (A > B)  {
          temp = A;  A = B;  B = temp;
    }
	while ((B % A) != 0)  {
		temp = B % A;
		B = A;
		A = temp;
	}
	printf("GCD of numerator and denominator=%d\n",A);
     a[i+2]/=A;
    a[i+3]/=A;
    printf("Fraction %d in reduced form=%d/%d\n",i/2+1,a[i+2],a[i+3]);
       }
       printf("All fractions\n");
       i=0;
       while(i<=n){
        printf("%d/%d\n",a[i],a[i+1]);
        ++i;
       }
    return 0;
}
