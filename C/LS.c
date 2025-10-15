#include<stdio.h>

int main(void){
    return 0;
}

int LinearSearch(int A[], int x, int n){
    
    int search = x; 
    for(int i = 0; i < n; i++){
        if(A[i] == search){
            return i;
        }
    }
    return -1;
}

