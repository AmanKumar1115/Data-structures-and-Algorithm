/*
WAP to arrange first half of the array in ascending order and second half of the array in descending order. (Use function call).
Example:
 Let a[]={ 11, 23, 44, 21, 32, 89, 4, 7, 2, 9} 
1st half contains 5 elements as {11, 23, 44, 21, 32} and 2nd half contains 5 elements as {89, 4, 7, 2, 9}.
Output: a[]= {11, 21, 23, 32, 44, 89, 9, 7, 4,2}
*/
#include <stdio.h>
void half(int a[],int n)
{
    int i,j,t,l=n/2;
    for(i=1;i<l;i++)
    {
        for(j=1;j<l;j++)
        {
            if(a[j-1]>a[j])
            {
                t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
            }  
        }
    } 
    for(i=l+1;i<n;i++)
    {
        for(j=l+1;j<n;j++)
        { 
            if(a[j-1]<a[j])
            {
                t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
            }   
        }
    }
}
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
    half(a,n);
    printf("\n\n");
    printf("\nArray in required order:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}