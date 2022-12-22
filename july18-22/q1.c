//WAP to find the smallest & largest number in the array (in a single loop)
#include <stdio.h>
#include <limits.h>
int main()
{
    int n;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    int a[n];
    int max=INT_MIN,min=INT_MAX;
    printf("\nEnter array elements one by one:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>max)
        max=a[i];
        if(a[i]<min)
        min=a[i];
    }
    printf("\nLargest number:%d",max);
    printf("\nSmallest number:%d \n",min);

}