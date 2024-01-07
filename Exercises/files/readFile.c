#include<stdio.h>

int main() {
	
	FILE *file_descriptor = fopen("file.txt", "r");
	
	if (file_descriptor == NULL) {
    	perror("File opening error");
	}
	else {
		
		char line[1200 + 1];

    	while (fgets(line, sizeof(line), file_descriptor) != NULL) {
			printf("%s", line);
		}		
		
		fclose(file_descriptor);		
	}
	
	return 0;
}
