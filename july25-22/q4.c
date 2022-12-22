//4.WAP to display the following triangular matrix 
//of two dimensional array
#include <stdio.h>
int main()
{
    int row,col;
    printf("\nEnter number of row and column:\n");
    scanf("%d",&row);
    scanf("%d",&col);
    int a[row][col];
    int x=1;
    for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
    a[i][j]=x++;
    printf("\nEnterd Matrix:\n");
    int i,j,k;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    printf("\nFor first triangular matrix:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<i;j++)
        {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }   
    printf("\nFor second triangular matrix:\n"); 
    for(i=0;i<row;i++)
    {
        for(j=0;j<col-i;j++)
        {
            printf("   ");
        }
        for(k=j;k<col;k++)
        printf("%3d",a[i][k]);
        printf("\n");
    }
    printf("\nFor third triangular matrix:\n");
    for(i=0;i<row;i++)
    {
        for(k=0;k<i;k++)
        printf("   ");
        for(j=k+1;j<col;j++)
        printf("%3d",a[i][j]);
        printf("\n");
    }
    printf("\nFor forth triangular matrix:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col-i-1;j++)
        printf("%3d",a[i][j]);
        printf("\n");
    }
}