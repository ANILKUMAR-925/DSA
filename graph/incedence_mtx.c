#include<stdio.h>
#include<stdlib.h>
#define size 100
int scan(int em[][2])
{
    int edge,i,j;
    printf("enter the number of edges : ");
    scanf("%d",&edge);
    printf("enter the edge matrix : \n");
    for(i=0;i<edge;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d",&em[i][j]);
        }
    }
    return edge;
}
int find(int em[][2],int incm[][size],int edge)
{
    int v=-1,i,j;
    for(i=0;i<edge;i++)
    {
        for(j=0;j<2;j++)
        {
            if(v<em[i][j])
            {
                v=em[i][j];
            }
        }
    }
    v++;
    for(i=0;i<v;i++)
    {
        for(j=0;j<edge;j++)
        {
            incm[i][j]=0;
        }
    }
    for(i=0;i<edge;i++)
    {
        int from=em[i][0];
        int to=em[i][1];
        incm[from][i]=1;
        incm[to][i]=-1;
    }
    return v;
}
void display(int incm[][size],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(incm[i][j]==1 || incm[i][j]==0)
            {
                printf(" ");
            }
            printf("%d ",incm[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    int edge,em[size][2];
    edge=scan(em);
    int incm[size][size];
    int v=find(em,incm,edge);
    printf("incedence matrix is :\n");
    display(incm,v,edge);
    return 0;
}