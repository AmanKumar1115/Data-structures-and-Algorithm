/*WAP prpgram to sort the linked list using following operation:
1. Ascending :small element of the list will move to the initial node
2. Descending :Large element will move to the initial node*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *InsertAtEnd(struct node *start, int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node *));
    temp->info = n;
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
struct node *ascending(struct node *start)
{
    struct node *q, *p, *small = start;
    for (q = start; q != NULL; q = q->next)
    {
        small = q;
        for (p = q->next; p != NULL; p = p->next)
        {
            if (p->info < small->info)
            {
                small = p;
            }
        }
        int x = q->info;
        q->info = small->info;
        small->info = x;
    }

    return start;
}
struct node *descending(struct node *start)
{
    struct node *q, *p, *small = start;
    for (q = start; q != NULL; q = q->next)
    {
        small = q;
        for (p = q->next; p != NULL; p = p->next)
        {
            if (p->info > small->info)
            {
                small = p;
            }
        }
        int x = q->info;
        q->info = small->info;
        small->info = x;
    }

    return start;
}

int main()
{
    printf("\nEnter the number of element in the linked list :");
    int n;
    scanf("%d", &n);
    struct node *start = NULL;
    printf("\nEnter element of the linked list: \n");
    for (int i = 0; i < n; i++)
    {
        int e;
        scanf("%d", &e);
        start = InsertAtEnd(start, e);
    }
    printf("\nLinked list element are: \n");
    print(start);

    start = ascending(start);
    printf("\nList in ascending order:\n ");
    print(start);

    start = descending(start);
    printf("\nList in descending  order:\n ");
    print(start);
    return 0;
}
