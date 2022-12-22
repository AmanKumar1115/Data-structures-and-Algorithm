// WAP to Reverse a Linked List in groups of a given size. (Note: If a linked list
// consists of 12 elements and the size of the group is 3, then the first 3 elements need
// to be reversed, the next 3 elements need to be reversed, and so on.
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
        start = temp;
    else
    {
        struct node *q;
        for (q = start; q->next != NULL; q = q->next)
            ;
        q->next = temp;
    }
    return start;
}
int count_node(struct node *start)
{
    int c = 0;
    for (; start != NULL; start = start->next)
        c++;
    return c;
}
struct node *reverseK(struct node *start, int k)
{
    if (start == NULL)
        return NULL;
    struct node *next = NULL;
    struct node *curr = start;
    struct node *prev = NULL;
    int count = 0;
    int l = count_node(start);
    if (l >= k)
    {
        for (; curr != NULL && count < k; curr = next)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            count++;
        }
        if (next != NULL)
            start->next = reverseK(next, k);
        return prev;
    }
    else
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
int main()
{
    struct node *start = NULL;
    printf("\nEnter the number of the element in the linked list: ");
    int n;
    scanf("%d", &n);
    printf("\nEnter data:");
    for (int i = 0; i < n; i++)
    {
        int e;
        scanf("%d", &e);
        start = Insert(start, e);
    }
    printf("\nEnter the size of the group :");
    int k;
    scanf("%d", &k);
    printf("\nLinked list before group reverse: ");
    print(start);
    start = reverseK(start, k);
    printf("\nLinked list after group reverse: ");
    print(start);
    return 0;
}