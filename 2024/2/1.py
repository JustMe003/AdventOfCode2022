from sys import stdin

min = 1
max = 3

def main():
    total = 0
    for line in stdin:
        l = [(int(x)) for x in line.split()]
        dir = 0
        n = l[0]
        i = 1
        b = True
        while i < len(l):
            n2 = n - l[i]
            if abs(n2) >= min and abs(n2) <= max and (dir == 0 or (dir < 0 and n2 < 0) or (dir > 0 and n2 > 0)):
                n = l[i]
                i += 1
                dir = n2
            else:
                b = False
                break
        if b:
            total += 1
    print(total)
        

if __name__ == "__main__":
    main()