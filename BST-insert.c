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

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot be inserted %d, already in BST", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node* ins = createnode(key);
    if (key < prev->data)
    {
        prev->left = ins;
    }
    else
    {
        prev->right = ins;
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
    //   /  \   / \
    //  4    8 20  56
    s->left = s1;
    s->right = s2;
    s1->left = s3;
    s1->right = s4;
    s2->left = s5;
    insert(s, 56);

    if (Isbst(s))
    {
        printf("The tree is BST.\n");
    }
    else
    {
        printf("The tree is not BST.\n");
    }
    printf("%d",s->right->right->data);

    //       18
    //      /  \
    //     7    45
    //   /  \   /
    //  4    8 20

    return 0;
}
