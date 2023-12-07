#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char* argv[]) {
    printf("redirect.c\n\n");
    
    close(1);

    creat("ls.txt", 0600);

    execvp("ls", argv);
}

