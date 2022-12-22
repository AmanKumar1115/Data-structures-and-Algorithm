//WAP to Rearrange a linked list such that all even and odd positioned nodes will be together.
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
struct node* even_odd_positioned(struct node* head)
{
    struct node* odd=head;
    struct node* even=head->next;
    struct node* es=even;
    while(odd->next!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=es;
    if(odd->next!=NULL)
        even->next=NULL;
    return head;  
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
    start=even_odd_positioned(start);
    printf("\nLinked list after arrangement: ");
    print(start);
    return 0;
}