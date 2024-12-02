from sys import stdin

min = 1
max = 3

def fun(l, f, dir):
    i = 1
    n = l[0]
    while i < len(l) and f >= 0:
        n2 = n - l[i]
        if abs(n2) >= 1 and abs(n2) <= 3 and ((dir < 0 and n2 < 0) or (dir > 0 and n2 > 0)):
            n = l[i]
        else:
            f -= 1
        i += 1
    return f >= 0

def tryAll(l, f):
    if fun(l, f, 1) or fun(l, f, -1) or fun(l[1:], f - 1, 1) or fun(l[1:], f - 1, -1):
        return 1
    return 0

def main():
    # total = 0
    # for line in stdin:
    #     l = [(int(x)) for x in line.split()]
    #     dir = 0
    #     n = l[0]
    #     i = 1
    #     b = True
    #     b2 = True
    #     while i < len(l):
    #         n2 = n - l[i]
    #         if abs(n2) >= min and abs(n2) <= max and (dir == 0 or (dir < 0 and n2 < 0) or (dir > 0 and n2 > 0)):
    #             n = l[i]
    #             i += 1
    #             dir = n2
    #         else:
    #             if not b:
    #                 b2 = False
    #                 break
    #             b = False
    #             i += 1
                
    #     print(l, b2)
    #     if b2:
    #         total += 1
    total = 0
    for line in stdin:
        total += tryAll([int(x) for x in line.split()], 1)
    print(total)
        

if __name__ == "__main__":
    main()