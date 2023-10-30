#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int countWords1(FILE *fp) {
    int inside = 0;
    int counter = 0;
    char c;
    
    while ((c = getc(fp)) != EOF) {
        
        if (isspace(c)) {
            inside = 0;
            
        } else {
            if (inside == 1) continue;
            else {
                inside = 1;
                counter++;
            }
        }
        
    }
    
    return counter;
}

int countWords2(FILE *fp) {
    int counter = 0;
    char c;
    
    while ((c = getc(fp)) != EOF) {
        if (isspace(c)) counter++;       
    }
    
    return counter+1;
}


int main (int argc, char *argv[]) {
    printf("countWords.c\n\n");
    
    const char name[] = "files.txt";
    
    FILE *fp = fopen(name, "r");
        
    if (fp == NULL) {
        perror(name);
        
        return EXIT_FAILURE;
    }
    
    printf("%d\n", countWords1(fp));
    
    rewind(fp);
    printf("%d", countWords2(fp));
    
    fclose(fp);
    
    return 0;
}
