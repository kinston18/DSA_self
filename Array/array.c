#include<stdio.h>
#include<conio.h>
int main()
{
    int i,n,arr[20];
    printf("Enter the elements of array:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n arr[%d]= ",i);
        scanf("%d",&arr[i]);
    }
    printf("The array is");
    for ( i = 0; i < n; i++)
    {
    printf("%d",arr[i]);    
    }
    
    return 0;
}
