//program to add two sparse matrix
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
void findsum(int trpm1[][3],int trpm2[][3],int res[][3])
{
    if(trpm1[0][0]==trpm2[0][0] && trpm1[0][1]==trpm2[0][1])
    {
        int i=1,j=1,k=1;
        while(i<=trpm1[0][2] && j<=trpm2[0][2])
        {
            if(trpm1[i][0]<trpm2[j][0])
            {
                res[k][0]=trpm1[i][0];
                res[k][1]=trpm1[i][1];
                res[k++][2]=trpm1[i++][2];
            }
            else if(trpm1[i][0]>trpm2[j][0])
            {
                res[k][0]=trpm2[j][0];
                res[k][1]=trpm2[j][1];
                res[k++][2]=trpm2[j++][2];
            }
            else
            {
                if(trpm1[i][1]<trpm2[j][1])
                {
                    res[k][0]=trpm1[i][0];
                    res[k][1]=trpm1[i][1];
                    res[k++][2]=trpm1[i++][2];
                }
                else if(trpm1[i][1]>trpm2[j][1])
                {
                    res[k][0]=trpm2[j][0];
                    res[k][1]=trpm2[j][1];
                    res[k++][2]=trpm2[j++][2];
                }
                else
                {
                    res[k][0]=trpm2[j][0];
                    res[k][1]=trpm2[j][1];
                    res[k++][2]=trpm1[i++][2]+trpm2[j++][2];
                }
            }
        }
        while(i<=trpm1[0][2])
        {
            res[k][0]=trpm1[i][0];
            res[k][1]=trpm1[i][1];
            res[k++][2]=trpm1[i++][2];
        }
        while(j<=trpm2[0][2])
        {
            res[k][0]=trpm2[j][0];
            res[k][1]=trpm2[j][1];
            res[k++][2]=trpm2[j++][2];
        }
        res[0][0]=trpm1[0][0];
        res[0][1]=trpm1[0][1];
        res[0][2]=k-1;
    }
}
int main()
{
    int trpm1[size][3],trpm2[size][3],res[size][3];
    int nzero1=scan(trpm1);
    printf("entered natrix is : \n");
    display(trpm1,nzero1);
    int nzero2=scan(trpm2);
    printf("entered natrix is : \n");
    display(trpm2,nzero2);
    findsum(trpm1,trpm2,res);
    printf("adiition of two matrix is :\n");
    display(res,res[0][2]);
    return 0;
}