/* All the snippts of C++ for competitive programming

***** supporting template
main_Snippt - main function
Random_Snippt - random input Generator 
builtin_Snippt - builtin function in c++
iset_Snippt - index set , index map 

****** Algorithm
exp_Snippt - exponention
two_pointer_Snippt - two pointer
inversion_Snippt - modified the merge algorithm
binary_Snippt - binary search function 

****** Date struture
DSU_Snippt - Disjoint set union structure
Trie_Snippts - Tries Date structure template
segmentTree_Snippt - Segment tree 
lazySegmentTree_Snippt - lazy segment tree

****** Math
sieve_Snippt - sieve function
nCr_Snippt - nCr function
Modulus_Snippts - modulus add , sub, mul , invM , expM
coprime_Snippt - no of Coprime in [1,n] range
Divisor_Snippt - prime Divisor , all prime divisor

****** Graph 
dfs_Snippt - DFS of non weight undirection graph
01dfs_Snippt - 0-1 DFS 1 & 0 weight undirected graph
dijstra_Snippt - dijstra algorithm function
floyd_Snippt - floyd warshell algorithm



 */

// lazySegmentTree_Snippt -----------------------------------------------------

// LST -> Lazy Segment Tree
template <class T, class V> class LST
{
  private:
    struct Node;

    Node *nodes;
    int N;

    void buildTree(T arr[], int stIndex, int lo, int hi)
    {
        if (lo == hi)
        {
            nodes[stIndex].assignLeaf(arr[lo]);
            return;
        }

        int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
        buildTree(arr, left, lo, mid);
        buildTree(arr, right, mid + 1, hi);
        nodes[stIndex].merge(nodes[left], nodes[right]);
    }

    Node getValue(int stIndex, int left, int right, int lo, int hi)
    {
        push(stIndex, left, right);

        if (left == lo && right == hi)
            return nodes[stIndex];

        int mid = (left + right) / 2;
        if (lo > mid)
            return getValue(2 * stIndex + 1, mid + 1, right, lo, hi);
        if (hi <= mid)
            return getValue(2 * stIndex, left, mid, lo, hi);

        Node leftResult = getValue(2 * stIndex, left, mid, lo, mid);
        Node rightResult = getValue(2 * stIndex + 1, mid + 1, right, mid + 1, hi);
        Node result;
        result.merge(leftResult, rightResult);
        return result;
    }

    int getSegmentTreeSize(int N)
    {
        int size = 1;
        for (; size < N; size <<= 1)
            ;
        return size << 1;
    }

    void update(int stIndex, int left, int right, int lo, int hi, T value)
    {
        push(stIndex, left, right);

        if (left == lo && right == hi)
        {
            nodes[stIndex].assignLazy(value);
            push(stIndex, left, right);
            return;
        }

        int mid = (left + right) / 2;
        if (lo > mid)
            update(2 * stIndex + 1, mid + 1, right, lo, hi, value);
        else if (hi <= mid)
            update(2 * stIndex, left, mid, lo, hi, value);
        else
        {
            update(2 * stIndex, left, mid, lo, mid, value);
            update(2 * stIndex + 1, mid + 1, right, mid + 1, hi, value);
        }

        nodes[stIndex].merge(nodes[left], nodes[right]);
    }

    void push(int stIndex, int left, int right)
    {
        if (nodes[stIndex].is_lazy() == false)
            return;

        T a = nodes[stIndex].lazyAssign();

        if (left != right)
        {
            nodes[2 * stIndex].assignLazy(a);
            nodes[2 * stIndex + 1].assignLazy(a);
        }
    }

  public:
    LST(T arr[], int N)
    {
        this->N = N;
        nodes = new Node[getSegmentTreeSize(N)];
        buildTree(arr, 1, 0, N - 1);
    }

    LST(vector<T> vrr)
    {
        const int N = vrr.size();
        int arr[N];
        for (int i = 0; i < N; i++)
            arr[i] = vrr[i];

        this->N = N;
        nodes = new Node[getSegmentTreeSize(N)];
        buildTree(arr, 1, 0, N - 1);
    }

    ~LST()
    {
        delete[] nodes;
    }

    V getValue(int lo, int hi)
    {
        Node result = getValue(1, 0, N - 1, lo, hi);
        return result.getValue();
    }

    void update(int lo, int hi, T value)
    {
        update(1, 0, N - 1, lo, hi, value);
    }
};

