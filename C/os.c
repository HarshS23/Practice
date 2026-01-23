#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// int main(int argc, char *argv[]){

//     printf("Hello world (PID: %d)\n", (int) getpid()); // we make a proccess here 
//     int rc = fork();   // we fork it (duplicate it), rc = the return value of fork()
//     if (rc < 0){
//         fprintf(stderr, "Fork failed\n"); // if fork failes print for failed
//         exit(1); // exit 
//     } else if (rc == 0){
//         printf("Child Process (PID: %d)\n", (int) getpid()); // if the return value of the fork == 0 --> it is a child process 
//     }else{
//         printf("Parent Process (PID: %d)\n", (int) getpid()); // else it is the parent process 
//     }

//     return 0;
// }


int main(int argc, char *argv[]){

    printf("Hello world (PID: %d)\n", (int) getpid()); // we make a proccess here 
    int rc = fork();   // we fork it (duplicate it), rc = the return value of fork()
    if (rc < 0){
        fprintf(stderr, "Fork failed\n"); // if fork failes print for failed
        exit(1); // exit 
    } else if (rc == 0){
        printf("Child Process (PID: %d)\n", (int) getpid()); // if the return value of the fork == 0 --> it is a child process 
    }else{
        int wc = wait(NULL);
        printf("hello, I am parent of %d (WC: %d) (PID: %d)\n", rc, wc, (int) getpid());
        // Parent process is waiting on child process to finish 
    }

    return 0;
}


