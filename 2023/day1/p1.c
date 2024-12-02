#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct arr arr;

struct arr {
    char one;
    char two;
    char three;
    char four;
    char five;
};

int getNumber(arr str) {
    if (str.three == 'o' && str.four == 'n' && str.five == 'e') {
        return 1;
    } else if (str.three == 't' && str.four == 'w' && str.five == 'o') {
        return 2;
    } else if (str.one == 't' && str.two == 'h' && str.three == 'r' && str.four == 'e' && str.five == 'e') {
        return 3;
    } else if (str.two == 'f' && str.three == 'o' && str.four == 'u' && str.five == 'r') {
        return 4;
    } else if (str.two == 'f' && str.three == 'i' && str.four == 'v' && str.five == 'e') {
        return 5;
    } else if (str.three == 's' && str.four == 'i' && str.five == 'x') {
        return 6;
    } else if (str.one == 's' && str.two == 'e' && str.three == 'v' && str.four == 'e' && str.five == 'n') {
        return 7;
    } else if (str.one == 'e' && str.two == 'i' && str.three == 'g' && str.four == 'h' && str.five == 't') {
        return 8;
    } else if (str.two == 'n' && str.three == 'i' && str.four == 'n' && str.five == 'e') {
        return 9;
    }
    return 0;
}

int checkForNumber(arr str) {
    if ((str.three == 'o' && str.four == 'n' && str.five == 'e') || (str.three == 't' && str.four == 'w' && str.five == 'o') || (str.one == 't' && str.two == 'h' && str.three == 'r' && str.four == 'e' && str.five == 'e')
    || (str.two == 'f' && str.three == 'o' && str.four == 'u' && str.five == 'r') || (str.two == 'f' && str.three == 'i' && str.four == 'v' && str.five == 'e') || (str.three == 's' && str.four == 'i' && str.five == 'x') 
    || (str.one == 's' && str.two == 'e' && str.three == 'v' && str.four == 'e' && str.five == 'n') || (str.one == 'e' && str.two == 'i' && str.three == 'g' && str.four == 'h' && str.five == 't') || (str.two == 'n' && str.three == 'i' && str.four == 'n' && str.five == 'e')) {
        return 1;
    }
    return 0;
}

arr move(arr str) {
    str.one = str.two;
    str.two = str.three;
    str.three = str.four;
    str.four = str.five;
    return str;
}

int main(int argc, char *argv[]) {
    long total = 0;
    char c;
    int first = -1, last = -1;
    arr str;
    str.one = '0';
    str.two = '0';
    str.three = '0';
    str.four = '0';
    str.five = '0';
    while (scanf("%c", &c) != EOF) {
        //printf("%c", c);
        str = move(str);
        str.five = c;
        if (c >= '0' && c <= '9') {
            if (first == -1) {
                first = c - '0';
            }
            last = c - '0';
        }
        if (c == '\n') {
        //    printf("%d%d\n", first, last);
            total += first * 10 + last;
            first = -1;
            last = -1;
        }
        if (checkForNumber(str)) {
            if (first == -1) {
                first = getNumber(str);
            }
            last = getNumber(str);
        }
    }
    printf("%ld\n", total);
    return 0;
}