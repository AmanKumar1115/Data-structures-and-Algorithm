//5.WAP that will sum the surrounding elements of a given index in the matrix.
// | 1| 2| 3| 4| 5| 
// | 6| 7| 8| 9|10|               
// |11|12|13|14|15|
// |16|17|18|19|20|
// |21|22|23|24|25|
//13’s surrounding elements are 7, 8, 9, 14, 19, 18, 17, 12
//11’s surrounding elements are 6, 7, 12, 17, 16
//25’s surrounding elements are 24, 19, 20
#include <stdio.h>
int main()
{
    int row,col,x,y;
    printf("\nEnter number of row and column:\n");
    scanf("%d",&row);
    scanf("%d",&col);
    int A[row][col];
    printf("\nEnter elements of the matrix:\n");
    for(x=0;x<row;x++)
    {
        for(y=0;y<col;y++)
        {
            scanf("%d",&A[x][y]);
        }
    }
    printf("\nEntered Matrix:\n");
    for(x=0;x<row;x++)
    {
        for(y=0;y<col;y++)
        {
            printf("%3d",A[x][y]);
        }
        printf("\n");
    }
    int sum=0,i,j;
    printf("Enter row number of element:\n");
    scanf("%d",&i);
    printf("Enter column number of element:\n");
    scanf("%d",&j);
    if(i>=row||j>=col)
    {
        printf("\nINVALID INDEX!");
        return 0;
    }
    if(i-1 >=0 && j-1>=0)
    {
        sum += A[i-1][j-1];
    }
    if(i-1>=0)
    {
        sum += A[i-1][j];
    }
    if(i-1 >= 0 && j+1<col)
    {
        sum += A[i-1][j+1];
    }
    if(j+1<col)
    {
        sum += A[i][j+1];
    }
    if(i+1 < row && j+1 < col)
    {
       sum += A[i+1][j+1];
    }
    if(i+1 < row)
    {
        sum += A[i+1][j];
    }
    if(i+1<row && j-1>=0)
    {
        sum += A[i-1][j-1];
    }
    if(j-1>=0)
    {
        sum += A[i][j-1];
    }
    printf("\nElement at A[%d][%d]:%d",i,j,A[i][j]);
    printf("\nSum: %d",sum);
}