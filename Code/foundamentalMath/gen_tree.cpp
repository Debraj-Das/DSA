// generating a tree in random ways 1 to n vertex
#include <bits/stdc++.h>
using namespace std;

const char el = '\n';
const char sp = ' ';

// clang-format off
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int rdi(int l = 0, int r = 1e9){ return std::uniform_int_distribution<int>(l, r)(rng);}
// clang-format on

int main()
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
