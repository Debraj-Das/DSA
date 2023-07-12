/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;
void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    //	cin >> t;
    while (t--)
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

typedef int keyVal;

typedef struct node
{
    keyVal data;
    node *left;
    node *right;
} *node_pointer;

node_pointer create(int key)
{
    node_pointer root = new node;
    root->data = key;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void insert(node_pointer &root, int key)
{
    if (root == NULL)
        root = create(key);
    else if (key < root->data)
        insert(root->left, key);
    else
        insert(root->right, key);

    return;
}

void put(node_pointer &root, node_pointer &p)
{
    if (root == nullptr)
        root = p;
    else
        put(root->left, p);
    return;
}

void del(node_pointer &root, int key)
{
    if (root == nullptr)
        return;
    else if (root->data > key)
        del(root->left, key);
    else if (root->data < key)
        del(root->right, key);
    else
    {
        node_pointer p = root;
        if (root->right == nullptr)
            root = root->left;
        else
        {
            root = root->right;
            put(root->right, root->left);
        }
        delete p;
    }
    return;
}

void inorder(node_pointer &root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
    return;
}

void solve()
{
    node_pointer root = nullptr;
    int n;
    cin >> n;
    for (int i = 0, key; i < n; ++i)
    {
        cin >> key;
        insert(root, key);
    }

    inorder(root);
    cout << endl;
    cin >> n;
    del(root, n);
    inorder(root);
    cout << endl;

    return;
}