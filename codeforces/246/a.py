n, k = map(int, input().split())
k = 6 - k
l = map(int, input().split())
c = 0
for i in l:
    if i < k:
        c += 1
print(c//3)
