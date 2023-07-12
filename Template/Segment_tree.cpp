#include <bits/stdc++.h> 
using namespace std;

/*
$   Some Importance Ideas of Segment Trees ::
    T is the type of input array elements
    V is the type of required aggregate statistic or data type of Node vaule
/    assignLeaf function Update, Depends What store in Node vaule
/    merge function Update, Depends what you store inside of in Node vaule
    Functions
    Constructor -> arguments : array , size of array
    getVaule -> give the vaule of the any Queries -> argument : range of index according to array
    update -> it update the SegmentTree -> argument : index , update vaule
*   Some example ->
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree<int, int> tree(arr, 8);
    cout << tree.getValue(0, 4) << '\n';
    tree.update(4, 10);
    cout << tree.getValue(2, 6) << '\n';
*/
template <class T, class V>
class SegmentTree
{
private:
    struct SegmentTreeNode
    {
        V value;
        void assignLeaf(T a)
        {
            value = a; // Update according to Questions
            return;
        }
        void merge(SegmentTreeNode a, SegmentTreeNode b)
        {
            value = a.value + b.value; // Update according to Questions
            return;
        }
        V getValue() { return value; }
    };
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

    ~SegmentTree() { delete[] nodes; }

    V getValue(int lo, int hi)
    {
        SegmentTreeNode result = getValue(1, 0, N - 1, lo, hi);
        return result.getValue();
    }

    void update(int index, T value) { update(1, 0, N - 1, index, value); }
};


