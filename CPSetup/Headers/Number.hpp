#ifndef NUMBER_H
#define NUMBER_H 

#include <bits/stdc++.h>
template <class T = int>
class Number
{
private:
    T mod;

public:
    Number(T mod = 1e9 + 7) { this->mod = mod; }

    //~ Modulo Operations : gcd, add(+), sub(-), mul(*), div(/), lcm , inv(1/), power(^)
    T gcd(T a, T b) { return std::__gcd(a, b); }
    T add(T a, T b) { return ((a + b) % mod + mod) % mod; }
    T sub(T a, T b) { return ((a - b) % mod + mod) % mod; }
    T mul(T a, T b) { return ((a % mod) * (b % mod)) % mod; }
    T power(T, T);
    T inv(T a) { return power(a, mod - 2); }
    T div(T a, T b) { return mul(a, inv(b)); }
    T lcm(T a, T b) { return (a * b) / gcd(a, b); }

    //~ Number Theory : fact(!), ncr, npr, nhr = ((n+r-1)Cr-1)
    T fact(T);
    T ncr(T, T);
    T npr(T, T);
    T nhr(T, T);

    // Extended Euclidean Algorithm
    // ax + by = gcd(a,b) and find the x and y interger values
    // size of arr must be 3 , arr[0] = gcd(a,b) , arr[1] = x , arr[2] = y
    void extengcd(T, T, T[]);


    // Modular Multiplicative Inverse
    // (a*b)%m = 1 , find b = a^-1
    T mminv(T, T);

    // Linear Diophantine Equation : ax + by = c
    // Returns true if solution exists, false otherwise
    // size of arr must be 3 , arr[0] = gcd(a,b) , arr[1] = x , arr[2] = y
    bool diophantine(T, T, T, T[]);

    // Check if a number is prime or not
    bool isprime(T);

    // Sieve of Eratosthenes for finding prime numbers in range [1,n]
    std::vector<T> primeNumber(T);

    // find the factors of a number
    std::vector<T> factors(T);

    // find the prime factors of a number. e.g 12 = 2 , 2 , 3
    std::vector<T> primefactors(T);

    // Euler Totient Function
    // phi(n) = count of numbers in [1,n] which are relatively prime to n
    T phi(T);

    // Catalan Number : C(n) = (2nCn)/(n+1)
    T catalan(T);

    // multiplicative order of a modulo m
    // smallest k such that a^k = 1 (mod m)
    T multiplicativeOrder(T, T);

    // Chinese Remainder Theorem
    // x = a1 (mod m1) , x = a2 (mod m2) , x = a3 (mod m3) etc
    // m1 , m2 , m3 must be pairwise co-prime
    // returns x
    T chineseRemainder(std::vector<T>, std::vector<T>);

    // square root of a number modulo m (if exists)
    // if not exists then returns -1
    T squareRoot(T);

    // Legendre Symbol
    // if a is quadratic residue modulo p then returns 1
    // if a is quadratic non-residue modulo p then returns -1
    T Legendre(T, T);

    // Carmichael Number : 
    // a composite number n which satisfies the modular arithmetic congruence relation 
    // b^(n-1) = 1 (mod n) for all integers b which are relatively prime to n
    bool isCarmichaelNumber(T);

    // Perfect Square :
    // if a number is perfect square then returns true
    bool isPerfectSquare(T);
};

template <class T>
T Number<T>::power(T a, T b)
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
    // Fermat Little Theorem
    if (r > n)
        return 0;
    if (r > n - r)
        r = n - r;
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
    // nhr(n, r) = ncr(n + r - 1, r)
    if (n == 0 && r == 0)
        return 1;
    return ncr(n + r - 1, r);
}

template <class T>
void Number<T>::extengcd(T a, T b, T res[])
{
    // ax + by = gcd(a, b)
    // res[0] = gcd(a, b) , res[1] = x , res[2] = y
    if (b == 0)
    {
        res[0] = a;
        res[1] = 1;
        res[2] = 0;
    }
    else
    {
        extengcd(b, a % b, res);
        T x = res[2];
        res[2] = res[1] - (a / b) * res[2];
        res[1] = x;
    }
    return;
}

