//Write a recursive function in C to reverse a singly linked list.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node* next;
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
        for (q = start; q->next != NULL; q = q->next);
        q->next = temp;
    }
    return start;
}
void print(struct node* start)
{
    while(start)
    {
        printf("%d ",start->info);
        start=start->next;
    }
}
struct node* reverse_recursive(struct node* start)
{
    if(start==NULL||start->next==NULL)
        return start;
    struct node* reverse = reverse_recursive(start->next);
    start->next->next=start;
    start->next=NULL;
    return reverse;
}
int main()
{
    printf("\nEnter the number element in the linked list: ");
    int N;
    scanf("%d",&N);
    struct node* start=NULL;
    printf("\nEnter data element: ");
    for(int i=0;i<N;i++)
    {
        int e;
        scanf("%d",&e);start=Insert(start,e);
    }
    printf("\nEntered linked list: ");
    print(start);
    start=reverse_recursive(start);
    printf("\nLinked list after arrangement: ");
    print(start);
    return 0;
}