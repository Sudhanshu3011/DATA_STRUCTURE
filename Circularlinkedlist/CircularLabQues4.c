#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *delete(struct node *head,int index)
{
    
   int i=1;
    struct node *p = head;
    
    do{
        p=p->next;
        i++;
    }while(i<index);
   
   if(p->next==head){
        p->next=p->next->next;
       head=p->next;
       return head;
   }
   else{
        p->next=p->next->next;
         do{
        p=p->next;
    }while(p!=head);
   }


    

    return head;
}
void traversal(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *ptr = head;
    do
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}


int main()
{
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;
    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = first;

    first->data = 102;
    first->next = second;

    second->data = 12;
    second->next = third;

    third->data = 14;
    third->next = head;
    printf("Before deletion.\n");
    traversal(head);
    head = delete(head,2);
    printf("After deletion.\n");
    traversal(head);

    return 0;
}

