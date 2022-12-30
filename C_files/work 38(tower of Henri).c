/*name-Debraj Das
  roll no-21CH300100*/

#include <stdio.h>

void tower(int ,char,char,char );

int j=0;

int main()
{
    int n;
    while(1)
    {
        printf("Enter the number of block : ");
        scanf("%d",&n);
        if(n==0)
        {
            printf("Thus no of block zero. So process is not executes.\n\n");
            return 0;
        }
        printf("\n Process execution start : \n");
  tower(n,'A','C','B');
        j=0;
        printf("\nFor Exit the execution enter Zero.\n\n");
    }
}

void tower(int n, char from, char to, char aux)
{ if (n==1)
 {  printf ("%3d.Step: Disk 1 : %c ---> %c \n",++j, from, to) ;
    return ;
 }
   tower (n-1, from, aux, to) ;
   printf ("%3d.Step: Disk %d : %c ---> %c\n",++j, n, from, to) ;
   tower (n-1, aux, to, from) ;
   return ;
}
