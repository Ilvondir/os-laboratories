#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("version.c\n\n");

    #ifdef linux
    	  system("ldd ./version");
          system("ldconfig -p | grep libc.so");
    #endif

    return 0;
}
