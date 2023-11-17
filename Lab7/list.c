#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("list.c\n\n");
    
    int length = 0;
    
    int i;
    for (i = 1; i < argc; i++) {
        length += strlen(argv[i]) + 1;
    }
    
    // "ls"
    // "dir"
    char buffor[length + 3 + 1];
    
    #ifdef linux
       strcpy(buffor, "ls");
    #else
       strcpy(buffor, "dir");
    #endif
    
    for (i = 1; i < argc; i++) {
        strcat(buffor, " ");
        strcat(buffor, argv[i]);
    }
    
    system(buffor);

    return 0;
}
