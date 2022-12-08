#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// safely call malloc
void *safeMalloc(int n) {
  void *p = malloc(n);
  if (p == NULL) {
    printf("Error: malloc(%d) failed. Out of memory?\n", n);
    exit(EXIT_FAILURE);
  }
  return p;
}

// free a matrix
void destroyIntArray2D(int **arr) {
  free(arr[0]);
  free(arr);
}

// create a matrix
int **makeIntArray2D(int width, int height) {
  int **arr = safeMalloc(height*sizeof(int *));
  arr[0] = safeMalloc(width*height*sizeof(int));
  for (int row=1; row < height; row++) {
    arr[row] = arr[row-1] + width;
  }
  return arr;
}

int getNumberOfVisibleTrees(int **mat, int x, int y, int n, int m) {
    int visibilityTop = 1, visibilityLeft = 1, visibilityBottom = 1, visibilityRight = 1;
    for(int i = x - 1; i >= 1; i--) {
        if(mat[x][y] <= mat[i][y]) {
            break;
        } else {
            visibilityTop++;
        }
    }
    for(int i = y - 1; i >= 1; i--) {
        if(mat[x][y] <= mat[x][i]) {
            break;
        } else {
            visibilityLeft++;
        }
    }
    for(int i = x + 1; i < n - 1; i++) {
        if(mat[x][y] <= mat[i][y]) {
            break;
        } else {
            visibilityBottom++;
        }
    }
    for(int i = y + 1; i < m - 1; i++) {
        if(mat[x][y] <= mat[x][i]) {
            break;
        } else {
            visibilityRight++;
        }
    }
    return visibilityTop * visibilityLeft * visibilityBottom * visibilityRight;
}

void getVisibleTrees(int **mat, int n, int m, int *total) {
    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < m - 1; j++) {
            *total = MAX((*total), getNumberOfVisibleTrees(mat, i, j, n, m));
        }
    }
}

int main(int argc, char *argv[]) {
    int size = 99;
    int **mat = makeIntArray2D(size, size), visibleTrees = 0;
    char c;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            scanf(" %c", &c);
            mat[i][j] = c - '0';
        }
    }
    getVisibleTrees(mat, size, size, &visibleTrees);
    printf("%d\n", visibleTrees);
    destroyIntArray2D(mat);
    return 0;
}