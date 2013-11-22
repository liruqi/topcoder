
sz = int(raw_input())

for case in range(1, sz+1):
    line = raw_input().split()
    N = int(line[0])
    K = int(line[1])

    aarr = []
    for it in raw_input().split():
        aarr.append(int(it))

    aarr.sort(reverse=False)
    comb = 1
    msum = 0
    for it in range(K-1,N):
        if (it >= K):
            comb = (comb * it) / (it - K + 1)
        #print ("#", aarr[it] , comb)
        msum += aarr[it] * comb
        msum = msum % 1000000007
    
    print "Case #%d: %d" % (case, msum)
