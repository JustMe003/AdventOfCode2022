#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct gear {
    int num1;
    int num2;
    int overflow;
    char c;
} gear;

typedef struct rows {
    gear *row1;
    gear *row2;
} rows;

void addToGear(gear *g, int n) {
    printf("%d %d %d %d\n", g->num1, g->num2, g->overflow, n);
    if (g->num1 == -1) {
        g->num1 = n;
    } else if (g->num2 == -1) {
        g->num2 = n;
    } else {
        g->overflow = 1;
    }
}

int isNumber(char c) {
    return c >= '0' && c <= '9';
}

int getNumberFromLeft(gear *r, int i) {
    if (i == 0) {
        if (isNumber(r[i].c)) {
            int res = r[i].c - '0';
            return res;
        }
    } else {
        if (isNumber(r[i].c)) {
            int res = r[i].c - '0';
            return res + 10 * getNumberFromLeft(r, i - 1);
        }
    }
    return 0;
}

int getNumber(gear *r, int size, int i) {
    if (size - 2 == i) {
        if (isNumber(r[i + 1].c)) {
            return getNumberFromLeft(r, i + 1);
        } else {
            return getNumberFromLeft(r, i);
        }
    } else {
        if (isNumber(r[i + 1].c)) {
            return getNumber(r, size, i + 1);
        } else {
            return getNumberFromLeft(r, i);
        }
    }
}

void updateGears(rows r, int size, int i, int n) {
//    printf("checking for gear: %c %d %d\n", r.row1[i].c, i, n);
    if (size == i) {
        updateGears(r, size, i - 1, n);
    }
    if (r.row1[i].c == '*') {
        addToGear(&(r.row1[i]), n);
    }
    if (!i || !isNumber(r.row2[i - 1].c)) {
        if (i && r.row1[i - 1].c == '*') {
            addToGear(&(r.row1[i - 1]), n);
        }
        return;
    } else {
        updateGears(r, size, i - 1, n);
    }
}


int main(int argc, char *argv[]) {
    int size = 2, index = 0;
    long total = 0;
    char c;
    rows r;
    r.row1 = malloc(size * sizeof(gear));
    scanf("%c", &c);
    int number = 0, special = -1;
    while (c != '\n' && c != '\13') {
        r.row1[index].c = c;
        if (isNumber(c)) {
            number = 1;
        } else if (c == '*') {
            special = index;
            r.row1[index].num1 = -1;
            r.row1[index].num2 = -1;
            r.row1[index].overflow = 0;
            if (number) {
                addToGear(&(r.row1[index]), getNumberFromLeft(r.row1, index - 1));
            }
            number = 0;
        } else {
            if (special > -1 && number) {
                addToGear(&(r.row1[special]), getNumberFromLeft(r.row1, index - 1));
            }
            special = -1;
            number = 0;
        }
        index++;
        if (index == size) {
            size *= 2;
            r.row1 = realloc(r.row1, size * sizeof(gear));
        }
        scanf("%c", &c);
    }
    size = index;
    r.row1 = realloc(r.row1, size * sizeof(gear));
    r.row2 = malloc(size * sizeof(gear));
    while (scanf("%c", &c) != EOF) {
        index = 0;
        number = 0, special = -1;
        while (index < size) {
            r.row2[index].c = c;
            if (isNumber(c)) {
                number = 1;
            } else {
                if (number) {
                    updateGears(r, size, index, getNumberFromLeft(r.row2, index - 1));
                    if (r.row2[index].c == '*') {
                        r.row2[index].num1 = -1;
                        r.row2[index].num2 = -1;
                        r.row2[index].overflow = 0;
                        addToGear(&(r.row2[index]), getNumberFromLeft(r.row2, index - 1));
                    }
                    if (special > -1) {
                        addToGear(&(r.row2[special]), getNumberFromLeft(r.row2, index - 1));
                    }
                }
                if (c == '*') {
                    r.row2[index].num1 = -1;
                    r.row2[index].num2 = -1;
                    r.row2[index].overflow = 0;
                    if (size - 1 >= index && isNumber(r.row1[index + 1].c)) {
//                        printf("top right\n");
                        addToGear(&(r.row2[index]), getNumber(r.row1, size, index + 1));
                        if (index > 0 && isNumber(r.row1[index - 1].c) && getNumber(r.row1, size, index - 1) != getNumber(r.row1, size, index + 1)) {
//                            printf("top left\n");
                            addToGear(&(r.row2[index]), getNumber(r.row1, size, index - 1));
                        }
                    } else if (isNumber(r.row1[index].c)) {
//                        printf("top middle\n");
                        addToGear(&(r.row2[index]), getNumber(r.row1, size, index));
                    } else if (index > 0 && isNumber(r.row1[index - 1].c)) {
 //                       printf("top left\n");
                        addToGear(&(r.row2[index]), getNumber(r.row1, size, index - 1));
                    }
                    if (number) {
                        addToGear(&(r.row2[index]), getNumber(r.row2, size, index - 1));
                        number = 0;
                    }
                    special = index;
                } else {
                    special = -1;
                }
                number = 0;
            }
            index++;
            scanf("%c", &c);
        }
        if (number) {
            updateGears(r, size, index - 1, getNumberFromLeft(r.row2, index - 1));
            if (special > -1) {
                addToGear(&(r.row2[special]), getNumberFromLeft(r.row2, index - 1));
            }
        }
        for (int i = 0; i < size; i++) {
            if (r.row1[i].c == '*') {
//                printf("* found: %d %d %d\n", r.row1[i].num1, r.row1[i].num2, r.row1[i].overflow);
            }
            if (r.row1[i].c == '*' && r.row1[i].num1 != -1 && r.row1[i].num2 != -1 && !r.row1[i].overflow) {
//                printf("Gear: %c %d %d %d\n", r.row1[i].c, r.row1[i].num1, r.row1[i].num2, r.row1[i].overflow);
                total += r.row1[i].num1 * r.row1[i].num2;
            }
        }
//        printf("\n");
        free(r.row1);
        r.row1 = r.row2;
        r.row2 = malloc(size * sizeof(gear));
    }
    for (int i = 0; i < size; i++) {
        if (r.row1[i].c == '*') {
//            printf("* found: %d %d %d\n", r.row1[i].num1, r.row1[i].num2, r.row1[i].overflow);
        }
        if (r.row1[i].c == '*' && r.row1[i].num1 != -1 && r.row1[i].num2 != -1 && !r.row1[i].overflow) {
//            printf("Gear: %c %d %d %d\n", r.row1[i].c, r.row1[i].num1, r.row1[i].num2, r.row1[i].overflow);
            total += r.row1[i].num1 * r.row1[i].num2;
        }
    }
//    printf("\n");
    free(r.row1);
    free(r.row2);

    printf("%ld\n", total);
    return 0;
}