/*
**  Some Importance Ideas of Lazy Segment Trees -->
1.   T -> type of input array elements
2.   V -> type of required aggregate statistic or data type of Node vaule

** 	Definite the Lazy Segment Tree Node -->
1.   assignLeaf function -> Update the value of node
2.   merge function -> Combined the nodes
3.   getValue function -> return the value of the node
4. 	 assignLazy function -> assign the node to lazy value
5.   is_lazy function -> it return function has lazy assign or not
6.   lazyAssign function -> it assign lazy value to node values

**  Functions of Lazy Segment Tree -->
1.   Constructor(ar , n) -> Build the segment Tree -> arguments : array , size of array
     Constructor(vect) -> Build the segment Tree -> arguments : vector
2.   getVaule(lo , hi) -> return value Queries -> argument : range of zero based indexing
3.   update(lo , hi , value) -> update the range-> argument : low  , high , update vaule

**  Some example of Sum Query ->
		
		int n = 9 ;
        int arr[n] = {2, 1, 3, 5, 4, 11, 23, 6, 2};

   		LST<int, int> sg(arr, n);

    	cout << sg.getValue(1, 3) << el; // Zero based index
    	sg.update(2, 6, 2);
    	
    	cout << sg.getValue(1, 3) << el;
    	cout << sg.getValue(5, 7) << el;

*/

template <class T, class V> struct LST<T, V>::Node
{
    V value;
    T lazy;
    size_t sz;
    bool isLazy;

    Node()
    {
        lazy = 0;
        isLazy = false;
    }

    void assignLeaf(T a)
    {
        // assign the node Depends of Node Storage
        value = a;
        sz = 1;
        return;
    }

    void merge(Node a, Node b)
    {
        // Update according to Questions Depends of Node Storage
        value = a.value + b.value;
        sz = a.sz + b.sz;
        return;
    }

    V getValue()
    {
        // Return the value of the node Depends of Node Storage
        return value;
    }

    void assignLazy(T a)
    {
        // assign the node to lazy value
        lazy = a;
        isLazy = true;
    }

    bool is_lazy()
    {
        // return this node has lazy assign or not
        return isLazy;
    }

    T lazyAssign()
    {
        // convert lazy value to node value
        value = lazy * sz;
        isLazy = false;

        return lazy;
    }
};

// segmentTree_Snippt ----------------------------------------------------------

template <class T, class V> class SegmentTree
{
  private:
    struct SegmentTreeNode;

    SegmentTreeNode *nodes;
    int N;

    void buildTree(T arr[], int stIndex, int lo, int hi)
    {
        if (lo == hi)
        {
            nodes[stIndex].assignLeaf(arr[lo]);
            return;
        }

        int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
        buildTree(arr, left, lo, mid);
        buildTree(arr, right, mid + 1, hi);
        nodes[stIndex].merge(nodes[left], nodes[right]);
    }

    SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi)
    {
        if (left == lo && right == hi)
            return nodes[stIndex];

        int mid = (left + right) / 2;
        if (lo > mid)
            return getValue(2 * stIndex + 1, mid + 1, right, lo, hi);
        if (hi <= mid)
            return getValue(2 * stIndex, left, mid, lo, hi);

        SegmentTreeNode leftResult = getValue(2 * stIndex, left, mid, lo, mid);
        SegmentTreeNode rightResult = getValue(2 * stIndex + 1, mid + 1, right, mid + 1, hi);
        SegmentTreeNode result;
        result.merge(leftResult, rightResult);
        return result;
    }

    int getSegmentTreeSize(int N)
    {
        int size = 1;
        for (; size < N; size <<= 1)
            ;
        return size << 1;
    }

    void update(int stIndex, int lo, int hi, int index, T value)
    {
        if (lo == hi)
        {
            nodes[stIndex].assignLeaf(value);
            return;
        }

        int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
        if (index <= mid)
            update(left, lo, mid, index, value);
        else
            update(right, mid + 1, hi, index, value);

        nodes[stIndex].merge(nodes[left], nodes[right]);
    }

  public:
    SegmentTree(T arr[], int N)
    {
        this->N = N;
        nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
        buildTree(arr, 1, 0, N - 1);
    }
    
    SegmentTree(vector<T> vrr)
    {
        const int N = vrr.size();
        int arr[N];
        for (int i = 0; i < N; i++)
            arr[i] = vrr[i];

        this->N = N;
        nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
        buildTree(arr, 1, 0, N - 1);
    }

    ~SegmentTree()
    {
        delete[] nodes;
    }

    V getValue(int lo, int hi)
    {
        SegmentTreeNode result = getValue(1, 0, N - 1, lo, hi);
        return result.getValue();
    }

    void update(int index, T value)
    {
        update(1, 0, N - 1, index, value);
    }
};

