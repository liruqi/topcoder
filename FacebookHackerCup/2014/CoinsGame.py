def game(N,K,C):
    res = (K / N) * N
    if (res >= C) :
        return C
    remainK = K % N  
    remainC = C % N  
    return (K/N) * N + N - (remainK - remainC)
   
kase = int(raw_input())

for k in range(kase):
    N,K,C = [int(x) for x in raw_input().split()]
    # K coins
    # N jars
    # get C coins
    res = (K / N) * N + N
    
    for empty in range(N):
        res = min(res, empty + game(N-empty, K, C))
    print ("Case #%d: "%(k+1)) + str(res)

