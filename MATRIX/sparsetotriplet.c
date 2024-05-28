//program to findout triplet representation of a sparse matrix
#include<stdio.h>
#define size 100
void scan(int spmat[][size],int* row,int* col)
{
    int i,j;
    printf("enter the number of rows and columns of the sparse matrix : ");
    scanf("%d%d",row,col);
    printf("enter the elements of the sparse matrix : ");
    for(i=0;i<*row;i++)
    {
        for(j=0;j<*col;j++)
        {
            scanf("%d",&spmat[i][j]);
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
void displaytrp(int mat[][3],int row,int col)
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
int findtrpm(int spmat[][size],int trpm[][3],int row,int col)
{
    int i,j,k=1;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(spmat[i][j]!=0)
            {
                trpm[k][0]=i;
                trpm[k][1]=j;
                trpm[k][2]=spmat[i][j];
                k++;
            }
        }
    }
    trpm[0][0]=row;
    trpm[0][1]=col;
    trpm[0][2]=k-1;
    return k;
}
int main()
{
    int spmat[size][size],trpm[size][3],row,col;
    scan(spmat,&row,&col);
    printf("entered matrix is :\n");
    display(spmat,row,col);
    int k=findtrpm(spmat,trpm,row,col);
    printf("triplet representetion is : \n");
    displaytrp(trpm,k,3);
    return 0;
}