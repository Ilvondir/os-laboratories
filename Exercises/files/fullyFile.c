#include<stdio.h>

int main() {
	
	const char *name = "file.txt";
	
	FILE *file_descriptor = fopen(name, "w");
	
	if (file_descriptor < 0) {
    	perror("File creation error");
	}
	else {
		
		fprintf(file_descriptor, "%s", "Ala ma kota\n");
		fprintf(file_descriptor, "%s", "a kot ma Ale");
		
		fclose(file_descriptor);
	}
	
	return 0;
}
