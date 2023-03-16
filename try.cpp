/*
	অভিজ্ঞতা একটি কঠিন শিক্ষক,
	সে প্রথমে তোমার পরীক্ষা নেয় এবং
	পরে তার পাঠ দেয়।
*/

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

// void solve()
// {
//     int a;
//     cin >> a;
//     if (a != 1)
//     {
//         int b = sqrt(a);
//         if (a == (b * b))
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
//     }
//     else
//         cout << "NO" << endl;
//     return;
// }

// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     int t;
//     cin >> t;
//     queue<int> q;
//     vector<int> n;
//     for (int i = 0; i < t; i++)
//     {
//         int temp;
//         cin >> temp;
//         n.push_back(temp);
//         q.push(temp);
//     }
//     int t_temp = q.front();
//     int i_t = t;

//     int count = 0;
//     for (int i = 1; i <= t_temp; i++)
//     {

//         if (t_temp % i == 0)
//             ++count;

//         if ((count > 3) || ((count < 3) && (i == t_temp)))
//         {
//             cout << "NO" << endl;
//             q.pop();
//             t_temp = q.front();
//             i = 0;
//             count = 0;
//             continue;
//         }

//         if ((count == 3) && (i == t_temp))
//         {
//             cout << "YES" << endl;
//             q.pop();
//             t_temp = q.front();
//             i = 0;
//             count = 0;
//             continue;
//         }
//     }

//     return 0;
// }

/*
	অভিজ্ঞতা একটি কঠিন শিক্ষক,
	সে প্রথমে তোমার পরীক্ষা নেয় এবং
	পরে তার পাঠ দেয়।
*/

// #include <bits/stdc++.h>

// using namespace std;

// #define int            long long int
// #define F              first
// #define S              second
// #define pb             push_back
// #define si             set <int>
// #define vi             vector <int>
// #define pii            pair <int, int>
// #define vpi            vector <pii>
// #define vpp            vector <pair<int, pii>>
// #define mii            map <int, int>
// #define mpi            map <pii, int>
// #define spi            set <pii>
// #define endl           "\n"
// #define sz(x)          ((int) x.size())
// #define all(p)         p.begin(), p.end()
// #define double         long double
// #define que_max        priority_queue <int>
// #define que_min        priority_queue <int, vi, greater<int>>
// #define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
// #define print(a)       for(auto x : a) cout << x << " "; cout << endl
// #define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
// #define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

// inline int power(int a, int b)
// {
//  int x = 1;
//  while (b)
//  {
//      if (b & 1) x *= a;
//      a *= a;
//      b >>= 1;
//  }
//  return x;
// }

// template <typename Arg1>
// void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
// template <typename Arg1, typename... Args>
// void __f (const char* names, Arg1&& arg1, Args&&... args)
// {
//  const char* comma = strchr (names + 1, ',');
//  cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
// }

// const int N = 200005;

// void solve() ;

// int32_t main()
// {
//  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// #ifndef ONLINE_JUDGE
//  freopen("input.txt",  "r",  stdin);
//  freopen("output.txt", "w", stdout);
// #endif

//  clock_t z = clock();

//  int t = 1;
//  cin >> t;
//  while (t--) solve();  // solve the problem inside of drive function for test cases.

//  cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

//  return 0;
// }

// void solve()
// {
//     cout<< "meet all o" <<endl;

//     return ;
// }

/*
	অভিজ্ঞতা একটি কঠিন শিক্ষক,
	সে প্রথমে তোমার পরীক্ষা নেয় এবং
	পরে তার পাঠ দেয়।
*/

// #include <bits/stdc++.h>
// using namespace std ;
// void solve() ;

// int32_t main()
// {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt",  "r",  stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     clock_t z = clock();

//     int t = 1;
// //	cin >> t;
//     while (t--) solve();  // solve the problem inside of drive function for test cases.

//     cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

//     return 0;
// }

// void solve()
// {
//     int  n ;
//     while(true)
//     {
//         cin>>n;
//         if(n==42)
//         break;
//         else
//         cout<<n<<endl;
//     }

//     return ;
// }

/*
	অভিজ্ঞতা একটি কঠিন শিক্ষক,
	সে প্রথমে তোমার পরীক্ষা নেয় এবং
	পরে তার পাঠ দেয়।
*/

// #include <bits/stdc++.h>
// using namespace std ;
// void solve() ;

// int32_t main()
// {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt",  "r",  stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     clock_t z = clock();

//     int t = 1;
// //	cin >> t;
//     while (t--) solve();  // solve the problem inside of drive function for test cases.

//     cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

//     return 0;
// }

// void solve()
// {
//     vector<int> arr[5] ;
//     arr[2].push_back(2);
//     arr[2].push_back(3);
//     arr[2].push_back(43);
//     for(auto x:arr[2])
//     cout<<x<<endl;

//     return ;
// }

// C++ program to find if
// there is a zero sum subarray

// #include <bits/stdc++.h>
// using namespace std;

// bool subArrayExists(int arr[], int N)
// {
// 	unordered_set<int> sumSet;

// 	// Traverse through array
// 	// and store prefix sums
// 	int sum = 0;
// 	for (int i = 0; i < N; i++)
// 	{
// 		sum += arr[i];

// 		// If prefix sum is 0 or
// 		// it is already present
// 		if (sum == 0 || sumSet.find(sum) != sumSet.end())
// 			return true;

// 		sumSet.insert(sum);
// 	}
// 	return false;
// }

// // Driver's code
// int main()
// {
// 	int arr[] = {-3, 2, 3, 1, 6};
// 	int N = sizeof(arr) / sizeof(arr[0]);

