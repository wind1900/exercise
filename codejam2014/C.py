f = open('ctest.txt')
out = open('c.txt', 'w')
T = int(f.readline().strip())
for case in range(T):
    out.write('Case #%d:\n' % (case+1,))
    r, c, m = (int(i) for i in f.readline().strip().split())
    l = ['*'] * c
    grid = [l[:] for i in range(r)]
    grid[0][0] = 'c'
    if r == 1:
        for i in range(r*c-m-1):
            grid[0][i+1] = '.'
    elif c == 1:
        for i in range(r*c-m-1):
            grid[i+1][0] = '.'
    elif r * c - m == 2 or r * c - m == 3:
        out.write('Impossible\n')
        continue
    elif r * c - m >= 4:
        grid[0][1] = '.'
        grid[1][0] = '.'
        grid[1][1] = '.'
        t = r * c - m - 4
        if t:
            for i in range(r):
                for j in range(c):
                    if grid[i][j] == '*':
                        t-=1
                        grid[i][j] = '.'
                        if t <= 0:
                            break
                if t <= 0:
                    break
    for i in range(r):
        out.write(''.join(grid[i]))
        out.write('\n')
out.close()
f.close()
