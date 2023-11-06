#define _XOPEN_SOURCE

#include <stdio.h>
#include <unistd.h>

char *crypt(const char *key, const char *salt);

// Programs using crypt should link to crypt.h using the compiler flag -lcrypt.

int main()
{
    char* password = "passw0rd";

    char* encrypted = crypt(password, "cd");

    printf("p: %s\n", password);
    printf("e: %s\n", encrypted);

    return 0;
}

// gcc -o crypt-xopen crypt-xopen.c -lcrypt
