#include<stdio.h>
#include<stdlib.h>
#define size 100
int scan(int em[][2])
{
    int i,j,edge;
    printf("enter the number of edges : ");
    scanf("%d",&edge);
    printf("ener the edge matrix :\n");
    for(i=0;i<edge;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d",&em[i][j]);
        }
    }
    return edge;
}
int findadjm(int em[][2],int adjm[][size],int edge)
{
    int i,j,v;
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
int main()
{
    int em[size][2],edge;
    edge=scan(em);
    int v,adjm[size][size];
    v=findadjm(em,adjm,edge);
    int pathm[v][v];
    findpathm(adjm,pathm,v);
    
}