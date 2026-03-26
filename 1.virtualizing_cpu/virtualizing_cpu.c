/*
The OSE is a body of sotware that makes sure the system operates 
correctly and efficientlly
The OS use virtualization that means transform a resource into a more 
general, powerful, and easy to use virtual form of itself
The OS is known as a resource manager, because it manage resources (CPU,
memory and disk) with many goals in mind
*/

#include <stdio.h>//
#include <stdlib.h>//dynamic memory
#include <time.h>
/*
We are showing virtualization. We are creating 4 tasks that should be
running at the same time. Can they do that?
*/
void spin(int seconds);

int main (int argc, char *argv[]){
    if (argc != 2) {
        /*
        This program allow two arguments, the program's name count
        as an argument
        */
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }

    char *str = argv[1];
    while (1) {
        spin(1);
        printf("%s\n", str);//stdio.h, %s to print strings
    }
    return 0;
    //to stop the program press ctrl+c
}

void spin(int seconds) {
    time_t start = time(NULL);
    while (time(NULL) - start < seconds) {
        //this functions just consume time
    }
}