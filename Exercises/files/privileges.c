	#include <stdio.h>
	
	int main() {
	    const char *name = "file.txt";
	    int privileges = 555;
	    
	    int status = chmod(name, privileges);
	
	    if (status == 0) {
	        printf("The permissions have been changed.");
	    } else {
	        perror("Chmod function error");
	    }
	    
	    return 0;
	}
	
	
