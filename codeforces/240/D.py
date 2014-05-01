n, k = map(int, input().split())
s = [[0] * n for i in range(k)]
for i in range(n):
    s[0][i] = 1
for j in range(1, k):
    for i in range(n):
        for k in range(i+1, n+1, i+1):
            s[j][k-1] += s[j-1][i]
            s[j][k-1] = s[j][k-1] % 1000000007
r = 0
for i in s[-1]:
    r += i
    r = r % 1000000007
print(r)
