#include <stdio.h>
#include <direct.h>

int main() {
    char *nazwa_katalogu = "NowyKatalog";

    if (mkdir(nazwa_katalogu) == 0) {
        printf("Katalog \"%s\" utworzony pomy�lnie.\n", nazwa_katalogu);
    } else {
        printf("B��d podczas tworzenia katalogu \"%s\".\n", nazwa_katalogu);
        perror("B��d");
        return 1;
    }

    return 0;
}




