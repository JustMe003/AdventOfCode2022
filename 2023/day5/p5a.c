#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct map {
    long source;
    long dest;
    long range;
} map;

typedef struct maps {
    map *arr;
    int size;
    int index;
} maps;

typedef struct longs {
    long start;
    long range;
} longs;
/*
void mapArray(longs *arr, int size, map *maps, int mapSize) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < mapSize; j++) {
            if (maps[j].source <= arr[i] && maps[j].source + maps[j].range - 1 >= arr[i]) {
                arr[i] = maps[j].dest - maps[j].source + arr[i];
                break;
            }
        }
    }
}*/

long getMinSeedNumber(longs *arr, int size, int src, int range) {
    long min = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i].start <= src && arr[i].start + arr[i].range > src) {
            return src;
        } else if (arr[i].start >= src && arr[i].start < src + range) {
            if (min == -1) {
                min = arr[i].start;
            } else if (min > arr[i].start) {
                min = arr[i].start;
            }
        }
    }
    return min;
}

long traceBack(maps *maps, int index, longs *arr, int size, long dest, long range) {
    printf("%ld %ld\n", dest, range);
    if (index < 0) {
        printf("checking ^ for seeds\n");
        return getMinSeedNumber(arr, size, dest, range);
    }
    if (range < 0) {
        return -1;
    }
    for (int i = 0; i < maps[index].index; i++) {
        if (maps[index].arr[i].dest <= dest && maps[index].arr[i].dest + maps[index].arr[i].range > dest) {
            printf("in range: %ld - %ld\n", maps[index].arr[i].dest, maps[index].arr[i].range + maps[index].arr[i].dest);
            long res = traceBack(maps, index - 1, arr, size, dest - maps[index].arr[i].dest + maps[index].arr[i].source, MIN(range, maps[index].arr[i].range));
            if (res == -1 && range > maps[index].arr[i].range) {
                printf("not in: %ld - %ld\tsearching in: %ld - %ld\n", maps[index].arr[i].dest, maps[index].arr[i].range + maps[index].arr[i].dest, dest + maps[index].arr[i].range, range - maps[index].arr[i].range);
                return traceBack(maps, index, arr, size, dest + maps[index].arr[i].range, range - maps[index].arr[i].range);
            }
            return res;
        }
    }
    // there is no map that fits
    // so we want to seach in [dest] - [first dest above [dest] + [range]] - [dest]
    long min = 0;
    for (int i = 0; i < maps[index].index; i++) {
        if (!min && maps[index].arr[i].dest > dest) {
            min = maps[index].arr[i].dest;
        } else if (maps[index].arr[i].dest > dest && maps[index].arr[i].dest < min) {
            min = maps[index].arr[i].dest;
        }
    }
    long range2 = range;
    if (min) {
        range2 = min - dest;
    }
    printf("searching in: %ld - %ld\n", dest, range2);  
    long res = traceBack(maps, index - 1, arr, size, dest, range2);
    if (res == -1 && min && range + dest - min > 0) {
        printf("not in: %ld - %ld\tsearching in: %ld - %ld\n", dest, range, min, range + dest - min);
        return traceBack(maps, index, arr, size, min, range + dest - min);
    } else {
        printf("not in: %ld - %ld\n", dest, range);
    }
    return res;
}

long getLowestSeed(maps *maps, int mapSize, longs *arr, int size) {
    map mapMin = maps[mapSize - 1].arr[0];
    long min = maps[mapSize - 1].arr[0].dest;
    for (int i = 0; i < maps[mapSize - 1].index; i++) {
        if (maps[mapSize - 1].arr[i].dest < min) {
            min = maps[mapSize - 1].arr[i].dest;
            mapMin = maps[mapSize - 1].arr[i];
        }
    }
    return traceBack(maps, mapSize - 2, arr, size, mapMin.source, mapMin.range);
}

int main(int argc, char *argv[]) {
    int size = 2, index = 0;
    longs *arr = malloc(size * sizeof(longs));
    char c, *mapName = malloc(sizeof(char));
    scanf("seeds:%c", &c);
    while (c != '\n') {
        longs l;
        scanf("%ld %ld%c", &l.start, &l.range, &c);
        arr[index] = l;
        index++;
        if (index == size) {
            size *= 2;
            arr = realloc(arr, size * sizeof(longs));
        }
    }
    size = index;
    arr = realloc(arr, size * sizeof(longs));

    int mapArrSize = 2, mapArrIndex = 0;
    maps *mapsArr = malloc(mapArrSize * sizeof(maps));
    do {
        int mapSize = 2, mapIndex = 0;
        map *mapArray = malloc(mapSize * sizeof(map));
        free(mapName);
        scanf("%ms map:\n", &mapName);
        do {
            map m;
            scanf("%ld %ld %ld%c", &m.dest, &m.source, &m.range, &c);
            mapArray[mapIndex] = m;
            mapIndex++;
            if (mapIndex == mapSize) {
                mapSize *= 2;
                mapArray = realloc(mapArray, mapSize * sizeof(map));
            }
        } while (c != '#');

        maps m;
        m.arr = mapArray;
        m.size = mapSize;
        m.index = mapIndex;
        mapsArr[mapArrIndex] = m;
        mapArrIndex++;
        if (mapArrIndex == mapArrSize) {
            mapArrSize *= 2;
            mapsArr = realloc(mapsArr, mapArrSize * sizeof(maps));
        }

    } while (strcmp(mapName, "humidity-to-location"));

    //long min = getLowestSeed(mapsArr, mapArrIndex, arr, size);
    printf("%ld\n", traceBack(mapsArr, mapArrIndex - 2, arr, size, 0, 55));

    for (int i = 0; i < mapArrIndex; i++) {
        free(mapsArr[i].arr);
    }
    free(mapName);
    free(mapsArr);
    free(arr);
    return 0;
}
