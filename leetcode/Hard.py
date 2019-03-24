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
