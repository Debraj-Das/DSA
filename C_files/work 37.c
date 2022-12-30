/*name-Debraj Das
  roll no-21CH300100*/

#include <stdio.h>

void tower(char,char,char,int );

int j=0;

int main()
{
    char a,b,c;
    int n;
    a='A';
    b='B';
    c='C';
    while(1)
    {
        printf("Enter the number of block : ");
        scanf("%d",&n);
        if(n==0)
        {
            printf("Thus no of block zero. So process is not executes.");
            return 0;
        }
        printf("\n Process execution start : \n");
        if(n%2==0) tower(a,b,c,n-1);
        else if(n==1)  printf("%3d.step %c ---> %c.\n",1,a,c);
        else  tower(a,c,b,n-1);
        j=0;
    }
    return 0;
}

void tower(char a,char b,char c,int n)
{
    char t;
    int i;
    if(n==0)  return ;
    printf("%3d.step %c ---> %c.\n",++j,a,b);
    printf("%3d.step %c ---> %c.\n",++j,a,c);
    printf("%3d.step %c ---> %c.\n",++j,b,c);
    for(i=1; i<n; ++i)
    {
        t=c;
        c=b;
        b=t;
        printf("%3d.step %c ---> %c.\n",++j,a,c);
        tower(b,a,c,i);
    }
    return ;

}
