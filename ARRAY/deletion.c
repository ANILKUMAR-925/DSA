//program to delete an element from the array
#include<stdio.h>
#include<stdlib.h>
int* scan(int* n)
{
    printf("enter the size of the array : ");
    scanf("%d",n);
    int* arr=(int*)malloc((*n)*sizeof(int));
    printf("enter the array elements : ");
    int i;
    for(i=0;i<*n;i++)
        scanf("%d",&arr[i]);
    return arr;
}
void display(int* arr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int delete(int* arr,int n)
{
    int i,pos;
    printf("enter the index you want to delete (0 to %d) : ",n-1);
    scanf("%d",&pos);
    if(pos<0 || pos>=n)
    {
        printf("can not delete\n");
        return n;
    }
    else
    {
        for(i=pos;i<n-1;i++)
        {
            arr[i]=arr[i+1];
        }
        return n-1;
    }
}
int main()
{
    int n;
    int* arr=scan(&n);
    printf("array elements before deletion : ");
    display(arr,n);
    delete(arr,n);
    printf("array elements after deletion : ");
    display(arr,n);
    return 0;
}