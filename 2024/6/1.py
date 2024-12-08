from sys import stdin

def getCords(x, y, dir):
    if dir == 1:
        return x, y - 1
    elif dir == 2:
        return x + 1, y
    elif dir == 3:
        return x, y + 1
    else:
        return x - 1, y

def getPrevCords(x, y, dir):
    if dir == 1:
        return x, y + 1
    elif dir == 2:
        return x - 1, y
    elif dir == 3:
        return x, y - 1
    else:
        return x + 1, y

def inRange(mat, x, y):
    return y >= 0 and y < len(mat) and x >= 0 and x < len(mat[y])

mat = []
x = -1
y = 0
for line in stdin:
    mat.append([x for x in line.rstrip()])
    n = line.find("^")
    if n > 0:
        x = n
    if x < 0:
        y += 1

dir = 1
while inRange(mat, x, y):
    if mat[y][x] != "#":
        mat[y][x] = "X"
        x, y = getCords(x, y, dir)
    else:
        x, y = getPrevCords(x, y, dir)
        dir = (dir + 1) % 4
        x, y = getCords(x, y, dir)

total = 0
for row in mat:
    for v in row:
        if v == "X":
            total += 1
print(total)