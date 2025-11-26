#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n,sum=0,*ptr,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    ptr=(int*)calloc(n,sizeof(int));
    if (ptr==NULL)
        {
        printf("Error");
        }
    else
        {
        printf("Enter the elements: ");
        for(i=0;i<n;i++)
            {
            scanf("%d",ptr+i);
            sum+=*(ptr+i);
            }
        printf("Sum is %d",sum);
        }
        free(ptr);
}
