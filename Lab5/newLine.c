#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printHex(FILE *fp) {
    char c;
    
    while ((c = getc(fp)) != EOF) {
        printf("%.2X ", c);
    }
}

void printLinesHex(FILE *fp) {
    char line[1200 + 1]; // Maksymaklna d³ugoœæ linii w notatniku

    while (fgets(line, sizeof(line), fp) != NULL) {
        char c;
        int i = 0;
        
        while (c = line[i++]) printf("%.2X ", c);
        
        printf("\n");
    }
}

void printChar(FILE *fp) {
    char c;
    
    while ((c = getc(fp)) != EOF) {
        if (c == '\t') printf("\'\\t\' ");
        else if (c == '\n') printf("\'\\n\' ");
        else if (c == '\r') printf("\'\\r\' ");
        else printf("\'%c\' ", c);
    }
}

void printLinesChar(FILE *fp) {
    char line[1200 + 1]; 
    while (fgets(line, sizeof(line), fp) != NULL) {
        char c;
        int i = 0;
        
        while (c = line[i++]) {
            if (c == '\t') printf("\'\\t\' ");
            else if (c == '\n') printf("\'\\n\'\n");
            else if (c == '\r') printf("\'\\r\' ");
            else printf("\'%c\' ", c);
        };
    }
}


int main (int argc, char *argv[]) {
    printf("newLine.c\n\n");
    
    const char name1[] = "linux.txt";
    const char name2[] = "windows.txt";
    const char *name;
    
    printf("1 %s\n", name1);
    printf("2 %s\n\n", name2);
    printf("Choose file: ");
    
    char number = getchar();
    
    if (number == '1') name = name1;
    else if (number == '2') name = name2;
    else {
        printf("\nChoose file 1 or 2.\n");
        return -1;
    }
    
    FILE *fp = fopen(name, "r");
        
    if (fp == NULL) {
        perror(name);
        
        return EXIT_FAILURE;
    }
    
    printf("\n%s\n\n", name);
    
    printHex(fp); printf("\n\n");
    
    rewind(fp);
    printChar(fp); printf("\n\n");
    
    rewind(fp);
    printLinesHex(fp); printf("\n");
    
    rewind(fp);
    printLinesChar(fp); printf("\n\n");
           
    fclose(fp);
    
    return 0;
}