// 	// Function call
// 	if (subArrayExists(arr, N))
// 		cout << "Found a subarray with 0 sum";
// 	else
// 		cout << "No Such Sub Array Exists!";
// 	return 0;
// }

/*
	অভিজ্ঞতা একটি কঠিন শিক্ষক,
	সে প্রথমে তোমার পরীক্ষা নেয় এবং
	পরে তার পাঠ দেয়।
*/

// #include <bits/stdc++.h>
// using namespace std;
// void solve();

// int32_t main()
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// 	clock_t z = clock();

// 	int t = 1;
// 	//	cin >> t;
// 	while (t--)
// 		solve(); // solve the problem inside of drive function for test cases.

// 	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

// 	return 0;
// }

// void solve()
// {
// 	int anw = 1;
// 	for (int i = 0; i < 23; i++)
// 	{
// 		cout << (i + 1) << ' ';
// 		anw = ((anw % 153) * 147) % 153;
// 	}
// 	cout << endl
// 		 << anw << endl;

// 	return;
// }

/*
	অভিজ্ঞতা একটি কঠিন শিক্ষক,
	সে প্রথমে তোমার পরীক্ষা নেয় এবং
	পরে তার পাঠ দেয়।
*/

// #include <bits/stdc++.h>
// using namespace std;

// #define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
// template <typename Arg1>
// void __f(const char *name, Arg1 &&arg1)
// {
// 	cout << name << " : " << arg1 << endl;
// }
// template <typename Arg1, typename... Args>
// void __f(const char *names, Arg1 &&arg1, Args &&...args)
// {
// 	const char *comma = strchr(names + 1, ',');
// 	cout.write(names, comma - names) << " : " << arg1 << " | ";
// 	__f(comma + 1, args...);
// }

// #define endl '\n'
// void solve();

// int32_t main()
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// 	clock_t z = clock();

// 	int t = 1;
// 		// cin >> t;
// 	while (t--)
// 		solve();

// 	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

// 	return 0;
// }

// void solve()
// {

// 	int number = 0b011; //binary form, This type of assignment called at declearted time called literals
// 	cout << number<<endl;
// 	number = 012;	// Octa number
// 	cout << number<<endl;
// 	number = 0x12 ;	// Hex decimal
// 	cout << number<<endl;


// 	return;
// }


/*
  ভাগ্য তাদেরই সাথ দেয় যারা
   কর্মে বিশ্বাস করে ভাগ্যে নয়।
*/
// #include <bits/stdc++.h>
// using namespace std;
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #define mod 1000000007
// #define pb emplace_back
// #define mp make_pair
// #define fi first
// #define sec second
// #define el '\n'
// typedef long long ll;
// typedef long double  ld;
// #define pii pair<ll,ll>
// #define vi vector< ll >
// #define vvi vector< vi >
// #define vpi vector< pii >
// #define vvpi vector< vpi >
// #define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// #define test(t) ll t;cin>>t;while(t--)
// #define mem(a,b) memset(a,b,sizeof(a))
// #define inn freopen("input.txt", "r", stdin)
// #define outt freopen("output.txt", "w", stdout)
// #define all(arr) arr.begin(),arr.end()
// #define fr(i,n) for(ll i=0;i<(n);++i)
// #define rep(i,a,b) for(ll i=a;i<=b;++i)
// #define per(i,a,b) for(ll i=a;i>=b;i--)
// #define remin(a,b) (a=min((a),(b)))
// #define remax(a,b) (a=max((a),(b)))
// #ifndef ONLINE_JUDGE
// #define debarr(a,n)cerr<<#a<<":";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl;
// #define debmat(mat,row,col)cerr<<#mat<<":\n";for(int i=0;i<row;i++){for(int j=0;j<col;j++)cerr<<mat[i][j]<<" ";cerr<<endl;}
// #define pr(...)dbs(#__VA_ARGS__,__VA_ARGS__)
// template<class S,class T>ostream &operator<<(ostream &os,const pair<S,T> &p){return os<<"("<<p.first<<","<<p.second<<")";}
// template<class T>ostream &operator<<(ostream &os,const vector<T> &p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
// template<class T>ostream &operator<<(ostream &os,const set<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
// template<class T>ostream &operator<<(ostream &os,const multiset<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
// template<class S,class T>ostream &operator<<(ostream &os,const map<S,T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
// template<class T>void dbs(string str,T t){cerr<<str<<":"<<t<<"\n";}
// template<class T,class...S>void dbs(string str,T t,S... s){int idx=str.find(',');cerr<<str.substr(0,idx)<<":"<<t<<",";dbs(str.substr(idx+1),s...);}
// #else
// #define pr(...){}
// #define debarr(a,n){}
// #define debmat(mat,row,col){}
// #endif
// ll power(ll x,ll y){ll res = 1;while(y){if(y&1) res = (res*x)%mod;y=y/2,x=(x*x)%mod;}return res%mod;}
// void solve();
// signed main()
// {
//    fast; inn ; outt ;
//    clock_t z = clock();
//    test(t)  solve();
//    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
//    return 0 ;
// }

// void solve()
// {
// 	cout<< "hello world"<<el ; 

//   return ;
// }

/*
	অভিজ্ঞতা একটি কঠিন শিক্ষক,
	সে প্রথমে তোমার পরীক্ষা নেয় এবং
	পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define el '\n'
#define f(a,b) for(int i = a; i < b; i++)
#define fr(a,b) for(int i = a; i >= b; i--)
#define vi vector<int>
void solve() ;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	clock_t z = clock();

	int t = 1;
//	cin >> t;
	while (t--) solve();

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;
}

void solve()
{
	string s ;
	s.push_back('a');
	s.push_back('b');
	cout<< s<<el ; 
	
	return ;
}

