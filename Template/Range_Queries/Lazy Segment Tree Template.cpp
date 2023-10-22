#include <bits/stdc++.h>
using namespace std;

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
**  Some Importance Ideas of Segment Trees -->
1.   T -> type of input array elements
2.   V -> type of required aggregate statistic or data type of Node vaule

** 	Definite the Segment Tree Node -->
1.   assignLeaf function -> Update the value of node
2.   merge function -> Combined the nodes
3.   getValue function -> return the value of the node
4. 	 assignLazy function -> assign the node to lazy value
5.   is_lazy function -> it return function has lazy assign or not
6.   lazyAssign function -> it assign lazy value to node values

**  Functions of Segment Tree -->
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
