//program to find out the transpose of an sparse matrix in triplet form
#include<stdio.h>
#include<stdlib.h>
#define size 100
int scan(int trpm[][3])
{
    int nzero;
    printf("enter the number of non zero elements in the sparse matrix : ");
    scanf("%d",&nzero);
    int i,j;
    printf("enetr the elements of triplet matrix :\n");
    for(i=0;i<=nzero;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&trpm[i][j]);
        }
    }
    return nzero;
}
void display(int trp[][3],int nzero)
{
    int i,j;
    for(i=0;i<=nzero;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",trp[i][j]);
        }
        printf("\n");
    }
}
void findtrps(int trpm[][3],int res[][3])
{
    int i,j,k=1;
    for(i=0;i<trpm[0][1];i++)
    {
        for(j=1;j<=trpm[0][2];j++)
        {
            if(trpm[j][1]==i)
            {
                res[k][0]=trpm[j][1];
                res[k][1]=trpm[j][0];
                res[k][2]=trpm[j][2];
                k++;
            }
        }
    }
    res[0][0]=trpm[0][1];
    res[0][1]=trpm[0][0];
    res[0][2]=trpm[0][2];
}
int main()
{
    int trpm[size][3],res[size][3],nzero;
    nzero=scan(trpm);
    printf("entered matrix is : \n");
    display(trpm,nzero);
    findtrps(trpm,res);
    printf("transpose of the matrix is :\n");
    display(res,nzero);
    return 0;
}