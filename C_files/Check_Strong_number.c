#include <stdio.h>

int factor(register int n)
{
    register int val=1 ;
    for(register int i = 1;i<=n;++i)
        val*=i;
    return val;
}

int main()
{
    int num ;
    printf("Enter a number :: ");
    scanf("%d",&num);
    register int new_num = 0 ;
    for(register int tump = num;tump;tump/=10)
    {
        new_num+=factor(tump%10);
    }
    if(new_num==num)
        printf("%d is a strong number\n",num);
    else 
        printf("%d is not a strong number\n",num);
    
    return 0;
}