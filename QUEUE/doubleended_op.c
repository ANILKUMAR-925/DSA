#include<stdio.h>
#include<stdlib.h>
#define size 5
typedef struct queue{
    int arr[size];
    int front,rear;
}queue;
queue q;
int isfull()
{
    if((q.rear+1)%size==q.front)
        return 1;
    else
        return 0;
}
int isempty()
{
    if(q.front==-1)
        return 1;
    else
        return 0;
}
void insertf(int x)
{
    if(isfull())
        printf("\nqueue overflow\n");
    else
    {
        if(q.front==-1)
            q.front=q.rear=0;
        else if(q.front==0)
            q.front=size-1;
        else
            q.front=q.front-1;
        q.arr[q.front]=x;
    }
}
void insertr(int x)
{
    if(isfull())
        printf("\nqueue overflow\n");
    else
    {
        if(q.rear==-1)
            q.rear=q.front=0;
        else
            q.rear=(q.rear+1)%size;
        q.arr[q.rear]=x;
    }
}
int deletef()
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
int deleter()
{
    int x;
    if(isempty())
        x=-1;
    else
    {
        x=q.arr[q.rear];
        if(q.rear==0)
            q.rear=size-1;
        else if(q.rear==q.front)
            q.front=q.rear=-1;
        else
            q.rear--;
    }
    return x;
}
void display()
{
    if(isempty())
        printf("\nqueue underflow\n");
    else
    {
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
        printf("enter 1 to INSERT at FRONT :\nenter 2 to INSERT  at REAR :\nenter 3 to  DELETE from FRONT :\nenter 4 to DELETE from REAR :\nenter 5 to DISPLAY :\nenter 6 to EXIT : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("\enter the element you want to insert : ");
                scanf("%d",&x);
                insertf(x);
                break;
            case 2:
                printf("\enter the element you want to insert : ");
                scanf("%d",&x);
                insertr(x);
                break;
            case 3:
                x=deletef();
                if(x==-1)
                    printf("\nqueue underflow\n");
                else
                    printf("\ndeleted element is : %d\n",x);
                break;
            case 4:
                x=deleter();
                if(x==-1)
                    printf("\nqueue underflow\n");
                else
                    printf("\ndeleted element is : %d\n",x);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default :
                printf("\nrong choice\n");
        }
        printf("\n");
    }
}