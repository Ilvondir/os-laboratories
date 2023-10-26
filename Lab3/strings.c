#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*                 index
                   | 
         0    1    2    3    4      indexes
str -> ['9']['9']['$'][' ']['\0']
       |         |
       str       ptr                pointers
*/

int indexOf(const char *str, int c) {

//    char *ptr;
//    for (ptr = &str[c]; ptr < str + sizeof(str)/sizeof(str[0]); ptr++) {
//    	
//    	if (*ptr == '$') return (-1)*(str-ptr)/sizeof(str[0]);
//		
//	}

    char *ptr = &str[c];
    while (1 == 1) {
        if (*ptr == '\0') break;
        if (*ptr == '$') return (-1) * (str - ptr) / sizeof(str[0]);
        ptr++;
    }

    return -1;
}

char *identity(const char *name, const char *surname) {

    int name_length = strlen(name);
    int surname_length = strlen(surname);

    int length = name_length + surname_length + 2;

    char *result = (char *) malloc(length);

    char *ptr;
    int i;
    for (ptr = result, i = 0; ptr < result + length; ptr++, i++) {
        if (i < name_length) *ptr = name[i];
        else if (i == name_length) *ptr = ' ';
        else if (i <= name_length + surname_length) *ptr = surname[i - name_length - 1];
        else *ptr = '\0';
    }

    return result;
}

char *login(const char *name, const char *surname) {

    int surname_length = strlen(surname);

    int length = surname_length + 1;

    if (length > 32) length = 32;

    char *login = (char *) malloc(length);

    int i;
    char *ptr;
    for (ptr = login, i = 0; ptr <= login + length; ptr++, i++) {
        if (i == length) {
            *ptr = '\0';
            break;
        }

        if (i == 0) *ptr = name[0];
        else *ptr = surname[i - 1];
    }

    return login;
}

int main(int argc, char *argv[]) {
    printf("strings.c\n\n");

    char str[] = " s sd fsd f$sdfsdfsdfsd dsfs";

    printf("%d", indexOf(str, 5));

    printf("\n\n");

    const char *name = "Michal";
    const char *surname = "Komsa";

    char *result = identity(name, surname);

    printf("Imie i nazwisko: %s", result);

    free(result);

    printf("\n\n");

    char *log = login(name, surname);

    printf("Login: %s", log);

    free(log);

    return 0;
}
