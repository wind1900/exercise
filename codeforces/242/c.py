n = int(input())
p = [int(i) for i in input().split()]
s = [0] * n
for i in range(1,n):
    s[i] = s[i-1] ^ i
q = 0
for i in range(n):
    q = q ^ p[i]
    if (n // (i+1)) % 2 == 1:
        q = q ^ s[i]
    q = q ^ s[n % (i+1)]
print(q)
