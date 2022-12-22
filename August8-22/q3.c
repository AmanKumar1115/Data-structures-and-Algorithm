/*3.WAP to create one array dynamically and do the following operations. (use
functions and switch case)
i. Input the element to the array
ii. Delete the element at a specified position (User will give the position)
iii. Delete the specified element (User will give the element, consider the array may have similar elements)
[Note: let specified element is 5 & element 5 is present 3 times, then delete all the
       occurrence of 5 & reduce the size of array by 3.]
iv. Delete from the beginning*/
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
int DeleteAtNthPosition(int *a, int n, int p)
{
    int i;
    for (i = p - 1; i < n; i++)
    {
        *(a + i) = *(a + i + 1);
    }
    n--;
    printf("\nThe array elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
    return n;
}
int removeElement(int *a, int e, int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(a + i) == e)
            {
                int t = *(a + i);
                *(a + i) = a[j];
                *(a + j) = t;
            }
        }
        if (*(a + i) == e)
            c++;
    }
    printf("\nThe array elements are:\n");
    for (int i = 0; i < n - c - 1; i++)
    {
        printf("%d ", *(a + i));
    }
    return (n - c - 1);
}
int DelteAtBegining(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        *(a + i) = *(a + i + 1);
    }
    n--;
    printf("\nThe array elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
    return n;
}
int main()
{
    int n, *a, r;
    printf("\nEnter the number element in array:");
    scanf("%d", &n);
    printf("\n1. Input the element to the array .\n");
    printf("2. Delete the element at a specified position (User will give the position) \n");
    printf("3. Delete the specified element (User will give the element, consider the array may have similar elements)[Note: let specified element is 5 & element 5 is present 3 times, then delete all the occurrence of 5 & reduce the size of array by 3.] \n");
    printf("4. Delete from the beginning.\n");
    a = (int *)malloc(n * sizeof(int));
    do
    {
        printf("\nEnter your choice according to menu:\n");
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            IntputElement(a, n);
            break;
        case 2:
            printf("\nEnter the  position :");
            int p;
            scanf("%d", &p);
            n = DeleteAtNthPosition(a, n, p);
            break;
        case 3:
            int b;
            printf("\nEnter the element:");
            scanf("%d", &b);
            n = removeElement(a, b, n);
            break;
        case 4:
            n = DelteAtBegining(a, n);
            break;
        default:
            printf("INVALID CHOICE!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            break;
        }

        printf("\nEnter any number to get menu or 0 to close : ");
        scanf("%d", &r);
    } while (r);
}