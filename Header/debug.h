#include<bits/stdc++.h>

#ifndef DEBUG_HPP
#define DEBUG_HPP

#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { std::cerr << name << " : " << arg1 << std::endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
 const char* comma = strchr (names + 1, ',');
 std::cerr.write (names, comma - names) << " : " << arg1 << '\n'; __f (comma + 1, args...);
}

#define darr(a,n)std::cerr<<#a<<" : [ ";for(int i=0;i<n;i++)std::cerr<<a[i]<<' ';std::cerr<<"]\n";
#define dmat(mat,row,col)std::cerr<<#mat<<" :\n";for(int i=0;i<row;i++){for(int j=0;j<col;j++)std::cerr<<mat[i][j]<<' ';std::cerr<<'\n';}

#define bstl(x) std::cerr << #x<<" : "; _p(x); std::cerr << endl;
void _p(auto t) {std::cerr << t;}
template <class T, class V> void _p(std::pair <T, V> p) {std::cerr << "{ "; _p(p.first); std::cerr << ", "; _p(p.second); std::cerr << " }";}
template <class T> void _p(std::vector <T> v) {std::cerr << "[ "; for (T i : v) {_p(i); std::cerr << " ";} std::cerr << "]";}
template <class T> void _p(std::set <T> v) {std::cerr << "[ "; for (T i : v) {_p(i); std::cerr << " ";} std::cerr << "]";}
template <class T> void _p(std::multiset <T> v) {std::cerr << "[ "; for (T i : v) {_p(i); std::cerr << " ";} std::cerr << "]";}
template <class T, class V> void _p(std::map <T, V> v) {std::cerr << "[ "; for (auto i : v) {_p(i); std::cerr << " ";} std::cerr << "]";}
template <class T, class V> void _p(std::unordered_map <T, V> v) {std::cerr << "[ "; for (auto i : v) {_p(i); std::cerr << " ";} std::cerr << "]";}

#endif 
