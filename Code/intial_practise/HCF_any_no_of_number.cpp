#include <iostream>

using namespace std;
int n;

bool check(int array[], int c)
{
    for (int i = 0; i < n; ++i)
    {
        if ((array[i] % c) != 0)
            return false;
    }
    return true;
}

void divided(int array[], int c)
{
    for (int i = 0; i < n; ++i)
    {
        array[i] /= c;
    }
    return;
}

inline void small(int array[])
{
    int *tem = array;
    for (int i = 0; i < n; ++i)
    {
        if (array[i] < *tem)
            tem = &array[i];
    }
    int t = array[0];
    array[0] = *tem;
    *tem = t;
    return;
}

int main()
{
    register int *array, hcf = 1, i;
    cout << "Enter the no of number :: ";
    cin >> n;
    array = new int[n];
    for (i = 0; i < n; ++i)
    {
        cout << (i + 1) << ") ";
        cin >> array[i];
    }
    small(array);

    while (check(array, 2))
    {
        hcf *= 2;
        divided(array, 2);
    }

    for (i = 3; i <= array[0]; i += 2)
    {
        while (check(array, i))
        {
            hcf *= i;
            divided(array, i);
        }
    }

    cout<<"\tHCF is : "<<hcf<<endl;

    return 0;
}

/*
#include <iostream>

using namespace std;
int main()
{
    int a,b;
    cout<<"enter two numbers : ";
    cin>>a>>b;

    while(a!=b)
    {
        if(a>b)
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
    }
    cout<<"HCF is : "<<a;

return 0;
}
*/