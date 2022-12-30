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
     for(i=0;i!='/n';++i)
        printf("%c",&p[i]);
     printf("\nPoet name: ");
     for(i+=2;i!='\n';++i)
        printf("%c",p[i]);
        printf("\n\n");
        for(i+=2;i!='\0';++i) {
            if(p[i]==' ') ++w;
            else if(p[i]=='\n')  ++l;
             else if(p[i]=='\n'&&p[i-1]=='/n')  ++s;
             else if(p[i]=='.'|| p[i]==','|| p[i]==':'|| p[i]==';'|| p[i]== '!'|| p[i]== '?') ++pu;
        }
     printf("Lines: %d",l);
      printf("Words: %d",w);
     printf("Stanzas: %d",s);
     printf("Punctuation marks: %d",pu);
    return 0;
}
