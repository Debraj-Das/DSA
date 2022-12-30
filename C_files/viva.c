#include <stdio.h>
#include <stdlib.h>


int add(int x){

  if(x==1) return 1;
  return x+add(x-1);
}

int main(int ,char *argv[])
{
   int x;
   scanf("%d",&x);
   printf("%d",add(x));
    return 0;
}
