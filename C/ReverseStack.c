#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
 
struct Stack
{
    int top;
    int size;
    char* array;
};
 

struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (char*) malloc(size * sizeof(char));
    return stack;
}
 
void push(struct Stack* stack, char item)
{
    if (stack->top == stack->size - 1)
        return;
    stack->array[++stack->top] = item;
}
 

char pop(struct Stack* stack)
{
    if (stack->top == -1){
        return 0;
    }
    return stack->array[stack->top--];
}
 

void reverse(char str[])
{
    int n = strlen(str);
    struct Stack* stack = createStack(n);
 
    
    int i;
    for (i = 0; i < n; i++)
        push(stack, str[i]);
 
    for (i = 0; i < n; i++)
        str[i] = pop(stack);
}
 

int main()
{    
    char str[100];
    printf("Enter a string to be reversed: ");
    scanf("%[^\n]%*c",str);

    printf("Original String is: %s\n",str);
    reverse(str);
    printf("\nReversed string is: %s", str);
 
    return 0;
}
