#include <stdio.h>
#include <stdlib.h>

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
    
    z.num = a*d + c*b;
    z.den = b*d;
    
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
    
    z.num = a*d - c*b;
    z.den = b*d;
    
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
    
    z.num = a*c;
    z.den = b*d;
    
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
    
    z.num = a*d;
    z.den = b*c;
    
    return z;
}

void print(struct Fraction x, struct Fraction y, const char op) {
    
    if (op != '+' && op != '-' && op != '*' && op != '/' && op != ':') {
        printf("%c - niepoprawne dzialanie", op);
    }
    else {
        struct Fraction z;
        
        if (op == '+') z = sum(x, y);
        if (op == '-') z = sub(x, y);
        if (op == '*') z = mul(x, y);
        if (op == '/' || op == ':') z = quo(x, y);

        printf("%d/%d %c %d/%d = %d/%d\n", x.num, x.den, op,
                                           y.num, y.den, z.num, z.den);
    }
    
}

void printFraction(struct Fraction x) {
    int a = x.num;
    int b = x.den;
    
    printf("(struct Fraction){%d,%d} -> ", a, b);
    
    if (a*b > 0 && a < 0) {
    	a *= (-1);
    	b *= (-1);
	}
	
	if (a*b<0) {
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
    
int main(int argc, char *argv[]) {
    printf("fractions.c\n\n");
    
    struct Fraction x = {7, 2};
    struct Fraction y = {15, 4};
    
    struct Fraction z = sum(x, y);
    
    printf("%d/%d + %d/%d = %d/%d\n", x.num, x.den,
                                      y.num, y.den, z.num, z.den); 
    
    z = mul(x, y);
    
    printf("%d/%d * %d/%d = %d/%d\n", x.num, x.den,
                                      y.num, y.den, z.num, z.den);
    
    printf("\n");
    
    print(x, y, '+');
    print(x, y, '-');
    print(x, y, '*');
    print(x, y, '/');
    print(x, y, ':');
    print(x, y, '&');
    
    printf("\n\n");
    
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
    
	return 0;
}
