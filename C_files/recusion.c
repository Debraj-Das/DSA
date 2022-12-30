#include <stdio.h>
#include <stdlib.h>

 void drew(int hight);

int main()
 {
    int hight;
    printf("Enter the hight of premide :");
    scanf("%d",&hight);
    drew(hight);
    return 0;
 }

 void drew(int hight)
 {
     if(hight==1)
     {
         printf("#\n");
         return ;
     }
    drew(hight-1);
    for(int i=0;i<hight;++i) printf("#");
    printf("\n");
    return ;
 }