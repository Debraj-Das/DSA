# I use some of common Macro, which list in below

- max value of given data type
```cpp
template<class T>
constexpr T maxl = numeric_limits<T>:: max();
```

for using it, `const auto mx = maxl<int64_t>;`

- min value of given data type
```cpp
template<class T>
constexpr T minl = numeric_limits<T>::min();
```

for using it `const auto mx = minl<int64_t>`

- common value type constant expression
```cpp
constexpr long long mod = 1e9+7;
constexpr long long inf = mod*mod;
const long double ep = 1e-9;
const long double pi = acos(-1.0);
```

- For printing precision
```cpp
#define setpr(x) cout<<setprecision(x)<<fixed
```

- Some typedef with template for Data type
```cpp
template <class T> 
using pq = priority_queue<T>;

template <class T> 
using pqg = priority_queue<T, vector<T>, greater<T>>;
```

