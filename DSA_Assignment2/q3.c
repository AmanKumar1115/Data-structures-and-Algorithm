// Write a function to delete the whole Linked List
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
struct node* deletenode(struct node* start)
{
    struct node* q;
    while (start)
    {
        q = start;
        start = start->next;
        free(q);
    }
    return start;
}
int main()
{
    struct node *start = NULL, *q;
    printf("Enter the number of element in the linked list: ");
    int n;
    scanf("%d", &n);
    printf("\nEnter the data :");
    for (int i = 0; i < n; i++)
    {
        int e;
        scanf("%d", &e);
        start = Insert(start, e);
    }
    printf("\nLinked list: ");
    q = start;
    while (q)
    {
        printf("%d ", q->info);
        q=q->next;
    }
    start=deletenode(start);
    if (start == NULL)
        printf("\nLINKED LIST IS DELETED!!!");
    return 0;
}