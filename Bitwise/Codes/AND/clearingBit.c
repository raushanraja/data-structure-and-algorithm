#include<stdio.h>

long toBinary(int decimal){
    long binary=0, remainder, multyplyFactor=1;

    while (decimal!=0)
    {
        remainder = decimal %2;
        binary +=  remainder*multyplyFactor;
        multyplyFactor*=10;
        decimal /=2;
    }
     return binary;
}


int main(){
    int numbers=15;
    long binary;
    binary = toBinary(numbers);
    printf("%d into binary is %ld\n",numbers,binary);
    return 0;
}


