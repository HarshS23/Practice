#include<stdio.h>

int sum_array(int A[], int n);

int main(void){

    int array[5] ={1,1,2,3,4};
    int x = sum_array(array, 5); 
    printf("The sum is : %d\n", x);

    return 0; 
}


int sum_array(int A[], int n){

    int sum = 0;

    for(int i = 0; i < n; i++){
        sum = sum + A[i];
    }

    return sum;
}