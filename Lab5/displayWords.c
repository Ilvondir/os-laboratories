#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printWords(FILE *fp) {
    char line[1200 + 1]; // Maksymaklna d³ugoœæ linii w notatniku
    char delim[] = " \n\t\r\b,";
    char *schowek;
    
    while (fgets(line, sizeof(line), fp) != NULL) {
        schowek = strtok(line, delim);
        
        while(schowek != NULL) {
            printf("%s\n", schowek);
            schowek = strtok(NULL, delim);
        }
    }
}

int main (int argc, char *argv[]) {
    printf("displayWords.c\n\n");
    
    const char name[] = "files.txt";
    
    FILE *fp = fopen(name, "r");
        
    if (fp == NULL) {
        perror(name);
        
        return EXIT_FAILURE;
    }
    
    printWords(fp);
    
    fclose(fp);
    
    return 0;
}
