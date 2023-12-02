import math


def fd(n):
    if n < 0:
        return 0
    if n <= 1:
        return 1
        
    digits = 0
    for i in range(2, n + 1):
        digits += math.log10(i)
    return math.floor(digits) + 1


x = int(input())

print(f"Number of digits of {x}! is {fd(x)}")