/*
**  Some Importance Ideas of Segment Trees -->
1.   T -> type of input array elements
2.   V -> type of required aggregate statistic or data type of Node vaule

** 	Definite the Segment Tree Node -->
1.   assignLeaf function -> Update the value of node
2.   merge function -> Combined the nodes
3.   getValue function -> return the value of the node 

**  Functions of Segment Tree -->
1.   Constructor(ar , n) -> Build the segment Tree -> arguments : array , size of array
	 Constructor(vect) -> Build the segment Tree -> arguments : vector
2.   getVaule(lo , hi) -> return value Queries -> argument : range of zero based indexing
3.   update(index , value) -> update the index-> argument : index , update vaule
    
**  Some example of Sum Query ->

	    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	    SegmentTree<int, int> tree(arr, 8);
	    cout << tree.getValue(0, 4) << '\n';
	    tree.update(4, 10);
	    cout << tree.getValue(2, 6) << '\n';
	    
*/

template <class T, class V> struct SegmentTree<T, V>::SegmentTreeNode
{
    V value;

    void assignLeaf(T a)
    {
    	// assign the node Depends of Node Storage
        value = a; 
        return;
    }
    
    void merge(SegmentTreeNode a, SegmentTreeNode b)
    {
    	// Update according to Questions Depends of Node Storage
        value = a.value + b.value; 
        return;
    }
    
    V getValue()
    {
    	// Return the value of the node Depends of Node Storage
        return value;
    }
};

// Trie_Snippts -----------------------------------------------------------------
struct node {
	node *nxt[26];
	bool is_end;
	node() {
		for (int i = 0; i < 26; i++) nxt[i] = NULL;
		is_end = false;
	}
};

node *root;

void insert_trie(string s) {
	node *cur = root;
	for (int i = 0; i < s.size(); i++) {
		int imap = s[i] - 'a';
		// new node
		if (cur->nxt[imap] == NULL) {
			cur->nxt[imap] = new node();
		}
		// goto that node
		cur = cur->nxt[imap];
	}
	// cur -> last node
	cur->is_end = true;
}

// O(|s|)
bool search_trie(string s) {
	node *cur = root;
	for (int i = 0; i < s.size(); i++) {
		int imap = s[i] - 'a';
		if (cur->nxt[imap] == NULL) return false;
		cur = cur->nxt[imap];
	}
	return cur->is_end;
}

/*
* How to use the trie data structure
int main()
{
	root = new node();

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		insert_trie(s);
	}

	if (search_trie("apaar")) {
		cout << "Found";
	}
	else {
		cout << "Not Found";
	}

	return 0;
}

*/

// main_Snippt ----------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);


   return 0;
}

// exp_Snippt -----------------------------------------------------------
inline long long exp(long long a, int b)
{
   long long x = 1;
   while (b)
   {
      if (b & 1)
         x *= a;
      a *= a;
      b >>= 1;
   }
   return x;
}

// two_pointer_Snippt -----------------------------------------------------------
int two_pointer(int ar[], int n, int sum) 
{
   // intial empty windows left and right side
   int l = 0, r = 0;
   // window value for empty windows depends
   int winVal = 0;
   // the answer for a empty window depends
   int ans = 0;

   while (l < n)
   {
      // moving right side to forward & Second condition depends
      while (r < n and (winVal + ar[r] <= sum))
      {
         // update the window value for include the element ar[r];
         winVal += ar[r];
         r++; // forward the right
      }

      // update the answer for this window. it depends
      ans = max(ans, (r - l));

      // moving left to one step forward
      if (r > l) // non empty window
      {
         // update window value for exclude the element ar[l];
         winVal -= ar[l];
         l++; // forward the left
      }
      else // empty window
      {
         // moving forward completed empty window
         l++;
         r++;
      }
   }

   return ans;
}

// Random_Snippt -----------------------------------------------------------
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

