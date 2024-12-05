from sys import stdin

def insert(tab: dict, key, value):
    l = tab.get(key)
    if l == None:
        l = []
    l.append(value)
    tab[key] = l
    return tab

def checkOrder(tab: dict, l: list):
    for i in range(len(l)):
        li = tab.get(l[i])
        if li != None:
            for j in range(i + 1, len(l)):
                if l[j] in li:
                    return False
    return True

def fixLine(before: dict, after: dict, l: list):
    order = []
    while order != l:
        order = l
        for i in range(len(l)):
            for j in range(i + 1, len(l)):
                bef = before.get(l[j])
                aft = after.get(l[i])
                if (bef != None and l[i] in bef) or (aft != None and l[j] in aft):
                    tmp = l[i]
                    l[i] = l[j]
                    l[j] = tmp
    return order[int(len(order) / 2)]

before = {}
after = {}
line = stdin.readline().rstrip()
while line != "":
    splits = line.split("|")
    first = int(splits[0])
    second = int(splits[1])
    before = insert(before, first, second)
    after = insert(after, second, first)

    line = stdin.readline().rstrip()

incorrect = []
for line in stdin:
    order = [int(v) for v in line.split(",")]
    if checkOrder(after, order) and order.reverse() == None and checkOrder(before, order):
        i = 0
    else:
        incorrect.append(order)

total = 0
for line in incorrect:
    total += fixLine(before, after, line)

print(total)