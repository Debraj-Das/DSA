#include <bits/stdc++.h>
using namespace std;

template <class T = int>
class Number
{
private:
    T mod;

public:
    Number(T mod = 1e9 + 7) { this->mod = mod; }

    T gcd(T a, T b) { return __gcd(a, b); }
    T add(T a, T b) { return ((a + b) % mod + mod) % mod; }
    T sub(T a, T b) { return ((a - b) % mod + mod) % mod; }
    T mul(T a, T b) { return ((a % mod) * (b % mod)) % mod; }
    T pow(T, T);
    T inv(T a) { return pow(a, mod - 2); }
    T div(T a, T b) { return mul(a, inv(b)); }
    T lcm(T a, T b) { return (a * b) / gcd(a, b); }

    T fact(T);
    T ncr(T, T);
    T npr(T, T);
    T nhr(T, T);

   

    

};

template <class T>
    void extengcd(T, T, T []);

template <class T>
    T mminv(T, T);

template <class T>
    T mminvprime(T, T);

template <class T>
    bool diophantine(T, T, T, T []);

template <class T>
    bool isprime(T);

template <class T>
    vector<T> primeNumber(T, T);

template <class T>
    vector<T> factors(T);

template <class T>
    vector<T> primefactors(T);

template <class T>
    vector<T> divisors(T);

template <class T>
    T phi(T);

template <class T>
    T phi(T, T []);

template <class T>
    T catalan(T);

template <class T>
    T catalan(T, T []);

template <class T>
    T totient(T);

template <class T>
    T multiplicativeOrder(T, T);

template <class T>
    T chineseRemainder(vector<T>, vector<T>);

template <class T>
    T chineseRemainder(vector<T>, vector<T>, T);

template <class T>
    T squareRoot(T);

template <class T>
    T Legendre(T, T);

template <class T>
    bool isCarmichaelNumber(T n);

template <class T>
    bool isPerfectSquare(T n);