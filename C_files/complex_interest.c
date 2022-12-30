#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double getdouble(char *string)
{ 
    double ret ;
    printf("%s",string);
    scanf("%lf",&ret);
    return ret ;
}

int main()
 {
    double intial_money , interest , no_year ;
    intial_money = getdouble("Enter the intial vaule of money : ");
    interest = getdouble("Enter the inerest(in percentage) : ");
    no_year = getdouble("Enter the no of year : ");
    interest = pow((1+interest/100),no_year);
    printf("\n Final money after %lf year is %lf\n",no_year,(intial_money*interest));
    return 0;
 }