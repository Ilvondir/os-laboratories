#include <stdio.h>
#include <windows.h>

int main() {
    const char *zrodlo = "C:\\Sciezka\\Do\\Zrodla";
    const char *docel = "C:\\Sciezka\\Do\\Docelowej";

    if (MoveFile(zrodlo, docel)) {
        printf("Przeniesienie zako�czone pomy�lnie.\n");
    } else {
        printf("B��d podczas przenoszenia katalogu.\n");
        perror("B��d");
        return 1;
    }

    return 0;
}



