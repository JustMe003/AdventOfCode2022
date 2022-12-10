
def main():
    inp = "noop noop addx 5 addx 1 noop noop addx 3 addx 1 addx 6 noop addx -1 addx 5 addx 1 noop addx 4 addx 1 noop addx -6 addx 12 noop addx 3 addx 1 addx -26 addx -12 addx 5 addx 19 addx -3 addx -13 addx 2 noop addx 3 addx 2 noop addx 3 addx 15 addx -8 addx 2 addx 6 noop addx -23 addx 20 addx 3 addx 2 addx 5 addx -40 noop noop addx 3 addx 6 addx -2 noop addx 5 noop noop addx 5 addx -2 addx 9 noop noop noop addx -14 addx 17 noop noop addx 8 noop noop addx -2 addx 4 noop noop addx -35 noop noop noop addx -1 addx 5 addx 6 noop addx -4 addx 5 addx 2 addx 3 noop addx 5 addx 14 addx -10 addx -25 addx 1 addx 38 addx -6 addx 2 addx 3 addx -2 addx -38 noop addx 9 addx -4 noop addx 25 addx -20 noop addx 3 addx 2 addx 5 addx 2 addx -9 addx 14 addx -2 noop noop addx 7 addx 3 addx -2 addx 2 noop addx 3 addx -38 noop addx 7 noop noop addx 1 noop addx 3 addx 1 noop noop addx 6 noop addx 4 addx 1 noop noop addx 4 addx 1 addx 7 addx -3 addx 5 noop noop noop noop noop noop noop".split()
    n = 1
    c = 1
    r = 0
    nextIsNumber = False
    for i in inp:
        n = n + 1
        if i == "addx":
            nextIsNumber = True
        elif nextIsNumber:
            print(c, i)
            c = c + int(i)
            nextIsNumber = False
        if n % 40 == 20:
            print(r, c, c * n)
            r = r + (c * n)
    print(n, c, r)

if __name__ == "__main__":
    main()