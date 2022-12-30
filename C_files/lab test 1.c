#include <stdio.h>
#include <stdlib.h>

int main()
{
    int seed, i;
  printf("Enter seed: ");
  scanf("%d",&seed);
  srand(seed);
  for(i=0; i<5; i++)
    printf("%2d ", rand()%100);
  printf("\n");
    return 0;
}
