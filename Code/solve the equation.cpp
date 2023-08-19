#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

inline void add(int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}

inline void sub(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += mod;
}

inline int mul(int a, int b)
{
    return (int)((long long)a * b % mod);
}

inline int power(int a, long long b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

inline int inv(int a)
{
    a %= mod;
    if (a < 0)
        a += mod;
    int b = mod, u = 0, v = 1;
    while (a)
    {
        int t = b / a;
        b -= t * a;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    assert(b == 1);
    if (u < 0)
        u += mod;
    return u;
}

signed main()
{
    // freopen("IN", "r", stdin);
    // freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    string s;
    getline(cin, s);
    while (T--)
    {
        getline(cin, s);
        vector<int> val;
        vector<char> op;
        int cur = 0;
        for (int i = 0; i < (int)s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                int x = s[i] - '0';
                cur *= 10;
                cur += x;
            }
            if (s[i] == ' ')
            {
                if (cur)
                {
                    val.push_back(cur);
                }
                cur = 0;
            }
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
                op.push_back(s[i]);
        }
        val.push_back(cur);

        assert((int)val.size() == 4);
        assert((int)op.size() == 2);
        int a = val[0], b = val[1], c = val[2], p = val[3];
        char op1 = op[0], op2 = op[1];

        assert(__gcd(a, p) == 1);
        assert(__gcd(b, p) == 1);
        assert(__gcd(c, p) == 1);

        a %= p;
        b %= p;
        c %= p;

        mod = p;

        if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/'))
        {
            int ans = 0;
            if (op2 == '*')
                ans = mul(b, c);
            else if (op2 == '/')
                ans = mul(b, inv(c));
            if (op1 == '+')
                add(ans, a);
            else if (op1 == '-')
            {
                sub(a, ans);
                ans = a;
            }
            assert(ans >= 0 && ans < p);
            cout << ans << "\n";
        }
        else if ((op2 == '+' || op2 == '-') && (op1 == '*' || op1 == '/'))
        {
            int ans = 0;
            if (op1 == '*')
                ans = mul(a, b);
            else if (op1 == '/')
                ans = mul(a, inv(b));
            if (op2 == '+')
                add(ans, c);
            else if (op2 == '-')
                sub(ans, c);
            assert(ans >= 0 && ans < p);
            cout << ans << "\n";
        }
        else if ((op2 == '+' || op2 == '-') && (op1 == '+' || op1 == '-'))
        {
            int ans = a;
            if (op1 == '+')
                add(ans, b);
            else if (op1 == '-')
                sub(ans, b);
            if (op2 == '+')
                add(ans, c);
            else if (op2 == '-')
                sub(ans, c);
            assert(ans >= 0 && ans < p);
            cout << ans << "\n";
        }
        else if ((op1 == '*') && (op2 == '/'))
        {
            int ans = 0;
            ans = mul(b, inv(c));
            ans = mul(a, ans);
            assert(ans >= 0 && ans < p);
            cout << ans << "\n";
        }
        else if ((op1 == '/') && (op2 == '*'))
        {
            int ans = 0;
            ans = mul(a, inv(b));
            ans = mul(ans, c);
            assert(ans >= 0 && ans < p);
            cout << ans << "\n";
        }
        else if ((op1 == op2))
        {
            assert((op1 == '*') || (op1 == '/'));
            int ans = 0;
            if (op1 == '*')
            {
                ans = mul(a, mul(b, c));
            }
            else
            {
                ans = mul(a, mul(inv(b), inv(c)));
            }
            assert(ans >= 0 && ans < p);
            cout << ans << "\n";
        }
    }
    return 0;
}
