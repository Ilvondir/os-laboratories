#include <sched.h>
#include <stdio.h>

int main() {
    int numerPolityki;

    printf("Podaj numer polityki: ");
    scanf("%d", &numerPolityki);

    int priorytet = sched_get_priority_max(numerPolityki);

    if (priorytet == -1) printf("Podano bledny numer polityki.");
    else printf("Maksymalna wartosc priorytetu dla grupy %d: %d\n", numerPolityki, priorytet);

    return 0;
}

// Z C na wykonywalny linuksa: gcc -m32 -o sched_get_priority_max sched_get_priority_max.c
