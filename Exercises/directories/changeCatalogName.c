#include <stdio.h>
#include <direct.h>

int main() {
	
	const char *stara_nazwa = "StaryKatalog";
	const char *nowa_nazwa = "NowaNazwaKatalogu";
		

    if (rename(stara_nazwa, nowa_nazwa) == 0) {
        printf("Zmiana nazwy katalogu z \"%s\" na \"%s\" pomy�lna.\n", stara_nazwa, nowa_nazwa);
    } else {
        printf("B��d podczas zmiany nazwy katalogu z \"%s\" na \"%s\".\n", stara_nazwa, nowa_nazwa);
        perror("B��d");
        return 1;
    }

    return 0;
}



