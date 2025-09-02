#include <stdio.h>


int fib1(int n){
    if (n < 2){
        return n;
    }else{
        return fib1(n-1) + fib1(n-2);
    }


}


int main(){
    int y;
    printf("Input a value: ");
    scanf(" %d", &y);
    int x = fib1(y);

    printf("FIB1 value : %d\n", x);
}