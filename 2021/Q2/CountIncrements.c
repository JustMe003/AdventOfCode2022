
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	int a, b, c, d, count = 0;
    scanf("%d %d %d", &a, &b, &c);
    while(scanf("%d", &d) != EOF) {
        if(d > a) {
            count++;
        }
        a = b;
        b = c;
        c = d;
    }
    printf("%d\n", count);
}