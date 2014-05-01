n, m = map(int, input().split())
c = [int(i) for i in input().split()]
closed = [False] * n
ans = [0] * n
for i in c:
    if closed[0]:
        break
    for j in range(i-1, n):
        if not closed[j]:
            closed[j] = True
            ans[j] = i
        else:
            continue
print(' '.join(str(i) for i in ans))
