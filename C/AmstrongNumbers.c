#include <stdio.h>
int main() {
    int n, inputNum, remainder, result = 0;
    printf("Enter an integer: ");
    scanf("%d", &n);
    inputNum = n;

    while (inputNum != 0) {
       remainder = inputNum % 10; 
       result += remainder * remainder * remainder;
       inputNum /= 10;
    }

    if (result == n)
        printf("This is Armstrong number");
    else
        printf("This is not Armstrong number");

    return 0;
}