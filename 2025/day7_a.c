#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct IntArr {
    int size;
    int index;
    int *arr;
} *IntArr;

IntArr createIntArr() {
    IntArr i = malloc(sizeof(struct IntArr));
    i->size = 2;
    i->index = 0;
    i->arr = malloc(sizeof(int) * i->size);
    return i;
}

void printIntArr(IntArr i) {
    printf("%d %d: [", i->size, i->index);
    for (int k = 0; k < i->index; k++) {
        printf("%d, ", i->arr[k]);
    }
    printf("]\n");
}

void addIntToArray(IntArr i, int n) {
    for (int k = 0; k < i->index; k++) {
        if (n == i->arr[k]) return;
    }
    i->arr[i->index] = n;
    i->index++;
    if (i->index == i->size) {
        i->size *= 2;
        i->arr = realloc(i->arr, sizeof(int) * i->size);
    }
}

void removeIntFromArray(IntArr i, int n) {
    for (int k = 0; k < i->index; k++) {
        if (n == i->arr[k]) {
            i->arr[k] = i->arr[i->index - 1];
            i->index--;
            break;
        }
    }
}

int intInArray(IntArr i, int n) {
    for (int k = 0; k < i->index; k++) {
        if (n == i->arr[k]) return 1;
    }
    return 0;
}

void freeIntArr(IntArr i) {
    free(i->arr);
    free(i);
}

int goodChar(char c) {
    return c == '.' || c == '^' || c == 'S';
}

int main(int argc, char **argv) {
    IntArr cur = createIntArr();

    int total = 0;
    char *s;
    while (scanf("%ms", &s) != EOF) {
        printf("%s\n", s);
        IntArr next = createIntArr();
        for (int i = 0; i < cur->index; i++) {
            addIntToArray(next, cur->arr[i]);
        }
        char c;
        int index = 0;
        do {
            c = s[index];
            if (c == 'S') addIntToArray(next, index);
            else if (c == '^' && intInArray(cur, index)) {
                total++;
                removeIntFromArray(next, index);
                addIntToArray(next, index - 1);
                addIntToArray(next, index + 1);
            } 
            index++;
        } while (goodChar(c));
        free(s);
        freeIntArr(cur);
        cur = next;

        printIntArr(cur);
    }
    freeIntArr(cur);

    printf("%d\n", total);
}