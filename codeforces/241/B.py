m, n = (int(i) for i in input().split(' '))
time = [None] * m
for i in range(m):
    time[i] = list(int(i) for i in input().split(' '))
r = [0] * m
r[0] = time[0][0]
for i in range(1, m):
    r[i] = r[i - 1] + time[i][0]
for i in range(1,n):
    r[0] += time[0][i]
    for j in range(1,m):
        r[j] = time[j][i] + max(r[j-1],r[j])
print(' '.join(str(i) for i in r))
