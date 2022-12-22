// WAP to Merge two sorted linked lists such that the merged list is in reverse order
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
struct node *reverse_merge(struct node *start1, struct node *start2)
{
    struct node *p = NULL;
    struct node *q = NULL;
    while (start1 && start2)
    {
        if (start1->info < start2->info)
        {
            q = start1->next;
            start1->next = p;
            p = start1;
            start1 = q;
        }
        else
        {
            q = start2->next;
            start2->next = p;
            p = start2;
            start2 = q;
        }
    }
    while (start1)
    {
        q = start1->next;
        start1->next = p;
        p = start1;
        start1 = q;
    }
    while (start2)
    {
        q = start2->next;
        start2->next = p;
        p = start2;
        start2 = q;
    }
    return p;
}
int main()
{
    printf("\nEnter the number of the element in the linked list1:");
    int N, M;
    scanf("%d", &N);
    printf("\nEnter the number of the element in the linked list2:");
    scanf("%d", &M);
    struct node *start1 = NULL;
    struct node *start2 = NULL;
    printf("\nEnter the data in sorted order of the linked list1: ");
    for (int i = 0; i < N; i++)
    {
        int e;
        scanf("%d", &e);
        start1 = Insert(start1, e);
    }
    printf("\nEnter the data in sorted order of the linked list2: ");
    for (int i = 0; i < M; i++)
    {
        int e;
        scanf("%d", &e);
        start2 = Insert(start2, e);
    }
    printf("\nEntered linked list1: ");
    print(start1);
    printf("\nEntered linked list2: ");
    print(start2);
    start1 = reverse_merge(start1, start2);
    printf("\nTwo sorted linked lists such that the merged list is in reverse order:");
    print(start1);
    return 0;
}