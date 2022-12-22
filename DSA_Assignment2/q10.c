//WAP to merge two sorted linked lists such that the original two linked lists will 
//change to a single merged list. (Merge in-place).
#include<stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node* next;
};
struct node* Insert(struct node* start, int data)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->info=data;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        struct node* q;
        for(q=start;q->next!=NULL;q=q->next);
        q->next=temp;
    }
    return start;
}
/*struct node* merge_in_place(struct node* start1,struct node* start2)
{
    if(start1==NULL)
        return start2;
    if(start2==NULL)
        return start1;
    struct node dummy;
    struct node* ptr=&dummy;
    while(start1 && start2)
    {
        if(start1->info < start2->info)
        {
            ptr->next=start1;
            start1=start1->next;
        }
        else
        {
            ptr->next=start2;
            start2=start2->next;
        }
        ptr=ptr->next;
    }
    if(start1)
        ptr->next=start1;
    else
        ptr->next=start2;
    return dummy.next;
}*/
void print(struct node* start)
{
    while(start)
    {
        printf("%d ",start->info);
        start=start->next;
    }
}
struct node*  merge_inplace(struct node* start1,struct node* start2)
{
    if(start1==NULL)
        return start2;
    if(start2==NULL)
        return start1;
    struct node* merge;
    if(start1->info<start2->info)
    {
        merge=start1;
        merge->next = merge_inplace(start1->next,start2);
    }
    else
    {
        merge=start2;
        merge->next = merge_inplace(start1,start2->next);
    }
    return merge;
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
    start1 = merge_inplace(start1, start2);
    printf("\nTwo sorted linked lists such that the merged list ");
    print(start1);
    return 0;
}