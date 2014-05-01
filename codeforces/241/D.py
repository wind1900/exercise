n = int(input())
seq = [int(i) for i in input().split(' ')]
trans = []
t = []
i = 0
while i < n:
    if seq[i] == -1:
        c = 1
        i+=1
        while i < n and seq[i] == -1:
            c+=1
            i+=1
        trans.append((-1, c))
        continue
    if i + 1 < n:
        if seq[i+1] == -1:
            trans.append((seq[i], 1))
            i+=1
            continue
        d = seq[i+1]-seq[i]
    else:
        trans.append((seq[i], 1))
        break
    left = seq[i]
    right = seq[i+1]
    i+=2
    while i < n and seq[i]!=-1 and seq[i]-right == d:
        right = seq[i]
        i+=1
    trans.append((left, right, d))
    
if len(trans) == 1:
    print(1)
    exit
for i, item in enumerate(trans):
    if item[0] != -1:
        continue
    if i == 0:
        right = trans[i+1]
        if len(right) == 2:
            trans[i] = None
            trans[i+1] = (right[0],right[0],0)
        elif right[2]<=0:
            trans[i] = None
            trans[i+1] = (right[0]-item[1]*right[2], right[1], right[2])
        elif (right[0]-item[1]*right[2]) > 0:
            trans[i] = None
            trans[i+1] = (right[0]-item[1]*right[2], right[1], right[2])
    elif i == len(trans)-1:
        left = trans[i-1]
        if len(left) == 2:
            trans[i] = None
            trans[i-1] = (left[0], left[0], 0)
        elif left[2]>=0:
            trans[i] = None
            trans[i-1] = (left[0], left[1]+item[1]*left[2], left[2])
        elif (left[1]+item[1]*left[2]) > 0:
            trans[i] = None
            trans[i-1] = (left[0], left[1]+item[1]*left[2], left[2])
    else:
        left = trans[i-1]
        right = trans[i+1]
        if len(left) == 2 and len(right) == 2:
            if (right[0]-left[0])%item[1] == 0:
                trans[i] = (left[0],right[0],(right[0]-left[0])//item[1])
                trans[i-1]=None
                trans[i+1]=None
        elif len(right) == 2:
            trans[i] = None
            trans[i+1] = (right[0],right[0],0)
        elif right[2]<=0:
            trans[i] = None
            trans[i+1] = (right[0]-item[1]*right[2], right[1], right[2])
        elif (right[0]-item[1]*right[2]) > 0:
            trans[i] = None
            trans[i+1] = (right[0]-item[1]*right[2], right[1], right[2])
        elif len(left) == 2:
            trans[i] = None
            trans[i-1] = (left[0], left[0], 0)
        elif left[2]>=0:
            trans[i] = None
            trans[i-1] = (left[0], left[1]+item[1]*left[2], left[2])
        elif (left[1]+item[1]*left[2]) > 0:
            trans[i] = None
            trans[i-1] = (left[0], left[1]+item[1]*left[2], left[2])
        elif (((left[1] - 1)/-left[2]) + ((right[0]-1)/right[1])) >= item[1]:
            trans[i] = None
        else:
            trans[i] = (-1,)
trans = [i for i in trans if i]
r = len(trans)
for i in range(len(trans)-1):
    if trans[i][0] == -1 or trans[i+1][0] == -1:
        continue
    if len(trans[i]) == 2 and (trans[i+1][0]-trans[i+1][2]) == trans[i][0]:
        r -= 1
    elif len(trans[i+1]) == 2 and (trans[i][1]+trans[i][2]) == trans[i+1][0]:
        r -= 1
    elif len(trans[i]) > 2 and len(trans[i+1]) > 2 and trans[i][2] == trans[i+1][2] and(trans[i+1][0] - trans[i][1]) == trans[i][2]:
        r-=1
print(r)
