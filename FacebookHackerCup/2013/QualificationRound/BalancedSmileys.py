
def blank_char(ch):
    if (ch>='a' and ch<='z'):
        return True
    if ch == ' ':
        return True
    return False


def solve(case,line):
    cnt = [0]*256
    dp = {}
    dp[0] = {0:1}
    cnt = {
        '(' : 0,
        ')' : 0,
        ':(' : 0,
        ':)' : 0,
    }

    last = ''
    idx = 0
    for ch in line:
        #print ch
        if blank_char(ch):
            dp[idx+1] = dp[idx].copy()
            idx += 1
            last = ch
            continue
        if ch in [':']:
            dp[idx+1]=dp[idx].copy()
            idx += 1
            last = ch
            continue
        if ch in ['(', ')']:
            dp[idx+1] = {}
            cnt[ch] += 1
            if last == ':':
                cnt [last+ch] += 1
                if ch == '(':
                    for num in dp[idx]:
                        dp[idx+1][num+1]=1
                    for num in dp[idx-1]:
                        dp[idx+1][num]=1
                else :
                    for num in dp[idx]:
                        if (num > 0):
                            dp[idx+1][num-1]=1
                    for num in dp[idx-1]:
                        dp[idx+1][num]=1
                    if len(dp[idx+1]) == 0:
                        #print( dp)
                        print(("Case #%d: NO"%case))
                        return
            else:
                if ch == '(':
                    for num in dp[idx]:
                         dp[idx+1][num+1]=1
                else :
                    for num in dp[idx]:
                        if (num > 0):
                            dp[idx+1][num-1]=1
                    if len(dp[idx+1]) == 0:
                        #print( dp)
                        print(("Case #%d: NO"%case))
                        return

            last = ch
            idx += 1
            continue
        
        # bad char:
        #print ("#bad char")
        print(("Case #%d: NO"%case))
        return
    #print( dp)
    if 0 in dp[len(line)]:
        print(("Case #%d: YES"%case))
    else :
        print(("Case #%d: NO"%case))
        
sz = int(input())

for case in range(1, sz+1):
    line = input()
    #print (line)
    solve(case,line)
    
