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

def printMat(mat):
    c = 0
    for i in mat:
        print(c, end="\t")
        for j in i:
            print(j, end="")

        print()
        c += 1

def findLoop(mat, x, y, dir):
    # print(x2, y2, dir)
    x, y = getPrevCords(x, y, dir)
    keyPoints = [(x, y)]
    dir = (dir + 1) % 4
    x, y = getCords(x, y, dir)
    while inRange(mat, x, y) and not ((x, y) in keyPoints):
        if mat[y][x] == "#":
            x, y = getPrevCords(x, y, dir)
            dir = (dir + 1) % 4
            keyPoints.append((x, y))
        x, y = getCords(x, y, dir)
    # if (x, y) in keyPoints:
        # print(keyPoints)
    return (x, y) in keyPoints

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

total = 0
dir = 1
loc = []
while inRange(mat, x, y):
    if mat[y][x] == "#":
        x, y = getPrevCords(x, y, dir)
        dir = (dir + 1) % 4
        x, y = getCords(x, y, dir)
    else:
        # mat[y][x] = "X"
        x, y = getCords(x, y, dir)
        if (x, y) not in loc and inRange(mat, x, y) and findLoop(mat, x, y, dir):
            total += 1
            loc.append((x, y))
            mat[y][x] = "0"
            # printMat(mat)
        x, y = getPrevCords(x, y, dir)

        x, y = getCords(x, y, dir)

printMat(mat)
print(total)