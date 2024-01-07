#include <stdio.h>

int main() {
	FILE *existed_file, *new_file;
	char bufor[1024];
	
	existed_file = fopen("file.txt", "r");
	new_file = fopen("copied.txt", "w");
	
	if (existed_file == NULL || new_file == NULL) {
		perror("File error");
	}
	
	char line[1200+1];
	
	while (fgets(line, sizeof(line), existed_file) != NULL) {
		fprintf(new_file, "%s", line);
	}
	
	fclose(existed_file);
	fclose(new_file);
	
	return 0;
}
