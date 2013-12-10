
kase = int(raw_input())

for k in range(kase):
    line =  raw_input().split()
    labels = line[0]
    N = int(line[1]) - 1
    
    setsz = len(labels)
    labelsz = 1 
    
    while (N >= setsz) :
        N -= setsz
        setsz *= len(labels)
        labelsz += 1

    res = []
    p = 0
    while p<labelsz:
        res.append(labels[ N%len(labels) ])
        N /= len(labels)
        p += 1
    res.reverse()
    print ("Case #%d: "%(k+1)) + "".join(res)

