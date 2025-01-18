from sys import stdin

def nextline():
    return stdin.readline().rstrip()

total = 0
line = nextline()
while len(line) > 0:
    splits = line.split()
    a = (int(splits[2][2:-1]), int(splits[3][2:]))
    line = nextline()
    splits = line.split()
    b = (int(splits[2][2:-1]), int(splits[3][2:]))
    line = nextline()
    splits = line.split()
    prize = (int(splits[1][2:-1]), int(splits[2][2:]))

    for i in range(min(100, int(prize[0] / b[0]), int(prize[1] / b[1])), 0, -1):
        p = (b[0] * i, b[1] * i)
        # print(i, p, (prize[0] - p[0]), (prize[1] - p[1]))
        if (prize[0] - p[0]) % a[0] == 0 and (prize[1] - p[1]) % a[1] == 0:
            print(i, int((prize[0] - p[0]) / a[0]), i + int((prize[0] - p[0]) / a[0]) * 3)
            total += i + int((prize[0] - p[0]) / a[0]) * 3
            break
        if (prize[0] - p[0]) / a[0] > 100 or (prize[1] - p[1]) / a[1] > 100:
            break
        
    
    nextline()
    line = nextline()

print(total)