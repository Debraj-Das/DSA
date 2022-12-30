/*Name-Debraj Das
Roll no-21CH30010
 */
#include <stdio.h>

void selet(int x,int w[]);{
switch(x) {
case -8 : w[7]=0;
break ;
case -7 : w[6]=0;
break ;
case -6 : w[5]=0;
break ;
case -5 : w[4]=0;
break ;
case -4 : w[3]=0;
break ;
case -3 : w[2]=0;
break ;
case -2 : w[1]=0;
break ;
case -1 : w[0]=0;
break ;
case 8 : w[7]=1;
break ;
case 7 : w[6]=1;
break ;
case 6 : w[5]=1;
break ;
case 5 : w[4]=1;
break ;
case 4 : w[3]=1;
break ;
case 3 : w[2]=1;
break ;
case 2 : w[1]=1;
break ;
case 1 : w[0]=1;
break ;
}
}

int main()
{
    int x,y,z,a[300],i,w[8];
    printf("1) Does the tour last for more than a week?\n2) Does the tour involve a lot of physical activities like hiking?\n");
    printf("3) Is the location of the tour a hill station?\n4) Is the cost per head more than 15000 INR?\n");
    printf("5) Are all the meals arranged by the tour manager?\n6) Are hotel rooms in the ground floor ensured for elderly people?\n");
    printf("7) Are the hotel rooms air-conditioned?\n8) Are wheelchairs arranged for physically challenged tourists?\n\n");
    printf("Enter number of groups: ");
    scanf("%d",&n);
    for(i=0;i<n;++i) {
        printf("Enter the three preferences of group ");
        scanf("%d %d %d",&x,&y,&z);
        a[3*i]=x;
        a[3*i+1]=y;
        a[3*i+2]=z;
        selet(x,w);
        selet(y,w);
        selet(z,w);
    }

    return 0;
}
