/*Name-Debraj Das
   Roll no-21CH30010*/

#include <stdio.h>
#include <string.h>

struct student
{
    char r[10];
    char n[100];
};

void swap(struct student *A, struct student *B,int k)
{
    int x;
    struct student t;
    if(k==0) x=strcmp(A->n,B->n);
    else x=strcmp(A->r,B->r);
    if(x>0)
    {
        t=*A;
        *A=*B;
        *B=t;
    }
    return ;

}

int main()
{
    struct student *p;
    int i,j,k,l;
    printf("How many students? ");
    scanf("%d",&i);
    p=(struct student *)malloc(i*sizeof(struct student));
    printf("Enter roll numbers and names: \n\n");
    for(j=0; j<i; ++j)
    {
        scanf("%s%[^\n]s",p[j].r,p[j].n);
    }
    printf("\nEnter 1 to sort by roll number, 0 to sort by name: ");
    scanf("%d",&k);
    printf("After sorting by roll number:\n\n");
    for(j=0; j<i; ++j)
    {
        for(l=j+1; l<i; ++l)
        {
            swap(p+j,p+l,k);
        }
        printf("%2d. %s %s\n",j+1,p[j].r,p[j].n);
    }
      free (p);

    return 0;
}
