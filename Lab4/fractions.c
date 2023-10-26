#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Fraction {
    int num, den;
};

/*
a/b + c/d = (a*d)/(b*d) + (c*b)/(d*b) = (a*d + c*b) / (b*d)
*/
struct Fraction sum(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;

    int c = y.num;
    int d = y.den;

    struct Fraction z;

    z.num = a * d + c * b;
    z.den = b * d;

    return z;
}

/*
a/b - c/d = (a*d)/(b*d) - (c*b)/(d*b) = (a*d - c*b) / (b*d)
*/
struct Fraction sub(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;

    int c = y.num;
    int d = y.den;

    struct Fraction z;

    z.num = a * d - c * b;
    z.den = b * d;

    return z;
}

/*
a/b * c/d  = (a*c) / (b*d)
*/
struct Fraction mul(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;

    int c = y.num;
    int d = y.den;

    struct Fraction z;

    z.num = a * c;
    z.den = b * d;

    return z;
}

/*
a/b / c/d  = (a*d) / (b*c)
*/
struct Fraction quo(struct Fraction x, struct Fraction y) {
    int a = x.num;
    int b = x.den;

    int c = y.num;
    int d = y.den;

    struct Fraction z;

    z.num = a * d;
    z.den = b * c;

    return z;
}

void printFraction(struct Fraction x) {
    int a = x.num;
    int b = x.den;

    if (a * b > 0 && a < 0) {
        a *= (-1);
        b *= (-1);
    }

    if (a * b < 0) {
        printf("-");

        if (a < 0) a *= -1;
        if (b < 0) b *= -1;
    }

    if (b == 0) printf("NaN\n", a, b);
    else if (a == 0) printf("0\n", a, b);
    else {
        if (b > a) printf("%d/%d\n", a, b);
        else {
            int nominator = a % b;
            int a_temp = a - nominator;
            int number = a_temp / b;

            if (nominator == 0) printf("%d\n", number);
            else printf("%d %d/%d\n", number, nominator, b);
        }
    }
}

void print(struct Fraction x, struct Fraction y, const char op) {

    if (op != '+' && op != '-' && op != '*' && op != '/' && op != ':') {
        printf("%c - niepoprawne dzialanie", op);
    } else {
        struct Fraction z;

        if (op == '+') z = sum(x, y);
        if (op == '-') z = sub(x, y);
        if (op == '*') z = mul(x, y);
        if (op == '/' || op == ':') z = quo(x, y);

        printf("%d/%d %c %d/%d = %d/%d\n", x.num, x.den, op,
               y.num, y.den, z.num, z.den);
    }

}

/*
       0    1    2    3      index
s -> ['-']['3']['5']['\0']   
     |    |    |    |        pointer
     s    s+1  s+2  s+3
*/
int isNumber(const char *s) {

    if (*s == '\0') return 0;

    if (*s == '-') s++;

    if (*s == '\0') return 0;

    while (*s) {
        if (!isdigit(*s)) return 0;
        s++;
    }

    return 1;
}
// TODO: Naprawic, zeby sam minus zwracal 0 (zrobione)

/*
       i         i'        j'        j
       0    1    2    3    4    5    6    7
s -> [' '][' ']['a']['l']['a'][' '][' ']['\0']
       k
*/
char *trim(char *s) {
    int i = 0;
    int j = strlen(s) - 1;
    int k = 0;

    while (isspace(s[i]) && i <= j) i++;

    while (isspace(s[j]) && i <= j) j--;

    while (i <= j) s[k++] = s[i++];

    s[k] = '\0';

    return s;
}
// TODO: CZY DA SIE NA I<J (Nie da sie)

int getOperator(char *op, const char *s) {

    int n = (int) strlen(s);

    char operator[n + 1];
    strncpy(operator, s, n + 1);
    trim(operator);

    if (strlen(operator) != 1) return 0;

    char operators[] = "+-*/:";

    char c = *operator;

    if (strchr(operators, c)) {
        *op = c;
        return 1;
    }

    return 0;
}

/*               index
                 | 
       0    1    2    3    4      indexes
s -> ['3']['7']['/']['5']['\0']
     |         |
     s         slash              pointers
*/

