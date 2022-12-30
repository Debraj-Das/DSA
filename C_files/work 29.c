//Name-Debraj Das
//Roll no-21CH30010
//In input range ,find the prime number &no of prime & non prime number.
#include <stdio.h>

int main()
{
    int a,b,c,d,n,r;
    printf("Enter the Range:");
    scanf("%d%d",&a,&b);
    printf("prime number in the range (%d-%d):",a,b);
    for(r=b-a+1,n=0;a<=b;++a){
        c=2,d=1;
        while(c<a){
            if(a%c==0) {d=0;
            break;}
            ++c;
        }if(d==1&&a!=1){printf("%d.",a),++n;}
    } printf("\nIn (%d-%d) range no of prime number is %d.\nAnd non prime is %d.",b-r+1,b,n,r-n);
    return 0;
}