// sieve_Snippt -----------------------------------------------------------
const int N = 1e6;
bool prime[N];

void sieve()
{
	for(int i = 2 ; i < N ; i++)
		prime[i] = true;
   
   prime[0] = false;
   prime[1] = false;
   
   for (int i = 2, j; i * i < N; i++)
   {
      if (prime[i] == false)
         continue;
      for (j = i * i; j < N; j += i)
         prime[j] = false;
   }

   return;
}

// segmenttree_snippt -----------------------------------------------------------
template <class t, class v> class segmenttree
{
  private:
    struct segmenttreenode;

    segmenttreenode *nodes;
    int n;

    void buildtree(t arr[], int stindex, int lo, int hi)
    {
        if (lo == hi)
        {
            nodes[stindex].assignleaf(arr[lo]);
            return;
        }

        int left = 2 * stindex, right = left + 1, mid = (lo + hi) / 2;
        buildtree(arr, left, lo, mid);
        buildtree(arr, right, mid + 1, hi);
        nodes[stindex].merge(nodes[left], nodes[right]);
    }

    segmenttreenode getvalue(int stindex, int left, int right, int lo, int hi)
    {
        if (left == lo && right == hi)
            return nodes[stindex];

        int mid = (left + right) / 2;
        if (lo > mid)
            return getvalue(2 * stindex + 1, mid + 1, right, lo, hi);
        if (hi <= mid)
            return getvalue(2 * stindex, left, mid, lo, hi);

        segmenttreenode leftresult = getvalue(2 * stindex, left, mid, lo, mid);
        segmenttreenode rightresult = getvalue(2 * stindex + 1, mid + 1, right, mid + 1, hi);
        segmenttreenode result;
        result.merge(leftresult, rightresult);
        return result;
    }

    int getsegmenttreesize(int n)
    {
        int size = 1;
        for (; size < n; size <<= 1)
            ;
        return size << 1;
    }

    void update(int stindex, int lo, int hi, int index, t value)
    {
        if (lo == hi)
        {
            nodes[stindex].assignleaf(value);
            return;
        }

        int left = 2 * stindex, right = left + 1, mid = (lo + hi) / 2;
        if (index <= mid)
            update(left, lo, mid, index, value);
        else
            update(right, mid + 1, hi, index, value);

        nodes[stindex].merge(nodes[left], nodes[right]);
    }

  public:
    segmenttree(t arr[], int n)
    {
        this->n = n;
        nodes = new segmenttreenode[getsegmenttreesize(n)];
        buildtree(arr, 1, 0, n - 1);
    }
    
    segmenttree(vector<t> vrr)
    {
        const int n = vrr.size();
        int arr[n];
        for (int i = 0; i < n; i++)
            arr[i] = vrr[i];

        this->n = n;
        nodes = new segmenttreenode[getsegmenttreesize(n)];
        buildtree(arr, 1, 0, n - 1);
    }

    ~segmenttree()
    {
        delete[] nodes;
    }

    v getvalue(int lo, int hi)
    {
        segmenttreenode result = getvalue(1, 0, n - 1, lo, hi);
        return result.getvalue();
    }

    void update(int index, t value)
    {
        update(1, 0, n - 1, index, value);
    }
};

/*
**  some importance ideas of segment trees -->
1.   t -> type of input array elements
2.   v -> type of required aggregate statistic or data type of node vaule

** 	definite the segment tree node -->
1.   assignleaf function -> update the value of node
2.   merge function -> combined the nodes
3.   getvalue function -> return the value of the node 

**  functions of segment tree -->
1.   constructor(ar , n) -> build the segment tree -> arguments : array , size of array
	 constructor(vect) -> build the segment tree -> arguments : vector
2.   getvaule(lo , hi) -> return value queries -> argument : range of zero based indexing
3.   update(index , value) -> update the index-> argument : index , update vaule
    
**  some example of sum query ->

	    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	    segmenttree<int, int> tree(arr, 8);
	    cout << tree.getvalue(0, 4) << '\n';
	    tree.update(4, 10);
	    cout << tree.getvalue(2, 6) << '\n';
	    
*/

template <class t, class v> struct segmenttree<t, v>::segmenttreenode
{
    v value;

    void assignleaf(t a)
    {
    	// assign the node Depends of Node Storage
        value = a; 
        return;
    }
    
    void merge(SegmentTreeNode a, SegmentTreeNode b)
    {
    	// Update according to Questions Depends of Node Storage
        value = a.value + b.value; 
        return;
    }
    
    V getValue()
    {
    	// Return the value of the node Depends of Node Storage
        return value;
    }
};

