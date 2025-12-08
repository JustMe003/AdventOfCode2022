#include <stdlib.h>
#include <stdio.h>

#define IN_BETWEEN(a, b, c) ((a) >= (b) && (a) <= (c)) ? (1) : (0)

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

            for (int i = 0; i < index; i++) {
                Range r2 = ranges[i];
                if (IN_BETWEEN(r->min, r2->min, r2->max)) {
                    if (IN_BETWEEN(r->max, r2->min, r2->max)) {
                        // printf("r in r2: %ld-%ld, %ld-%ld\n", r->min, r->max, r2->min, r2->max);
                        r->min = 0;
                        r->max = 0;
                        break;
                    } else {
                        // printf("r->min in r2: %ld-%ld, %ld-%ld\n", r->min, r->max, r2->min, r2->max);
                        r->min = r2->max + 1;
                    }
                } else if (IN_BETWEEN(r->max, r2->min, r2->max)) {
                    // printf("r->max in r2: %ld-%ld, %ld-%ld\n", r->min, r->max, r2->min, r2->max);
                    r->max = r2->min - 1;
                } else if (IN_BETWEEN(r2->min, r->min, r->max)) {
                    if (IN_BETWEEN(r2->max, r->min, r->max)) {
                        // printf("r2 in r: %ld-%ld, %ld-%ld\n", r->min, r->max, r2->min, r2->max);
                        r2->min = 0;
                        r2->max = 0;
                    }
                }

                // if (IN_BETWEEN(r->min, r2->min, r2->max) && IN_BETWEEN(r->max, r2->min, r2->max)) {
                    // printf("r in r2: %ld-%ld, %ld-%ld\n", r->min, r->max, r2->min, r2->max);
                //     r->min = 0;
                //     r->max = 0;
                // } else if (IN_BETWEEN(r2->min, r->min, r->max) && IN_BETWEEN(r2->max, r->min, r->max)) {
                //     printf("r2 in r: %ld-%ld, %ld-%ld\n", r->min, r->max, r2->min, r2->max);
                //     r2->min = 0;
                //     r2->max = 0;
                // } else {
                //     if (IN_BETWEEN(r->min, r2->min, r2->max)) {
                //         r->min = r2->max + 1;
                //     } else if (IN_BETWEEN(r->max, r2->min, r2->max)) {
                //         r->max = r2->min - 1;
                //     }

                // }
            }

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

    long total = 0;

    for (int i = 0; i < index; i++) {
        // printf("%ld - %ld\n", ranges[i]->min, ranges[i]->max);
        if (ranges[i]->min != 0 && ranges[i]->max != 0) {
            total += ranges[i]->max - ranges[i]->min + 1;
        }
        free(ranges[i]);
    }

    printf("%ld\n", total);

    free(ranges);
}