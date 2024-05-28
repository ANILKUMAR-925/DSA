#include<stdio.h>
#include<stdlib.h>
int* scanarr(int* n)
{
    int i;
    printf("enter the array size : ");
    scanf("%d",n);
    int* arr=(int*)malloc((*n)*sizeof(int));
    printf("enter the array elements : ");
    for(i=0;i<*n;i++)
    {
        scanf("%d",&arr[i]);
    }
    return arr;
}
void display(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int findindex(int arr[],int low,int high)
{
    int key=arr[low];
    int i,j,temp;
    i=low+1;
    j=high;
    do
    {
        //find the element larger than key from left side
        while(arr[i]<key)
        {
            i++;
        }
        //find the element smaller tha the key from right side
        while(arr[j]>key)
        {
            j--;
        }
        //after finding large and small element swap
        if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }while(i<j);
    //swapping the key element to its smaller element and returning the fix index of key
    temp=arr[j];
    arr[j]=arr[low];
    arr[low]=temp;
    return j;
}
void quicks(int arr[],int low,int high)
{
    int index;
    if(low<high)
    {
        //finding the fix index of first element of the array
        index=findindex(arr,low,high);
        //sorting the left side array of the fix index
        quicks(arr,low,index-1);
        //sorting right side array of the fix index
        quicks(arr,index+1,high);
    }
}
int main()
{
    int n;
    int* arr=scanarr(&n);
    printf("array elements before sorting : ");
    display(arr,n);
    quicks(arr,0,n-1);
    printf("\narray elements after sorting : ");
    display(arr,n);
    return 0;
}