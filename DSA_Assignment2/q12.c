//Write a program to arrange all odd numbers first then all even numbers in a linked list.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node* next;
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
void print(struct node* start)
{
    while(start)
    {
        printf("%d ",start->info);
        start=start->next;
    }
}
struct node* odd_even(struct node* start)
{
    struct node hodd,*odd=&hodd;
    hodd.next=start;
    struct node heven,*even=&heven;
    while(start)
    {
        if(start->info%2!=0)
        {
            odd->next=start;
            odd=odd->next;
        }
        else
        {
            even->next=start;
            even=even->next;
        }
        start=start->next;
    }
    odd->next =heven.next;   
    even->next=NULL;
    heven.next=NULL;
    return hodd.next;
}
int main()
{
    printf("\nEnter the number element in the linked list: ");
    int N;
    scanf("%d",&N);
    struct node* start=NULL;
    printf("\nEnter data element: ");
    for(int i=0;i<N;i++)
    {
        int e;
        scanf("%d",&e);start=Insert(start,e);
    }
    printf("\nEntered linked list: ");
    print(start);
    start=odd_even(start);
    printf("\nLinked list after arrangement: ");
    print(start);
    return 0;
}


