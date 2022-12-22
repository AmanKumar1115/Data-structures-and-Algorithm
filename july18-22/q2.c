//2.WAP to reverse the array. Don't use another array
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
  printf("\nThe array element as entered:\n");
  for(int i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
  int m=n-1;
  for(int i=0;i<n/2;i++)
  {
    int t=a[m];
    a[m]=a[i];
    a[i]=t;
    m--;
  }
  printf("\nThe array element in reversed order:\n");
  for(int i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }
}