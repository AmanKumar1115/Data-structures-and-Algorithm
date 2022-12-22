/// 6. Write a Recursive function to print the Linked List in forward and reverse directions.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *Insert(struct node *start, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
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
void forward_print(struct node *start)
{
    if (start == NULL)
        return;
    printf("%d ", start->info);
    forward_print(start->next);
}
void reversed_print(struct node *start)
{
    if (start == NULL)
        return;
    reversed_print(start->next);
    printf("%d ", start->info);
}
int main()
{
    struct node* start=NULL;
    printf("\nEnter the number of element in the linked list: ");
    int n;scanf("%d ",&n);
    for(int i=0;i<n;i++)
    {
        int e;scanf("%d",&e);
        start=Insert(start,e);
    }
    printf("\nLinked list in forward direction: ");
    forward_print(start);
    printf("\nLinked list in reverse direction: ");
    reversed_print(start);
    return 0;
}