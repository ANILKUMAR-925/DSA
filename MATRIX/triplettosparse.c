//program to find out the sparse matrix from triplet matrix
#include<stdio.h>
#define size 100
int scan(int trpm[][3])
{
    int i,j,nzero;
    printf("enter the number of non zero element in the sparse matrix : ");
    scanf("%d",&nzero);
    printf("enter the matrix elements : ");
    for(i=0;i<=nzero;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&trpm[i][j]);
        }
    }
    return nzero;
}
void displaytrpm(int mat[][3],int nzero)
{
    int i,j;
    for(i=0;i<=nzero;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
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
int findspm(int trpm[][3],int spm[][size],int nzero)
{
    int i,j;
    int row=trpm[0][0],col=trpm[0][1];
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            spm[i][j]=0;
        }
    }
    for(i=1;i<=nzero;i++)
    {
        int from=trpm[i][0];
        int to=trpm[i][1];
        spm[from][to]=trpm[i][2];
    }
}
int main()
{
    int trpm[size][3],spm[size][size],nzero;
    nzero=scan(trpm);
    printf("entered matrix is :\n");
    displaytrpm(trpm,nzero);
    findspm(trpm,spm,nzero);
    printf("sparse matrix is :\n");
    display(spm,trpm[0][0],trpm[0][1]);
    return 0;
}