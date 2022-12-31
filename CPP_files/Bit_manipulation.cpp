#include <bits/stdc++.h>
using namespace std;

void clear_ith_posstion(int &n, int i)
{
    int mask = ~(1 << i);
    n = (n & mask);
    return;
}

void update_ith_position(int &n,int i , int val)
{
    clear_ith_posstion(n,i);
    int mask = (val<<i);
    n = (n|mask);
    return ;
}

void set_ith_position(int &n, int i)
{
    int mask = (1 << i);
    n = (n | mask);
    return;
}

int get_ith_posstion(int n, int i)
{
    int mask = (1 << i);
    return (mask & n) ? 1 : 0;
}

void clear_last_i_bits(int &n , int i)
{
    int mask = (-1<<i);
    n = n&mask ;
    return ;
}

void clear_bits_in_range(int &n , int i , int j)
{
    int a = (-1)<<(j+1);
    int b = (1<<i)-1;
    int mask = (a|b);
    n = n&mask;
    return ;
}

void solve()
{
    int n, i;
    cin >> n >> i;
    cout << get_ith_posstion(n, i) << endl;
    clear_ith_posstion(n, i);
    cout << n << endl;
    set_ith_position(n, i);
    cout << n << endl;
    update_ith_position(n,i,0);
    cout<<n<<endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    cin >> t;
    while (t--)
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
