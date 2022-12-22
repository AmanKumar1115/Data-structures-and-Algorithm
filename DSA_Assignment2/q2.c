// WAP to find the Nth node from the end of a Linked List
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
void print(struct node *start)
{
    while (start)
    {
        printf("%d ", start->info);
        start = start->next;
    }
}
void NTHnode_END(struct node *start, int s, int N)
{
    for (int i = 1; i < s + 1 - N; i++)
        start = start->next;
    printf("\nNth node from the end has the value : %d", start->info);
}
int main()
{
    int s, n;
    printf("\nEnter the number of node in the linked list:");
    scanf("%d", &s);
    printf("Enter the data in the linked list: ");
    struct node *start = NULL;
    for (int i = 0; i < s; i++)
    {
        int e;
        scanf("%d", &e);
        start = Insert(start, e);
    }
    printf("\nEnter the value of n(for Nth node from end): ");
    scanf("%d", &n);
    if (s < n)
    {
        printf("Node dose not exits!!");
        return 0;
    }
    NTHnode_END(start, s, n);
    return 0;
}