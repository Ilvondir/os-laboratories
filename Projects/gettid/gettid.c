#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

/*
Aby doinstalowac biblioteki 32-bitowe do maszyny
z zajec nalezy przed kompilacja programu wykonac polecenie:

	sudo apt-get install gcc-multilib
	
Kompilacja:

	gcc -m32 -o gettid gettid.c
*/

int main() {
	
    int tid = syscall(SYS_gettid);

    printf("ID obecnego watku: %d\n", tid);
    
    return 0;
}
