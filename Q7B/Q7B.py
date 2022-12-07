goBackToRoot = False
n = 0

def recursiveFill(inp):
    global goBackToRoot
    global n
    data = {}
    for i in range(n, len(inp)):
        if goBackToRoot or n >= len(inp):
            return data
        l = inp[n].split()
        n = n + 1
        if l[0] == "$":
            if l[1] == "cd":
                if l[2] == "..":
                    return data
                elif l[2] == "/":
                    goBackToRoot = True
                    return data
                else:
                    data[l[2]] = recursiveFill(inp)
        else:
            if l[0] != "dir":
                data[l[1]] = int(l[0])
    return data
        
def countAllDirectories(data):
    c = 0
    for v in data.items():
        if isinstance(v[1], int):
            c = c + v[1]
        else:
            c = c + countAllDirectories(v[1])
    return c

def findSmallestDirectory(data, min):
    c = countAllDirectories(data)
    for v in data.items():
        if not isinstance(v[1], int):
            a = findSmallestDirectory(v[1], min)
            if a >= min and (c == -1 or a < c):
                c = a
    return c

def main():
    global n
    global goBackToRoot
    f = open("input.txt", "r")
    inp = f.readlines()
    data = {}
    while n < len(inp):
        data = recursiveFill(inp)
        n = n + 1
        goBackToRoot = False
    print(findSmallestDirectory(data, 30000000 - (70000000 - countAllDirectories(data))))
    f.close()

    

if __name__ == '__main__':
    main()