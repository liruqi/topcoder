# Enter your code here. Read input from STDIN. Print output to STDOUT

s = raw_input()

row = len(s)
col = len(s)

for r in range(1, len(s)):
    c = (len(s) + r - 1) / r
    if c < r:
        continue
    if (r+1)*(r+1) <= len(s): 
        continue
    if (c-1)*(c-1) >= len(s):
        continue
    #print (r,c)
    if (r*c < row*col):
        row = r
        col = c

ans = []
for c in range(col):
    w = ""
    for r in range(row):
        idx = r * col + c
        if (idx < len(s)):
            w = w + s[idx]
    ans.append(w)

print " ".join(ans)
