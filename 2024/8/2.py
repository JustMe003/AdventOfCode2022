from sys import stdin

def inRange(mat, x, y):
    return x >= 0 and y >= 0 and y < len(mat) and x < len(mat[y])

def placeHashTag(mat, x, y, ix, iy):
    while inRange(mat, x, y):
        mat[y][x] = "#"
        x += ix
        y += iy

def calcDif(mat, x1, y1, x2, y2):
    ix = abs(x2 - x1)
    iy = abs(y2 - y1)
    if x1 < x2:
        if y1 < y2:
            placeHashTag(mat, x1, y1, -ix, -iy)
            placeHashTag(mat, x2, y2, ix, iy)
        else:
            placeHashTag(mat, x1, y1, - ix, iy)
            placeHashTag(mat, x2, y2, ix, -iy)
    else:
        if y1 < y2:
            placeHashTag(mat, x1, y1, ix, -iy)
            placeHashTag(mat, x2, y2, -ix, iy)
        else:
            placeHashTag(mat, x1, y1, ix, iy)
            placeHashTag(mat, x2, y2, -ix, -iy)



mat = []
tab = {}
x = 0
y = 0
for line in stdin:
    row = []
    for c in line.rstrip():
        if c != ".":
            d = tab.get(c)
            if d == None:
                d = []
            d.append((x, y))
            tab[c] = d
        x += 1
        row.append(c)
    x = 0
    y += 1
    mat.append(row)
print(mat)
print(tab)

for k in tab.keys():
    l = tab.get(k)
    for i in range(len(l)):
        x1, y1 = l[i]
        for j in range(i + 1, len(l)):
            x2, y2 = l[j]
            calcDif(mat, x1, y1, x2, y2)

total = 0
for row in mat:
    for c in row:
        print(c, end="")
        if c == "#":
            total += 1
    print()
print(total)