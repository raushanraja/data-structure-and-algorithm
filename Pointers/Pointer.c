#include <stdio.h>

int main(){
    int i, *p;
    i=10;
    p=&i;
    printf("i=%d p=%u *p=%d\n",i,p,*p);
    *p=11;
    printf("After setting *p=11\n");
    printf("i=%d p=%u *p=%d\n",i,p,*p);
    return 0;
}