/*Find the smallest and largest element in the linked list */
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
    printf("\nLinked list element are: \n");
    while(start)
    {
        printf("%d ",start->info);
        start=start->next;
    }
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
        start=InsertAtEnd(start, e);
    }
    print(start);
    struct node *q = start;
    int max = INT_MIN;
    int min = INT_MAX;
    for (q = start; q != NULL; q = q->next)
    {
        if (q->info < min)
        {
            min = q->info;
        }
        if (q->info > max)
        {
            max = q->info;
        }
    }
    printf("\nLargest element:%d", max);
    printf("\nSmallest element:%d", min);
    return 0;
}