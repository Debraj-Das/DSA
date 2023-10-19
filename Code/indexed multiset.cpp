#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    oset<pair<int, int>> inset;

    // Insert elements into the indexed multiset.
    inset.insert(make_pair(5, 1));
    inset.insert(make_pair(2, 2));
    inset.insert(make_pair(5, 3)); // Duplicate elements are allowed.

    // Count elements less than or equal to a given value.
    int count = inset.order_of_key(make_pair(6, 3));

    cout << count << '\n';

    inset.erase({5, 1});

    // Find the order statistics for an element.
    pair<int, int> rank = *inset.find_by_order(1); // This returns the second smallest element (0-based index).

    cout << rank.first << '\n';

    return 0;
}
