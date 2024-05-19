#include<stdio.h>
#include<stdlib.h>
int* scan(int* n)
{
    printf("enter the array size : ");
    scanf("%d",n);
    int* arr=(int*)malloc((*n)*sizeof(int));
    printf("enter the array elements : ");
    int i;
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
void heapify(int* arr,int n,int parent)
{
    int lc,rc,largest=parent;
    lc=2*parent+1;//left child
    rc=2*parent+2;//right child
    //find largest among the child
    if(arr[largest]<arr[lc] && lc<n)
    {
        largest=lc;
    }
    if(arr[largest]<arr[rc] && rc<n)
    {
        largest=rc;
    }
    if(parent!=largest)
    {
        //swapping largest child with parent
        int temp=arr[largest];
        arr[largest]=arr[parent];
        arr[parent]=temp;
        heapify(arr,n,largest);
    }
}
void heap_sort(int* arr,int n)
{
    int i;
    for(i=(n/2)-1;i<=0;i--)
    {
        heapify(arr,n,i);
    }
    for(i=n-1;i>=0;i--)
    {
        int temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        heapify(arr,i,0);
    }
}
int main()
{
    int n;
    int* arr=scan(&n);
    printf("array elements before sorting : ");
    display(arr,n);
    heap_sort(arr,n);
    printf("array elements after sorting : ");
    display(arr,n);
    printf("\n");
    return 0;
}