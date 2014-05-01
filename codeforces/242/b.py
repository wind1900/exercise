import math

n,s = (int(i) for i in input().strip().split())
l = [None] * n
for i in range(n):
    x,y,p = map(int, input().split())
    l[i] = (x*x+y*y, p)
l.sort(key=lambda x:x[0])
r = 1000000 - s
for i in l:
    r -= i[1]
    if r <= 0:
        print("%.7f" % (math.sqrt(i[0])))
        break
if r > 0:
    print(-1)
