//name-Debraj Das
//Roll no-21CH30010

#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>
#include<io.h>



int main()
{
    int i;
    for(i=0;i<5;++i){
    setmode(_fileno(stdout),_O_U16TEXT);
    wprintf(L" test \xfffc \n");
    }
    return 0;
}
