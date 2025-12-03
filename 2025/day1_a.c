#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    char c;
    int n;
    int timesHitZero = 0;
    int dialNumber = 50;

    while (scanf("%c%d ", &c, &n) != EOF) {
        if (c == 'L') {
            dialNumber -= n;
        } else {
            dialNumber += n;
        }
        dialNumber = (dialNumber + 100) % 100;
        if (!dialNumber) timesHitZero++;
    }

    printf("Times hit zero: %d\n", timesHitZero);
}