#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");
    // wchar_t str[] = { 2309 , 2310 , 2311 , 2312 , 2313 , 2314 , 2315 };
    // wprintf(L"%ls\r\n",str);
    wchar_t str;
    wscanf(L"%lc",&str);
    for (int i = 0; i < 52; ++i)
    {
        wprintf(L"%lc  ", (str + i));
    }   

    return 0;
}