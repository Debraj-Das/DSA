/*
~ merge function is used to merge two nodes to create parent node
* So Define merge function according to the query
e.g: sum Query
    merge(a,b) { return a+b;}
e.g: min Query
    merge(a,b) { return min(a,b);}

* How to use the Segment Class Example
template <typename T>
T merge(T a, T b)
{
    return a + b;
}

int main()
{
    int arr[] = {5, 8, 6, 3, 2, 7};
    SegmentTree<int, merge> st(arr, 6);

    std::cout << st.getValue(0, 1) << std::endl;
    st.update(0, 10);
    std::cout << st.getValue(0, 1) << std::endl;

    return 0;
}

*/

/*
! Instructions to use Segment Tree Class
* Data type of the segment tree is T
T = int , double or any other data type
@ merge function is used to merge two nodes to create parent node

~Public functions of Segment Tree Class
* Constructor of Segment tree
    SegmentTree(std::vector<T> arr)
    SegmentTree(T arr[], int n)

* Update the value of the index-th element to value
    void update(int index, T value)

* Get the value of the function over the range [lo, hi]
    T getValue(int lo, int hi)
*/

#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP
#include <vector>

template <typename T, T (*merge)(T, T)>
class SegmentTree
{
protected:
    std::vector<T> tree;
    int n;
    void build(std::vector<T> &arr)
    {
        for (int i = 0; i < n; i++)
            tree[n + i - 1] = arr[i];
        for (int i = n - 2; i >= 0; i--)
            tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
    }

public:
    // Constructors
    SegmentTree(std::vector<T> arr)
    {
        n = arr.size();
        this->tree.resize(2 * n - 1);
        build(arr);
    }
    SegmentTree(T arr[], int n)
    {
        this->n = n;
        this->tree.resize(2 * n - 1);
        std::vector<T> v(arr, arr + n);
        build(v);
    }

    // Update the value of the index-th element to value
    void update(int index, T value)
    {
        index += n - 1;
        tree[index] = value;
        while (index > 0)
        {
            index = (index - 1) / 2;
            tree[index] = merge(tree[2 * index + 1], tree[2 * index + 2]);
        }
        return;
    }

    // Get the value of the function over the range [lo, hi]
    T getValue(int lo, int hi)
    {
        lo += n, hi += n;
        T res = 0;
        while (lo <= hi)
        {
            if (lo % 2 == 1)
                res = merge(res, tree[lo++ - 1]);
            if (hi % 2 == 0)
                res = merge(res, tree[hi-- - 1]);
            lo >>= 1, hi >>= 1;
        }
        return res;
    }
};

#endif // SEGMENT_TREE_HPP