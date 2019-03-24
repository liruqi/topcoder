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

