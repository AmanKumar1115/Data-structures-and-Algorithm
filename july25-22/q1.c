//Q1: 1.Write a program to remove repeated elements in a given array.
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
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                for(int k=j;k<n-1;k++)
                {
                    a[k]=a[k+1];
                }
                n--;
                j--;
            }
        }
    }
    printf("\nArray after removal of duplicates::\n");
    for(int m=0;m<n;m++)
    {
        printf("%d ",a[m]);
    }
   
}