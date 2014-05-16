f = open('A-large (1).in')
out = open('co1.txt', 'w')

def gcd(p, q):
    r = p % q
    while r != 0:
        p = q
        q = r
        r = p % q
    return q

t = int(f.readline())
for c in range(t):
    p,q = map(int, f.readline().split('/'))
    g = gcd(p,q)
    q = q // g
    p = p // g
    t = q & (q - 1)
    if t != 0:
        out.write('Case #%d: %s\n' % (c+1, 'impossible'))
        continue
    r = 0
    while p < q and r <= 40:
        r+=1
        q = q // 2
    if r <= 40:
        out.write('Case #%d: %d\n' % (c+1, r))
    else:
        out.write('Case #%d: %s\n' % (c+1, 'impossible'))

out.close()
f.close()
