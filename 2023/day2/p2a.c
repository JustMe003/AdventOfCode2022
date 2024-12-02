#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(int argc, char *argv[]) {
    int game, num, r = 12, g = 13, b = 14, total = 0;
    char c;
    while (scanf("%c", &c) != EOF) {
        int boolean = 1;
        scanf("%*ms %d%c", &game, &c);
        while (c != '\n') {
            scanf("%d %c", &num, &c);
            if (c == 'r') {
                boolean = MIN(num <= r, boolean);
            } else if (c == 'g') {
                boolean = MIN(num <= g, boolean);
            } else if (c == 'b') {
                boolean = MIN(num <= b, boolean);
            }
            while (c != ' ' && c != '\n') {
                scanf("%c", &c);
            }
        }
        if (boolean) {
            total += game;
        }
    }
    printf("%d\n", total);
    return 0;
}