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
            for (int m = 1; m <= len / 2; m++) {
                if (len % m == 0) {
                    long n = i % power(10, m);
                    long leftover = i;
                    for (int j = 0; j < len / m; j++) {
                        leftover -= n;
                        leftover /= power(10, m);
                        long n2 = leftover % power(10, m);
                        if(n != n2) break;
                    }
                    if (!leftover) {
                        total += i;
                        break;
                    }
                }
            }
        }
    }

    printf("%ld\n", total);
}