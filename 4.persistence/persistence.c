#include <stdio.h>//input output
#include <unistd.h>//interact unix/linux
#include <assert.h>//verify executions
#include <fcntl.h>//file control
#include <sys/types.h>//define system data types
#include <sys/stat.h>

/*
Program shows how to move data from memory to the disk
"fd" is a number called file descriptor, that has a specific meaning
Program doesn'save data at the disk directly, it go throuhgt Kernel.
*/

int main(int argc, char *argv[]){

    int fd = open("/tmp/file",O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU);
    /*
    open o create files
    open(adress,arguments,credentials)
    it returns a number if it works, -1 if there any mistake
    */
    assert(fd>-1);
    int rc = write(fd, "hello world\n",12);
    /*
    write file
    write(descriptor,text to be write,byte number)
    */
    assert(rc == 12);//confirm all bytes were written
    close(fd);
    return 0;
}

/*
Persistence /pəˈsɪs.təns/ (staying despite great difficulty)
    In a programming context means data that stay after program has finished
    RAM -> temporal
    Disco -> persistente

    0 -> stdin
    1 -> stdout
    2 -> stderr
    3 -> /tmp/file
*/