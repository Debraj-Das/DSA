//Name-Debraj Das
//Roll no-21CH30010

#include <stdio.h>

 typedef struct {
     char s[30];
 }str ;
 str Getstring(char c[20]){
     str a;
     int i=-1;
     printf("%s\n",c);
     do {
        scanf("%c",&a.s[++i]);
     }
     while(a.s[i]!='\n');
     a.s[i]='\0';
     return a;
 }



int main()
{
    str anwer;
    printf("Hello Everyone.\n");
   anwer=Getstring("What is Your name?");
    printf("Hello %s.",anwer.s);
    return 0;
}
