n,m,t = map(int, input().split())
p,u,d = map(int, input().split())
h = [None] * n
for i in range(n):
    h[i] = [int(i) for i in input().split()]
row = [None] * n
col = [None] * m
for i in range(n):
    row[i] = [None] * m
    for j in range(m):
        row[i][j] = [None] * m
        row[i][j][j] = 0
        for k in range(j-1, -1, -1):
            if h[i][k+1] > h[i][k]:
                row[i][j][k] = row[i][j][k+1] + d
            elif h[i][k+1] == h[i][k]:
                row[i][j][k] = row[i][j][k+1] + p
            else:
                row[i][j][k] = row[i][j][k+1] + u
        for k in range(j+1,m):
            if h[i][k-1] > h[i][k]:
                row[i][j][k] = row[i][j][k-1] + d
            elif h[i][k-1] == h[i][k]:
                row[i][j][k] = row[i][j][k-1] + p
            else:
                row[i][j][k] = row[i][j][k-1] + u
                
for i in range(m):
    col[i] = [0] * (n * n)
    for j in range(n):
        col[i][j] = [None] * n
        col[i][j][j] = 0
        for k in range(j-1,-1,-1):
            if h[k+1][i] > h[k][i]:
                col[i][j][k] = col[i][j][k+1]+d
            elif h[k+1][i] == h[k][i]:
                col[i][j][k] = col[i][j][k+1]+p
            else:
                col[i][j][k] = col[i][j][k+1]+u
        for k in range(j+1,n):
            if h[k-1][i] > h[k][i]:
                col[i][j][k] = col[i][j][k-1]+d
            elif h[k-1][i] == h[k][i]:
                col[i][j][k] = col[i][j][k-1]+p
            else:
                col[i][j][k] = col[i][j][k-1]+u
r = [0,0,0,0]
tt = 9000001
for i in range(n):
    for j in range(i+2,n):
        for k in range(m):
            for l in range(k+2,m):
                ct = row[i][k][l] + row[j][l][k] + col[k][j][i] + col[l][i][j]
                if abs(ct-t) < tt:
                    r[0] = i
                    r[2] = j
                    r[1] = k
                    r[3] = l
                    tt = abs(ct-t)
print(r[0]+1,r[1]+1,r[2]+1,r[3]+1)
