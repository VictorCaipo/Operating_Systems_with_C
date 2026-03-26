#include <unistd.h>//OS functions
#include <stdio.h>
#include <stdlib.h>//dynamic memory
#include <assert.h>//to detect mistakes
#include <time.h>
/*
A process is a program running with many permissions
*/
void spin(int seconds);

int main(int argc, char *argv[]){
    /*
    malloc request memory from the heap, it return a pointer to that
    adress.
    */    
    int *p = malloc(sizeof(int));
    assert(p != NULL);//Program continues if malloc works

    printf(" (%d) address of p: %p \n", getpid(), (void*)p );
    *p = 0;
    while(1) {
        spin(1);
        *p = *p + 1;
        printf(" (%d) p: %d \n", getpid(), *p);
    }
    /*
    %d decimal 
    %08x hexadecimal, fill with zeros
    8 character
    */
    return 0;
}

void spin(int seconds) {
    time_t start = time(NULL);
    while (time(NULL) - start < seconds) {
        //just consume time
    }
}
/*
When running the program many times, we notice the same adress is
repeated for different process.

This occurs because every process have a different virtual memory. OS
assign memory for each process.
*/