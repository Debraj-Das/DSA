/*Name-Debraj Das
   Roll no-21CH30010 */

#include <stdio.h>


int main()
{
    int i,l=0,w=0,s=0,pu=0;
    char p[1000];
    printf("Enter a poem with its name and poet:\n");
    scanf("%[^#]s",p);
    printf("Poem name: ");
    for(i=0; p[i]!='\n'; ++i)
        printf("%c",p[i]);
    printf("\nPoet name: ");
    for(i+=2; p[i]!='\n'; ++i)
        printf("%c",p[i]);
    printf("\n\n");
    for(i+=2; p[i]!='\0'; ++i)
    {
        if(p[i]==' '||p[i]=='\n') ++w;
         if(p[i]=='\n')  ++l;
         if(p[i]=='\n'&&p[i-1]=='\n')  ++s;
         if(p[i]=='.'|| p[i]==','|| p[i]==':'|| p[i]==';'|| p[i]== '!'|| p[i]== '?') ++pu;
    }
    printf("Lines: %d\n",l-s);
    printf("Words: %d\n",w-s);
    printf("Stanzas: %d\n",s+1);
    printf("Punctuation marks: %d\n",pu);
    return 0;
}
