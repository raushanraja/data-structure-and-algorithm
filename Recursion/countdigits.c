#include <stdio.h>

int cod(int n){
    if(n==0)
        return 0;
    return 1+ cod(n/10);
}


int main(){
    int n;
    printf("Enter n\n");
    scanf("%d",&n);
    printf("%d ",cod(n));
    return 0;
}