#include <stdio.h>
#include <stdlib.h>

int main()
 {
    long double chack ;
    printf("Enter a no: ");
    scanf("%Lf",&chack);
    printf("No. entered is %Lf\n",chack);
    if(chack==23.6) printf("True\n");
    else printf("Faluse\n");
    return 0;
 }

   /* TEXT Part for learning purpose --> 
      C language float type value store in double type ram storage so you use equally logical opration 
      for other then double type it give some time nonsence result.
      like if I do this by float type or long double type it gives nonsence result.
      so using equally logical opration on float always careful. */