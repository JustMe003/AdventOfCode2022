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

total = 0
for line in stdin:
    order = [int(v) for v in line.split(",")]
    if checkOrder(after, order) and order.reverse() == None and checkOrder(before, order):
        total += order[int(len(order) / 2)]
    
print(total)