#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n,sum=0,*ptr,i;
    printf("Enter number of elements:");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    if (ptr==NULL)
        {
        printf("Error");
        }
    else
        {
        for(i=0;i<n;i++)
            {
            scanf("%d",ptr+i);
            sum+=*(ptr+i);
            }
        printf("Sum of numbers %d",sum);
        }
        free(ptr);
}