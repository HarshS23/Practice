#include <iostream>
using namespace std; 

// compilation code: clang++ -std=gnu++14 practice.cpp -o practice 
// run: ./practice 
int main(){
    // static memory - Stack memory (allocated at build/compile time)
    // dynamic memory - heap memory/free store (allocated at run time), need to be cleaned up 
    // heap is larger than stack and is used when you dont know how much memory you need ahead of time 


    // Stack memory allocations
    int savings; // created on the stack 
    savings = 1000; // currently stored in the stack 
    cout << &savings << " " << savings << endl;


    // Heap memory allocation 
    // new is a key word that allocates memory on the heap
    int* savingPtr = new int;  //Created on the heap with new keyword 
    // savingPrt stored on the stack, but the memory address it is pointing too is created on the heap 
    *savingPtr = 50000;
    cout << savingPtr << " " << *savingPtr << endl;


    std::cout << "Hello World" << std::endl;

    delete savingPtr;



}