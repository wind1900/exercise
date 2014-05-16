f = open('B-small-attempt2.in')
out = open('co2.txt', 'w')
mod = 1000000007

def same(s):
    for i in s:
        if i != s[0]:
            return False
    return True

def jie(n):
    r = 1
    for i in range(1, n+1):
        r = (r * i) % mod
    return r

def midused(used, s):
    i = 0
    j = len(s) - 1
    while i < len(s) and s[i] == s[0]:
        i += 1
    while j >= 0 and s[j] == s[-1]:
        j -= 1
    for k in range(len(s)):
        if used[ord(s[k])-ord('a')]:
            return True
        k += 1
    k = i
    while k <= j:
        used[ord(s[k])-ord('a')] = True
        k += 1
    return False

def notadj(s):
    i = 0
    used = [False] * 26
    c = s[i]
    used[ord(c)-ord('a')] = True
    while i < len(s):
        if s[i] != c:
            c = s[i]
            if used[ord(c) - ord('a')]:
                return True
            used[ord(c) - ord('a')] = True
        i += 1
    return False

def output(cars, out, n):
    
    first = [0] * 26
    last = [0] * 26
    allsame = [0] * 26
    l = n
    used = [False] * 26
    
    for i in cars:
        if notadj(i):
            out.write('Case #%d: %d\n' % (c+1, 0))
            return
        if i[0] == i[-1]:
            if same(i):
                allsame[ord(i[0])-ord('a')] += 1
                l -= 1
                if used[ord(i[0]) - ord('a')]:
                    out.write('Case #%d: %d\n' % (c+1, 0))
                    return
            else:
                out.write('Case #%d: %d\n' % (c+1, 0))
                return
        else:
            if midused(used, i):
                out.write('Case #%d: %d\n' % (c+1, 0))
                return
            first[ord(i[0])-ord('a')] += 1
            last[ord(i[-1])-ord('a')] += 1

    for i in range(26):
        if allsame[i] > 0 or first[i] > 0 or last[i] > 0:
            if used[i]:
                out.write('Case #%d: %d\n' % (c+1, 0))
                return
    
    for i in range(26):
        if first[i] > 1 or last[i] > 1:
            out.write('Case #%d: %d\n' % (c+1, 0))
            return
        elif first[i] == 1 and last[i] == 1:
            l -= 1

    r = 1
    
    for i in range(26):
        r = r * jie(allsame[i]) % mod
        if allsame[i] != 0 and first[i] == 0 and last[i] == 0:
            l += 1
    r = r * jie(l) % mod
    out.write('Case #%d: %d\n' % (c+1, r))

t = int(f.readline())
for c in range(t):
    n = int(f.readline())
    cars = f.readline().split()
    output(cars, out, n)
    
f.close()
out.close()
