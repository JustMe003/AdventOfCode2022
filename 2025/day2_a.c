#include <stdlib.h>
#include <stdio.h>

int getCharLengthOfLong(long in) {
    int len = 1;
    long div = 10;
    while (in % div != in) {
        len++;
        div *= 10;
    }
    return len;
}

long power(long n, int x) {
    long total = 1;
    for(int i = 0; i < x; i++) {
        total *= n;
    }
    return total;
}

int main(int argc, char **argv) {
    long min;
    long max;
    long total = 0;

    while (scanf("%ld-%ld", &min, &max) != EOF) {
        scanf(", ");
        for(long i = min; i <= max; i++) {
            int len = getCharLengthOfLong(i);
            if (len % 2 == 0) {
                long n2 = i % power(10, len / 2);
                long n1 = (i - n2) / power(10, len / 2);
                if (n1 == n2) {
                    total += i;
                }
            }
        }
    }

    printf("%ld\n", total);
}