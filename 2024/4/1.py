from sys import stdin

def next(c):
    if c == "X":
        return "M"
    elif c == "M":
        return "A"
    elif c == "A":
        return "S"
    elif c == "S":
        return True

def search(mat, y0, x0, yi, xi, c):
    if y0 < 0 or y0 >= len(mat) or x0 < 0 or x0 >= len(mat[y0]):
        return False
    # print(mat[y0][x0], c)
    if mat[y0][x0] == c:
        c = next(c)
        if c == True: return True
        return search(mat, y0 + yi, x0 + xi, yi, xi, c)
    else:
        return False

total = 0
mat = []
for line in stdin:
    mat.append(line.rstrip())
    print(line.rstrip())

for i in range(len(mat)):
    for j in range(len(mat[i])):
        if mat[i][j] == "X":
            if search(mat, i, j, 1, 1, "X"): total += 1
            if search(mat, i, j, 0, 1, "X"): total += 1
            if search(mat, i, j, -1, 1, "X"): total += 1
            if search(mat, i, j, 1, 0, "X"): total += 1
            if search(mat, i, j, -1, 0, "X"): total += 1
            if search(mat, i, j, 1, -1, "X"): total += 1
            if search(mat, i, j, 0, -1, "X"): total += 1
            if search(mat, i, j, -1, -1, "X"): total += 1
print(total)
