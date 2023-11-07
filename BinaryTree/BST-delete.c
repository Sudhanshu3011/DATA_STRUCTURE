#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node)); // allocating the size dynamically
    new->data = data;                                 // data
    new->left = NULL;                                 // linking the left
    new->right = NULL;                                // linking the right
    return new;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
struct node *inodprece(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *delete(struct node *root, int key)
{
    struct node *pre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->right == NULL && root->left == NULL)
    {
        free(root);
        return NULL;
    }
    if (root->data < key)
    {
        root->right = delete (root->right, key);
    }
    else if (root->data > key)
    {
        root->left = delete (root->left, key);
    }
    else
    {
        pre = inodprece(root);
        root->data = pre->data;
        root->left = delete (root->left, pre->data);
    }
    return root;
}

int Isbst(struct node *root)
{
    // creating a new node for storing the data purpose
    static struct node *pre = NULL;
    if (root != NULL)
    {
        // calling the function again for the left root
        if (!Isbst(root->left))
        {
            return 0;
        }
        // comparision statement
        if (pre != NULL && root->data <= pre->data)
        {
            return 0;
        }
        pre = root;
        // right root
        return Isbst(root->right);
    }
    else
    {
        return 1;
    }
}
struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == key)
    {
        return root;
    }
    else if (root->data < key)
    {
        search(root->right, key);
    }
    else
    {
        search(root->left, key);
    }
}

int main()
{
    struct node *s = createnode(18);
    struct node *s1 = createnode(7);
    struct node *s2 = createnode(45);
    struct node *s3 = createnode(4);
    struct node *s4 = createnode(8);
    struct node *s5 = createnode(20);

    // struct node *s1= createnode(33);
    //       18
    //      /  \
    //     7    45
    //   /  \   /
    //  4    8 20
    s->left = s1;
    s->right = s2;
    s1->left = s3;
    s1->right = s4;
    s2->left = s5;
    if (Isbst(s))
    {
        printf("The tree is BST.\n");
    }
    else
    {
        printf("The tree is not BST.\n");
    }

    inorder(s);
    //deletion of leaf
    // s = delete (s, 4);
    // printf("\n");
    // inorder(s);
    //deletion of non leaf
    s=delete(s,7);
    printf("\n");
    inorder(s);
    //deletion of root 
    // s=delete(s,18);
    // printf("\n");
    // inorder(s);
    return 0;
}
