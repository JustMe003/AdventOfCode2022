#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM_DIGITS 12

#define MIN(a, b) ((a) < (b) ? (a) : (b))

long long pow10(int n) {
    long long res = 1;
    for (int i = 0; i < n; i++) res *= 10;
    return res;
}

long long getNumber(int *digits) {
    long long total = 0;
    for (int i = 0; i < NUM_DIGITS; i++) {
        total += digits[i] * pow10(NUM_DIGITS - i - 1);
    }
    return total;
}

int main(int argc, char **argv) {
    char *s;
    int digits[NUM_DIGITS]; 
    long long total = 0;
    while (scanf("%ms ", &s) != EOF) {
        for (int i = 0; i < NUM_DIGITS; i++) digits[i] = 0;
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            int d = s[i] - '0';
            for (int j = NUM_DIGITS - MIN(NUM_DIGITS, len - i); j < NUM_DIGITS; j++) {
                if (digits[j] == 0 || digits[j] < d) {
                    digits[j] = d;
                    for (int k = j + 1; k < NUM_DIGITS; k++) {
                        digits[k] = 0;
                    }
                    break;
                }
            }            
        }
        total += getNumber(digits);
        free(s);
    }
    printf("%lld\n", total);
}