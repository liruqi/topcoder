def solve():
    row = raw_input().split()
    pro = [int(float(x) * 1000) for x in row[1:]]
    K = int(row[0])

    #print ('#', pro, K) 
    dp = []
    for i in range(0, K+1):
        ar = []
        for j in range(0, K+1):
            ar.append([0]*1001)
        dp.append(ar)
    dp[0][0][ pro[2] ] = 1
    for s in range(0, 2*K-1):
        for i in range(min(s+1, K)):
            j = s - i
            if j>=K:
                continue
            for ps in range(1001):
                if dp[i][j][ps] > 0:
                    #print ('#', i, j, ps)
                    #sunny + win
                    dp[i+1][j][min(1000, ps+pro[3])] += dp[i][j][ps] * (ps/1000.0) * (pro[0] / 1000.0) * (pro[4] / 1000.0)
                    dp[i+1][j][ps] += dp[i][j][ps] * (ps/1000.0) * (pro[0] / 1000.0) * (1 - pro[4] / 1000.0)
                    #sunny + loose
                    #print ('#L24', i, j+1,max(0, ps-pro[5])) 
                    dp[i][j+1][max(0, ps-pro[5])] += dp[i][j][ps] * (ps/1000.0)* (1 - pro[0] / 1000.0) * (pro[6] / 1000.0)
                    dp[i][j+1][ps] += dp[i][j][ps] * (ps/1000.0) * (1 - pro[0] / 1000.0) * (1 - pro[6] / 1000.0)
                    #rainning + win
                    pr = 1 - ps/1000.0
                    dp[i+1][j][min(1000, ps+pro[3])] += dp[i][j][ps]* pr * (pro[1] / 1000.0) * (pro[4] / 1000.0)
                    dp[i+1][j][ps] += dp[i][j][ps] * pr * (pro[1] / 1000.0) * (1 - pro[4] / 1000.0)
                    
                    dp[i][j+1][max(0, ps-pro[5])] += dp[i][j][ps] * pr * (1 - pro[1] / 1000.0) * (pro[6] / 1000.0)
                    dp[i][j+1][ps] += dp[i][j][ps] * pr * (1 - pro[1] / 1000.0) * (1 - pro[6] / 1000.0)
    res = 0            
    for j in range(K):
        for ps in range(1001):
            if dp[K][j][ps] > 0:
                #print ("#R", j, ps, dp[K][j][ps])
                res += dp[K][j][ps]
    return res

kase = int(raw_input())

for k in range(1,kase+1):
    print "Case #%d: %.6f" % (k, solve())
