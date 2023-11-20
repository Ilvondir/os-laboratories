#include <stdlib.h>
#include <stdio.h>
#include <sched.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
    gcc -m32 -o sched_get_priority_min sched_get_priority_min.c
*/

int main(int argc, char *argv[]) {
    printf("sched_get_priority_min.c\n\n");

    int num;

    printf("Select politic: "); scanf("%d", &num);

    int result = sched_get_priority_min(num);

    if (result==-1) printf("Error!\n");
    else printf("Min priority: %d\n", result);

    return 0;
}

