//program to check validity of any expression containing nested parenthesis
#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#define size 100
char stack[size];
int top=-1;
int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if(top==size-1)
        return 1;
    else
        return 0;
}
void push(char x)
{
    if(!isfull())
        stack[++top]=x;
}
char pop()
{
    if(!isempty())
        return stack[top--];
}
char peak()
{
    if(!isempty())
        return stack[top];
}
int match(char x,char y)
{
    if(x==')' && y=='(')
        return 1;
    if(x=='}' && y=='{')
        return 1;
    if(x==']' && y=='[')
        return 1;
    else
        return 0;
}
void isvalid(char exp[])
{
    int i=0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{' )
            push(exp[i]);
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
            if(match(exp[i],peak()))
                pop();
            else
                return;
        }
        i++;
    }
}
int main()
{
    char exp[size];
    printf("enter the expression : ");
    scanf("%[^\n]s",exp);
    isvalid(exp);
    if(isempty())
        printf("expression is valid\n");
    else
        printf("expression is invalid\n");
    return 0;
}