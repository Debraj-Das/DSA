#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
}node ;

node *createNode(int key)
{
    node *nod = (node *)malloc(sizeof(node));
    nod->key = key;
    nod->left = NULL;
    nod->right = NULL;
    nod->height = 1;
    return nod ;
}

int getHeight(node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBalanceFactor(node *n)
{
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
}

node *insert(node *node, int key)
{
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node ;   //* this condition for nonrepitation condition.
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    //# Left Left Case
    if (bf > 1 && key < node->left->key)
        return rightRotate(node);
    //# Right Right Case
    if (bf < -1 && key > node->right->key)
        return leftRotate(node);
    //$ Left Right Case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    //$ Right Left Case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
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
    node *root = NULL;
   int n;
   printf("Enter the set number :: ");
   scanf("%d", &n);
   for (int i = 0, data; i < n; ++i)
   {
      printf("%d) ", (i + 1));
      scanf("%d", &data);
      root = insert(root, data);
   }

    preOrder(root);
    printf("\n");
    tree_free(root) ;
    return 0;
}
