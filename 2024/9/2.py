from sys import stdin


mode = 1
id = 0
disk = []
space = []

for x in stdin.readline().rstrip():
    v = int(x)
    if mode:
        for _ in range(v):
            disk.append(id)
        id += 1
    else:
        if v > 0:
            space.append((len(disk), v))
        for _ in range(v):
            disk.append(-1)
    mode = (mode + 1) % 2

space.reverse()
print(disk)
# print(space)

e = len(disk) - 1
while e >= 0 and space[len(space) - 1][0] < e:
    # print(space[len(space) - 1][0], e)
    if disk[e] >= 0:
        id = disk[e]
        size = 0
        while e >= 0 and disk[e] == id:
            size += 1
            e -= 1
        i = len(space) - 1
        while i >= 0:
            pair = space[i]
            if pair[1] >= size:
                s = pair[0]
                for j in range(size):
                    disk[s + j] = id
                    disk[e + j + 1] = -1
                if pair[1] > size:
                    space[i] = (pair[0] + size, pair[1] - size)
                else:
                    space.pop(i)
                # print(disk)
                # print(space)
                break
            i -= 1
    else:    
        e -= 1

print(disk)

total = 0
i = 0
while i < len(disk):
    if disk[i] > 0:
        total += (i * disk[i])
    i += 1
print(total)