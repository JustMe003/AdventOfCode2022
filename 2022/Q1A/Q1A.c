#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int power(int base, int pow) {
    if(pow == 0) {
        return 1;
    }
    return base * power(base, pow - 1);
}

int main(int argc, char *argv[]) {
    int highest = 0, current = 0, i = 0;
    char c[10], lastChar = '=';
    while(scanf("%c", &c[i]) != EOF) {
        if(c[i] == '\n' || c[i] == 13) {
            if(lastChar == '\n' && c[i] == 13) {
                printf("%d, %d\n", current, highest);
                highest = MAX(highest, current);
                current = 0;
            } else {
                for(int j = 0; j < i; j++) {
                    if(c[j] != '\n') {
                        current += (power(10, i - j - 1) * (c[j] - '0'));
                    }
                }
            }
            i = 0;
            lastChar = '\n';
        } else {
            i++;
            lastChar = '=';
        }
    }
    printf("%d\n", highest);
    return 0;
}
