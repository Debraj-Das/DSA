#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *scanstring(char *q)
{
    char a[10000],*p;
    printf("%s",q);
    scanf("%[^\n]s",a);
    int i =strlen(a)+1;
    p=(char *)malloc(i*sizeof(char));
    for(int j=0;j<i;++j)
    p[j]=a[j];
    return p;
}

int main()
 {
    char *name;
    name=scanstring("Enter the name of Your :");
    printf("Hellow %s\n",name);
    free(name);
    return 0;
 }