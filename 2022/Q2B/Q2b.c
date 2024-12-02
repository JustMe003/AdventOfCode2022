#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN3(a) ((a) < 1 ? (3) - (a) : (a))
#define MAX3(a) ((a) > 3 ? (a) - (3) : (a))

int main(int argc, char *argv[]) {
    char a, b;
    int total = 0;
    while(scanf(" %c %c", &a, &b) != EOF) {
        total += (b - 'X') * 3;
        if(b - 'X' == 0) {
            total += MIN3(a - 'A');
        } else if(b - 'X' == 1) {
            total += a - 'A' + 1;
        } else {
            total += MAX3(a - 'A' + 2);
        }
    }
    printf("%d\n", total);
    return 0;
}