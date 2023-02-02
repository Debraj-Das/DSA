// /*
//     অভিজ্ঞতা একটি কঠিন শিক্ষক,
//     সে প্রথমে তোমার পরীক্ষা নেয় এবং
//     পরে তার পাঠ দেয়।
// */

// #include <bits/stdc++.h>
// using namespace std;
// void solve();

// int32_t main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     clock_t z = clock();

//     int t = 1;
//     cin >> t;
//     while (t--)
//         solve(); // solve the problem inside of drive function for test cases.

//     cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

//     return 0;
// }

// bool sortrev(const pair<int, int> &a, const pair<int, int> &b)
// {
//     return (a.first > b.first);
// }

// void incinerate(vector<pair<int, int>> &monster, int n, int k)
// {
//     int min_val, end = n, i;
//     sort(monster.begin(), monster.end(), sortrev);
//     while ((monster[0].first > 0) && (k > 0))
//     {
//         min_val = monster[0].second;
//         for (i = 0; i < end; ++i)
//         {
//             if (monster[i].first <= k)
//             {
//                 monster[i].first -= k;
//                 break;
//             }
//             else
//             {
//                 monster[i].first -= k;
//                 if (min_val > monster[i].second)
//                     min_val = monster[i].second;
//             }
//         }
//         k -= min_val;
//         end = i;
//     }

//     if (monster[0].first > 0)
//         cout << "NO" << endl;
//     else
//         cout << "YES" << endl;
//     return;
// }

// void solve()
// {
//     int n, k;
//     cin >> n >> k;
//     vector<pair<int, int>> monster(n);
//     for (int i = 0; i < n; ++i)
//         cin >> monster[i].first;
//     for (int i = 0; i < n; ++i)
//         cin >> monster[i].second;

//     incinerate(monster, n, k);
//     return;
// }


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define el '\n'
#define yes cout<<"YES"<<el
#define no cout<<"NO"<<el
#define f(i,a,b) for(ll i = a; i <= b; i++)
#define fr(i,a,b) for(ll i = a; i >= b; i--)
#define vi vector<int>
#define speed ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)(x).size())
#define test ll _x86_; cin>>_x86_; while(_x86_--)
 
void solve()
{
    int n, k, baseh{0}; cin>>n>>k;
    vector<pair<int,int>> m(n); vi h(n); 
 
    f(i,0,n-1) cin>>m[i].first;
    f(i,0,n-1) cin>>m[i].second;
 
    sort(all(m));
 
    f(i, 0, n-1) h[i] = m[i].first;
 
    fr(i, n-2, 0) m[i].second = min(m[i+1].second, m[i].second);
 
    while(k > 0)
    {
        int ded = upper_bound(all(h), k+baseh) - h.begin();
 
        if(ded == n) { yes; return; }
 
        baseh += k;
        k -= m[ded].second;
    }
    no;
}
 
int32_t main()
{
    speed;     
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    test 
    solve();
    
    return 0 ;
}
