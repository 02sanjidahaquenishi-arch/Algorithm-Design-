#include<stdio.h>
int main()
{
    int n;
    printf("Enter the index of fib series:");
    scanf("%d", &n);
    int fib[n+1];
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<=n;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    printf("\n fib number at your wanted index: %d \n",fib[n]);
    for(int i=0;i<=n;i++)
    {
        printf(" %d ",fib[i]);
    }
}