// nCr_Snippt -----------------------------------------------------------
const int N = 200000 + 5;
ll fact[N], invfact[N];

long long invM(ll a)
{
   int b = mod - 2;
   long long ans = 1;

   while (b)
   {
      if (b & 1)
         ans = (1ll * ans * a) % mod;
      a = (1ll * a * a) % mod;
      b >>= 1;
   }

   return ans;
}

void factorialcul()
{
   fact[0] = 1;
   for (int i = 1; i < N; i++)
   {
      fact[i] = ((fact[i - 1] % mod) * (i % mod)) % mod;
   }

   invfact[N - 1] = invM(fact[N - 1]);
   for (int i = N - 2; i >= 0; --i)
   {
      invfact[i] = ((invfact[i + 1] % mod) * (i + 1)) % mod;
   }

   return;
}

ll ncr(ll n, ll r)
{
   if (r > n)
      return 0ll;

   ll res = fact[n] % mod;
   res = (res * (invfact[n - r] % mod)) % mod;
   res = (res * (invfact[r] % mod)) % mod;

   return res;
}

// Modulus_Snippts -----------------------------------------------------------
long long add(long long a, long long b)
{
    long long ans = (a % mod + b % mod) % mod;
    return ans;
}

long long sub(long long a, long long b)
{
    long long ans = (a % mod - b % mod + mod) % mod;
    return ans;
}

long long mul(long long a, long long b)
{
    long long ans = ((a % mod) * (b % mod)) % mod;
    return ans;
}

long long inv(long long a)
{
   int b = mod - 2;
   long long ans = 1;

   while (b)
   {
      if (b & 1)
         ans = (1ll * ans * a) % mod;
      a = (1ll * a * a) % mod;
      b >>= 1;
   }

   return ans;
}

long long expM(long long a, int b)
{
   long long ans = 1;
   while (b)
   {
      if (b & 1)
         ans = (1ll * ans * a) % mod;
      a = (1ll * a * a) % mod;
      b >>= 1;
   }

   return ans;
}

// iset_Snippt -----------------------------------------------------------
#include <bits/extc++.h>
template <typename K, typename V, typename Comp = std::less<K>>
using imap = __gnu_pbds::tree<K, V, Comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <typename K, typename Comp = std::less<K>> using iset = imap<K, __gnu_pbds::null_type, Comp>;


/*
**	Same as Set with some Extra Feature (find_by_order , order_by_key)
     oset<int> s;
     s.insert(23);
     s.insert(34);
     s.insert(6);
    
**  returns an iterator to the element at a given position (0-based index)
     auto x = s.find_by_order(2);
     cout << *x << "\n"; -> 34

**  return the count the smaller element of that element
     s.order_of_key(34); -> return 2
     
** You can use all other set functions like ->
	s.erase(25);
*/

// inversion_Snippt -----------------------------------------------------------
long long inversion(int ar[], int l, int r)
{
   if (l >= r)
      return 0;

   const int mid = (r + l) / 2;

   long long ans = inversion(ar, l, mid);
   ans += inversion(ar, mid + 1, r);

   int i = l, j = mid + 1, k = 0, temp[r - l + 1];

   while (i <= mid and j <= r)
   {
      if (ar[i] <= ar[j])
      {
         temp[k++] = ar[i++];
         // inversion calculation between two array part
         ans += j - mid - 1;
      }
      else
      {
         temp[k++] = ar[j++];
      }
   }

   while (i <= mid)
   {
      temp[k++] = ar[i++];
      // inversion calculation for first part of array due ot second part of the array
      ans += (r - mid);
   }
   while (j <= r)
   {
      temp[k++] = ar[j++];
   }

   for (i = l, k = 0; i <= r; i++, k++)
      ar[i] = temp[k];

   return ans;
}

