/*WAP to implement sparse matrix using linked list as follows:
//1 Transpose
//2 Addition
//3 Multilplication*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int row, col, val;
    struct node *next;
};
struct head
{
    int tr, tc, tele;
    struct node *next;
};
struct head *insert_end(struct head *start, int r, int c, int v)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->row = r;
    temp->col = c;
    temp->val = v;
    temp->next = NULL;
    if (start->next == NULL)
    {
        start->next = temp;
    }
    else
    {
        struct node *q;
        for (q = start->next; q->next != NULL; q = q->next)
            ;
        q->next = temp;
    }
    return start;
}
void Tranpose(struct head *h)
{
    int t;
    struct node *q;
    t = h->tr;
    h->tr = h->tc;
    h->tc = t;
    for (q = h->next; q != NULL; q = q->next)
    {
        t = q->row;
        q->row = q->col;
        q->col = t;
    }
}
struct head *sparse_add_ll(struct head *h1, struct head *h2)
{
    struct node *q, *p1, *p2, *prev;
    if (h1->tr != h2->tr || h1->tc != h2->tc)
        return NULL;
    if (h1->next == NULL)
    {
        h1->next = h2->next;
    }
    else
    {
        for (q = h1->next; q->next != NULL; q = q->next)
            ;
        q->next = h2->next;
    }
    for (p1 = h1->next; p1->next != NULL; p1 = p1->next)
    {
        prev = p1;
        for (p2 = p1->next; p2 != NULL;)
        {
            if (p1->row == p2->row && p1->col == p2->col)
            {
                p1->val = p1->val + p2->val;
                prev->next = p2->next;
                free(p2);
                p2 = prev->next;
            }
            else
            {
                prev = p2;
                p2 = p2->next;
            }
        }
    }
    return h1;
}
struct head *sparse_mul_ll(struct head *h1, struct head *h2)
{
    struct node *p1, *p2, *prev;
    if (h1->tc != h2->tr)
        return NULL;
    struct head *h3 = NULL;
    for (p1 = h1->next; p1 != NULL; p1 = p1->next)
    {
        for (p2 = h2->next; p2 != NULL; p2 = p2->next)
        {
            if (p1->col == p2->col)
            {
                int val = p1->val * p2->val;
                h3 = insert_end(h3, p1->row, p2->col, val);
            }
        }
    }
    for (p1 = h3->next; p1->next != NULL; p1 = p1->next)
    {
        prev = p1;
        for (p2 = p1->next; p2 != NULL;)
        {
            if (p1->row == p2->row && p1->col == p2->col)
            {
                p1->val += p2->val;
                prev->next = p2->next;
                free(p2);
                p2 = prev->next;
            }
            else
            {
                prev = p2;
                p2 = p2->next;
            }
        }
    }
    return h3;
}
void print(struct head **h)
{
    printf("%d\t%d\t%d", (*h)->tr, (*h)->tc, (*h)->tele);
    struct node *p = (*h)->next;
    printf("\n");
    while (p)
    {
        printf("%d\t%d\t%d", p->row, p->col, p->val);
        printf("\n");
        p = p->next;
    }
}
int main()
{
    struct head *h1, *h2;
    int i = 0;
    int tr, tc, tele;


    h1 = (struct head *)malloc(sizeof(struct head));
    printf("\nEnter the value of the tr ,tc ,tele for matrix 1 : ");
    scanf("%d%d%d", &tr, &tc, &tele);
    h1->tr = tr;
    h1->tc = tc;
    h1->tele = tele;
    printf("\nEnter the row , col and val  for matrix 1:");
    for (i = 0; i < h1->tele; i++)
    {
        int row, col, val;
        scanf("%d%d%d", &row, &col, &val);
        h1 = insert_end(h1, row, col, val);
    }


    h2 = (struct head *)malloc(sizeof(struct head));
    printf("\nEnter the value of the tr ,tc ,tele for matrix 2 : ");
    scanf("%d%d%d", &tr, &tc, &tele);
    h2->tr = tr;
    h2->tc = tc;
    h2->tele = tele;
    printf("\nEnter the row , col and val  for matrix 2:");
    for (i = 0; i < h2->tele; i++)
    {
        int row, col, val;
        scanf("%d%d%d", &row, &col, &val);
        h2 = insert_end(h2, row, col, val);
    }
    printf("\nSparse matric 1::\n");
    printf("\n");
    print(&h1);
    printf("\nTranpsoe of matrix 1::");
    printf("\n");
    Tranpose(h1);
    print(&h1);
    printf("\nSparse matric 2::\n");
    printf("\n");
    print(&h2);
    printf("\n");
    printf("\nSparse matrix after addition::");
    printf("\n");
    h1 = sparse_add_ll(h1, h2);
    print(&h1);
    printf("\n");
    printf("\nMatrix multiplication ::");
    struct head *h3 = sparse_mul_ll(h1, h2);
    print(&h3);
    return 0;
}