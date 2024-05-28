//program to add two matrix
#include<stdio.h>
#define size 100
void scan(int mat[][size],int* row,int* col)
{
    int i,j;
    printf("enter the number of rows and columns of the matrix : ");
    scanf("%d%d",row,col);
    printf("enter the matrix elements : ");
    for(i=0;i<*row;i++)
    {
        for(j=0;j<*col;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
}
void display(int mat[][size],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void findsum(int mat1[][size],int mat2[][size],int res[][size],int r1,int c1)
{
    int i,j;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            res[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
}
int main()
{
    int mat1[size][size],mat2[size][size],res[size][size],row1,row2,col1,col2;
    scan(mat1,&row1,&col1);
    printf("enetered matrix is : \n");
    display(mat1,row1,col1);
    scan(mat2,&row2,&col2);
    printf("enetered matrix is : \n");
    display(mat2,row2,col2);
    if(row1!=row2 || col1!=col2)
        printf("matrix multiplication is not possible\n");
    else
    {
        findsum(mat1,mat2,res,row1,col2);
        printf("addition of two matrix is :\n");
        display(res,row1,col2);
    }
    return 0;
}