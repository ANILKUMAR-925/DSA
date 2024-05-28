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
node* swap(node* ptr1,node* ptr2)
{
    node* temp;
    temp=ptr2->next;
    ptr2->next=ptr1;
    ptr1->next=temp;
    return ptr2;
}
node* sort(node* head)
{
    int i,j,len=lenll(head);
    node **prev,*ptr1,*ptr2;
    for(i=0;i<len-1;i++)
    {
        prev=&head;
        for(j=0;j<len-i-1;j++)
        {
            ptr1=*prev;
            ptr2=ptr1->next;
            if(ptr1->data>ptr2->data)
            {
                *prev=swap(ptr1,ptr2);
            }
            prev=&(*prev)->next;
        }
    }
    return head;
}
node* reverse(node* head)
{
    node *prev=NULL,*current=head,*after;
    while(current!=NULL)
    {
        after=current->next;
        current->next=prev;
        prev=current;
        current=after;
    }
    return prev;
}
node* merge(node* head1,node* head2)
{
    node* temp=head1;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=head2;
    return head1;
}
void search(node* head)
{
    int x,y=0;
    printf("\nenter the element you want to search : ");
    scanf("%d",&x);
    while(head!=NULL)
    {
        if(head->data==x)
        {
            y=1;
            break;
        }
        head=head->next;
    }
    if(y==1)
        printf("%d is present in the linkedlist\n",x);
    else
        printf("%d is present in the linkedlist\n",x);
}
int main()
{
    node* head,*head1;
    head=createll();
    int op;
    while(1)
    {
        printf("\nenter 1 to DISPLAY :\nenter 2 to INSERT :\nenter 3 to DELETE :\ncase 4 to SORT :\nenter 5 to REVERSE :\nenter 6 to MERGE :\nenter 7 to SEARCH :\nenter 8 to EXIT : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                display(head);
                break;
            case 2:
                head=insertm(head);
                int x;
                printf("\nenter the element you want to search : ");
                scanf("%d",&x);
                break;
            case 3:
                head=deletem(head);
                break;
            case 4:
                head=sort(head);
                break;
            case 5:
                head=reverse(head);
                break;
            case 6:
                printf("\nenter the second linkedlist :\n");
                head1=createll();
                head=merge(head,head1);
                break;
            case 7:
                search(head);
                break;
            case 8:
                exit(0);
                break;
            default :
                printf("\nwrong choice\n");
        }
    }
}