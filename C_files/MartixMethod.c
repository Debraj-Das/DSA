#include <stdio.h>
#include <stdlib.h>

void exchance(int ** ,int ,int ,int );  // exchance row and colomn.
int subcodinard(int ** ,int ); // determind subcoordinate by recuirtion.

int gcd(int a,int b)  //determind of GCD.
{
    int tum ;
    if(a<0) a*=(-1);
    if(b<0) b*=(-1);
    if(a<b)
    {
        tum = a;
        a=b;
        b=tum;
    }
    if(b==0) return 1;
    while(b!=0)
    {
        tum=a%b;
        a=b;
        b=tum;
    }
    return a;
}

int main()
 {
    int order , **matrix ,i ,j ,**adjoint ,*vaule_martix ,sign ;
    while(1)  
    {
    printf("\nEnter the order of the Coefficient Matrix : ");   // In main n variable use as a order of matrix.
    scanf("%d",&order);

    // Allocated space for 2D array dynamically.                                            
    matrix=(int **)malloc(order*sizeof(int *));
    for(i=0;i< order;++i)
    {
        matrix[i] =(int *)malloc(order*sizeof(int ));
    }

    adjoint=(int **)malloc(order*sizeof(int *));
    for(i=0;i< order;++i)
    {
        adjoint[i] =(int *)malloc(order*sizeof(int ));
    }

     // Scanned the input by for loop.
    printf("\nEnter the element of Coefficient Matrix : \n");
    for(i=0;i< order;++i)
    { 
        printf("\t");
        for(j=0;j<order;++j)
        {
            scanf("%d",&matrix[i][j]);
        }
    }

    //determind the Adjoint of cofficient Matrix.
   for(i=0 ; i<order ;++i)
   {
           if(i%2!=0) sign=1;
            else sign=-1;
       for(j=0;j<order;++j)
       {
           exchance(matrix,j,i,order);
           sign*=(-1);
        if((((order-i)>2)&&((order-j)<=2))||(((order-i)<=2)&&((order-j)>2))) 
               {
                   adjoint[i][j]=(-1)*sign*subcodinard(matrix,order-1);
               }
        else 
              {   
                  adjoint[i][j]=subcodinard(matrix,order-1)*sign;
              }
        exchance(matrix,j,i,order);
       }
   }

    int det_coordinate=subcodinard(matrix,order);     // determinants of matrix.

    printf("Determined of the  Coefficient matrix is %d\n",det_coordinate);
    printf("\nprint the Adjoint Martrix \n\t");
    for(i=0;i<order;++i)
    {
        for(j=0;j<order;++j)
        {
            printf(" %d ",adjoint[i][j]);
        }
        printf("\n\t");
    }
    free(matrix);

    if(det_coordinate==0)
    {
    printf("\nDetermined of the  Coefficient matrix is %d.\n\t So Eqution are INCONSISTENT.\n",det_coordinate);
     return 1;
    }

    // Main output part.
    vaule_martix=(int *)malloc(order*sizeof(int ));
    printf("\nEnter the Constant respectively :\n\t");
    for(i=0;i<order;++i)
    {
        scanf("%d",&vaule_martix[i]);
    }
    printf("Value of Variable of Linear Equation \n");
    for(i=0 ;i<order;++i)   //sign variable used as a output of final variable.
    {
        sign=0;
      for(j=0;j<order;++j)
      {
        sign+=vaule_martix[j]*adjoint[i][j];
      }

       j =gcd(sign,det_coordinate);
       if(det_coordinate==j||det_coordinate==-j)
       {
           printf("\tValue of X%d is %d.\n",i+1,sign/j);
       }
       else 
       {
           if(det_coordinate<0) j*=(-1);
           printf("\tValue of X%d is %d/%d.\n",i+1,sign/j,det_coordinate/j);
       }
    }
    free(adjoint);
    free(vaule_martix);
    printf("\nComputed is finished.\n If you exit from this Computation Enter Zero(0).\n\tEnter input : ");
    scanf("%d",&sign);
    if(sign==0)  break;
    else printf("\nAgain the Computation of Linear simultaneous equations by matrix method start.\n");
    }
    printf("\nComputation is finished.\n");
    return 0;
 }
  
 void exchance(int **matrix, int row , int colomn ,int order )
 {
     int chance,i;
     // first exchance row
     for(i=0;i<order;++i)
     {
         chance=matrix[order-1][i];
         matrix[order-1][i]=matrix[row][i];
         matrix[row][i]=chance;
     }
    // Then exchance colomn.
    for(i=0;i<order;++i)
    {
        chance=matrix[i][order-1];
         matrix[i][order-1]=matrix[i][colomn];
         matrix[i][colomn]=chance;
    }
    return ;
 }

 int subcodinard(int **matrix,int order)
 {     
     int det=0;
     //Base condition.
     if(order==1) return matrix[0][0];
     // Recuition of the function.
     for(int i=0,sign=-1;i<order;++i)
    {
        exchance(matrix,0,i,order);
        sign*=(-1);
        if(((order-0)>2&&(order-i)<=2)||((order-0)<=2&&(order-i)>2)) 
        {
               det+=matrix[order-1][order-1]*subcodinard(matrix,order-1)*sign*(-1);
        }
        else 
        {
              det+=matrix[order-1][order-1]*subcodinard(matrix,order-1)*sign;
        }
        exchance(matrix,0,i,order);
    }
     return det ;
 }