//queue operations using linkedlist
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node *front=NULL,*rear=NULL;
void insert(int x)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    if(front==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=rear->next;
    }
    newnode->next=NULL;
}
int delete()
{
    int x;
    node* temp;
    if(front==NULL)
    {
        x=-1;
    }
    else if(front==rear)
    {
        x=front->data;
        temp=front;
        front=rear=NULL;
    }
    else
    {
        x=front->data;
        temp=front;
        front=front->next;
    }
    free(temp);
    return x;
}
void display()
{
    node *temp=front;
    if(temp==NULL)
        printf("\nqueue underflow\n");
    else
    {
        printf("\nqueue elements are : ");
        while(temp!=rear)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
int main()
{
    int op,x;
    while(1)
    {
        printf("\nenter 1 to INSERT :\nenetr 2 to DELETE :\nenetr 3 to DISPLAY :\nenter 4 to EXIT : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("\nenter the element to insert : ");
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
                display();
                break;
            default :
                printf("\nwrong choice\n");    
        }
    }
}