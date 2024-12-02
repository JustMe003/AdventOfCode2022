#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct rows {
    char *row1;
    char *row2;
} rows;

int isNumber(char c) {
    return c >= '0' && c <= '9';
}

int getNumberFromLeft(char *r, int i) {
    if (i == 0) {
        if (isNumber(r[i])) {
            int res = r[i] - '0';
            r[i] = '.';
            return res;
        }
    } else {
        if (isNumber(r[i])) {
            int res = r[i] - '0';
            r[i] = '.';
            return res + 10 * getNumberFromLeft(r, i - 1);
        }
    }
    return 0;
}

int getNumber(char *r, int size, int i) {
    if (size - 2 == i) {
        if (isNumber(r[i + 1])) {
            return getNumberFromLeft(r, i + 1);
        } else {
            return getNumberFromLeft(r, i);
        }
    } else {
        if (isNumber(r[i + 1])) {
            return getNumber(r, size, i + 1);
        } else {
            return getNumberFromLeft(r, i);
        }
    }
}

int searchForSpecialChar(rows r, int size, int i) {
    if (!isNumber(r.row2[i])) {
        return 0;
    }
    if (i == 0) {
        return (!isNumber(r.row1[i]) && r.row1[i] != '.') || (!isNumber(r.row1[i + 1]) && r.row1[i + 1] != '.');
    } else if (size - 1 == i) {
        return (!isNumber(r.row1[i]) && r.row1[i] != '.') || (!isNumber(r.row1[i - 1]) && r.row1[i - 1] != '.') || searchForSpecialChar(r, size, i - 1);
    } else {
        return (!isNumber(r.row1[i]) && r.row1[i] != '.') || (!isNumber(r.row1[i - 1]) && r.row1[i - 1] != '.') || (!isNumber(r.row1[i + 1]) && r.row1[i + 1] != '.') || searchForSpecialChar(r, size, i - 1);
    }
}


int main(int argc, char *argv[]) {
    int total = 0, size = 2, index = 0;
    char c;
    rows r;
    r.row1 = malloc(size * sizeof(char));
    scanf("%c", &c);
    int number = 0, special = 0;
    while (c != '\n' && c != '\13') {
        r.row1[index] = c;
        if (isNumber(c)) {
            number = 1;
        } else if (c != '.') {
            special = 1;
            if (number) {
                total += getNumberFromLeft(r.row1, index - 1);
            }
            number = 0;
        } else {
            if (special && number) {
                total += getNumberFromLeft(r.row1, index - 1);
            }
            special = 0;
            number = 0;
        }
        index++;
        if (index == size) {
            size *= 2;
            r.row1 = realloc(r.row1, size * sizeof(char));
        }
        scanf("%c", &c);
    }
    size = index;
    r.row1 = realloc(r.row1, size * sizeof(char));
    r.row2 = malloc(size * sizeof(char));
    while (scanf("%c", &c) != EOF) {
        index = 0;
        number = 0, special = 0;
        while (index < size) {
            r.row2[index] = c;
            if (isNumber(c)) {
                number = 1;
            } else {
                if (number) {
                    if (searchForSpecialChar(r, size, index - 1) || special) {
                        total += getNumber(r.row2, size, index - 1);
                    }
                }
                if (c != '.' && c >= 14) {
                    if (index < size - 1 && isNumber(r.row1[index + 1])) {
                        total += getNumber(r.row1, size, index + 1);
                    }
                    if (isNumber(r.row1[index])) {
                        total += getNumber(r.row1, size, index);
                    }
                    if (index > 0 && isNumber(r.row1[index - 1])) {
                        total += getNumber(r.row1, size, index - 1);
                    } 
                    if (number) {
                        total += getNumber(r.row2, size, index - 1);
                        number = 0;
                    }
                    special = c;
                } else {
                    special = 0;
                }
                number = 0;
            }
            index++;
            scanf("%c", &c);
        }
        if (number) {
            if (searchForSpecialChar(r, size, index - 1) || special) {
                total += getNumber(r.row2, size, index - 1);
            }
        }
        for (int i = 0; i < size; i++) {
            printf("%c", r.row1[i]);
        }
        printf("\n");
        free(r.row1);
        r.row1 = r.row2;
        r.row2 = malloc(size * sizeof(char));
    }
    for (int i = 0; i < size; i++) {
        printf("%c", r.row1[i]);
    }
    printf("\n");
    free(r.row1);
    free(r.row2);

    printf("%d\n", total);
    return 0;
}