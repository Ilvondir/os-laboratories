#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("delusers.c\n\n");
    
    const char *name = "baza.txt";
    
    FILE *fp = fopen(name, "r");
    
    if (fp == NULL) {
        perror(name);
        
        return EXIT_FAILURE;
    }
    
    char line[1000];

    while (fgets(line, sizeof(line), fp) != NULL) {
        
        char login[32+1];
        
        char* token = strtok(line, ";");
        
        strncpy(login, token, 1);
        login[1] = '\0';
        
        token = strtok(NULL, ";");
        
        strcat(login, token);
        
        if (strlen(login) > 32) login[32] = '\0';
        
        char command[100] = "sudo userdel -r ";
    	
        strcat(command, login);
        
        system(command);       
    }
    
    fclose(fp);

    return 0;
}

// sudo userdel -r jkowalski
