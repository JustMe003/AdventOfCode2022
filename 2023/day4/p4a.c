#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(int *arr, int size) {
    printf("[%d", arr[0]);
    for (int i = 1; i < size; i++) {
        printf(", %d", arr[i]);
    }
    printf("]\n");
}

int inArray(int *arr, int size, int n) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == n) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int *win, total = 0, size = 10, num = 25, n;
    int mult[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    char c;
    win = malloc(size * sizeof(int));
    do {
        scanf("Card %*d:");
        int value = 0;
        int winIndex = 0;
        while (winIndex < size) {
            scanf("%d", &win[winIndex]);
            winIndex++;
        }
        
        scanf("%c", &c);
        while (c != '|') {
            scanf("%c", &c);
        }

        for (int i = 0; i < num; i++) {
            scanf("%d", &n);
            if (inArray(win, size, n)) {
                value++;
            }
        }

        total += mult[0];

        printArray(mult, 11);

        for (int i = 0; i < value; i++) {
            mult[i + 1] += mult[0];
        }

        for (int i = 1; i < 11; i++) {
            mult[i - 1] = mult[i];
        }


        mult[10] = 1;

        scanf("%c", &c);

        scanf("Card %*d:");
    } while (scanf("%c", &c) != EOF);
    free(win);
    printf("%d\n", total);
    return 0;
}