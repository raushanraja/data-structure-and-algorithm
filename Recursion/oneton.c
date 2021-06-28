#include <stdio.h>

int oneton(int n){
    if(n==1){
        printf("%d ",1); 
        return 0;   
    }
    oneton(n-1);
    printf("%d ",n);
    return 0;

}


int main(){
    int n;
    printf("Enter n\n");
    scanf("%d",&n);
    oneton(n);
    return 0;
}