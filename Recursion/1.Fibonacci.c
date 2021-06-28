#include<stdio.h>

int fibo(int n){
// Base Cases

    if (n==0)
        return 0;
    if (n==1 || n==2)
        return 1;
// Recursive Part
    return fibo(n-1)+fibo(n-2);
}


int main(){
    int n;
    printf("Enter the number of terms to find sum of first n fibonacci numbers:\n");
    scanf("%d",&n);
    printf("%d\n", fibo(n));
    return 0;
}