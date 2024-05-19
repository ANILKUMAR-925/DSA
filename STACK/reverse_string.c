#include<stdio.h>
#include<string.h>
#define size 100
typedef struct stack{
    char arr[size];
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
void push(char x)
{
    if(isfull())
        printf("stack overflow");
    else
        star.arr[++star.top]=x;
}
char pop()
{
    if(isempty())
        return '0';
    else
        return star.arr[star.top--];
}
void reversestr(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        push(str[i]);
        i++;
    }
    i=0;
    while(str[i]!='\0')
    {
        str[i]=pop();
        i++;
    }
}
int main()
{
    star.top=-1;
    char str[size];
    printf("enter the string : ");
    scanf("%[^\n]s",str);
    printf("string before reversing : %s\n",str);
    reversestr(str);
    printf("string after reversing : %s\n",str);
    return 0;
}