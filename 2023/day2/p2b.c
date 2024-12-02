#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(int argc, char *argv[]) {
    int game, num, r = 0, g = 0, b = 0, total = 0;
    char c;
    while (scanf("%c", &c) != EOF) {
        scanf("%*ms %d%c", &game, &c);
        while (c != '\n') {
            scanf("%d %c", &num, &c);
            if (c == 'r') {
                r = MAX(num, r);
            } else if (c == 'g') {
                g = MAX(num, g);
            } else if (c == 'b') {
                b = MAX(num, b);
            }
            while (c != ' ' && c != '\n') {
                scanf("%c", &c);
            }
        }
        total += r * g * b;
        r = 0; g = 0; b = 0;
    }
    printf("%d\n", total);
    return 0;
}