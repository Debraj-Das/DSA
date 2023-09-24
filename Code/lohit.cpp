#include <bits/stdc++.h>

using namespace std;

int prime[100100];

const int m = 100100;

void sieve()

{

    int i, p;

    for (p = 2; p * p < m; p++)

    {

        if (prime[p] == 0)

        {

            for (i = p; i < m; i += p)

            {

                prime[i] = p;
            }
        }
    }
}

signed main()

{

    int t, n, i;

    memset(prime, 0, m);

    sieve();

    cin >> t;

    while (t--)

    {

        cin >> n;

        unordered_map<int, vector<int>> mp;

        for (i = 2; i <= n; i++)

        {

            mp[prime[i]].push_back(i);
        }

        cout << "1 ";

        for (auto j : mp)

        {

            for (auto k : j.second)

            {

                cout << k << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}