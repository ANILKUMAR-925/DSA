//program to insert an element in the array
#include<stdio.h>
#include<stdlib.h>
int* scan(int *n)
{
    printf("enter the size of the array : ");
    scanf("%d",n);
    int* arr=(int*)malloc((*n+1)*sizeof(int));
    printf("enter the array elements : ");
    int i;
    for(i=0;i<*n;i++)
        scanf("%d",&arr[i]);
    return arr;
}
void display(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int insert(int arr[],int n)
{
    int i,value,pos;
    printf("enter the index where you want to insert (0 to %d) : ",n);
    scanf("%d",&pos);
    printf("enter the element you want to insert : ");
    scanf("%d",&value);
    if(pos>n || pos<0)
        printf("can not insert\n");
    else
    {
        for(i=n+1;i>pos;i--)
            arr[i]=arr[i-1];
        arr[pos]=value;
        return n+1;
    }
}
int main()
{
    int n;
    int* arr=scan(&n);
    printf("array elements before insertion : ");
    display(arr,n);
    n=insert(arr,n);
    printf("array elements after insertion : ");
    display(arr,n);
    return 0;
}