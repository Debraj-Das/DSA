/*
অভিজ্ঞতা একটি কঠিন শিক্ষক,
সে প্রথমে তোমার পরীক্ষা নেয় এবং
পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define sp ' '

#define f(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, a, b) for (int i = (a); i >= (b); i--)

#define max(a, b) ((a) > (b)) ? (a) : (b)
#define maxa(a, b) a += ((b)-a) * ((b) > a)

#define min(a, b) ((a) < (b)) ? (a) : (b)
#define mina(a, b) a -= (a - (b)) * ((b) < a)

#define eif(cds, a, b) (cds) ? (a) : (b)

#define vi vector<int>
#define pb push_back

#define pii pair<int, int>
#define ff first
#define ss second

#define all(a) a.begin(), a.end()

#define F(x, a) for (auto x : a)

template <typename T> using V = vector<T>;

inline int exp(int a, int b)
{
    int x;
    for (x = 1; b; a *= a, b >>= 1)
        x *= (b & 1) ? a : 1;
    return x;
}

void Pair();
void Vector();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // Pair();
    // Vector();

    cout << exp(11, 2) << el;

    return 0;
}

/*	Iterator brief discussion

in iterator there are four function ->
1. begin() -> first element of the container
2. end() -> after the last element of container
3. rbegin() -> last element of the container
4. rend() -> before the first element of the container

if you want to travel whole container then used the for each loop
*/

void Vector()
{
    // intialised the vector
    vi v; // intiallised the empty vector and you inialised by any other vector
    // push element in back of vector
    v.pb(10);
    v.pb(12);
    v.pb(5);
    v.pb(6);
    v.pb(23);

    sort(all(v));
    // for each loop
    F(i, v) cout << i << sp;
    cout << el;

    // pop of last element (pop the back element)
    // v.pop_back();
    // print the last element
    // cout << *(v.rbegin()) << el;
}

void Pair()
{
    // how to declear the pair of int and string
    pair<int, string> p;
    p = {2, "avec"};
    cout << p.first << sp << p.second << el;
    // you can create any type of variable pair like pair<set<int>,vector<int>> p ;
}


void complex()
{
	complex<double> c{23, 43};
    cout << c << el;
    c.imag(23);
    cout << c << el;
	
	return ;
}

/*
	
	

*/