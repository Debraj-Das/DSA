#include <stdio.h>
#include <stdlib.h>

int main()
{
      double math , physic , chemistry ;
      printf("Enter the math number :: ");
      scanf("%lf",&math);
      printf("Enter the physic number :: ");
      scanf("%lf",&physic);
      printf("Enter the chemistry number :: ");
      scanf("%lf",&chemistry);
      double average = (math + physic + chemistry)/3 ;
      if(math>=33 && physic >= 33 && chemistry >= 33 && average >= 40)
            printf("You are passed.\n");
      else 
            printf("You are failed.\n");
     return 0;
}