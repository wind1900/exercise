fin = open('B-large.in')
out = open('b.txt', 'w')
T = int(fin.readline().strip())
for case in range(T):
    c, f, x = (float(i) for i in fin.readline().strip().split())
    #compare X,C
    if c >= x:
        farm = 0
    else:
        farm = int(x / c - 2 / f)
    time = x / (2 + f * farm)
    for i in range(farm):
        time += c / (2 + i * f)
    out.write('Case #%d: %.7f\n' % (case+1, time))
out.close()
fin.close()

    

