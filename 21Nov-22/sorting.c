/*
Wap menu driven program to do the folowing sorting
bubble sort
selection
insertion
merger
*/
#include <stdio.h>

void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
}
void selection_sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[smallest] > a[j])
                smallest = j;
        }
        if (smallest != 1)
        {
            int temp = a[i];
            a[i] = a[smallest];
            a[smallest] = temp;
        }
    }
}
// void insertion_sort(int a[], int n)
// {
//     for (int j = 1; j < n; j++)
//     {
//         int item = a[j];
//         int i = j - 1;
//         while (item < a[i] && i >= 0)
//         {
//             a[i+1] = a[i];
//             i--;
//         }
//         a[i++] = item;
//     }
// }
void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void merge(int a[], int low, int m, int high)
{
    int l = low, h = m + 1, k = 0;
    int b[high];
    while (l <= m && h <= high)
    {
        if (a[l] < a[h])
        {
            b[k] = a[l];
            k++;
            l++;
        }
        else
        {
            b[k] = a[h];
            k++;
            h++;
        }
    }
    if (l != m + 1)
        for (int i = l; i < m; i++)
            b[k++] = a[i++];
    else
        for (int i = h; i <= high; i++)
            b[k++] = a[i++];
}
void merge_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int m = low + (high - low) / 2;
        merge_sort(a, low, m);
        merge_sort(a, m + 1, high);
        merge(a, low, m, high);
    }
}
void print(int a[], int n)
{
    printf("\nSorted array :");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    int a[] = {9, 6, 3, 1, 5, 4};
    int n = sizeof(a) / sizeof(a[0]);
    printf("\n1.Bubble sort: ");
    printf("\n2.Selection sort: ");
    printf("\n3.Insertion sort: ");
    printf("\n4.Merge sort: ");
    printf("\nEnter the choice: ");
    int ch;
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        bubble_sort(a, n);
        print(a, n);
        break;
    case 2:
        selection_sort(a, n);
        print(a, n);
        break;
    case 3:
        insertion_sort(a, n);
        print(a, n);
        break;
    case 4:
        merge_sort(a, 0, n - 1);
        print(a, n);
        break;
    default:
        printf("\nINVALID CHOICE!!!!!!!");
    }
}