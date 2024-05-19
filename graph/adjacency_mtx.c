#include<stdio.h>
#include<stdlib.h>
#define size 100
int scan(int em[][2])
{
    int edge;
    printf("enter the number of edges : ");
    scanf("%d",&edge);
    int i,j;
    printf("enter the edge matrix :\n");
    for(i=0;i<edge;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d",&em[i][j]);
        }
    }
    return edge;
}
int find(int em[][2],int adjm[][size],int edge)
{
    int v=-1;
    int i,j;
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
        for(j=0;j<v;j++)
        {
            adjm[i][j]=0;
        }
    }
    for(i=0;i<edge;i++)
    {
        int from=em[i][0];
        int to=em[i][1];
        adjm[from][to]=1;
        adjm[to][from]=1;
    }
    return v;
}
void display(int adjm[][size],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",adjm[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    int edge,em[size][2];
    edge=scan(em);
    int adjm[size][size];
    int v=find(em,adjm,edge);
    printf("adjacency matrix is : \n");
    display(adjm,v,v);
    return 0;
}