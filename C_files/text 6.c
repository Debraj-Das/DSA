/*Name-Debraj Das
roll no-21CH30010
Q: some concept practice from the Lecture */

#include <stdio.h>

int main()
{
    double a = 1.256e2;
    int c;
    char i;
    scanf("%d%lf",&c,&a);
    printf("print the float number: %2.2lf\n",a);    //test of special backslash characters.
    printf("bite of int %d\nbite of float %d\nbite of char %d\nscan the char variable:",sizeof(c),sizeof(a),sizeof(i));//test of size of date types.
    i=getchar();            //used of getchar function.
    printf("output of char variable %c",i);
   /* scanf("%d",&c);
    const int b=c;  //incorrect due to variable declared middle of the code.
    printf("print the constant variable %d.\n",b);  */
    return 0;
}
