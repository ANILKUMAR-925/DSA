#include<stdio.h>
#include<stdlib.h>
int* scanarr(int* n)
{
    int i;
    printf("enter the size of the array : ");
    scanf("%d",n);
    int* arr=(int*)malloc((*n)*sizeof(int));
    printf("enter the array elements : ");
    for(i=0;i<*n;i++)
    {
        scanf("%d",&arr[i]);
    }
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
void sort(int* arr,int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        for(j=i;key<arr[j-1] && j>0;j--)
        {
            arr[j]=arr[j-1];
        }
        arr[j]=key;
    }
}
int main()
{
    int n,*arr;
    arr=scanarr(&n);
    printf("array elements before sorting : ");
    display(arr,n);
    sort(arr,n);
    printf("array elements after sorting : ");
    display(arr,n);
    return 0;
}