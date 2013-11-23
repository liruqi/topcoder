def solve():
    row = int(raw_input())
    grid = []
    for r in range(row):
        grid.append(raw_input())
    ulr = row
    ulc = row
    drr = -1
    drc = -1
    cnt = 0
    for r in range(row):
        for c in range(row):
            if grid[r][c] == '#':
                ulr = min(ulr, r)
                ulc = min(ulc, c)
                drr = max(drr, r)
                drc = max(drc, c)
                cnt += 1
    if (ulr > drr) or (ulc > drc):
        return "NO"
    if (drr - ulr) != (drc - ulc):
        return "NO"
    if (drr - ulr + 1) * (drc - ulc + 1) != cnt:
        return "NO"
    return "YES"

kase = int(raw_input())

for k in range(1,kase+1):
    print "Case %d: %s" % (k, solve())
