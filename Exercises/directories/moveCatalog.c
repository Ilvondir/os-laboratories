#include <stdio.h>
#include <windows.h>

int main() {
    const char *zrodlo = "C:\\Sciezka\\Do\\Zrodla";
    const char *docel = "C:\\Sciezka\\Do\\Docelowej";

    if (MoveFile(zrodlo, docel)) {
        printf("Przeniesienie zakoñczone pomyœlnie.\n");
    } else {
        printf("B³¹d podczas przenoszenia katalogu.\n");
        perror("B³¹d");
        return 1;
    }

    return 0;
}



