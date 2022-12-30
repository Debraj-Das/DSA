//Name-Debraj Das
//Roll no-21CH30010

#include <stdio.h>

int main()
{
    int i,a[100],n=0,m,t,low,up;
    printf("Enter the option ");
    scanf("%d",&i);
    while(i != 5){
        switch(i) {
    case 1: {printf("Enter the number ");
            scanf("%d",&a[n]);
            ++n;
            for(m=0;m<=n;++m){
                if(a[m]==a[n]) {--n;
                break;}
                for(m=0;m<n;++m)  {
                    if(a[m]>a[n]){
                        t=a[m],a[m]=a[n],a[n]=t;
                     }  }  }  }
                    break ;
    case 2: {
    printf("Enter lower limit :") ;
    scanf("%d",&low);
    printf("Enter upper limit :") ;
    scanf("%d",&up);
    for(m=n,t=n;m>=0;--m){
        if(low<=a[m]&&a[m]<=up){
            a[m]=a[t];
            for(m=0;m<n;++m)  {
                    if(a[m]>a[n]){
                        t=a[m],a[m]=a[n],a[n]=t;
                     }  --n;
        }  }  }  } break;
        case 3:{  printf("Enter the number ");
        scanf("%d",&t);
             for(m=0;m<=n;++m){
                if(a[m]==t) { printf("There exit a number;");
                break;}
                else printf("There exit a  no number;");
        }

        } break ;
        case 4:{
        if(n==0) printf("Datebase empty.");
        for(m=0;m<=n;++m) printf("%d",a[m]);
        } break ;
        default :printf("Enter a valid option number .");
    }
     printf("1.Insert\n2.Delete numbers in a range\n3.Search\n4.Display\n5.Exit\n");
     printf("Enter the option ");
    scanf("%d",&i);
     }
    return 0;
}
