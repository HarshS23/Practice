#include <stdio.h>


int fib1(int n){
    if (n < 2){
        return n;
    }else{
        return fib1(n-1) + fib1(n-2);
    }


}

int fib2(int n){
    int F[] = {0,1};

    for(int i = 3 ; i < n+1; i++){ 
        F[i] = F[i-2] + F[i - 3];
    }
    return F[n + 1];


}

int fib3(int n){
    if (n = 0) return 0; 
    int x = 0;
    int y = 1;

    for(unsigned int k = 2; k < n; k++){
        k = x + y; 
        x = y; 
        y = k; 
    }
    return y;

}


int main(){
    int y;
    printf("Input a value: ");
    scanf(" %d", &y);
    int x = fib1(y);
    int z = fib2(y);

    printf("FIB1 value: %d\n", x);
    printf("FIB2 value: %d\n", z);
}