#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int mod = 1e9 + 7;

int gcd(int a, int b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int expo(int a, int b, int m = mod)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}
void extendgcd(int a, int b, int *v) // pass an arry of size1 3
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    int x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
}

int mminv(int a, int b)
{
    int arr[3];
    extendgcd(a, b, arr);
    return arr[0];
} // for non prime b
int mminvprime(int a, int b) { return expo(a, b - 2, b); }

int combination(int n, int r, int m, int *fact, int *ifact)
{
    int val1 = fact[n];
    int val2 = ifact[n - r];
    int val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}

vector<int> sieve(int n)
{
    int *arr = new int[n + 1]();
    vector<int> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}

int mod_add(int a, int b, int m = mod)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
int mod_mul(int a, int b, int m = mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
int mod_sub(int a, int b, int m = mod)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
int mod_div(int a, int b, int m = mod) // only for prime m
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} 

int phin(int n)
{
    int number = n;
    if (n % 2 == 0)
    {
        number /= 2;
        while (n % 2 == 0)
            n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            number = (number / i * (i - 1));
        }
    }
    if (n > 1)
        number = (number / n * (n - 1));
    return number;
} // O(sqrt(N))

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRandomNumber(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    for (int i = 0; i < 50; ++i)
        cout << getRandomNumber(2, 45) << endl;
    return 0;
}