// floyd_Snippt -----------------------------------------------------------
int n, m;
   cin >> n >> m;

   int dist[n][n];
   for (int i = 0, j; i < n; i++)
   {
      for (j = 0; j < n; j++)
      {
         dist[i][j] = eif((i == j), 0, inf);
      }
   }

   for (int i = 0, u, v, w; i < m; i++)
   {
      cin >> u >> v >> w;
      u--, v--;
      dist[u][v] = w;
   }

   // floyd warshall algorithm
   for (int k = 0, i, j; k < n; k++)
      for (i = 0; i < n; i++)
         for (j = 0; j < n; j++)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
   
   // You got any pair of shortest path dist[i][j] == shortest path between i to j or j to i

// DSU_Snippt-----------------------------------------------------------
struct DSU
{
   int n, num_grp;
   int *par, *sz;

   DSU()
   {
      n = 0;
      num_grp = 0;
      par = NULL;
      sz = NULL;
   }

   DSU(int n)
   {
      this->n = n;
      num_grp = n;
      par = new int[n];
      sz = new int[n];
      for (int i = 0; i < n; i++)
      {
         par[i] = i;
         sz[i] = 1;
      }
   }

   void reset(int n = 0)
   {
      if (par)
         delete[] par;
      if (sz)
         delete[] sz;

      this->n = n;
      num_grp = n;

      if (n == 0)
      {
         par = NULL;
         sz = NULL;
         return;
      }

      par = new int[n];
      sz = new int[n];
      for (int i = 0; i < n; i++)
      {
         par[i] = i;
         sz[i] = 1;
      }
   }

   ~DSU()
   {
      if (par)
         delete[] par;
      if (sz)
         delete[] sz;
   }

   int find(int u)
   {
      return u == par[u] ? u : par[u] = find(par[u]);
   }

   void merge(int u, int v)
   {
      u = find(u), v = find(v);
      if (u == v)
         return;

      if (sz[u] > sz[v])
         swap(u, v);
      par[u] = v;
      sz[v] += sz[u];
      num_grp--;
   }

   int component()
   {
      return num_grp;
   }

   int sz_component(int u)
   {
      u = find(u);
      return sz[u];
   }
};


/*
// eg.   kruskal Algorithm(MST)
 
   int n, m;
   cin >> n >> m;

   array<int, 3> edgeList[m];
   for (int i = 0, u, v, w; i < m; i++)
   {
      cin >> u >> v >> w;
      edgeList[i][0] = w;
      edgeList[i][1] = u - 1;
      edgeList[i][2] = v - 1;
   }

   sort(edgeList, edgeList + m);

   int price = 0, edge = 0;
   DSU uf(n);
   F(&e, edgeList)
   {
      if (uf.find(e[1]) == uf.find(e[2]))
         continue;

      uf.merge(e[1], e[2]);
      price += e[0];
      edge++;
   }
   
   if(edge == (n-1))
   cout << price << el;
   else
   cout<<"NO Solution"<<el; // MST not possible

*/

// Divisor_Snippt -----------------------------------------------------------
const int N = 1e7 + 1;
int divisor[N] = {0};

void primeDivisor()
{
    divisor[1] = 1;
    for (int i = 2, j; i < N; i++)
        if (divisor[i] == 0)
        {
            for (j = i; j < N; j += i)
                if (divisor[j] == 0)
                    divisor[j] = i;
        }

    return;
}

// All the Prime Divisor of any interger(<= 1e7) (e.g, 45 = 3*3*5)
vector<int> APD(int a)
{
    vector<int> ans;
    while (a > 1)
    {
        ans.pb(divisor[a]);
        a /= divisor[a];
    }
    sort(ans.begin(), ans.end());

    return ans;
}

// dijstra_Snippt -----------------------------------------------------------
void dijstra(int sc)
{
    vis.assign(n, 0);
    dist.assign(n, inf);

    dist[sc] = 0;
    pqg<pii> p;
    p.push(mp(0, sc));

    pii fs;
    int neigh, wg;
    while (p.size())
    {
        fs = p.top();
        p.pop();

        if (vis[fs.ss])
            continue;
        vis[fs.ss] = 1;

        for (auto &v : gr[fs.ss])
        {
            neigh = v.ff;
            wg = v.ss;
            if (dist[neigh] > dist[fs.ss] + wg)
            {
                dist[neigh] = dist[fs.ss] + wg;
                p.push(mp(dist[neigh], neigh));
            }
        }
    }

    return;
}

