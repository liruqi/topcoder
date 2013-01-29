
sz = int(raw_input())

for case in range(1, sz+1):
    line = raw_input()
    cnt = [0]*256
    for ch in line:
        #print ch
        idx = -1
        if (ch>='a' and ch<='z'):
            idx = ord(ch) - ord('a')
        if (ch>='A' and ch<='Z'):
            idx = ord(ch) - ord('A')
        if idx >= 0:
            cnt[idx] += 1

    cnt.sort(reverse=True)
    answer = 0
    weight = 26
    for c in cnt:
        answer += weight * c
        weight -= 1
    print "Case #%d: %d" % (case, answer)
