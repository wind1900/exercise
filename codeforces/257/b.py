x, y = map(int, input().split())
n = int(input())
r = [x, y, y - x, -x, -y, x - y]
print(r[(n-1) % len(r)] % 1000000007)
