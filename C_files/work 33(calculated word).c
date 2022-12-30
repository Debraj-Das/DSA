/*name-Debraj Das
  Roll no-21CH30010 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char d[100000];
    int i,j=0;
    printf("Enter the sentence :\n");
    scanf("%[^#]s",d);
    for(i=0;d[i]!='\0';++i)
        if(d[i]==' ') ++j;
        printf("Number of word :%d",j);
    return 0;
}
