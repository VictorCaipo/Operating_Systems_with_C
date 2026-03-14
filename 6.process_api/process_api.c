#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
fork() = hijo->0 ; padre->PID del hijo; error->-1
El programa crea un proceso hijo, luego hace que este proceso hijo
ejecuta otro programa con la funcion excvp(), importante saber
que los dos procesos se crean a la vez y por lo tanto ls siempre
se ejecutara
*/

int main(void){

    printf("Proceso inicial PID: %d\n", getpid());

    int rc = fork();

    if (rc < 0){
        printf("Error al crear proceso");
        exit(1);
    }
    if (rc == 0){
        printf("Soy el hijo PID: %d\n", getpid());

        char *args[] = {"ls", "-l", NULL};

        execvp(args[0], args);
        
        printf("Esto no deberia imprimirse\n");
    }
    else{
        wait(NULL);//el padre espera a que el hijo termine

        printf("Soy el padre PID: %d\n", getpid());
        printf("El hijo termino\n");
    }


    return 0;
}

/*
Los sitemas UNIX crean y controlan procesos usando 3 llamadas 
principales fork, exec, y wait. Cada proceso tiene un identificador 
unico.
fork() 
    crea un proceso casi identico al proceso padre, retorna un valor 
    para saber en que proceso nos encontramos

    El proceso padre e hijo pueden ejecutarse en cualquier orden, esto 
depende del scheduler del CPU

wait()
    permite que el proceso padre espera a que el hijo termine, este
    se usa cuando el padre se bloquea

exec() 
    remplaza el programa actual por otro programa, es decir se carga
    un nuevo ejecutable y remplaza completamente el proceso actual

Un shell (como bash) usa este patron, fork(crea un hijo), exec(el
hijo ejecuta un comando), wait(el padre espera que termine)

Los procesos pueden recibir signals para controlarlos SIGINT (term
inar el proceso) SIGTSTP (pausar el proceso)

*/