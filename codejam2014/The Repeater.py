f = open('A-large.in')
out = open('repeater.txt', 'w')
T = int(f.readline().strip())

def compute(l):
    c = [0] * (l[-1]+1)
    t = 0
    s = l[0]
    left = 0
    right = 0
    for i in l:
        c[i] += 1
        t += i - l[0]
    left = c[l[0]]
    right = len(l) - left
    ans = t
    while s < len(c)-1:
        s += 1
        t = t - right + left
        left += c[s]
        right -= c[s]
        ans = min(ans, t)
    return ans

def output(l, out, c):
    ch = l[0][0]
    pattern = [ch]
    for i in l[0]:
        if i == ch:
            continue
        pattern.append(i)
        ch = i
    num = [None] * n
    for i,s in enumerate(l):
        k = 0
        t = [0] * len(pattern)
        for j in s:
            if j != pattern[k]:
                k+=1
                if k >= len(pattern) or j != pattern[k]:
                    out.write('Case #%d: Fegla Won\n' % (c+1))
                    return
            t[k] += 1
        for j in t:
            if j == 0:
                out.write('Case #%d: Fegla Won\n' % (c+1))
                return
        num[i] = t
    r = 0
    for i in range(len(pattern)):
        t = [j[i] for j in num]
        t.sort()
        r += compute(t)
    out.write('Case #%d: %d\n' % (c+1, r))

for c in range(T):
    n = int(f.readline().strip())
    l = [None] * n
    for i in range(n):
        l[i] = f.readline().strip()
    output(l, out, c)
out.close()
f.close()
