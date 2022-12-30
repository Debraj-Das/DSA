#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createNode(int data)
{
    node *n;                          // creating a node pointer
    n = (node *)malloc(sizeof(node)); // Allocating memory in the heap
    n->data = data;                   // Setting the data
    n->left = NULL;                   // Setting the left and right children to NULL
    n->right = NULL;                  // Setting the left and right children to NULL
    return n;                         // Finally returning the created node
}

void preOrder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    return;
}

void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
    return;
}

void inOrder(node *root)
{
    if (root)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
    return;
}

int isBST(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

node *searchIter(node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

void insert(node *root, int key)
{
    node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
            return;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    node *new = createNode(key);
    if (key < prev->data)
        prev->left = new;
    else
        prev->right = new;
    return;
}

node *deleteNode(node *root, int value)
{
    if (root)
    {                                                // # searching for the node to be deleted
        if (value < root->data)
            root->left = deleteNode(root->left, value);
        else if (value > root->data)
            root->right = deleteNode(root->right, value);

        else                                        //* deletion strategy when the node is found
        {
            if (root->left == NULL || root->right == NULL)
            {
                node *temp;
                if (root->left)
                    temp = root->left;
                else
                    temp = root->right;
                free(root);
                root = temp;
            }
            else
            {
                node *iPre = root->left;
                while (iPre->right != NULL)
                    iPre = iPre->right;
                root->data = iPre->data;
                root->left = deleteNode(root->left, iPre->data);
            }
        }
    }
    return root;
}

void tree_free(node *root)
{
    if (root)
    {
        tree_free(root->left);
        tree_free(root->right);
        free(root);
    }
    return;
}

int main()
{

    // Constructing the root node - Using Function (Recommended)
    node *p = createNode(5);
    insert(p, 3);
    insert(p, 6);
    insert(p, 1);
    insert(p, 4);
    // # Finally The tree looks like this:
    //        5
    //       / \
    //      3   6
    //     / \
    //    1   4

    inOrder(p);
    printf("\n");
    deleteNode(p, 5);
    inOrder(p);
    printf("\n");

    tree_free(p);
    return 0;
}
