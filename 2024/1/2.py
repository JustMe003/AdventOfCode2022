from sys import stdin


def main():
    l1 = []
    l2 = []
    for line in stdin:
        splits = line.split()
        l1.append(int(splits[0]))
        l2.append(int(splits[1]))
    
    l1.sort()
    l2.sort()

    total = 0
    i1 = 0
    i2 = 0
    while i1 < len(l1) and i2 < len(l2):
        print(l1[i1], l2[i2], total)
        n = l1[i1]
        i1 += 1
        x = 1
        while i1 < len(l1) and l1[i1] == n:
            i1 += 1
            x += 1
        y = 0
        while i2 < len(l2) and l2[i2] <= n:
            if l2[i2] == n:
                y += 1
            i2 += 1
        total += x * y * n
    print(total)

if __name__ == "__main__":
    main()