#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <crypt.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    printf("addusers.c\n\n");
    
    const char *name = "baza.txt";
    
    FILE *fp = fopen(name, "r");
    
    if (fp == NULL) {
        perror(name);
        
        return EXIT_FAILURE;
    }
    
    char line[1000];
    
    struct crypt_data data;
    data.initialized = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        
        char login[32+1];
        char fullName[50+1];
        char password[8+1];
        
        char* token = strtok(line, ";");
        
        strncpy(login, token, 1);
        login[1] = '\0';
        
        strcpy(fullName, token);
        strcat(fullName, " ");
        
        token = strtok(NULL, ";");
        
        strcat(login, token);
        
        if (strlen(login) > 32) login[32] = '\0';
        
        strcat(fullName, token);
        
        token = strtok(NULL, ";");
        
        int n = strlen(token); 
        
        /*
        windows\r\n
        linux\n        
        */
        
        if (token[n-2] == '\r') {
            token[n-2] = '\0';
        } else 
            token[n-1] = '\0';
        
        if (strlen(token) > 8) token[8] = '\0';
        
        strcpy(password, token);
    
        char* encrypted = crypt_r(password, "cd", &data);
        
        char command[100] = "sudo useradd -m -p ";
        
        strcat(command, encrypted);
        strcat(command, " -c \"");
        strcat(command, fullName);
        strcat(command, "\" -s /bin/bash -g student ");
        strcat(command, login);
        
        system(command);       
    }
    
    fclose(fp);

    return 0;
}

// useradd -m -p [encrypted] -c "Jan Kowalski" -s /bin/bash -g student jkowalski
