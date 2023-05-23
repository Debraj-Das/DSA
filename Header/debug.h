








#include<bits/stdc++.h>
using namespace std;

#ifndef DEBUG_HPP
#define DEBUG_HPP

#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
 const char* comma = strchr (names + 1, ',');
 cerr.write (names, comma - names) << " : " << arg1 << '\n'; __f (comma + 1, args...);
}

#define darr(a,n)cerr<<#a<<" : [ ";for(int i=0;i<n;i++)cerr<<a[i]<<' ';cerr<<"]\n";
#define dmat(mat,row,col)cerr<<#mat<<" :\n";for(int i=0;i<row;i++){for(int j=0;j<col;j++)cerr<<mat[i][j]<<' ';cerr<<'\n';}

#define bstl(x) cerr << #x<<" : "; _p(x); cerr << endl;
void _p(auto t) {cerr << t;}
template <class T, class V> void _p(pair <T, V> p) {cerr << "{ "; _p(p.first); cerr << ", "; _p(p.second); cerr << " }";}
template <class T> void _p(vector <T> v) {cerr << "[ "; for (T i : v) {_p(i); cerr << " ";} cerr << "]";}
template <class T> void _p(set <T> v) {cerr << "[ "; for (T i : v) {_p(i); cerr << " ";} cerr << "]";}
template <class T> void _p(multiset <T> v) {cerr << "[ "; for (T i : v) {_p(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _p(map <T, V> v) {cerr << "[ "; for (auto i : v) {_p(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _p(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_p(i); cerr << " ";} cerr << "]";}

#endif 
