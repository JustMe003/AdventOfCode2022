#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    char c;
    int n;
    int timesHitZero = 0;
    int dialNumber = 50;

    while (scanf("%c%d ", &c, &n) != EOF) {
        if (n > 99) {
            timesHitZero += n / 100;
            n %= 100;
        }
        if (c == 'L') {
            if (dialNumber && dialNumber - n < 0) timesHitZero++;
            dialNumber -= n;
        } else {
            if (dialNumber + n > 100) timesHitZero++;
            dialNumber += n;
        }
        dialNumber = dialNumber % 100;
        if (dialNumber < 0) dialNumber += 100;

        if (!dialNumber) timesHitZero++;
    }

    printf("Times hit zero: %d\n", timesHitZero);
}