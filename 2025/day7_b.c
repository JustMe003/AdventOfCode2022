#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct IntArr {
    int size;
    int index;
    int *arr;
    long long *weight;
} *IntArr;

IntArr createIntArr() {
    IntArr i = malloc(sizeof(struct IntArr));
    i->size = 2;
    i->index = 0;
    i->arr = malloc(sizeof(int) * i->size);
    i->weight = malloc(sizeof(long long) * i->size);
    return i;
}

void printIntArr(IntArr i) {
    printf("%d %d: [", i->size, i->index);
    for (int k = 0; k < i->index; k++) {
        printf("%d (%lld), ", i->arr[k], i->weight[k]);
    }
    printf("]\n");
}

void addIntToArray(IntArr i, int n, long long weight) {
    if (weight < 0) printf("%lld\n", weight);
    for (int k = 0; k < i->index; k++) {
        if (n == i->arr[k]) {
            if (i->weight[k] + weight < 0) printf("%lld %lld %lld\n", i->weight[k], weight, i->weight[k] + weight);
            i->weight[k] += weight;
            return;
        }
    }
    i->arr[i->index] = n;
    i->weight[i->index] = weight;
    i->index++;
    if (i->index == i->size) {
        i->size *= 2;
        i->arr = realloc(i->arr, sizeof(int) * i->size);
        i->weight = realloc(i->weight, sizeof(long long) * i->size);
    }
}

void removeIntFromArray(IntArr i, int n) {
    for (int k = 0; k < i->index; k++) {
        if (n == i->arr[k]) {
            i->arr[k] = i->arr[i->index - 1];
            i->weight[k] = i->weight[i->index - 1];
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

long long getWeight(IntArr i, int n) {
    for (int k = 0; k < i->index; k++) {
        if (n == i->arr[k]) return i->weight[k];
    }
    return 0;
}

void freeIntArr(IntArr i) {
    free(i->arr);
    free(i->weight);
    free(i);
}

int goodChar(char c) {
    return c == '.' || c == '^' || c == 'S';
}

int main(int argc, char **argv) {
    IntArr cur = createIntArr();

    char *s;
    while (scanf("%ms", &s) != EOF) {
        printf("%s\n", s);
        IntArr next = createIntArr();
        for (int i = 0; i < cur->index; i++) {
            addIntToArray(next, cur->arr[i], cur->weight[i]);
        }
        char c;
        int index = 0;
        do {
            c = s[index];
            if (c == 'S') addIntToArray(next, index, 1);
            else if (c == '^' && intInArray(cur, index)) {
                long long weight = getWeight(cur, index);
                if (weight <= 0) printf("%d %lld\n", index, weight);
                removeIntFromArray(next, index);
                addIntToArray(next, index - 1, weight);
                addIntToArray(next, index + 1, weight);
            } 
            index++;
        } while (goodChar(c));
        free(s);
        freeIntArr(cur);
        cur = next;
        
        // printIntArr(cur);
    }
    long long total = 0;
    for (int i = 0; i < cur->index; i++) {
        total += cur->weight[i];
    }

    freeIntArr(cur);

    printf("%lld\n", total);
}