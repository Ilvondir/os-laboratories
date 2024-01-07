#include<stdio.h>

int main() {
	
	int status;
	
	status = rename("file.txt", "moved/file.txt");
	
	if (status == 0) printf("File moved successfully!");
	else printf("Error: unable to move the file");	
	
	return 0;
}
