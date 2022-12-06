#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int inputsAreDifferent(char arr[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) {
                return 0;
            }
        }
    }
    return 1;
}

void moveInputs(char arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

int main(int argc, char *argv[]) {
    char arr[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int n = 0;
    while(scanf("%c", &arr[13]) != EOF) {
        n++;
        if(inputsAreDifferent(arr, 14)) {
            break;
        } else {
            moveInputs(arr, 14);
        }
    }
    printf("%d\n", n);
    return 0;
}