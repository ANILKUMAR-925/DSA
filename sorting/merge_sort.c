#include<stdio.h>
#include<stdlib.h>
int* scanarr(int* n)
{
    int i;
    printf("enter size of the array : ");
    scanf("%d",n);
    int* arr=(int*)malloc(sizeof(int));
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
}
void merge(int* arr,int low,int mid,int high)
{
    int i,j,k=low;
    int ptr[100];
    i=low,j=mid+1;
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
            ptr[k++]=arr[i++];
        }
        else
        {
            ptr[k++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        ptr[k++]=arr[i++];
    }
    while(j<=high)
    {
        ptr[k++]=arr[j++];
    }
    //copy the elements to main array
    for(i=0;i<=high;i++)
    {
        arr[i]=ptr[i];
    }
}
void sort(int* arr,int low,int high)
{
    if(low<high)
    {
        //dividing the array into two parts
        int mid=(low+high)/2;
        //sorting the left part of the array
        sort(arr,low,mid);
        //sorting right part of the array
        sort(arr,mid+1,high);
        //merging the two parts in the same array
        merge(arr,low,mid,high);
    }
}
int main()
{
    int *arr,n;
    arr=scanarr(&n);
    printf("array elements before sorting : ");
    display(arr,n);
    sort(arr,0,n-1);
    printf("\narray elements after sorting : ");
    display(arr,n);
    return 0;
}