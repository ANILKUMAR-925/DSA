//program to perform operations on circular linkedlist
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* createll(node* head)
{
    int op;
    node *newnode,*temp;
    do
    {
        newnode=(node*)malloc(sizeof(node));
        printf("\nenter the data : ");
        scanf("%d",&newnode->data);
        if(head==NULL)
        {
            head=temp=newnode;
            head->next=head;
        }
        else
        {
            temp->next=newnode;
            temp=temp->next;
            newnode->next=head;
        }
        printf("enter 1 for another node else enter 0 : ");
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
        node* temp=head;
        printf("\nlinkedlist elements are : ");
        while(temp->next!=head)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
    }
}
node* insertb(node* head)
{
    node *newnode,*temp;
    newnode=(node*)malloc(sizeof(node));
    printf("\nenter the data : ");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        newnode->next=head;
        head=newnode;
        temp->next=head;
    }
    return head;
}
node* inserte(node* head)
{
    node *newnode,*temp=head;
    newnode=(node*)malloc(sizeof(node));
    printf("\nenter the data : ");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
    }
    return head;
}
int lenll(node* head)
{
    node* temp=head;
    int i=0;
    while(temp->next!=head)
    {
        temp=temp->next;
        i++;
    }
    return i+1;
}
node* insertm(node* head)
{
    node *newnode,*temp=head,*prev=NULL;
    int i=1,pos,len=lenll(head);
    printf("\nenter the position you want to insert 1 to %d : ",len+1);
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
        newnode=(node*)malloc(sizeof(node));
        printf("enter the data : ");
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
    node* temp=head;
    if(head==NULL)
    {
        return NULL;
    }
    else if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        node* ptr=head;
        head=head->next;
        temp->next=head;
        free(ptr);
    }
    return head;
}
node* deletee(node* head)
{
    node *temp=head,*prev=NULL;
    if(head==NULL)
    {
        return NULL;
    }
    else if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        while(temp->next!=head)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=head;
        free(temp);
    }
    return head;
}
node* deletem(node* head)
{
    int i=1,pos,len=lenll(head);
    node* temp=head,*prev=NULL;
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
    int x,op;
    node *head=NULL;
    head=createll(head);
    while(1)
    {
        printf("\nenetr 1 to display :\nenter 2 to insert : \nenter 3 to delete :\nenter 4 to exit : ");
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
                    printf("\nlinkedlist is empty\n");
                break;
            case 4:
                exit(0);
                break;
            default :
                printf("\nwrorng choice\n");
        
        }
        printf("\n");
    }
    return 0;
}