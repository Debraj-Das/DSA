
#include <bits/stdc++.h>

#define max1(x, y) (x) > (y) ? (x) : (y)

#define sc(n) scanf(" %c", &n)
#define sl(n) scanf("%ld", &n)
#define sll(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define ss(n) scanf("%s", n)
#define INF (int)1e9
#define EPS 1e-9
#define bitcount __builtin_popcount
#define gcd __gcd
#define forall(i, a, b) for (int i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(a) ((int)(a.size()))
#define mp make_pair
#define checkbit(n, b) ((n >> b) & 1)
#define l long

using namespace std;

int all_nine(string str) // check if all digits are '9'
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '9')
            return 0;
    }
    return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    int t;
    cin >> t;

    while (t--)
    {
        cin >> str;
        int i, j, num;
        char ans[str.length() + 3];
        int n = str.length();

        if (all_nine(str))
        { // if all 9
            ans[0] = '1';
            for (i = 0; i < n; i++)
            {
                ans[i + 1] = '0';
            }
            ans[n] = '1';
            ans[n + 1] = '\0';
            cout << ans << endl;
        }

        else
        {
            i = n / 2;
            j = i;

            if (n % 2 == 0)
                i = i - 1;

            while (i >= 0 && str[i] == str[j])
            { // checking for equal from middle
              //  <---i    j--->
                i--;
                j++;
            }

            if (i < 0 || str[i] < str[j])
            { // not equal or string is palindroic(i<0)
                i = n / 2;
                j = i;
                if (n % 2 == 0)
                    i = i - 1;
                int carry = 1;
                while (i >= 0)
                {
                    num = ((str[i] - '0') + carry);
                    carry = num / 10;
                    str[i] = (num % 10) + '0';
                    str[j] = str[i];
                    i--;
                    j++;
                }
            }
            else
            {
                while (i >= 0) // making second half same.
                {
                    str[j] = str[i];
                    i--;
                    j++;
                }
            }
            cout << str << endl;
        }
    }
    return 0;
}