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

void printAllPositions(struct position *p) {
    for(int i = 0; i < 10; i++) {
        printf("%d: (%d, %d)\t", i, p[i].x, p[i].y);
    }
    printf("\n");
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
    arrX[*size] = x;
    arrY[*size] = y;
    (*size)++;
}

void moveUp(int arrX[], int arrY[], struct position *p, int moves, int *arrSize, int *size) {
    for(int i = 0; i < moves; i++) {
        (p[0].x)++;
        for(int j = 1; j < 10; j++) {
            if(abs(p[j-1].x - p[j].x) > 1 && abs(p[j-1].y - p[j].y) > 1) {
                (p[j].x)++;
                if(p[j-1].y - p[j].y > 0) {
                    p[j].y++;
                } else if(p[j-1].y - p[j].y < 0) {
                    p[j].y--;
                }
            } else if(abs(p[j-1].x - p[j].x) > 1) {
                (p[j].x)++;
                if(abs(p[j-1].y - p[j].y) > 0) {
                    p[j].y = (p[j-1].y);
                }
            } else if(abs(p[j-1].y - p[j].y) > 1) {
                (p[j].x)++;
                if(p[j-1].y - p[j].y > 0) {
                    p[j].y++;
                } else if(p[j-1].y - p[j].y < 0) {
                    p[j].y--;
                }
            }
        }
        printAllPositions(p);
        addPositionIfNotFound(arrX, arrY, arrSize, size, p[9].x, p[9].y);
    }
}

void moveLeft(int arrX[], int arrY[], struct position *p, int moves, int *arrSize, int *size) {
    for(int i = 0; i < moves; i++) {
        (p[0].y)--;
        for(int j = 1; j < 10; j++) {
            if(abs(p[j-1].x - p[j].x) > 1 && abs(p[j-1].y - p[j].y) > 1) {
                (p[j].y)--;
                if(p[j-1].x - p[j].x > 0) {
                    p[j].x++;
                } else if(p[j-1].x - p[j].x < 0) {
                    p[j].x--;
                }
            } else if(abs(p[j-1].y - p[j].y) > 1) {
                (p[j].y)--;
                if(abs(p[j-1].x - p[j].x) > 0) {
                    (p[j].x) = (p[j-1].x);
                }
            } else if(abs(p[j-1].x - p[j].x) > 1) {
                (p[j].y)--;
                if(p[j-1].x - p[j].x > 0) {
                    p[j].x++;
                } else if(p[j-1].x - p[j].x < 0) {
                    p[j].x--;
                }
            }
        }
        printAllPositions(p);
        addPositionIfNotFound(arrX, arrY, arrSize, size, p[9].x, p[9].y);
    }
}

void moveDown(int arrX[], int arrY[], struct position *p, int moves, int *arrSize, int *size) {
    for(int i = 0; i < moves; i++) {
        (p[0].x)--;
        for(int j = 1; j < 10; j++) {
            if(abs(p[j-1].x - p[j].x) > 1 && abs(p[j-1].y - p[j].y) > 1) {
                (p[j].x)--;
                if(p[j-1].y - p[j].y > 0) {
                    p[j].y++;
                } else if(p[j-1].y - p[j].y < 0) {
                    p[j].y--;
                }
            } else if(abs(p[j-1].x - p[j].x) > 1) {
                (p[j].x)--;
                if(abs(p[j-1].y - p[j].y) > 0) {
                    (p[j].y) = (p[j-1].y);
                }
            } else if(abs(p[j-1].y - p[j].y) > 1) {
                (p[j].x)--;
                if(p[j-1].y - p[j].y > 0) {
                    p[j].y++;
                } else if(p[j-1].y - p[j].y < 0) {
                    p[j].y--;
                }
            }
        }
        printAllPositions(p);
        addPositionIfNotFound(arrX, arrY, arrSize, size, p[9].x, p[9].y);
    }
}

void moveRight(int arrX[], int arrY[], struct position *p, int moves, int *arrSize, int *size) {
    for(int i = 0; i < moves; i++) {
        (p[0].y)++;
        for(int j = 1; j < 10; j++) {
            if(abs(p[j-1].x - p[j].x) > 1 && abs(p[j-1].y - p[j].y) > 1) {
                (p[j].y)++;
                if(p[j-1].x - p[j].x > 0) {
                    p[j].x++;
                } else if(p[j-1].x - p[j].x < 0) {
                    p[j].x--;
                }
            } else if(abs(p[j-1].y - p[j].y) > 1) {
                (p[j].y)++;
                if(abs(p[j-1].x - p[j].x) > 0) {
                    (p[j].x) = (p[j-1].x);
                }
            } else if(abs(p[j-1].x - p[j].x) > 1) {
                (p[j].y)++;
                if(p[j-1].x - p[j].x > 0) {
                    p[j].x++;
                } else if(p[j-1].x - p[j].x < 0) {
                    p[j].x--;
                }
            }
        }
        printAllPositions(p);
        addPositionIfNotFound(arrX, arrY, arrSize, size, p[9].x, p[9].y);
    }
}

int main(int argc, char *argv[]) {
    int m, arrSize = 9000, size = 1, *x, *y;
    x = safeMalloc(arrSize * sizeof(int));
    y = safeMalloc(arrSize * sizeof(int));
    char c;
    struct position p[10];
    for(int i = 0; i < 10; i++) {
        positionBuilder(&p[i], 0, 0);
    }
    x[0] = 0;
    y[0] = 0;
    while(scanf("%c %d", &c, &m) != EOF) {
        printf("%c %d\n", c, m);
        if(c == 'U') {
            moveUp(x, y, p, m, &arrSize, &size);
        } else if(c == 'L') {
            moveLeft(x, y, p, m, &arrSize, &size);
        } else if(c == 'D') {
            moveDown(x, y, p, m, &arrSize, &size);
        } else if(c == 'R') {
            moveRight(x, y, p, m, &arrSize, &size);
        }
    }
    printf("%d\n", size);

    return 0;
}