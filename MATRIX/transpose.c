//program to find out the transpose of the matrix
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
void findtrp(int mat[][size],int trp[][size],int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        for(j=0;j<row;j++)
        {
            trp[i][j]=mat[j][i];
        }
    }
}
int main()
{
    int row,col,mat[size][size],trp[size][size];
    scan(mat,&row,&col);
    printf("entered matrix is :\n");
    display(mat,row,col);
    findtrp(mat,trp,row,col);
    printf("transpose of the matrix is : \n");
    display(trp,col,row);
}