n = int(input())
left = None
right = None
for i in range(n):
    st = input()
    op, num, ans = st.split(' ')
    num = int(num)
    if ans == 'N':
        if op == '>=':
            op = '<'
        elif op == '>':
            op = '<='
        elif op == '<=':
            op = '>'
        else:
            op = '>='
    if op == '>=':
        if left == None:
            left = num
        else:
            left = max(left, num)
    elif op == '>':
        if left == None:
            left = num+1
        else:
            left = max(left, num+1)
    elif op == '<=':
        if right == None:
            right = num
        else:
            right = min(right, num)
    else: # op == '<'
        if right == None:
            right = num-1
        else:
            right = min(right, num-1)
if left == None and right == None:
    print(0)
elif left == None:
    print(right)
elif right == None:
    print(left)
elif left > right:
    print('Impossible')
else:
    print(left)
    
