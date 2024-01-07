#include <stdio.h>
#include <direct.h>

int main() {
    char *nazwa_katalogu = "DoUsuniecia";

    if (rmdir(nazwa_katalogu) == 0) {
        printf("Usuniêcie katalogu \"%s\" pomyœlne.\n", nazwa_katalogu);
    } else {
        printf("B³¹d podczas usuwania katalogu \"%s\".\n", nazwa_katalogu);
        perror("B³¹d");
        return 1;
    }

    return 0;
}







