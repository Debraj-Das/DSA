#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *intial_node(int data) //* for intiallised the node pointer.
{
    node *n = (node *)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node *insertion_point(node *root, int key)
{
    if (root == NULL)
        root = intial_node(key);
    else if (root->data > key)
        root->left = insertion_point(root->left, key);
    else
        root->right = insertion_point(root->right, key);

    return root;
}

void Preorder_print(node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        Preorder_print(root->left);
        Preorder_print(root->right);
    }
    return;
}

void Postorder_print(node *root)
{
    if (root)
    {
        Postorder_print(root->left);
        Postorder_print(root->right);
        printf("%d ", root->data);
    }
    return;
}

void Inorder_print(node *root)
{
    if (root)
    {
        Inorder_print(root->left);
        printf("%d ", root->data);
        Inorder_print(root->right);
    }
    return;
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

int hight_of_tree(node *root)
{
    if (root == NULL)
        return -1;
    int left_subtree_hight = hight_of_tree(root->left);
    int right_subtree_hight = hight_of_tree(root->right);

    if (left_subtree_hight > right_subtree_hight)
        return left_subtree_hight + 1;
    else
        return right_subtree_hight + 1;
}

int sum_of_tree(node *root)
{
    if (root == NULL)
        return 0;
    else
        return root->data + sum_of_tree(root->left) + sum_of_tree(root->right);
}

int maximum_of_tree(node *root)
{
    if (root == NULL)
        return INT_MIN;
    int left_max = maximum_of_tree(root->left);
    int right_max = maximum_of_tree(root->right);
    int max = root->data;
    if (max < left_max)
        max = left_max;
    if (max < right_max)
        max = right_max;
    return max;
}

int minimum_of_tree(node *root)
{
    if (root == NULL)
        return INT_MAX;
    int left_min = minimum_of_tree(root->left);
    int right_min = minimum_of_tree(root->right);
    int min = root->data;
    if (min > left_min)
        min = left_min;
    if (min > right_min)
        min = right_min;
    return min;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    node *root = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0, x; i < n; ++i)
    {
        scanf("%d", &x);
        root = insertion_point(root, x);
    }
    printf("inorder tree :: \n");
    Inorder_print(root);
    printf("\n");

    printf("preorder tree :: \n");
    Preorder_print(root);
    printf("\n");

    printf("postorder tree :: \n");
    Postorder_print(root);
    printf("\n");

    printf("Hight : %d\n", hight_of_tree(root));
    printf("sum : %d\n", sum_of_tree(root));
    printf("max : %d\n", maximum_of_tree(root));
    printf("min : %d\n",minimum_of_tree(root));
    //    if(check_tree_is_bst_or_not(root))
    //    printf("\nRoot is a Binary search tree\n\n");
    //    else
    //     printf("\nRoot is not a Binary search tree\n\n");

    tree_free(root);

    return 0;
}
