//.WAP to find kth smallest & kth largest element in the array.
#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the array element one by one:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i< n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("Entered elements in ascending order are:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    int k;
    printf("\nEnter the value of K:\n");
    scanf("\n %d",&k);
    printf("\nKth largest no.: %d",a[n-k]);
    printf("\nKth smallest no.: %d",a[k-1]);
    return 0;
}