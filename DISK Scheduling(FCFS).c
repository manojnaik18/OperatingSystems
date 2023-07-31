#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,req[50],mov=0,cp;
    printf("enter current position\n");
    scanf("%d",&cp);
    printf("Enter the number of requests\n");
    scanf("%d",&n);
    printf("Enter the requst order\n");
    for(i=1;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    mov=mov+abs(cp-req[0]);
    printf("%d->%d",cp,req[0]);
    for(i=1;i<n;i++)
    {
        mov=mov+abs(req[i]-req[i-1]);
        printf("->%d",req[i]);
    }
printf("\n");
printf("Total movement=%d\n",mov);
}
