//program to multiply two matrix
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
void findmul(int mat1[][size],int mat2[][size],int res[][size],int r1,int c2,int r2)
{
    int i,j,k;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            res[i][j]=0;
            for(k=0;k<r2;k++)
            {
                res[i][j]=res[i][j]+mat1[i][k]*mat2[k][j];
            }
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
    if(col1!=row2)
        printf("matrix multiplication is not possible\n");
    else
    {
        findmul(mat1,mat2,res,row1,col2,row2);
        printf("multiplication of two matrix is :\n");
        display(res,row1,col2);
    }
    return 0;
}