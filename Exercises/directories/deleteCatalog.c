#include <stdio.h>
#include <direct.h>

int main() {
    char *nazwa_katalogu = "DoUsuniecia";

    if (rmdir(nazwa_katalogu) == 0) {
        printf("Usuni�cie katalogu \"%s\" pomy�lne.\n", nazwa_katalogu);
    } else {
        printf("B��d podczas usuwania katalogu \"%s\".\n", nazwa_katalogu);
        perror("B��d");
        return 1;
    }

    return 0;
}







