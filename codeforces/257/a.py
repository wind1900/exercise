n, m = map(int, input().split())
a = list(map(int, input().split()))
ma = a[0] // m + (1 if a[0] % m else 0)
r = 0
for i in range(n):
    t = a[i] // m + (1 if a[i] % m else 0)
    if t >= ma:
        r = i
        ma = t
print(r+1)
