// clang-format off
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
inline int rdi(int l = 0, int r = 1e9){ return std::uniform_int_distribution<int>(l, r)(rng); }
// clang-format on

inline double rdd(int l = 0 , int r = 1000)
{
	double ans = rdi(1000 , 1000*r);
	return ans /1000 ;
}

// shuffle(v.begin(), v.end(), rng);  // shuffle syntex

const string a =  "abcdefghijklmnopqrstuvwxyz";
const string A =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string num = "0123456789";
const string spec = "!@#$%^&*";

inline char rdc()
{
	const string source = a ;
	const int n = source.size() - 1;

	return source[rdi(0,n)];
}

inline string rds(const int len)
{
	const string source = a + A + num + spec;
	const int n = source.size() - 1 ;
   string st;
   st.reserve(len);
	
   for (int i = 0; i < len; ++i)
      st += alphanum[rdi(0, n)];
   return st;
}

vector<int> rdv(int n)
{
   std::vector<int> v(n);
   for (int i = 0; i < n; i++)
      v[i] = rdi();
   return v;
}

// Random array
void rda(int arr[], int n)
{
   for (int i = 0; i < n; i++)
      arr[i] = rdi();
   return;
}

void distinctElements()
{
   int n = rdi(2, 20);
   cout << n << el;

   set<int> used;
   for (int i = 0, x; i < n; i++)
   {
      do
      {
         x = rdi(1, 10);
      } while (used.count(x));

      cout << x << sp;
      used.insert(x);
   }
   cout << el;

   return;
}

void tree()
{
   int n = rdi(2, 20);
   cout << n << el;

   vector<pair<int, int>> edges;
   for (int i = 2; i <= n; ++i)
   {
      edges.emplace_back(rdi(1, i - 1), i);
   }

   // rename the vertice
   vector<int> perm(n + 1);
   for (int i = 1; i <= n; ++i)
   {
      perm[i] = i;
   }
   random_shuffle(perm.begin() + 1, perm.end());

   // random order of edges
   random_shuffle(edges.begin(), edges.end());

   for (pair<int, int> &e : edges)
   {
      if (rdi() % 2)
      {
         // random order of two vertices
         swap(e.first, e.second);
      }

      cout << e.first << sp << e.second << el;
   }
}
