//program to perform operations on stack
#include<stdio.h>
#include<stdlib.h>
#define size 100
typedef struct stack{
    int arr[size];
    int top;
}stack;
stack star;
int isfull()
{
    if(star.top==size-1)
        return 1;
    else
        return 0;
}
int isempty()
{
    if(star.top==-1)
        return 1;
    else
        return 0;
}
void push(int x)
{
    if(isfull())
        printf("stack overflow");
    else
        star.arr[++star.top]=x;
}
int pop()
{
    if(isempty())
        return -1;
    else
        return star.arr[star.top--];
}
int top()
{
    if(isempty())
        return -1;
    else
        return star.arr[star.top];
}
void display()
{
    if(isempty())
        printf("\nstack underflow\n");
    else
    {
        printf("\nstack elements are : ");
        int i=star.top;
        while(i!=-1)
        {
            printf("%d ",star.arr[i]);
            i--;
        }
    }
    printf("\n");
}
int main()
{
    star.top=-1;
    int op,x;
    while(1)
    {
        printf("enetr 1 to PUSH :\nenter 2 to POP :\nenter 3 to get TOP element :\nenter 4 to DISPLAY :\nenter 5 to EXIT : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("\nenter the element you want to INSERT : ");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                x=pop();
                if(x==-1)
                    printf("\nqueue underflow\n");
                else
                    printf("\ndeleted element is : %d\n",x);
                break;
            case 3:
                x=top();
                if(x==-1)
                    printf("\nqueue underflow\n");
                else
                    printf("\ntop element is : %d\n",x);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default :
                printf("\nwrong choice\n");
        }
        printf("\n");
    }
    return 0;
}