#include<stdio.h>

int main() {
	
	int status;
	
	status = rename("file.txt", "renamed.txt");
	
	if (status == 0) printf("File renamed successfully!");
	else printf("Error: unable to rename the file");	
	
	return 0;
}
