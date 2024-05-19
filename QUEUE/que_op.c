#include<stdio.h>
#include<stdlib.h>
#define size 100
typedef struct queue{
    int arr[size];
    int front,rear;
}queue;
queue q;
int isempty()
{
    if(q.front==-1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if(q.rear==size-1)
        return 1;
    else
        return 0;
}
void insert(int x)
{
    if(isfull())
        printf("\nqueue overflow\n");
    else
    {
        if(q.front==-1)
        {
            q.front=q.rear=0;
            q.arr[q.rear]=x;
        }
        else
            q.arr[++q.rear]=x;
    }
}
int delete()
{
    if(isempty())
        return -1;
    else
    {
        int x=q.arr[q.front];
        if(q.front==q.rear)
        {
            q.front=q.rear=-1;
        }
        else
            q.front++;
        return x;
    }
}
int getf()
{
    if(isempty())
        return -1;
    else
        return q.arr[q.front];
}
int getr()
{
    if(isempty())
        return -1;
    else
        return q.arr[q.rear];
}
void display()
{
    int i=q.front;
    printf("\nqueue elements are : ");
    while(i<=q.rear)
    {
        printf("%d ",q.arr[i]);
        i++;
    }
    printf("\n");
}
int main()
{
    q.front=q.rear=-1;
    int op,x;
    while(1)
    {
        printf("enetr 1 to INSERT :\nenter 2 to DELETE :\nenter 3 to get FRONT :\nenter 4 to get REAR :\nenter 5 to DISPLAY :\nenter 6 to EXIT : ");
        scanf("%d",&op);;
        switch(op)
        {
            case 1:
                printf("\nenter the element you want to insert : ");
                scanf("%d",&x);
                insert(x);
                break;
            case 2:
                x=delete();
                if(x==-1)
                    printf("\nqueue underflow\n");
                else
                    printf("\ndeleted element is : %d\n",x);
                break;
            case 3:
                x=getf();
                if(x==-1)
                    printf("\nqueue underflow\n");
                else
                    printf("\nfront element is : %d\n",x);
                break;
            case 4:
                x=getr();
                if(x==-1)
                    printf("\nqueue underflow\n");
                else
                    printf("\nrear element is : %d\n",x);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default :
                printf("\nwrong choice\n");
        }
        printf("\n");
    }
}