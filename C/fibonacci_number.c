//program to find the nth fibonacci number
#include<stdio.h>
int fib(int m);
int main(){
    int n;
    printf("Enter the nth number\n");
    scanf("%d",&n);
    printf("%dth fibonacci number is ",n);
    printf("%d",fib(n));
    return 0;
}
//recursive function used
int fib(int m){
    if(m==1){
        return 0;
    }if(m==2){
        return 1;
    }
    return (fib(m-1)+fib(m-2));
}
