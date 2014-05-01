n = int(input())
s = list(input())
x = 0
X = 0
for c in s:
    if c == 'x':
        x += 1
    else:
        X += 1
if x == n / 2:
    print(0)
elif X > x:
    c = (X - x) // 2
    print(c)
    for i in range(n):
        if s[i] == 'X':
           s[i] = 'x'
           c -= 1
           if c == 0:
               break
else:
    c = (x - X) // 2
    print(c)
    for i in range(n):
        if s[i] == 'x':
            s[i] = 'X'
            c -= 1
            if c == 0:
                break
print(''.join(s))
