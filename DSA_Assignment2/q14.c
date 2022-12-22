// Write a function to find the union of two linked lists.
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
void print(struct node *start)
{
    while (start)
    {
        printf("%d ", start->info);
        start = start->next;
    }
}
struct node *Join(struct node *start1, struct node *start2)
{
    if (start1 == NULL)
        return start2;
    else
    {
        struct node *q;
        for (q = start1; q->next != NULL; q = q->next)
            ;
        q->next = start2;
    }
    return start1;
}
struct node* union_list(struct node* start)
{
    struct node *p1, *p2, *prev;
    for (p1 = start; p1->next != NULL; p1 = p1->next)
    {
        prev = p1;
        for (p2 = p1->next; p2->next != NULL;)
        {
            if (p1->info == p2->info)
            {
                prev->next = p2->next;
                free(p2);
                p2=prev->next;
            }
            else
            {
                prev = p2;
                p2 = p2->next;
            }
        }
    }
    return start;
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
    start1 = Join(start1, start2);
    start1 = union_list(start1);
    printf("\nUnion of two linked lists:");
    print(start1);
    return 0;
}
