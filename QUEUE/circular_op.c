//program to perform operation operation s on a circular queue
#include<stdio.h>
#include<stdlib.h>
#define size 3
typedef struct queue{
    int arr[size];
    int front,rear;
}queue;
queue q;
int isempty()
{
    if(q.rear==-1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if((q.rear+1)%size==q.front)
        return 1;
    else
        return 0;
}
void insert(int x)
{
    if(isfull())
        printf("\nquque overflow\n");
    else
    {
        if(q.front==-1)
            q.front=q.rear=0;
        else
            q.rear=(q.rear+1)%size;
        q.arr[q.rear]=x;
    }
}
int delete()
{
    int x;
    if(isempty())
        x=-1;
    else
    {
        x=q.arr[q.front];
        if(q.front==q.rear)
            q.front=q.rear=-1;
        else
            q.front=(q.front+1)%size;
    }
    return x;
}
void display()
{
    if(isempty())
        printf("\nqueue underflow\n");
    else
    {
        printf("\nqueue elements are : ");
        int i=q.front;
        while(i!=q.rear)
        {
            printf("%d ",q.arr[i]);
            i=(i+1)%size;
        }
        printf("%d\n",q.arr[i]);
    }
}
int main()
{
    q.front=q.rear=-1;
    int op,x;
    while(1)
    {
        printf("enter 1 to INSERT :\nenter 2 to DELETE :\nenter 3 to DISPLAY :\nenter 4 to EXIT : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("\nenter element you want to insert : ");
                scanf("%d",&x);
                insert(x);
                break;
            case 2:
                x=delete();
                if(x==-1)
                    printf("\nqueue undesflow\n");
                else
                    printf("\ndeleted element is : %d\n",x);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default :
                printf("\nwrong choice\n");
        }
        printf("\n");
    }
}