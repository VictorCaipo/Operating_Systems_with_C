/* Definition:
Concurrency: We use this conceptual term to refer to problems that
arise because of concurrency.
Thread: Minimum unity of process that an OS execute. A thread is part
of a process.
*/

/* Working:
We are executing two threads at the same time, each of them work over the
the 'worker' function (a routine). Each thread increment the loop variable
depending on the argv argument, so if the input is 100 the ouput shall be
200. However, when the argv argument is over 10000, our program get broken.
The output now is 15480. Why? It is because of the instruction's behavior
when being executed.
*/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"

volatile int counter = 0;
int loops;

void *worker(void *arg){
    for(int i = 0; i<loops; i++){
        counter++;
    }
    return NULL;
}

int main (int argc, char *argv[]){
    if (argc != 2){
        fprintf(stderr, "usage: threads <value>\n");
        //stderr: stream of error
        //the second argument is the message
        exit(1);
    }
    loops = atoi(argv[1]);
    //convert a string to a int

    pthread_t p1, p2;

    printf("Initial value: %d \n", counter);

    Pthread_create(&p1, NULL, worker, NULL);
    //creates a new thread 
    //(identificator,atributs,function to be executed,arguments)
    Pthread_create(&p2, NULL, worker, NULL);
    Pthread_join(p1, NULL);
    //waiting thread to be finished
    //(thread to be finished, returned value)
    Pthread_join(p2, NULL);
    
    printf("Final value: %d\n", counter);
    return 0;

}
/*
English:
    concurrently: at the same time /kənˈkʌr.ənt.li/ <The two events happened concurrently>
Estructura de compilacion:
    gcc concurrency.c -o concurrency -pthread
*/