#include <stdio.h>
#include <stdlib.h>
typedef struct address
{
    int p;
    char ch;
    double query;
} xyz;

int gobal_variable;

int main()
{
    auto int auto_variable;
    register int register_varible;
    static int static_varible;
    int *pointer;
    xyz variable;
    pointer = (int *)malloc(sizeof(int));
    printf("address of machine code %p.\n", main);
    printf("intial vaule of dynamic allocated variable = %d & address = %p\n", *pointer, pointer);
    printf("intial vaule of auto variable = %d & address = %p\n", auto_variable, &auto_variable);
    printf("intial value of static variable = %d & address = %p\n", static_varible, &static_varible);
    printf("intial vaule of gobal variable = %d & address = %p\n", gobal_variable, &gobal_variable);
    printf("intial vaule of register variable = %d.\n", register_varible);                 // register type varible have no address.
    printf("intial value of structure variable %d &address %p.\n", variable.p, &variable); // structure define as a auto type variable.
    {
        register int i = 0;
        auto_variable = 0;
    jump:
        printf("vaule of i is present & vaule of i = %d \n", i);
        ++auto_variable;
        ++i;
    }
    if (auto_variable < 5)
        goto jump;
    free(pointer);
    return 0;
}