#include <stdio.h>

int main() {
    FILE *pipe = popen("dir", "r");

    if (!pipe) {
        perror("B³¹d otwarcia potoku");
        return 1;
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        printf("%s", buffer);
    }

    pclose(pipe);

    return 0;
}




