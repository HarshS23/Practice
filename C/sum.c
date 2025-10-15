#include<stdio.h>

int sum_array(int A[], int n);
int printReverseOrder(int A[], int n);

int main(void){

    int array[5] ={1,1,2,3,4};
    int x = sum_array(array, 5); 
    printReverseOrder(array, 5);
    //printf("The sum is : %d\n", x);

    return 0; 
}

int printReverseOrder(int A[], int n){ 

    for(int i = n; i > 0 ; i--){ 

        printf("Here is the index: %d\n", i);

    }
}

int sum_array(int A[], int n){

    int sum = 0;

    for(int i = 0; i < n; i++){
        sum = sum + A[i];
    }

    return sum;
}

/* 

    if(A[i] == 4 && (array_len == 13 || array_len = 16)){
        return a0 = 4 (Visa)
    }
    else if(A[i] == 5 || (A[i + 1] == 1 || A[i + 1] == 2|| A[i + 1] == 4 || ) && a1 = 16 ){
        return a0 = 5 (MasterCard)
    }
    else if ( A[i] == 3 && 300 <= A[i] <= 305){
        return a0 = 3 (Diner's club)
    }
    else{
        return a0 = 0
    }


*/