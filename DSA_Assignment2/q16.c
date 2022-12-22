// Write a function to find the differences between two linked lists.
#include <stdbool.h>
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
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
bool isPresent(struct node *head, int data)
{
    while (head != NULL)
    {
        if (head->data == data)
            return true;
        head = head->next;
    }
    return false;
}
struct node *getdifference(struct node *head1, struct node *head2)
{
    struct node dummy;
    struct node *result = &dummy;
    struct node *t1 = head1;
    struct node *t2 = head2;
    while (t1)
    {
        if (!isPresent(head2, t1->data))
        {
            result->next = t1;
            result = result->next;
        }
        t1 = t1->next;
        if (t2 != NULL)
            t2 = t2->next;
    }
    result->next = NULL;
    return dummy.next;
}

int main()
{
    printf("\nEnter the number of the element in the linked list1:");
    int N, M;
    scanf("%d", &N);
    printf("\nEnter the number of the element in the linked list2:");
    scanf("%d", &M);
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    printf("\nEnter the data of the linked list1: ");
    for (int i = 0; i < N; i++)
    {
        int e;
        scanf("%d", &e);
        head1 = Insert(head1, e);
    }
    printf("\nEnter the data of the linked list2: ");
    for (int i = 0; i < M; i++)
    {
        int e;
        scanf("%d", &e);
        head2 = Insert(head2, e);
    }
    struct node *intersecn = NULL;
    struct node *unin = NULL;
    printf("\n First list is \n");
    printList(head1);

    printf("\n Second list is \n");
    printList(head2);
    intersecn = getdifference(head1, head2);

    printf("\n Difference list is \n");
    printList(intersecn);
    return 0;
}
