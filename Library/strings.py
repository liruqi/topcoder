# https://www.hackerrank.com/challenges/bigger-is-greater/
# No such impl in Python lib: https://stackoverflow.com/questions/4223349

class strings:
    def next_permutation(w):
        stk=[]
        n=len(w)
        def nextperm(sc):
            i=0
            for x in stk:
                if x > sc:
                    stk[i] = sc
                    return x+''.join(stk)
                i+=1
            return ''.join(stk)+sc

        for i in range(n):
            k=n-1-i
            if stk and w[k]<stk[-1]:
                return w[:k] + nextperm(w[k])
            else:
                stk.append(w[k])
        # return 'no answer'
        return ''.join(stk)
