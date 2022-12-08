#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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

int isVisible(int **mat, int x, int y, int n, int m) {
    int isVisible = 1;
    for(int i = 0; i < x; i++) {
        if(mat[x][y] <= mat[i][y]) {
            isVisible = 0;
            break;
        }
    }
    if(isVisible) {
        return 1;
    }
    isVisible = 1;
    for(int i = 0; i < y; i++) {
        if(mat[x][y] <= mat[x][i]) {
            isVisible = 0;
            break;
        }
    }
    if(isVisible) {
        return 1;
    }
    isVisible = 1;
    for(int i = x + 1; i < n; i++) {
        if(mat[x][y] <= mat[i][y]) {
            isVisible = 0;
            break;
        }
    }
    if(isVisible) {
        return 1;
    }
    isVisible = 1;
    for(int i = y + 1; i < m; i++) {
        if(mat[x][y] <= mat[x][i]) {
            isVisible = 0;
            break;
        }
    }
    return isVisible;
}

void getVisibleTrees(int **mat, int n, int m, int *total) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(isVisible(mat, i, j, n, m)) {
                (*total)++;
            }
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