#include <stdio.h>
#include <stdlib.h>

int main()
 {
    printf("5/9 = %d and size for data storage is %d.\n",5/9,sizeof(5/9));
    printf("5.0/9 = %lf and size for data storage is %d\n",5.0/9,sizeof(5.0/9));  // float number storage internal in double type.
    return 0;
 }