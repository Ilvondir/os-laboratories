#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int losuj(int a, int b) {
    return a + rand() % (b - a);
}

// [a-zA-Z0-9./]

/*
a  b
oooo
4567

Liczba kropek = b - a + 1 => 7 - 4 + 1 = 4
*/

int wariacje1() {
    int one = ('z' - 'a' + 1) + ('Z' - 'A' + 1) + ('9' - '0' + 1) + 1 + 1;
    int two = one*one;
    
    return two;
}

int match(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '.') || (c == '/');
}

int wariacje2() {
    int counter = 0;

    int i, j;
    for (i=0;i<256;i++) {
        for (j=0;j<256;j++) {
            if (match(i) && match(j)) counter++;
        }
    }

    return counter;
}

void set(char salt[2]) {
    int one = ('z' - 'a' + 1) + ('Z' - 'A' + 1) + ('9' - '0' + 1) + 1 + 1;
    
    char tab[one];
    
    int i = 0;
    int j;
    
    for (j = 'a'; j <= 'z'; j++) {
        tab[i] = j;
        i++;
    }
    
    for (j = 'A'; j <= 'Z'; j++) {
        tab[i] = j;
        i++;
    }
    
    for (j = '0'; j <= '9'; j++) {
        tab[i] = j;
        i++;
    }
    
    tab[i++] = '.';
    tab[i] = '/';
    
    salt[0] = tab[losuj(0, one+1)];
    salt[1] = tab[losuj(0, one+1)];
}

void errnoExample() {
    const char name[] = "file1.txt";
    
    FILE *fp = fopen(name, "r");
    
    if (fp == NULL) {
        int errno_ = errno;
       
        printf("errno = %d\n\n", errno_);
       
        printf("%s: %s\n", name, strerror(errno_));
    }
    else fclose(fp);
}

void perrorExample() {
    const char name[] = "file1.txt";
    
    FILE *fp = fopen(name, "r");
    
    if (fp == NULL) {
        perror(name);
    }
    else fclose(fp);
}

int main(int argc, char *argv[]) {
    printf("misc.c\n\n");
    
    printf("RAND_MAX = %d\n\n", RAND_MAX);
    
    time_t t;
    srand((unsigned) time(&t));
    
    int a = 13;
    int b = 15;
    
    int liczbaLosowan = 5;
    
    // losuj test
    int i;
    for (i=0;i<liczbaLosowan;i++) {
        printf("losuj(%d, %d) = %d\n", a, b, losuj(a, b));
    }
    
    printf("\n");
    
    // wariacje1 test
    printf("wariacje1() = %d\n", wariacje1()); 
    
    printf("\n");

    // wariacje2 test
    printf("wariacje2() = %d\n", wariacje2()); 
    
    printf("\n");
    
    // set test 
    char salt[2];
    
    for (i=0;i<liczbaLosowan;i++) {
        set(salt);
        printf("salt[2] = \"%c%c\"\n", salt[0], salt[1]);
    }
    
    printf("\n");
    
    // errnoExample test
    errnoExample();

    // perrorExample test
    perrorExample();

    return 0;
}
