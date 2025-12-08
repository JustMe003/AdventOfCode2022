#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int getAdjacentPaperRolls(char **workspace, int height, int width, int x, int y) {
    int total = 0;
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if (j >= 0 && j < width && i >= 0 && i < height) {
                char c = workspace[i][j];
                if (c == '@' || c == 'X') total++;
            }
        }
    }
    return total - 1;
}

int main(int argc, char **argv) {
    int size = 2;
    int index = 0;
    char **workspace = malloc(sizeof(char *) * size);
    char *line;
    while (scanf("%ms\n", &line) != EOF) {
        workspace[index] = line;
        index++;
        if (index == size) {
            size *= 2;
            workspace = realloc(workspace, sizeof(char *) * size);
        }
    }

    int total = 0;
    int subTotal = 0;
    int len = strlen(workspace[0]);
    do {
        subTotal = 0;
        for (int y = 0; y < index; y++) {
            for (int x = 0; x < len; x++) {
                if (workspace[y][x] == '@') {
                    if (getAdjacentPaperRolls(workspace, index, len, x, y) < 4) {
                        subTotal++;
                        workspace[y][x] = 'X';
                    }
                }
            }
        }
        total += subTotal;
        printf("%d %d\n", total, subTotal);
        for (int y = 0; y < index; y++) {
            for (int x = 0; x < len; x++) {
                if (workspace[y][x] == 'X') {
                    workspace[y][x] = '.';
                }
            }
        }
    } while (subTotal > 0);

    printf("%d\n", total);

    for (int i = 0; i < index; i++) {
        free(workspace[i]);
    }
    free(workspace);
}