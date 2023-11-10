#include <stdio.h>
#include <stdlib.h>

// The structure for making the AVL tree
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
int max(int a, int b)
{
    return a > b ? a : b;
}

// tracking the height
int getheight(struct node *s)
{
    if (s == NULL)
    {
        return 0;
    }
    return s->height;
}

// creating a new node dynamically
struct node *createnode(int key)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = key;
    new->left = NULL;
    new->right = NULL;
    new->height = 1;

    return new;
}

// balancing factor of the root
int balancefac(struct node *s)
{
    if (s == NULL)
    {
        return 0;
    }
    return getheight(s->left) - getheight(s->right);
}
// preorder trasversal
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/*
->the process of left rotation
#left rotation
      x              ___\                 v
     / \                 \               / \
 T(1)   v            ___ /              x   T(3)
      /  \              /              / \
    T(2) T(3)                       T(1)  T(2)
*/
struct node *leftrotate(struct node *x)
{
    struct node *v = x->right;
    struct node *T2 = v->left;

    v->left = x;
    x->right = T2;

    v->height = max(getheight(v->right), getheight(v->left)) + 1;
    x->height = max(getheight(x->right), getheight(x->left)) + 1;

    return v;
}

/*
->the process of right rotation
#left rotation
      v              ___\                 x
     / \                 \               / \
    x   T(3)         ___ /            T(1)  v
   / \                  /                  / \
T(1) T(2)                               T(2) T(3)
*/
struct node *rightrotate(struct node *v)
{
    struct node *x = v->left;
    struct node *T2 = x->right;

    x->right = v;
    v->left = T2;

    v->height = max(getheight(v->right), getheight(v->left)) + 1;
    x->height = max(getheight(x->right), getheight(x->left)) + 1;

    return x;
}
// insertion of the key in order
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return createnode(key);
    }
    if (key < node->data)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->data)
    {
        node->right = insert(node->right, key);
    }

    // Here the code is updating fo the leaf node of the AVL tree
    node->height = max(getheight(node->left), getheight(node->right)) + 1;
    int bf = balancefac(node);

    // left left rotation
    if (bf > 1 && key < node->left->data)
    {
        return rightrotate(node);
    }
    // left right rotation
    if (bf > 1 && key > node->left->data)
    {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }
    // right left rotation
    if (bf < -1 && key < node->right->data)
    {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
    // right right rotation
    if (bf < -1 && key > node->right->data)
    {
        return leftrotate(node);
    }

    return node;
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 3);

    preorder(root);
    


    return 0;
}