int getFraction(struct Fraction *x, const char *s) {

//    int number_of_slash = 0;
//    int index_of_slash = -1;
//    int number_of_minus = 0;
//    const char *temp = s;
//    int length = (int) strlen(s);
//
//    int i = 0;
//    while (*s) {
//        if (!isdigit(*s) && *s != '/' && *s != '-') return 0;
//
//        if (*s == '/') {
//            index_of_slash = i;
//            if (number_of_slash > 0) return 0;
//            else number_of_slash++;
//        }
//
//        if (*s == '-') {
//            if (number_of_minus >= 2) return 0;
//            else number_of_minus++;
//        }
//
//        s++;
//        i++;
//    }
//
//    if (number_of_slash == 0) {
//
//        x->num = atoi(temp);
//        x->den = 1;
//
//    } else {
//
//        char first_number[index_of_slash + 1];
//
//        strncpy(first_number, temp, index_of_slash);
//
//        if (isNumber(first_number)) x->num = atoi(first_number);
//
//        char second_number[length - index_of_slash];
//
//        for (i = 0; i < index_of_slash + 1; i++) temp++;
//
//        strncpy(second_number, temp, length - index_of_slash - 1);
//
//        if (isNumber(first_number)) x->den = atoi(second_number);
//    }

    int n = strlen(s);
    char *slash = strchr(s, '/');
    
    if (!slash) {
        char number[n+1];
        strcpy(number, s);
        trim(number);
        
        if (isNumber(number)) {
            x -> num = atoi(number);
            x -> den = 1;
            
            return 1;
        }
        
        return 0;
    }
    
    char num[n];
    char den[n];
    
    int index = slash - s;
    
    strncpy(num, s, index);
    num[index] = '\0';
    strcpy(den, slash+1);

    trim(num);
    trim(den);
    
    if (isNumber(num) && isNumber(den) && atoi(den) != 0) {
        x -> num = atoi(num);
        x -> den = atoi(den);
        
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    printf("fractions.c\n\n");
    
    int tests = 0;
    
    if (!tests) goto program;
    
    struct Fraction x = {7, 2};
    struct Fraction y = {11, 4};

    struct Fraction z = sum(x, y);

    printf("%d/%d + %d/%d = %d/%d\n", x.num, x.den,
           y.num, y.den, z.num, z.den);

    z = mul(x, y);

    printf("%d/%d * %d/%d = %d/%d\n", x.num, x.den,
           y.num, y.den, z.num, z.den);

    printf("\n\n");

    print(x, y, '+');
    print(x, y, '-');
    print(x, y, '*');
    print(x, y, '/');
    print(x, y, ':');
    print(x, y, '&');

    printf("\n\n\n");

    struct Fraction k = {-0, 1};
    struct Fraction w = {-1, 0};
    struct Fraction w1 = {8, 2};
    struct Fraction w2 = {-3, 3};
    struct Fraction w3 = {-17, 3};
    printFraction(x);
    printFraction(y);
    printFraction(k);
    printFraction(w);
    printFraction(w1);
    printFraction(w2);
    printFraction(w3);

    printf("\n\n");

//  isNumber test

    char *s = "-";

    if (isNumber(s)) printf("It is a number.\n");
    else printf("It is not a number.\n");

    printf("\n\n");

//  trim test
    char str[] = "   ala        ";
    printf("%s$\n", trim(str));

    printf("\n\n");

//  getOperator test
    char *op = "  ?    ";

    char o;

    if (getOperator(&o, op)) {
        printf("Napis %s przechowuje operator %c.\n", op, o);
    } else {
        printf("Napis %s nie przechowuje operatora.\n", op);
    }

    printf("\n\n");
    
//  getFraction test
    char *fr_str = "37/6";
    struct Fraction a;

    if (getFraction(&a, fr_str)) printFraction(a);
    else printf("Napis nie przechowuje ulamka.");

    printf("\n\n");
    
    program:;

//  implemantation

    struct Fraction first_fraction;
    struct Fraction second_fraction;

    char s1[50];
    char s2[50];
    char oper[50];
    char o1;
    
    do {
        printf("a/b: "); gets(s1);
    } while (!getFraction(&first_fraction, s1));

    do {
        printf("c/d: "); gets(s2);
    } while (!getFraction(&second_fraction, s2));

    printf("\n");

    do {
        printf("op: "); gets(oper);
    } while (!getOperator(&o1, oper));
    
    printf("\n");
    
    print(first_fraction, second_fraction, o1);

    return 0;
}
