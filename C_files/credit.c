#include <stdio.h>
#include <stdlib.h>

int main()
 {
    long long int num,n;
    int i,j=0;
    do 
    {
        printf("Enter the Credit card number : ");
        scanf("%lld",&num);
    }
    while(num<1e10);
    for(i=0,n=num;n>0;++i) n/=10;
    if(i==15)
    {
        n=num;
        while(n>100) n/=10;
        if(n==34||n==37) i=1;
        else 
        {
            printf("unknown card .");
            return 0;
        }
    }
    else if(i==16)
    {
        n=num;
        while(n>100) n/=10;
        if(n>=51&&n<=55) i=2;
        else 
        {
            if(n/10==4) i=3;
            else 
            {
              printf("unknown card .");
            return 0;  
            }
        }
    }
    else if(i==13)
    {
        n=num;
        while(n>10) n/=10;
        if(n/10==4) i=3;
            else 
            {
              printf("unknown card .");
            return 0;  
            }
    }
    while(num>0)
    {
        n=num%10;
        j+=n;
        num/=10;
        n=num%10;
        n*=2;
        if(n>10) 
        {
            while(n>0) 
            {
                j+=n%10;
                n/=10;
            }
        }
        else 
        {
            j+=n;
        }
        num/=10;
    }
    if(j%10!=0) 
    {
        printf("invaild number.");
        return 0;
    }
    switch(i)
    {
        case 1: printf("American credit card.\n");
        break;
        case 2:  printf("Master credit.\n");
        break;
        case 3: printf("Visa card.");
    }
    return 0;
 }