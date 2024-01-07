#include<stdio.h>

int main() {
	
	const char *name = "empty.txt";
	
	FILE *file_descriptor = fopen(name, "w");
	
	if (file_descriptor < 0) {
    	perror("File creation error");
	}
	else {
		printf("File %s created successfully!", name);
		fclose(file_descriptor);
	}
	
	return 0;
}
