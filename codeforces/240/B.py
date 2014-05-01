import math
n, a, b = map(int, input().split())
x = [int(i) for i in input().split()]
ans = [0] * n
for i, w in enumerate(x):
    r = (w * a) // b
    ans[i] = w - math.ceil(r * b / a)
    if ans[i] < 0:
        ans[i] = 0
print(' '.join(str(i) for i in ans))
