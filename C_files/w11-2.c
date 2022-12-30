/*Name-Debraj Das
   Roll no-21CH30010*/

#include <stdio.h>
#include <string.h>

struct student
{
    char r[10];
    char n[100];
};

int main()
{
    struct student *p;
     int i,j,x,k=0;
     char s[10],re[10],*z;
     z=re;
    printf("How many students? ");
    scanf("%d",&i);
    p=(struct student *)malloc(i*sizeof(struct student));
    printf("Enter roll numbers and names (sorted by roll number): \n");
    for(j=0; j<i; ++j)
    {
        scanf("%s%[^\n]s",p[j].r,p[j].n);
    }
    printf("Enter prefix: ");
    scanf("%s",s);
    printf("\nFound:\n");
    x =strlen(s);
    for(j=0; j<i; ++j){
        strcpy(z,p[j].r);
        strcpy(z+x," ");
        if(strcmp(z,s)==0){
            printf("%s %s\n",p[j].r,p[j].n);
            k=1;
        }
    }
    if(k==0) printf("None found !");
    return 0;
}
