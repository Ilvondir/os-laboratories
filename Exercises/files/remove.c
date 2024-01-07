#include<stdio.h>

int main() {
	
	int status;
	
	status = remove("file.txt");
	
	if (status == 0) printf("File removed successfully!");
	else printf("Error: unable to remove the file");	
	
	return 0;
}
