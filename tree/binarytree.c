//program to perform operation on binary tree
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
node* createbt()
{
    node *root;
    root=(node*)malloc(sizeof(node));
    printf("\nenter the data else enter 0 for no data : ");
    scanf("%d",&root->data);
    if(root->data==0)
    {
        free(root);
        return NULL;   
    }
    else
    {
        printf("enter the left data of %d : ",root->data);
        root->left=createbt();
        printf("enter the right data of %d : ",root->data);
        root->right=createbt();
    }
    return root;
}
void intvl(node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        intvl(root->left);
        printf("%d ",root->data);
        intvl(root->right);
    }
}
void pretvl(node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        printf("%d ",root->data);
        pretvl(root->left);
        pretvl(root->right);
    }
}
void posttvl(node* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        posttvl(root->left);
        posttvl(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
    node* root=NULL;
    root=createbt();
    int op;
    printf("\n");
    while(1)
    {
        printf("enter 1 for preorder traversal :\nenter 2 for inorder traversal :\nenter 3 for postorder traversal :\nenter 4 to exit : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("\npreorder traversal : ");
                pretvl(root);
                printf("\n");
                break;
            case 2:
                printf("\ninorder traversal : ");
                intvl(root);
                printf("\n");
                break;
            case 3:
                printf("\npostorder traversal : ");
                posttvl(root);
                printf("\n");
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nwrong choice\n");
        }
        printf("\n");
    }
    return 0;
}