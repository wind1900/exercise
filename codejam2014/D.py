def win(a, b):
    i = 0
    j = 0
    while i < len(a):
        while j < len(b) and b[j] < a[i]:
            j += 1
        if j == len(b):
            break
        j += 1
        i += 1
    return len(a) - i

def decewin(a, b):
    

f = open('dtest.txt')
out = open('d.txt', 'w')
T = int(f.readline().strip())
for case in range(T):
    n = int(f.readline().strip())
    a = list(float(i) for i in f.readline().strip().split())
    b = list(float(i) for i in f.readline().strip().split())
    a.sort()
    b.sort()
    ans1 = max(decewin(a[i:], b[:n-i]) for i in range(n))
    ans2 = win(a,b)
    out.write('Case #%d: %d %d\n' % (case+1, ans1, ans2))
out.close()
f.close()
    
