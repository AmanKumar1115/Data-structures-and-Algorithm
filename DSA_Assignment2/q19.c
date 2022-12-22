//19. How to find the node at which the intersection of two singly linked lists begins.
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
void print(struct node *start)
{
    while (start != NULL)
    {
        printf("%d ", start->data);
        start = start->next;
    }
}
int count(struct node* start)
{
    int  c=0;
    while(start)
    {
        c++;
        start=start->next;
    } 
    return c;
}
void intersect(struct node* start1,struct node* start2,int pos)
{
    struct node* temp1 = start1;
    pos--;
    while(pos--)
    {
        temp1=temp1->next;
    }
    struct node* temp2 =start2;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
}
int intersection_point(struct node* start1,struct node* start2)
{
    int l1=count(start1);
    int l2=count(start2);
    int d=0;
    struct node* ptr1;
    struct node* ptr2;
    if(l1>l2)
    {
        d=l1-l2;
        ptr1=start1;
        ptr2=start2;
    }
    else
    {
        d=l2-l1;
        ptr1=start2;
        ptr2=start1;
    }
    while(d)
    {
        ptr1=ptr1->next;
        if(ptr1==NULL)
        {
            return -1;
        }
        d--;
    }
    while(ptr1 && ptr2)
    {
        if(ptr1==ptr2)
        {
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -999;
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
    printf("\nEnter the data of the linked list1: ");
    for (int i = 0; i < N; i++)
    {
        int e;
        scanf("%d", &e);
        start1 = Insert(start1, e);
    }
    printf("\nEnter the data of the linked list2: ");
    for (int i = 0; i < M; i++)
    {
        int e;
        scanf("%d", &e);
        start2 = Insert(start2, e);
    }
    intersect(start1,start2,4);
    printf("\n First list is \n");
    print(start1);

    printf("\n Second list is \n");
    print(start2);
    int d = intersection_point(start1, start2);
    printf("\nData at the intersection point : %d ",d);

    return 0;
}
