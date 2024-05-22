//stack using linkedlist
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* top=NULL;
void push(int x)
{
    node* newnode=(node*)malloc(sizeof(node));;
    if(newnode==NULL)
        printf("\nstack overflow\n");
    else
    {
        newnode->data=x;
        newnode->next=top;
        top=newnode;
    }
}
int pop()
{
    int x;
    if(top==NULL)
        x=-1;
    else
    {
        node* temp=top;
        x=top->data;
        top=top->next;
        free(temp);
    }
    return x;
}
void display()
{
    node* temp=top;
    if(temp==NULL)
        printf("\nstack underflow\n");
    else
    {
        printf("\nstack elements are : ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int op,x;
    while(1)
    {
        printf("\nenter 1 to INSERT :\nenter 2 to DELETE :\nenter 3 to DISPLAY :\nenetr 4 to EXIT : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("\nenter the element you want to insert : ");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                x=pop();
                if(x==-1)
                    printf("\nstack underflow\n");
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
    }
}