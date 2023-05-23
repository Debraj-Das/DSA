#include "./Number.h"

template <class T>
T Number<T>::pow(T a, T b)
{
    T res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b = b >> 1;
    }
    return res;
}

template <class T>
T Number<T>::fact(T n)
{
    T res = 1;
    for (T i = 2; i <= n; i++)
        res = mul(res, i);
    return res;
}

template <class T>
T Number<T>::ncr(T n, T r)
{
    if (r > n)
        return 0;
    T res = 1;
    for (T i = 1; i <= r; i++)
    {
        res = mul(res, n - i + 1);
        res = div(res, i);
    }
    return res;
}

template <class T>
T Number<T>::npr(T n, T r)
{
    if (r > n)
        return 0;
    T res = 1;
    for (T i = 1; i <= r; i++)
        res = mul(res, n - i + 1);
    return res;
}

template <class T>
T Number<T>::nhr(T n, T r)
{
    if (n == 0 && r == 0)
        return 1;
    return ncr(n + r - 1, r);
}
