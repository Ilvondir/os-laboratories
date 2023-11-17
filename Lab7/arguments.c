#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("arguments.c\n\n");
    
    printf("argc = %d\n\n", argc);
    
    printf("addr: %s\n\n", argv[0]);
    
    #ifdef linux
    	char delim = '/';
    #else
    	char delim = '\\';
    #endif
    
    char *last = strrchr(argv[0], delim);
    
    printf("name: %s\n\n", last+1);
    
    printf("params: ");
    
    int i;
    for (i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    
    printf("\n\n");

    return 0;
}
