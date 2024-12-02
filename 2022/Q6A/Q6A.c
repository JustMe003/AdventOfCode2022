#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    char a, b, c, d;
    int n = 4;
    scanf("%c%c%c", &d, &c, &b);
    while(scanf("%c", &a) != EOF) {
        if(a != b && a != c && a != d && b != c && b != d && c != d) {
            break;
        } else {
            n++;
        }
        d = c;
        c = b;
        b = a;
    }
    printf("%d\n", n);
    return 0;
}