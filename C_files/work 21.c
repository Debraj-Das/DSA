//Name:DEbraj Das
//Roll no-21CH30010
//lec 6 Homework 2
#include <stdio.h>

int main()
{
    double M;
    printf("Mark of the student out of 100 is ");
    scanf("%lf",&M);
    printf("Grade of the student is ");
    if (0<=M&&M<=35)
        printf("F");
    else if (35<M&&M<=50)
        printf("P.");
      else if (50<M&&M<=60)
        printf("D.");
       else if (60<M&&M<=700)
        printf("C.");
      else if (70<M&&M<=80)
        printf("B.");
       else if (80<M&&M<=90)
        printf("A.");
        else if (90<M&&M<=100)
        printf("EX.");
        else printf("value of mark has error.");
    return 0;
}
