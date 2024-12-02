
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	int a, b, count = 0;
    scanf("%d", &a);
    while(scanf("%d", &b) != EOF) {
        if(b > a) {
            count++;
        }
        a = b;
    }
    printf("%d\n", count);
}