//2.	Write a program to find the maximum number of consecutive elements present in ascending order.
#include <stdio.h>
//#include <math.h>
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
    int c=1,m=0;
    for(int i=0;i<n;i++)
    { 
        if(a[i+1]==(a[i]+1))
        {
            c++;
        }
        else
        {
            if(c>m)
            m=c;
            c=1;
        }
    }
    printf("\nmaximum number of consecutive elements present in ascending order: %d",m);
}
