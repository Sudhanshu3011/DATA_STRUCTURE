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
int main()
{
    struct node *s = createnode(18);
    struct node *s1 = createnode(7);
    struct node *s2 = createnode(45);
    struct node *s3 = createnode(4);
    struct node *s4 = createnode(8);
    struct node *s5 = createnode(15);

    // struct node *s1= createnode(33);
    s->left = s1;
    s->right = s2;
    s1->left = s3;
    s1->right = s4;
    s2->left = s5;
    inorder(s);
        //       18
        //      /  \
        //     7    45
        //   /  \   /
        //  4    8 15

    return 0;
}
