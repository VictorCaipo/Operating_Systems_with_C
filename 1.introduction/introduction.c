/*The OSE is a body of sotware that makes sure the system operates correctly and efficientlly*/
/*The OS use virtualization that means transform a resource into a more general, powerful, and easy to use virtual form of itself*/
/*The OS is known as a resource manager, because it manage resources (CPU, memory and disk) with many goals in mind*/

#include <stdio.h>
#include <stdlib.h>//interactua con el sistema operativo malloc() y free() libreria estandar
#include <sys/time.h>//interactua sistemas tipo linux, mide el tiempo con alta precision, no es libreria estandar
#include <assert.h>//herramienta de diagnostico de programador, verifica que las cosas sean como deberian ser, libreria estandar
#include "common.h"//libreria propia del programador

int main (int argc, char *argv[]){
    if (argc != 2) {
        fprintf(stderr, "usage: cpu <string>\n");//stdio
        exit(1);//stdlib
    }
    char *str = argv[1];
    while (1) {

        Spin(1);//common
        printf("%s\n", str);//stdio
    }
    return 0;
}