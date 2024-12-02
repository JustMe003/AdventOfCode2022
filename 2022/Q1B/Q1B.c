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
    int highest1 = 0, highest2 = 0, highest3 = 0, current = 0, i = 0;
    char c[10], lastChar = '=';
    while(scanf("%c", &c[i]) != EOF) {
        if(c[i] == '\n' || c[i] == 13) {
            if(lastChar == '\n' && c[i] == 13) {
                if(highest1 < current) {
                    highest3 = highest2;
                    highest2 = highest1;
                    highest1 = current;
                } else if(highest2 < current) {
                    highest3 = highest2;
                    highest2 = current;
                } else if(highest3 < current) {
                    highest3 < current;
                }
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
    printf("%d, %d, %d, %d\n", highest1, highest2, highest3, highest1 + highest2 + highest3);
    return 0;
}
