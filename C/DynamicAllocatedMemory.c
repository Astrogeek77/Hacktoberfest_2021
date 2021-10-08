#include<stdio.h>
#include<stdlib.h>

int main()
{   
    int n;
    printf("Enter the size of the memory blocks: ");
    scanf("%d",&n);

    int *ptr = (int *)malloc(n*sizeof(int));

    if (*ptr==NULL)
    {
        printf("Error! Memory cannot be allocated");
        exit(1);
    }
    
    for (int i = 0; i<n ; i++)
    {   
        printf("Enter an integer: ");
        scanf("%d",ptr+i);
    }
    
    printf("Dynamic allocated memory integers are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(ptr+i));
    }
    

return 0;
}
