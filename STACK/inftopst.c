//convert infix to postfix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
int top=-1;
char stack[size];
void push(char x)
{
    if(top!=size-1)
        stack[++top]=x;
}
char pop()
{
    if(top!=-1)
        return stack[top--];
}
char peak()
{
    if(top!=-1)
        return stack[top];
}
int isoperand(char x)
{
    if(x>='a' && x<='z')
        return 1;
    else if(x>='A' && x<='Z')
        return 1;
    else
        return 0;
}
int precd(char x)
{
    switch(x)
    {
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '^':
            return 3;
            break;
        default :
            return 0;
    }
}
void inftopst(char infx[],char pstfx[])
{
    int i=0,j=0;
    while(infx[i]!='\0')
    {
        char x=infx[i];
        if(isoperand(x))
            pstfx[j++]=x;
        else if(x=='(')
            push(x);
        else if(x==')')
        {
            while(peak()!='(')
                pstfx[j++]=pop();
            pop();
        }
        else
        {
            while(precd(peak())>=precd(x))
            {
                if(x=='^' && peak()=='^')
                    break;
                else
                    pstfx[j++]=pop();   
            }
            push(x);   
        }
        i++;
    }
    while(top!=-1)
        pstfx[j++]=pop();
    pstfx[j]='\0';
}
int main()
{
    char infx[size];
    printf("enter the infix expression : ");
    scanf("%[^\n]s",infx);
    char pstfx[size];
    inftopst(infx,pstfx);
    printf("postfix expression is : %s\n",pstfx);
    return 0;
}
