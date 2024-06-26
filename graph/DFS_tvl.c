#include<stdio.h>
#include<stdlib.h>
#define size 100
int scan(int em[][2])
{
    int i,j,edge;
    printf("enter the number of edges : ");
    scanf("%d",&edge);
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
int findadjm(int em[][2],int adjm[][size],int edge)
{
    int i,j,v=-1;
    for(i=0;i<edge;i++)
    {
        for(j=0;j<2;j++)
        {
            if(em[i][j]>v)
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
    }
    return v;
}
void dfstvl(int adjm[][size],int visit[],int v,int node)
{
    //visiting and printing all node connected to first node
    int i;
    printf("%d ",node);
    visit[node]=1;
    for(i=0;i<v;i++)
    {
        if(adjm[node][i]==1 && visit[i]==0)
        {
            dfstvl(adjm,visit,v,i);
        }
    }
}
int main()
{
    int em[size][2],edge;
    edge=scan(em);
    int v,adjm[size][size];
    v=findadjm(em,adjm,edge);
    int i,visit[v];
    for(i=0;i<v;i++)
    {
        visit[i]=0;
    }
    int node;
    printf("enetr the node  from which you want to traverse : ");
    scanf("%d",&node);
    printf("DFS traversal : ");
    dfstvl(adjm,visit,v,node);
    printf("\n");
    return 0;
}