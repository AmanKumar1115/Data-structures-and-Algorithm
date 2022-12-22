// WAP to implement polynomial operation using linked as follow:
// 1. Addition
// 2. Multiplication
#include <stdio.h>
#include <stdlib.h>

struct polynomial
{
    int coff;
    int pow;
    struct polynomial *next;
};
struct polynomial *Join(struct polynomial *start1,struct polynomial *start2)
{
    if(start1==NULL)
        return start2;
    else
    {
        struct polynomial *q;
        for(q=start1;q->next!=NULL;q=q->next );
        q->next=start2;   
    }
    return start1;
}
struct polynomial *insert_sort(struct polynomial *start, int coeff, int pow)
{
    struct polynomial *temp, *prev, *q;
    temp = (struct polynomial *)malloc(sizeof(struct polynomial));
    temp->coff = coeff;
    temp->pow = pow;
    temp->next = NULL;
    if (start == NULL ||  start->pow > pow)
    {
        temp->next=start;
        start = temp;
    }
    else
    {
        q=start;
        while (q ->next != NULL && q->pow < pow)
        {
            prev = q;
            q = q->next;
        } 
        temp->next = q;
        prev->next = temp;
    }
    return start;
}
struct polynomial *insert_end(struct polynomial *start, int c, int p)
{
    struct polynomial *temp, *q;
    temp = (struct polynomial *)malloc(sizeof(struct polynomial));
    temp->coff = c;
    temp->pow = p;
    temp->next = NULL;
    if (start == NULL)
        start = temp;
    else
    {
        for (q = start; q->next != NULL; q = q->next);
        q->next = temp;
    }
    return start;
}
void print(struct polynomial *poly)
{
    while (poly)
    {
        printf("%dx^%d   ", poly->coff, poly->pow);
        poly = poly->next;
    }
}
struct polynomial* multiply(struct polynomial *poly1,struct polynomial *poly2)
{
    int coeff,pow;
    struct polynomial* p1 = poly1, *p2 = poly2,*poly3=NULL,*prev;
    for (p1 = poly1; p1 != NULL; p1 = p1->next)
    {
        for (p2 = poly2; p2 != NULL; p2 = p2->next)
        {
            coeff = p1->coff * p2->coff;
            pow = p1->pow + p2->pow;
            poly3 = insert_end(poly3, coeff, pow);
        }
    }
    for (p1 = poly3; p1->next != NULL; p1 = p1->next)
    {
        prev = p1;
        for (p2 = p1->next; p2 != NULL;)
        {
            if (p1->pow == p2->pow)
            {
                p1->coff = p1->coff + p2->coff;
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
    return poly3;
}
int main()
{
    int pow, coeff;
    struct polynomial *poly1 = NULL, *poly2 = NULL, *poly3 = NULL, *p1, *p2, *prev;
    int m, n;
    printf("\nEnter the number of element in poly1 and ploy2 : ");
    scanf("%d", &m);
    scanf("%d", &n);
    for (int i = 0; i < m; i++)
    {
        printf("\nEnter coeff and pow  polynomial 1: ");
        scanf("%d%d", &coeff, &pow);
        poly1= insert_sort(poly1, coeff, pow);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter coeff and pow for polynomial 2: ");
        scanf("%d%d", &coeff, &pow);
        poly2 = insert_sort(poly2, coeff, pow);
    }
    printf("\nPolynomial 1::");
    print(poly1);
    printf("\nPolynomial 2::");
    print(poly2);
    printf("\nPolynomial 3::");
    poly3 = multiply(poly1,poly2);
    print(poly3);
    printf("\n\nPolynomial after addition::\n");
    struct polynomial*start3 = Join(poly1,poly2);
    for (p1 = start3; p1->next != NULL; p1 = p1->next)
    {
        prev = p1;
        for (p2 = p1->next; p2 != NULL;)
        {
            if (p1->pow == p2->pow)
            {
                p1->coff = p1->coff + p2->coff;
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
    print(start3);
    return 0;
}