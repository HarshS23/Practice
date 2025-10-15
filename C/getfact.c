#include <stdio.h> 

int main(){
    int s = 1; 
    for(int j = 2; j < 5; j++){
        s = s * j;
    }
    printf("Factorial is: %d\n", s);
    return 0;
}