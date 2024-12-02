#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int a, b, c, d, r = 0;
    while(scanf("%d-%d,%d-%d", &a, &b, &c, &d) != EOF) {
        if((a <= c && b >= d) || (c <= a && d >= b)) {
            r++;
        }
    }
    printf("%d\n", r);
    return 0;
}