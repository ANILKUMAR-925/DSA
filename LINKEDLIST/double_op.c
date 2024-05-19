//program to perform operations on a double linkedlist
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;
node* createll(node *head)
{
    node *newnode,*temp;
    int op;
    do
    {
        newnode=(node*)malloc(sizeof(node));
        printf("\nenetr the data : ");
        scanf("%d",&newnode->data);
        if(head==NULL)
        {
            head=temp=newnode;
            head->prev=NULL;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=temp->next;
        }
        newnode->next=NULL;
        printf("enter 1 for newnode else enter 0 : ");
        scanf("%d",&op);
    }while(op==1);
    return head;
}
void traverse(node* head)
{
    if(head==NULL)
    {
        printf("\nlinkedlist is empty\n");
    }
    else
    {
        printf("\nlinkedlist elements are : ");
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
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\nenter the data for the node : ");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        head->next=NULL;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    head->prev=NULL;
    return head;
}
node* inserte(node* head)
{
    node* newnode,*temp=head;
    newnode=(node*)malloc(sizeof(node));
    printf("\neneter the data : ");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        head->prev=NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
    newnode->next=NULL;
    return head;
}
int lenll(node* head)
{
    int i=0;
    while(head!=NULL)
    {
        head=head->next;
        i++;
    }
    return i;
}
node* insertm(node* head)
{
    int i=1,len=lenll(head),pos;
    node *temp=head,*newnode;
    printf("\nenter the position tou want to insert 1 to %d : ",len+1);
    scanf("%d",&pos);
    if(pos==1)
    {
        head=insertb(head);
    }
    else if(pos==len+1)
    {
        head=inserte(head);
    }
    else if(pos<1 || pos>len+1)
    {
        printf("enter the position between 1 to %d\n",len+1);
    }
    else
    {
        node* before=NULL;
        newnode=(node*)malloc(sizeof(node));
        printf("enter the data : ");
        scanf("%d",&newnode->data);
        while(i<pos)
        {
            before=temp;
            temp=temp->next;
            i++;
        }
        before->next=newnode;
        newnode->prev=before;
        newnode->next=temp;
    }
    return head;
}
node* deleteb(node* head)
{
    if(head==NULL)
    {
        return head;
    }
    else if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        node *temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    return head;
}
node* deletee(node* head)
{
    node* temp=head;
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        node* before=temp->prev;
        before->next=NULL;
        free(temp);
    }
    return head;
}
node* deletem(node* head)
{
    int i=1,pos,len=lenll(head);
    node* temp=head;
    printf("\nenter the position you want to delete 1 to %d : ",len);
    scanf("%d",&pos);
    if(pos==1)
    {
        head=deleteb(head);
    }
    else if(pos==len)
    {
        head=deletee(head);
    }
    else if(pos<1 || pos>len)
    {
        printf("enter the position between 1 to %d\n",len);
    }
    else
    {
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        node* before=temp->prev;
        node* after=temp->next;
        before->next=after;
        after->prev=before;
        free(temp);
    }
    return head;
}
int main()
{
    int x,op;
    node* head=NULL;
    head=createll(head);
    while(1)
    {
        printf("\nenter 1 to display :\nenter 2 to insert :\nenter 3 to delete :\neneter 4 to exit :");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                traverse(head);
                printf("\n");
                break;
            case 2:
                head=insertm(head);
                break;
            case 3:
                head=deletem(head);
                if(head==NULL)
                {
                    printf("\ncan not delete\n");
                }
                break;
            case 4:
                exit(0);
            default :
                printf("wrong choice\n");
        }
        printf("\n");
    }
    return 0;
}