#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct position {
  int x;
  int y;
};

void positionBuilder(struct position *s, int x, int y) {
    s->x = x;
    s->y = y;
}

// safely call malloc
void *safeMalloc(int n) {
  void *p = malloc(n);
  if (p == NULL) {
    printf("Error: malloc(%d) failed. Out of memory?\n", n);
    exit(EXIT_FAILURE);
  }
  return p;
}

void addPositionIfNotFound(int arrX[], int arrY[], int *arrSize, int *size, int x, int y) {
    for(int i = 0; i < *size; i++) {
        if(arrX[i] == x && arrY[i] == y) {
            return;
        }
    }
    if(*size == (*arrSize) - 1) {
        (*arrSize) += 10;
        arrX = realloc(arrX, (*arrSize) * sizeof(int));
        arrY = realloc(arrY, (*arrSize) * sizeof(int));
    }
    printf("%d, %d\n", arrX[*size - 1], arrY[*size - 1]);
    arrX[*size] = x;
    arrY[*size] = y;
    (*size)++;
}

void moveUp(int arrX[], int arrY[], struct position *h, struct position *t, int moves, int *arrSize, int *size) {
    for(int i = 0; i < moves; i++) {
        (h->x)++;
        if(abs(h->x - t->x) > 1) {
            (t->x)++;
            if(abs(h->y - t->y) > 0) {
                t->y = h->y;
            }
            addPositionIfNotFound(arrX, arrY, arrSize, size, t->x, t->y);
        }
    }
}

void moveLeft(int arrX[], int arrY[], struct position *h, struct position *t, int moves, int *arrSize, int *size) {
    for(int i = 0; i < moves; i++) {
        (h->y)--;
        if(abs(h->y - t->y) > 1) {
            (t->y)--;
            if(abs(h->x - t->x) > 0) {
                t->x = h->x;
            }
            addPositionIfNotFound(arrX, arrY, arrSize, size, t->x, t->y);
        }
    }
}

void moveDown(int arrX[], int arrY[], struct position *h, struct position *t, int moves, int *arrSize, int *size) {
    for(int i = 0; i < moves; i++) {
        (h->x)--;
        if(abs(h->x - t->x) > 1) {
            (t->x)--;
            if(abs(h->y - t->y) > 0) {
                t->y = h->y;
            }
            addPositionIfNotFound(arrX, arrY, arrSize, size, t->x, t->y);
        }
    }
}

void moveRight(int arrX[], int arrY[], struct position *h, struct position *t, int moves, int *arrSize, int *size) {
    for(int i = 0; i < moves; i++) {
        (h->y)++;
        if(abs(h->y - t->y) > 1) {
            (t->y)++;
            if(abs(h->x - t->x) > 0) {
                t->x = h->x;
            }
            addPositionIfNotFound(arrX, arrY, arrSize, size, t->x, t->y);
        }
    }
}

int main(int argc, char *argv[]) {
    int m, arrSize = 9000, size = 1, *x, *y;
    x = safeMalloc(arrSize * sizeof(int));
    y = safeMalloc(arrSize * sizeof(int));
    char c;
    struct position h, t;
    positionBuilder(&h, 0, 0);
    positionBuilder(&t, 0, 0);
    x[0] = 0;
    y[0] = 0;
    while(scanf("%c %d", &c, &m) != EOF) {
        if(c == 'U') {
            moveUp(x, y, &h, &t, m, &arrSize, &size);
        } else if(c == 'L') {
            moveLeft(x, y, &h, &t, m, &arrSize, &size);
        } else if(c == 'D') {
            moveDown(x, y, &h, &t, m, &arrSize, &size);
        } else if(c == 'R') {
            moveRight(x, y, &h, &t, m, &arrSize, &size);
        }
    }
    printf("%d\n", size);

    return 0;
}