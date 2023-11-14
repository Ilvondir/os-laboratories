#include <stdio.h>
#include <unistd.h>

int main() {
	printf("getppid.c\n\n");
	
	printf("ID procesu mojego rodzica to: %d.\n", getppid());
  
	return 0;
}

// Kompilacja: gcc -m64 -no-pie getppid getppid.c
