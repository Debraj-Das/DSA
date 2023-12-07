def solve():
    a = input().split(' ')
    n = int(a[0])
    r = int(a[1])

    if (n - r < r): r = n - r

    ans = 1
    for i in range(r):
        ans = (ans * (n - i)) / (i + 1)

    print(int(ans))


solve()
