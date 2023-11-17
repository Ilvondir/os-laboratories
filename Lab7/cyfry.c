#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int cyfry1(int number) {
    if (number == 0) return 1;
    return ceil(log10(abs(number)));
} 

int cyfry2(int number) {
    return snprintf(NULL, 0, "%d", abs(number));
}

int cyfry3(int number) {
    int counter = 0;

    number = abs(number);

    do {
        number = (number - (number % 10)) / 10;
        counter++;
    } while (number != 0);

    return counter;
}

int main(int argc, char *argv[]) {
    printf("cyfry.c\n\n");
    
    int number = -1240;
    
    printf("cyfry1(%d) = %d\n", number, cyfry1(number));
    printf("cyfry2(%d) = %d\n", number, cyfry2(number));
    printf("cyfry3(%d) = %d\n", number, cyfry3(number));

    return 0;
}
