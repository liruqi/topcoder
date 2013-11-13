#!/bin/python
# https://www.hackerrank.com/submissions/code/1102208

def quickSort(ar, k):
    if (len(ar) <= 1) :
        return ar[0]
    
    p = ar[0]
    la = []
    ra = []
    for v in ar[1:]:
        if (v < p):
            la.append(v)
        else:
            ra.append(v)
    if k < len(la):
        return quickSort(la, k)
    if k == len(la):
        return p
    return quickSort(ra, k-len(la)-1)


m = input()
ar = [int(i) for i in raw_input().strip().split()]
print quickSort(ar, len(ar)/2)
