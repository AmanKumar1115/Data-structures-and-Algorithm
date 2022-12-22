/*Write a program to take input of two polynomials (array implementation) and use
menu driven to apply the following operations on it.
 a. Addition
b. Multiplication*/
/*#include <stdio.h>
#include <stdlib.h>
int *add(int *a, int *b, int m, int n)
{
    printf("\nFunction started:\n");
    int *c;
    int k;
    if (m > n)
    {
        k = m;
        c = (int *)calloc(1, m * sizeof(int));
        for (int i = 0; i <= n; i++)
        {
            c[i] = b[i];
        }
        printf("\nThe array elements after copying:\n");
        for (int i = 0; i <= n; i++)
        {
            printf("%d ", *(c + i));
        }
        for (int i = 0; i <= m; i++)
        {
            c[i] = c[i] + a[i];
        }
    }
    else
    {
        k = n;
        c = (int *)calloc(0, n * sizeof(int));
        for (int i = 0; i <= m; i++)
        {
            c[i] = a[i];
        }
        printf("\nThe array elements after copying:\n");
        for (int i = 0; i <= m; i++)
        {
            printf("%d ", *(c + i));
        }
        for (int i = 0; i <= n; i++)
        {
            c[i] = c[i] + b[i];
        }
    }
    return c;
}
/*void mul(int *a, int *b, int m, int n)
{
    int *c;
    c = (int *)calloc(1, (m + n + 1) * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; i++)
        {
            c[i + j] = c[i + j] + a[i] * b[j];
        }
    }
    printf("\nThe polynomial after multiplication:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%dx^%d + ", *(c + i), i);
    }
}
int *IntputElement(int *a, int n)
{
    if (a == NULL)
    {
        printf("\nError!Memmory not allocated!\n");
        exit(0);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    return a;
}
int main()
{
    int n, m;
    printf("\nEnter the maximum pow in polynomial 1 :");
    scanf("%d", &m);
    printf("\nEnter the maximum pow in polynomial 2 :");
    scanf("%d", &n);
    int *a;
    a = (int *)malloc(m * sizeof(int));
    printf("\nEnter the co-efficient of the polynomial_1: ");
    a = IntputElement(a, m);
    printf("\nThe array elements are:\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", *(a + i));
    }
    int *b;
    b = (int *)malloc(n * sizeof(int));
    printf("\nEnter the co-efficient of the polynomial_2: ");
    b = IntputElement(a, n);
    printf("\nThe array elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(b + i));
    }
    int *c;
    c = add(a, b, m, n);
    printf("\nThe polynomial after addition:\n");
    int k;
    if (m > n)
        k = m;
    else
        k = n;
    for (int i = 0; i < k; i++)
    {
        printf("%d ", *(c + i));
    }
    // mul(a, b, m, n);
    return 0;
}*/
/*4. Write a program to take input of two polynomials (array implementation) and use
menu driven to apply the following operations on it.
a. Addition
b. Subtraction
c. Multiplication*/

#include <stdio.h>
#include <stdlib.h>

int *add(int *p, int m, int *q, int n)
{
    int *c = NULL;
    int i;
    if (m > n)
    {
        c = (int *)calloc(m + 1, sizeof(int));
        for (i = 0; i <= n; i++)
            *(c + i) = *(q + i);
        for (i = 0; i <= m ; i++)
            *(c + i) += *(p + i);
    }
    else
    {
        c = (int *)calloc(n + 1, sizeof(int));
        for (i = 0; i <= m; i++)
            *(c + i) = *(p + i);
        for (i = 0; i <= n ; i++)
            *(c + i) += *(q + i);
    }
    return c;
}
int *subtract(int *p, int m, int *q, int n)
{
    int *c = NULL;
    int i;
    if (m > n)
    {
        c = (int *)calloc(m + 1, sizeof(int));
        for (i = 0; i <= m ; i++)
            *(c + i) = *(p + i);
        for (i = 0; i <= n ; i++)
            *(c + i) -= *(q + i);
    }
    else
    {
        c = (int *)calloc(n + 1, sizeof(int));
        for (i = 0; i <= m ; i++)
            *(c + i) = *(p + i);
        for (i = 0; i <= n ; i++)
            *(c + i) -= *(q + i);
    }
    return c;
}
int *mul(int *p, int m, int *q, int n)
{
    int *c = NULL;
    c = (int *)calloc(m + n + 1, sizeof(int));
    int i, j;
    for (i = 0; i <= m ; i++)
        for (j = 0; j <= n; j++)
            *(c + i + j) += *(p + i) * *(q + j);
    return c;
}
void print(int *p, int m)
{
    if (p == NULL)
    {
        printf("No elements!\n");
        return;
    }
    for (int i = 0; i <= m ; i++)
    {
        if (*(p + i) != 0)
        {
            printf("%dx^%d ", *(p + i), i);
            if (i != m)
                printf("+ ");
        }
    }
    printf("\n");
}

void main()
{
    int m, n;
    printf("Input the highest order of first polynomial : ");
    scanf("%d", &m);
    int *p = (int *)calloc(m + 1, sizeof(int));
    int i;
    printf("Enter the terms of first polynomial :\n");
    for (i = 0; i <= m; i++)
    {
        printf("Enter coefficient of x^%d : ", i);
        scanf("%d", p + i);
    }
    printf("Input the highest order of second polynomial : ");
    scanf("%d", &n);
    int *q = (int *)calloc(n + 1, sizeof(int));
    printf("Enter the terms of second polynomial :\n");
    for (i = 0; i <= n; i++)
    {
        printf("Enter the coefficient of x^%d : ", i);
        scanf("%d", q + i);
    }
    printf("First polynomial entered is :\n");
    print(p, m);
    printf("\nSecond polynomial entered is :\n");
    print(q, n);
    printf("\n");
    int ch=0, *c = NULL;
    int k;
    if (m > n)
        k = m;
    else
        k = n;
    while (ch != 4)
    {
        printf("\n1. Addition\n");
        printf("\n2. Subtraction\n");
        printf("\n3. Multiplication\n");
        printf("\n4. Exit\n");
        printf("Choose an option :");
        scanf("%d", &ch);
        while (ch < 1 || ch > 4)
        {
            printf("Choose valid option : ");
            scanf("%d", &ch);
        }
        switch (ch)
        {
        case 1:
            c = add(p, m, q, n);
            printf("\nAddition of two polynomials is :\n");
            print(c, k);
            break;
        case 2:
            c = subtract(p, m, q, n);
            printf("\nSubtraction of two polynomials is :\n");
            print(c, k);
            break;
        case 3:
            c = mul(p, m, q, n);
            printf("\nMultiplication of two polynomials is :\n");
            print(c, m + n);
            break;
        }
    }
}
