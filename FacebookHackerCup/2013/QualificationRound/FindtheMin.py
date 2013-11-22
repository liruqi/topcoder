import heapq

def solve(case):
    line = raw_input().split()
    listsz = int(line[0])
    k = int(line[1])

    line = raw_input().split()
    a = int(line[0])
    b = int(line[1])
    c = int(line[2])
    r = int(line[3])

    used = [0] * (k+1)
    mitem = a
    marray = []
    index = 0
    unusedset = []

    lastposition = {}
    while (index < k):
        marray.append(mitem)
        if mitem <= k:
            used[mitem] = 1
            lastposition[mitem] = index 
        index += 1
        mitem = (b * mitem + c) % r
    for it in range(k+1):
        if used[it]==0:
            unusedset.append(it)
    #print "#unused set"
    #print unusedset 
    heapq.heapify(unusedset)
    while (index < k+k+1):
        candidate = -1
        if index - k - 1 >= 0 and marray[index - k - 1] <= k:
            candidate = marray[index - k - 1]
            if candidate <= unusedset[0]:
                #print candidate, lastposition, lastposition.has_key(candidate)
                if not ( lastposition.has_key(candidate)) or (lastposition[candidate]+k < index):
                    #print "#insert %d: %d" % (index - k - 1, candidate)
                    #print marray
                    marray.append( candidate )
                    lastposition[candidate] = index
                    index += 1
                    continue
        
        while lastposition.has_key(unusedset[0]) and (lastposition[unusedset[0]]+k >= index):
            heapq.heappop(unusedset)

        marray.append( unusedset[0] )
        lastposition[ unusedset[0] ] = index
        heapq.heappop(unusedset)
        if candidate >= 0:
            heapq.heappush(unusedset, candidate)

        if (index == listsz - 1):
            #print marray[k:]
            print "Case #%d: %d" % (case, marray[-1])
            return
        index += 1
    #print marray[:k]
    #print marray[k:k+k+1]
    print "Case #%d: %d" % (case, marray[k + (listsz-1-k)%(k+1)])


sz = int(raw_input())
for case in range(1, sz+1):
    solve(case)
