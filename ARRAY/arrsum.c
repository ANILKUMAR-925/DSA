//program to find out the esum of the elements of the matrix
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
int findsum(int* arr,int n)
{
    int sum=0,i;
    for(i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    return sum;
}
int main()
{
    int n;
    int* arr=scan(&n);
    int sum=findsum(arr,n);
    printf("sum of the elements of the array is : %d\n",sum);
    return 0;
}