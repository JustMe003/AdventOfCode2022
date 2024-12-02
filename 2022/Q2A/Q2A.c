#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]) {
    char a, b;
    int total = 0;
    while(scanf(" %c %c", &a, &b) != EOF) {
        total += b - 'W';
        if(a - 'A' == b - 'X'){
            total += 3;
        } else {
            if((a - 'A' == 0 && b - 'X' == 1) || (a - 'A' == 1 && b - 'X' == 2) || (a - 'A' == 2 && b - 'X' == 0)) {
                total += 6;
            }
        }
    }
    printf("%d\n", total);
    return 0;
}