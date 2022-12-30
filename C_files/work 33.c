/*My Calculator */

#include <stdio.h>

float arg();
float pow(float,float );
float exp(float );
float log(float );
float sin(float );
float asin(float );

int main()
{
    double x,y,a[100];
    int i,j,t=1;
    char c,M[100];
    printf("this calculator use special type of function expression:\n 1.power x^y = p x , y ,\n 2.Exponential e^x = e x, \n 3.Logarithmic log y base x = l y , x , log y = l y , 1 ,\n 4.Trigonometry sin x = t 1 x ,\n");
    printf("5.Anti trigonometry arc sin x = a 1 x,\n 6.Hyp Trigonometry sinh x = h 1 x ,\n 7.floor [x] = f x ,\n 8.ceiling (x) = c x ,\n 9.Fractional {x} = F x ,\n 10.Mod |x| = m x ,\n 11.Sign(x) = s x,\n ");
    while(t!=0)
    {
        for(i=0; M[i-1]!='='; ++i)
        {
            scanf("%c",&c);
            switch(c)
            {
            case 'p':
            {
                x = arg();
                y= arg();
                a[i]=exp(y*log(x));
            }
            break ;
            case 'e':
            {
                x = arg();
                a[i]=exp(x);
            }
            break ;
            case 'l':
            {
                y= arg();
                x = arg();
                if(x==1.00) a[i]=log(y);
                else a[i]=log(y)/log(x);
            }
            break ;
            case 't':
            {
                scanf("%d",&t);
                x =arg()/360;
                switch(t)
                {
                case 1 :
                    a[i]=sin(0.01745*x);
                    break ;
                case 2 :
                    a[i]=sin(1.571-0.01745*x);
                    break ;
                case 3 :
                    a[i]=sin(0.01745*x)/sin(1.571-0.01745*x);
                    break ;
                case 4 :
                    a[i]=1/sin(0.01745*x);
                    break ;
                case 5 :
                    a[i]=1/sin(1.571-0.01745*x);
                    break ;
                case 6 :
                    a[i]=sin(1.571-0.01745*x)/sin(0.01745*x);
                    break ;
                }
            }
            break ;
            case 'a':
            {
                scanf("%d",&t);
                x =arg();
                switch(t)
                {
                case 1 :
                    a[i]= 57.3*asin(x);
                    break ;
                case 2 :
                    a[i]=90- 57.3*asin(x);
                    break ;
                case 3 :
                    a[i]= 57.3*asin(x/pow(1-x*x,0.5));
                    break ;
                case 4 :
                    if(x!=0) a[i]= 57.3*asin(1/x);
                    break ;
                case 5 :
                    a[i]=90- 57.3*asin(1/x);
                    break ;
                case 6 :
                    a[i]= 57.3*asin(pow(1-x*x,0.5)/x);
                    break ;
                }
            }
            break ;
            case 'h'
            {
                scanf("%d",&t);
                x =arg();
                switch(t)
                {
                case 1 :
                    a[i]= (exp(x)-exp(-x))/2;
                    break ;
                case 2 :
                    a[i]= (exp(x)+exp(-x))/2;
                    break ;
                case 3 :
                    a[i]= (exp(x)-exp(-x))/(exp(x)+exp(-x));
                    break ;
                case 4 :
                    a[i]= 2/(exp(x)-exp(-x));
                    break ;
                case 5 :
                    a[i]= 2/(exp(x)+exp(-x));
                    break ;
                case 6 :
                    a[i]= (exp(x)+exp(-x))/(exp(x)-exp(-x));
                    break ;
                }
            }
            break ;
            case 'f':
            {
                x = arg();
                if(x>=0) a[i]=(int)x;
                else a[i]=(int)x+1;
            }
            break ;
            case 'c'
            {
                x = arg();
                if(x>=0) a[i]=(int)x+1;
                else a[i]=(int)x;
            }
            break ;
            case 'F':
            {
                x = arg();
                if(x>=0) a[i]=x-(int)x;
                else a[i]=x-(int)x-1;
            }
            break ;
            case 'm':
            {
                x = arg();
                if(x>=0) a[i]=x;
                else a[i]=-x;
            }
            break ;
            case 's':
            {
                x = arg();
                if(x>0) a[i]=1;
                else if(x<0) a[i]=-1;
                else a[i]=0;
            }
            break ;
            }
            scanf("%c",&M[i]) ;
        }
        for(j=0,t=0; j<i; ++j)
        {
            if(M[j]=='*') a[i-t++]=a[i]*a[i+1];
            if(M[j]=='/') a[i-t++]=a[i]/a[i+1];
        }
        for(j=0,t=0; j<i; ++j)
        {
            if(M[j]=='+') a[j-t++]=a[j]+a[j+1];
            if(M[j]=='-') a[j-t++]=a[j]-a[j+1];
        }
        printf("%5.3f\nif you want to exit the calculator type zero.If not type any any non zero. Enter number: ",a[0]);
        scanf("%d",&t);
    }
    return 0;
}





