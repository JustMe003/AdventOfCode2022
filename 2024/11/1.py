from sys import stdin

def blink(n, m):
    # print(n, m)
    if m == 0:
        return 1
    m -= 1
    if n == 0:
        return blink(1, m)
    elif len(str(n)) % 2 == 0:
        s = str(n)
        return blink(int(s[:int(len(s)/2)]), m) + blink(int(s[int(len(s)/2):]), m)
    else:
        return blink(n * 2024, m)

l = [int(x) for x in stdin.readline().rstrip().split()]
total = 0
for n in l:
    total += blink(n, 75)

print(total)