/*
int n, m;
V<V<pii>> gr;
vi vis;
vi dist;

void solve()
{
    cin >> n >> m;
    gr.resize(n, V<pii>(0));
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        u--, v--;
        gr[u].pb({v, w});
        gr[v].pb({u, w});
    }

    int sc;
    cin >> sc;
    dijstra(sc - 1);

    f(i, 0, n) cout << dist[i] << sp;
    cout << el;

    return;
}

*/

// coprime_Snippt -----------------------------------------------------------
const int N = 1e6 + 1;
int phi[N];

void coprime()
{
    for (int i = 0; i < N; i++)
        phi[i] = i;

    for (int i = 2, j; i < N; i++)
        if (phi[i] == i)
            for (j = i; j < N; j += i)
                phi[j] -= (phi[j] / i);

    return;
}

// builtin_Snippt -----------------------------------------------------------
// builtin bit function for C++
__builtin_clz(4) // count the leading zero in a number Ans: 27
__builtin_clzll(4) // for long long Ans: 59
__builtin_ctz(16) // count the loading zero for a integer Ans: 4
__builtin_ctzll(1024) // for long long
__builtin_popcount(1203) // count the bit ones in any number Ans : 6
__builtin_popcountll(120341ll) // for long long
 
// binary_Snippt -----------------------------------------------------------
int binary(int lo, int hi, function<bool(int)> check)
{
    int ans = hi + 1, mid;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ans;
}
/* How to used the binary function in binary search operation
1. lower ranage = lo , higher range = hi ;
2. check function => which respect the solution space is NNNNNYYYYY(first no then yes)

auto check = [&](int mid) {
	// body of the check function
	// return true or false depend on mid ;
}

	int ar[n] ;
eg. int ans = binary(0, n - 1, [&](int i) { return ar[i] < ar[0]; });
*/

// dfs_Snippt -----------------------------------------------------------
void distance(int u)
{
    vis.assign(n, inf);
    vis[u] = 0;

    queue<int> q;
    q.push(u);
    while (q.size())
    {
        u = q.front();
        q.pop();

        for (auto &v : gr[u])
        {
            if (vis[v] > vis[u] + 1)
            {
                vis[v] = vis[u] + 1;
                q.push(v);
            }
        }
    }

    return;
}

void multisourceDistance(vi source)
{
    vis.assign(n, inf);
    queue<int> q;
    for (auto &u : source)
    {
        vis[u] = 0;
        q.push(u);
    }

    int u;
    while (q.size())
    {
        u = q.front();
        q.pop();

        for (auto &v : gr[u])
        {
            if (vis[v] > vis[u] + 1)
            {
                vis[v] = vis[u] + 1;
                q.push(v);
            }
        }
    }

    return;
}

/*
int n, m;
V<vi> gr;
vi vis;

void solve()
{
    cin >> n >> m;
    gr.resize(n, vi(0));
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        u--, v--;

        gr[u].pb(v);
        gr[v].pb(u);
    }

    multisourceDistance({0});

    f(i, 0, n)
    {
        cout << eif((vis[i] == inf), -1, vis[i]) << sp;
    }
    cout << el;

    return;
}

*/

// 01dfs_Snippt -----------------------------------------------------------
void distance(int u)
{
    vis.assign(n, inf);
    vis[u] = 0;

    deque<int> q;
    q.push_back(u);
    while (q.size())
    {
        u = q.front();
        q.pop_front();

        for (auto &v : gr[u])
        {
            if (vis[v.ff] > vis[u] + v.ss)
            {
                vis[v.ff] = vis[u] + v.ss;

                if (v.ss)
                    q.push_back(v.ff);
                else
                    q.push_front(v.ff);
            }
        }
    }

    return;
}

/*
// Zero one Graph
int n, m;
V<V<pii>> gr;
vi vis;

void solve()
{
    cin >> n >> m;
    gr.resize(n, V<pii>(0));
    int u, v, w;

    f(i, 0, m)
    {
        cin >> u >> v >> w;
        u--, v--;
        gr[u].pb({v, w});
        gr[v].pb({u, w});
    }

    distance(0);

    f(i, 0, n)
    {
        cout << eif((vis[i] == inf), -1, vis[i]) << sp;
    }
    cout << el;

    return;
}

*/

// -----------------------------------------------------------

// -----------------------------------------------------------

// -----------------------------------------------------------

// -----------------------------------------------------------

// -----------------------------------------------------------

// -----------------------------------------------------------

// -----------------------------------------------------------

// -----------------------------------------------------------

// -----------------------------------------------------------



