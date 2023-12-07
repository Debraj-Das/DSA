import sys
import os
import math

sys.setrecursionlimit(100000000)
def inp(): return int(input())
def strng(): return input().strip()


def jn(x, l): return x.join(map(str, l))
def strl(): return list(input().strip())


def mul(): return map(int, input().strip().split())
def mulf(): return map(float, input().strip().split())
def seq(): return list(map(int, input().strip().split()))


def ceil(x): return int(x) if (x == int(x)) else int(x)+1
def ceildiv(x, d): return x//d if (x % d == 0) else x//d+1


def main(bool=False):
    t = 1
    if bool:
        t = inp()
    for _ in range(t):
        solve()

# Code for Every test case


def solve():
    print("Hello World")


main()
