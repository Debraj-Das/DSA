#include <bits/stdc++.h>
using namespace std;

#define el '\n'

inline void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();

    return 0;
}

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

void solve()
{
    int ar[] = {2, 3, 4, 5, 6};

    SegmentTree<int, int> sg(ar, 5);

    cout << sg.getValue(1, 3) << el;

    return;
}
