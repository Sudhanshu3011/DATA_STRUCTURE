#include<stdio.h>
#include<malloc.h>
struct node {
    int data;
    struct node* left;
    struct node * right;
};
struct node *createnode(int data)
{
    struct node *new;
    new= (struct node*)malloc(sizeof(struct node));//allocating the size dynamically
    new->data=data;//data
    new->left=NULL;//linking the left 
    new->right=NULL;//linking the right
    return new;
}
int main()
{
    struct node *s= createnode(18);
    struct node *s1= createnode(7);
    struct node *s2= createnode(45);
    
    // struct node *s1= createnode(33);
   s->left=s1;
   s->right=s2;

}