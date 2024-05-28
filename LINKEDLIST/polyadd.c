//program to addition of polynomial
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int coef;
    int exp;
    struct node* next;
}node;
node* createpol(node* poly)
{   
    int op;
    do
    {
        node* temp;
        node* newnode=(node*)malloc(sizeof(node));
        printf("\nenter the coefficient and exponent : ");
        scanf("%d%d",&newnode->coef,&newnode->exp);
        if(poly==NULL)
        {
            poly=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=temp->next;
        }
        newnode->next=NULL;
        printf("enter 1 for another node else enter 0 : ");
        scanf("%d",&op);
    }while(op==1);
    return poly;
}
void display(node* poly)
{
    node* temp=poly;
    while(temp->next!=NULL)
    {
        printf("%dx^%d+",temp->coef,temp->exp);
        temp=temp->next;
    }
    printf("%dx^%d\n",temp->coef,temp->exp);
}
node* insert(node* poly3,int coef,int exp)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->coef=coef;
    newnode->exp=exp;
    newnode->next=NULL;
    node* temp;
    if(poly3==NULL)
    {
        poly3=newnode;
        temp=newnode;
    }
    else
    {
        temp=poly3;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return poly3;
}
node* addpol(node* poly1,node* poly2)
{
    node* poly3=NULL;
    int coef,exp;
    while(poly1!=NULL && poly2!=NULL)
    {
        if(poly1->exp>poly2->exp)
        {
            coef=poly1->coef;
            exp=poly1->exp;
            poly3=insert(poly3,coef,exp);
            poly1=poly1->next;
        }
        else if(poly1->exp<poly2->exp)
        {
            coef=poly2->coef;
            exp=poly2->exp;
            poly3=insert(poly3,coef,exp);
            poly2=poly2->next;
        }
        else
        {
            coef=poly1->coef+poly2->coef;
            exp=poly1->exp;
            poly3=insert(poly3,coef,exp);
            poly1=poly1->next;
            poly2=poly2->next;
        }
    }
    while(poly1!=NULL)
    {
        coef=poly1->coef;
        exp=poly1->exp;
        poly3=insert(poly3,coef,exp);
        poly1=poly1->next;
    }
    while(poly2!=NULL)
    {
        coef=poly2->coef;
        exp=poly2->exp;
        poly3=insert(poly3,coef,exp);
        poly2=poly2->next;
    }
    return poly3;
}
int main()
{
    node *poly1=NULL,*poly2=NULL,*poly3=NULL;
    printf("enter the first polynomial : \n");
    poly1=createpol(poly1);
    printf("entered polynomial is : ");
    display(poly1);
    printf("enter the second polynomial : \n");
    poly2=createpol(poly2);
    printf("entered polynomial is : ");
    display(poly2);
    poly3=addpol(poly1,poly2);
    printf("addition of the two polynomials are : ");
    display(poly3);
    return 0;
}