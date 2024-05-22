//program to perform operations on a single linkedlist
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* createll()
{
    int op;
    node *head=NULL,*temp;
    do
    {
        node* newnode=(node*)malloc(sizeof(node));
        printf("\nenter the data : ");
        scanf("%d",&newnode->data);
        if(head==NULL)
            head=temp=newnode;
        else
        {
            temp->next=newnode;
            temp=temp->next;
        }
        newnode->next=NULL;
        printf("\nenter 1 for another node else enter 0 : ");
        scanf("%d",&op);
    }while(op==1);
    return head;
}
void display(node* head)
{
    if(head==NULL)
        printf("\nlinkedlist is empty\n");
    else
    {
        printf("\nlinkedlist element are : ");
        while(head!=NULL)
        {
            printf("%d ",head->data);
            head=head->next;
        }
        printf("\n");
    }
}
node* insertb(node* head)
{
    node* newnode=(node*)malloc(sizeof(node));
    printf("\nenter the data to insert : ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    return head;
}
node* inserte(node* head)
{
    node* newnode=(node*)malloc(sizeof(node));
    printf("\nenter the data to insert : ");
    scanf("%d",&newnode->data);
    node* temp=head;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    newnode->next=NULL;
    return head;
}
int lenll(node* head)
{
    int i;
    if(head==NULL)
        i=0;
    else
    {
        while(head!=NULL)
        {
            head=head->next;
            i++;
        }
    }
    return i;
}
node* insertm(node* head)
{
    int pos,i,len=lenll(head);
    printf("enter the position you want to insert (1 to %d) : ",len+1);
    scanf("%d",&pos);
    if(pos==1)
        head=insertb(head);
    else if(pos==len+1)
        head=inserte(head);
}
int main()
{
    node* head;
    head=createll();
    int op;
    while(1)
    {
        printf("\nenter 1 to DISPLAY :\nenter 2 to INSERT :\nenter 3 to EXIT : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                display(head);
                break;
            case 2:
                head=insertm(head);
                break;
            case 3:
                exit(0);
                break;
            default :
                printf("\nwrong choice\n");
        }
    }
}