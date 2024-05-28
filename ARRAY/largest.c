//program to find out the largest elements of the matrix
#include<stdio.h>
#include<stdlib.h>
int* scan(int *n)
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
int findlarge(int* arr,int n)
{
    int largest=arr[0],i;
    for(i=1;i<n;i++)
    {
        if(largest<arr[i])
            largest=arr[i];
    }
    return largest;
}
int main()
{
    int n;
    int* arr=scan(&n);
    int largest=findlarge(arr,n);
    printf("largest element of the array is : %d\n",largest);
    return 0;
}