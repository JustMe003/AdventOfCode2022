def moveObjects(l, count, source, dest):
    for i in range(count, 0, -1):
        l[dest].append(l[source][max(len(l[source]) - i, 0)])
        l[source].pop(max(len(l[source]) - i, 0))

def main():
    f = open("input.txt", "r")
    contents = f.readlines()
    l = []
    size = 0
    line = 0

    for i in contents:
        line = line + 1
        if size == 0:
            size = int(len(i) / 4)
            for j in range(size):
                l.append([])
        hasSquareBracket = False
        for j in i:
            if j == '[':
                hasSquareBracket = True
        if not hasSquareBracket:
            break
        for j in range(size):
            if i[1 + (4 * j)] != " ":
                l[j].insert(0, i[1 + (4 * j)])
    
    line = line + 1
    for i in contents:
        if line <= 0:
            input = i.split()
            moveObjects(l, int(input[1]), int(input[3]) - 1, int(input[5]) - 1)
        line = line - 1

    for j in l:
        print(j)
    
    f.close()


if __name__ == '__main__':
    main()