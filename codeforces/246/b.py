n = int(input())
c = [0] * 100001
y = [0] * n
for i in range(n):
    x, y[i] = map(int, input().split())
    c[x]+=1

for i in range(n):
    a = n - 1 + c[y[i]]
    b = 2 * n - 2 - a
    print(a, b)

