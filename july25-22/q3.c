//3.In a one dimensional array, user gives a certain range of index with shifting value. You need to right shift and rotate those range of values based on the given shifting value. 
//Given array: 2,9,6,3,5,8,11,3,6,7,13,5 
//Given range: 4th index to 9th index(consider the starting index is 0) and shifting value is 2 
//Output:      2,9,6,3,6,7,5,8,11,3,13,5

#include <stdio.h>
int main()
{
    int n;
    printf("\nEnter the number of element in the array:\n");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter element one by one :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int s,e;
    printf("\nGiven range begin and end :\n");
    scanf("%d",&s);
    scanf("%d",&e);
    printf("\nEnter the shifting value:\n");
    int v;
    scanf("%d",&v);
    for(int j=0;j<v;j++)
    {
        int t=a[e];
        for(int k=e;k>=s;k--)
        {
            a[k]=a[k-1];
        }
        a[s]=t;
    }
    printf("\nArray after shifting value:\n");
    for(int k=0;k<n;k++)
    printf("%d ",a[k]);
}