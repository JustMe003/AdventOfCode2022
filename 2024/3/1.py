import re
from sys import stdin

pat = re.compile(r"mul\(([0-9]+),([0-9]+)\)")

total = 0
for line in stdin:
    for n1, n2 in re.findall(pat, line):
        total += int(n1) * int(n2)

print(total)