template <class T>
T Number<T>::mminv(T a, T b)
{
    // if gcd(a, b) != 1 then return -1
    if (gcd(a, b) != 1)
        return -1;
    T res[3];
    extengcd(a, b, res);
    return res[1];
}

template <class T>
bool Number<T>::diophantine(T a, T b, T c, T res[])
{
    // ax + by = c
    // if c%gcd(a, b) != 0 then return false
    // res[0] = gcd(a, b) , res[1] = x , res[2] = y
    extengcd(a, b, res);
    if (c % res[0] != 0)
        return false;
    res[1] *= c / res[0];
    res[2] *= c / res[0];
    if (a < 0)
        res[1] *= -1;
    if (b < 0)
        res[2] *= -1;
    return true;
}

template <class T>
bool Number<T>::isprime(T n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    T i = 5;
    while (i * i <= n)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
        i += 6;
    }
    return true;
}

template <class T>
std::vector<T> Number<T>::primeNumber(T n)
{
    // Sieve of Eratosthenes and Segmented Sieve Algorithm
    // Returns all prime numbers less than or equal to n
    std::vector<T> res;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (T p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (T i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (T p = 2; p <= n; p++)
        if (prime[p])
            res.push_back(p);
    return res;
}

template <class T>
std::vector<T> Number<T>::factors(T n)
{
    std::vector<T> res;
    for (T i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (i != n / i)
                res.push_back(n / i);
        }
    }
    return res;
}

template <class T>
std::vector<T> Number<T>::primefactors(T n)
{
    std::vector<T> res;
    while (n % 2 == 0)
    {
        res.push_back(2);
        n = n / 2;
    }
    for (T i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            res.push_back(i);
            n = n / i;
        }
    }
    if (n > 2)
        res.push_back(n);
    return res;
}

template <class T>
T Number<T>::phi(T n)
{
    // Euler's Totient Function or Euler's Phi Function
    // no of numbers less than n and coprime to n
    T res = n;
    for (T i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n = n / i;
            res = res - (res / i);
        }
    }
    if (n > 1)
        res = res - (res / n);
    return res;
}

template <class T>
T Number<T>::catalan(T a)
{
    T res = 1;
    for (T i = 1; i <= a; i++)
    {
        res = mul(res, a + i);
        res = div(res, i);
    }
    return div(res, a + 1);
}

template <class T>
T Number<T>::multiplicativeOrder(T a, T b)
{
    T res = 1;
    while (power(a, res) % b != 1)
        res++;
    return res;
}

template <class T>
T Number<T>::chineseRemainder(std::vector<T> a, std::vector<T> b)
{
    T prod = 1;
    for (T i = 0; i < a.size(); i++)
        prod *= a[i];
    T res = 0;
    for (T i = 0; i < a.size(); i++)
    {
        T pp = prod / a[i];
        res += b[i] * mminv(pp, a[i]) * pp;
    }
    return res % prod;
}

template <class T>
T Number<T>::squareRoot(T a)
{
    T l = 1, r = a, res;
    while (l <= r)
    {
        T mid = (l + r) / 2;
        if (mid * mid == a)
            return mid;
        if (mid * mid < a)
        {
            l = mid + 1;
            res = mid;
        }
        else
            r = mid - 1;
    }
    return res;
}

template <class T>
T Number<T>::Legendre(T a, T b)
{
    if (gcd(a, b) > 1)
        return 0;
    if (power(a, (b - 1) / 2) % b == 1)
        return 1;
    return -1;
}

template <class T>
bool Number<T>::isCarmichaelNumber(T n)
{
    if (isprime(n))
        return false;
    for (T i = 2; i < n; i++)
        if (power(i, n - 1) % n != 1)
            return false;
    return true;
}

template <class T>
bool Number<T>::isPerfectSquare(T n)
{
    T x = squareRoot(n);
    return x * x == n;
}


#endif // NUMBER_H_INCLUDED