from sys import stdin

def validExpr(n, nums, v):
    if len(nums) == 0:
        return n == v
    return validExpr(n, nums[1:], v + nums[0]) or validExpr(n, nums[1:], v * nums[0])

total = 0
for line in stdin:
    i = line.find(": ")
    n = int(line[:i])
    nums = [int(x) for x in line[i + 2:].split(" ")]
    if validExpr(n, nums[1:], nums[0]):
        total += n

print(total)