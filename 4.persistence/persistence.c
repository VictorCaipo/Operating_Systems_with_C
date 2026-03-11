#include <stdio.h>//input output
#include <unistd.h>//acceso a llamadas al sistema de unix/linux
#include <assert.h>//verificar condiciones en tiempo de ejecucion
#include <fcntl.h>//control de archivos
#include <sys/types.h>//define tipos de datos del sistema usados en llamadas al sistema
#include <sys/stat.h>

/*
The program muestra como mover datos de la memoria a el disco

"fd" is a number called file descriptor, that has a specific meaning

El programa no escribe al disco directamente, pasa por el kernel siempre,
las funciones que usa son system calls (open, write and close).

*/

int main(int argc, char *argv[]){

    int fd = open("/tmp/file",O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU);
    /*
    abrir o crear archivos
    open(ruta del archivo,argumentos,permisos del usuario)
    la funcion devuelve numero entero si funciona, -1 si hay error
    */
    assert(fd>-1);//continua el programa si fd es mayor a -1
    int rc = write(fd, "hello world\n",12);
    /*
    escribir bytes en un archivo
    write(descriptor del archivo, texto a escribir, numero de bytes)
    */
    assert(rc == 12);//confirma que se escribieron todos los bytes
    close(fd);//cierra archivo, libera recursos, asegura que datos se guarden correctamente
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