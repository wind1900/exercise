f = open('A-small-attempt0.in')
out = open('a.txt', 'w')
T = int(f.readline().strip())
for case in range(T):
    row1 = int(f.readline().strip())
    for i in range(row1-1):
        f.readline()
    set1 = set(int(i) for i in f.readline().strip().split())
    for i in range(4-row1):
        f.readline()
    row2 = int(f.readline().strip())
    for i in range(row2-1):
        f.readline()
    set2 = set(int(i) for i in f.readline().strip().split())
    for i in range(4-row2):
        f.readline()
    ans = set1 & set2
    if len(ans) == 1:
        output = str(ans.pop())
    elif len(ans) > 1:
        output = 'Bad magician!'
    else:
        output = 'Volunteer cheated!'
    out.write('Case #%d: %s\n' % (case+1, output))
out.close()
f.close()
