#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int cyfry(int number) {
    return snprintf(NULL, 0, "%d", abs(number));
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main(int argc, char *argv[]) {
    printf("dodawanie.c\n\n");

    int a, b;

    printf("a = ");
    scanf("%d", &a);

    printf("b = ");
    scanf("%d", &b);

    int aDigits = cyfry(a);
    int bDigits = cyfry(b);

    int digits = max(aDigits, bDigits);

    char tempA[digits], tempB[digits];

    itoa(a, tempA, 10);
    itoa(b, tempB, 10);

    char buforA[digits], buforB[digits];
    char upperLine[digits+1];
    char result[digits+1];
    char hr[digits+2];

    int i = 0;
    for (i=0;i<digits;i++) {
        buforA[i] = '0';
        buforB[i] = '0';
    }
    buforA[digits] = '\0';
    buforB[digits] = '\0';

    if (aDigits == bDigits) {
        itoa(a, buforA, 10);
        itoa(b, buforB, 10);
    }
    else if (aDigits < bDigits) {
        itoa(b, buforB, 10);

        int c = 0;
        for (i=aDigits-1, c=digits-1;i>=0;i--,c--) {
            buforA[c] = tempA[i];
        }

    }
    else {
        itoa(a, buforA, 10);

        int c = 0;
        for (i=bDigits-1, c=digits-1;i>=0;i--,c--) {
            buforB[c] = tempB[i];
        }
    }


    for(i=0;i<=digits;i++) {
        upperLine[i] = '0';
        result[i] = '0';
    }
    upperLine[digits+1] = '\0';
    result[digits+1] = '\0';

    for(i=0;i<=digits+1;i++) hr[i] = '-';
    hr[digits+2] = '\0';

    for(i=digits-1;i>=0;i--) {
        if ((buforA[i]-'0') + (buforB[i]-'0') + (upperLine[i+1]-'0') > 9) upperLine[i] = '1';
    }

    for(i=0;i<digits+1;i++) {
        if (i==0) result[0] = upperLine[0];
        else {
            result[i] = (((buforA[i-1]-'0') + (buforB[i-1]-'0') + (upperLine[i]-'0'))%10) + '0';
        }
    }


    for (i=0;i<digits+1;i++) if (upperLine[i]=='0') upperLine[i] = ' ';

    for (i=0;i<digits+1;i++) {
        if (result[i] != '0') break;
        result[i] = ' ';
    }

    for (i=0;i<digits;i++) {
        if (buforB[i] != '0') break;
        buforB[i] = ' ';
    }

    for (i=0;i<digits;i++) {
        if (buforA[i] != '0') break;
        buforA[i] = ' ';
    }

    printf("\n");
    printf(" %s\n", upperLine);
    printf("  %s\n", buforA);
    printf("+ %s\n", buforB);
    printf("%s\n", hr);
    printf(" %s\n", result);

    return 0;
}
