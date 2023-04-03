/*
Some Importance Class template ->
1. recurrence
2. segment tree
3. 


*/
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
struct Mat
{
    int sz;
    vector<vector<int>> m;
    Mat(int size = 2)
    {
        sz = size;
        m.resize(sz);
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                m[i].push_back(0);
            }
        }
    }

    void identity()
    {
        for (int i = 0; i < sz; i++)
            m[i][i] = 1;
        return;
    }

    Mat operator*(Mat a)
    {
        Mat res(sz);
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                for (int k = 0; k < sz; k++)
                {
                    res.m[i][j] += m[i][k] * a.m[k][j];
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }

    Mat operator^(int n)
    {
        Mat res(sz);
        res.identity();

        Mat T(*this);
        while (n)
        {
            if (n & 1)
                res = res * T;
            T = T * T, n >>= 1;
        }
        return res;
    }
};

struct Recurrence
{
private:
    int sz;
    int order;
    Mat *matrix;
    vector<int> b;

public:
    Recurrence(vector<int> coeffience = {1, 1}, vector<int> base = {1, 1}, bool homo = true)
    {
        sz = coeffience.size();
        order = base.size();
        if (homo)
        {
            if (order != sz)
                exit(-1);
        }
        else
        {
            if (order != (sz - 1))
                exit(-1);
        }

        matrix = new Mat(sz);
        for (int i = 0; i < sz; ++i)
            matrix->m[0][i] = coeffience[i];

        for (int i = 1; i < order; ++i)
            matrix->m[i][i - 1] = 1;

        for (int i = order - 1; i >= 0; --i)
            b.push_back(base[i]);

        if (!homo)
        {
            matrix->m[sz - 1][sz - 1] = 1;
            b.push_back(1);
        }
    }

    ~Recurrence()
    {
        delete matrix;
    }

    int nth_element(int n) //* find the nth element
    {
        if (n < 0)
            return (-1);
        else if (n < order)
            return b[n];

        Mat T(*matrix);
        n = (n - order + 1); //~ assumsed element start from 0
        Mat res = T ^ n;

        long long val = 0;
        for (int i = 0; i < sz; ++i)
            val = ((res.m[0][i] * b[i]) % mod + val % mod);
        return (val % mod);
    }
};



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


