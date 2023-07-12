#include <bits/stdc++.h>

using namespace std;

int main()
{
    int *memory_leak = new int(5);
    cout << *memory_leak << endl;
    cout << "Check for memory leak" << endl;
    return 0;
}