# Solution of hard problems in the list: https://leetcode.com/problemset/top-100-liked-questions/

# https://leetcode.com/problems/lru-cache/

import collections

class LRUCache(collections.OrderedDict):

    def __init__(self, capacity: int):
        self.maxsize = capacity
        
    def get(self, key: int) -> int:
        if key in self: 
            value = super().__getitem__(key)
            self.move_to_end(key)
            return value
        return -1
    
    def put(self, key: int, value: int) -> None:
        if key in self: 
            if len(self) >= self.maxsize:
                oldest = next(iter(self))
                del self[oldest]
        else:
            self.move_to_end(key)
        super().__setitem__(key, value)

    def test():
        obj = LRUCache(2)
        obj.put(2,6)
        print(obj.get(1))
        obj.put(1,5)
        obj.put(1,2)
        print(obj.get(1))
        print(obj.get(2))

class Solution:
    # https://leetcode.com/problems/binary-tree-maximum-path-sum/
    def maxPathSum(self, root: TreeNode) -> int:
        self.infmin = min(root.val, 0) - 1
        self.can = root.val
        self.MaxDownwardSum(root)
        return self.can
    
    def MaxDownwardSum(self, root: TreeNode):
        if not root:
            return self.infmin
        self.can = max(self.can, root.val)

        lmds = self.MaxDownwardSum(root.left)
        rmds = self.MaxDownwardSum(root.right)
        mds = max(lmds, rmds)
        self.can = max(self.can, mds + root.val)
        self.can = max(self.can, lmds + rmds + root.val)
        if mds <= 0 or root.val <= 0:
            return max(mds + root.val, root.val)
        return mds + root.val
    # End of binary-tree-maximum-path-sum
    
    # https://leetcode.com/problems/largest-rectangle-in-histogram/
    def largestRectangleArea(self, heights) -> int:
        N = len(heights)
        lIdx, incStack = self.buildIncIndex(heights)
        lIdx = [-1 if x>=N else x for x in lIdx]
        heights.reverse()
        rrIdx, decStack = self.buildIncIndex(heights)
        print (rrIdx, heights)

        rrIdx.reverse()
        rIdx = [N - 1 - x if x>=0 else x for x in rrIdx]
        print (lIdx, rIdx)
        heights.reverse()
        can = 0
        for i in range(N):
            x = heights[i]
            width = 1
            if (lIdx[i] >= 0):
                width += (i - lIdx[i])
            if (rIdx[i] > i):
                width += (rIdx[i] - i)
            can = max(can, width * x)
        return can

    def buildIncIndex(self, heights):
        leftIdx, incStack = [], []
        N = len(heights)

        for i in range(len(heights)):
            x = heights[i]
            idx = N
            while incStack and x <= heights[incStack[-1]]:
                idx = incStack[-1]
                incStack.pop()
            if (idx < N and leftIdx[idx]<N):
                idx = leftIdx[idx]
            incStack.append(i)
            leftIdx.append(idx)
        return (leftIdx, incStack)

    def largestRectangleAreaTest(self):
        print (self.largestRectangleArea([2,1,5,6,2,3]))
    # End of largest-rectangle-in-histogram

    # https://leetcode.com/problems/maximal-rectangle/
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        mtx = []
        for row in matrix:
            c = 0
            drow = []
            for x in row:
                if x == "0":
                    c = 0
                    drow.append(0)
                else:
                    c+=1
                    drow.append(c)
            mtx.append(drow)
        can = 0
        for i in range(len(mtx)):
            row = mtx[i]
            for j in range(len(row)):
                k = i
                area = 0
                minr = row[j]
                while (minr > 0):
                    can = max(can,
                              minr * (1 + i - k))
                    k -= 1
                    if (k < 0):
                        break
                    minr = min(minr, mtx[k][j])
        return can
    # End of maximal-rectangle