#include<stdio.h>
#include<stdlib.h>
#define size 100
typedef struct queue{
    int arr[size];
    int f,r;
}queue;
queue q;
int isempty()
{
    if(q.r==-1)
        return 1;
    else 
        return 0;
}
int isfull()
{
    if(q.r==size-1)
        return 1;
    else
        return 0;
}
void enque(int x)
{
    if(!isfull())
    {
        if(q.r==-1)
        {
            q.f=q.r=0;
            q.arr[q.r]=x;
        }
        else
            q.arr[++q.r]=x;
    }
}
int deque()
{
    if(!isempty())
    {
        int x=q.arr[q.f];
        if(q.f==q.r)
        {
            q.f=q.r=-1;
        }
        else
            q.f++;
        return x;
    }
}
int scan(int em[][2])
{
    int i,j,edge;
    printf("enter the number of edge : ");
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
void bfstvl(int em[][2],int adjm[][size],int v)
{
    int node,i,j;
    printf("enter the node from which you want to traverse : ");
    scanf("%d",&node);
    int visit[v];
    //marrking all the  nodes as unvisited
    for(i=0;i<v;i++)
    {
        visit[i]=0;
    }
    visit[node]=1;
    printf("%d ",node);
    enque(node);
    while(!isempty())
    {
        node=deque();
        for(i=0;i<v;i++)
        {
            //checking if there is a direction in between deque node to another node which is not visited  
            if(adjm[node][i]==1 && visit[i]==0)
            {
                printf("%d ",i);
                enque(i);
                visit[i]=1;
            }
        }
    }
}
int main()
{   
    q.f=q.r=-1;
    int edge,em[size][2];
    edge=scan(em);
    int adjm[size][size],v;
    v=findadjm(em,adjm,edge);
    printf("BFS traversal : ");
    bfstvl(em,adjm,v);
    printf("\n");
    return 0;
}