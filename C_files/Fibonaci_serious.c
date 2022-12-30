#include <stdio.h>
#include <stdlib.h>

int main()
 {
    int *serious , order , find_point , advance_point , previous_point;
    do 
    {
        advance_point=0;
        printf("\nEnter the order of the Fibonaci serious : ");
        scanf("%d",&order);
        serious=(int *)malloc(order*sizeof(int ));
        printf("Enter the element of intial value of Fibonaci serious : \n");
        for(previous_point=0;previous_point<order;++previous_point)
        {
            scanf("%d",&serious[previous_point]);
            advance_point+=serious[previous_point];
        }
        printf("\nEnter the find last point of Serious : ");
        scanf("%d",&find_point);
        printf("\nElements of Fibonaci serious are ;\n\t");
        for(previous_point=0;previous_point<find_point;++previous_point)
        {
            if(previous_point==order) 
            {
                printf("%d ",advance_point);
                break;
            }
            printf("%d ",serious[previous_point]);
            if(previous_point%10==9) printf("\n\t");
        }
        for(int i=order,n=0;i<find_point-1;++i,++n)
        {
            n%=order;
            previous_point=advance_point;
            advance_point=2*advance_point-serious[n];
            serious[n]=previous_point;
            printf("%d ",advance_point);
            if(i%10==9) printf("\n\t");
        }
        free(serious);
        printf("\n\nIf you contineu your computation than enter any nonzero number or for exit enter Zero.\n");
        printf("For further computation enter input : ");
        scanf("%d",&previous_point);
    }
    while(previous_point);
    printf("\n Computation is finished.\n");
    return 0;
 }