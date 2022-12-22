//Given two elements, write a program to swap nodes containing two elements without swapping data in a linked list.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node* Insert(struct node * start,int data)
{
    struct node * temp;
    temp =(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->next=NULL;
    temp->next=start;
    start=temp;
    return start;
}
void print(struct node *start)
{
    while(start)
    {
        printf("%d ",start->info);
        start=start->next;
    }
}
int main()
{
    int x,y;
    printf("\nEnter the data in the lisked list: ");
    scanf("%d",&x);
    scanf("%d",&y);
    struct node *start=NULL;
    start=Insert(start,x);
    start=Insert(start,y);
    printf("\nLinked list before swapping of the node :");
    print(start);
    struct node*q=start->next;
    q->next=start;
    start->next=NULL;
    start=q;
    printf("\nLinked list after swapping of the node :");
    print(start);
}