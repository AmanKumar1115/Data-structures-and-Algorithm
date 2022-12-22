//Given a singly linked list, write a function to swap elements pair-wise.
//For example, if the linked list is 1->2->3->4->5 then the function should change it
//to 2->1->4->3->5, and if the linked list is 1->2->3->4->5->6 then the function
//should change it to 2->1->4->3->6->5.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *Insert(struct node *start, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct node *q;
        for (q = start; q->next != NULL; q = q->next)
            ;
        q->next = temp;
    }
    return start;
}
void print(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
struct node* swap_pair(struct node* start)
{
    int x;
    struct node* temp=start;
    while(temp!=NULL && temp->next!=NULL)
    {
        x = temp->data;
        temp->data=temp->next->data;
        temp->next->data=x;
        temp=temp->next->next;     
    }
    printf("\nB\n");
    return start;
}
int main()
{
    printf("\nEnter the number element in the linked list: ");
    int N;
    scanf("%d", &N);
    struct node *start = NULL;
    printf("\nEnter data element: ");
    for (int i = 0; i < N; i++)
    {
        int e;
        scanf("%d", &e);
        start = Insert(start, e);
    }
    printf("\nEntered linked list: ");
    print(start);
    start = swap_pair(start);
    printf("\nC\n");
    printf("\nLinked list after swap pair wise: ");
    print(start);
    return 0;
}
