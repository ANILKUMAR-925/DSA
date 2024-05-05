//program to perform operation on binary search tree
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
node* insertbst(node* root,int x)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->data=x;
        root->left=NULL;
        root->right=NULL;
    }
    else
    {
        if(x<root->data) //if data is small from root data insert at the left sub tree
        {
            root->left=insertbst(root->left,x);
        }
        else if(x>root->data) //if data is larger than root data inserting at the right sub tree
        {
            root->right=insertbst(root->right,x);
        }
        else
        {
            printf("\ncan not insert same element\n");
        }
    }
    return root;
}
node* findmin(node* root)
{
    if(root->left==NULL)
    {
        return root;
    }
    else
    {
        return findmin(root->left);
    }
}
node* findmax(node* root)
{
    if(root->right==NULL)
    {
        return root;
    }
    else
    {
        return findmax(root->right);
    }
}
node* deletebst(node* root,int x)
{
    if(root==NULL)
    {
        printf("\n%d not found\n",x);
    }
    else if(x<root->data)  //searching at the left sub tree
    {
        root->left=deletebst(root->left,x);
    }
    else if(x>root->data)  //serching at the right sub tree
    {
        root->right=deletebst(root->right,x);
    }
    else
    {
        //deletion of node having right child only
        if(root->left==NULL && root->right!=NULL)
        {
            node* temp=root;
            root=root->right;
            free(temp);
        }
        //deletion of node having left child only
        else if(root->left!=NULL && root->right==NULL)
        {
            node* temp=root;
            root=root->left;
            free(temp);
        }
        //deletion of leaf node
        else if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        //deletion of node having two child
        else
        {
            node* temp=findmin(root->right);
            //exchnge the root value with minimum value of right sub tree
            root->data=temp->data;
            //deleting the minimum value of right sub tree
            root->right=deletebst(root->right,temp->data);
        }
    }
    return root;
}
node* searchbst(node* root,int x)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(x<root->data)
    {
        return searchbst(root->left,x);
    }
    else if(x>root->data)
    {
        return searchbst(root->right,x);
    }
    else
        return root;
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
    node* root=NULL,*temp;
    int op,x;
    while(1)
    {
        printf("enter 1 to insert :\nenter 2 to delete :\nenter 3 to search :\nenter 4 to find minimum :\nenter 5 to find max :\nenter 6 for preorder traversal :\nenter 7 for inorder traversal :\nenter 8 for postorder traversal :\nenter 9 to exit :");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("\nenter the element you want to insert : ");
                scanf("%d",&x);
                root=insertbst(root,x);
                break;
            case 2:
                printf("\nenter the elemnet you want to delete : ");
                scanf("%d",&x);
                root=deletebst(root,x);
                break;
            case 3:
                printf("\nenter the element you want to search : ");
                scanf("%d",&x);
                temp=searchbst(root,x);
                if(temp->data==x)
                {
                    printf("element is found\n");
                }
                else
                {
                    printf("element is not found\n");
                }
                break;
            case 4:
                temp=findmin(root);
                if(temp!=NULL)
                {
                    printf("\nsmallest element is : %d\n",temp->data);
                }
                break;
            case 5:
                temp=findmax(root);
                if(temp!=NULL)
                {
                    printf("\nlargest element is : %d\n",temp->data);
                }
                break;
            case 6:
                printf("\npreorder traversal : ");
                pretvl(root);
                printf("\n");
                break;
            case 7:
                printf("\ninorder traversal : ");
                intvl(root);
                printf("\n");
                break;
            case 8:
                printf("\npostorder traversal : ");
                posttvl(root);
                printf("\n");
                break;
            case 9:
                exit(0);
                break;
            default:
            printf("\nwrong choice\n");
        }
        printf("\n");
    }
    return 0;
}