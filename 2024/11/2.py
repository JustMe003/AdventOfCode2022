from sys import stdin

def blink(n, m, t: dict):
    if m == 0:
        return 1
    if n in t.keys() and m in t[n].keys():
        # print(n, m, t[n][m])
        return t[n][m]
    m -= 1
    if n == 0:
        c = blink(1, m, t)
        if m > 0:
            if 0 not in t.keys():
                t.update({0: {}})
            t1 = t.get(0)
            t1.update({m: c})
        return c
    elif len(str(n)) % 2 == 0:
        s = str(n)
        n1 = int(s[:int(len(s)/2)])
        c = blink(n1, m, t)
        if m > 0:
            if n1 not in t.keys():
                t.update({n1: {}})
            t1 = t.get(n1)
            t1.update({m: c})
        n2 = int(s[int(len(s)/2):])
        c2 = blink(n2, m, t)
        if m > 0:
            if n2 not in t.keys():
                t.update({n2: {}})
            t2 = t.get(n2)
            t2.update({m: c2})
        return c + c2
    else:
        n1 = n * 2024
        c = blink(n1, m, t)
        if m > 0:
            if n1 not in t.keys():
                t.update({n1: {}})
            t1 = t.get(n1)
            t1.update({m: c})
        return c

l = [int(x) for x in stdin.readline().rstrip().split()]
t = {}

total = 0
for n in l:
    total += blink(n, 9, t)
    print(total)

for k in t.keys():
    print(k, t.get(k))
print(total)
