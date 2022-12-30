//Name:Debraj Das
////Roll no-21CH30010

#include <stdio.h>

int main()
{
  int x;
  printf("The number of day:");
  scanf("%d",&x);
  switch(x){
  case 0: printf("Sunday");
  break;
  case 1: printf("Monday");
  break;
  case 2: printf("Tuesday");
  break;
  case 3: printf("Wednesday");
  break;
  case 4: printf("Thuresday");
  break;
  case 5: printf("Friday");
  break;
  case 6: printf("Saturday");
  break;
  default: printf("Error---invaild number for day");
  }
    return 0;
}
