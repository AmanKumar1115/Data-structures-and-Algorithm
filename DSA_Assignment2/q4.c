// WAP to detect a loop in a linked list and if exist then find the starting node of the loop and break the
// loop from the linked list.
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
struct node *detect(struct node *head)
{
    struct node *slow = head;
    struct node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return slow;
    }
    return NULL;
}
void delete_cycle(struct node *head)
{
    struct node *meet = detect(head);
    struct node *q = head, *prev ;
    while (q != meet)
    {
        q = q->next;
        meet = meet->next;
    }
    for(prev=meet;prev->next!=q;prev=prev->next);
    prev->next=NULL;
}
void print(struct node *start)
{
    while(start)
    {
        printf("%d ",start->info);
        start =start->next;
    }
}
int main()
{
    struct node *start = NULL, *p, *end;
    printf("\nEnter the number of element in the linked list: ");
    int n;
    scanf("%d", &n);
    printf("\nEnter the data: ");
    for (int i = 0; i < n; i++)
    {
        int e;
        scanf("%d", &e);
        start = Insert(start, e);
    }
    for (end = start; end->next != NULL; end = end->next);
    end->next = start->next->next; // This line is adds a loop in the linked list;If we invoke our print(start) function ,it go endless.
    p = detect(start);
    if (p == NULL){
        printf("\nLinked list dose not have any loop.");
        return 0;
    }
    delete_cycle(start);
    printf("\nLinked list after removal of loop: ");
    print(start);
    return 0;
}