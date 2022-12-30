#include <stdio.h>

int main()
{
    char name[12],surname[12];
    int i,j;
    printf("Enter the name and surname :");
    scanf("%s%s",name,surname);
    printf("result : ");
    for(i=0; name[i]||surname[i]; ++i)
    {
        if(name[i]>90&&name[i])
        {
            name[i]=name[i]+'A'-'a';
        }
        if(name[i])  printf("%c",name[i]);
        if(surname[i]<90&&surname[i])
        {
            surname[i]=surname[i]-'A'+'a';
        }
        if(surname[i])  printf("%c",surname[i]);
    }


    return 0;
}
