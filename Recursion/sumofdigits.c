#include <stdio.h>

int sod(int n){
    if(n==0)
        return 0;
    return n%10+sod(n/10);
}
int main(){
    int n;
    printf("Enter n\n");
    scanf("%d",&n);
    printf("%d\n",sod(n));
    return 0;
}