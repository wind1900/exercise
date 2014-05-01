n = int(input())
book = [None] * n
for i in range(n):
    t = [int(i) for i in input().split(' ')]
    book[i] = (i, t[0], t[1])
k = int(input())
cap = [(i, int(c)) for i,c in enumerate(input().split(' '))]
cap.sort(key=lambda x:x[1])
book.sort(key=lambda x:(x[1]))
m = 0
s = 0
r = []
cand = []
j = 0
for i in range(k):
    while j < len(book) and cap[i][1] >= book[j][1]:
        cand.append((book[j][0], book[j][2]))
        j+=1
    if len(cand) == 0:
        continue
    cand.sort(key=lambda x:x[1])
    m+=1
    s+=cand[-1][1]
    r.append((cand.pop()[0]+1, cap[i][0]+1))
print(m, s)
for i in range(m):
    print(r[i][0], r[i][1])
