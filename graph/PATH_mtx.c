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
    }
    return v;
}
void multm(int mat1[][size],int mat2[][size],int resm[][size],int v)
{
    int i,j,k;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            resm[i][j]=0;
            for(k=0;k<v;k++)
            {
                resm[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
}
void addm(int mat1[][size],int mat2[][size],int resm[][size],int v)
{
    int i,j;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            resm[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
}
void findpathm(int adjm[][size],int pathm[][size],int v)
{
    int addres[size][size],mulres[size][size];
    int i,j;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            addres[i][j]=mulres[i][j]=adjm[i][j];
        }
    }
    for(i=2;i<=v;i++)
    {
        int add[size][size],mult[size][size];
        for(i=0;i<v;i++)
        {
            for(j=0;j<v;j++)
            {
                add[i][j]=addres[i][j];
                mult[i][j]=mulres[i][j];
            }
        }
        multm(mult,adjm,mulres,v);
        addm(add,mulres,addres,v);
    }
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(addres[i][j]!=0)
                pathm[i][j]=1;
            else
                pathm[i][j]=0;
        }
    }
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