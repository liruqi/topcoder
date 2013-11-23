from operator import itemgetter, attrgetter

def solve():
    N,M,P = [int(x) for x in raw_input().split()]
    players = []
    for r in range(N):
        name,shot,height = [x for x in raw_input().split()]
        players.append((name, int(shot)*1000 + int(height)))
    #print players
    players = sorted(players, key=itemgetter(1))
    players.reverse()
    #print players
   
    t1 = []
    t2 = [] 
    for r in range(N):
        if r % 2 > 0:
            t2.append(players[r])
        else :
            t1.append(players[r])
    sub1 = t1[:P]
    sub1.reverse()
    t1 = sub1 + t1[P:] 
    
    sub2 = t2[:P]
    sub2.reverse()
    t2 = sub2 + t2[P:]
   
    #print (t1,t2)
    m1 = M % (len(t1))
    names = []
    for p in range(m1, m1+P):
        names.append(t1[p % (len(t1))][0])

    m2 = M % (len(t2))
    for p in range(m2, m2+P):
        names.append(t2[p % (len(t2))][0])


    names = sorted(names)
    return " ".join(names)

kase = int(raw_input())

for k in range(1,kase+1):
    print "Case #%d: %s" % (k, solve())
