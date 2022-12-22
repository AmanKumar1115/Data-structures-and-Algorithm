/*
5.WAP to take all odd numbers to the first part and all even numbers to the second part of the array (Use function call). 
Example:
 Let a[]={ 11, 23, 44, 21, 32, 89, 4, 7, 2, 9} 
Then output: {11, 23, 21, 89, 7, 9, 44, 32, 4, 2}
*/
#include <stdio.h>
void arrange(int l,int x[])
{
    int j=0;
    for(int i=0;i<l;i++)
    {
        if(x[i]%2==0)
        {
            continue;
        }
        int t=x[i];
        x[i]=x[j];
        x[j]=t;
        j++;
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
    arrange(n,a);
    printf("\nArray in required order:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

