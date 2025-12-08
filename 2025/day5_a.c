#include <stdlib.h>
#include <stdio.h>

typedef struct Range {
    long min;
    long max;
} *Range;

int main(int argc, char **argv) {
    int size = 2;
    int index = 0;
    Range *ranges = malloc(sizeof(struct Range) * size);

    long n;
    char c;
    while (scanf("%ld", &n) != EOF) {
        scanf("%c", &c);
        if (c == '-') {
            Range r = malloc(sizeof(struct Range));
            r->min = n;
            scanf("%ld ", &n);
            r->max = n;
            ranges[index] = r;
            index++;
            if (index == size) {
                size *= 2;
                ranges = realloc(ranges, sizeof(struct Range) * size);
            }
        } else {
            break;
        }
    }

    int total = 0;

    do {
        for (int i = 0; i < index; i++) {
            Range r = ranges[i];
            if (n >= r->min && n <= r->max) {
                total++;
                break;
            }
        }
    } while (scanf("%ld", &n) != EOF);

    printf("%d\n", total);

    for (int i = 0; i < index; i++) {
        free(ranges[i]);
    }

    free(ranges);
}