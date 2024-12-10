from sys import stdin


mode = 1
id = 0
disk = []
for x in stdin.readline().rstrip():
    if mode:
        for _ in range(int(x)):
            disk.append(id)
        id += 1
    else:
        for _ in range(int(x)):
            disk.append(-1)
    mode = (mode + 1) % 2

s = 0
e = len(disk) - 1
while s < e:
    if disk[s] < 0:
        while disk[e] < 0 and s < e:
            e -= 1
        if disk[e] > 0:
            disk[s] = disk[e]
            disk[e] = -1
    s += 1

# print(disk)
total = 0
i = 0
while disk[i] >= 0:
    total += (i * disk[i])
    i += 1
print(total)