#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *left = nullptr;
    node *right = nullptr;
};

#define node_pointer node *

class node_method
{
private:
    node_pointer create_node(int key = 0)
    {
        node_pointer root = new node;
        root->data = key;
        return root;
    }

public:
    node_pointer make_binary_tree()
    {
        //* 0 for null the node and -1 for break
        int key;
        cin >> key;
        if (key == 0 || key == -1)
            return nullptr;
        node_pointer root = create_node(key);
        queue<node_pointer> lavel;
        lavel.push(root);

        while (true)
        {
            if (lavel.size() == 0)
                break;
            node_pointer p = lavel.front();
            cin >> key;
            if (key == (-1))
                break;
            else if (key)
            {
                p->left = create_node(key);
                lavel.push(p->left);
            }

            cin >> key;
            if (key == (-1))
                break;
            else if (key)
            {
                p->right = create_node(key);
                lavel.push(p->right);
            }
            lavel.pop();
        }
        return root;
    }

    //~ lavel wish traversal
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

    //~ insertion according to BST  rule
    void BST_insertion(node_pointer &root, int key)
    {
        if (root == nullptr)
            root = create_node(key);
        else if (root->data > key)
            BST_insertion(root->left, key);
        else
            BST_insertion(root->right, key);
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

};

node_pointer root;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    node_pointer root = nullptr;
    node_method tree;
    int n;
    cin >> n;
    for (int i = 0, x; i < n; ++i)
    {
        cin >> x;
        tree.BST_insertion(root, x);
    }
    tree.breadth_wise_traversal(root);
    cout << endl;

    node_pointer binary_tree = tree.make_binary_tree();
    tree.breadth_wise_traversal(binary_tree);

    return 0;
}