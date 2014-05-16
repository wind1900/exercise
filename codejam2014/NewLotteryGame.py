f = open('B-small-attempt0 (1).in')
out = open('lottery.txt', 'w')
T = int(f.readline().strip())
for c in range(T):
    a,b,k = map(int, f.readline().strip().split())
    r = 0
    for i in range(a):
        for j in range(b):
            if i&j < k:
                r+=1
    out.write('Case #%d: %d\n' % (c+1, r))
f.close()
out.close()
