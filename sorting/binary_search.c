//progarm for binary search
#include<stdio.h>
#include<stdlib.h>
int* scan(int* size)
{
    printf("enter the size of the arry : ");
    scanf("%d",size);
    int* arr=(int *)malloc((*size)*sizeof(int));
    int i;
    printf("enter the array elements in sorted manner : ");
    for(i=0;i<*size;i++)
    {
        scanf("%d",&arr[i]);
    }
    return arr;
}
void display(int* arr,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int search(int* arr,int size)
{
    int value;
    printf("enter the element you want to search : ");
    scanf("%d",&value);
    int low=0,high=size-1,mid=(low+high)/2;
    while(low<=high)
    {
        if(arr[mid]==value)
            return mid;
        else if(arr[mid]>value)
            high=mid-1;
        else if(arr[mid]<value)
            low=mid+1;
        mid=(low+high)/2;
    }
    return -1;
}
int main()
{
    int size;
    int* arr=scan(&size);
    printf("entered array is : ");
    display(arr,size);
    int x=search(arr,size);
    if(x!=-1)
        printf("element s found on the index : %d\n",x);
    else
        printf("element is not found\n");
    return 0;
}