# For https://www.hackerrank.com/challenges/queens-on-board

def solve():
    (N, M) = [int(x) for x in raw_input().split()]
    board = []
    for n in range(N):
        board.append(raw_input())
    dp = [[0] * (1<<(3*M)), [0] * (1<<(3*M))]
    dp[1][0] = 1
    res = 0
    
    for r in range(N):
        pre = (r+1) % 2
        cur = r % 2
        for mask in range(1<<(3*M)):
            dp[cur][mask] = 0
        
        res = 0
        for mask in range(1<<(3*M)):
            if dp[pre][mask] == 0:
                continue
            cmask = 0
            blockMask = 0
            for c in range(M):
                if board[r][c]!='.':
                    blockMask |= (1<<c)

                pm = (mask >> (3*c)) % 8
                if pm & 1 > 0:
                    if c>0 and board[r][c-1]=='.':
                        cmask |= (1<<(3*(c-1)))
                if pm & (1<<1) > 0:
                    if board[r][c]=='.':
                        cmask |= (1<<(3*c + 1))
                if pm & (1<<2) > 0:
                    if c+1<M and board[r][c+1]=='.':
                        cmask |= (1<<(3*(c+1) + 2))

            for queenMask in range(1<<M):
                if (queenMask & blockMask) > 0:
                    continue
                qcnt = 0
                valid = 1
                for c in range(M):
                    if queenMask & (1<<c):
                        qcnt += 1
                        if qcnt > 1:
                            valid = 0
                            break
                    elif blockMask & (1<<c):
                        qcnt = 0
                if valid:
                    finalMask = 0 
                    for c in range(M):
                        if queenMask & (1<<c):
                            finalMask = finalMask | (7<<(3*c))
                    if (finalMask + cmask == (finalMask | cmask)):
                        finalMask = finalMask | cmask
                        dp[cur][finalMask] += dp[pre][mask]
                        res += dp[pre][mask]
                        #print ("# line: ", r, "{0:b}".format(queenMask), "finalMask: " + "{0:o}".format(finalMask), "cmask: " + "{0:o}".format(cmask), dp[pre][mask])
    print (res-1) % 1000000007
    
case = int(raw_input())

for k in range(case):
    solve();
