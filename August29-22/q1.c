// Write a menu driven program in C language .To create the linked list where User will give the option for insert
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};

struct node *InsertATBeg(struct node *start, int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = n;
    temp->next = NULL;
    temp->next = start;
    start = temp;
    return start;
}
struct node *InsertATEnd(struct node *start, int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = n;
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
struct node *InsertATPosition(struct node *start, int n, int pos)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = n;
    temp->next = NULL;
    if (pos == 1)
    {
        temp->next = start;
        start = temp;
    }
    else if (start != NULL && pos != 1)
    {
        int i;
        struct node *q = start;
        for (i = 1; i < pos - 1; i++)
            q = q->next;
        if (q == NULL)
            return start;
        temp->next = q->next;
        q->next = temp;
    }
    return start;
}
struct node *InsertAfterelement(struct node *start, int a, int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = a;
    temp->next = NULL;
    if (start == NULL)
        return start;
    else
    {
        struct node *q;
        for (q = start; q->info != n; q = q->next)
        {
            if (q == NULL)
            {
                printf("\nData cannot be inserted\n");
                return start;
            }
        }
        temp->next = q->next;
        q->next = temp;
    }
    return start;
}
void printlist(struct node *start)
{
    struct node *q;
    printf("\nLisked Lists:\n");
    for (q = start; q != NULL; q = q->next)
        printf("%d ", q->info);
    printf("\n");
}
int main()
{
    struct node *start = NULL;
    int r;
    printf("\nEnter 5 element already present in the linked list:\n");
    for (int i = 0; i < 5; i++)
    {
        int e;
        scanf("%d", &e);
        start = InsertATBeg(start, e);
    }
    do
    {
        printf("\nEnter the choice according to menu fiven below:\n");
        printf("1. Insert At the beginning.\n");
        
        printf("2. Insert At the end.\n");
        printf("3. Insert At the Nth postion.\n");
        printf("4. Insert after the given element:\n");
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the number to be inserted :\n");
            int m;
            scanf("%d", &m);
            start = InsertATBeg(start, m);
            printlist(start);
            break;
        case 2:
            printf("\nEnter the number to be inserted :\n");
            int s;
            scanf("%d", &s);
            start = InsertATEnd(start, s);
            printlist(start);
            break;

        case 3:
            printf("\nEnter the number to be inserted :\n");
            int g;
            scanf("%d", &g);
            printf("\nEnter the position:\n");
            int pos;
            scanf("%d", &pos);
            start = InsertATPosition(start, g, pos);
            printlist(start);
            break;
        case 4:
            int a, y;
            printf("\nEnter the element to be entered and after which element data will inserted:\n");
            scanf("%d%d", &a, &y);
            start = InsertAfterelement(start, a, y);
            printlist(start);
            break;
        default:
            printf("\nINVALID INPUT!!!!!!!!!\n");
            break;
        }

        printf("\nEnter 0 if you want to exist or 1 to get menu again:");
        scanf("%d", &r);
    } while (r);
}