from sys import stdin

def search(mat, y, x):
    if y < 1 or y + 1 >= len(mat) or x < 1 or x + 1 >= len(mat[y]):
        return False
    if mat[y + 1][x + 1] in "MS" and mat[y - 1][x + 1] in "MS" and mat[y - 1][x - 1] in "MS" and mat[y + 1][x - 1] in "MS":
        return mat[y + 1][x + 1] != mat[y - 1][x - 1] and mat[y + 1][x - 1] != mat[y - 1][x + 1]
    return False

total = 0
mat = []
for line in stdin:
    mat.append(line.rstrip())
    print(line.rstrip())

for i in range(len(mat)):
    for j in range(len(mat[i])):
        if mat[i][j] == "A":
            if search(mat, i, j): total += 1
            
print(total)
