#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}node;
void display(node* head)
{
    if(head==NULL)
        printf("\nlinkedlist is empty\n");
    else
    {
        node* temp=head;
        while(temp->next!=head)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
node* createll(node *head)
{
    int op;
    do
    {
        node* temp;
        node* newnode=(node*)malloc(sizeof(node));
        printf("\nenter the data : ");
        scanf("%d",&newnode->data);
        if(head==NULL)
        {
            temp=head=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=temp->next;
        }
        head->prev=newnode;
        newnode->next=head;
        printf("enter 1 for another node else enter 0 : ");
        scanf("%d",&op);
    }while(op==1);
    return head;
}
node* insertb(node* head)
{
    node* newnode=(node*)malloc(sizeof(node));
    printf("enetr the data : ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    newnode->prev=head->prev;
    (head->prev)->next=newnode;
    head=newnode;
    return head;
}
node* inserte(node* head)
{
    node* newnode=(node*)malloc(sizeof(node));
    printf("enter the data : ");
    scanf("%d",&newnode->data);
    node* temp;
    if(head==NULL)
    {
        temp=head=newnode;
    }
    else
    {
        node* temp=head->prev;
        temp->next=newnode;
        newnode->prev=temp;
    }
    head->prev=newnode;
    newnode->next=head;
    return head;
}
int lenll(node* head)
{
    int i=0;
    node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
        i++;
    }
    return ++i;
}
node* insertm(node* head)
{
    int i=1,pos,len=lenll(head);
    printf("\nenter the position where you want to insert (1 to %d) : ",len+1);
    scanf("%d",&pos);
    if(pos==1)
    {
        head=insertb(head);
    }
    else if(pos==len+1)
    {
        head=inserte(head);
    }
    else if(pos<=0 || pos>len+1)
    {
        printf("enter the position between 1 to %d\n",len+1);
    }
    else
    {
        node* temp=head;
        node* newnode=(node*)malloc(sizeof(node));
        printf("enter the data you ant ot insert : ");
        scanf("%d",&newnode->data);
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        node* before=temp->prev;
        newnode->next=temp;
        newnode->prev=before;
        before->next=newnode;
        temp->prev=newnode;
    }
    return head;
}
node* deleteb(node* head)
{
    node* temp=head;
    if(head->next==head)
    {
        free(temp);
        return NULL;
    }
    else
    {
        node* before=head->prev;
        before->next=head->next;
        head=head->next;
        head->prev=before;
        free(temp);
    }
    return head;
}
node* deletee(node* head)
{
    node* temp=head;
    if(head->next==head)
    {
        free(temp);
        head=NULL;
    }
    else
    {
        temp=head->prev;
        node* before=temp->prev;
        before->next=head;
        head->prev=before;
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
    {
        head=deleteb(head);
    }
    else if(pos==len)
    {
        head=deletee(head);
    }
    else if(pos<1 || pos>len)
    {
        printf("eneter the position between 1 to %d\n",len);
    }
    else
    {
        node* temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        node* before=temp->prev;
        before->next=temp->next;
        (temp->next)->prev=before;
        free(temp);
    }
    return head;
}
int main()
{
    node* head=NULL;
    int op;
    while(1)
    {
        printf("enter 1 to DISPLAY :\nenter 2 to INSERT :\nenter 3 to DELETE :\nenter 4 to EXIT : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            printf("\nlinkedlist elements are : ");
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
        printf("\n");
    }
    return 0;
}