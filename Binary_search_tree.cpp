/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।

    কার জন্য কাজ করছো ?
    এবং কি কাজ করছো?
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

class BST
{
private:
    //~ Structure for Node
    typedef struct node
    {
        int data;
        node *left = nullptr;
        node *right = nullptr;
    } *node_pointer;

    //~ Insert a node in Binary Search tree
    node_pointer create(int key = 0)
    {
        node_pointer root = new node;
        root->data = key;
        return root;
    }
    void insert(node_pointer &root, int key)
    {
        if (root == nullptr)
            root = create(key);
        else if (root->data > key)
            insert(root->left, key);
        else if (root->data < key)
            insert(root->right, key);
        else
            --no_of_node;
        return;
    }

    //~ Searching a node
    bool search(node_pointer root, int key)
    {
        if (root == nullptr)
            return false;
        else if (root->data > key)
            return search(root->left, key);
        else if (root->data < key)
            return search(root->right, key);
        else
            return true;
    }

    //~ Breadth wish traversal
    void breadth_wise_traversal(node_pointer root)
    {
        if (root == nullptr)
            return;
        queue<node_pointer> lavel;
        lavel.push(root);
        node_pointer p;
        while (lavel.size())
        {
            p = lavel.front();
            if (p->left)
                lavel.push(p->left);
            if (p->right)
                lavel.push(p->right);
            cout << p->data << ' ';
            lavel.pop();
        }
        return;
    }
    //~ Depth wish traversal
    void preorder(node_pointer root)
    {
        if (root == nullptr)
            return;
        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
        return;
    }
    void inorder(node_pointer root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
        return;
    }
    void postorder(node_pointer root)
    {
        if (root == nullptr)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << endl;
        return;
    }

    //~ Delete a node
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
    
    //~ FREE Tree all
    void tree_free(node_pointer root)
    {
        if (root)
        {
            tree_free(root->left);
            tree_free(root->right);
            free(root);
            root = nullptr;
        }
        return;
    }
    //~ count of height of the tree
    int height(node_pointer root)
    {
        if (root == NULL)
            return 0;

        int left_height = height(root->left);
        int right_height = height(root->right);
        return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
    }
    //~ Count of the leaf node
    int count_leaf(node_pointer root, int count)
    {
        if (root == NULL)
            return count;
        else if (root->left == NULL && root->right == NULL)
            return count + 1;
        count = count_leaf(root->left, count);
        count = count_leaf(root->left, count);
        return count;
    }

public:
    node_pointer Root = nullptr;
    int no_of_node = 0;
    void insert_node(int key)
    {
        insert(Root, key);
        ++no_of_node;
    }
};

void solve()
{

    return;
}