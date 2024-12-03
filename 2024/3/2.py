import re
from sys import stdin

pat = re.compile(r"mul\(([0-9]+),([0-9]+)\)")
dont = re.compile(r"don't\(\)")

def f(s):
    total = 0
    for n1, n2 in re.findall(pat, s):
        total += int(n1) * int(n2)
    return total

total = 0
s = ""
for line in stdin:
    s += line

for s1 in re.split(dont, s):
    i = s1.find("do()")
    if i > 0:
        total += f(s1[i:])

print(total)