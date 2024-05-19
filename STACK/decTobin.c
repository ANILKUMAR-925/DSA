//program to convert binary to decimal
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
void bintodec(int num)
{
    int rem;
    while(num>0)
    {
        rem=num%2;
        num=num/2;
        push(rem);
    }
    while(star.top!=-1)
    {
        printf("%d",pop());
    }
    printf("\n");
}
int main()
{
    star.top=-1;
    int num;
    printf("enter a decimal number : ");
    scanf("%d",&num);
    printf("binary equivalent of %d is : ",num);
    bintodec(num);
    printf("\n");
}