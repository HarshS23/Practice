#include <stdio.h>


int fib1(int n){
    if (n < 2){
        return n;
    }else{
        return fib1(n-1) + fib1(n-2);
    }


}


int main(){
    int x = fib1(5);

    printf("FIB1 value : %d\n", x);
}