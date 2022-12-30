#include <stdio.h>

//Complete the following function.


void calculate_the_maximum(int n, int k)
{
    int a,b,i,j,e=1,p,q;
    int and=0,or=0,xor=0;
    int c=0,d=0,f=0;
    int m=0;
    for(a=1; a<n; ++a)
    {
        for(b=a+1; b<=n; ++b)
        {
            for(i=a,p=b; i||p; i/=2,p/=2)
            {
                j=i%2;
                q=p%2;
                c+=(j&&q)*e;
                d+=(j||q)*e;
                f+=(j!=q)*e;
                e*=2;
            }
            ++m;
            printf("%2d.a=%d,b=%d;a&b=%d;a|b=%d;a+b=%d;\n",m,a,b,c,d,f);
            if(c>and&&c<k) and=c;
            if(d>or&&d<k) or=d;
            if(f>xor&&f<k) xor=f;
            c=0;
            d=0;
            f=0;
            e=1;
        }
    }
    printf("And = %d\nOR = %d\nXOR = %d",and,or,xor);
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
