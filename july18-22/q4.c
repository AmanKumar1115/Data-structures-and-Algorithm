/*
WAP program to do the following operations on matrix.
a.Find the number of zero’s
b.Find the sum of all elements above the main diagonal  
c.Display all the diagonal elements.
d.Display the matrix in a row major order
e.Display the matrix in a column major order.
*/
#include <stdio.h>
int main()
{
    int col,row;
    printf("\nEnter the number of rows and columns respectively:\n");
    scanf("%d",&row);
    scanf("%d",&col);
    int a[row][col],c=0,s=0,i,j,k;
    printf("\nEnter the values of matrix in row major order:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
            c++;
        }   
    }
    printf("\nEntered matrix :\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<row;i++)
    {
        for(k=0;k<i;k++);
        for(j=k+1;j<col;j++)
        s=s+a[i][j];
    }
    printf("\na.)Number of zero's:%d",c);
    printf("\n\nb.)sum of element above the main diagonal:%d",s);
    printf("\n\nc.)Diagonal element of matrix: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(i==j)
            printf("%d ",a[i][j]);
        }
    }
    printf("\n\nd.)Element of martrix in row major order:\n");
        for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",a[i][j]);
        }
    }
    printf("\n\n3.)Element of martrix in coloumn major order:");
        for(i=0;i<col;i++)
    {
        for(j=0;j<row;j++)
        {
            printf("%d ",a[j][i]);
        }
    }
}