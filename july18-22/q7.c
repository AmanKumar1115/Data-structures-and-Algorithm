//7.In a one dimensional array find out all the elements, which is the
//summation of its immediate previous contiguous elements
// and those previous elements including that element are 
//either in ascending or descending order.

//Ex: Given array: 2,9,3,6,9,8,17,3,6,4,13,5
//Output: output is 9, which is a summation of it’s previous elements 3 and 6
#include <stdio.h>
int main()
{
    int arr[12]={2,9,3,6,9,8,17,3,6,4,13,5};
    int sum=0;
    int n=12;
    for(int i=0;i<n-1;i++)
    {
        sum=arr[i];
        for(int j=i;j<n-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                if(sum==arr[j+1])
                {
                    printf("SUM:%d",arr[j+1]);
                    i=j+1;
                }
                else
                {
                    sum=sum+arr[j+1];
                }
            }
            else
            {
                i=j;
                break;
            }
        }
    }
    return 0;
}