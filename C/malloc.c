#include <stdio.h>
#include <stdlib.h>

// malloc (memory allocation) allocates memory in the heap, it will take the number of bytes you want allocate those bytes  
// on the heap and will return a pointer to those bytes. 
// since malloc doesnt know the TYPE of the pointer you may need to cast the type to malloc in c and c++ 
// ex C language: int *p = malloc(sizeof(int));
// ex C++ language: int *p = (int*)malloc(sizeof(int));

// if you try to allocate more memory than you have avaliable malloc will return null 
// therefore it is good practice to 
// free(ptr);
// ptr = Null;

int DynamicMemoryAllocation(void);

int main(){

    DynamicMemoryAllocation();
    return 0;
}

int DynamicMemoryAllocation(void){

    int number = 0; 
    printf("Enter how many grades youd like to enter: ");
    scanf("%d", &number);

    char *grades = malloc(number * sizeof(char));
    // if malloc fails it returns a null and we should check for that failure 
    if(grades == NULL){
        printf("ERROR: Malloc failed to allocate memory\n"); 
        return 1;
    }

    for(int i = 0; i < number ; i++){ 
        printf("Enter grades number #%d: ", i+1); 
        scanf(" %c", &grades[i]);
    }

    for(int i = 0; i < number; i++){
        printf("Grades[%d] : %c\n", i + 1, grades[i]);
    }

    free(grades);
    grades = NULL;

    return 0;
}