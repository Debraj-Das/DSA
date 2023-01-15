/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;
void solve();

struct Bst
{
    int data;
    Bst *leftnode;
    Bst *rightnode;
};

Bst *create(int n)
{
    Bst *root = new Bst;
    root->leftnode = NULL;
    root->rightnode = NULL;
    root->data = n;
    return root;
}

Bst *intial(Bst *root)
{
    if(root == NULL)
    return root ;
    int left , right ;
    cout<<"Enter the left node : ";
    cin>>left ;
    if(left == -1)
    root->leftnode = NULL;
    else root->leftnode = create(left) ;
    cout<<"Enter the right node : ";
    cin>>right ;
    if(left == -1)
    root->rightnode = NULL;
    else root->rightnode = create(right);
    root->leftnode = intial(root->leftnode);
    root->rightnode = intial(root->rightnode);
    return root ;
}

void print(Bst *root)
{
    if(root == NULL)
    return ;
    else
    {
        cout<<root->data<<':';
        if(root->leftnode)
        cout<<' '<<root->leftnode->data;
        if(root->rightnode)
        cout<<' '<<root->rightnode->data;
    }
    cout<<endl;
    print(root->leftnode);
    print(root->rightnode);
    return ;
}

int32_t main()
{
   int r ;
    cout<<"Enter the root ";
    cin>>r;
     Bst *root ;
    if(r==-1)
    root = NULL ;
    else
    root= create(r);
    root = intial(root);
    print(root);
    return 0;
}

void solve()
{
    int r ;
    cout<<"Enter the root ";
    cin>>r;
     Bst *root ;
    if(r==-1)
    root = NULL ;
    else
    root= create(r);
    root = intial(root);
    print(root);
    return;
}