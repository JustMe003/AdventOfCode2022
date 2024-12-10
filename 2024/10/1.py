from sys import stdin

def findPath(mat, x, y, n):
    if mat[y][x] == 9 and n == 9:
        return set([(y + 1) * len(mat) + x])
    n += 1
    ans = set()
    if x > 0 and mat[y][x - 1] == n:
        ans = ans.union(findPath(mat, x - 1, y, n))
    if y > 0 and mat[y - 1][x] == n:
        ans = ans.union(findPath(mat, x, y - 1, n))
    if x < len(mat[y]) - 1 and mat[y][x + 1] == n:
        ans = ans.union(findPath(mat, x + 1, y, n))
    if y < len(mat) - 1 and mat[y + 1][x] == n:
        ans = ans.union(findPath(mat, x, y + 1, n))

    return ans



mat = []
for line in stdin:
    mat.append([int(x) for x in line.rstrip()])

total = 0
for i in range(len(mat)):
    for j in range(len(mat[i])):
        if mat[i][j] == 0:
            total += len(findPath(mat, j, i, 0))

print(total)