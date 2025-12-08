#include <stdlib.h>
#include <stdio.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)

int readLine(char **s, int size) {
    *s = malloc(sizeof(char) * size);
    int index = 0;
    char c;
    do {
        scanf("%c", &c);
        (*s)[index] = c;
        index++;
        if (index == size) {
            size *= 2;
            *s = realloc(*s, sizeof(char) * size);
        }
    } while (c != '\n');
    (*s)[index - 1] = '\0';
    return index;
}

int pow10(int n) {
    long res = 1;
    for (int i = 0; i < n; i++) res *= 10;
    return res;
}

int readNumber(char **mat, int col, int height) {
    int tot = 0;
    int p = 0;
    for (int i = height - 2; i >= 0; i--) {
        char c = mat[i][col];
        // printf("%c %d %d\n", c, tot, p);
        if (c != ' ') {
            tot += (c - '0') * pow10(p);
            p++;
        }
    }
    return tot;
}

int main(int argc, char **argv) {
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    char **mat = malloc(sizeof(char *) * height);

    char *line;
    int lineLen = readLine(&line, 2);
    mat[0] = line;

    for (int i = 1; i < height; i++) {
        char *s;
        readLine(&s, lineLen);
        mat[i] = s;
    }

    long long total = 0;
    int pointer = 0;
    for (int i = 0; i < width; i++) {
        char c = mat[height - 1][pointer];
        if (c == '+') {
            long long subTot = 0;
            do {
                subTot += readNumber(mat, pointer, height);
                pointer++;
            } while (mat[height - 1][pointer] == ' ');
            printf("%lld\n", subTot);
            total += subTot;
        } else {
            long long subTot = 1;
            do {
                subTot *= MAX(readNumber(mat, pointer, height), 1);
                pointer++;
            } while (mat[height - 1][pointer] == ' ');
            printf("%lld\n", subTot);
            total += subTot;
        }
    }

    printf("%lld\n", total);
    
    for (int i = 0; i < height; i++) {
        free(mat[i]);
    }
    free(mat);
}