#include <stdlib.h>
#include <stdio.h>

void printChars(FILE *fp) {
    char c;
    
    while ((c = getc(fp)) != EOF) printf("%c", c);
}

void printLines(FILE *fp) {
    char line[1200 + 1]; // Maksymaklna d³ugoœæ linii w notatniku

    while (fgets(line, sizeof(line), fp) != NULL) printf("%s", line);
}

void copy(const char *addr1, const char *addr2) {
	FILE *fp = fopen(addr1, "r");
	FILE *fpc = fopen(addr2, "w+");
        
    if (fp == NULL || fpc == NULL) {
        
        if (fp == NULL) perror(addr1); 
        if (fpc == NULL) perror(addr2); 
        
	} 
	else {
		char line[1200 + 1];
	
	    while (fgets(line, sizeof(line), fp) != NULL) {
	    	fprintf(fpc, line);
		};
		
		fclose(fp);
		fclose(fpc);
	}

}

int main (int argc, char *argv[]) {
    printf("files.c\n\n");
    
    const char name1[] = "files.txt";
    const char name2[] = "copied.txt";
    
	copy(name1, name2);
    
//    printChars(fp);
//    
//    printf("\n\n");
//    
//    rewind(fp);
//    printLines(fp);

    return 0;
}
