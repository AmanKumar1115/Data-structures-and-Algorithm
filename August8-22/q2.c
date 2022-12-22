/*2.WAP to create one array dynamically (user will tell the size of the array at run time)
and do the following operations. (use functions and switch case)
i. Input the element to the array
ii. Insert the element at a specified position (User will give the element and position)
iii. Insert at beginning (User will give the element)
iv. Insert at end (User will give the element use realloc() to increase the size)*/
#include <stdio.h>
#include <stdlib.h>
void IntputElement(int *a, int n)
{
    if (a == NULL)
    {
        printf("\nError!Memmory not allocated!\n");
        exit(0);
    }
    printf("\nEnter Array element one by one:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    printf("\nThe array elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
}
int InputAtNthPosition(int *a, int n, int e, int p)
{
    a = realloc(a, n + 1);
    int i;
    for (i = n; i > n - p; i--)
    {
        *(a + i) = *(a + i - 1);
    }
    *(a + i) = e;
    printf("\nThe array elements are:\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", *(a + i));
    }
    return n + 1;
}
int InsertAtbeginning(int *a, int b, int n)
{
    a = realloc(a, n + 1);
    int i;
    for (i = n; i >= 1; i--)
    {
        *(a + i) = *(a + i - 1);
    }
    *a = b;
    printf("\nThe array elements are:\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", *(a + i));
    }
    return n + 1;
}
int InsertAtend(int s, int *a, int n)
{
    a = realloc(a, n + 1);
    *(a + n) = s;
    printf("\nThe array elements are:\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", *(a + i));
    }
    return n + 1;
}
int main()
{
    int n, *a, r;
    printf("\n1. Input the element to the array .\n");
    printf("2. Insert the element at a specified position (User will give the element and position).\n");
    printf("3. Insert at beginning (User will give the element).\n");
    printf("4. Insert at end (User will give the element use realloc() to increase the size).\n");
    do
    {
        printf("\nEnter your choice according to menu given above:\n");
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the number element in array:");
            scanf("%d", &n);
            a = (int *)malloc(n * sizeof(int));
            IntputElement(a, n);
            break;
        case 2:
            printf("\nEnter the  position and element:");
            int p, e;
            scanf("%d", &p);
            scanf("%d", &e);
            n = InputAtNthPosition(a, n, e, p);
            break;
        case 3:
            int b;
            printf("\nEnter the element:");
            scanf("%d", &b);
            n = InsertAtbeginning(a, b, n);
            break;
        case 4:
            printf("\nEnter the element:");
            int s;
            scanf("%d", &s);
            n = InsertAtend(s, a, n);
            break;
        default:
            printf("INVALID CHOICE!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            break;
        }

        printf("\nEnter any number to get menu or 0 to close : ");
        scanf("%d", &r);
    } while (r);
}