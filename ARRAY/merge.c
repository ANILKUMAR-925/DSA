//program to merge two arrays in a resultant array
#include<stdio.h>
#include<stdlib.h>
int* scan(int* n)
{
    printf("enetr the array size : ");
    scanf("%d",n);
    int* arr=(int*)malloc((*n)*sizeof(int));
    int i;
    printf("enter the array elmeents in sorted manners : ");
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
int* merging(int* arr1,int* arr2,int n1,int n2,int* n3)
{
    *n3=n1+n2;
    int* res=(int*)malloc((*n3)*sizeof(int));
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
            res[k++]=arr1[i++];
        else
            res[k++]=arr2[j++];
    }
    while(i<n1)
        res[k++]=arr1[i++];
    while(j<n2)
        res[k++]=arr2[j++];
    return res;
}
int main()
{
    int n1,n2,n3;
    int* arr1=scan(&n1);
    int* arr2=scan(&n2);
    int* res=merging(arr1,arr2,n1,n2,&n3);
    printf("resultant array is : ");
    display(res,n3);
    return 0;
}