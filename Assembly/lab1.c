#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// airline = 1 
// airline & financials = 2 
// Banking & financials (Diner's club) = 3 
// Banking & financials (Visa) = 4 
// Banking & financials (MasterCard) = 5
// Merchandising & financials (discover) = 6 

// assignment: determine if its a valid credit card number or not , if its valid then determine if then determine 
// what type of card it is 

const char* creditValid(long long num){

    int array[16]; 
    int count = 0;

    while (num > 0){
        array[count++] = num % 10; 
        num /= 10;
    }

    for(int i = 0; i < count / 2; i++){

        int temp = array[i]; 
        array[i] = array[count - i - 1]; 
        array[count - i - 1] = temp;

    }

    int first = array[0];
    switch(first){
        case 1: return "Airline"; 
        case 2: return "Airline & Financials"; 
        case 3: return "Banking & financials (Diner's club)";
        case 4: return "Banking & financials (Visa)";
        case 5: return "Banking & financials (MasterCard)";
        case 6: return "Merchandising & financials (Discover)";
        default: return "ERROR";
    }
}


int main(){

    long long x = 9234567890123456;
    const char* num = creditValid(x);
    printf("%s\n", num);                
    return 0;
}

