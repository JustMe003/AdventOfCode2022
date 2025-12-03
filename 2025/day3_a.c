#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char *s;
    int n1 = 0;
    int n2 = 0;
    int total = 0;
    while (scanf("%ms ", &s) != EOF) {
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            int d = s[i] - '0';
            if (n1 == 0) n1 = d;
            else if (d > n1 && i < len - 1) {
                n1 = d;
                n2 = 0;
            } else if (n2 == 0) n2 = d;
            else if (d > n2) n2 = d;
        }
        total += n1 * 10 + n2;
        n1 = 0;
        n2 = 0;
        free(s);
    }
    printf("%d\n", total);
}