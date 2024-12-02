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
    for i in range(len(l1)):
        total += abs(l1[i] - l2[i])
    print(total)

if __name__ == "__main__":
    main()