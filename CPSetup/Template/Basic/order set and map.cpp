#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
template <typename K, typename V, typename Comp = std::less<K>>
using omap = __gnu_pbds::tree<K, V, Comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <typename K, typename Comp = std::less<K>> using oset = omap<K, __gnu_pbds::null_type, Comp>;

int main()
{
    oset<int> s;
    s.insert(20);
    s.insert(50);
    cout << s.order_of_key(60) << endl;  // count elements smaller than 60
    cout << *s.find_by_order(1) << endl; // element with index 1
}