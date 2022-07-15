from sortedcontainers import SortedList
from functools import lru_cache
import operator
import heapq
INF=999999999
USEHEAP=True

INF=999999999
class Solution:
    def minInterval(self, intervals, queries):
        n=len(intervals)
        sl = SortedList([[x[0],x[1]+1] for x in intervals]) # [)
        nonolp = []
        nonolpE = []
        nonosz = []
        isz=SortedList([[INF,INF]])
        ti=0
        
        def hppush(itv,sz):
            nonopush(itv,sz)

            end=itv[1]
            while isz and isz[ti][0]<=end and isz[ti][1]>=sz:
                isz.pop(0)
                #print("Pop:",itv,sz,isz.pop(0))

            if isz[ti][0]>=end:
                if isz[ti][1]>sz:
                    isz.add([end,sz])
                    nonopush([end,isz[ti][0]],isz[ti][1])
                return
            i=ti
            while i < len(isz):
                if isz[i][0]>end:
                    break
                if isz[i][0]==end:
                    if isz[i][1] > sz:
                        isz.pop(i)
                        break
                    return
                if isz[i][1]>=sz:
                    isz.pop(i)
                    continue
                i+=1
            isz.add([end,sz])

            #print("Push:",end,sz,isz)

        def nonopush(itv,sz):
            if not nonolp:
                nonolp.append(itv[0])
                nonolpE.append(itv[1])
                nonosz.append(sz)
                return 1
            
            if nonosz[-1]<sz:
                if itv[0]<nonolpE[-1]:
                    return 2
            else:
                if itv[0]==nonolp[-1]:
                    nonosz[-1]=sz
                    nonolpE[-1]=itv[1]
                    return 4
            if itv[0]>=itv[1]:
                return 5
            nonolp.append(itv[0])
            nonolpE.append(itv[1])
            nonosz.append(sz)
            return 0
        
        def hppop(end):
            #print("hppop",end,isz)
            top=[]
            while isz and isz[ti][0]<=end:
                #top=heapq.heappop(isz)
                top=isz.pop(0)
                if isz:
                    r = nonopush([top[0],isz[ti][0]], isz[ti][1])
                    #print("hppop it:",r,top,isz[ti])
            return top

        def buildNonOverlap(i):

            while i<n:
                #print("***",sl[i],nonolp,nonosz)
                itv=sl[i]
                itvsz=itv[1]-itv[0]
                i+=1
                
                endpoint=hppop(itv[0])
                ret=hppush(itv,itvsz)

            print(isz)
            hppop(INF)
        
        buildNonOverlap(0)
        print(nonolp)
        print(nonosz)
#         nonosl=SortedList(nonolp)

#         @lru_cache
#         def query(x):
#             idx = nonosl.bisect_left(x)
#             if idx<=0:
#                 return -1 if x < nonosl[0] else nonosz[0]

#             if idx>=len(nonosl):
#                 return -1
#             if x < nonosl[idx]:
#                 v = nonosz[idx-1]
#                 return v  if (v < INF) else -1

#             return nonosz[idx] if (nonosz[idx] < INF) else -1

        nonosz=[(x if x<INF else -1) for x in nonosz]
        qt=[None]*len(queries)
        i=0
        for x in queries:
            qt[i]=[x,i,-1]
            i+=1
        qt.sort()
        
        i,j=0,0
        citv=-1
        while i<len(qt) and j<len(nonolp):
            x=qt[i]
            if j==0:
                if x[0]<nonolp[j]:
                    x[2]=-1
                    i+=1
                else:
                    citv=j
                    j+=1
                continue
            if x[0]>=nonolp[j]:
                citv=j
                j+=1
                continue
            # x in citv
            x[2]=nonosz[citv]
            i+=1
        
        while i<len(qt):
            if qt[i][0]<nonolp[-1]:
                qt[i][2]=nonosz[-1]
            else:
                qt[i][2]=-1
            i+=1
        print(qt,sorted(qt, key = operator.itemgetter(1)))
        
        return [x[2] for x in sorted(qt, key = operator.itemgetter(1))]
        

s=Solution()
a=[[41,86],[57,81],[24,28],[5,69],[21,98],[4,95],[41,76],[61,99],[52,72],[51,67],[47,67],[81,91],[93,94],[72,72],[70,89],[68,77],[41,41],[41,77],[68,77],[65,73],[11,65],[40,94],[87,94],[95,97],[19,85],[11,26],[65,85],[77,86],[25,49],[46,77],[51,67],[29,83],[5,93],[83,99],[38,50],[73,80],[41,41],[92,100],[39,59],[81,100],[1,85],[39,78],[99,100],[12,93],[71,74],[57,63],[86,99],[28,65],[62,68],[53,77],[29,53],[97,97],[41,61],[1,88],[67,87],[85,95],[1,13],[67,73],[38,42],[1,11],[45,61],[71,73],[55,99],[75,87],[46,98],[45,93],[61,71],[31,74],[95,98],[84,90],[69,95],[67,68],[41,68],[87,94],[40,73],[93,93],[73,95],[61,73],[64,78],[4,20],[81,96],[40,48],[4,11],[40,56],[33,74],[23,80],[53,74],[30,87],[65,69],[51,86],[87,89],[46,53],[81,85],[81,97],[22,23],[1,83],[76,85],[71,71],[19,84],[21,53]]
b=[13,97,27,41,45,65,1,81,41,55,61,77,5,56,82,1,1,41,45,62,67,97,96,5,51,77,29,29,85,51,49,69,73,100,65,70,4,79,73,44,99,1,33,9,21,23,77,37,65,44,1,53,61,9,41,69,1,17,77,30,81,51,25,11,62,42,33,59,78,77,87,93,37,77,21,9,61,37,5,46,86,49,79,7,5,77,79,49,16,55,38,70,77,16,13,5,73,29,30,64]

a=[[1,4],[2,4],[3,6],[4,4]]
b=[2,3,4,5]

# a=[[4,5],[5,8],[1,9],[8,10],[1,6],[7,9],[3,3],[3,5],[7,7]]
# b=[2,2,6,3,9,6,1,1,1,9]
print(s.minInterval(a, b))