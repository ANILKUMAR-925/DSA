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
    int i=0;
    if(head==NULL)
        return i;
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
    int pos,i=1,len=lenll(head);
    printf("\nenter the position you want to insert (1 to %d) : ",len+1);
    scanf("%d",&pos);
    if(pos==1)
        head=insertb(head);
    else if(pos==len+1)
        head=inserte(head);
    else if(pos<=0 || pos>len+1)
        printf("enter the position between 1 to %d\n",len+1);
    else
    {
        node *prev,*temp=head,*newnode;
        newnode=(node*)malloc(sizeof(node));
        printf("enter the data to insert : ");
        scanf("%d",&newnode->data);
        while(i<pos)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=newnode;
        newnode->next=temp;
    }
    return head;
}
node* deleteb(node* head)
{
    if(head==NULL)
        printf("\nqueue underflow\n");
    else
    {
        node* temp=head;
        head=head->next;
        free(temp);
    }
    return head;
}
node* deletee(node* head)
{
    node* temp=head;
    if(head==NULL)
        printf("\nqueue underflow\n");
    else if(temp->next==NULL)
    {
        free(temp);
        head=NULL;
    }
    else
    {
        node* prev;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
    }
    return head;
}
node* deletem(node* head)
{
    int i=1,pos,len=lenll(head);
    printf("\nenter the position you want to delete (1 to %d) : ",len);
    scanf("%d",&pos);
    if(pos==1)
        head=deleteb(head);
    else if(pos==len)
        head=deletee(head);
    else if(pos<1 || pos>len)
        printf("enter the position between 1 to %d\n",len);
    else
    {
        node* temp=head,*prev;
        while(i<pos)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        free(temp);
    }
    return head;
}
int main()
{
    node* head;
    head=createll();
    int op;
    while(1)
    {
        printf("\nenter 1 to DISPLAY :\nenter 2 to INSERT :\nenter 3 to DELETE :\nenter 4 to EXIT : ");
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
                head=deletem(head);
                break;
            case 4:
                exit(0);
                break;
            default :
                printf("\nwrong choice\n");
        }
    }
}