#include <stdio.h>
#include <stdlib.h>

int main()
 {
    int intial,final,n;
    do {
        printf("Intial population :");
        scanf("%d",&intial);
    }
    while(intial<9);
    do {
        printf("Final population :");
        scanf("%d",&final);
    }
    while(final<intial);
  for(n=0;intial<final;++n) 
  {
      intial+=(intial/3-intial/4);
  }
  printf("Year : %d\n",n);
    return 0;
 }