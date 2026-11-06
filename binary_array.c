#include<stdio.h>
int main()
{
    int n,search;
    printf("Enter array size :");
    scanf("%d",&n);
    int  a[n];
    printf("Enter array elemrnt :");
    for (int i=0;i<n;i++)
    {
    scanf("%d", &a[i]);
    }

    for (int i=0; i<n-1; i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                 int temp=a[j];
                 a[j]=a[j+1];
                 a[j+1]=temp;

            }
        }
    }
    printf("Sorted array element : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }



printf("\nEnter number to search :");
scanf("%d",&search);
int low=0;
int high = n-1;
int found=0;
while(low<= high)
{
    int mid =( low+high)/2 ;
    if(a[mid]== search)
    {
        printf("Number found at index %d \n",mid);
        found=1;
        break;

    }
    else if ( search>a[mid])
    {
        low= mid +1;

    }
    else {
        high = mid -1;
    }
}
    if (found ==0)
    {
        printf("Number not found \n");
    }
return 0;


}