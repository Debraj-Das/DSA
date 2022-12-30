//Name:Debraj Das
//Roll no-21CH30010
//lec:5 Homework:1
#include <stdio.h>

int main()
{
    int t;
    printf("Boiling point of the substance(in celsius):");
    scanf("%d",&t);
    printf("This substance is ");
    switch(t){
    case 100: printf("water.");
    break;
    case 357: printf("mercury.");
    break;
    case 1187: printf("cupper.");
    break;
    case 2193: printf("silver.");
    break;
   case 2660: printf("gold.");
    break;
        default:printf("unknown.");}
    return 0;
}
