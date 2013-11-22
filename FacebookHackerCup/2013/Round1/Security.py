sectionsz = 0
sectionlength = 0
match1 = []
match2 = []
visited = []

def encypt(k1):
   return k1.replace('a','1') .replace('?','2').replace('b','3').replace('c','4').replace('d','5').replace('e','6').replace('f','7')
def decypt(k1):
   return k1.replace('1','a') .replace('2','?').replace('3','b').replace('4','c').replace('5','d').replace('6','e').replace('7','f')


def sectionequal(k1,k2):
    for it in range(len(k1)):
        if (k1[it]==k2[it] or k1[it]=='?' or k2[it]=='?'):
            continue
        return False
    return True



def dfs(p, graph):
    #print ("#dfs", p, match2)
    if p >= sectionsz:
        return True
    #print graph,visited,match1,match2
    global visited
    edges = graph[p]
    for it in edges:
        if visited[it] == 0:
            visited[it] = 1
            if match2[it] == -1 or dfs(match2[it],graph):
                match2[it] = p
                match1[p] = it
                return True

    return False
def solve(k1,k2):
    global visited,match1,match2
    graph = []
    match1 = [-1] * sectionsz
    match2 = [-1] * sectionsz
    visited = []
    #print (k1,k2,sectionsz)
    for it in range(sectionsz):
        edges = []
        k1sec = k1[it*sectionlength: (it+1)*sectionlength]
        for it2 in range(sectionsz):
            k2sec = k2[it2*sectionlength: (it2+1)*sectionlength]
            if sectionequal(k1sec,k2sec):
                edges.append(it2)
        graph.append(edges)
    #print graph
    ans = 0
    for it in range(sectionsz):
        visited = [0]*sectionsz
        if dfs(it, graph):
            ans += 1
    return ans

sz = int(raw_input())
for case in range(1, sz+1):
    
    sectionsz = int(raw_input())
    k1 = raw_input()
    k2 = raw_input()
    
    #k1 = encypt(k1)
    #k2 = encypt(k2)
    
    sectionlength = len(k1) / sectionsz
    
    #print k2sections
    #print k1, k2, k2sections
    last = ""
    for it in range(len(k2)):
        if k1[it]!='?':
            continue
        lastresolved = False
        for c in 'abcdef':
            last = k1[:it]+c+k1[it+1:]
            ret = solve(last,k2)
            if ret == sectionsz:
                lastresolved = True
                k1 = last
                break
        if not lastresolved:
            break
    if solve(k1,k2) != sectionsz:
        print "Case #%d: IMPOSSIBLE" % (case)
    else:
        print "Case #%d: %s" % (case, k1)
