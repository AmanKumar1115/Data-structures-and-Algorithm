// Given a linked list and a value x, partition it such that all nodes less than x come
// before nodes greater than or equal to x.
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
void print(struct node *start)
{
    while (start != NULL)
    {
        printf("%d ", start->data);
        start = start->next;
    }
}
struct node *parition(struct node *start, int x)
{
    struct node hsmall, *small = &hsmall;
    hsmall.next = start;
    struct node hgreater, *greater = &hgreater;
    while (start)
    {
        if (start->data < x)
        {
            small->next = start;
            small = small->next;
        }
        else
        {
            greater->next = start;
            greater = greater->next;
        }
        start = start->next;
    }
    small->next = hgreater.next;
    greater->next = NULL;
    hgreater.next = NULL;
    return hsmall.next;
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
    printf("\nEnter the partition value :");
    int v;
    scanf("%d", &v);
    start = parition(start, v);
    printf("\nLinked list after arrangement: ");
    print(start);
    return 0;
}
