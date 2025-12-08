#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    printf("%d %d\n", width, height);
    
    int **mat = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        int *arr = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            scanf("%d", &arr[j]);
        }
        mat[i] = arr;
    }

    long total = 0;

    for (int i = 0; i < width; i++) {
        char c;
        scanf(" %c ", &c);
        if (c == '+') {
            long tot = 0;
            for (int j = 0; j < height; j++) {
                tot += mat[j][i];
            }
            total += tot;
        } else {
            long tot = 1;
            for (int j = 0; j < height; j++) {
                tot *= mat[j][i];
            }
            total += tot;
        }
    }

    printf("%ld\n", total);

    for (int i = 0; i < height; i++) {
        free(mat[i]);
    }

    free(mat);
}