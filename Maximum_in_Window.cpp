/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define el '\n'
#define f(i,a,b) for(int i = a; i < b; i++)
#define fr(i,a,b) for(int i = a; i >= b; i--)
#define vi vector<int>
void solve() ;

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
#endif

    int t = 1;
	cin >> t;
    while (t--) solve();

    return 0;
}

void push(deque<int> &q , int a)
{
    while(!q.empty() and q.back() < a)
        q.pop_back();
    q.push_back(a);
    return ;
}

void solve()
{
    int n , k ; cin>>n>>k;
    int arr[n] ; f(i , 0 , n ) cin>>arr[i];
    deque<int> q ;
    f(i , 0 , k) push(q , arr[i]);
    cout<<q.front()<<' ';
    f(i , k , n) 
    {
        if(q.front() == arr[i-k]) q.pop_front();
        push(q , arr[i]);
        cout<<q.front()<<' ';
    }
    cout<<el;
    
    return ;
}