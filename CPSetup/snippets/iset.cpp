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
