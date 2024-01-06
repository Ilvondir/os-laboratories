#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>

int main(int argc, char *argv[]) {
	
	if (argc == 1 || argc > 2) {
		printf("One parameter expected!\n");
		return 1;
	}
	
	int len = strlen(argv[1]);
	
	int i;
	for (i = 0; i < len; i++) {
		if (!isdigit(argv[1][i])) {
			printf("Parameter must be a number!\n");
			return 1;
		}
	}
	
	printf("Parameter (process id): %s\n", argv[1]);
	
	pid_t process_id = atoi(argv[1]);
	
	char command[50] = "ps -p ";
	strcat(command, argv[1]);
	strcat(command,  " -o comm=");
	
	FILE *pipe = popen(command, "r");
	
	char process_name[100];
	
	fgets(process_name, 100, pipe);
	
	fclose(pipe);
	
	if (strlen(process_name) == 0) {
		printf("There is no process with id %s.\n", argv[1]);
		return 1;
	}
	else {
		process_name[strlen(process_name) - 1] = '\0';
		
		int status = kill(process_id, 9);
		
		if (status == 0) printf("Process %s killed successfuly!\n", process_name);
		else printf("Process %s was not killed. \nRemember about 'sudo' :)\n", process_name);
	}
	
	return 0;
}

/*
	Michal Komsa
		gcc -m64 -o kill kill.c
*/
