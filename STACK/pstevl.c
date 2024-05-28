//program for postfix evaluation
#include<stdio.h>
#include<string.h>
#include<math.h>
#define size 100
int stack[size];
int top=-1;
int isfull()
{
    if(top==size-1)
        return 1;
    else 
        return 0;
}
int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void push(int x)
{
    if(!isfull())
    {
        stack[++top]=x;
    }

}
int pop()
{
    if(!isempty())
    {
        return stack[top--];
    }
}
int isoperator(char x)
{
    if(x<='+' || x=='-' || x=='*' || x=='/' || x=='^')
        return 1;
    else 
        return 0;
}
void find(char x)
{
    int a=pop();
    int b=pop();
    int value;
    switch(x)
    {
        case '+':
            value=b+a;
            push(value);
            break;
        
        case '-':
            value=b-a;
            push(value);
            break;    
        case '*':
            value=b*a;
            push(value);
            break;
        case '/':
            value=b/a;
            push(value);
            break;
        case '^':
            value=pow(b,a);
            push(value);
            break;
        default :
            return;
    }
}
int pstfxev(char pstfx[])
{
    int i=0;
    while(pstfx[i]!='\0')
    {
        char x=pstfx[i];
        int value;
        if(!isoperator(x))
        {
            printf("enter the value of %c : ",x);
            scanf("%d",&value);
            push(value);
        }
        else
        {
            find(x);
        }
        i++;
    }
    int res=pop();
    return res;
}
int main()
{
    char pstfx[size];
    printf("enetr the postfix expression : ");
    scanf("%[^\n]s",pstfx);
    int res=pstfxev(pstfx);
    printf("result is : %d\n",res);
    return 0;
}